#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "messages.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Message {

namespace {

const ::google::protobuf::Descriptor* SearchResult_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SearchResult_reflection_ = NULL;
const ::google::protobuf::Descriptor* SearchResult_Hit_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SearchResult_Hit_reflection_ = NULL;
const ::google::protobuf::Descriptor* NearbyHits_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NearbyHits_reflection_ = NULL;
const ::google::protobuf::Descriptor* NearbyHits_NearbyHit_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NearbyHits_NearbyHit_reflection_ = NULL;
const ::google::protobuf::Descriptor* Results_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Results_reflection_ = NULL;
const ::google::protobuf::Descriptor* Results_Result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Results_Result_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_messages_2eproto() {
  protobuf_AddDesc_messages_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "messages.proto");
  GOOGLE_CHECK(file != NULL);
  SearchResult_descriptor_ = file->message_type(0);
  static const int SearchResult_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult, term_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult, numhits_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult, hits_),
  };
  SearchResult_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SearchResult_descriptor_,
      SearchResult::default_instance_,
      SearchResult_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SearchResult));
  SearchResult_Hit_descriptor_ = SearchResult_descriptor_->nested_type(0);
  static const int SearchResult_Hit_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, pageuri_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, idx_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, fragment_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, length_),
  };
  SearchResult_Hit_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SearchResult_Hit_descriptor_,
      SearchResult_Hit::default_instance_,
      SearchResult_Hit_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SearchResult_Hit, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SearchResult_Hit));
  NearbyHits_descriptor_ = file->message_type(1);
  static const int NearbyHits_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits, term1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits, term2_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits, nearbyhits_),
  };
  NearbyHits_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      NearbyHits_descriptor_,
      NearbyHits::default_instance_,
      NearbyHits_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(NearbyHits));
  NearbyHits_NearbyHit_descriptor_ = NearbyHits_descriptor_->nested_type(0);
  static const int NearbyHits_NearbyHit_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, pageuri_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, fragment_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, offset1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, length1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, offset2_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, length2_),
  };
  NearbyHits_NearbyHit_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      NearbyHits_NearbyHit_descriptor_,
      NearbyHits_NearbyHit::default_instance_,
      NearbyHits_NearbyHit_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NearbyHits_NearbyHit, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(NearbyHits_NearbyHit));
  Results_descriptor_ = file->message_type(2);
  static const int Results_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, results_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, numresults_),
  };
  Results_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Results_descriptor_,
      Results::default_instance_,
      Results_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Results));
  Results_Result_descriptor_ = Results_descriptor_->nested_type(0);
  static const int Results_Result_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results_Result, pageuri_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results_Result, term1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results_Result, term2_),
  };
  Results_Result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Results_Result_descriptor_,
      Results_Result::default_instance_,
      Results_Result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results_Result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Results_Result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Results_Result));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_messages_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SearchResult_descriptor_, &SearchResult::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SearchResult_Hit_descriptor_, &SearchResult_Hit::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    NearbyHits_descriptor_, &NearbyHits::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    NearbyHits_NearbyHit_descriptor_, &NearbyHits_NearbyHit::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Results_descriptor_, &Results::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Results_Result_descriptor_, &Results_Result::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_messages_2eproto() {
  delete SearchResult::default_instance_;
  delete SearchResult_reflection_;
  delete SearchResult_Hit::default_instance_;
  delete SearchResult_Hit_reflection_;
  delete NearbyHits::default_instance_;
  delete NearbyHits_reflection_;
  delete NearbyHits_NearbyHit::default_instance_;
  delete NearbyHits_NearbyHit_reflection_;
  delete Results::default_instance_;
  delete Results_reflection_;
  delete Results_Result::default_instance_;
  delete Results_Result_reflection_;
}

