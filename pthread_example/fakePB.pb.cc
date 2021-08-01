// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fakePB.proto

#include "fakePB.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace myFakePb {
constexpr ACC_DATA::ACC_DATA(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : x_axis_(0)
  , y_axis_(0)
  , z_axis_(0){}
struct ACC_DATADefaultTypeInternal {
  constexpr ACC_DATADefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ACC_DATADefaultTypeInternal() {}
  union {
    ACC_DATA _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ACC_DATADefaultTypeInternal _ACC_DATA_default_instance_;
constexpr DATAPACK::DATAPACK(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : data_()
  , cmd_(0u){}
struct DATAPACKDefaultTypeInternal {
  constexpr DATAPACKDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DATAPACKDefaultTypeInternal() {}
  union {
    DATAPACK _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DATAPACKDefaultTypeInternal _DATAPACK_default_instance_;
}  // namespace myFakePb
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_fakePB_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_fakePB_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_fakePB_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_fakePB_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::myFakePb::ACC_DATA, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::myFakePb::ACC_DATA, x_axis_),
  PROTOBUF_FIELD_OFFSET(::myFakePb::ACC_DATA, y_axis_),
  PROTOBUF_FIELD_OFFSET(::myFakePb::ACC_DATA, z_axis_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::myFakePb::DATAPACK, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::myFakePb::DATAPACK, cmd_),
  PROTOBUF_FIELD_OFFSET(::myFakePb::DATAPACK, data_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::myFakePb::ACC_DATA)},
  { 8, -1, sizeof(::myFakePb::DATAPACK)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::myFakePb::_ACC_DATA_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::myFakePb::_DATAPACK_default_instance_),
};

const char descriptor_table_protodef_fakePB_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014fakePB.proto\022\010myFakePb\":\n\010ACC_DATA\022\016\n\006"
  "x_axis\030\001 \001(\005\022\016\n\006y_axis\030\002 \001(\005\022\016\n\006z_axis\030\003"
  " \001(\005\"9\n\010DATAPACK\022\013\n\003cmd\030\001 \001(\r\022 \n\004data\030\002 "
  "\003(\0132\022.myFakePb.ACC_DATAb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_fakePB_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_fakePB_2eproto = {
  false, false, 151, descriptor_table_protodef_fakePB_2eproto, "fakePB.proto", 
  &descriptor_table_fakePB_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_fakePB_2eproto::offsets,
  file_level_metadata_fakePB_2eproto, file_level_enum_descriptors_fakePB_2eproto, file_level_service_descriptors_fakePB_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_fakePB_2eproto_getter() {
  return &descriptor_table_fakePB_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_fakePB_2eproto(&descriptor_table_fakePB_2eproto);
namespace myFakePb {

// ===================================================================

class ACC_DATA::_Internal {
 public:
};

ACC_DATA::ACC_DATA(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:myFakePb.ACC_DATA)
}
ACC_DATA::ACC_DATA(const ACC_DATA& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&x_axis_, &from.x_axis_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_axis_) -
    reinterpret_cast<char*>(&x_axis_)) + sizeof(z_axis_));
  // @@protoc_insertion_point(copy_constructor:myFakePb.ACC_DATA)
}

inline void ACC_DATA::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&x_axis_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&z_axis_) -
    reinterpret_cast<char*>(&x_axis_)) + sizeof(z_axis_));
}

ACC_DATA::~ACC_DATA() {
  // @@protoc_insertion_point(destructor:myFakePb.ACC_DATA)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ACC_DATA::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ACC_DATA::ArenaDtor(void* object) {
  ACC_DATA* _this = reinterpret_cast< ACC_DATA* >(object);
  (void)_this;
}
void ACC_DATA::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ACC_DATA::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ACC_DATA::Clear() {
// @@protoc_insertion_point(message_clear_start:myFakePb.ACC_DATA)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&x_axis_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&z_axis_) -
      reinterpret_cast<char*>(&x_axis_)) + sizeof(z_axis_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ACC_DATA::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 x_axis = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          x_axis_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 y_axis = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          y_axis_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 z_axis = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          z_axis_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ACC_DATA::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:myFakePb.ACC_DATA)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 x_axis = 1;
  if (this->_internal_x_axis() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_x_axis(), target);
  }

  // int32 y_axis = 2;
  if (this->_internal_y_axis() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_y_axis(), target);
  }

  // int32 z_axis = 3;
  if (this->_internal_z_axis() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_z_axis(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:myFakePb.ACC_DATA)
  return target;
}

