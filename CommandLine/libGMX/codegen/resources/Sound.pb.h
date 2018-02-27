// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: resources/Sound.proto

#ifndef PROTOBUF_resources_2fSound_2eproto__INCLUDED
#define PROTOBUF_resources_2fSound_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "options.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_resources_2fSound_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsSoundImpl();
void InitDefaultsSound();
inline void InitDefaults() {
  InitDefaultsSound();
}
}  // namespace protobuf_resources_2fSound_2eproto
namespace buffers {
namespace resources {
class Sound;
class SoundDefaultTypeInternal;
extern SoundDefaultTypeInternal _Sound_default_instance_;
}  // namespace resources
}  // namespace buffers
namespace buffers {
namespace resources {

enum Sound_Kind {
  Sound_Kind_NORMAL = 0,
  Sound_Kind_BACKGROUND_MUSIC = 1,
  Sound_Kind_THREE_DIMENSIONAL = 2,
  Sound_Kind_MULTIMEDIA_PLAYER = 3
};
bool Sound_Kind_IsValid(int value);
const Sound_Kind Sound_Kind_Kind_MIN = Sound_Kind_NORMAL;
const Sound_Kind Sound_Kind_Kind_MAX = Sound_Kind_MULTIMEDIA_PLAYER;
const int Sound_Kind_Kind_ARRAYSIZE = Sound_Kind_Kind_MAX + 1;

const ::google::protobuf::EnumDescriptor* Sound_Kind_descriptor();
inline const ::std::string& Sound_Kind_Name(Sound_Kind value) {
  return ::google::protobuf::internal::NameOfEnum(
    Sound_Kind_descriptor(), value);
}
inline bool Sound_Kind_Parse(
    const ::std::string& name, Sound_Kind* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Sound_Kind>(
    Sound_Kind_descriptor(), name, value);
}
enum Sound_Type {
  Sound_Type_MONO = 0,
  Sound_Type_STEREO = 1,
  Sound_Type_POSITIONAL = 2
};
bool Sound_Type_IsValid(int value);
const Sound_Type Sound_Type_Type_MIN = Sound_Type_MONO;
const Sound_Type Sound_Type_Type_MAX = Sound_Type_POSITIONAL;
const int Sound_Type_Type_ARRAYSIZE = Sound_Type_Type_MAX + 1;

const ::google::protobuf::EnumDescriptor* Sound_Type_descriptor();
inline const ::std::string& Sound_Type_Name(Sound_Type value) {
  return ::google::protobuf::internal::NameOfEnum(
    Sound_Type_descriptor(), value);
}
inline bool Sound_Type_Parse(
    const ::std::string& name, Sound_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Sound_Type>(
    Sound_Type_descriptor(), name, value);
}
// ===================================================================

class Sound : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:buffers.resources.Sound) */ {
 public:
  Sound();
  virtual ~Sound();

  Sound(const Sound& from);