void protobuf_AddDesc_messages_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016messages.proto\022\007Message\"\265\001\n\014SearchResu"
    "lt\022\014\n\004term\030\001 \002(\t\022\017\n\007numHits\030\002 \001(\r\022\'\n\004hit"
    "s\030\003 \003(\0132\031.Message.SearchResult.Hit\032]\n\003Hi"
    "t\022\017\n\007pageuri\030\001 \002(\t\022\013\n\003idx\030\002 \001(\r\022\020\n\010fragm"
    "ent\030\003 \002(\r\022\022\n\006offset\030\004 \003(\rB\002\020\001\022\022\n\006length\030"
    "\005 \003(\rB\002\020\001\"\317\001\n\nNearbyHits\022\r\n\005term1\030\001 \002(\t\022"
    "\r\n\005term2\030\002 \002(\t\022\'\n\nnearbyhits\030\003 \003(\0132\023.Mes"
    "sage.NearbyHits\032z\n\tNearbyHit\022\017\n\007pageuri\030"
    "\001 \002(\t\022\020\n\010fragment\030\002 \002(\r\022\023\n\007offset1\030\004 \003(\r"
    "B\002\020\001\022\017\n\007length1\030\005 \001(\r\022\023\n\007offset2\030\006 \003(\rB\002"
    "\020\001\022\017\n\007length2\030\007 \001(\r\"\200\001\n\007Results\022(\n\007resul"
    "ts\030\001 \003(\0132\027.Message.Results.Result\022\022\n\nnum"
    "Results\030\002 \001(\r\0327\n\006Result\022\017\n\007pageuri\030\001 \002(\t"
    "\022\r\n\005term1\030\002 \002(\t\022\r\n\005term2\030\003 \002(\tB\002H\001", 554);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "messages.proto", &protobuf_RegisterTypes);
  SearchResult::default_instance_ = new SearchResult();
  SearchResult_Hit::default_instance_ = new SearchResult_Hit();
  NearbyHits::default_instance_ = new NearbyHits();
  NearbyHits_NearbyHit::default_instance_ = new NearbyHits_NearbyHit();
  Results::default_instance_ = new Results();
  Results_Result::default_instance_ = new Results_Result();
  SearchResult::default_instance_->InitAsDefaultInstance();
  SearchResult_Hit::default_instance_->InitAsDefaultInstance();
  NearbyHits::default_instance_->InitAsDefaultInstance();
  NearbyHits_NearbyHit::default_instance_->InitAsDefaultInstance();
  Results::default_instance_->InitAsDefaultInstance();
  Results_Result::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_messages_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_messages_2eproto {
  StaticDescriptorInitializer_messages_2eproto() {
    protobuf_AddDesc_messages_2eproto();
  }
} static_descriptor_initializer_messages_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int SearchResult_Hit::kPageuriFieldNumber;
const int SearchResult_Hit::kIdxFieldNumber;
const int SearchResult_Hit::kFragmentFieldNumber;
const int SearchResult_Hit::kOffsetFieldNumber;
const int SearchResult_Hit::kLengthFieldNumber;
#endif  // !_MSC_VER

SearchResult_Hit::SearchResult_Hit()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SearchResult_Hit::InitAsDefaultInstance() {
}

SearchResult_Hit::SearchResult_Hit(const SearchResult_Hit& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SearchResult_Hit::SharedCtor() {
  _cached_size_ = 0;
  pageuri_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  idx_ = 0u;
  fragment_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SearchResult_Hit::~SearchResult_Hit() {
  SharedDtor();
}

void SearchResult_Hit::SharedDtor() {
  if (pageuri_ != &::google::protobuf::internal::kEmptyString) {
    delete pageuri_;
  }
  if (this != default_instance_) {
  }
}

void SearchResult_Hit::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SearchResult_Hit::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SearchResult_Hit_descriptor_;
}

const SearchResult_Hit& SearchResult_Hit::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();  return *default_instance_;
}

SearchResult_Hit* SearchResult_Hit::default_instance_ = NULL;

SearchResult_Hit* SearchResult_Hit::New() const {
  return new SearchResult_Hit;
}

