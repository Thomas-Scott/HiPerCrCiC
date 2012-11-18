#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "docs.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Pages {

namespace {

const ::google::protobuf::Descriptor* Page_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Page_reflection_ = NULL;
const ::google::protobuf::Descriptor* Page_Fragment_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Page_Fragment_reflection_ = NULL;
const ::google::protobuf::Descriptor* Author_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Author_reflection_ = NULL;
const ::google::protobuf::Descriptor* Date_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Date_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_docs_2eproto() {
  protobuf_AddDesc_docs_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "docs.proto");
  GOOGLE_CHECK(file != NULL);
  Page_descriptor_ = file->message_type(0);
  static const int Page_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, uri_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, title_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, fragment_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, date_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, author_),
  };
  Page_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Page_descriptor_,
      Page::default_instance_,
      Page_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Page));
  Page_Fragment_descriptor_ = Page_descriptor_->nested_type(0);
  static const int Page_Fragment_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page_Fragment, text_),
  };
  Page_Fragment_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Page_Fragment_descriptor_,
      Page_Fragment::default_instance_,
      Page_Fragment_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page_Fragment, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Page_Fragment, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Page_Fragment));
  Author_descriptor_ = file->message_type(1);
  static const int Author_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Author, first_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Author, last_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Author, middle_),
  };
  Author_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Author_descriptor_,
      Author::default_instance_,
      Author_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Author, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Author, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Author));
  Date_descriptor_ = file->message_type(2);
  static const int Date_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Date, year_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Date, month_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Date, day_),
  };
  Date_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Date_descriptor_,
      Date::default_instance_,
      Date_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Date, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Date, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Date));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_docs_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Page_descriptor_, &Page::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Page_Fragment_descriptor_, &Page_Fragment::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Author_descriptor_, &Author::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Date_descriptor_, &Date::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_docs_2eproto() {
  delete Page::default_instance_;
  delete Page_reflection_;
  delete Page_Fragment::default_instance_;
  delete Page_Fragment_reflection_;
  delete Author::default_instance_;
  delete Author_reflection_;
  delete Date::default_instance_;
  delete Date_reflection_;
}

void protobuf_AddDesc_docs_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ndocs.proto\022\005Pages\"\236\001\n\004Page\022\013\n\003uri\030\001 \002("
    "\t\022\r\n\005title\030\002 \003(\t\022&\n\010fragment\030\003 \003(\0132\024.Pag"
    "es.Page.Fragment\022\031\n\004date\030\004 \003(\0132\013.Pages.D"
    "ate\022\035\n\006author\030\005 \003(\0132\r.Pages.Author\032\030\n\010Fr"
    "agment\022\014\n\004text\030\001 \002(\t\"5\n\006Author\022\r\n\005first\030"
    "\001 \003(\t\022\014\n\004last\030\002 \003(\t\022\016\n\006middle\030\003 \003(\t\"0\n\004D"
    "ate\022\014\n\004year\030\001 \001(\r\022\r\n\005month\030\002 \001(\r\022\013\n\003day\030"
    "\003 \001(\rB\002H\001", 289);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "docs.proto", &protobuf_RegisterTypes);
  Page::default_instance_ = new Page();
  Page_Fragment::default_instance_ = new Page_Fragment();
  Author::default_instance_ = new Author();
  Date::default_instance_ = new Date();
  Page::default_instance_->InitAsDefaultInstance();
  Page_Fragment::default_instance_->InitAsDefaultInstance();
  Author::default_instance_->InitAsDefaultInstance();
  Date::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_docs_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_docs_2eproto {
  StaticDescriptorInitializer_docs_2eproto() {
    protobuf_AddDesc_docs_2eproto();
  }
} static_descriptor_initializer_docs_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int Page_Fragment::kTextFieldNumber;
#endif  // !_MSC_VER

Page_Fragment::Page_Fragment()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Page_Fragment::InitAsDefaultInstance() {
}