  inline Sound& operator=(const Sound& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Sound(Sound&& from) noexcept
    : Sound() {
    *this = ::std::move(from);
  }

  inline Sound& operator=(Sound&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Sound& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Sound* internal_default_instance() {
    return reinterpret_cast<const Sound*>(
               &_Sound_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Sound* other);
  friend void swap(Sound& a, Sound& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Sound* New() const PROTOBUF_FINAL { return New(NULL); }

  Sound* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Sound& from);
  void MergeFrom(const Sound& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Sound* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef Sound_Kind Kind;
  static const Kind NORMAL =
    Sound_Kind_NORMAL;
  static const Kind BACKGROUND_MUSIC =
    Sound_Kind_BACKGROUND_MUSIC;
  static const Kind THREE_DIMENSIONAL =
    Sound_Kind_THREE_DIMENSIONAL;
  static const Kind MULTIMEDIA_PLAYER =
    Sound_Kind_MULTIMEDIA_PLAYER;
  static inline bool Kind_IsValid(int value) {
    return Sound_Kind_IsValid(value);
  }
  static const Kind Kind_MIN =
    Sound_Kind_Kind_MIN;
  static const Kind Kind_MAX =
    Sound_Kind_Kind_MAX;
  static const int Kind_ARRAYSIZE =
    Sound_Kind_Kind_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Kind_descriptor() {
    return Sound_Kind_descriptor();
  }
  static inline const ::std::string& Kind_Name(Kind value) {
    return Sound_Kind_Name(value);
  }
  static inline bool Kind_Parse(const ::std::string& name,
      Kind* value) {
    return Sound_Kind_Parse(name, value);
  }

  typedef Sound_Type Type;
  static const Type MONO =
    Sound_Type_MONO;
  static const Type STEREO =
    Sound_Type_STEREO;
  static const Type POSITIONAL =
    Sound_Type_POSITIONAL;
  static inline bool Type_IsValid(int value) {
    return Sound_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Sound_Type_Type_MIN;
  static const Type Type_MAX =
    Sound_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Sound_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Type_descriptor() {
    return Sound_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return Sound_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return Sound_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string file_name = 6 [(.buffers.gmx) = "data"];
  bool has_file_name() const;
  void clear_file_name();
  static const int kFileNameFieldNumber = 6;
  const ::std::string& file_name() const;
  void set_file_name(const ::std::string& value);
  #if LANG_CXX11
  void set_file_name(::std::string&& value);
  #endif
  void set_file_name(const char* value);
  void set_file_name(const char* value, size_t size);
  ::std::string* mutable_file_name();
  ::std::string* release_file_name();
  void set_allocated_file_name(::std::string* file_name);

  // optional string file_extension = 7 [(.buffers.gmx) = "extension"];
  bool has_file_extension() const;
  void clear_file_extension();
  static const int kFileExtensionFieldNumber = 7;
  const ::std::string& file_extension() const;
  void set_file_extension(const ::std::string& value);
  #if LANG_CXX11
  void set_file_extension(::std::string&& value);
  #endif
  void set_file_extension(const char* value);
  void set_file_extension(const char* value, size_t size);
  ::std::string* mutable_file_extension();
  ::std::string* release_file_extension();
  void set_allocated_file_extension(::std::string* file_extension);

  // optional string data = 10 [(.buffers.gmx) = "origname", (.buffers.file_path) = true];
  bool has_data() const;
  void clear_data();
  static const int kDataFieldNumber = 10;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const char* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // optional double pan = 4;
  bool has_pan() const;
  void clear_pan();
  static const int kPanFieldNumber = 4;
  double pan() const;
  void set_pan(double value);

  // optional double volume = 5 [(.buffers.gmx) = "volume/volume"];
  bool has_volume() const;
  void clear_volume();
  static const int kVolumeFieldNumber = 5;
  double volume() const;
  void set_volume(double value);

  // optional int32 id = 2 [(.buffers.gmx) = "GMX_DEPRECATED"];
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 2;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional .buffers.resources.Sound.Kind kind = 8;
  bool has_kind() const;
  void clear_kind();
  static const int kKindFieldNumber = 8;
  ::buffers::resources::Sound_Kind kind() const;
  void set_kind(::buffers::resources::Sound_Kind value);

  // optional .buffers.resources.Sound.Type type = 9 [(.buffers.gmx) = "types/type"];
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 9;
  ::buffers::resources::Sound_Type type() const;
  void set_type(::buffers::resources::Sound_Type value);

  // optional int32 effects = 11;
  bool has_effects() const;
  void clear_effects();
  static const int kEffectsFieldNumber = 11;
  ::google::protobuf::int32 effects() const;
  void set_effects(::google::protobuf::int32 value);

  // optional uint32 bit_rate = 12 [(.buffers.gmx) = "bitRates/bitRate"];
  bool has_bit_rate() const;
  void clear_bit_rate();
  static const int kBitRateFieldNumber = 12;
  ::google::protobuf::uint32 bit_rate() const;
  void set_bit_rate(::google::protobuf::uint32 value);

  // optional bool preload = 3;
  bool has_preload() const;
  void clear_preload();
  static const int kPreloadFieldNumber = 3;
  bool preload() const;
  void set_preload(bool value);

  // optional bool compressed = 15;
  bool has_compressed() const;
  void clear_compressed();
  static const int kCompressedFieldNumber = 15;
  bool compressed() const;
  void set_compressed(bool value);

  // optional bool streamed = 16;
  bool has_streamed() const;
  void clear_streamed();
  static const int kStreamedFieldNumber = 16;
  bool streamed() const;
  void set_streamed(bool value);

  // optional bool uncompress_on_load = 17 [(.buffers.gmx) = "uncompressOnLoad"];
  bool has_uncompress_on_load() const;
  void clear_uncompress_on_load();
  static const int kUncompressOnLoadFieldNumber = 17;
  bool uncompress_on_load() const;
  void set_uncompress_on_load(bool value);

  // optional uint32 sample_rate = 13 [(.buffers.gmx) = "sampleRates/sampleRate"];
  bool has_sample_rate() const;
  void clear_sample_rate();
  static const int kSampleRateFieldNumber = 13;
  ::google::protobuf::uint32 sample_rate() const;
  void set_sample_rate(::google::protobuf::uint32 value);

  // optional uint32 bit_depth = 14 [(.buffers.gmx) = "bitDepths/bitDepth"];
  bool has_bit_depth() const;
  void clear_bit_depth();
  static const int kBitDepthFieldNumber = 14;
  ::google::protobuf::uint32 bit_depth() const;
  void set_bit_depth(::google::protobuf::uint32 value);

  // optional int32 audio_group = 18 [(.buffers.gmx) = "audioGroup"];
  bool has_audio_group() const;
  void clear_audio_group();
  static const int kAudioGroupFieldNumber = 18;
  ::google::protobuf::int32 audio_group() const;
  void set_audio_group(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:buffers.resources.Sound)
 private:
  void set_has_name();
  void clear_has_name();
  void set_has_id();
  void clear_has_id();
  void set_has_preload();
  void clear_has_preload();
  void set_has_pan();
  void clear_has_pan();
  void set_has_volume();
  void clear_has_volume();
  void set_has_file_name();
  void clear_has_file_name();
  void set_has_file_extension();
  void clear_has_file_extension();
  void set_has_kind();
  void clear_has_kind();
  void set_has_type();
  void clear_has_type();
  void set_has_data();
  void clear_has_data();
  void set_has_effects();
  void clear_has_effects();
  void set_has_bit_rate();
  void clear_has_bit_rate();
  void set_has_sample_rate();
  void clear_has_sample_rate();
  void set_has_bit_depth();
  void clear_has_bit_depth();
  void set_has_compressed();
  void clear_has_compressed();
  void set_has_streamed();
  void clear_has_streamed();
  void set_has_uncompress_on_load();
  void clear_has_uncompress_on_load();
  void set_has_audio_group();
  void clear_has_audio_group();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr file_name_;
  ::google::protobuf::internal::ArenaStringPtr file_extension_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  double pan_;
  double volume_;
  ::google::protobuf::int32 id_;
  int kind_;
  int type_;
  ::google::protobuf::int32 effects_;
  ::google::protobuf::uint32 bit_rate_;
  bool preload_;
  bool compressed_;
  bool streamed_;
  bool uncompress_on_load_;
  ::google::protobuf::uint32 sample_rate_;
  ::google::protobuf::uint32 bit_depth_;
  ::google::protobuf::int32 audio_group_;
  friend struct ::protobuf_resources_2fSound_2eproto::TableStruct;
  friend void ::protobuf_resources_2fSound_2eproto::InitDefaultsSoundImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Sound

// optional string name = 1;
inline bool Sound::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Sound::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Sound::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Sound::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Sound::name() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.name)
  return name_.GetNoArena();
}
inline void Sound::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.name)
}
#if LANG_CXX11
inline void Sound::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:buffers.resources.Sound.name)
}
#endif
inline void Sound::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:buffers.resources.Sound.name)
}
inline void Sound::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:buffers.resources.Sound.name)
}
inline ::std::string* Sound::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:buffers.resources.Sound.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Sound::release_name() {
  // @@protoc_insertion_point(field_release:buffers.resources.Sound.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Sound::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:buffers.resources.Sound.name)
}