void SearchResult_Hit::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_pageuri()) {
      if (pageuri_ != &::google::protobuf::internal::kEmptyString) {
        pageuri_->clear();
      }
    }
    idx_ = 0u;
    fragment_ = 0u;
  }
  offset_.Clear();
  length_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SearchResult_Hit::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string pageuri = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_pageuri()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->pageuri().data(), this->pageuri().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_idx;
        break;
      }
      
      // optional uint32 idx = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_idx:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &idx_)));
          set_has_idx();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_fragment;
        break;
      }
      
      // required uint32 fragment = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fragment:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fragment_)));
          set_has_fragment();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_offset;
        break;
      }
      
      // repeated uint32 offset = 4 [packed = true];
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_offset:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_offset())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 34, input, this->mutable_offset())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_length;
        break;
      }
      
      // repeated uint32 length = 5 [packed = true];
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_length:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_length())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 42, input, this->mutable_length())));
        } else {
          goto handle_uninterpreted;
        }
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

void SearchResult_Hit::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string pageuri = 1;
  if (has_pageuri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pageuri().data(), this->pageuri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->pageuri(), output);
  }
  
  // optional uint32 idx = 2;
  if (has_idx()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->idx(), output);
  }
  
  // required uint32 fragment = 3;
  if (has_fragment()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->fragment(), output);
  }
  
  // repeated uint32 offset = 4 [packed = true];
  if (this->offset_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(4, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_offset_cached_byte_size_);
  }
  for (int i = 0; i < this->offset_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->offset(i), output);
  }
  
  // repeated uint32 length = 5 [packed = true];
  if (this->length_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(5, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_length_cached_byte_size_);
  }
  for (int i = 0; i < this->length_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->length(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SearchResult_Hit::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string pageuri = 1;
  if (has_pageuri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pageuri().data(), this->pageuri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->pageuri(), target);
  }
  
  // optional uint32 idx = 2;
  if (has_idx()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->idx(), target);
  }
  
  // required uint32 fragment = 3;
  if (has_fragment()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->fragment(), target);
  }
  
  // repeated uint32 offset = 4 [packed = true];
  if (this->offset_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      4,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _offset_cached_byte_size_, target);
  }
  for (int i = 0; i < this->offset_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->offset(i), target);
  }
  
  // repeated uint32 length = 5 [packed = true];
  if (this->length_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      5,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _length_cached_byte_size_, target);
  }
  for (int i = 0; i < this->length_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->length(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SearchResult_Hit::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string pageuri = 1;
    if (has_pageuri()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->pageuri());
    }
    
    // optional uint32 idx = 2;
    if (has_idx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->idx());
    }
    
    // required uint32 fragment = 3;
    if (has_fragment()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fragment());
    }
    
  }
  // repeated uint32 offset = 4 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->offset_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->offset(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _offset_cached_byte_size_ = data_size;
    total_size += data_size;
  }
  
  // repeated uint32 length = 5 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->length_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->length(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _length_cached_byte_size_ = data_size;
    total_size += data_size;
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

void SearchResult_Hit::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SearchResult_Hit* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SearchResult_Hit*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SearchResult_Hit::MergeFrom(const SearchResult_Hit& from) {
  GOOGLE_CHECK_NE(&from, this);
  offset_.MergeFrom(from.offset_);
  length_.MergeFrom(from.length_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pageuri()) {
      set_pageuri(from.pageuri());
    }
    if (from.has_idx()) {
      set_idx(from.idx());
    }
    if (from.has_fragment()) {
      set_fragment(from.fragment());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SearchResult_Hit::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SearchResult_Hit::CopyFrom(const SearchResult_Hit& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SearchResult_Hit::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000005) != 0x00000005) return false;
  
  return true;
}

