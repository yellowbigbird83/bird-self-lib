#include "stdafx.h"
#include "UdpServer.h"
#include <WinSock2.h>
//#include <thread.h>

#include "HandleMsg.h"
#include "DebugFile.h"
#include "config.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
using namespace std;
//using namespace DebugFile;

//const int c_udp_port_listen  = 30000;
//const int c_udp_port_send  = 30000;

const int c_send_sleep_ms = 100;

CUdpServer* CUdpServer::g_pThis = NULL;

bool GetHostEntAndPort(hostent& hostEnt, int& portSend  );
//////////////////////////////////////////////////////////////////////////
CUdpServer& CUdpServer::GetInstance()
{
	if(!g_pThis)
	{
		g_pThis = new CUdpServer();
        atexit(DetroyInstance);        
	}
	return *g_pThis;
}

void CUdpServer::DetroyInstance()
{
    SAFE_DELETE(g_pThis);
}

CUdpServer::CUdpServer()
:m_ifRunningThreadListen(false)
//,m_portListen(c_udp_port_listen)
//,m_portSend(c_udp_port_send)
,m_pSocket(NULL)
,m_mutexSocket(FALSE, _T("CUdpServer_socket") )
,m_mutexMsg(FALSE, _T("CUdpServer_msg") )
{

}

CUdpServer::~CUdpServer()
{
    SAFE_DELETE(m_pSocket);
}

//////////////////////////////////////////////////////////////////////////
bool CUdpServer::StartThreadListen()
{
	//CreateThread();
    if(m_ifRunningThreadListen){
        AddDebug("error, CUdpServer::StartThreadListen twice.");
        return false;
    }
	
	DWORD dwThreadId = 0;
	m_ifRunningThreadListen = true;
	HANDLE hThread = ::CreateThread(NULL, 0, CUdpServer::ThreadFunc_listen, (LPVOID*)this, 0, &dwThreadId);
	if (!hThread)
	{
		m_ifRunningThreadListen = false;
		return false;
	}
	CloseHandle(hThread);		
	
	//ThreadFunc_server(0);

	return true;
}

bool CUdpServer::StartThreadSend()
{
	DWORD dwThreadId = 0;
	m_ifRunningThreadSend = true;
	HANDLE hThread = ::CreateThread(NULL, 0, CUdpServer::ThreadFunc_send, (LPVOID*)this, 0, &dwThreadId);
	if (!hThread)
	{
		m_ifRunningThreadSend = false;
		return false;
	}
	//m_ifRunningThreadSend = true;
	CloseHandle(hThread);	

	return true;
}


DWORD  CUdpServer::ThreadFunc_listen(void* pServer)
{
	CUdpServer* pThis = (CUdpServer*)pServer;
	if(!pThis)
		return 0;
	try{
		pThis->ThreadLoopListen();
	}
	catch(exception )
	{
	}
	return 1;
}

DWORD CUdpServer::ThreadFunc_send(void* pServer)
{
	CUdpServer* pThis = (CUdpServer*)pServer;
	if(!pThis)
		return 0;

	try{
		pThis->ThreadLoopSend();		
	}
	catch(exception )
	{
	}
	return 1;
}