// optional int32 id = 2 [(.buffers.gmx) = "GMX_DEPRECATED"];
inline bool Sound::has_id() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Sound::set_has_id() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Sound::clear_has_id() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Sound::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 Sound::id() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.id)
  return id_;
}
inline void Sound::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.id)
}

// optional bool preload = 3;
inline bool Sound::has_preload() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void Sound::set_has_preload() {
  _has_bits_[0] |= 0x00000800u;
}
inline void Sound::clear_has_preload() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void Sound::clear_preload() {
  preload_ = false;
  clear_has_preload();
}
inline bool Sound::preload() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.preload)
  return preload_;
}
inline void Sound::set_preload(bool value) {
  set_has_preload();
  preload_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.preload)
}

// optional double pan = 4;
inline bool Sound::has_pan() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Sound::set_has_pan() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Sound::clear_has_pan() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Sound::clear_pan() {
  pan_ = 0;
  clear_has_pan();
}
inline double Sound::pan() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.pan)
  return pan_;
}
inline void Sound::set_pan(double value) {
  set_has_pan();
  pan_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.pan)
}

// optional double volume = 5 [(.buffers.gmx) = "volume/volume"];
inline bool Sound::has_volume() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Sound::set_has_volume() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Sound::clear_has_volume() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Sound::clear_volume() {
  volume_ = 0;
  clear_has_volume();
}
inline double Sound::volume() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.volume)
  return volume_;
}
inline void Sound::set_volume(double value) {
  set_has_volume();
  volume_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.volume)
}