void SearchResult_Hit::Swap(SearchResult_Hit* other) {
  if (other != this) {
    std::swap(pageuri_, other->pageuri_);
    std::swap(idx_, other->idx_);
    std::swap(fragment_, other->fragment_);
    offset_.Swap(&other->offset_);
    length_.Swap(&other->length_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SearchResult_Hit::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SearchResult_Hit_descriptor_;
  metadata.reflection = SearchResult_Hit_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int SearchResult::kTermFieldNumber;
const int SearchResult::kNumHitsFieldNumber;
const int SearchResult::kHitsFieldNumber;
#endif  // !_MSC_VER

SearchResult::SearchResult()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SearchResult::InitAsDefaultInstance() {
}

SearchResult::SearchResult(const SearchResult& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SearchResult::SharedCtor() {
  _cached_size_ = 0;
  term_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  numhits_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SearchResult::~SearchResult() {
  SharedDtor();
}

void SearchResult::SharedDtor() {
  if (term_ != &::google::protobuf::internal::kEmptyString) {
    delete term_;
  }
  if (this != default_instance_) {
  }
}

void SearchResult::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SearchResult::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SearchResult_descriptor_;
}

const SearchResult& SearchResult::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();  return *default_instance_;
}

SearchResult* SearchResult::default_instance_ = NULL;

SearchResult* SearchResult::New() const {
  return new SearchResult;
}

void SearchResult::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_term()) {
      if (term_ != &::google::protobuf::internal::kEmptyString) {
        term_->clear();
      }
    }
    numhits_ = 0u;
  }
  hits_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SearchResult::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string term = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_term()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->term().data(), this->term().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_numHits;
        break;
      }
      
      // optional uint32 numHits = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_numHits:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &numhits_)));
          set_has_numhits();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_hits;
        break;
      }
      
      // repeated .Message.SearchResult.Hit hits = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_hits:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_hits()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_hits;
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

void SearchResult::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string term = 1;
  if (has_term()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term().data(), this->term().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->term(), output);
  }
  
  // optional uint32 numHits = 2;
  if (has_numhits()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->numhits(), output);
  }
  
  // repeated .Message.SearchResult.Hit hits = 3;
  for (int i = 0; i < this->hits_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->hits(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SearchResult::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string term = 1;
  if (has_term()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term().data(), this->term().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->term(), target);
  }
  
  // optional uint32 numHits = 2;
  if (has_numhits()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->numhits(), target);
  }
  
  // repeated .Message.SearchResult.Hit hits = 3;
  for (int i = 0; i < this->hits_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->hits(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SearchResult::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string term = 1;
    if (has_term()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->term());
    }
    
    // optional uint32 numHits = 2;
    if (has_numhits()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->numhits());
    }
    
  }
  // repeated .Message.SearchResult.Hit hits = 3;
  total_size += 1 * this->hits_size();
  for (int i = 0; i < this->hits_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->hits(i));
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