size_t ACC_DATA::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:myFakePb.ACC_DATA)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 x_axis = 1;
  if (this->_internal_x_axis() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_x_axis());
  }

  // int32 y_axis = 2;
  if (this->_internal_y_axis() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_y_axis());
  }

  // int32 z_axis = 3;
  if (this->_internal_z_axis() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_z_axis());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ACC_DATA::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ACC_DATA::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ACC_DATA::GetClassData() const { return &_class_data_; }

void ACC_DATA::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<ACC_DATA *>(to)->MergeFrom(
      static_cast<const ACC_DATA &>(from));
}


void ACC_DATA::MergeFrom(const ACC_DATA& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:myFakePb.ACC_DATA)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_x_axis() != 0) {
    _internal_set_x_axis(from._internal_x_axis());
  }
  if (from._internal_y_axis() != 0) {
    _internal_set_y_axis(from._internal_y_axis());
  }
  if (from._internal_z_axis() != 0) {
    _internal_set_z_axis(from._internal_z_axis());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ACC_DATA::CopyFrom(const ACC_DATA& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:myFakePb.ACC_DATA)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ACC_DATA::IsInitialized() const {
  return true;
}

void ACC_DATA::InternalSwap(ACC_DATA* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ACC_DATA, z_axis_)
      + sizeof(ACC_DATA::z_axis_)
      - PROTOBUF_FIELD_OFFSET(ACC_DATA, x_axis_)>(
          reinterpret_cast<char*>(&x_axis_),
          reinterpret_cast<char*>(&other->x_axis_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ACC_DATA::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_fakePB_2eproto_getter, &descriptor_table_fakePB_2eproto_once,
      file_level_metadata_fakePB_2eproto[0]);
}

// ===================================================================

class DATAPACK::_Internal {
 public:
};

DATAPACK::DATAPACK(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  data_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:myFakePb.DATAPACK)
}
DATAPACK::DATAPACK(const DATAPACK& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      data_(from.data_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  cmd_ = from.cmd_;
  // @@protoc_insertion_point(copy_constructor:myFakePb.DATAPACK)
}

inline void DATAPACK::SharedCtor() {
cmd_ = 0u;
}

DATAPACK::~DATAPACK() {
  // @@protoc_insertion_point(destructor:myFakePb.DATAPACK)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void DATAPACK::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void DATAPACK::ArenaDtor(void* object) {
  DATAPACK* _this = reinterpret_cast< DATAPACK* >(object);
  (void)_this;
}
void DATAPACK::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DATAPACK::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void DATAPACK::Clear() {
// @@protoc_insertion_point(message_clear_start:myFakePb.DATAPACK)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  cmd_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* DATAPACK::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 cmd = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          cmd_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .myFakePb.ACC_DATA data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_data(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* DATAPACK::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:myFakePb.DATAPACK)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 cmd = 1;
  if (this->_internal_cmd() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_cmd(), target);
  }

  // repeated .myFakePb.ACC_DATA data = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_data_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_data(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:myFakePb.DATAPACK)
  return target;
}

size_t DATAPACK::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:myFakePb.DATAPACK)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .myFakePb.ACC_DATA data = 2;
  total_size += 1UL * this->_internal_data_size();
  for (const auto& msg : this->data_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint32 cmd = 1;
  if (this->_internal_cmd() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_cmd());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData DATAPACK::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    DATAPACK::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*DATAPACK::GetClassData() const { return &_class_data_; }

void DATAPACK::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<DATAPACK *>(to)->MergeFrom(
      static_cast<const DATAPACK &>(from));
}


void DATAPACK::MergeFrom(const DATAPACK& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:myFakePb.DATAPACK)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
  if (from._internal_cmd() != 0) {
    _internal_set_cmd(from._internal_cmd());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void DATAPACK::CopyFrom(const DATAPACK& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:myFakePb.DATAPACK)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DATAPACK::IsInitialized() const {
  return true;
}

void DATAPACK::InternalSwap(DATAPACK* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  data_.InternalSwap(&other->data_);
  swap(cmd_, other->cmd_);
}

::PROTOBUF_NAMESPACE_ID::Metadata DATAPACK::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_fakePB_2eproto_getter, &descriptor_table_fakePB_2eproto_once,
      file_level_metadata_fakePB_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace myFakePb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::myFakePb::ACC_DATA* Arena::CreateMaybeMessage< ::myFakePb::ACC_DATA >(Arena* arena) {
  return Arena::CreateMessageInternal< ::myFakePb::ACC_DATA >(arena);
}
template<> PROTOBUF_NOINLINE ::myFakePb::DATAPACK* Arena::CreateMaybeMessage< ::myFakePb::DATAPACK >(Arena* arena) {
  return Arena::CreateMessageInternal< ::myFakePb::DATAPACK >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