// optional string file_name = 6 [(.buffers.gmx) = "data"];
inline bool Sound::has_file_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Sound::set_has_file_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Sound::clear_has_file_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Sound::clear_file_name() {
  file_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_file_name();
}
inline const ::std::string& Sound::file_name() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.file_name)
  return file_name_.GetNoArena();
}
inline void Sound::set_file_name(const ::std::string& value) {
  set_has_file_name();
  file_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.file_name)
}
#if LANG_CXX11
inline void Sound::set_file_name(::std::string&& value) {
  set_has_file_name();
  file_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:buffers.resources.Sound.file_name)
}
#endif
inline void Sound::set_file_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_file_name();
  file_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:buffers.resources.Sound.file_name)
}
inline void Sound::set_file_name(const char* value, size_t size) {
  set_has_file_name();
  file_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:buffers.resources.Sound.file_name)
}
inline ::std::string* Sound::mutable_file_name() {
  set_has_file_name();
  // @@protoc_insertion_point(field_mutable:buffers.resources.Sound.file_name)
  return file_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Sound::release_file_name() {
  // @@protoc_insertion_point(field_release:buffers.resources.Sound.file_name)
  clear_has_file_name();
  return file_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Sound::set_allocated_file_name(::std::string* file_name) {
  if (file_name != NULL) {
    set_has_file_name();
  } else {
    clear_has_file_name();
  }
  file_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), file_name);
  // @@protoc_insertion_point(field_set_allocated:buffers.resources.Sound.file_name)
}

// optional string file_extension = 7 [(.buffers.gmx) = "extension"];
inline bool Sound::has_file_extension() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Sound::set_has_file_extension() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Sound::clear_has_file_extension() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Sound::clear_file_extension() {
  file_extension_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_file_extension();
}
inline const ::std::string& Sound::file_extension() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.file_extension)
  return file_extension_.GetNoArena();
}
inline void Sound::set_file_extension(const ::std::string& value) {
  set_has_file_extension();
  file_extension_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.file_extension)
}
#if LANG_CXX11
inline void Sound::set_file_extension(::std::string&& value) {
  set_has_file_extension();
  file_extension_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:buffers.resources.Sound.file_extension)
}
#endif
inline void Sound::set_file_extension(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_file_extension();
  file_extension_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:buffers.resources.Sound.file_extension)
}
inline void Sound::set_file_extension(const char* value, size_t size) {
  set_has_file_extension();
  file_extension_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:buffers.resources.Sound.file_extension)
}
inline ::std::string* Sound::mutable_file_extension() {
  set_has_file_extension();
  // @@protoc_insertion_point(field_mutable:buffers.resources.Sound.file_extension)
  return file_extension_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Sound::release_file_extension() {
  // @@protoc_insertion_point(field_release:buffers.resources.Sound.file_extension)
  clear_has_file_extension();
  return file_extension_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Sound::set_allocated_file_extension(::std::string* file_extension) {
  if (file_extension != NULL) {
    set_has_file_extension();
  } else {
    clear_has_file_extension();
  }
  file_extension_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), file_extension);
  // @@protoc_insertion_point(field_set_allocated:buffers.resources.Sound.file_extension)
}