void SearchResult::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SearchResult* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SearchResult*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SearchResult::MergeFrom(const SearchResult& from) {
  GOOGLE_CHECK_NE(&from, this);
  hits_.MergeFrom(from.hits_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_term()) {
      set_term(from.term());
    }
    if (from.has_numhits()) {
      set_numhits(from.numhits());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SearchResult::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SearchResult::CopyFrom(const SearchResult& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SearchResult::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  for (int i = 0; i < hits_size(); i++) {
    if (!this->hits(i).IsInitialized()) return false;
  }
  return true;
}

void SearchResult::Swap(SearchResult* other) {
  if (other != this) {
    std::swap(term_, other->term_);
    std::swap(numhits_, other->numhits_);
    hits_.Swap(&other->hits_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SearchResult::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SearchResult_descriptor_;
  metadata.reflection = SearchResult_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int NearbyHits_NearbyHit::kPageuriFieldNumber;
const int NearbyHits_NearbyHit::kFragmentFieldNumber;
const int NearbyHits_NearbyHit::kOffset1FieldNumber;
const int NearbyHits_NearbyHit::kLength1FieldNumber;
const int NearbyHits_NearbyHit::kOffset2FieldNumber;
const int NearbyHits_NearbyHit::kLength2FieldNumber;
#endif  // !_MSC_VER

NearbyHits_NearbyHit::NearbyHits_NearbyHit()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void NearbyHits_NearbyHit::InitAsDefaultInstance() {
}

NearbyHits_NearbyHit::NearbyHits_NearbyHit(const NearbyHits_NearbyHit& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void NearbyHits_NearbyHit::SharedCtor() {
  _cached_size_ = 0;
  pageuri_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  fragment_ = 0u;
  length1_ = 0u;
  length2_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NearbyHits_NearbyHit::~NearbyHits_NearbyHit() {
  SharedDtor();
}

void NearbyHits_NearbyHit::SharedDtor() {
  if (pageuri_ != &::google::protobuf::internal::kEmptyString) {
    delete pageuri_;
  }
  if (this != default_instance_) {
  }
}

void NearbyHits_NearbyHit::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NearbyHits_NearbyHit::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NearbyHits_NearbyHit_descriptor_;
}

const NearbyHits_NearbyHit& NearbyHits_NearbyHit::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();  return *default_instance_;
}

NearbyHits_NearbyHit* NearbyHits_NearbyHit::default_instance_ = NULL;

NearbyHits_NearbyHit* NearbyHits_NearbyHit::New() const {
  return new NearbyHits_NearbyHit;
}

void NearbyHits_NearbyHit::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_pageuri()) {
      if (pageuri_ != &::google::protobuf::internal::kEmptyString) {
        pageuri_->clear();
      }
    }
    fragment_ = 0u;
    length1_ = 0u;
    length2_ = 0u;
  }
  offset1_.Clear();
  offset2_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool NearbyHits_NearbyHit::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string pageuri = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_pageuri()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->pageuri().data(), this->pageuri().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_fragment;
        break;
      }
      
      // required uint32 fragment = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fragment:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fragment_)));
          set_has_fragment();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_offset1;
        break;
      }
      
      // repeated uint32 offset1 = 4 [packed = true];
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_offset1:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_offset1())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 34, input, this->mutable_offset1())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_length1;
        break;
      }
      
      // optional uint32 length1 = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_length1:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &length1_)));
          set_has_length1();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_offset2;
        break;
      }
      
      // repeated uint32 offset2 = 6 [packed = true];
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_offset2:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_offset2())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 50, input, this->mutable_offset2())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_length2;
        break;
      }
      
      // optional uint32 length2 = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_length2:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &length2_)));
          set_has_length2();
        } else {
          goto handle_uninterpreted;
        }
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

