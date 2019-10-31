#pragma once

#include "tl/TlObject.h"

#include <cstdint>
#include <utility>
#include <vector>

#include <jni.h>

#include <string>
#include "td/utils/SharedSlice.h"

namespace td {
class TlStorerToString;
}
namespace ton {
namespace tonlib_api {

class Object;
using BaseObject = Object;

template <class Type>
using object_ptr = ::ton::tl_object_ptr<Type>;

template <class Type, class... Args>
object_ptr<Type> make_object(Args &&... args) {
  return object_ptr<Type>(new Type(std::forward<Args>(args)...));
}

template <class ToType, class FromType>
object_ptr<ToType> move_object_as(FromType &&from) {
  return object_ptr<ToType>(static_cast<ToType *>(from.release()));
}

std::string to_string(const BaseObject &value);

template <class T>
std::string to_string(const object_ptr<T> &value) {
  if (value == nullptr) {
    return "null";
  }

  return to_string(*value);
}

class accountAddress;

class bip39Hints;

class config;

class data;

class error;

class exportedEncryptedKey;

class exportedKey;

class exportedPemKey;

class fees;

class InputKey;

class key;

class KeyStoreType;

class LogStream;

class logTags;

class logVerbosityLevel;

class ok;

class options;

class sendGramsResult;

class SyncState;

class unpackedAccountAddress;

class Update;

class generic_AccountState;

class internal_transactionId;

class liteServer_info;

class options_configInfo;

class query_fees;

class query_info;

class raw_accountState;

class raw_initialAccountState;

class raw_message;

class raw_transaction;

class raw_transactions;

class smc_info;

class smc_MethodId;

class smc_runResult;

class testGiver_accountState;

class testWallet_accountState;

class testWallet_initialAccountState;

class tvm_cell;

class tvm_numberDecimal;

class tvm_slice;

class tvm_StackEntry;

class uninited_accountState;

class wallet_accountState;

class wallet_initialAccountState;

class wallet_v3_accountState;

class wallet_v3_initialAccountState;

class Object;

class Object {
 public:
  virtual ~Object() {
  }

  virtual void store(JNIEnv *env, jobject &s) const {
  }

  virtual void store(td::TlStorerToString &s, const char *field_name) const = 0;

  static jclass Class;

  virtual std::int32_t get_id() const = 0;