// optional .buffers.resources.Sound.Kind kind = 8;
inline bool Sound::has_kind() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Sound::set_has_kind() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Sound::clear_has_kind() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Sound::clear_kind() {
  kind_ = 0;
  clear_has_kind();
}
inline ::buffers::resources::Sound_Kind Sound::kind() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.kind)
  return static_cast< ::buffers::resources::Sound_Kind >(kind_);
}
inline void Sound::set_kind(::buffers::resources::Sound_Kind value) {
  assert(::buffers::resources::Sound_Kind_IsValid(value));
  set_has_kind();
  kind_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.kind)
}

// optional .buffers.resources.Sound.Type type = 9 [(.buffers.gmx) = "types/type"];
inline bool Sound::has_type() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Sound::set_has_type() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Sound::clear_has_type() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Sound::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::buffers::resources::Sound_Type Sound::type() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.type)
  return static_cast< ::buffers::resources::Sound_Type >(type_);
}
inline void Sound::set_type(::buffers::resources::Sound_Type value) {
  assert(::buffers::resources::Sound_Type_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.type)
}

// optional string data = 10 [(.buffers.gmx) = "origname", (.buffers.file_path) = true];
inline bool Sound::has_data() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Sound::set_has_data() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Sound::clear_has_data() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Sound::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_data();
}
inline const ::std::string& Sound::data() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.data)
  return data_.GetNoArena();
}
inline void Sound::set_data(const ::std::string& value) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.data)
}
#if LANG_CXX11
inline void Sound::set_data(::std::string&& value) {
  set_has_data();
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:buffers.resources.Sound.data)
}
#endif
inline void Sound::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:buffers.resources.Sound.data)
}
inline void Sound::set_data(const char* value, size_t size) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:buffers.resources.Sound.data)
}
inline ::std::string* Sound::mutable_data() {
  set_has_data();
  // @@protoc_insertion_point(field_mutable:buffers.resources.Sound.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Sound::release_data() {
  // @@protoc_insertion_point(field_release:buffers.resources.Sound.data)
  clear_has_data();
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Sound::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    set_has_data();
  } else {
    clear_has_data();
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:buffers.resources.Sound.data)
}

// optional int32 effects = 11;
inline bool Sound::has_effects() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void Sound::set_has_effects() {
  _has_bits_[0] |= 0x00000200u;
}
inline void Sound::clear_has_effects() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void Sound::clear_effects() {
  effects_ = 0;
  clear_has_effects();
}
inline ::google::protobuf::int32 Sound::effects() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.effects)
  return effects_;
}
inline void Sound::set_effects(::google::protobuf::int32 value) {
  set_has_effects();
  effects_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.effects)
}

// optional uint32 bit_rate = 12 [(.buffers.gmx) = "bitRates/bitRate"];
inline bool Sound::has_bit_rate() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void Sound::set_has_bit_rate() {
  _has_bits_[0] |= 0x00000400u;
}
inline void Sound::clear_has_bit_rate() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void Sound::clear_bit_rate() {
  bit_rate_ = 0u;
  clear_has_bit_rate();
}
inline ::google::protobuf::uint32 Sound::bit_rate() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.bit_rate)
  return bit_rate_;
}
inline void Sound::set_bit_rate(::google::protobuf::uint32 value) {
  set_has_bit_rate();
  bit_rate_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.bit_rate)
}

// optional uint32 sample_rate = 13 [(.buffers.gmx) = "sampleRates/sampleRate"];
inline bool Sound::has_sample_rate() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void Sound::set_has_sample_rate() {
  _has_bits_[0] |= 0x00008000u;
}
inline void Sound::clear_has_sample_rate() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void Sound::clear_sample_rate() {
  sample_rate_ = 0u;
  clear_has_sample_rate();
}
inline ::google::protobuf::uint32 Sound::sample_rate() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.sample_rate)
  return sample_rate_;
}
inline void Sound::set_sample_rate(::google::protobuf::uint32 value) {
  set_has_sample_rate();
  sample_rate_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.sample_rate)
}