bool CUdpServer::InitSocket()
{
	bool ifok = false;
    const bool fServer = CConfig::GetInstance().GetIsServer();
    int portListen = CConfig::GetInstance().m_portClientListen;
    if(fServer)
        portListen = CConfig::GetInstance().m_portServerListen;

    m_mutexSocket.Lock(5000);
    do{
        if(m_pSocket){
			ifok = true;
			break;
		}

		if(!m_pSocket){
			m_pSocket = new SOCKET();
			if(!m_pSocket)
				break;

			try
			{
                WORD wVersionRequested;
                WSADATA wsaData;
                int err;
                wVersionRequested =MAKEWORD( 1, 1 );
                err = WSAStartup( wVersionRequested, &wsaData );
                if ( err != 0 ) {
                    /* Tell the user that we couldn't find a useable */
                    /* winsock.dll. */
                     AddDebug("WSAStartup error.");
                    break;
                }

				*m_pSocket = ::socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
				if(INVALID_SOCKET == *m_pSocket){
                    DWORD errRet = GetLastError();
                    AddDebug("ini socket error.");
					ASSERT(false);
					SAFE_DELETE(m_pSocket);
					break;
				}

				sockaddr_in si0;   
				si0.sin_family=AF_INET;   
				si0.sin_port = htons(portListen);   
				si0.sin_addr.S_un.S_addr = ADDR_ANY;   

				int ret = ::bind(*m_pSocket, (LPSOCKADDR)&si0, sizeof(si0));
				if(SOCKET_ERROR == ret){
					ASSERT(false);
					const DWORD err = GetLastError();
					SAFE_DELETE(m_pSocket);
					AddDebug("bind socket error.");				
					break;
				}
				ifok = true;
				AddDebug("bind socket ok.");	
			}
			catch (CException* )
			{
			}

		}
	}while(false);

	m_mutexSocket.Unlock();
	return ifok;	
}

int CUdpServer::ThreadLoopListen()
{
	AddDebug("CUdpServer::ThreadLoopListen 0.");
	//SOCKET sktSever = ::socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(!InitSocket() )
		return 0;
	SOCKET& sktSever = *m_pSocket;
	
	const int max_buf_size = 1*1024*1024;
	string vecBuf;
	vecBuf.resize(max_buf_size);

	CMessage msg;
	//msg.m_data.resize(datasize);
	int receivNum = 0;
	sockaddr_in addr; 
	int nlen = sizeof(addr);

	CTime   time0;
	__time64_t timevalue= 0;
	CString dbgstr;
	wstring wstr;

	//m_ifRunningThreadListen
	while(true)  //
	{
		receivNum = ::recvfrom(sktSever, (char*)&vecBuf[0], vecBuf.size(), 0,  (sockaddr*)&addr , &nlen);
		if(receivNum>0
			&& receivNum < (int)vecBuf.size() )
		{
			dbgstr.Format(_T("recvfrom num=%d"), receivNum);
			wstr = dbgstr;
			AddDebug(wstr);

			msg.m_data = vecBuf;
			msg.m_data.resize(receivNum);
            
			//save time
			time0 =CTime::GetCurrentTime(); 
			timevalue = time0.GetTime() ;
			msg.m_time = timevalue;			

			//save addr
			if(nlen>0){
				msg.m_addressData.resize(nlen);
				memcpy(&(msg.m_addressData[0]), &addr, nlen);
			}

			CHandleMsg::GetInstance().AddMsg(msg);
			//int sendtret = ::sendto(sktSever, "ok", 3, 0, (sockaddr*)&addr , nlen);
		}
		::Sleep(1);
	}
	::closesocket(sktSever);
	
	return 0;
}

bool GetHostEntAndPort(hostent& hostEnt, int& portSend  )
{
	const bool fServer = CConfig::GetInstance().GetIsServer();
    portSend = CConfig::GetInstance().m_portClientSend;
    string strSendIp = CConfig::GetInstance().m_strDestIpClient;
    if(fServer){
        portSend = CConfig::GetInstance().m_portServerSend;
        strSendIp = CConfig::GetInstance().m_strDestIpServer;
    }

    //parse dns to ip
    hostent* htSend = ::gethostbyname(strSendIp.c_str() );
	if(!htSend){
		AddDebug("gethostbyname(%s) failed.", strSendIp.c_str() );        
		return false;
	}
	hostEnt = *htSend;
	return true;
}