Page_Fragment::Page_Fragment(const Page_Fragment& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Page_Fragment::SharedCtor() {
  _cached_size_ = 0;
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Page_Fragment::~Page_Fragment() {
  SharedDtor();
}

void Page_Fragment::SharedDtor() {
  if (text_ != &::google::protobuf::internal::kEmptyString) {
    delete text_;
  }
  if (this != default_instance_) {
  }
}

void Page_Fragment::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Page_Fragment::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Page_Fragment_descriptor_;
}

const Page_Fragment& Page_Fragment::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_docs_2eproto();  return *default_instance_;
}

Page_Fragment* Page_Fragment::default_instance_ = NULL;

Page_Fragment* Page_Fragment::New() const {
  return new Page_Fragment;
}

void Page_Fragment::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_text()) {
      if (text_ != &::google::protobuf::internal::kEmptyString) {
        text_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Page_Fragment::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string text = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->text().data(), this->text().length(),
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

void Page_Fragment::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string text = 1;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->text(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Page_Fragment::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string text = 1;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->text(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Page_Fragment::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string text = 1;
    if (has_text()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
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

void Page_Fragment::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Page_Fragment* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Page_Fragment*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Page_Fragment::MergeFrom(const Page_Fragment& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_text()) {
      set_text(from.text());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Page_Fragment::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Page_Fragment::CopyFrom(const Page_Fragment& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Page_Fragment::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  return true;
}

void Page_Fragment::Swap(Page_Fragment* other) {
  if (other != this) {
    std::swap(text_, other->text_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Page_Fragment::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Page_Fragment_descriptor_;
  metadata.reflection = Page_Fragment_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int Page::kUriFieldNumber;
const int Page::kTitleFieldNumber;
const int Page::kFragmentFieldNumber;
const int Page::kDateFieldNumber;
const int Page::kAuthorFieldNumber;
#endif  // !_MSC_VER

Page::Page()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Page::InitAsDefaultInstance() {
}

Page::Page(const Page& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Page::SharedCtor() {
  _cached_size_ = 0;
  uri_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Page::~Page() {
  SharedDtor();
}

void Page::SharedDtor() {
  if (uri_ != &::google::protobuf::internal::kEmptyString) {
    delete uri_;
  }
  if (this != default_instance_) {
  }
}

void Page::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Page::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Page_descriptor_;
}

const Page& Page::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_docs_2eproto();  return *default_instance_;
}

Page* Page::default_instance_ = NULL;

Page* Page::New() const {
  return new Page;
}

void Page::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_uri()) {
      if (uri_ != &::google::protobuf::internal::kEmptyString) {
        uri_->clear();
      }
    }
  }
  title_.Clear();
  fragment_.Clear();
  date_.Clear();
  author_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Page::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string uri = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_uri()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->uri().data(), this->uri().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_title;
        break;
      }
      
      // repeated string title = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_title:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_title()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->title(0).data(), this->title(0).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_title;
        if (input->ExpectTag(26)) goto parse_fragment;
        break;
      }
      
      // repeated .Pages.Page.Fragment fragment = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_fragment:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_fragment()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_fragment;
        if (input->ExpectTag(34)) goto parse_date;
        break;
      }
      
      // repeated .Pages.Date date = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_date:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_date()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_date;
        if (input->ExpectTag(42)) goto parse_author;
        break;
      }
      
      // repeated .Pages.Author author = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_author:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_author()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_author;
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

void Page::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string uri = 1;
  if (has_uri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->uri().data(), this->uri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->uri(), output);
  }
  
  // repeated string title = 2;
  for (int i = 0; i < this->title_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->title(i).data(), this->title(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->title(i), output);
  }
  
  // repeated .Pages.Page.Fragment fragment = 3;
  for (int i = 0; i < this->fragment_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->fragment(i), output);
  }
  
  // repeated .Pages.Date date = 4;
  for (int i = 0; i < this->date_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->date(i), output);
  }
  
  // repeated .Pages.Author author = 5;
  for (int i = 0; i < this->author_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->author(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Page::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string uri = 1;
  if (has_uri()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->uri().data(), this->uri().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->uri(), target);
  }
  
  // repeated string title = 2;
  for (int i = 0; i < this->title_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->title(i).data(), this->title(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->title(i), target);
  }
  
  // repeated .Pages.Page.Fragment fragment = 3;
  for (int i = 0; i < this->fragment_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->fragment(i), target);
  }
  
  // repeated .Pages.Date date = 4;
  for (int i = 0; i < this->date_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->date(i), target);
  }
  
  // repeated .Pages.Author author = 5;
  for (int i = 0; i < this->author_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->author(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Page::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string uri = 1;
    if (has_uri()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->uri());
    }
    
  }
  // repeated string title = 2;
  total_size += 1 * this->title_size();
  for (int i = 0; i < this->title_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->title(i));
  }
  
  // repeated .Pages.Page.Fragment fragment = 3;
  total_size += 1 * this->fragment_size();
  for (int i = 0; i < this->fragment_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->fragment(i));
  }
  
  // repeated .Pages.Date date = 4;
  total_size += 1 * this->date_size();
  for (int i = 0; i < this->date_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->date(i));
  }
  
  // repeated .Pages.Author author = 5;
  total_size += 1 * this->author_size();
  for (int i = 0; i < this->author_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->author(i));
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