// optional uint32 bit_depth = 14 [(.buffers.gmx) = "bitDepths/bitDepth"];
inline bool Sound::has_bit_depth() const {
  return (_has_bits_[0] & 0x00010000u) != 0;
}
inline void Sound::set_has_bit_depth() {
  _has_bits_[0] |= 0x00010000u;
}
inline void Sound::clear_has_bit_depth() {
  _has_bits_[0] &= ~0x00010000u;
}
inline void Sound::clear_bit_depth() {
  bit_depth_ = 0u;
  clear_has_bit_depth();
}
inline ::google::protobuf::uint32 Sound::bit_depth() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.bit_depth)
  return bit_depth_;
}
inline void Sound::set_bit_depth(::google::protobuf::uint32 value) {
  set_has_bit_depth();
  bit_depth_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.bit_depth)
}

// optional bool compressed = 15;
inline bool Sound::has_compressed() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void Sound::set_has_compressed() {
  _has_bits_[0] |= 0x00001000u;
}
inline void Sound::clear_has_compressed() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void Sound::clear_compressed() {
  compressed_ = false;
  clear_has_compressed();
}
inline bool Sound::compressed() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.compressed)
  return compressed_;
}
inline void Sound::set_compressed(bool value) {
  set_has_compressed();
  compressed_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.compressed)
}

// optional bool streamed = 16;
inline bool Sound::has_streamed() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void Sound::set_has_streamed() {
  _has_bits_[0] |= 0x00002000u;
}
inline void Sound::clear_has_streamed() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void Sound::clear_streamed() {
  streamed_ = false;
  clear_has_streamed();
}
inline bool Sound::streamed() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.streamed)
  return streamed_;
}
inline void Sound::set_streamed(bool value) {
  set_has_streamed();
  streamed_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.streamed)
}

// optional bool uncompress_on_load = 17 [(.buffers.gmx) = "uncompressOnLoad"];
inline bool Sound::has_uncompress_on_load() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void Sound::set_has_uncompress_on_load() {
  _has_bits_[0] |= 0x00004000u;
}
inline void Sound::clear_has_uncompress_on_load() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void Sound::clear_uncompress_on_load() {
  uncompress_on_load_ = false;
  clear_has_uncompress_on_load();
}
inline bool Sound::uncompress_on_load() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.uncompress_on_load)
  return uncompress_on_load_;
}
inline void Sound::set_uncompress_on_load(bool value) {
  set_has_uncompress_on_load();
  uncompress_on_load_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.uncompress_on_load)
}

// optional int32 audio_group = 18 [(.buffers.gmx) = "audioGroup"];
inline bool Sound::has_audio_group() const {
  return (_has_bits_[0] & 0x00020000u) != 0;
}
inline void Sound::set_has_audio_group() {
  _has_bits_[0] |= 0x00020000u;
}
inline void Sound::clear_has_audio_group() {
  _has_bits_[0] &= ~0x00020000u;
}
inline void Sound::clear_audio_group() {
  audio_group_ = 0;
  clear_has_audio_group();
}
inline ::google::protobuf::int32 Sound::audio_group() const {
  // @@protoc_insertion_point(field_get:buffers.resources.Sound.audio_group)
  return audio_group_;
}
inline void Sound::set_audio_group(::google::protobuf::int32 value) {
  set_has_audio_group();
  audio_group_ = value;
  // @@protoc_insertion_point(field_set:buffers.resources.Sound.audio_group)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace resources
}  // namespace buffers

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::buffers::resources::Sound_Kind> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::buffers::resources::Sound_Kind>() {
  return ::buffers::resources::Sound_Kind_descriptor();
}
template <> struct is_proto_enum< ::buffers::resources::Sound_Type> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::buffers::resources::Sound_Type>() {
  return ::buffers::resources::Sound_Type_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_resources_2fSound_2eproto__INCLUDED