int CUdpServer::ThreadLoopSend()
{
	if(!InitSocket() )
		return 0;
	SOCKET& skt = *m_pSocket;
	
    SOCKADDR_IN addr;  
    bool ifok =false;
    int sendret = 0;
    CMessage msg;

	while(m_ifRunningThreadSend)
    {
        ::Sleep(c_send_sleep_ms);
        ifok = GetMsg(msg);
        if(!ifok)
            continue;

        const size_t addrsize = msg.m_addressData.size(); 
        const int addrsize1 = sizeof(SOCKADDR);
        if(addrsize< 1)
        {
            AddDebug("msg.m_addressData.size() < 1.");
			hostent htSend  ;
			int portSend=0;
			bool fGetPort = GetHostEntAndPort(htSend, portSend);
			if(!fGetPort){
				continue;
			}
            addr.sin_addr.S_un.S_addr=  *(DWORD*)htSend.h_addr_list[0];
                //inet_addr(strSendIp.c_str() );  //"192.168.0.104"
            addr.sin_family=AF_INET;
            addr.sin_port=htons(portSend); //other one's port
        }
        else{
            memcpy(&addr, &(msg.m_addressData[0]), addrsize);
            if(addrsize != addrsize1)
            {
                AddDebug("Err: SOCKADDR_IN size err.");
            }
        }		

        char* pstr = (char*)&msg.m_data[0];
        const UINT sendsize = static_cast<UINT>(msg.m_data.size() );
        sendret = ::sendto(skt, pstr, sendsize, 0,
            (SOCKADDR*)&addr, addrsize1);
        if(sendret < 1){
            //error;
            const DWORD err = GetLastError();
            AddDebug("send udp error.");
            continue;
        }
        else{
            CString cstr;
            cstr.Format(_T("sendto ok, byte=%d"), sendret);
            wstring wstr = cstr.GetString();
            AddDebug(wstr);
        }
	}
	return 0;
}

//bool	CUdpServer::SendMsg(const CMessage& msg)
//{
//	AddDebug("CUdpServer::SendMsg 0.");
//
//	InitSocket();
//	if(!m_pSocket)
//		return false;
//	SOCKET& sockClient = *m_pSocket;
//
//	try
//	{
//		//SOCKET sockClient=socket(AF_INET,SOCK_DGRAM,0);
//
//		SOCKADDR_IN addr;
//		const int addrsize = msg.m_addressData.size(); 
//		const int addrsize1 = sizeof(SOCKADDR);
//		if(addrsize< 1)
//		{
//			AddDebug("msg.m_addressData.size() < 1.");
//			addr.sin_addr.S_un.S_addr=inet_addr(m_strSendIp.c_str() );  //"192.168.0.104"
//			addr.sin_family=AF_INET;
//			addr.sin_port=htons(m_portSend); //port
//			
//		}
//		else{
//			memcpy(&addr, &(msg.m_addressData[0]), addrsize);
//			if(addrsize != addrsize1)
//			{
//				AddDebug("Err: SOCKADDR_IN size err.");
//			}
//		}		
//
//		char* pstr = (char*)&msg.m_data[0];
//		const UINT sendsize = msg.m_data.size();
//		int sendret = ::sendto(sockClient, pstr, sendsize, 0,
//			(SOCKADDR*)&addr, addrsize1);
//		if(sendret < 1){
//			//error;
//			DWORD err = GetLastError();
//			AddDebug("send udp error.");
//			return false;
//		}
//		else{
//			AddDebug("sendto ok.");
//		}
//		//closesocket(sockClient);  //let thread to close
//		
//	}
//	catch (CException* )
//	{
//		return false;
//	}
//	
//	return true;
//}

void    CUdpServer::AddMsg(const CMessage& msg)
{
    m_mutexMsg.Lock(1000);
    //todo, m_vecMsg size max
    m_vecMsg.push_back(msg);
    m_mutexMsg.Unlock();
}

bool    CUdpServer::GetMsg(CMessage& msg)
{
    bool ifok = false;

    m_mutexMsg.Lock(1000) ;
    if(m_vecMsg.size() <1)
        return ifok;
    {	
        msg = m_vecMsg[0];
        m_vecMsg.erase( m_vecMsg.begin() );
        ifok = true;
    }
    m_mutexMsg.Unlock();

    return ifok;
}
//////////////////////////////////////////////////////////////////////////

//void	 CUdpServer::SetSendIp(const std::string& strip)
//{
//	m_strSendIp = strip;
//}
//void	CUdpServer::SetListenPort(UINT port)
//{
//	m_portListen = port;
//}
//void	CUdpServer::SetSendPort(UINT port)
//{
//	m_portSend = port;
//}
//////////////////////////////////////////////////////////////////////////