void Page::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Page* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Page*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Page::MergeFrom(const Page& from) {
  GOOGLE_CHECK_NE(&from, this);
  title_.MergeFrom(from.title_);
  fragment_.MergeFrom(from.fragment_);
  date_.MergeFrom(from.date_);
  author_.MergeFrom(from.author_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_uri()) {
      set_uri(from.uri());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Page::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Page::CopyFrom(const Page& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Page::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  for (int i = 0; i < fragment_size(); i++) {
    if (!this->fragment(i).IsInitialized()) return false;
  }
  return true;
}

void Page::Swap(Page* other) {
  if (other != this) {
    std::swap(uri_, other->uri_);
    title_.Swap(&other->title_);
    fragment_.Swap(&other->fragment_);
    date_.Swap(&other->date_);
    author_.Swap(&other->author_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Page::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Page_descriptor_;
  metadata.reflection = Page_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Author::kFirstFieldNumber;
const int Author::kLastFieldNumber;
const int Author::kMiddleFieldNumber;
#endif  // !_MSC_VER

Author::Author()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Author::InitAsDefaultInstance() {
}

Author::Author(const Author& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Author::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Author::~Author() {
  SharedDtor();
}

void Author::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Author::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Author::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Author_descriptor_;
}

const Author& Author::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_docs_2eproto();  return *default_instance_;
}

Author* Author::default_instance_ = NULL;

Author* Author::New() const {
  return new Author;
}

void Author::Clear() {
  first_.Clear();
  last_.Clear();
  middle_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Author::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated string first = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_first:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_first()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->first(0).data(), this->first(0).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_first;
        if (input->ExpectTag(18)) goto parse_last;
        break;
      }
      
      // repeated string last = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_last:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_last()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->last(0).data(), this->last(0).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_last;
        if (input->ExpectTag(26)) goto parse_middle;
        break;
      }
      
      // repeated string middle = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_middle:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_middle()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->middle(0).data(), this->middle(0).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_middle;
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

void Author::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated string first = 1;
  for (int i = 0; i < this->first_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->first(i).data(), this->first(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->first(i), output);
  }
  
  // repeated string last = 2;
  for (int i = 0; i < this->last_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->last(i).data(), this->last(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->last(i), output);
  }
  
  // repeated string middle = 3;
  for (int i = 0; i < this->middle_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->middle(i).data(), this->middle(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->middle(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Author::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated string first = 1;
  for (int i = 0; i < this->first_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->first(i).data(), this->first(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(1, this->first(i), target);
  }
  
  // repeated string last = 2;
  for (int i = 0; i < this->last_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->last(i).data(), this->last(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->last(i), target);
  }
  
  // repeated string middle = 3;
  for (int i = 0; i < this->middle_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->middle(i).data(), this->middle(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(3, this->middle(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Author::ByteSize() const {
  int total_size = 0;
  
  // repeated string first = 1;
  total_size += 1 * this->first_size();
  for (int i = 0; i < this->first_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->first(i));
  }
  
  // repeated string last = 2;
  total_size += 1 * this->last_size();
  for (int i = 0; i < this->last_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->last(i));
  }
  
  // repeated string middle = 3;
  total_size += 1 * this->middle_size();
  for (int i = 0; i < this->middle_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->middle(i));
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

void Author::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Author* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Author*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Author::MergeFrom(const Author& from) {
  GOOGLE_CHECK_NE(&from, this);
  first_.MergeFrom(from.first_);
  last_.MergeFrom(from.last_);
  middle_.MergeFrom(from.middle_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Author::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Author::CopyFrom(const Author& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Author::IsInitialized() const {
  
  return true;
}

void Author::Swap(Author* other) {
  if (other != this) {
    first_.Swap(&other->first_);
    last_.Swap(&other->last_);
    middle_.Swap(&other->middle_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Author::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Author_descriptor_;
  metadata.reflection = Author_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Date::kYearFieldNumber;
const int Date::kMonthFieldNumber;
const int Date::kDayFieldNumber;
#endif  // !_MSC_VER

Date::Date()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Date::InitAsDefaultInstance() {
}

Date::Date(const Date& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Date::SharedCtor() {
  _cached_size_ = 0;
  year_ = 0u;
  month_ = 0u;
  day_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Date::~Date() {
  SharedDtor();
}

void Date::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Date::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Date::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Date_descriptor_;
}

const Date& Date::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_docs_2eproto();  return *default_instance_;
}

Date* Date::default_instance_ = NULL;

Date* Date::New() const {
  return new Date;
}

void Date::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    year_ = 0u;
    month_ = 0u;
    day_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Date::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 year = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &year_)));
          set_has_year();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_month;
        break;
      }
      
      // optional uint32 month = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_month:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &month_)));
          set_has_month();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_day;
        break;
      }
      
      // optional uint32 day = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_day:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &day_)));
          set_has_day();
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

void Date::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional uint32 year = 1;
  if (has_year()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->year(), output);
  }
  
  // optional uint32 month = 2;
  if (has_month()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->month(), output);
  }
  
  // optional uint32 day = 3;
  if (has_day()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->day(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Date::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional uint32 year = 1;
  if (has_year()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->year(), target);
  }
  
  // optional uint32 month = 2;
  if (has_month()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->month(), target);
  }
  
  // optional uint32 day = 3;
  if (has_day()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->day(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Date::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 year = 1;
    if (has_year()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->year());
    }
    
    // optional uint32 month = 2;
    if (has_month()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->month());
    }
    
    // optional uint32 day = 3;
    if (has_day()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->day());
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

void Date::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Date* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Date*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Date::MergeFrom(const Date& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_year()) {
      set_year(from.year());
    }
    if (from.has_month()) {
      set_month(from.month());
    }
    if (from.has_day()) {
      set_day(from.day());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Date::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Date::CopyFrom(const Date& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Date::IsInitialized() const {
  
  return true;
}

void Date::Swap(Date* other) {
  if (other != this) {
    std::swap(year_, other->year_);
    std::swap(month_, other->month_);
    std::swap(day_, other->day_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Date::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Date_descriptor_;
  metadata.reflection = Date_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Pages

// @@protoc_insertion_point(global_scope)
