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

class accountRevisionList;

class AccountState;

class Action;

class adnlAddress;

class bip39Hints;

class config;

class data;

class error;

class exportedEncryptedKey;

class exportedKey;

class exportedPemKey;

class exportedUnencryptedKey;

class fees;

class fullAccountState;

class InitialAccountState;

class InputKey;

class key;

class KeyStoreType;

class LogStream;

class logTags;

class logVerbosityLevel;

class ok;

class options;

class SyncState;

class unpackedAccountAddress;

class Update;

class dns_Action;

class dns_entry;

class dns_EntryData;

class dns_resolved;

class ton_blockId;

class internal_transactionId;

class liteServer_info;

class msg_Data;

class msg_dataDecrypted;

class msg_dataDecryptedArray;

class msg_dataEncrypted;

class msg_dataEncryptedArray;

class msg_message;

class options_configInfo;

class options_info;

class query_fees;

class query_info;

class raw_fullAccountState;

class raw_message;

class raw_transaction;

class raw_transactions;

class smc_info;

class smc_MethodId;

class smc_runResult;

class ton_blockIdExt;

class tvm_cell;

class tvm_list;

class tvm_numberDecimal;

class tvm_slice;

class tvm_StackEntry;

class tvm_tuple;

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

class accountRevisionList final : public Object {
 public:
  static jclass Class;
  std::vector<std::int32_t> revisions_;
  static jfieldID revisions_fieldID;

  accountRevisionList();

  explicit accountRevisionList(std::vector<std::int32_t> &&revisions_);

