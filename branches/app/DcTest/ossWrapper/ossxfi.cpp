/*************************************************************/
/* Copyright (C) 2009 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/* Generated for: Expedia, Inc., Bellevue, WA, Fast Infoset licenses 21878 (32-bit) & 11264 (64-bit) for Windows */
/* Created: Thu Oct 29 10:48:07 2009 */
/* XSD/FWS Compiler version: 2.3.2 */
/* Code generated for runtime version 2.3.2 */
/* Compiler operating system: Windows X64 */
/* Compiler machine type: AMD64 */
/* Target operating system: Windows X64 */
/* Target machine type: AMD64 */
/* C compiler options required: None */
/* XSD/FWS Compiler options and file names specified:
 * -c++ -fastInfosetAPI
 */

#include   "stdafx.h"
#include <ossxsd.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _WIN64 
    //x64

extern void DLL_ENTRY _ossx_run_FI_on_AMD64_WINDOWS_X64(OssxEnv *, unsigned char *);
void DLL_ENTRY_FDEF _ossxinit_fi_(OssxEnv *world) {
    static const unsigned char _ossx_fiinfo[] = {
        0x00, 0x93, 0x37, 0x18, 0xb6, 0x56, 0x45, 0x17, 0x13, 0xa9,
        0x2b, 0x4c, 0x13, 0x38, 0x2b, 0x87, 0xb9, 0xaa, 0xb8, 0x7b,
        0xd6, 0x62, 0xc5, 0x45, 0x4f, 0x6f, 0xcd, 0x0e, 0x68, 0xea,
        0xdf, 0x34, 0xda, 0x40, 0xea, 0x39, 0x03, 0xa9, 0xff, 0x21,
        0xed, 0x4d, 0xd3, 0x8c, 0x9f, 0x91, 0x01, 0x2c, 0xdd, 0x59,
        0x85, 0x70, 0x0a, 0xd6, 0x2e, 0xfb, 0x68, 0x9f, 0x0a, 0xdd,
        0xef, 0xdb, 0x17, 0xb4, 0x89, 0x48, 0xe6, 0x38, 0xc4, 0xec,
        0x2d, 0xf1, 0x77, 0x31, 0xc5, 0xa5, 0x48, 0x3f, 0xee, 0xb5,
        0x34, 0x89, 0xd7, 0x5a, 0x06, 0x96, 0x31, 0x2f, 0x01, 0xf1,
        0x13, 0xab, 0xd3, 0x97, 0xa9, 0x1d, 0x5d, 0x19, 0xa7, 0xc5,
        0x50, 0xf3, 0xde, 0x1e, 0x64, 0xcb, 0x93, 0x39, 0x25, 0x0e,
        0x61, 0x34, 0xb8, 0x7a, 0xd8, 0xd8, 0xc5, 0xf9, 0x90, 0x87,
        0x6b, 0x60, 0x02, 0x6e, 0xba, 0x75, 0xce, 0xf2, 0xcb, 0xcd,
        0x3e, 0x18, 0x55, 0x0e, 0xe1, 0xb6, 0x0f, 0xde, 0x84, 0xb8,
        0x39, 0xc5, 0x23, 0xde, 0x6f, 0xa7, 0x5d, 0xb0, 0x61
    };
    _ossx_run_FI_on_AMD64_WINDOWS_X64(world, (unsigned char *)_ossx_fiinfo);
}
const OssxFITable OSSX_FI_CTL_TBL = {0, 1, _ossxinit_fi_, NULL};

#else
//win32, x86

extern void DLL_ENTRY _ossx_run_FI_on_INTEL_X86_WINDOWS_AND_WINNT(OssxEnv *, unsigned char *);
void DLL_ENTRY_FDEF _ossxinit_fi_(OssxEnv *world) {
    static const unsigned char _ossx_fiinfo[] = {
        0x00, 0x7d, 0x37, 0xd8, 0xb9, 0xc6, 0x1e, 0xd7, 0x47, 0x39,
        0xe2, 0xd5, 0x47, 0x3a, 0xe2, 0x79, 0x6d, 0x6a, 0x90, 0x9e,
        0x51, 0x3f, 0x94, 0x53, 0xfe, 0x25, 0x50, 0x2a, 0x34, 0x9f,
        0xb4, 0x24, 0x74, 0xb4, 0x6a, 0x48, 0x51, 0x2d, 0xcd, 0xf7,
        0x4d, 0x3d, 0x7d, 0x39, 0xec, 0x00, 0x11, 0xa5, 0x24, 0xde,
        0x1b, 0x5b, 0x93, 0x11, 0x57, 0xee, 0x17, 0x85, 0x96, 0x4e,
        0xd5, 0x4f, 0x7d, 0x6f, 0x20, 0x6b, 0x8a, 0x1c, 0x74, 0x6c,
        0x7d, 0x88, 0xb0, 0x49, 0xab, 0xc9, 0xc8, 0x23, 0x0b, 0x81,
        0x06, 0x01, 0xfd, 0x8d, 0x96, 0x31, 0xfe, 0x58, 0x2f, 0x02,
        0xdc, 0xe4, 0x7d, 0xbf, 0x08, 0x80, 0x8a, 0xed, 0x84, 0x0a,
        0xaf, 0x73, 0xa6, 0x94, 0xd3, 0xa6, 0xbb, 0xaa, 0xce, 0xf9,
        0xf2, 0xc2, 0x1f, 0x62, 0x94, 0xf6, 0x61, 0xad, 0x3d, 0x94,
        0x35, 0xfd, 0x25, 0xc2, 0xec, 0xcf, 0x57
    };
    _ossx_run_FI_on_INTEL_X86_WINDOWS_AND_WINNT(world, (unsigned char *)_ossx_fiinfo);
}
const OssxFITable OSSX_FI_CTL_TBL = {0, 1, _ossxinit_fi_, NULL};
#endif

#ifdef __cplusplus
}	/* extern "C" */
#endif /* __cplusplus */