void NearbyHits_NearbyHit::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string pageuri = 1;
  if (has_pageuri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pageuri().data(), this->pageuri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->pageuri(), output);
  }
  
  // required uint32 fragment = 2;
  if (has_fragment()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->fragment(), output);
  }
  
  // repeated uint32 offset1 = 4 [packed = true];
  if (this->offset1_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(4, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_offset1_cached_byte_size_);
  }
  for (int i = 0; i < this->offset1_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->offset1(i), output);
  }
  
  // optional uint32 length1 = 5;
  if (has_length1()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->length1(), output);
  }
  
  // repeated uint32 offset2 = 6 [packed = true];
  if (this->offset2_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(6, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_offset2_cached_byte_size_);
  }
  for (int i = 0; i < this->offset2_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->offset2(i), output);
  }
  
  // optional uint32 length2 = 7;
  if (has_length2()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->length2(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* NearbyHits_NearbyHit::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string pageuri = 1;
  if (has_pageuri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pageuri().data(), this->pageuri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->pageuri(), target);
  }
  
  // required uint32 fragment = 2;
  if (has_fragment()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->fragment(), target);
  }
  
  // repeated uint32 offset1 = 4 [packed = true];
  if (this->offset1_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      4,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _offset1_cached_byte_size_, target);
  }
  for (int i = 0; i < this->offset1_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->offset1(i), target);
  }
  
  // optional uint32 length1 = 5;
  if (has_length1()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->length1(), target);
  }
  
  // repeated uint32 offset2 = 6 [packed = true];
  if (this->offset2_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      6,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _offset2_cached_byte_size_, target);
  }
  for (int i = 0; i < this->offset2_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->offset2(i), target);
  }
  
  // optional uint32 length2 = 7;
  if (has_length2()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->length2(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int NearbyHits_NearbyHit::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string pageuri = 1;
    if (has_pageuri()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->pageuri());
    }
    
    // required uint32 fragment = 2;
    if (has_fragment()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fragment());
    }
    
    // optional uint32 length1 = 5;
    if (has_length1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->length1());
    }
    
    // optional uint32 length2 = 7;
    if (has_length2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->length2());
    }
    
  }
  // repeated uint32 offset1 = 4 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->offset1_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->offset1(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _offset1_cached_byte_size_ = data_size;
    total_size += data_size;
  }
  
  // repeated uint32 offset2 = 6 [packed = true];
  {
    int data_size = 0;
    for (int i = 0; i < this->offset2_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->offset2(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    _offset2_cached_byte_size_ = data_size;
    total_size += data_size;
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

void NearbyHits_NearbyHit::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const NearbyHits_NearbyHit* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const NearbyHits_NearbyHit*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void NearbyHits_NearbyHit::MergeFrom(const NearbyHits_NearbyHit& from) {
  GOOGLE_CHECK_NE(&from, this);
  offset1_.MergeFrom(from.offset1_);
  offset2_.MergeFrom(from.offset2_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pageuri()) {
      set_pageuri(from.pageuri());
    }
    if (from.has_fragment()) {
      set_fragment(from.fragment());
    }
    if (from.has_length1()) {
      set_length1(from.length1());
    }
    if (from.has_length2()) {
      set_length2(from.length2());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void NearbyHits_NearbyHit::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NearbyHits_NearbyHit::CopyFrom(const NearbyHits_NearbyHit& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NearbyHits_NearbyHit::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void NearbyHits_NearbyHit::Swap(NearbyHits_NearbyHit* other) {
  if (other != this) {
    std::swap(pageuri_, other->pageuri_);
    std::swap(fragment_, other->fragment_);
    offset1_.Swap(&other->offset1_);
    std::swap(length1_, other->length1_);
    offset2_.Swap(&other->offset2_);
    std::swap(length2_, other->length2_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata NearbyHits_NearbyHit::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NearbyHits_NearbyHit_descriptor_;
  metadata.reflection = NearbyHits_NearbyHit_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int NearbyHits::kTerm1FieldNumber;
const int NearbyHits::kTerm2FieldNumber;
const int NearbyHits::kNearbyhitsFieldNumber;
#endif  // !_MSC_VER

NearbyHits::NearbyHits()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void NearbyHits::InitAsDefaultInstance() {
}

NearbyHits::NearbyHits(const NearbyHits& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void NearbyHits::SharedCtor() {
  _cached_size_ = 0;
  term1_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  term2_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NearbyHits::~NearbyHits() {
  SharedDtor();
}

void NearbyHits::SharedDtor() {
  if (term1_ != &::google::protobuf::internal::kEmptyString) {
    delete term1_;
  }
  if (term2_ != &::google::protobuf::internal::kEmptyString) {
    delete term2_;
  }
  if (this != default_instance_) {
  }
}

void NearbyHits::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NearbyHits::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NearbyHits_descriptor_;
}

const NearbyHits& NearbyHits::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();  return *default_instance_;
}

NearbyHits* NearbyHits::default_instance_ = NULL;

NearbyHits* NearbyHits::New() const {
  return new NearbyHits;
}

void NearbyHits::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_term1()) {
      if (term1_ != &::google::protobuf::internal::kEmptyString) {
        term1_->clear();
      }
    }
    if (has_term2()) {
      if (term2_ != &::google::protobuf::internal::kEmptyString) {
        term2_->clear();
      }
    }
  }
  nearbyhits_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool NearbyHits::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string term1 = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_term1()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->term1().data(), this->term1().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_term2;
        break;
      }
      
      // required string term2 = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_term2:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_term2()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->term2().data(), this->term2().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_nearbyhits;
        break;
      }
      
      // repeated .Message.NearbyHits nearbyhits = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_nearbyhits:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_nearbyhits()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_nearbyhits;
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

void NearbyHits::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string term1 = 1;
  if (has_term1()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term1().data(), this->term1().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->term1(), output);
  }
  
  // required string term2 = 2;
  if (has_term2()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term2().data(), this->term2().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->term2(), output);
  }
  
  // repeated .Message.NearbyHits nearbyhits = 3;
  for (int i = 0; i < this->nearbyhits_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->nearbyhits(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* NearbyHits::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string term1 = 1;
  if (has_term1()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term1().data(), this->term1().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->term1(), target);
  }
  
  // required string term2 = 2;
  if (has_term2()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term2().data(), this->term2().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->term2(), target);
  }
  
  // repeated .Message.NearbyHits nearbyhits = 3;
  for (int i = 0; i < this->nearbyhits_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->nearbyhits(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int NearbyHits::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string term1 = 1;
    if (has_term1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->term1());
    }
    
    // required string term2 = 2;
    if (has_term2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->term2());
    }
    
  }
  // repeated .Message.NearbyHits nearbyhits = 3;
  total_size += 1 * this->nearbyhits_size();
  for (int i = 0; i < this->nearbyhits_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->nearbyhits(i));
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

void NearbyHits::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const NearbyHits* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const NearbyHits*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void NearbyHits::MergeFrom(const NearbyHits& from) {
  GOOGLE_CHECK_NE(&from, this);
  nearbyhits_.MergeFrom(from.nearbyhits_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_term1()) {
      set_term1(from.term1());
    }
    if (from.has_term2()) {
      set_term2(from.term2());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void NearbyHits::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NearbyHits::CopyFrom(const NearbyHits& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NearbyHits::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  for (int i = 0; i < nearbyhits_size(); i++) {
    if (!this->nearbyhits(i).IsInitialized()) return false;
  }
  return true;
}

void NearbyHits::Swap(NearbyHits* other) {
  if (other != this) {
    std::swap(term1_, other->term1_);
    std::swap(term2_, other->term2_);
    nearbyhits_.Swap(&other->nearbyhits_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata NearbyHits::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NearbyHits_descriptor_;
  metadata.reflection = NearbyHits_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Results_Result::kPageuriFieldNumber;
const int Results_Result::kTerm1FieldNumber;
const int Results_Result::kTerm2FieldNumber;
#endif  // !_MSC_VER

Results_Result::Results_Result()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Results_Result::InitAsDefaultInstance() {
}

Results_Result::Results_Result(const Results_Result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Results_Result::SharedCtor() {
  _cached_size_ = 0;
  pageuri_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  term1_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  term2_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Results_Result::~Results_Result() {
  SharedDtor();
}

void Results_Result::SharedDtor() {
  if (pageuri_ != &::google::protobuf::internal::kEmptyString) {
    delete pageuri_;
  }
  if (term1_ != &::google::protobuf::internal::kEmptyString) {
    delete term1_;
  }
  if (term2_ != &::google::protobuf::internal::kEmptyString) {
    delete term2_;
  }
  if (this != default_instance_) {
  }
}

void Results_Result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Results_Result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Results_Result_descriptor_;
}

const Results_Result& Results_Result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();  return *default_instance_;
}

Results_Result* Results_Result::default_instance_ = NULL;

Results_Result* Results_Result::New() const {
  return new Results_Result;
}

void Results_Result::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_pageuri()) {
      if (pageuri_ != &::google::protobuf::internal::kEmptyString) {
        pageuri_->clear();
      }
    }
    if (has_term1()) {
      if (term1_ != &::google::protobuf::internal::kEmptyString) {
        term1_->clear();
      }
    }
    if (has_term2()) {
      if (term2_ != &::google::protobuf::internal::kEmptyString) {
        term2_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Results_Result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string pageuri = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_pageuri()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->pageuri().data(), this->pageuri().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_term1;
        break;
      }
      
      // required string term1 = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_term1:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_term1()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->term1().data(), this->term1().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_term2;
        break;
      }
      
      // required string term2 = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_term2:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_term2()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->term2().data(), this->term2().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
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

void Results_Result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string pageuri = 1;
  if (has_pageuri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pageuri().data(), this->pageuri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->pageuri(), output);
  }
  
  // required string term1 = 2;
  if (has_term1()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term1().data(), this->term1().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->term1(), output);
  }
  
  // required string term2 = 3;
  if (has_term2()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term2().data(), this->term2().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->term2(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Results_Result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string pageuri = 1;
  if (has_pageuri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pageuri().data(), this->pageuri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->pageuri(), target);
  }
  
  // required string term1 = 2;
  if (has_term1()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term1().data(), this->term1().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->term1(), target);
  }
  
  // required string term2 = 3;
  if (has_term2()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->term2().data(), this->term2().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->term2(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Results_Result::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string pageuri = 1;
    if (has_pageuri()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->pageuri());
    }
    
    // required string term1 = 2;
    if (has_term1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->term1());
    }
    
    // required string term2 = 3;
    if (has_term2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->term2());
    }
    
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

void Results_Result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Results_Result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Results_Result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Results_Result::MergeFrom(const Results_Result& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pageuri()) {
      set_pageuri(from.pageuri());
    }
    if (from.has_term1()) {
      set_term1(from.term1());
    }
    if (from.has_term2()) {
      set_term2(from.term2());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Results_Result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Results_Result::CopyFrom(const Results_Result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Results_Result::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void Results_Result::Swap(Results_Result* other) {
  if (other != this) {
    std::swap(pageuri_, other->pageuri_);
    std::swap(term1_, other->term1_);
    std::swap(term2_, other->term2_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Results_Result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Results_Result_descriptor_;
  metadata.reflection = Results_Result_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int Results::kResultsFieldNumber;
const int Results::kNumResultsFieldNumber;
#endif  // !_MSC_VER

Results::Results()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Results::InitAsDefaultInstance() {
}

Results::Results(const Results& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Results::SharedCtor() {
  _cached_size_ = 0;
  numresults_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Results::~Results() {
  SharedDtor();
}

void Results::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Results::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Results::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Results_descriptor_;
}

const Results& Results::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();  return *default_instance_;
}

Results* Results::default_instance_ = NULL;

Results* Results::New() const {
  return new Results;
}

void Results::Clear() {
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    numresults_ = 0u;
  }
  results_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Results::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Message.Results.Result results = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_results:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_results()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_results;
        if (input->ExpectTag(16)) goto parse_numResults;
        break;
      }
      
      // optional uint32 numResults = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_numResults:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &numresults_)));
          set_has_numresults();
        } else {
          goto handle_uninterpreted;
        }
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

void Results::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Message.Results.Result results = 1;
  for (int i = 0; i < this->results_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->results(i), output);
  }
  
  // optional uint32 numResults = 2;
  if (has_numresults()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->numresults(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Results::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Message.Results.Result results = 1;
  for (int i = 0; i < this->results_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->results(i), target);
  }
  
  // optional uint32 numResults = 2;
  if (has_numresults()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->numresults(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Results::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional uint32 numResults = 2;
    if (has_numresults()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->numresults());
    }
    
  }
  // repeated .Message.Results.Result results = 1;
  total_size += 1 * this->results_size();
  for (int i = 0; i < this->results_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->results(i));
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

void Results::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Results* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Results*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Results::MergeFrom(const Results& from) {
  GOOGLE_CHECK_NE(&from, this);
  results_.MergeFrom(from.results_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_numresults()) {
      set_numresults(from.numresults());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Results::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Results::CopyFrom(const Results& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Results::IsInitialized() const {
  
  for (int i = 0; i < results_size(); i++) {
    if (!this->results(i).IsInitialized()) return false;
  }
  return true;
}

void Results::Swap(Results* other) {
  if (other != this) {
    results_.Swap(&other->results_);
    std::swap(numresults_, other->numresults_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Results::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Results_descriptor_;
  metadata.reflection = Results_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
