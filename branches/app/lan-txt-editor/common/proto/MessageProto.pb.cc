// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageProto.proto

#pragma warning(disable:4251 4244 4267)

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageProto.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MessageProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessageProto_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageProto_2eproto() {
  protobuf_AddDesc_MessageProto_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageProto.proto");
  GOOGLE_CHECK(file != NULL);
  MessageProto_descriptor_ = file->message_type(0);
  static const int MessageProto_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageProto, cmdtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageProto, msgfiledata_),
  };
  MessageProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessageProto_descriptor_,
      MessageProto::default_instance_,
      MessageProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessageProto));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageProto_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessageProto_descriptor_, &MessageProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageProto_2eproto() {
  delete MessageProto::default_instance_;
  delete MessageProto_reflection_;
}

void protobuf_AddDesc_MessageProto_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_msgFile_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022MessageProto.proto\032\rmsgFile.proto\">\n\014M"
    "essageProto\022\017\n\007cmdType\030\001 \002(\005\022\035\n\013msgFileD"
    "ata\030\002 \003(\0132\010.MsgFile", 99);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageProto.proto", &protobuf_RegisterTypes);
  MessageProto::default_instance_ = new MessageProto();
  MessageProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageProto_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageProto_2eproto {
  StaticDescriptorInitializer_MessageProto_2eproto() {
    protobuf_AddDesc_MessageProto_2eproto();
  }
} static_descriptor_initializer_MessageProto_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MessageProto::kCmdTypeFieldNumber;
const int MessageProto::kMsgFileDataFieldNumber;
#endif  // !_MSC_VER

MessageProto::MessageProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MessageProto::InitAsDefaultInstance() {
}

MessageProto::MessageProto(const MessageProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MessageProto::SharedCtor() {
  _cached_size_ = 0;
  cmdtype_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessageProto::~MessageProto() {
  SharedDtor();
}

void MessageProto::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MessageProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessageProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageProto_descriptor_;
}

const MessageProto& MessageProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageProto_2eproto();
  return *default_instance_;
}

MessageProto* MessageProto::default_instance_ = NULL;

MessageProto* MessageProto::New() const {
  return new MessageProto;
}

void MessageProto::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    cmdtype_ = 0;
  }
  msgfiledata_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MessageProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 cmdType = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &cmdtype_)));
          set_has_cmdtype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_msgFileData;
        break;
      }

      // repeated .MsgFile msgFileData = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_msgFileData:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_msgfiledata()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_msgFileData;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MessageProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 cmdType = 1;
  if (has_cmdtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->cmdtype(), output);
  }

  // repeated .MsgFile msgFileData = 2;
  for (int i = 0; i < this->msgfiledata_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->msgfiledata(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MessageProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 cmdType = 1;
  if (has_cmdtype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->cmdtype(), target);
  }

  // repeated .MsgFile msgFileData = 2;
  for (int i = 0; i < this->msgfiledata_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->msgfiledata(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MessageProto::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 cmdType = 1;
    if (has_cmdtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->cmdtype());
    }

  }
  // repeated .MsgFile msgFileData = 2;
  total_size += 1 * this->msgfiledata_size();
  for (int i = 0; i < this->msgfiledata_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->msgfiledata(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MessageProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessageProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessageProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessageProto::MergeFrom(const MessageProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  msgfiledata_.MergeFrom(from.msgfiledata_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_cmdtype()) {
      set_cmdtype(from.cmdtype());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessageProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessageProto::CopyFrom(const MessageProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageProto::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  for (int i = 0; i < msgfiledata_size(); i++) {
    if (!this->msgfiledata(i).IsInitialized()) return false;
  }
  return true;
}

void MessageProto::Swap(MessageProto* other) {
  if (other != this) {
    std::swap(cmdtype_, other->cmdtype_);
    msgfiledata_.Swap(&other->msgfiledata_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessageProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessageProto_descriptor_;
  metadata.reflection = MessageProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