  static object_ptr<Object> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class Function: public Object {
 public:
  static jclass Class;

  static object_ptr<Function> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class accountAddress final : public Object {
 public:
  static jclass Class;
  std::string account_address_;
  static jfieldID account_address_fieldID;

  accountAddress();

  explicit accountAddress(std::string const &account_address_);

  static const std::int32_t ID = 755613099;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<accountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class bip39Hints final : public Object {
 public:
  static jclass Class;
  std::vector<std::string> words_;
  static jfieldID words_fieldID;

  bip39Hints();

  explicit bip39Hints(std::vector<std::string> &&words_);

  static const std::int32_t ID = 1012243456;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<bip39Hints> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class config final : public Object {
 public:
  static jclass Class;
  std::string config_;
  static jfieldID config_fieldID;
  std::string blockchain_name_;
  static jfieldID blockchain_name_fieldID;
  bool use_callbacks_for_network_;
  static jfieldID use_callbacks_for_network_fieldID;
  bool ignore_cache_;
  static jfieldID ignore_cache_fieldID;

  config();

  config(std::string const &config_, std::string const &blockchain_name_, bool use_callbacks_for_network_, bool ignore_cache_);

  static const std::int32_t ID = -1538391496;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<config> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class data final : public Object {
 public:
  static jclass Class;
  td::SecureString bytes_;
  static jfieldID bytes_fieldID;

  data();

  explicit data(td::SecureString &&bytes_);

  static const std::int32_t ID = -414733967;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<data> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class error final : public Object {
 public:
  static jclass Class;
  std::int32_t code_;
  static jfieldID code_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  error();

  error(std::int32_t code_, std::string const &message_);

  static const std::int32_t ID = -1679978726;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<error> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class exportedEncryptedKey final : public Object {
 public:
  static jclass Class;
  td::SecureString data_;
  static jfieldID data_fieldID;

  exportedEncryptedKey();

  explicit exportedEncryptedKey(td::SecureString &&data_);

  static const std::int32_t ID = 2024406612;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<exportedEncryptedKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class exportedKey final : public Object {
 public:
  static jclass Class;
  std::vector<td::SecureString> word_list_;
  static jfieldID word_list_fieldID;

  exportedKey();

  explicit exportedKey(std::vector<td::SecureString> &&word_list_);

  static const std::int32_t ID = -1449248297;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<exportedKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class exportedPemKey final : public Object {
 public:
  static jclass Class;
  td::SecureString pem_;
  static jfieldID pem_fieldID;

  exportedPemKey();

  explicit exportedPemKey(td::SecureString &&pem_);

  static const std::int32_t ID = 1425473725;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<exportedPemKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class fees final : public Object {
 public:
  static jclass Class;
  std::int64_t in_fwd_fee_;
  static jfieldID in_fwd_fee_fieldID;
  std::int64_t storage_fee_;
  static jfieldID storage_fee_fieldID;
  std::int64_t gas_fee_;
  static jfieldID gas_fee_fieldID;
  std::int64_t fwd_fee_;
  static jfieldID fwd_fee_fieldID;

  fees();

  fees(std::int64_t in_fwd_fee_, std::int64_t storage_fee_, std::int64_t gas_fee_, std::int64_t fwd_fee_);

  static const std::int32_t ID = 1676273340;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<fees> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class InputKey: public Object {
 public:
  static jclass Class;

  static object_ptr<InputKey> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class inputKeyRegular final : public InputKey {
 public:
  static jclass Class;
  object_ptr<key> key_;
  static jfieldID key_fieldID;
  td::SecureString local_password_;
  static jfieldID local_password_fieldID;

  inputKeyRegular();

  inputKeyRegular(object_ptr<key> &&key_, td::SecureString &&local_password_);

  static const std::int32_t ID = -555399522;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InputKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class inputKeyFake final : public InputKey {
 public:
  static jclass Class;

  inputKeyFake();

  static const std::int32_t ID = -1074054722;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InputKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class key final : public Object {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  td::SecureString secret_;
  static jfieldID secret_fieldID;

  key();

  key(std::string const &public_key_, td::SecureString &&secret_);

  static const std::int32_t ID = -1978362923;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<key> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class KeyStoreType: public Object {
 public:
  static jclass Class;

  static object_ptr<KeyStoreType> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class keyStoreTypeDirectory final : public KeyStoreType {
 public:
  static jclass Class;
  std::string directory_;
  static jfieldID directory_fieldID;

  keyStoreTypeDirectory();

  explicit keyStoreTypeDirectory(std::string const &directory_);

  static const std::int32_t ID = -378990038;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<KeyStoreType> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class keyStoreTypeInMemory final : public KeyStoreType {
 public:
  static jclass Class;

  keyStoreTypeInMemory();

  static const std::int32_t ID = -2106848825;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<KeyStoreType> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class LogStream: public Object {
 public:
  static jclass Class;

  static object_ptr<LogStream> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class logStreamDefault final : public LogStream {
 public:
  static jclass Class;

  logStreamDefault();

  static const std::int32_t ID = 1390581436;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<LogStream> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class logStreamFile final : public LogStream {
 public:
  static jclass Class;
  std::string path_;
  static jfieldID path_fieldID;
  std::int64_t max_file_size_;
  static jfieldID max_file_size_fieldID;

  logStreamFile();

  logStreamFile(std::string const &path_, std::int64_t max_file_size_);

  static const std::int32_t ID = -1880085930;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<LogStream> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class logStreamEmpty final : public LogStream {
 public:
  static jclass Class;

  logStreamEmpty();

  static const std::int32_t ID = -499912244;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<LogStream> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class logTags final : public Object {
 public:
  static jclass Class;
  std::vector<std::string> tags_;
  static jfieldID tags_fieldID;

  logTags();

  explicit logTags(std::vector<std::string> &&tags_);

  static const std::int32_t ID = -1604930601;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<logTags> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class logVerbosityLevel final : public Object {
 public:
  static jclass Class;
  std::int32_t verbosity_level_;
  static jfieldID verbosity_level_fieldID;

  logVerbosityLevel();

  explicit logVerbosityLevel(std::int32_t verbosity_level_);

  static const std::int32_t ID = 1734624234;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<logVerbosityLevel> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class ok final : public Object {
 public:
  static jclass Class;

  ok();

  static const std::int32_t ID = -722616727;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<ok> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class options final : public Object {
 public:
  static jclass Class;
  object_ptr<config> config_;
  static jfieldID config_fieldID;
  object_ptr<KeyStoreType> keystore_type_;
  static jfieldID keystore_type_fieldID;

  options();

  options(object_ptr<config> &&config_, object_ptr<KeyStoreType> &&keystore_type_);

  static const std::int32_t ID = -1924388359;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<options> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class sendGramsResult final : public Object {
 public:
  static jclass Class;
  std::int64_t sent_until_;
  static jfieldID sent_until_fieldID;
  std::string body_hash_;
  static jfieldID body_hash_fieldID;

  sendGramsResult();

  sendGramsResult(std::int64_t sent_until_, std::string const &body_hash_);

  static const std::int32_t ID = 426872238;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<sendGramsResult> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class SyncState: public Object {
 public:
  static jclass Class;

  static object_ptr<SyncState> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class syncStateDone final : public SyncState {
 public:
  static jclass Class;

  syncStateDone();

  static const std::int32_t ID = 1408448777;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<SyncState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class syncStateInProgress final : public SyncState {
 public:
  static jclass Class;
  std::int32_t from_seqno_;
  static jfieldID from_seqno_fieldID;
  std::int32_t to_seqno_;
  static jfieldID to_seqno_fieldID;
  std::int32_t current_seqno_;
  static jfieldID current_seqno_fieldID;

  syncStateInProgress();

  syncStateInProgress(std::int32_t from_seqno_, std::int32_t to_seqno_, std::int32_t current_seqno_);

  static const std::int32_t ID = 107726023;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<SyncState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class unpackedAccountAddress final : public Object {
 public:
  static jclass Class;
  std::int32_t workchain_id_;
  static jfieldID workchain_id_fieldID;
  bool bounceable_;
  static jfieldID bounceable_fieldID;
  bool testnet_;
  static jfieldID testnet_fieldID;
  std::string addr_;
  static jfieldID addr_fieldID;

  unpackedAccountAddress();

  unpackedAccountAddress(std::int32_t workchain_id_, bool bounceable_, bool testnet_, std::string const &addr_);

  static const std::int32_t ID = 1892946998;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<unpackedAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class Update: public Object {
 public:
  static jclass Class;

  static object_ptr<Update> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class updateSendLiteServerQuery final : public Update {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;
  std::string data_;
  static jfieldID data_fieldID;

  updateSendLiteServerQuery();

  updateSendLiteServerQuery(std::int64_t id_, std::string const &data_);

  static const std::int32_t ID = -1555130916;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Update> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class updateSyncState final : public Update {
 public:
  static jclass Class;
  object_ptr<SyncState> sync_state_;
  static jfieldID sync_state_fieldID;

  updateSyncState();

  explicit updateSyncState(object_ptr<SyncState> &&sync_state_);

  static const std::int32_t ID = 1204298718;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Update> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_AccountState: public Object {
 public:
  static jclass Class;

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_accountStateRaw final : public generic_AccountState {
 public:
  static jclass Class;
  object_ptr<raw_accountState> account_state_;
  static jfieldID account_state_fieldID;

  generic_accountStateRaw();

  explicit generic_accountStateRaw(object_ptr<raw_accountState> &&account_state_);

  static const std::int32_t ID = -1387096685;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_accountStateTestWallet final : public generic_AccountState {
 public:
  static jclass Class;
  object_ptr<testWallet_accountState> account_state_;
  static jfieldID account_state_fieldID;

  generic_accountStateTestWallet();

  explicit generic_accountStateTestWallet(object_ptr<testWallet_accountState> &&account_state_);

  static const std::int32_t ID = -1041955397;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_accountStateWallet final : public generic_AccountState {
 public:
  static jclass Class;
  object_ptr<wallet_accountState> account_state_;
  static jfieldID account_state_fieldID;

  generic_accountStateWallet();

  explicit generic_accountStateWallet(object_ptr<wallet_accountState> &&account_state_);

  static const std::int32_t ID = 942582925;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_accountStateWalletV3 final : public generic_AccountState {
 public:
  static jclass Class;
  object_ptr<wallet_v3_accountState> account_state_;
  static jfieldID account_state_fieldID;

  generic_accountStateWalletV3();

  explicit generic_accountStateWalletV3(object_ptr<wallet_v3_accountState> &&account_state_);

  static const std::int32_t ID = -281349583;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_accountStateTestGiver final : public generic_AccountState {
 public:
  static jclass Class;
  object_ptr<testGiver_accountState> account_state_;
  static jfieldID account_state_fieldID;

  generic_accountStateTestGiver();

  explicit generic_accountStateTestGiver(object_ptr<testGiver_accountState> &&account_state_);

  static const std::int32_t ID = 1134654598;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_accountStateUninited final : public generic_AccountState {
 public:
  static jclass Class;
  object_ptr<uninited_accountState> account_state_;
  static jfieldID account_state_fieldID;

  generic_accountStateUninited();

  explicit generic_accountStateUninited(object_ptr<uninited_accountState> &&account_state_);

  static const std::int32_t ID = -908702008;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<generic_AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class internal_transactionId final : public Object {
 public:
  static jclass Class;
  std::int64_t lt_;
  static jfieldID lt_fieldID;
  std::string hash_;
  static jfieldID hash_fieldID;

  internal_transactionId();

  internal_transactionId(std::int64_t lt_, std::string const &hash_);

  static const std::int32_t ID = -989527262;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<internal_transactionId> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class liteServer_info final : public Object {
 public:
  static jclass Class;
  std::int64_t now_;
  static jfieldID now_fieldID;
  std::int32_t version_;
  static jfieldID version_fieldID;
  std::int64_t capabilities_;
  static jfieldID capabilities_fieldID;

  liteServer_info();

  liteServer_info(std::int64_t now_, std::int32_t version_, std::int64_t capabilities_);

  static const std::int32_t ID = -1250165133;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<liteServer_info> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class options_configInfo final : public Object {
 public:
  static jclass Class;
  std::int64_t default_wallet_id_;
  static jfieldID default_wallet_id_fieldID;

  options_configInfo();

  explicit options_configInfo(std::int64_t default_wallet_id_);

  static const std::int32_t ID = 165216422;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<options_configInfo> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_fees final : public Object {
 public:
  static jclass Class;
  object_ptr<fees> source_fees_;
  static jfieldID source_fees_fieldID;
  object_ptr<fees> destination_fees_;
  static jfieldID destination_fees_fieldID;

  query_fees();

  query_fees(object_ptr<fees> &&source_fees_, object_ptr<fees> &&destination_fees_);

  static const std::int32_t ID = 725267759;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<query_fees> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_info final : public Object {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;
  std::int64_t valid_until_;
  static jfieldID valid_until_fieldID;
  std::string body_hash_;
  static jfieldID body_hash_fieldID;

  query_info();

  query_info(std::int64_t id_, std::int64_t valid_until_, std::string const &body_hash_);

  static const std::int32_t ID = 1588635915;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<query_info> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_accountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  std::string code_;
  static jfieldID code_fieldID;
  std::string data_;
  static jfieldID data_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  std::string frozen_hash_;
  static jfieldID frozen_hash_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  raw_accountState();

  raw_accountState(std::int64_t balance_, std::string const &code_, std::string const &data_, object_ptr<internal_transactionId> &&last_transaction_id_, std::string const &frozen_hash_, std::int64_t sync_utime_);

  static const std::int32_t ID = 1205935434;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<raw_accountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_initialAccountState final : public Object {
 public:
  static jclass Class;
  std::string code_;
  static jfieldID code_fieldID;
  std::string data_;
  static jfieldID data_fieldID;

  raw_initialAccountState();

  raw_initialAccountState(std::string const &code_, std::string const &data_);

  static const std::int32_t ID = 777456197;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<raw_initialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_message final : public Object {
 public:
  static jclass Class;
  std::string source_;
  static jfieldID source_fieldID;
  std::string destination_;
  static jfieldID destination_fieldID;
  std::int64_t value_;
  static jfieldID value_fieldID;
  std::int64_t fwd_fee_;
  static jfieldID fwd_fee_fieldID;
  std::int64_t ihr_fee_;
  static jfieldID ihr_fee_fieldID;
  std::int64_t created_lt_;
  static jfieldID created_lt_fieldID;
  std::string body_hash_;
  static jfieldID body_hash_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  raw_message();

  raw_message(std::string const &source_, std::string const &destination_, std::int64_t value_, std::int64_t fwd_fee_, std::int64_t ihr_fee_, std::int64_t created_lt_, std::string const &body_hash_, std::string const &message_);

  static const std::int32_t ID = -906281442;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<raw_message> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_transaction final : public Object {
 public:
  static jclass Class;
  std::int64_t utime_;
  static jfieldID utime_fieldID;
  std::string data_;
  static jfieldID data_fieldID;
  object_ptr<internal_transactionId> transaction_id_;
  static jfieldID transaction_id_fieldID;
  std::int64_t fee_;
  static jfieldID fee_fieldID;
  std::int64_t storage_fee_;
  static jfieldID storage_fee_fieldID;
  std::int64_t other_fee_;
  static jfieldID other_fee_fieldID;
  object_ptr<raw_message> in_msg_;
  static jfieldID in_msg_fieldID;
  std::vector<object_ptr<raw_message>> out_msgs_;
  static jfieldID out_msgs_fieldID;

  raw_transaction();

  raw_transaction(std::int64_t utime_, std::string const &data_, object_ptr<internal_transactionId> &&transaction_id_, std::int64_t fee_, std::int64_t storage_fee_, std::int64_t other_fee_, object_ptr<raw_message> &&in_msg_, std::vector<object_ptr<raw_message>> &&out_msgs_);

  static const std::int32_t ID = 1887601793;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<raw_transaction> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_transactions final : public Object {
 public:
  static jclass Class;
  std::vector<object_ptr<raw_transaction>> transactions_;
  static jfieldID transactions_fieldID;
  object_ptr<internal_transactionId> previous_transaction_id_;
  static jfieldID previous_transaction_id_fieldID;

  raw_transactions();

  raw_transactions(std::vector<object_ptr<raw_transaction>> &&transactions_, object_ptr<internal_transactionId> &&previous_transaction_id_);

  static const std::int32_t ID = -2063931155;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<raw_transactions> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_info final : public Object {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  smc_info();

  explicit smc_info(std::int64_t id_);

  static const std::int32_t ID = 1134270012;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<smc_info> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_MethodId: public Object {
 public:
  static jclass Class;

  static object_ptr<smc_MethodId> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_methodIdNumber final : public smc_MethodId {
 public:
  static jclass Class;
  std::int32_t number_;
  static jfieldID number_fieldID;

  smc_methodIdNumber();

  explicit smc_methodIdNumber(std::int32_t number_);

  static const std::int32_t ID = -1541162500;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<smc_MethodId> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_methodIdName final : public smc_MethodId {
 public:
  static jclass Class;
  std::string name_;
  static jfieldID name_fieldID;

  smc_methodIdName();

  explicit smc_methodIdName(std::string const &name_);

  static const std::int32_t ID = -249036908;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<smc_MethodId> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_runResult final : public Object {
 public:
  static jclass Class;
  std::int64_t gas_used_;
  static jfieldID gas_used_fieldID;
  std::vector<object_ptr<tvm_StackEntry>> stack_;
  static jfieldID stack_fieldID;
  std::int32_t exit_code_;
  static jfieldID exit_code_fieldID;

  smc_runResult();

  smc_runResult(std::int64_t gas_used_, std::vector<object_ptr<tvm_StackEntry>> &&stack_, std::int32_t exit_code_);

  static const std::int32_t ID = 1413805043;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<smc_runResult> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testGiver_accountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  testGiver_accountState();

  testGiver_accountState(std::int64_t balance_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_);

  static const std::int32_t ID = 860930426;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<testGiver_accountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_accountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  testWallet_accountState();

  testWallet_accountState(std::int64_t balance_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_);

  static const std::int32_t ID = 305698744;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<testWallet_accountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_initialAccountState final : public Object {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;

  testWallet_initialAccountState();

  explicit testWallet_initialAccountState(std::string const &public_key_);

  static const std::int32_t ID = -1231516227;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<testWallet_initialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_cell final : public Object {
 public:
  static jclass Class;
  std::string bytes_;
  static jfieldID bytes_fieldID;

  tvm_cell();

  explicit tvm_cell(std::string const &bytes_);

  static const std::int32_t ID = -859530316;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_cell> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_numberDecimal final : public Object {
 public:
  static jclass Class;
  std::string number_;
  static jfieldID number_fieldID;

  tvm_numberDecimal();

  explicit tvm_numberDecimal(std::string const &number_);

  static const std::int32_t ID = 1172477619;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_numberDecimal> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_slice final : public Object {
 public:
  static jclass Class;
  std::string bytes_;
  static jfieldID bytes_fieldID;

  tvm_slice();

  explicit tvm_slice(std::string const &bytes_);

  static const std::int32_t ID = -1069968387;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_slice> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_StackEntry: public Object {
 public:
  static jclass Class;

  static object_ptr<tvm_StackEntry> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_stackEntrySlice final : public tvm_StackEntry {
 public:
  static jclass Class;
  object_ptr<tvm_slice> slice_;
  static jfieldID slice_fieldID;

  tvm_stackEntrySlice();

  explicit tvm_stackEntrySlice(object_ptr<tvm_slice> &&slice_);

  static const std::int32_t ID = 1395485477;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_StackEntry> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_stackEntryCell final : public tvm_StackEntry {
 public:
  static jclass Class;
  object_ptr<tvm_cell> cell_;
  static jfieldID cell_fieldID;

  tvm_stackEntryCell();

  explicit tvm_stackEntryCell(object_ptr<tvm_cell> &&cell_);

  static const std::int32_t ID = 1303473952;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_StackEntry> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_stackEntryNumber final : public tvm_StackEntry {
 public:
  static jclass Class;
  object_ptr<tvm_numberDecimal> number_;
  static jfieldID number_fieldID;

  tvm_stackEntryNumber();

  explicit tvm_stackEntryNumber(object_ptr<tvm_numberDecimal> &&number_);

  static const std::int32_t ID = 1358642622;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_StackEntry> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_stackEntryUnsupported final : public tvm_StackEntry {
 public:
  static jclass Class;

  tvm_stackEntryUnsupported();

  static const std::int32_t ID = 378880498;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_StackEntry> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class uninited_accountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  std::string frozen_hash_;
  static jfieldID frozen_hash_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  uninited_accountState();

  uninited_accountState(std::int64_t balance_, object_ptr<internal_transactionId> &&last_transaction_id_, std::string const &frozen_hash_, std::int64_t sync_utime_);

  static const std::int32_t ID = -918880075;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<uninited_accountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_accountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  wallet_accountState();

  wallet_accountState(std::int64_t balance_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_);

  static const std::int32_t ID = -1919815977;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<wallet_accountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_initialAccountState final : public Object {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;

  wallet_initialAccountState();

  explicit wallet_initialAccountState(std::string const &public_key_);

  static const std::int32_t ID = -1079249978;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<wallet_initialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_v3_accountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  wallet_v3_accountState();

  wallet_v3_accountState(std::int64_t balance_, std::int64_t wallet_id_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_);

  static const std::int32_t ID = 1977698154;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<wallet_v3_accountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_v3_initialAccountState final : public Object {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  wallet_v3_initialAccountState();

  wallet_v3_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_);

  static const std::int32_t ID = 283460879;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<wallet_v3_initialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class addLogMessage final : public Function {
 public:
  static jclass Class;
  std::int32_t verbosity_level_;
  static jfieldID verbosity_level_fieldID;
  std::string text_;
  static jfieldID text_fieldID;

  addLogMessage();

  addLogMessage(std::int32_t verbosity_level_, std::string const &text_);

  static const std::int32_t ID = 1597427692;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<addLogMessage> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class changeLocalPassword final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> input_key_;
  static jfieldID input_key_fieldID;
  td::SecureString new_local_password_;
  static jfieldID new_local_password_fieldID;

  changeLocalPassword();

  changeLocalPassword(object_ptr<InputKey> &&input_key_, td::SecureString &&new_local_password_);

  static const std::int32_t ID = -401590337;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<key>;

  static object_ptr<changeLocalPassword> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class close final : public Function {
 public:
  static jclass Class;

  close();

  static const std::int32_t ID = -1187782273;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<close> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class createNewKey final : public Function {
 public:
  static jclass Class;
  td::SecureString local_password_;
  static jfieldID local_password_fieldID;
  td::SecureString mnemonic_password_;
  static jfieldID mnemonic_password_fieldID;
  td::SecureString random_extra_seed_;
  static jfieldID random_extra_seed_fieldID;

  createNewKey();

  createNewKey(td::SecureString &&local_password_, td::SecureString &&mnemonic_password_, td::SecureString &&random_extra_seed_);

  static const std::int32_t ID = -1861385712;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<key>;

  static object_ptr<createNewKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class decrypt final : public Function {
 public:
  static jclass Class;
  td::SecureString encrypted_data_;
  static jfieldID encrypted_data_fieldID;
  td::SecureString secret_;
  static jfieldID secret_fieldID;

  decrypt();

  decrypt(td::SecureString &&encrypted_data_, td::SecureString &&secret_);

  static const std::int32_t ID = 357991854;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<data>;

  static object_ptr<decrypt> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class deleteAllKeys final : public Function {
 public:
  static jclass Class;

  deleteAllKeys();

  static const std::int32_t ID = 1608776483;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<deleteAllKeys> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class deleteKey final : public Function {
 public:
  static jclass Class;
  object_ptr<key> key_;
  static jfieldID key_fieldID;

  deleteKey();

  explicit deleteKey(object_ptr<key> &&key_);

  static const std::int32_t ID = -1579595571;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<deleteKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class encrypt final : public Function {
 public:
  static jclass Class;
  td::SecureString decrypted_data_;
  static jfieldID decrypted_data_fieldID;
  td::SecureString secret_;
  static jfieldID secret_fieldID;

  encrypt();

  encrypt(td::SecureString &&decrypted_data_, td::SecureString &&secret_);

  static const std::int32_t ID = -1821422820;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<data>;

  static object_ptr<encrypt> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class exportEncryptedKey final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> input_key_;
  static jfieldID input_key_fieldID;
  td::SecureString key_password_;
  static jfieldID key_password_fieldID;

  exportEncryptedKey();

  exportEncryptedKey(object_ptr<InputKey> &&input_key_, td::SecureString &&key_password_);

  static const std::int32_t ID = 218237311;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<exportedEncryptedKey>;

  static object_ptr<exportEncryptedKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class exportKey final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> input_key_;
  static jfieldID input_key_fieldID;

  exportKey();

  explicit exportKey(object_ptr<InputKey> &&input_key_);

  static const std::int32_t ID = -1622353549;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<exportedKey>;

  static object_ptr<exportKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class exportPemKey final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> input_key_;
  static jfieldID input_key_fieldID;
  td::SecureString key_password_;
  static jfieldID key_password_fieldID;

  exportPemKey();

  exportPemKey(object_ptr<InputKey> &&input_key_, td::SecureString &&key_password_);

  static const std::int32_t ID = -643259462;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<exportedPemKey>;

  static object_ptr<exportPemKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_createSendGramsQuery final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;
  object_ptr<accountAddress> source_;
  static jfieldID source_fieldID;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::int64_t amount_;
  static jfieldID amount_fieldID;
  std::int32_t timeout_;
  static jfieldID timeout_fieldID;
  bool allow_send_to_uninited_;
  static jfieldID allow_send_to_uninited_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  generic_createSendGramsQuery();

  generic_createSendGramsQuery(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t amount_, std::int32_t timeout_, bool allow_send_to_uninited_, std::string const &message_);

  static const std::int32_t ID = 208206338;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<query_info>;

  static object_ptr<generic_createSendGramsQuery> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_getAccountState final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  generic_getAccountState();

  explicit generic_getAccountState(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = -657000446;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<generic_AccountState>;

  static object_ptr<generic_getAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class generic_sendGrams final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;
  object_ptr<accountAddress> source_;
  static jfieldID source_fieldID;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::int64_t amount_;
  static jfieldID amount_fieldID;
  std::int32_t timeout_;
  static jfieldID timeout_fieldID;
  bool allow_send_to_uninited_;
  static jfieldID allow_send_to_uninited_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  generic_sendGrams();

  generic_sendGrams(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t amount_, std::int32_t timeout_, bool allow_send_to_uninited_, std::string const &message_);

  static const std::int32_t ID = -553513162;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<sendGramsResult>;

  static object_ptr<generic_sendGrams> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getBip39Hints final : public Function {
 public:
  static jclass Class;
  std::string prefix_;
  static jfieldID prefix_fieldID;

  getBip39Hints();

  explicit getBip39Hints(std::string const &prefix_);

  static const std::int32_t ID = -1889640982;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<bip39Hints>;

  static object_ptr<getBip39Hints> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getLogStream final : public Function {
 public:
  static jclass Class;

  getLogStream();

  static const std::int32_t ID = 1167608667;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<LogStream>;

  static object_ptr<getLogStream> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getLogTagVerbosityLevel final : public Function {
 public:
  static jclass Class;
  std::string tag_;
  static jfieldID tag_fieldID;

  getLogTagVerbosityLevel();

  explicit getLogTagVerbosityLevel(std::string const &tag_);

  static const std::int32_t ID = 951004547;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<logVerbosityLevel>;

  static object_ptr<getLogTagVerbosityLevel> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getLogTags final : public Function {
 public:
  static jclass Class;

  getLogTags();

  static const std::int32_t ID = -254449190;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<logTags>;

  static object_ptr<getLogTags> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getLogVerbosityLevel final : public Function {
 public:
  static jclass Class;

  getLogVerbosityLevel();

  static const std::int32_t ID = 594057956;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<logVerbosityLevel>;

  static object_ptr<getLogVerbosityLevel> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class importEncryptedKey final : public Function {
 public:
  static jclass Class;
  td::SecureString local_password_;
  static jfieldID local_password_fieldID;
  td::SecureString key_password_;
  static jfieldID key_password_fieldID;
  object_ptr<exportedEncryptedKey> exported_encrypted_key_;
  static jfieldID exported_encrypted_key_fieldID;

  importEncryptedKey();

  importEncryptedKey(td::SecureString &&local_password_, td::SecureString &&key_password_, object_ptr<exportedEncryptedKey> &&exported_encrypted_key_);

  static const std::int32_t ID = 656724958;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<key>;

  static object_ptr<importEncryptedKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class importKey final : public Function {
 public:
  static jclass Class;
  td::SecureString local_password_;
  static jfieldID local_password_fieldID;
  td::SecureString mnemonic_password_;
  static jfieldID mnemonic_password_fieldID;
  object_ptr<exportedKey> exported_key_;
  static jfieldID exported_key_fieldID;

  importKey();

  importKey(td::SecureString &&local_password_, td::SecureString &&mnemonic_password_, object_ptr<exportedKey> &&exported_key_);

  static const std::int32_t ID = -1607900903;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<key>;

  static object_ptr<importKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class importPemKey final : public Function {
 public:
  static jclass Class;
  td::SecureString local_password_;
  static jfieldID local_password_fieldID;
  td::SecureString key_password_;
  static jfieldID key_password_fieldID;
  object_ptr<exportedPemKey> exported_key_;
  static jfieldID exported_key_fieldID;

  importPemKey();

  importPemKey(td::SecureString &&local_password_, td::SecureString &&key_password_, object_ptr<exportedPemKey> &&exported_key_);

  static const std::int32_t ID = 76385617;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<key>;

  static object_ptr<importPemKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class init final : public Function {
 public:
  static jclass Class;
  object_ptr<options> options_;
  static jfieldID options_fieldID;

  init();

  explicit init(object_ptr<options> &&options_);

  static const std::int32_t ID = -2014661877;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<init> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class kdf final : public Function {
 public:
  static jclass Class;
  td::SecureString password_;
  static jfieldID password_fieldID;
  td::SecureString salt_;
  static jfieldID salt_fieldID;
  std::int32_t iterations_;
  static jfieldID iterations_fieldID;

  kdf();

  kdf(td::SecureString &&password_, td::SecureString &&salt_, std::int32_t iterations_);

  static const std::int32_t ID = -1667861635;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<data>;

  static object_ptr<kdf> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class liteServer_getInfo final : public Function {
 public:
  static jclass Class;

  liteServer_getInfo();

  static const std::int32_t ID = 1435327470;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<liteServer_info>;

  static object_ptr<liteServer_getInfo> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class onLiteServerQueryError final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;
  object_ptr<error> error_;
  static jfieldID error_fieldID;

  onLiteServerQueryError();

  onLiteServerQueryError(std::int64_t id_, object_ptr<error> &&error_);

  static const std::int32_t ID = -677427533;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<onLiteServerQueryError> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class onLiteServerQueryResult final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;
  std::string bytes_;
  static jfieldID bytes_fieldID;

  onLiteServerQueryResult();

  onLiteServerQueryResult(std::int64_t id_, std::string const &bytes_);

  static const std::int32_t ID = 2056444510;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<onLiteServerQueryResult> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class options_setConfig final : public Function {
 public:
  static jclass Class;
  object_ptr<config> config_;
  static jfieldID config_fieldID;

  options_setConfig();

  explicit options_setConfig(object_ptr<config> &&config_);

  static const std::int32_t ID = 646497241;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<options_setConfig> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class options_validateConfig final : public Function {
 public:
  static jclass Class;
  object_ptr<config> config_;
  static jfieldID config_fieldID;

  options_validateConfig();

  explicit options_validateConfig(object_ptr<config> &&config_);

  static const std::int32_t ID = -346965447;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<options_configInfo>;

  static object_ptr<options_validateConfig> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class packAccountAddress final : public Function {
 public:
  static jclass Class;
  object_ptr<unpackedAccountAddress> account_address_;
  static jfieldID account_address_fieldID;

  packAccountAddress();

  explicit packAccountAddress(object_ptr<unpackedAccountAddress> &&account_address_);

  static const std::int32_t ID = -1388561940;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<packAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_estimateFees final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;
  bool ignore_chksig_;
  static jfieldID ignore_chksig_fieldID;

  query_estimateFees();

  query_estimateFees(std::int64_t id_, bool ignore_chksig_);

  static const std::int32_t ID = -957002175;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<query_fees>;

  static object_ptr<query_estimateFees> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_forget final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  query_forget();

  explicit query_forget(std::int64_t id_);

  static const std::int32_t ID = -1211985313;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<query_forget> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_getInfo final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  query_getInfo();

  explicit query_getInfo(std::int64_t id_);

  static const std::int32_t ID = -799333669;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<query_info>;

  static object_ptr<query_getInfo> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_send final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  query_send();

  explicit query_send(std::int64_t id_);

  static const std::int32_t ID = 925242739;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<query_send> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_createAndSendMessage final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::string initial_account_state_;
  static jfieldID initial_account_state_fieldID;
  std::string data_;
  static jfieldID data_fieldID;

  raw_createAndSendMessage();

  raw_createAndSendMessage(object_ptr<accountAddress> &&destination_, std::string const &initial_account_state_, std::string const &data_);

  static const std::int32_t ID = -772224603;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<raw_createAndSendMessage> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_createQuery final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::string init_code_;
  static jfieldID init_code_fieldID;
  std::string init_data_;
  static jfieldID init_data_fieldID;
  std::string body_;
  static jfieldID body_fieldID;

  raw_createQuery();

  raw_createQuery(object_ptr<accountAddress> &&destination_, std::string const &init_code_, std::string const &init_data_, std::string const &body_);

  static const std::int32_t ID = -1928557909;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<query_info>;

  static object_ptr<raw_createQuery> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_getAccountAddress final : public Function {
 public:
  static jclass Class;
  object_ptr<raw_initialAccountState> initital_account_state_;
  static jfieldID initital_account_state_fieldID;

  raw_getAccountAddress();

  explicit raw_getAccountAddress(object_ptr<raw_initialAccountState> &&initital_account_state_);

  static const std::int32_t ID = -521283849;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<raw_getAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_getAccountState final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  raw_getAccountState();

  explicit raw_getAccountState(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = 663706721;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<raw_accountState>;

  static object_ptr<raw_getAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_getTransactions final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;
  object_ptr<internal_transactionId> from_transaction_id_;
  static jfieldID from_transaction_id_fieldID;

  raw_getTransactions();

  raw_getTransactions(object_ptr<accountAddress> &&account_address_, object_ptr<internal_transactionId> &&from_transaction_id_);

  static const std::int32_t ID = 935377269;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<raw_transactions>;

  static object_ptr<raw_getTransactions> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_sendMessage final : public Function {
 public:
  static jclass Class;
  std::string body_;
  static jfieldID body_fieldID;

  raw_sendMessage();

  explicit raw_sendMessage(std::string const &body_);

  static const std::int32_t ID = -1789427488;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<raw_sendMessage> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class runTests final : public Function {
 public:
  static jclass Class;
  std::string dir_;
  static jfieldID dir_fieldID;

  runTests();

  explicit runTests(std::string const &dir_);

  static const std::int32_t ID = -2039925427;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<runTests> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class setLogStream final : public Function {
 public:
  static jclass Class;
  object_ptr<LogStream> log_stream_;
  static jfieldID log_stream_fieldID;

  setLogStream();

  explicit setLogStream(object_ptr<LogStream> &&log_stream_);

  static const std::int32_t ID = -1364199535;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<setLogStream> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class setLogTagVerbosityLevel final : public Function {
 public:
  static jclass Class;
  std::string tag_;
  static jfieldID tag_fieldID;
  std::int32_t new_verbosity_level_;
  static jfieldID new_verbosity_level_fieldID;

  setLogTagVerbosityLevel();

  setLogTagVerbosityLevel(std::string const &tag_, std::int32_t new_verbosity_level_);

  static const std::int32_t ID = -2095589738;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<setLogTagVerbosityLevel> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class setLogVerbosityLevel final : public Function {
 public:
  static jclass Class;
  std::int32_t new_verbosity_level_;
  static jfieldID new_verbosity_level_fieldID;

  setLogVerbosityLevel();

  explicit setLogVerbosityLevel(std::int32_t new_verbosity_level_);

  static const std::int32_t ID = -303429678;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<setLogVerbosityLevel> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_getCode final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  smc_getCode();

  explicit smc_getCode(std::int64_t id_);

  static const std::int32_t ID = -2115626088;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tvm_cell>;

  static object_ptr<smc_getCode> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_getData final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  smc_getData();

  explicit smc_getData(std::int64_t id_);

  static const std::int32_t ID = -427601079;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tvm_cell>;

  static object_ptr<smc_getData> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_getState final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;

  smc_getState();

  explicit smc_getState(std::int64_t id_);

  static const std::int32_t ID = -214390293;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<tvm_cell>;

  static object_ptr<smc_getState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_load final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  smc_load();

  explicit smc_load(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = -903491521;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<smc_info>;

  static object_ptr<smc_load> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class smc_runGetMethod final : public Function {
 public:
  static jclass Class;
  std::int64_t id_;
  static jfieldID id_fieldID;
  object_ptr<smc_MethodId> method_;
  static jfieldID method_fieldID;
  std::vector<object_ptr<tvm_StackEntry>> stack_;
  static jfieldID stack_fieldID;

  smc_runGetMethod();

  smc_runGetMethod(std::int64_t id_, object_ptr<smc_MethodId> &&method_, std::vector<object_ptr<tvm_StackEntry>> &&stack_);

  static const std::int32_t ID = -255261270;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<smc_runResult>;

  static object_ptr<smc_runGetMethod> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class sync final : public Function {
 public:
  static jclass Class;

  sync();

  static const std::int32_t ID = -1617065525;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<sync> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testGiver_getAccountAddress final : public Function {
 public:
  static jclass Class;

  testGiver_getAccountAddress();

  static const std::int32_t ID = -540100768;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<testGiver_getAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testGiver_getAccountState final : public Function {
 public:
  static jclass Class;

  testGiver_getAccountState();

  static const std::int32_t ID = 267738275;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<testGiver_accountState>;

  static object_ptr<testGiver_getAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testGiver_sendGrams final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  std::int64_t amount_;
  static jfieldID amount_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  testGiver_sendGrams();

  testGiver_sendGrams(object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t amount_, std::string const &message_);

  static const std::int32_t ID = -1785750375;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<sendGramsResult>;

  static object_ptr<testGiver_sendGrams> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_getAccountAddress final : public Function {
 public:
  static jclass Class;
  object_ptr<testWallet_initialAccountState> initital_account_state_;
  static jfieldID initital_account_state_fieldID;

  testWallet_getAccountAddress();

  explicit testWallet_getAccountAddress(object_ptr<testWallet_initialAccountState> &&initital_account_state_);

  static const std::int32_t ID = -1557748223;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<testWallet_getAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_getAccountState final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  testWallet_getAccountState();

  explicit testWallet_getAccountState(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = 654082364;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<testWallet_accountState>;

  static object_ptr<testWallet_getAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_init final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;

  testWallet_init();

  explicit testWallet_init(object_ptr<InputKey> &&private_key_);

  static const std::int32_t ID = -1417409140;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<testWallet_init> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_sendGrams final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  std::int64_t amount_;
  static jfieldID amount_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  testWallet_sendGrams();

  testWallet_sendGrams(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t amount_, std::string const &message_);

  static const std::int32_t ID = 573748322;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<sendGramsResult>;

  static object_ptr<testWallet_sendGrams> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class unpackAccountAddress final : public Function {
 public:
  static jclass Class;
  std::string account_address_;
  static jfieldID account_address_fieldID;

  unpackAccountAddress();

  explicit unpackAccountAddress(std::string const &account_address_);

  static const std::int32_t ID = -682459063;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<unpackedAccountAddress>;

  static object_ptr<unpackAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_getAccountAddress final : public Function {
 public:
  static jclass Class;
  object_ptr<wallet_initialAccountState> initital_account_state_;
  static jfieldID initital_account_state_fieldID;

  wallet_getAccountAddress();

  explicit wallet_getAccountAddress(object_ptr<wallet_initialAccountState> &&initital_account_state_);

  static const std::int32_t ID = -1004103180;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<wallet_getAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_getAccountState final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  wallet_getAccountState();

  explicit wallet_getAccountState(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = 462294850;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<wallet_accountState>;

  static object_ptr<wallet_getAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_init final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;

  wallet_init();

  explicit wallet_init(object_ptr<InputKey> &&private_key_);

  static const std::int32_t ID = -395706309;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ok>;

  static object_ptr<wallet_init> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_sendGrams final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  std::int64_t valid_until_;
  static jfieldID valid_until_fieldID;
  std::int64_t amount_;
  static jfieldID amount_fieldID;
  std::string message_;
  static jfieldID message_fieldID;

  wallet_sendGrams();

  wallet_sendGrams(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t valid_until_, std::int64_t amount_, std::string const &message_);

  static const std::int32_t ID = 297317621;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<sendGramsResult>;

  static object_ptr<wallet_sendGrams> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_v3_getAccountAddress final : public Function {
 public:
  static jclass Class;
  object_ptr<wallet_v3_initialAccountState> initital_account_state_;
  static jfieldID initital_account_state_fieldID;

  wallet_v3_getAccountAddress();

  explicit wallet_v3_getAccountAddress(object_ptr<wallet_v3_initialAccountState> &&initital_account_state_);

  static const std::int32_t ID = 1011655671;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<wallet_v3_getAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

}  // namespace tonlib_api
}  // namespace ton