  static const std::int32_t ID = 120583012;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<accountRevisionList> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class AccountState: public Object {
 public:
  static jclass Class;

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_accountState final : public AccountState {
 public:
  static jclass Class;
  std::string code_;
  static jfieldID code_fieldID;
  std::string data_;
  static jfieldID data_fieldID;
  std::string frozen_hash_;
  static jfieldID frozen_hash_fieldID;

  raw_accountState();

  raw_accountState(std::string const &code_, std::string const &data_, std::string const &frozen_hash_);

  static const std::int32_t ID = -531917254;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;

  testWallet_accountState();

  explicit testWallet_accountState(std::int32_t seqno_);

  static const std::int32_t ID = -2053909931;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;

  wallet_accountState();

  explicit wallet_accountState(std::int32_t seqno_);

  static const std::int32_t ID = -390017192;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_v3_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;

  wallet_v3_accountState();

  wallet_v3_accountState(std::int64_t wallet_id_, std::int32_t seqno_);

  static const std::int32_t ID = -1619351478;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_highload_v1_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;

  wallet_highload_v1_accountState();

  wallet_highload_v1_accountState(std::int64_t wallet_id_, std::int32_t seqno_);

  static const std::int32_t ID = 1616372956;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_highload_v2_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  wallet_highload_v2_accountState();

  explicit wallet_highload_v2_accountState(std::int64_t wallet_id_);

  static const std::int32_t ID = -1803723441;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testGiver_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;

  testGiver_accountState();

  explicit testGiver_accountState(std::int32_t seqno_);

  static const std::int32_t ID = -696813142;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_accountState final : public AccountState {
 public:
  static jclass Class;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  dns_accountState();

  explicit dns_accountState(std::int64_t wallet_id_);

  static const std::int32_t ID = 1727715434;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class uninited_accountState final : public AccountState {
 public:
  static jclass Class;
  std::string frozen_hash_;
  static jfieldID frozen_hash_fieldID;

  uninited_accountState();

  explicit uninited_accountState(std::string const &frozen_hash_);

  static const std::int32_t ID = 1522374408;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<AccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class Action: public Object {
 public:
  static jclass Class;

  static object_ptr<Action> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class actionNoop final : public Action {
 public:
  static jclass Class;

  actionNoop();

  static const std::int32_t ID = 1135848603;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Action> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class actionMsg final : public Action {
 public:
  static jclass Class;
  std::vector<object_ptr<msg_message>> messages_;
  static jfieldID messages_fieldID;
  bool allow_send_to_uninited_;
  static jfieldID allow_send_to_uninited_fieldID;

  actionMsg();

  actionMsg(std::vector<object_ptr<msg_message>> &&messages_, bool allow_send_to_uninited_);

  static const std::int32_t ID = 246839120;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Action> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class actionDns final : public Action {
 public:
  static jclass Class;
  std::vector<object_ptr<dns_Action>> actions_;
  static jfieldID actions_fieldID;

  actionDns();

  explicit actionDns(std::vector<object_ptr<dns_Action>> &&actions_);

  static const std::int32_t ID = 1193750561;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<Action> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class adnlAddress final : public Object {
 public:
  static jclass Class;
  std::string adnl_address_;
  static jfieldID adnl_address_fieldID;

  adnlAddress();

  explicit adnlAddress(std::string const &adnl_address_);

  static const std::int32_t ID = 70358284;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<adnlAddress> fetch(JNIEnv *env, jobject &p);

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

class exportedUnencryptedKey final : public Object {
 public:
  static jclass Class;
  td::SecureString data_;
  static jfieldID data_fieldID;

  exportedUnencryptedKey();

  explicit exportedUnencryptedKey(td::SecureString &&data_);

  static const std::int32_t ID = 730045160;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<exportedUnencryptedKey> fetch(JNIEnv *env, jobject &p);

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

class fullAccountState final : public Object {
 public:
  static jclass Class;
  std::int64_t balance_;
  static jfieldID balance_fieldID;
  object_ptr<internal_transactionId> last_transaction_id_;
  static jfieldID last_transaction_id_fieldID;
  object_ptr<ton_blockIdExt> block_id_;
  static jfieldID block_id_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;
  object_ptr<AccountState> account_state_;
  static jfieldID account_state_fieldID;

  fullAccountState();

  fullAccountState(std::int64_t balance_, object_ptr<internal_transactionId> &&last_transaction_id_, object_ptr<ton_blockIdExt> &&block_id_, std::int64_t sync_utime_, object_ptr<AccountState> &&account_state_);

  static const std::int32_t ID = -686286006;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<fullAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class InitialAccountState: public Object {
 public:
  static jclass Class;

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string code_;
  static jfieldID code_fieldID;
  std::string data_;
  static jfieldID data_fieldID;

  raw_initialAccountState();

  raw_initialAccountState(std::string const &code_, std::string const &data_);

  static const std::int32_t ID = -337945529;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testGiver_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;

  testGiver_initialAccountState();

  static const std::int32_t ID = -1448412176;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class testWallet_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;

  testWallet_initialAccountState();

  explicit testWallet_initialAccountState(std::string const &public_key_);

  static const std::int32_t ID = 819380068;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;

  wallet_initialAccountState();

  explicit wallet_initialAccountState(std::string const &public_key_);

  static const std::int32_t ID = -1122166790;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_v3_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  wallet_v3_initialAccountState();

  wallet_v3_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_);

  static const std::int32_t ID = -118074048;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_highload_v1_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  wallet_highload_v1_initialAccountState();

  wallet_highload_v1_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_);

  static const std::int32_t ID = -327901626;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class wallet_highload_v2_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  wallet_highload_v2_initialAccountState();

  wallet_highload_v2_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_);

  static const std::int32_t ID = 1966373161;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_initialAccountState final : public InitialAccountState {
 public:
  static jclass Class;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  std::int64_t wallet_id_;
  static jfieldID wallet_id_fieldID;

  dns_initialAccountState();

  dns_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_);

  static const std::int32_t ID = 1842062527;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<InitialAccountState> fetch(JNIEnv *env, jobject &p);

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

class dns_Action: public Object {
 public:
  static jclass Class;

  static object_ptr<dns_Action> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_actionDeleteAll final : public dns_Action {
 public:
  static jclass Class;

  dns_actionDeleteAll();

  static const std::int32_t ID = 1067356318;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_Action> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_actionDelete final : public dns_Action {
 public:
  static jclass Class;
  std::string name_;
  static jfieldID name_fieldID;
  std::int32_t category_;
  static jfieldID category_fieldID;

  dns_actionDelete();

  dns_actionDelete(std::string const &name_, std::int32_t category_);

  static const std::int32_t ID = 775206882;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_Action> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_actionSet final : public dns_Action {
 public:
  static jclass Class;
  object_ptr<dns_entry> entry_;
  static jfieldID entry_fieldID;

  dns_actionSet();

  explicit dns_actionSet(object_ptr<dns_entry> &&entry_);

  static const std::int32_t ID = -1374965309;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_Action> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_entry final : public Object {
 public:
  static jclass Class;
  std::string name_;
  static jfieldID name_fieldID;
  std::int32_t category_;
  static jfieldID category_fieldID;
  object_ptr<dns_EntryData> entry_;
  static jfieldID entry_fieldID;

  dns_entry();

  dns_entry(std::string const &name_, std::int32_t category_, object_ptr<dns_EntryData> &&entry_);

  static const std::int32_t ID = -1842435400;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_entry> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_EntryData: public Object {
 public:
  static jclass Class;

  static object_ptr<dns_EntryData> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_entryDataUnknown final : public dns_EntryData {
 public:
  static jclass Class;
  std::string bytes_;
  static jfieldID bytes_fieldID;

  dns_entryDataUnknown();

  explicit dns_entryDataUnknown(std::string const &bytes_);

  static const std::int32_t ID = -1285893248;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_EntryData> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_entryDataText final : public dns_EntryData {
 public:
  static jclass Class;
  std::string text_;
  static jfieldID text_fieldID;

  dns_entryDataText();

  explicit dns_entryDataText(std::string const &text_);

  static const std::int32_t ID = -792485614;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_EntryData> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_entryDataNextResolver final : public dns_EntryData {
 public:
  static jclass Class;
  object_ptr<accountAddress> resolver_;
  static jfieldID resolver_fieldID;

  dns_entryDataNextResolver();

  explicit dns_entryDataNextResolver(object_ptr<accountAddress> &&resolver_);

  static const std::int32_t ID = 330382792;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_EntryData> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_entryDataSmcAddress final : public dns_EntryData {
 public:
  static jclass Class;
  object_ptr<accountAddress> smc_address_;
  static jfieldID smc_address_fieldID;

  dns_entryDataSmcAddress();

  explicit dns_entryDataSmcAddress(object_ptr<accountAddress> &&smc_address_);

  static const std::int32_t ID = -1759937982;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_EntryData> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_entryDataAdnlAddress final : public dns_EntryData {
 public:
  static jclass Class;
  object_ptr<adnlAddress> adnl_address_;
  static jfieldID adnl_address_fieldID;

  dns_entryDataAdnlAddress();

  explicit dns_entryDataAdnlAddress(object_ptr<adnlAddress> &&adnl_address_);

  static const std::int32_t ID = -1114064368;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_EntryData> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class dns_resolved final : public Object {
 public:
  static jclass Class;
  std::vector<object_ptr<dns_entry>> entries_;
  static jfieldID entries_fieldID;

  dns_resolved();

  explicit dns_resolved(std::vector<object_ptr<dns_entry>> &&entries_);

  static const std::int32_t ID = 2090272150;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<dns_resolved> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class ton_blockId final : public Object {
 public:
  static jclass Class;
  std::int32_t workchain_;
  static jfieldID workchain_fieldID;
  std::int64_t shard_;
  static jfieldID shard_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;

  ton_blockId();

  ton_blockId(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_);

  static const std::int32_t ID = -1185382494;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<ton_blockId> fetch(JNIEnv *env, jobject &p);

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

class msg_Data: public Object {
 public:
  static jclass Class;

  static object_ptr<msg_Data> fetch(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataRaw final : public msg_Data {
 public:
  static jclass Class;
  std::string body_;
  static jfieldID body_fieldID;

  msg_dataRaw();

  explicit msg_dataRaw(std::string const &body_);

  static const std::int32_t ID = 38878511;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_Data> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataText final : public msg_Data {
 public:
  static jclass Class;
  std::string text_;
  static jfieldID text_fieldID;

  msg_dataText();

  explicit msg_dataText(std::string const &text_);

  static const std::int32_t ID = -341560688;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_Data> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataDecryptedText final : public msg_Data {
 public:
  static jclass Class;
  std::string text_;
  static jfieldID text_fieldID;

  msg_dataDecryptedText();

  explicit msg_dataDecryptedText(std::string const &text_);

  static const std::int32_t ID = -1289133895;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_Data> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataEncryptedText final : public msg_Data {
 public:
  static jclass Class;
  std::string text_;
  static jfieldID text_fieldID;

  msg_dataEncryptedText();

  explicit msg_dataEncryptedText(std::string const &text_);

  static const std::int32_t ID = -296612902;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_Data> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataDecrypted final : public Object {
 public:
  static jclass Class;
  std::string proof_;
  static jfieldID proof_fieldID;
  object_ptr<msg_Data> data_;
  static jfieldID data_fieldID;

  msg_dataDecrypted();

  msg_dataDecrypted(std::string const &proof_, object_ptr<msg_Data> &&data_);

  static const std::int32_t ID = 195649769;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_dataDecrypted> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataDecryptedArray final : public Object {
 public:
  static jclass Class;
  std::vector<object_ptr<msg_dataDecrypted>> elements_;
  static jfieldID elements_fieldID;

  msg_dataDecryptedArray();

  explicit msg_dataDecryptedArray(std::vector<object_ptr<msg_dataDecrypted>> &&elements_);

  static const std::int32_t ID = -480491767;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_dataDecryptedArray> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataEncrypted final : public Object {
 public:
  static jclass Class;
  object_ptr<accountAddress> source_;
  static jfieldID source_fieldID;
  object_ptr<msg_Data> data_;
  static jfieldID data_fieldID;

  msg_dataEncrypted();

  msg_dataEncrypted(object_ptr<accountAddress> &&source_, object_ptr<msg_Data> &&data_);

  static const std::int32_t ID = 564215121;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_dataEncrypted> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_dataEncryptedArray final : public Object {
 public:
  static jclass Class;
  std::vector<object_ptr<msg_dataEncrypted>> elements_;
  static jfieldID elements_fieldID;

  msg_dataEncryptedArray();

  explicit msg_dataEncryptedArray(std::vector<object_ptr<msg_dataEncrypted>> &&elements_);

  static const std::int32_t ID = 608655794;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_dataEncryptedArray> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_message final : public Object {
 public:
  static jclass Class;
  object_ptr<accountAddress> destination_;
  static jfieldID destination_fieldID;
  std::string public_key_;
  static jfieldID public_key_fieldID;
  std::int64_t amount_;
  static jfieldID amount_fieldID;
  object_ptr<msg_Data> data_;
  static jfieldID data_fieldID;

  msg_message();

  msg_message(object_ptr<accountAddress> &&destination_, std::string const &public_key_, std::int64_t amount_, object_ptr<msg_Data> &&data_);

  static const std::int32_t ID = -2110533580;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<msg_message> fetch(JNIEnv *env, jobject &p);

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

  static const std::int32_t ID = 451217371;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<options_configInfo> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class options_info final : public Object {
 public:
  static jclass Class;
  object_ptr<options_configInfo> config_info_;
  static jfieldID config_info_fieldID;

  options_info();

  explicit options_info(object_ptr<options_configInfo> &&config_info_);

  static const std::int32_t ID = -64676736;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<options_info> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class query_fees final : public Object {
 public:
  static jclass Class;
  object_ptr<fees> source_fees_;
  static jfieldID source_fees_fieldID;
  std::vector<object_ptr<fees>> destination_fees_;
  static jfieldID destination_fees_fieldID;

  query_fees();

  query_fees(object_ptr<fees> &&source_fees_, std::vector<object_ptr<fees>> &&destination_fees_);

  static const std::int32_t ID = 1614616510;
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

class raw_fullAccountState final : public Object {
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
  object_ptr<ton_blockIdExt> block_id_;
  static jfieldID block_id_fieldID;
  std::string frozen_hash_;
  static jfieldID frozen_hash_fieldID;
  std::int64_t sync_utime_;
  static jfieldID sync_utime_fieldID;

  raw_fullAccountState();

  raw_fullAccountState(std::int64_t balance_, std::string const &code_, std::string const &data_, object_ptr<internal_transactionId> &&last_transaction_id_, object_ptr<ton_blockIdExt> &&block_id_, std::string const &frozen_hash_, std::int64_t sync_utime_);

  static const std::int32_t ID = -1465398385;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<raw_fullAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_message final : public Object {
 public:
  static jclass Class;
  object_ptr<accountAddress> source_;
  static jfieldID source_fieldID;
  object_ptr<accountAddress> destination_;
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
  object_ptr<msg_Data> msg_data_;
  static jfieldID msg_data_fieldID;

  raw_message();

  raw_message(object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t value_, std::int64_t fwd_fee_, std::int64_t ihr_fee_, std::int64_t created_lt_, std::string const &body_hash_, object_ptr<msg_Data> &&msg_data_);

  static const std::int32_t ID = 1368093263;
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

class ton_blockIdExt final : public Object {
 public:
  static jclass Class;
  std::int32_t workchain_;
  static jfieldID workchain_fieldID;
  std::int64_t shard_;
  static jfieldID shard_fieldID;
  std::int32_t seqno_;
  static jfieldID seqno_fieldID;
  std::string root_hash_;
  static jfieldID root_hash_fieldID;
  std::string file_hash_;
  static jfieldID file_hash_fieldID;

  ton_blockIdExt();

  ton_blockIdExt(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_, std::string const &root_hash_, std::string const &file_hash_);

  static const std::int32_t ID = 2031156378;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<ton_blockIdExt> fetch(JNIEnv *env, jobject &p);

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

  static const std::int32_t ID = -413424735;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_cell> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_list final : public Object {
 public:
  static jclass Class;
  std::vector<object_ptr<tvm_StackEntry>> elements_;
  static jfieldID elements_fieldID;

  tvm_list();

  explicit tvm_list(std::vector<object_ptr<tvm_StackEntry>> &&elements_);

  static const std::int32_t ID = 1270320392;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_list> fetch(JNIEnv *env, jobject &p);

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

  static const std::int32_t ID = 537299687;
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

class tvm_stackEntryTuple final : public tvm_StackEntry {
 public:
  static jclass Class;
  object_ptr<tvm_tuple> tuple_;
  static jfieldID tuple_fieldID;

  tvm_stackEntryTuple();

  explicit tvm_stackEntryTuple(object_ptr<tvm_tuple> &&tuple_);

  static const std::int32_t ID = -157391908;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_StackEntry> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class tvm_stackEntryList final : public tvm_StackEntry {
 public:
  static jclass Class;
  object_ptr<tvm_list> list_;
  static jfieldID list_fieldID;

  tvm_stackEntryList();

  explicit tvm_stackEntryList(object_ptr<tvm_list> &&list_);

  static const std::int32_t ID = -1186714229;
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

class tvm_tuple final : public Object {
 public:
  static jclass Class;
  std::vector<object_ptr<tvm_StackEntry>> elements_;
  static jfieldID elements_fieldID;

  tvm_tuple();

  explicit tvm_tuple(std::vector<object_ptr<tvm_StackEntry>> &&elements_);

  static const std::int32_t ID = -1363953053;
  std::int32_t get_id() const final {
    return ID;
  }

  static object_ptr<tvm_tuple> fetch(JNIEnv *env, jobject &p);

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

class createQuery final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;
  object_ptr<accountAddress> address_;
  static jfieldID address_fieldID;
  std::int32_t timeout_;
  static jfieldID timeout_fieldID;
  object_ptr<Action> action_;
  static jfieldID action_fieldID;

  createQuery();

  createQuery(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&address_, std::int32_t timeout_, object_ptr<Action> &&action_);

  static const std::int32_t ID = -1316835098;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<query_info>;

  static object_ptr<createQuery> fetch(JNIEnv *env, jobject &p);

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

class dns_resolve final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;
  std::string name_;
  static jfieldID name_fieldID;
  std::int32_t category_;
  static jfieldID category_fieldID;
  std::int32_t ttl_;
  static jfieldID ttl_fieldID;

  dns_resolve();

  dns_resolve(object_ptr<accountAddress> &&account_address_, std::string const &name_, std::int32_t category_, std::int32_t ttl_);

  static const std::int32_t ID = -149238065;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<dns_resolved>;

  static object_ptr<dns_resolve> fetch(JNIEnv *env, jobject &p);

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

class exportUnencryptedKey final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> input_key_;
  static jfieldID input_key_fieldID;

  exportUnencryptedKey();

  explicit exportUnencryptedKey(object_ptr<InputKey> &&input_key_);

  static const std::int32_t ID = -634665152;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<exportedUnencryptedKey>;

  static object_ptr<exportUnencryptedKey> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getAccountAddress final : public Function {
 public:
  static jclass Class;
  object_ptr<InitialAccountState> initial_account_state_;
  static jfieldID initial_account_state_fieldID;
  std::int32_t revision_;
  static jfieldID revision_fieldID;

  getAccountAddress();

  getAccountAddress(object_ptr<InitialAccountState> &&initial_account_state_, std::int32_t revision_);

  static const std::int32_t ID = -1159101819;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountAddress>;

  static object_ptr<getAccountAddress> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class getAccountState final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  getAccountState();

  explicit getAccountState(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = -2116357050;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<fullAccountState>;

  static object_ptr<getAccountState> fetch(JNIEnv *env, jobject &p);

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

class guessAccountRevision final : public Function {
 public:
  static jclass Class;
  object_ptr<InitialAccountState> initial_account_state_;
  static jfieldID initial_account_state_fieldID;

  guessAccountRevision();

  explicit guessAccountRevision(object_ptr<InitialAccountState> &&initial_account_state_);

  static const std::int32_t ID = 1463344293;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<accountRevisionList>;

  static object_ptr<guessAccountRevision> fetch(JNIEnv *env, jobject &p);

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

class importUnencryptedKey final : public Function {
 public:
  static jclass Class;
  td::SecureString local_password_;
  static jfieldID local_password_fieldID;
  object_ptr<exportedUnencryptedKey> exported_unencrypted_key_;
  static jfieldID exported_unencrypted_key_fieldID;

  importUnencryptedKey();

  importUnencryptedKey(td::SecureString &&local_password_, object_ptr<exportedUnencryptedKey> &&exported_unencrypted_key_);

  static const std::int32_t ID = -1184671467;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<key>;

  static object_ptr<importUnencryptedKey> fetch(JNIEnv *env, jobject &p);

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

  static const std::int32_t ID = -1000594762;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<options_info>;

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

class msg_decrypt final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> input_key_;
  static jfieldID input_key_fieldID;
  object_ptr<msg_dataEncryptedArray> data_;
  static jfieldID data_fieldID;

  msg_decrypt();

  msg_decrypt(object_ptr<InputKey> &&input_key_, object_ptr<msg_dataEncryptedArray> &&data_);

  static const std::int32_t ID = 223596297;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<msg_dataDecryptedArray>;

  static object_ptr<msg_decrypt> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class msg_decryptWithProof final : public Function {
 public:
  static jclass Class;
  std::string proof_;
  static jfieldID proof_fieldID;
  object_ptr<msg_dataEncrypted> data_;
  static jfieldID data_fieldID;

  msg_decryptWithProof();

  msg_decryptWithProof(std::string const &proof_, object_ptr<msg_dataEncrypted> &&data_);

  static const std::int32_t ID = -2111649663;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<msg_Data>;

  static object_ptr<msg_decryptWithProof> fetch(JNIEnv *env, jobject &p);

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

  static const std::int32_t ID = 1870064579;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<options_configInfo>;

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

class raw_getAccountState final : public Function {
 public:
  static jclass Class;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;

  raw_getAccountState();

  explicit raw_getAccountState(object_ptr<accountAddress> &&account_address_);

  static const std::int32_t ID = -1327847118;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<raw_fullAccountState>;

  static object_ptr<raw_getAccountState> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

class raw_getTransactions final : public Function {
 public:
  static jclass Class;
  object_ptr<InputKey> private_key_;
  static jfieldID private_key_fieldID;
  object_ptr<accountAddress> account_address_;
  static jfieldID account_address_fieldID;
  object_ptr<internal_transactionId> from_transaction_id_;
  static jfieldID from_transaction_id_fieldID;

  raw_getTransactions();

  raw_getTransactions(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&account_address_, object_ptr<internal_transactionId> &&from_transaction_id_);

  static const std::int32_t ID = 1029612317;
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

  static const std::int32_t ID = -1875977070;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<ton_blockIdExt>;

  static object_ptr<sync> fetch(JNIEnv *env, jobject &p);

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

class withBlock final : public Function {
 public:
  static jclass Class;
  object_ptr<ton_blockIdExt> id_;
  static jfieldID id_fieldID;
  object_ptr<Function> function_;
  static jfieldID function_fieldID;

  withBlock();

  withBlock(object_ptr<ton_blockIdExt> &&id_, object_ptr<Function> &&function_);

  static const std::int32_t ID = -789093723;
  std::int32_t get_id() const final {
    return ID;
  }

  using ReturnType = object_ptr<Object>;

  static object_ptr<withBlock> fetch(JNIEnv *env, jobject &p);

  void store(JNIEnv *env, jobject &s) const final;

  void store(td::TlStorerToString &s, const char *field_name) const final;

  static ReturnType fetch_result(JNIEnv *env, jobject &p);

  static void init_jni_vars(JNIEnv *env, const char *package_name);
};

}  // namespace tonlib_api
}  // namespace ton
