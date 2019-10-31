#include "tonlib_api.h"

#include "tl/tl_jni_object.h"
#include "tl/tl_object_store.h"
#include "td/utils/int_types.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"

namespace ton {
namespace tonlib_api {

std::string to_string(const BaseObject &value) {
  td::TlStorerToString storer;
  value.store(storer, "");
  return storer.str();
}

jclass Object::Class;

object_ptr<Object> Object::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case accountAddress::ID:
      return accountAddress::fetch(env, p);
    case bip39Hints::ID:
      return bip39Hints::fetch(env, p);
    case config::ID:
      return config::fetch(env, p);
    case data::ID:
      return data::fetch(env, p);
    case error::ID:
      return error::fetch(env, p);
    case exportedEncryptedKey::ID:
      return exportedEncryptedKey::fetch(env, p);
    case exportedKey::ID:
      return exportedKey::fetch(env, p);
    case exportedPemKey::ID:
      return exportedPemKey::fetch(env, p);
    case fees::ID:
      return fees::fetch(env, p);
    case inputKeyRegular::ID:
      return inputKeyRegular::fetch(env, p);
    case inputKeyFake::ID:
      return inputKeyFake::fetch(env, p);
    case key::ID:
      return key::fetch(env, p);
    case keyStoreTypeDirectory::ID:
      return keyStoreTypeDirectory::fetch(env, p);
    case keyStoreTypeInMemory::ID:
      return keyStoreTypeInMemory::fetch(env, p);
    case logStreamDefault::ID:
      return logStreamDefault::fetch(env, p);
    case logStreamFile::ID:
      return logStreamFile::fetch(env, p);
    case logStreamEmpty::ID:
      return logStreamEmpty::fetch(env, p);
    case logTags::ID:
      return logTags::fetch(env, p);
    case logVerbosityLevel::ID:
      return logVerbosityLevel::fetch(env, p);
    case ok::ID:
      return ok::fetch(env, p);
    case options::ID:
      return options::fetch(env, p);
    case sendGramsResult::ID:
      return sendGramsResult::fetch(env, p);
    case syncStateDone::ID:
      return syncStateDone::fetch(env, p);
    case syncStateInProgress::ID:
      return syncStateInProgress::fetch(env, p);
    case unpackedAccountAddress::ID:
      return unpackedAccountAddress::fetch(env, p);
    case updateSendLiteServerQuery::ID:
      return updateSendLiteServerQuery::fetch(env, p);
    case updateSyncState::ID:
      return updateSyncState::fetch(env, p);
    case generic_accountStateRaw::ID:
      return generic_accountStateRaw::fetch(env, p);
    case generic_accountStateTestWallet::ID:
      return generic_accountStateTestWallet::fetch(env, p);
    case generic_accountStateWallet::ID:
      return generic_accountStateWallet::fetch(env, p);
    case generic_accountStateWalletV3::ID:
      return generic_accountStateWalletV3::fetch(env, p);
    case generic_accountStateTestGiver::ID:
      return generic_accountStateTestGiver::fetch(env, p);
    case generic_accountStateUninited::ID:
      return generic_accountStateUninited::fetch(env, p);
    case internal_transactionId::ID:
      return internal_transactionId::fetch(env, p);
    case liteServer_info::ID:
      return liteServer_info::fetch(env, p);
    case options_configInfo::ID:
      return options_configInfo::fetch(env, p);
    case query_fees::ID:
      return query_fees::fetch(env, p);
    case query_info::ID:
      return query_info::fetch(env, p);
    case raw_accountState::ID:
      return raw_accountState::fetch(env, p);
    case raw_initialAccountState::ID:
      return raw_initialAccountState::fetch(env, p);
    case raw_message::ID:
      return raw_message::fetch(env, p);
    case raw_transaction::ID:
      return raw_transaction::fetch(env, p);
    case raw_transactions::ID:
      return raw_transactions::fetch(env, p);
    case smc_info::ID:
      return smc_info::fetch(env, p);
    case smc_methodIdNumber::ID:
      return smc_methodIdNumber::fetch(env, p);
    case smc_methodIdName::ID:
      return smc_methodIdName::fetch(env, p);
    case smc_runResult::ID:
      return smc_runResult::fetch(env, p);
    case testGiver_accountState::ID:
      return testGiver_accountState::fetch(env, p);
    case testWallet_accountState::ID:
      return testWallet_accountState::fetch(env, p);
    case testWallet_initialAccountState::ID:
      return testWallet_initialAccountState::fetch(env, p);
    case tvm_cell::ID:
      return tvm_cell::fetch(env, p);
    case tvm_numberDecimal::ID:
      return tvm_numberDecimal::fetch(env, p);
    case tvm_slice::ID:
      return tvm_slice::fetch(env, p);
    case tvm_stackEntrySlice::ID:
      return tvm_stackEntrySlice::fetch(env, p);
    case tvm_stackEntryCell::ID:
      return tvm_stackEntryCell::fetch(env, p);
    case tvm_stackEntryNumber::ID:
      return tvm_stackEntryNumber::fetch(env, p);
    case tvm_stackEntryUnsupported::ID:
      return tvm_stackEntryUnsupported::fetch(env, p);
    case uninited_accountState::ID:
      return uninited_accountState::fetch(env, p);
    case wallet_accountState::ID:
      return wallet_accountState::fetch(env, p);
    case wallet_initialAccountState::ID:
      return wallet_initialAccountState::fetch(env, p);
    case wallet_v3_accountState::ID:
      return wallet_v3_accountState::fetch(env, p);
    case wallet_v3_initialAccountState::ID:
      return wallet_v3_initialAccountState::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void Object::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Object").c_str());
  accountAddress::init_jni_vars(env, package_name);
  bip39Hints::init_jni_vars(env, package_name);
  config::init_jni_vars(env, package_name);
  data::init_jni_vars(env, package_name);
  error::init_jni_vars(env, package_name);
  exportedEncryptedKey::init_jni_vars(env, package_name);
  exportedKey::init_jni_vars(env, package_name);
  exportedPemKey::init_jni_vars(env, package_name);
  fees::init_jni_vars(env, package_name);
  InputKey::init_jni_vars(env, package_name);
  key::init_jni_vars(env, package_name);
  KeyStoreType::init_jni_vars(env, package_name);
  LogStream::init_jni_vars(env, package_name);
  logTags::init_jni_vars(env, package_name);
  logVerbosityLevel::init_jni_vars(env, package_name);
  ok::init_jni_vars(env, package_name);
  options::init_jni_vars(env, package_name);
  sendGramsResult::init_jni_vars(env, package_name);
  SyncState::init_jni_vars(env, package_name);
  unpackedAccountAddress::init_jni_vars(env, package_name);
  Update::init_jni_vars(env, package_name);
  generic_AccountState::init_jni_vars(env, package_name);
  internal_transactionId::init_jni_vars(env, package_name);
  liteServer_info::init_jni_vars(env, package_name);
  options_configInfo::init_jni_vars(env, package_name);
  query_fees::init_jni_vars(env, package_name);
  query_info::init_jni_vars(env, package_name);
  raw_accountState::init_jni_vars(env, package_name);
  raw_initialAccountState::init_jni_vars(env, package_name);
  raw_message::init_jni_vars(env, package_name);
  raw_transaction::init_jni_vars(env, package_name);
  raw_transactions::init_jni_vars(env, package_name);
  smc_info::init_jni_vars(env, package_name);
  smc_MethodId::init_jni_vars(env, package_name);
  smc_runResult::init_jni_vars(env, package_name);
  testGiver_accountState::init_jni_vars(env, package_name);
  testWallet_accountState::init_jni_vars(env, package_name);
  testWallet_initialAccountState::init_jni_vars(env, package_name);
  tvm_cell::init_jni_vars(env, package_name);
  tvm_numberDecimal::init_jni_vars(env, package_name);
  tvm_slice::init_jni_vars(env, package_name);
  tvm_StackEntry::init_jni_vars(env, package_name);
  uninited_accountState::init_jni_vars(env, package_name);
  wallet_accountState::init_jni_vars(env, package_name);
  wallet_initialAccountState::init_jni_vars(env, package_name);
  wallet_v3_accountState::init_jni_vars(env, package_name);
  wallet_v3_initialAccountState::init_jni_vars(env, package_name);
}

jclass Function::Class;

object_ptr<Function> Function::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case addLogMessage::ID:
      return addLogMessage::fetch(env, p);
    case changeLocalPassword::ID:
      return changeLocalPassword::fetch(env, p);
    case close::ID:
      return close::fetch(env, p);
    case createNewKey::ID:
      return createNewKey::fetch(env, p);
    case decrypt::ID:
      return decrypt::fetch(env, p);
    case deleteAllKeys::ID:
      return deleteAllKeys::fetch(env, p);
    case deleteKey::ID:
      return deleteKey::fetch(env, p);
    case encrypt::ID:
      return encrypt::fetch(env, p);
    case exportEncryptedKey::ID:
      return exportEncryptedKey::fetch(env, p);
    case exportKey::ID:
      return exportKey::fetch(env, p);
    case exportPemKey::ID:
      return exportPemKey::fetch(env, p);
    case generic_createSendGramsQuery::ID:
      return generic_createSendGramsQuery::fetch(env, p);
    case generic_getAccountState::ID:
      return generic_getAccountState::fetch(env, p);
    case generic_sendGrams::ID:
      return generic_sendGrams::fetch(env, p);
    case getBip39Hints::ID:
      return getBip39Hints::fetch(env, p);
    case getLogStream::ID:
      return getLogStream::fetch(env, p);
    case getLogTagVerbosityLevel::ID:
      return getLogTagVerbosityLevel::fetch(env, p);
    case getLogTags::ID:
      return getLogTags::fetch(env, p);
    case getLogVerbosityLevel::ID:
      return getLogVerbosityLevel::fetch(env, p);
    case importEncryptedKey::ID:
      return importEncryptedKey::fetch(env, p);
    case importKey::ID:
      return importKey::fetch(env, p);
    case importPemKey::ID:
      return importPemKey::fetch(env, p);
    case init::ID:
      return init::fetch(env, p);
    case kdf::ID:
      return kdf::fetch(env, p);
    case liteServer_getInfo::ID:
      return liteServer_getInfo::fetch(env, p);
    case onLiteServerQueryError::ID:
      return onLiteServerQueryError::fetch(env, p);
    case onLiteServerQueryResult::ID:
      return onLiteServerQueryResult::fetch(env, p);
    case options_setConfig::ID:
      return options_setConfig::fetch(env, p);
    case options_validateConfig::ID:
      return options_validateConfig::fetch(env, p);
    case packAccountAddress::ID:
      return packAccountAddress::fetch(env, p);
    case query_estimateFees::ID:
      return query_estimateFees::fetch(env, p);
    case query_forget::ID:
      return query_forget::fetch(env, p);
    case query_getInfo::ID:
      return query_getInfo::fetch(env, p);
    case query_send::ID:
      return query_send::fetch(env, p);
    case raw_createAndSendMessage::ID:
      return raw_createAndSendMessage::fetch(env, p);
    case raw_createQuery::ID:
      return raw_createQuery::fetch(env, p);
    case raw_getAccountAddress::ID:
      return raw_getAccountAddress::fetch(env, p);
    case raw_getAccountState::ID:
      return raw_getAccountState::fetch(env, p);
    case raw_getTransactions::ID:
      return raw_getTransactions::fetch(env, p);
    case raw_sendMessage::ID:
      return raw_sendMessage::fetch(env, p);
    case runTests::ID:
      return runTests::fetch(env, p);
    case setLogStream::ID:
      return setLogStream::fetch(env, p);
    case setLogTagVerbosityLevel::ID:
      return setLogTagVerbosityLevel::fetch(env, p);
    case setLogVerbosityLevel::ID:
      return setLogVerbosityLevel::fetch(env, p);
    case smc_getCode::ID:
      return smc_getCode::fetch(env, p);
    case smc_getData::ID:
      return smc_getData::fetch(env, p);
    case smc_getState::ID:
      return smc_getState::fetch(env, p);
    case smc_load::ID:
      return smc_load::fetch(env, p);
    case smc_runGetMethod::ID:
      return smc_runGetMethod::fetch(env, p);
    case sync::ID:
      return sync::fetch(env, p);
    case testGiver_getAccountAddress::ID:
      return testGiver_getAccountAddress::fetch(env, p);
    case testGiver_getAccountState::ID:
      return testGiver_getAccountState::fetch(env, p);
    case testGiver_sendGrams::ID:
      return testGiver_sendGrams::fetch(env, p);
    case testWallet_getAccountAddress::ID:
      return testWallet_getAccountAddress::fetch(env, p);
    case testWallet_getAccountState::ID:
      return testWallet_getAccountState::fetch(env, p);
    case testWallet_init::ID:
      return testWallet_init::fetch(env, p);
    case testWallet_sendGrams::ID:
      return testWallet_sendGrams::fetch(env, p);
    case unpackAccountAddress::ID:
      return unpackAccountAddress::fetch(env, p);
    case wallet_getAccountAddress::ID:
      return wallet_getAccountAddress::fetch(env, p);
    case wallet_getAccountState::ID:
      return wallet_getAccountState::fetch(env, p);
    case wallet_init::ID:
      return wallet_init::fetch(env, p);
    case wallet_sendGrams::ID:
      return wallet_sendGrams::fetch(env, p);
    case wallet_v3_getAccountAddress::ID:
      return wallet_v3_getAccountAddress::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void Function::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Function").c_str());
  addLogMessage::init_jni_vars(env, package_name);
  changeLocalPassword::init_jni_vars(env, package_name);
  close::init_jni_vars(env, package_name);
  createNewKey::init_jni_vars(env, package_name);
  decrypt::init_jni_vars(env, package_name);
  deleteAllKeys::init_jni_vars(env, package_name);
  deleteKey::init_jni_vars(env, package_name);
  encrypt::init_jni_vars(env, package_name);
  exportEncryptedKey::init_jni_vars(env, package_name);
  exportKey::init_jni_vars(env, package_name);
  exportPemKey::init_jni_vars(env, package_name);
  generic_createSendGramsQuery::init_jni_vars(env, package_name);
  generic_getAccountState::init_jni_vars(env, package_name);
  generic_sendGrams::init_jni_vars(env, package_name);
  getBip39Hints::init_jni_vars(env, package_name);
  getLogStream::init_jni_vars(env, package_name);
  getLogTagVerbosityLevel::init_jni_vars(env, package_name);
  getLogTags::init_jni_vars(env, package_name);
  getLogVerbosityLevel::init_jni_vars(env, package_name);
  importEncryptedKey::init_jni_vars(env, package_name);
  importKey::init_jni_vars(env, package_name);
  importPemKey::init_jni_vars(env, package_name);
  init::init_jni_vars(env, package_name);
  kdf::init_jni_vars(env, package_name);
  liteServer_getInfo::init_jni_vars(env, package_name);
  onLiteServerQueryError::init_jni_vars(env, package_name);
  onLiteServerQueryResult::init_jni_vars(env, package_name);
  options_setConfig::init_jni_vars(env, package_name);
  options_validateConfig::init_jni_vars(env, package_name);
  packAccountAddress::init_jni_vars(env, package_name);
  query_estimateFees::init_jni_vars(env, package_name);
  query_forget::init_jni_vars(env, package_name);
  query_getInfo::init_jni_vars(env, package_name);
  query_send::init_jni_vars(env, package_name);
  raw_createAndSendMessage::init_jni_vars(env, package_name);
  raw_createQuery::init_jni_vars(env, package_name);
  raw_getAccountAddress::init_jni_vars(env, package_name);
  raw_getAccountState::init_jni_vars(env, package_name);
  raw_getTransactions::init_jni_vars(env, package_name);
  raw_sendMessage::init_jni_vars(env, package_name);
  runTests::init_jni_vars(env, package_name);
  setLogStream::init_jni_vars(env, package_name);
  setLogTagVerbosityLevel::init_jni_vars(env, package_name);
  setLogVerbosityLevel::init_jni_vars(env, package_name);
  smc_getCode::init_jni_vars(env, package_name);
  smc_getData::init_jni_vars(env, package_name);
  smc_getState::init_jni_vars(env, package_name);
  smc_load::init_jni_vars(env, package_name);
  smc_runGetMethod::init_jni_vars(env, package_name);
  sync::init_jni_vars(env, package_name);
  testGiver_getAccountAddress::init_jni_vars(env, package_name);
  testGiver_getAccountState::init_jni_vars(env, package_name);
  testGiver_sendGrams::init_jni_vars(env, package_name);
  testWallet_getAccountAddress::init_jni_vars(env, package_name);
  testWallet_getAccountState::init_jni_vars(env, package_name);
  testWallet_init::init_jni_vars(env, package_name);
  testWallet_sendGrams::init_jni_vars(env, package_name);
  unpackAccountAddress::init_jni_vars(env, package_name);
  wallet_getAccountAddress::init_jni_vars(env, package_name);
  wallet_getAccountState::init_jni_vars(env, package_name);
  wallet_init::init_jni_vars(env, package_name);
  wallet_sendGrams::init_jni_vars(env, package_name);
  wallet_v3_getAccountAddress::init_jni_vars(env, package_name);
}

jclass accountAddress::Class;
jfieldID accountAddress::account_address_fieldID;

accountAddress::accountAddress()
  : account_address_()
{}

accountAddress::accountAddress(std::string const &account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t accountAddress::ID;

object_ptr<accountAddress> accountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<accountAddress> res = make_object<accountAddress>();
  res->account_address_ = td::jni::fetch_string(env, p, res->account_address_fieldID);
  return res;
}

void accountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, account_address_); if (nextString) { env->SetObjectField(s, account_address_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void accountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "AccountAddress");
    s.store_field("accountAddress", account_address_);
    s.store_class_end();
  }
}

void accountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$AccountAddress").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", "Ljava/lang/String;");
}

jclass bip39Hints::Class;
jfieldID bip39Hints::words_fieldID;

bip39Hints::bip39Hints()
  : words_()
{}

bip39Hints::bip39Hints(std::vector<std::string> &&words_)
  : words_(std::move(words_))
{}

const std::int32_t bip39Hints::ID;

object_ptr<bip39Hints> bip39Hints::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<bip39Hints> res = make_object<bip39Hints>();
  res->words_ = td::jni::FetchVector<std::string>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->words_fieldID));;
  return res;
}

void bip39Hints::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, words_); if (arr_tmp_) { env->SetObjectField(s, words_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void bip39Hints::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Bip39Hints");
    { const std::vector<std::string> &v = words_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("words", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { s.store_field("", v[i]); } s.store_class_end(); }
    s.store_class_end();
  }
}

void bip39Hints::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Bip39Hints").c_str());
  words_fieldID = td::jni::get_field_id(env, Class, "words", "[Ljava/lang/String;");
}

jclass config::Class;
jfieldID config::config_fieldID;
jfieldID config::blockchain_name_fieldID;
jfieldID config::use_callbacks_for_network_fieldID;
jfieldID config::ignore_cache_fieldID;

config::config()
  : config_()
  , blockchain_name_()
  , use_callbacks_for_network_()
  , ignore_cache_()
{}

config::config(std::string const &config_, std::string const &blockchain_name_, bool use_callbacks_for_network_, bool ignore_cache_)
  : config_(std::move(config_))
  , blockchain_name_(std::move(blockchain_name_))
  , use_callbacks_for_network_(use_callbacks_for_network_)
  , ignore_cache_(ignore_cache_)
{}

const std::int32_t config::ID;

object_ptr<config> config::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<config> res = make_object<config>();
  res->config_ = td::jni::fetch_string(env, p, res->config_fieldID);
  res->blockchain_name_ = td::jni::fetch_string(env, p, res->blockchain_name_fieldID);
  res->use_callbacks_for_network_ = (env->GetBooleanField(p, res->use_callbacks_for_network_fieldID) != 0);
  res->ignore_cache_ = (env->GetBooleanField(p, res->ignore_cache_fieldID) != 0);
  return res;
}

void config::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, config_); if (nextString) { env->SetObjectField(s, config_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  { jstring nextString = td::jni::to_jstring(env, blockchain_name_); if (nextString) { env->SetObjectField(s, blockchain_name_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetBooleanField(s, use_callbacks_for_network_fieldID, use_callbacks_for_network_);
  env->SetBooleanField(s, ignore_cache_fieldID, ignore_cache_);
}

void config::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Config");
    s.store_field("config", config_);
    s.store_field("blockchainName", blockchain_name_);
    s.store_field("useCallbacksForNetwork", use_callbacks_for_network_);
    s.store_field("ignoreCache", ignore_cache_);
    s.store_class_end();
  }
}

void config::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Config").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", "Ljava/lang/String;");
  blockchain_name_fieldID = td::jni::get_field_id(env, Class, "blockchainName", "Ljava/lang/String;");
  use_callbacks_for_network_fieldID = td::jni::get_field_id(env, Class, "useCallbacksForNetwork", "Z");
  ignore_cache_fieldID = td::jni::get_field_id(env, Class, "ignoreCache", "Z");
}

jclass data::Class;
jfieldID data::bytes_fieldID;

data::data()
  : bytes_()
{}

data::data(td::SecureString &&bytes_)
  : bytes_(std::move(bytes_))
{}

const std::int32_t data::ID;

object_ptr<data> data::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<data> res = make_object<data>();
  res->bytes_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->bytes_fieldID));
  return res;
}

void data::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, bytes_); if (nextBytes) { env->SetObjectField(s, bytes_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void data::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Data");
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

void data::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Data").c_str());
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "[B");
}

jclass error::Class;
jfieldID error::code_fieldID;
jfieldID error::message_fieldID;

error::error()
  : code_()
  , message_()
{}

error::error(std::int32_t code_, std::string const &message_)
  : code_(code_)
  , message_(std::move(message_))
{}

const std::int32_t error::ID;

object_ptr<error> error::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<error> res = make_object<error>();
  res->code_ = env->GetIntField(p, res->code_fieldID);
  res->message_ = td::jni::fetch_string(env, p, res->message_fieldID);
  return res;
}

void error::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, code_fieldID, code_);
  { jstring nextString = td::jni::to_jstring(env, message_); if (nextString) { env->SetObjectField(s, message_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void error::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Error");
    s.store_field("code", code_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

void error::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Error").c_str());
  code_fieldID = td::jni::get_field_id(env, Class, "code", "I");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "Ljava/lang/String;");
}

jclass exportedEncryptedKey::Class;
jfieldID exportedEncryptedKey::data_fieldID;

exportedEncryptedKey::exportedEncryptedKey()
  : data_()
{}

exportedEncryptedKey::exportedEncryptedKey(td::SecureString &&data_)
  : data_(std::move(data_))
{}

const std::int32_t exportedEncryptedKey::ID;

object_ptr<exportedEncryptedKey> exportedEncryptedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportedEncryptedKey> res = make_object<exportedEncryptedKey>();
  res->data_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return res;
}

void exportedEncryptedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void exportedEncryptedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportedEncryptedKey");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

void exportedEncryptedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportedEncryptedKey").c_str());
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
}

jclass exportedKey::Class;
jfieldID exportedKey::word_list_fieldID;

exportedKey::exportedKey()
  : word_list_()
{}

exportedKey::exportedKey(std::vector<td::SecureString> &&word_list_)
  : word_list_(std::move(word_list_))
{}

const std::int32_t exportedKey::ID;

object_ptr<exportedKey> exportedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportedKey> res = make_object<exportedKey>();
  res->word_list_ = td::jni::FetchVector<td::SecureString>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->word_list_fieldID));;
  return res;
}

void exportedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, word_list_); if (arr_tmp_) { env->SetObjectField(s, word_list_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void exportedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportedKey");
    { const std::vector<td::SecureString> &v = word_list_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("wordList", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { s.store_field("", v[i]); } s.store_class_end(); }
    s.store_class_end();
  }
}

void exportedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportedKey").c_str());
  word_list_fieldID = td::jni::get_field_id(env, Class, "wordList", "[Ljava/lang/String;");
}

jclass exportedPemKey::Class;
jfieldID exportedPemKey::pem_fieldID;

exportedPemKey::exportedPemKey()
  : pem_()
{}

exportedPemKey::exportedPemKey(td::SecureString &&pem_)
  : pem_(std::move(pem_))
{}

const std::int32_t exportedPemKey::ID;

object_ptr<exportedPemKey> exportedPemKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportedPemKey> res = make_object<exportedPemKey>();
  res->pem_ = td::jni::fetch_string_secure(env, p, res->pem_fieldID);
  return res;
}

void exportedPemKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring_secure(env, pem_); if (nextString) { env->SetObjectField(s, pem_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void exportedPemKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportedPemKey");
    s.store_field("pem", pem_);
    s.store_class_end();
  }
}

void exportedPemKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportedPemKey").c_str());
  pem_fieldID = td::jni::get_field_id(env, Class, "pem", "Ljava/lang/String;");
}

jclass fees::Class;
jfieldID fees::in_fwd_fee_fieldID;
jfieldID fees::storage_fee_fieldID;
jfieldID fees::gas_fee_fieldID;
jfieldID fees::fwd_fee_fieldID;

fees::fees()
  : in_fwd_fee_()
  , storage_fee_()
  , gas_fee_()
  , fwd_fee_()
{}

fees::fees(std::int64_t in_fwd_fee_, std::int64_t storage_fee_, std::int64_t gas_fee_, std::int64_t fwd_fee_)
  : in_fwd_fee_(in_fwd_fee_)
  , storage_fee_(storage_fee_)
  , gas_fee_(gas_fee_)
  , fwd_fee_(fwd_fee_)
{}

const std::int32_t fees::ID;

object_ptr<fees> fees::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<fees> res = make_object<fees>();
  res->in_fwd_fee_ = env->GetLongField(p, res->in_fwd_fee_fieldID);
  res->storage_fee_ = env->GetLongField(p, res->storage_fee_fieldID);
  res->gas_fee_ = env->GetLongField(p, res->gas_fee_fieldID);
  res->fwd_fee_ = env->GetLongField(p, res->fwd_fee_fieldID);
  return res;
}

void fees::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, in_fwd_fee_fieldID, in_fwd_fee_);
  env->SetLongField(s, storage_fee_fieldID, storage_fee_);
  env->SetLongField(s, gas_fee_fieldID, gas_fee_);
  env->SetLongField(s, fwd_fee_fieldID, fwd_fee_);
}

void fees::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Fees");
    s.store_field("inFwdFee", in_fwd_fee_);
    s.store_field("storageFee", storage_fee_);
    s.store_field("gasFee", gas_fee_);
    s.store_field("fwdFee", fwd_fee_);
    s.store_class_end();
  }
}

void fees::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Fees").c_str());
  in_fwd_fee_fieldID = td::jni::get_field_id(env, Class, "inFwdFee", "J");
  storage_fee_fieldID = td::jni::get_field_id(env, Class, "storageFee", "J");
  gas_fee_fieldID = td::jni::get_field_id(env, Class, "gasFee", "J");
  fwd_fee_fieldID = td::jni::get_field_id(env, Class, "fwdFee", "J");
}

jclass InputKey::Class;

object_ptr<InputKey> InputKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case inputKeyRegular::ID:
      return inputKeyRegular::fetch(env, p);
    case inputKeyFake::ID:
      return inputKeyFake::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void InputKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$InputKey").c_str());
  inputKeyRegular::init_jni_vars(env, package_name);
  inputKeyFake::init_jni_vars(env, package_name);
}

jclass inputKeyRegular::Class;
jfieldID inputKeyRegular::key_fieldID;
jfieldID inputKeyRegular::local_password_fieldID;

inputKeyRegular::inputKeyRegular()
  : key_()
  , local_password_()
{}

inputKeyRegular::inputKeyRegular(object_ptr<key> &&key_, td::SecureString &&local_password_)
  : key_(std::move(key_))
  , local_password_(std::move(local_password_))
{}

const std::int32_t inputKeyRegular::ID;

object_ptr<InputKey> inputKeyRegular::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<inputKeyRegular> res = make_object<inputKeyRegular>();
  res->key_ = td::jni::fetch_tl_object<key>(env, td::jni::fetch_object(env, p, res->key_fieldID));;
  res->local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->local_password_fieldID));
  return std::move(res);
}

void inputKeyRegular::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (key_ != nullptr) { jobject next; key_->store(env, next); if (next) { env->SetObjectField(s, key_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, local_password_); if (nextBytes) { env->SetObjectField(s, local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void inputKeyRegular::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "InputKeyRegular");
    if (key_ == nullptr) { s.store_field("key", "null"); } else { key_->store(s, "key"); }
    s.store_bytes_field("localPassword", local_password_);
    s.store_class_end();
  }
}

void inputKeyRegular::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$InputKeyRegular").c_str());
  key_fieldID = td::jni::get_field_id(env, Class, "key", (PSLICE() << "L" << package_name << "/TonApi$Key;").c_str());
  local_password_fieldID = td::jni::get_field_id(env, Class, "localPassword", "[B");
}

jclass inputKeyFake::Class;

inputKeyFake::inputKeyFake() {
}

const std::int32_t inputKeyFake::ID;

object_ptr<InputKey> inputKeyFake::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<inputKeyFake> res = make_object<inputKeyFake>();
  return std::move(res);
}

void inputKeyFake::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void inputKeyFake::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "InputKeyFake");
    s.store_class_end();
  }
}

void inputKeyFake::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$InputKeyFake").c_str());
}

jclass key::Class;
jfieldID key::public_key_fieldID;
jfieldID key::secret_fieldID;

key::key()
  : public_key_()
  , secret_()
{}

key::key(std::string const &public_key_, td::SecureString &&secret_)
  : public_key_(std::move(public_key_))
  , secret_(std::move(secret_))
{}

const std::int32_t key::ID;

object_ptr<key> key::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<key> res = make_object<key>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->secret_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->secret_fieldID));
  return res;
}

void key::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, secret_); if (nextBytes) { env->SetObjectField(s, secret_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void key::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Key");
    s.store_field("publicKey", public_key_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

void key::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Key").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  secret_fieldID = td::jni::get_field_id(env, Class, "secret", "[B");
}

jclass KeyStoreType::Class;

object_ptr<KeyStoreType> KeyStoreType::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case keyStoreTypeDirectory::ID:
      return keyStoreTypeDirectory::fetch(env, p);
    case keyStoreTypeInMemory::ID:
      return keyStoreTypeInMemory::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void KeyStoreType::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$KeyStoreType").c_str());
  keyStoreTypeDirectory::init_jni_vars(env, package_name);
  keyStoreTypeInMemory::init_jni_vars(env, package_name);
}

jclass keyStoreTypeDirectory::Class;
jfieldID keyStoreTypeDirectory::directory_fieldID;

keyStoreTypeDirectory::keyStoreTypeDirectory()
  : directory_()
{}

keyStoreTypeDirectory::keyStoreTypeDirectory(std::string const &directory_)
  : directory_(std::move(directory_))
{}

const std::int32_t keyStoreTypeDirectory::ID;

object_ptr<KeyStoreType> keyStoreTypeDirectory::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<keyStoreTypeDirectory> res = make_object<keyStoreTypeDirectory>();
  res->directory_ = td::jni::fetch_string(env, p, res->directory_fieldID);
  return std::move(res);
}

void keyStoreTypeDirectory::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, directory_); if (nextString) { env->SetObjectField(s, directory_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void keyStoreTypeDirectory::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "KeyStoreTypeDirectory");
    s.store_field("directory", directory_);
    s.store_class_end();
  }
}

void keyStoreTypeDirectory::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$KeyStoreTypeDirectory").c_str());
  directory_fieldID = td::jni::get_field_id(env, Class, "directory", "Ljava/lang/String;");
}

jclass keyStoreTypeInMemory::Class;

keyStoreTypeInMemory::keyStoreTypeInMemory() {
}

const std::int32_t keyStoreTypeInMemory::ID;

object_ptr<KeyStoreType> keyStoreTypeInMemory::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<keyStoreTypeInMemory> res = make_object<keyStoreTypeInMemory>();
  return std::move(res);
}

void keyStoreTypeInMemory::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void keyStoreTypeInMemory::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "KeyStoreTypeInMemory");
    s.store_class_end();
  }
}

void keyStoreTypeInMemory::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$KeyStoreTypeInMemory").c_str());
}

jclass LogStream::Class;

object_ptr<LogStream> LogStream::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case logStreamDefault::ID:
      return logStreamDefault::fetch(env, p);
    case logStreamFile::ID:
      return logStreamFile::fetch(env, p);
    case logStreamEmpty::ID:
      return logStreamEmpty::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void LogStream::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LogStream").c_str());
  logStreamDefault::init_jni_vars(env, package_name);
  logStreamFile::init_jni_vars(env, package_name);
  logStreamEmpty::init_jni_vars(env, package_name);
}

jclass logStreamDefault::Class;

logStreamDefault::logStreamDefault() {
}

const std::int32_t logStreamDefault::ID;

object_ptr<LogStream> logStreamDefault::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<logStreamDefault> res = make_object<logStreamDefault>();
  return std::move(res);
}

void logStreamDefault::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void logStreamDefault::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LogStreamDefault");
    s.store_class_end();
  }
}

void logStreamDefault::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LogStreamDefault").c_str());
}

jclass logStreamFile::Class;
jfieldID logStreamFile::path_fieldID;
jfieldID logStreamFile::max_file_size_fieldID;

logStreamFile::logStreamFile()
  : path_()
  , max_file_size_()
{}

logStreamFile::logStreamFile(std::string const &path_, std::int64_t max_file_size_)
  : path_(std::move(path_))
  , max_file_size_(max_file_size_)
{}

const std::int32_t logStreamFile::ID;

object_ptr<LogStream> logStreamFile::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<logStreamFile> res = make_object<logStreamFile>();
  res->path_ = td::jni::fetch_string(env, p, res->path_fieldID);
  res->max_file_size_ = env->GetLongField(p, res->max_file_size_fieldID);
  return std::move(res);
}

void logStreamFile::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, path_); if (nextString) { env->SetObjectField(s, path_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, max_file_size_fieldID, max_file_size_);
}

void logStreamFile::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LogStreamFile");
    s.store_field("path", path_);
    s.store_field("maxFileSize", max_file_size_);
    s.store_class_end();
  }
}

void logStreamFile::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LogStreamFile").c_str());
  path_fieldID = td::jni::get_field_id(env, Class, "path", "Ljava/lang/String;");
  max_file_size_fieldID = td::jni::get_field_id(env, Class, "maxFileSize", "J");
}

jclass logStreamEmpty::Class;

logStreamEmpty::logStreamEmpty() {
}

const std::int32_t logStreamEmpty::ID;

object_ptr<LogStream> logStreamEmpty::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<logStreamEmpty> res = make_object<logStreamEmpty>();
  return std::move(res);
}

void logStreamEmpty::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void logStreamEmpty::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LogStreamEmpty");
    s.store_class_end();
  }
}

void logStreamEmpty::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LogStreamEmpty").c_str());
}

jclass logTags::Class;
jfieldID logTags::tags_fieldID;

logTags::logTags()
  : tags_()
{}

logTags::logTags(std::vector<std::string> &&tags_)
  : tags_(std::move(tags_))
{}

const std::int32_t logTags::ID;

object_ptr<logTags> logTags::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<logTags> res = make_object<logTags>();
  res->tags_ = td::jni::FetchVector<std::string>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->tags_fieldID));;
  return res;
}

void logTags::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, tags_); if (arr_tmp_) { env->SetObjectField(s, tags_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void logTags::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LogTags");
    { const std::vector<std::string> &v = tags_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("tags", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { s.store_field("", v[i]); } s.store_class_end(); }
    s.store_class_end();
  }
}

void logTags::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LogTags").c_str());
  tags_fieldID = td::jni::get_field_id(env, Class, "tags", "[Ljava/lang/String;");
}

jclass logVerbosityLevel::Class;
jfieldID logVerbosityLevel::verbosity_level_fieldID;

logVerbosityLevel::logVerbosityLevel()
  : verbosity_level_()
{}

logVerbosityLevel::logVerbosityLevel(std::int32_t verbosity_level_)
  : verbosity_level_(verbosity_level_)
{}

const std::int32_t logVerbosityLevel::ID;

object_ptr<logVerbosityLevel> logVerbosityLevel::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<logVerbosityLevel> res = make_object<logVerbosityLevel>();
  res->verbosity_level_ = env->GetIntField(p, res->verbosity_level_fieldID);
  return res;
}

void logVerbosityLevel::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, verbosity_level_fieldID, verbosity_level_);
}

void logVerbosityLevel::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LogVerbosityLevel");
    s.store_field("verbosityLevel", verbosity_level_);
    s.store_class_end();
  }
}

void logVerbosityLevel::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LogVerbosityLevel").c_str());
  verbosity_level_fieldID = td::jni::get_field_id(env, Class, "verbosityLevel", "I");
}

jclass ok::Class;

ok::ok() {
}

const std::int32_t ok::ID;

object_ptr<ok> ok::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<ok> res = make_object<ok>();
  return res;
}

void ok::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void ok::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Ok");
    s.store_class_end();
  }
}

void ok::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Ok").c_str());
}

jclass options::Class;
jfieldID options::config_fieldID;
jfieldID options::keystore_type_fieldID;

options::options()
  : config_()
  , keystore_type_()
{}

options::options(object_ptr<config> &&config_, object_ptr<KeyStoreType> &&keystore_type_)
  : config_(std::move(config_))
  , keystore_type_(std::move(keystore_type_))
{}

const std::int32_t options::ID;

object_ptr<options> options::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<options> res = make_object<options>();
  res->config_ = td::jni::fetch_tl_object<config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  res->keystore_type_ = td::jni::fetch_tl_object<KeyStoreType>(env, td::jni::fetch_object(env, p, res->keystore_type_fieldID));;
  return res;
}

void options::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
  if (keystore_type_ != nullptr) { jobject next; keystore_type_->store(env, next); if (next) { env->SetObjectField(s, keystore_type_fieldID, next); env->DeleteLocalRef(next); } }
}

void options::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Options");
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    if (keystore_type_ == nullptr) { s.store_field("keystoreType", "null"); } else { keystore_type_->store(s, "keystoreType"); }
    s.store_class_end();
  }
}

void options::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Options").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$Config;").c_str());
  keystore_type_fieldID = td::jni::get_field_id(env, Class, "keystoreType", (PSLICE() << "L" << package_name << "/TonApi$KeyStoreType;").c_str());
}

jclass sendGramsResult::Class;
jfieldID sendGramsResult::sent_until_fieldID;
jfieldID sendGramsResult::body_hash_fieldID;

sendGramsResult::sendGramsResult()
  : sent_until_()
  , body_hash_()
{}

sendGramsResult::sendGramsResult(std::int64_t sent_until_, std::string const &body_hash_)
  : sent_until_(sent_until_)
  , body_hash_(std::move(body_hash_))
{}

const std::int32_t sendGramsResult::ID;

object_ptr<sendGramsResult> sendGramsResult::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<sendGramsResult> res = make_object<sendGramsResult>();
  res->sent_until_ = env->GetLongField(p, res->sent_until_fieldID);
  res->body_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_hash_fieldID));
  return res;
}

void sendGramsResult::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, sent_until_fieldID, sent_until_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_hash_); if (nextBytes) { env->SetObjectField(s, body_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void sendGramsResult::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SendGramsResult");
    s.store_field("sentUntil", sent_until_);
    s.store_bytes_field("bodyHash", body_hash_);
    s.store_class_end();
  }
}

void sendGramsResult::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SendGramsResult").c_str());
  sent_until_fieldID = td::jni::get_field_id(env, Class, "sentUntil", "J");
  body_hash_fieldID = td::jni::get_field_id(env, Class, "bodyHash", "[B");
}

jclass SyncState::Class;

object_ptr<SyncState> SyncState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case syncStateDone::ID:
      return syncStateDone::fetch(env, p);
    case syncStateInProgress::ID:
      return syncStateInProgress::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void SyncState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SyncState").c_str());
  syncStateDone::init_jni_vars(env, package_name);
  syncStateInProgress::init_jni_vars(env, package_name);
}

jclass syncStateDone::Class;

syncStateDone::syncStateDone() {
}

const std::int32_t syncStateDone::ID;

object_ptr<SyncState> syncStateDone::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<syncStateDone> res = make_object<syncStateDone>();
  return std::move(res);
}

void syncStateDone::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void syncStateDone::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SyncStateDone");
    s.store_class_end();
  }
}

void syncStateDone::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SyncStateDone").c_str());
}

jclass syncStateInProgress::Class;
jfieldID syncStateInProgress::from_seqno_fieldID;
jfieldID syncStateInProgress::to_seqno_fieldID;
jfieldID syncStateInProgress::current_seqno_fieldID;

syncStateInProgress::syncStateInProgress()
  : from_seqno_()
  , to_seqno_()
  , current_seqno_()
{}

syncStateInProgress::syncStateInProgress(std::int32_t from_seqno_, std::int32_t to_seqno_, std::int32_t current_seqno_)
  : from_seqno_(from_seqno_)
  , to_seqno_(to_seqno_)
  , current_seqno_(current_seqno_)
{}

const std::int32_t syncStateInProgress::ID;

object_ptr<SyncState> syncStateInProgress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<syncStateInProgress> res = make_object<syncStateInProgress>();
  res->from_seqno_ = env->GetIntField(p, res->from_seqno_fieldID);
  res->to_seqno_ = env->GetIntField(p, res->to_seqno_fieldID);
  res->current_seqno_ = env->GetIntField(p, res->current_seqno_fieldID);
  return std::move(res);
}

void syncStateInProgress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, from_seqno_fieldID, from_seqno_);
  env->SetIntField(s, to_seqno_fieldID, to_seqno_);
  env->SetIntField(s, current_seqno_fieldID, current_seqno_);
}

void syncStateInProgress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SyncStateInProgress");
    s.store_field("fromSeqno", from_seqno_);
    s.store_field("toSeqno", to_seqno_);
    s.store_field("currentSeqno", current_seqno_);
    s.store_class_end();
  }
}

void syncStateInProgress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SyncStateInProgress").c_str());
  from_seqno_fieldID = td::jni::get_field_id(env, Class, "fromSeqno", "I");
  to_seqno_fieldID = td::jni::get_field_id(env, Class, "toSeqno", "I");
  current_seqno_fieldID = td::jni::get_field_id(env, Class, "currentSeqno", "I");
}

jclass unpackedAccountAddress::Class;
jfieldID unpackedAccountAddress::workchain_id_fieldID;
jfieldID unpackedAccountAddress::bounceable_fieldID;
jfieldID unpackedAccountAddress::testnet_fieldID;
jfieldID unpackedAccountAddress::addr_fieldID;

unpackedAccountAddress::unpackedAccountAddress()
  : workchain_id_()
  , bounceable_()
  , testnet_()
  , addr_()
{}

unpackedAccountAddress::unpackedAccountAddress(std::int32_t workchain_id_, bool bounceable_, bool testnet_, std::string const &addr_)
  : workchain_id_(workchain_id_)
  , bounceable_(bounceable_)
  , testnet_(testnet_)
  , addr_(std::move(addr_))
{}

const std::int32_t unpackedAccountAddress::ID;

object_ptr<unpackedAccountAddress> unpackedAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<unpackedAccountAddress> res = make_object<unpackedAccountAddress>();
  res->workchain_id_ = env->GetIntField(p, res->workchain_id_fieldID);
  res->bounceable_ = (env->GetBooleanField(p, res->bounceable_fieldID) != 0);
  res->testnet_ = (env->GetBooleanField(p, res->testnet_fieldID) != 0);
  res->addr_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->addr_fieldID));
  return res;
}

void unpackedAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, workchain_id_fieldID, workchain_id_);
  env->SetBooleanField(s, bounceable_fieldID, bounceable_);
  env->SetBooleanField(s, testnet_fieldID, testnet_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, addr_); if (nextBytes) { env->SetObjectField(s, addr_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void unpackedAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "UnpackedAccountAddress");
    s.store_field("workchainId", workchain_id_);
    s.store_field("bounceable", bounceable_);
    s.store_field("testnet", testnet_);
    s.store_bytes_field("addr", addr_);
    s.store_class_end();
  }
}

void unpackedAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$UnpackedAccountAddress").c_str());
  workchain_id_fieldID = td::jni::get_field_id(env, Class, "workchainId", "I");
  bounceable_fieldID = td::jni::get_field_id(env, Class, "bounceable", "Z");
  testnet_fieldID = td::jni::get_field_id(env, Class, "testnet", "Z");
  addr_fieldID = td::jni::get_field_id(env, Class, "addr", "[B");
}

jclass Update::Class;

object_ptr<Update> Update::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case updateSendLiteServerQuery::ID:
      return updateSendLiteServerQuery::fetch(env, p);
    case updateSyncState::ID:
      return updateSyncState::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void Update::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Update").c_str());
  updateSendLiteServerQuery::init_jni_vars(env, package_name);
  updateSyncState::init_jni_vars(env, package_name);
}

jclass updateSendLiteServerQuery::Class;
jfieldID updateSendLiteServerQuery::id_fieldID;
jfieldID updateSendLiteServerQuery::data_fieldID;

updateSendLiteServerQuery::updateSendLiteServerQuery()
  : id_()
  , data_()
{}

updateSendLiteServerQuery::updateSendLiteServerQuery(std::int64_t id_, std::string const &data_)
  : id_(id_)
  , data_(std::move(data_))
{}

const std::int32_t updateSendLiteServerQuery::ID;

object_ptr<Update> updateSendLiteServerQuery::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<updateSendLiteServerQuery> res = make_object<updateSendLiteServerQuery>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return std::move(res);
}

void updateSendLiteServerQuery::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void updateSendLiteServerQuery::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "UpdateSendLiteServerQuery");
    s.store_field("id", id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

void updateSendLiteServerQuery::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$UpdateSendLiteServerQuery").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
}

jclass updateSyncState::Class;
jfieldID updateSyncState::sync_state_fieldID;

updateSyncState::updateSyncState()
  : sync_state_()
{}

updateSyncState::updateSyncState(object_ptr<SyncState> &&sync_state_)
  : sync_state_(std::move(sync_state_))
{}

const std::int32_t updateSyncState::ID;

object_ptr<Update> updateSyncState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<updateSyncState> res = make_object<updateSyncState>();
  res->sync_state_ = td::jni::fetch_tl_object<SyncState>(env, td::jni::fetch_object(env, p, res->sync_state_fieldID));;
  return std::move(res);
}

void updateSyncState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (sync_state_ != nullptr) { jobject next; sync_state_->store(env, next); if (next) { env->SetObjectField(s, sync_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void updateSyncState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "UpdateSyncState");
    if (sync_state_ == nullptr) { s.store_field("syncState", "null"); } else { sync_state_->store(s, "syncState"); }
    s.store_class_end();
  }
}

void updateSyncState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$UpdateSyncState").c_str());
  sync_state_fieldID = td::jni::get_field_id(env, Class, "syncState", (PSLICE() << "L" << package_name << "/TonApi$SyncState;").c_str());
}

jclass generic_AccountState::Class;

object_ptr<generic_AccountState> generic_AccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case generic_accountStateRaw::ID:
      return generic_accountStateRaw::fetch(env, p);
    case generic_accountStateTestWallet::ID:
      return generic_accountStateTestWallet::fetch(env, p);
    case generic_accountStateWallet::ID:
      return generic_accountStateWallet::fetch(env, p);
    case generic_accountStateWalletV3::ID:
      return generic_accountStateWalletV3::fetch(env, p);
    case generic_accountStateTestGiver::ID:
      return generic_accountStateTestGiver::fetch(env, p);
    case generic_accountStateUninited::ID:
      return generic_accountStateUninited::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void generic_AccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountState").c_str());
  generic_accountStateRaw::init_jni_vars(env, package_name);
  generic_accountStateTestWallet::init_jni_vars(env, package_name);
  generic_accountStateWallet::init_jni_vars(env, package_name);
  generic_accountStateWalletV3::init_jni_vars(env, package_name);
  generic_accountStateTestGiver::init_jni_vars(env, package_name);
  generic_accountStateUninited::init_jni_vars(env, package_name);
}

jclass generic_accountStateRaw::Class;
jfieldID generic_accountStateRaw::account_state_fieldID;

generic_accountStateRaw::generic_accountStateRaw()
  : account_state_()
{}

generic_accountStateRaw::generic_accountStateRaw(object_ptr<raw_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateRaw::ID;

object_ptr<generic_AccountState> generic_accountStateRaw::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_accountStateRaw> res = make_object<generic_accountStateRaw>();
  res->account_state_ = td::jni::fetch_tl_object<raw_accountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  return std::move(res);
}

void generic_accountStateRaw::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_accountStateRaw::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericAccountStateRaw");
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_class_end();
  }
}

void generic_accountStateRaw::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountStateRaw").c_str());
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$RawAccountState;").c_str());
}

jclass generic_accountStateTestWallet::Class;
jfieldID generic_accountStateTestWallet::account_state_fieldID;

generic_accountStateTestWallet::generic_accountStateTestWallet()
  : account_state_()
{}

generic_accountStateTestWallet::generic_accountStateTestWallet(object_ptr<testWallet_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateTestWallet::ID;

object_ptr<generic_AccountState> generic_accountStateTestWallet::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_accountStateTestWallet> res = make_object<generic_accountStateTestWallet>();
  res->account_state_ = td::jni::fetch_tl_object<testWallet_accountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  return std::move(res);
}

void generic_accountStateTestWallet::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_accountStateTestWallet::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericAccountStateTestWallet");
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_class_end();
  }
}

void generic_accountStateTestWallet::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountStateTestWallet").c_str());
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$TestWalletAccountState;").c_str());
}

jclass generic_accountStateWallet::Class;
jfieldID generic_accountStateWallet::account_state_fieldID;

generic_accountStateWallet::generic_accountStateWallet()
  : account_state_()
{}

generic_accountStateWallet::generic_accountStateWallet(object_ptr<wallet_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateWallet::ID;

object_ptr<generic_AccountState> generic_accountStateWallet::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_accountStateWallet> res = make_object<generic_accountStateWallet>();
  res->account_state_ = td::jni::fetch_tl_object<wallet_accountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  return std::move(res);
}

void generic_accountStateWallet::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_accountStateWallet::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericAccountStateWallet");
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_class_end();
  }
}

void generic_accountStateWallet::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountStateWallet").c_str());
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$WalletAccountState;").c_str());
}

jclass generic_accountStateWalletV3::Class;
jfieldID generic_accountStateWalletV3::account_state_fieldID;

generic_accountStateWalletV3::generic_accountStateWalletV3()
  : account_state_()
{}

generic_accountStateWalletV3::generic_accountStateWalletV3(object_ptr<wallet_v3_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateWalletV3::ID;

object_ptr<generic_AccountState> generic_accountStateWalletV3::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_accountStateWalletV3> res = make_object<generic_accountStateWalletV3>();
  res->account_state_ = td::jni::fetch_tl_object<wallet_v3_accountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  return std::move(res);
}

void generic_accountStateWalletV3::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_accountStateWalletV3::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericAccountStateWalletV3");
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_class_end();
  }
}

void generic_accountStateWalletV3::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountStateWalletV3").c_str());
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$WalletV3AccountState;").c_str());
}

jclass generic_accountStateTestGiver::Class;
jfieldID generic_accountStateTestGiver::account_state_fieldID;

generic_accountStateTestGiver::generic_accountStateTestGiver()
  : account_state_()
{}

generic_accountStateTestGiver::generic_accountStateTestGiver(object_ptr<testGiver_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateTestGiver::ID;

object_ptr<generic_AccountState> generic_accountStateTestGiver::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_accountStateTestGiver> res = make_object<generic_accountStateTestGiver>();
  res->account_state_ = td::jni::fetch_tl_object<testGiver_accountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  return std::move(res);
}

void generic_accountStateTestGiver::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_accountStateTestGiver::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericAccountStateTestGiver");
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_class_end();
  }
}

void generic_accountStateTestGiver::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountStateTestGiver").c_str());
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$TestGiverAccountState;").c_str());
}

jclass generic_accountStateUninited::Class;
jfieldID generic_accountStateUninited::account_state_fieldID;

generic_accountStateUninited::generic_accountStateUninited()
  : account_state_()
{}

generic_accountStateUninited::generic_accountStateUninited(object_ptr<uninited_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateUninited::ID;

object_ptr<generic_AccountState> generic_accountStateUninited::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_accountStateUninited> res = make_object<generic_accountStateUninited>();
  res->account_state_ = td::jni::fetch_tl_object<uninited_accountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  return std::move(res);
}

void generic_accountStateUninited::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_accountStateUninited::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericAccountStateUninited");
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_class_end();
  }
}

void generic_accountStateUninited::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericAccountStateUninited").c_str());
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$UninitedAccountState;").c_str());
}

jclass internal_transactionId::Class;
jfieldID internal_transactionId::lt_fieldID;
jfieldID internal_transactionId::hash_fieldID;

internal_transactionId::internal_transactionId()
  : lt_()
  , hash_()
{}

internal_transactionId::internal_transactionId(std::int64_t lt_, std::string const &hash_)
  : lt_(lt_)
  , hash_(std::move(hash_))
{}

const std::int32_t internal_transactionId::ID;

object_ptr<internal_transactionId> internal_transactionId::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<internal_transactionId> res = make_object<internal_transactionId>();
  res->lt_ = env->GetLongField(p, res->lt_fieldID);
  res->hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->hash_fieldID));
  return res;
}

void internal_transactionId::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, lt_fieldID, lt_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, hash_); if (nextBytes) { env->SetObjectField(s, hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void internal_transactionId::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "InternalTransactionId");
    s.store_field("lt", lt_);
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

void internal_transactionId::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$InternalTransactionId").c_str());
  lt_fieldID = td::jni::get_field_id(env, Class, "lt", "J");
  hash_fieldID = td::jni::get_field_id(env, Class, "hash", "[B");
}

jclass liteServer_info::Class;
jfieldID liteServer_info::now_fieldID;
jfieldID liteServer_info::version_fieldID;
jfieldID liteServer_info::capabilities_fieldID;

liteServer_info::liteServer_info()
  : now_()
  , version_()
  , capabilities_()
{}

liteServer_info::liteServer_info(std::int64_t now_, std::int32_t version_, std::int64_t capabilities_)
  : now_(now_)
  , version_(version_)
  , capabilities_(capabilities_)
{}

const std::int32_t liteServer_info::ID;

object_ptr<liteServer_info> liteServer_info::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<liteServer_info> res = make_object<liteServer_info>();
  res->now_ = env->GetLongField(p, res->now_fieldID);
  res->version_ = env->GetIntField(p, res->version_fieldID);
  res->capabilities_ = env->GetLongField(p, res->capabilities_fieldID);
  return res;
}

void liteServer_info::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, now_fieldID, now_);
  env->SetIntField(s, version_fieldID, version_);
  env->SetLongField(s, capabilities_fieldID, capabilities_);
}

void liteServer_info::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LiteServerInfo");
    s.store_field("now", now_);
    s.store_field("version", version_);
    s.store_field("capabilities", capabilities_);
    s.store_class_end();
  }
}

void liteServer_info::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LiteServerInfo").c_str());
  now_fieldID = td::jni::get_field_id(env, Class, "now", "J");
  version_fieldID = td::jni::get_field_id(env, Class, "version", "I");
  capabilities_fieldID = td::jni::get_field_id(env, Class, "capabilities", "J");
}

jclass options_configInfo::Class;
jfieldID options_configInfo::default_wallet_id_fieldID;

options_configInfo::options_configInfo()
  : default_wallet_id_()
{}

options_configInfo::options_configInfo(std::int64_t default_wallet_id_)
  : default_wallet_id_(default_wallet_id_)
{}

const std::int32_t options_configInfo::ID;

object_ptr<options_configInfo> options_configInfo::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<options_configInfo> res = make_object<options_configInfo>();
  res->default_wallet_id_ = env->GetLongField(p, res->default_wallet_id_fieldID);
  return res;
}

void options_configInfo::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, default_wallet_id_fieldID, default_wallet_id_);
}

void options_configInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OptionsConfigInfo");
    s.store_field("defaultWalletId", default_wallet_id_);
    s.store_class_end();
  }
}

void options_configInfo::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OptionsConfigInfo").c_str());
  default_wallet_id_fieldID = td::jni::get_field_id(env, Class, "defaultWalletId", "J");
}

jclass query_fees::Class;
jfieldID query_fees::source_fees_fieldID;
jfieldID query_fees::destination_fees_fieldID;

query_fees::query_fees()
  : source_fees_()
  , destination_fees_()
{}

query_fees::query_fees(object_ptr<fees> &&source_fees_, object_ptr<fees> &&destination_fees_)
  : source_fees_(std::move(source_fees_))
  , destination_fees_(std::move(destination_fees_))
{}

const std::int32_t query_fees::ID;

object_ptr<query_fees> query_fees::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_fees> res = make_object<query_fees>();
  res->source_fees_ = td::jni::fetch_tl_object<fees>(env, td::jni::fetch_object(env, p, res->source_fees_fieldID));;
  res->destination_fees_ = td::jni::fetch_tl_object<fees>(env, td::jni::fetch_object(env, p, res->destination_fees_fieldID));;
  return res;
}

void query_fees::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (source_fees_ != nullptr) { jobject next; source_fees_->store(env, next); if (next) { env->SetObjectField(s, source_fees_fieldID, next); env->DeleteLocalRef(next); } }
  if (destination_fees_ != nullptr) { jobject next; destination_fees_->store(env, next); if (next) { env->SetObjectField(s, destination_fees_fieldID, next); env->DeleteLocalRef(next); } }
}

void query_fees::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryFees");
    if (source_fees_ == nullptr) { s.store_field("sourceFees", "null"); } else { source_fees_->store(s, "sourceFees"); }
    if (destination_fees_ == nullptr) { s.store_field("destinationFees", "null"); } else { destination_fees_->store(s, "destinationFees"); }
    s.store_class_end();
  }
}

void query_fees::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryFees").c_str());
  source_fees_fieldID = td::jni::get_field_id(env, Class, "sourceFees", (PSLICE() << "L" << package_name << "/TonApi$Fees;").c_str());
  destination_fees_fieldID = td::jni::get_field_id(env, Class, "destinationFees", (PSLICE() << "L" << package_name << "/TonApi$Fees;").c_str());
}

jclass query_info::Class;
jfieldID query_info::id_fieldID;
jfieldID query_info::valid_until_fieldID;
jfieldID query_info::body_hash_fieldID;

query_info::query_info()
  : id_()
  , valid_until_()
  , body_hash_()
{}

query_info::query_info(std::int64_t id_, std::int64_t valid_until_, std::string const &body_hash_)
  : id_(id_)
  , valid_until_(valid_until_)
  , body_hash_(std::move(body_hash_))
{}

const std::int32_t query_info::ID;

object_ptr<query_info> query_info::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_info> res = make_object<query_info>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->valid_until_ = env->GetLongField(p, res->valid_until_fieldID);
  res->body_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_hash_fieldID));
  return res;
}

void query_info::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  env->SetLongField(s, valid_until_fieldID, valid_until_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_hash_); if (nextBytes) { env->SetObjectField(s, body_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void query_info::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryInfo");
    s.store_field("id", id_);
    s.store_field("validUntil", valid_until_);
    s.store_bytes_field("bodyHash", body_hash_);
    s.store_class_end();
  }
}

void query_info::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryInfo").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  valid_until_fieldID = td::jni::get_field_id(env, Class, "validUntil", "J");
  body_hash_fieldID = td::jni::get_field_id(env, Class, "bodyHash", "[B");
}

jclass raw_accountState::Class;
jfieldID raw_accountState::balance_fieldID;
jfieldID raw_accountState::code_fieldID;
jfieldID raw_accountState::data_fieldID;
jfieldID raw_accountState::last_transaction_id_fieldID;
jfieldID raw_accountState::frozen_hash_fieldID;
jfieldID raw_accountState::sync_utime_fieldID;

raw_accountState::raw_accountState()
  : balance_()
  , code_()
  , data_()
  , last_transaction_id_()
  , frozen_hash_()
  , sync_utime_()
{}

raw_accountState::raw_accountState(std::int64_t balance_, std::string const &code_, std::string const &data_, object_ptr<internal_transactionId> &&last_transaction_id_, std::string const &frozen_hash_, std::int64_t sync_utime_)
  : balance_(balance_)
  , code_(std::move(code_))
  , data_(std::move(data_))
  , last_transaction_id_(std::move(last_transaction_id_))
  , frozen_hash_(std::move(frozen_hash_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t raw_accountState::ID;

object_ptr<raw_accountState> raw_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_accountState> res = make_object<raw_accountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->code_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->code_fieldID));
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->frozen_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->frozen_hash_fieldID));
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void raw_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, code_); if (nextBytes) { env->SetObjectField(s, code_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, frozen_hash_); if (nextBytes) { env->SetObjectField(s, frozen_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void raw_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawAccountState");
    s.store_field("balance", balance_);
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    s.store_bytes_field("frozenHash", frozen_hash_);
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void raw_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawAccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  code_fieldID = td::jni::get_field_id(env, Class, "code", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  frozen_hash_fieldID = td::jni::get_field_id(env, Class, "frozenHash", "[B");
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass raw_initialAccountState::Class;
jfieldID raw_initialAccountState::code_fieldID;
jfieldID raw_initialAccountState::data_fieldID;

raw_initialAccountState::raw_initialAccountState()
  : code_()
  , data_()
{}

raw_initialAccountState::raw_initialAccountState(std::string const &code_, std::string const &data_)
  : code_(std::move(code_))
  , data_(std::move(data_))
{}

const std::int32_t raw_initialAccountState::ID;

object_ptr<raw_initialAccountState> raw_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_initialAccountState> res = make_object<raw_initialAccountState>();
  res->code_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->code_fieldID));
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return res;
}

void raw_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, code_); if (nextBytes) { env->SetObjectField(s, code_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void raw_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawInitialAccountState");
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

void raw_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawInitialAccountState").c_str());
  code_fieldID = td::jni::get_field_id(env, Class, "code", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
}

jclass raw_message::Class;
jfieldID raw_message::source_fieldID;
jfieldID raw_message::destination_fieldID;
jfieldID raw_message::value_fieldID;
jfieldID raw_message::fwd_fee_fieldID;
jfieldID raw_message::ihr_fee_fieldID;
jfieldID raw_message::created_lt_fieldID;
jfieldID raw_message::body_hash_fieldID;
jfieldID raw_message::message_fieldID;

raw_message::raw_message()
  : source_()
  , destination_()
  , value_()
  , fwd_fee_()
  , ihr_fee_()
  , created_lt_()
  , body_hash_()
  , message_()
{}

raw_message::raw_message(std::string const &source_, std::string const &destination_, std::int64_t value_, std::int64_t fwd_fee_, std::int64_t ihr_fee_, std::int64_t created_lt_, std::string const &body_hash_, std::string const &message_)
  : source_(std::move(source_))
  , destination_(std::move(destination_))
  , value_(value_)
  , fwd_fee_(fwd_fee_)
  , ihr_fee_(ihr_fee_)
  , created_lt_(created_lt_)
  , body_hash_(std::move(body_hash_))
  , message_(std::move(message_))
{}

const std::int32_t raw_message::ID;

object_ptr<raw_message> raw_message::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_message> res = make_object<raw_message>();
  res->source_ = td::jni::fetch_string(env, p, res->source_fieldID);
  res->destination_ = td::jni::fetch_string(env, p, res->destination_fieldID);
  res->value_ = env->GetLongField(p, res->value_fieldID);
  res->fwd_fee_ = env->GetLongField(p, res->fwd_fee_fieldID);
  res->ihr_fee_ = env->GetLongField(p, res->ihr_fee_fieldID);
  res->created_lt_ = env->GetLongField(p, res->created_lt_fieldID);
  res->body_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_hash_fieldID));
  res->message_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->message_fieldID));
  return res;
}

void raw_message::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, source_); if (nextString) { env->SetObjectField(s, source_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  { jstring nextString = td::jni::to_jstring(env, destination_); if (nextString) { env->SetObjectField(s, destination_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, value_fieldID, value_);
  env->SetLongField(s, fwd_fee_fieldID, fwd_fee_);
  env->SetLongField(s, ihr_fee_fieldID, ihr_fee_);
  env->SetLongField(s, created_lt_fieldID, created_lt_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_hash_); if (nextBytes) { env->SetObjectField(s, body_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, message_); if (nextBytes) { env->SetObjectField(s, message_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void raw_message::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawMessage");
    s.store_field("source", source_);
    s.store_field("destination", destination_);
    s.store_field("value", value_);
    s.store_field("fwdFee", fwd_fee_);
    s.store_field("ihrFee", ihr_fee_);
    s.store_field("createdLt", created_lt_);
    s.store_bytes_field("bodyHash", body_hash_);
    s.store_bytes_field("message", message_);
    s.store_class_end();
  }
}

void raw_message::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawMessage").c_str());
  source_fieldID = td::jni::get_field_id(env, Class, "source", "Ljava/lang/String;");
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", "Ljava/lang/String;");
  value_fieldID = td::jni::get_field_id(env, Class, "value", "J");
  fwd_fee_fieldID = td::jni::get_field_id(env, Class, "fwdFee", "J");
  ihr_fee_fieldID = td::jni::get_field_id(env, Class, "ihrFee", "J");
  created_lt_fieldID = td::jni::get_field_id(env, Class, "createdLt", "J");
  body_hash_fieldID = td::jni::get_field_id(env, Class, "bodyHash", "[B");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "[B");
}

jclass raw_transaction::Class;
jfieldID raw_transaction::utime_fieldID;
jfieldID raw_transaction::data_fieldID;
jfieldID raw_transaction::transaction_id_fieldID;
jfieldID raw_transaction::fee_fieldID;
jfieldID raw_transaction::storage_fee_fieldID;
jfieldID raw_transaction::other_fee_fieldID;
jfieldID raw_transaction::in_msg_fieldID;
jfieldID raw_transaction::out_msgs_fieldID;

raw_transaction::raw_transaction()
  : utime_()
  , data_()
  , transaction_id_()
  , fee_()
  , storage_fee_()
  , other_fee_()
  , in_msg_()
  , out_msgs_()
{}

raw_transaction::raw_transaction(std::int64_t utime_, std::string const &data_, object_ptr<internal_transactionId> &&transaction_id_, std::int64_t fee_, std::int64_t storage_fee_, std::int64_t other_fee_, object_ptr<raw_message> &&in_msg_, std::vector<object_ptr<raw_message>> &&out_msgs_)
  : utime_(utime_)
  , data_(std::move(data_))
  , transaction_id_(std::move(transaction_id_))
  , fee_(fee_)
  , storage_fee_(storage_fee_)
  , other_fee_(other_fee_)
  , in_msg_(std::move(in_msg_))
  , out_msgs_(std::move(out_msgs_))
{}

const std::int32_t raw_transaction::ID;

object_ptr<raw_transaction> raw_transaction::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_transaction> res = make_object<raw_transaction>();
  res->utime_ = env->GetLongField(p, res->utime_fieldID);
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  res->transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->transaction_id_fieldID));;
  res->fee_ = env->GetLongField(p, res->fee_fieldID);
  res->storage_fee_ = env->GetLongField(p, res->storage_fee_fieldID);
  res->other_fee_ = env->GetLongField(p, res->other_fee_fieldID);
  res->in_msg_ = td::jni::fetch_tl_object<raw_message>(env, td::jni::fetch_object(env, p, res->in_msg_fieldID));;
  res->out_msgs_ = td::jni::FetchVector<raw_message>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->out_msgs_fieldID));;
  return res;
}

void raw_transaction::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, utime_fieldID, utime_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (transaction_id_ != nullptr) { jobject next; transaction_id_->store(env, next); if (next) { env->SetObjectField(s, transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, fee_fieldID, fee_);
  env->SetLongField(s, storage_fee_fieldID, storage_fee_);
  env->SetLongField(s, other_fee_fieldID, other_fee_);
  if (in_msg_ != nullptr) { jobject next; in_msg_->store(env, next); if (next) { env->SetObjectField(s, in_msg_fieldID, next); env->DeleteLocalRef(next); } }
  { auto arr_tmp_ = td::jni::store_vector(env, out_msgs_); if (arr_tmp_) { env->SetObjectField(s, out_msgs_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void raw_transaction::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawTransaction");
    s.store_field("utime", utime_);
    s.store_bytes_field("data", data_);
    if (transaction_id_ == nullptr) { s.store_field("transactionId", "null"); } else { transaction_id_->store(s, "transactionId"); }
    s.store_field("fee", fee_);
    s.store_field("storageFee", storage_fee_);
    s.store_field("otherFee", other_fee_);
    if (in_msg_ == nullptr) { s.store_field("inMsg", "null"); } else { in_msg_->store(s, "inMsg"); }
    { const std::vector<object_ptr<raw_message>> &v = out_msgs_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("outMsgs", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void raw_transaction::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawTransaction").c_str());
  utime_fieldID = td::jni::get_field_id(env, Class, "utime", "J");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
  transaction_id_fieldID = td::jni::get_field_id(env, Class, "transactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  fee_fieldID = td::jni::get_field_id(env, Class, "fee", "J");
  storage_fee_fieldID = td::jni::get_field_id(env, Class, "storageFee", "J");
  other_fee_fieldID = td::jni::get_field_id(env, Class, "otherFee", "J");
  in_msg_fieldID = td::jni::get_field_id(env, Class, "inMsg", (PSLICE() << "L" << package_name << "/TonApi$RawMessage;").c_str());
  out_msgs_fieldID = td::jni::get_field_id(env, Class, "outMsgs", (PSLICE() << "[L" << package_name << "/TonApi$RawMessage;").c_str());
}

jclass raw_transactions::Class;
jfieldID raw_transactions::transactions_fieldID;
jfieldID raw_transactions::previous_transaction_id_fieldID;

raw_transactions::raw_transactions()
  : transactions_()
  , previous_transaction_id_()
{}

raw_transactions::raw_transactions(std::vector<object_ptr<raw_transaction>> &&transactions_, object_ptr<internal_transactionId> &&previous_transaction_id_)
  : transactions_(std::move(transactions_))
  , previous_transaction_id_(std::move(previous_transaction_id_))
{}

const std::int32_t raw_transactions::ID;

object_ptr<raw_transactions> raw_transactions::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_transactions> res = make_object<raw_transactions>();
  res->transactions_ = td::jni::FetchVector<raw_transaction>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->transactions_fieldID));;
  res->previous_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->previous_transaction_id_fieldID));;
  return res;
}

void raw_transactions::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, transactions_); if (arr_tmp_) { env->SetObjectField(s, transactions_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
  if (previous_transaction_id_ != nullptr) { jobject next; previous_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, previous_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
}

void raw_transactions::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawTransactions");
    { const std::vector<object_ptr<raw_transaction>> &v = transactions_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("transactions", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    if (previous_transaction_id_ == nullptr) { s.store_field("previousTransactionId", "null"); } else { previous_transaction_id_->store(s, "previousTransactionId"); }
    s.store_class_end();
  }
}

void raw_transactions::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawTransactions").c_str());
  transactions_fieldID = td::jni::get_field_id(env, Class, "transactions", (PSLICE() << "[L" << package_name << "/TonApi$RawTransaction;").c_str());
  previous_transaction_id_fieldID = td::jni::get_field_id(env, Class, "previousTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
}

jclass smc_info::Class;
jfieldID smc_info::id_fieldID;

smc_info::smc_info()
  : id_()
{}

smc_info::smc_info(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t smc_info::ID;

object_ptr<smc_info> smc_info::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_info> res = make_object<smc_info>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void smc_info::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void smc_info::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcInfo");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

void smc_info::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcInfo").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass smc_MethodId::Class;

object_ptr<smc_MethodId> smc_MethodId::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case smc_methodIdNumber::ID:
      return smc_methodIdNumber::fetch(env, p);
    case smc_methodIdName::ID:
      return smc_methodIdName::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void smc_MethodId::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcMethodId").c_str());
  smc_methodIdNumber::init_jni_vars(env, package_name);
  smc_methodIdName::init_jni_vars(env, package_name);
}

jclass smc_methodIdNumber::Class;
jfieldID smc_methodIdNumber::number_fieldID;

smc_methodIdNumber::smc_methodIdNumber()
  : number_()
{}

smc_methodIdNumber::smc_methodIdNumber(std::int32_t number_)
  : number_(number_)
{}

const std::int32_t smc_methodIdNumber::ID;

object_ptr<smc_MethodId> smc_methodIdNumber::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_methodIdNumber> res = make_object<smc_methodIdNumber>();
  res->number_ = env->GetIntField(p, res->number_fieldID);
  return std::move(res);
}

void smc_methodIdNumber::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, number_fieldID, number_);
}

void smc_methodIdNumber::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcMethodIdNumber");
    s.store_field("number", number_);
    s.store_class_end();
  }
}

void smc_methodIdNumber::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcMethodIdNumber").c_str());
  number_fieldID = td::jni::get_field_id(env, Class, "number", "I");
}

jclass smc_methodIdName::Class;
jfieldID smc_methodIdName::name_fieldID;

smc_methodIdName::smc_methodIdName()
  : name_()
{}

smc_methodIdName::smc_methodIdName(std::string const &name_)
  : name_(std::move(name_))
{}

const std::int32_t smc_methodIdName::ID;

object_ptr<smc_MethodId> smc_methodIdName::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_methodIdName> res = make_object<smc_methodIdName>();
  res->name_ = td::jni::fetch_string(env, p, res->name_fieldID);
  return std::move(res);
}

void smc_methodIdName::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, name_); if (nextString) { env->SetObjectField(s, name_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void smc_methodIdName::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcMethodIdName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

void smc_methodIdName::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcMethodIdName").c_str());
  name_fieldID = td::jni::get_field_id(env, Class, "name", "Ljava/lang/String;");
}

jclass smc_runResult::Class;
jfieldID smc_runResult::gas_used_fieldID;
jfieldID smc_runResult::stack_fieldID;
jfieldID smc_runResult::exit_code_fieldID;

smc_runResult::smc_runResult()
  : gas_used_()
  , stack_()
  , exit_code_()
{}

smc_runResult::smc_runResult(std::int64_t gas_used_, std::vector<object_ptr<tvm_StackEntry>> &&stack_, std::int32_t exit_code_)
  : gas_used_(gas_used_)
  , stack_(std::move(stack_))
  , exit_code_(exit_code_)
{}

const std::int32_t smc_runResult::ID;

object_ptr<smc_runResult> smc_runResult::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_runResult> res = make_object<smc_runResult>();
  res->gas_used_ = env->GetLongField(p, res->gas_used_fieldID);
  res->stack_ = td::jni::FetchVector<tvm_StackEntry>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->stack_fieldID));;
  res->exit_code_ = env->GetIntField(p, res->exit_code_fieldID);
  return res;
}

void smc_runResult::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, gas_used_fieldID, gas_used_);
  { auto arr_tmp_ = td::jni::store_vector(env, stack_); if (arr_tmp_) { env->SetObjectField(s, stack_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
  env->SetIntField(s, exit_code_fieldID, exit_code_);
}

void smc_runResult::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcRunResult");
    s.store_field("gasUsed", gas_used_);
    { const std::vector<object_ptr<tvm_StackEntry>> &v = stack_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("stack", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_field("exitCode", exit_code_);
    s.store_class_end();
  }
}

void smc_runResult::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcRunResult").c_str());
  gas_used_fieldID = td::jni::get_field_id(env, Class, "gasUsed", "J");
  stack_fieldID = td::jni::get_field_id(env, Class, "stack", (PSLICE() << "[L" << package_name << "/TonApi$TvmStackEntry;").c_str());
  exit_code_fieldID = td::jni::get_field_id(env, Class, "exitCode", "I");
}

jclass testGiver_accountState::Class;
jfieldID testGiver_accountState::balance_fieldID;
jfieldID testGiver_accountState::seqno_fieldID;
jfieldID testGiver_accountState::last_transaction_id_fieldID;
jfieldID testGiver_accountState::sync_utime_fieldID;

testGiver_accountState::testGiver_accountState()
  : balance_()
  , seqno_()
  , last_transaction_id_()
  , sync_utime_()
{}

testGiver_accountState::testGiver_accountState(std::int64_t balance_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_)
  : balance_(balance_)
  , seqno_(seqno_)
  , last_transaction_id_(std::move(last_transaction_id_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t testGiver_accountState::ID;

object_ptr<testGiver_accountState> testGiver_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testGiver_accountState> res = make_object<testGiver_accountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void testGiver_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  env->SetIntField(s, seqno_fieldID, seqno_);
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void testGiver_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestGiverAccountState");
    s.store_field("balance", balance_);
    s.store_field("seqno", seqno_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void testGiver_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestGiverAccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass testWallet_accountState::Class;
jfieldID testWallet_accountState::balance_fieldID;
jfieldID testWallet_accountState::seqno_fieldID;
jfieldID testWallet_accountState::last_transaction_id_fieldID;
jfieldID testWallet_accountState::sync_utime_fieldID;

testWallet_accountState::testWallet_accountState()
  : balance_()
  , seqno_()
  , last_transaction_id_()
  , sync_utime_()
{}

testWallet_accountState::testWallet_accountState(std::int64_t balance_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_)
  : balance_(balance_)
  , seqno_(seqno_)
  , last_transaction_id_(std::move(last_transaction_id_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t testWallet_accountState::ID;

object_ptr<testWallet_accountState> testWallet_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testWallet_accountState> res = make_object<testWallet_accountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void testWallet_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  env->SetIntField(s, seqno_fieldID, seqno_);
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void testWallet_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestWalletAccountState");
    s.store_field("balance", balance_);
    s.store_field("seqno", seqno_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void testWallet_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestWalletAccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass testWallet_initialAccountState::Class;
jfieldID testWallet_initialAccountState::public_key_fieldID;

testWallet_initialAccountState::testWallet_initialAccountState()
  : public_key_()
{}

testWallet_initialAccountState::testWallet_initialAccountState(std::string const &public_key_)
  : public_key_(std::move(public_key_))
{}

const std::int32_t testWallet_initialAccountState::ID;

object_ptr<testWallet_initialAccountState> testWallet_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testWallet_initialAccountState> res = make_object<testWallet_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  return res;
}

void testWallet_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void testWallet_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestWalletInitialAccountState");
    s.store_field("publicKey", public_key_);
    s.store_class_end();
  }
}

void testWallet_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestWalletInitialAccountState").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
}

jclass tvm_cell::Class;
jfieldID tvm_cell::bytes_fieldID;

tvm_cell::tvm_cell()
  : bytes_()
{}

tvm_cell::tvm_cell(std::string const &bytes_)
  : bytes_(std::move(bytes_))
{}

const std::int32_t tvm_cell::ID;

object_ptr<tvm_cell> tvm_cell::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_cell> res = make_object<tvm_cell>();
  res->bytes_ = td::jni::fetch_string(env, p, res->bytes_fieldID);
  return res;
}

void tvm_cell::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, bytes_); if (nextString) { env->SetObjectField(s, bytes_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void tvm_cell::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmCell");
    s.store_field("bytes", bytes_);
    s.store_class_end();
  }
}

void tvm_cell::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmCell").c_str());
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "Ljava/lang/String;");
}

jclass tvm_numberDecimal::Class;
jfieldID tvm_numberDecimal::number_fieldID;

tvm_numberDecimal::tvm_numberDecimal()
  : number_()
{}

tvm_numberDecimal::tvm_numberDecimal(std::string const &number_)
  : number_(std::move(number_))
{}

const std::int32_t tvm_numberDecimal::ID;

object_ptr<tvm_numberDecimal> tvm_numberDecimal::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_numberDecimal> res = make_object<tvm_numberDecimal>();
  res->number_ = td::jni::fetch_string(env, p, res->number_fieldID);
  return res;
}

void tvm_numberDecimal::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, number_); if (nextString) { env->SetObjectField(s, number_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void tvm_numberDecimal::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmNumberDecimal");
    s.store_field("number", number_);
    s.store_class_end();
  }
}

void tvm_numberDecimal::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmNumberDecimal").c_str());
  number_fieldID = td::jni::get_field_id(env, Class, "number", "Ljava/lang/String;");
}

jclass tvm_slice::Class;
jfieldID tvm_slice::bytes_fieldID;

tvm_slice::tvm_slice()
  : bytes_()
{}

tvm_slice::tvm_slice(std::string const &bytes_)
  : bytes_(std::move(bytes_))
{}

const std::int32_t tvm_slice::ID;

object_ptr<tvm_slice> tvm_slice::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_slice> res = make_object<tvm_slice>();
  res->bytes_ = td::jni::fetch_string(env, p, res->bytes_fieldID);
  return res;
}

void tvm_slice::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, bytes_); if (nextString) { env->SetObjectField(s, bytes_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void tvm_slice::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmSlice");
    s.store_field("bytes", bytes_);
    s.store_class_end();
  }
}

void tvm_slice::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmSlice").c_str());
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "Ljava/lang/String;");
}

jclass tvm_StackEntry::Class;

object_ptr<tvm_StackEntry> tvm_StackEntry::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case tvm_stackEntrySlice::ID:
      return tvm_stackEntrySlice::fetch(env, p);
    case tvm_stackEntryCell::ID:
      return tvm_stackEntryCell::fetch(env, p);
    case tvm_stackEntryNumber::ID:
      return tvm_stackEntryNumber::fetch(env, p);
    case tvm_stackEntryUnsupported::ID:
      return tvm_stackEntryUnsupported::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void tvm_StackEntry::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntry").c_str());
  tvm_stackEntrySlice::init_jni_vars(env, package_name);
  tvm_stackEntryCell::init_jni_vars(env, package_name);
  tvm_stackEntryNumber::init_jni_vars(env, package_name);
  tvm_stackEntryUnsupported::init_jni_vars(env, package_name);
}

jclass tvm_stackEntrySlice::Class;
jfieldID tvm_stackEntrySlice::slice_fieldID;

tvm_stackEntrySlice::tvm_stackEntrySlice()
  : slice_()
{}

tvm_stackEntrySlice::tvm_stackEntrySlice(object_ptr<tvm_slice> &&slice_)
  : slice_(std::move(slice_))
{}

const std::int32_t tvm_stackEntrySlice::ID;

object_ptr<tvm_StackEntry> tvm_stackEntrySlice::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_stackEntrySlice> res = make_object<tvm_stackEntrySlice>();
  res->slice_ = td::jni::fetch_tl_object<tvm_slice>(env, td::jni::fetch_object(env, p, res->slice_fieldID));;
  return std::move(res);
}

void tvm_stackEntrySlice::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (slice_ != nullptr) { jobject next; slice_->store(env, next); if (next) { env->SetObjectField(s, slice_fieldID, next); env->DeleteLocalRef(next); } }
}

void tvm_stackEntrySlice::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmStackEntrySlice");
    if (slice_ == nullptr) { s.store_field("slice", "null"); } else { slice_->store(s, "slice"); }
    s.store_class_end();
  }
}

void tvm_stackEntrySlice::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntrySlice").c_str());
  slice_fieldID = td::jni::get_field_id(env, Class, "slice", (PSLICE() << "L" << package_name << "/TonApi$TvmSlice;").c_str());
}

jclass tvm_stackEntryCell::Class;
jfieldID tvm_stackEntryCell::cell_fieldID;

tvm_stackEntryCell::tvm_stackEntryCell()
  : cell_()
{}

tvm_stackEntryCell::tvm_stackEntryCell(object_ptr<tvm_cell> &&cell_)
  : cell_(std::move(cell_))
{}

const std::int32_t tvm_stackEntryCell::ID;

object_ptr<tvm_StackEntry> tvm_stackEntryCell::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_stackEntryCell> res = make_object<tvm_stackEntryCell>();
  res->cell_ = td::jni::fetch_tl_object<tvm_cell>(env, td::jni::fetch_object(env, p, res->cell_fieldID));;
  return std::move(res);
}

void tvm_stackEntryCell::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (cell_ != nullptr) { jobject next; cell_->store(env, next); if (next) { env->SetObjectField(s, cell_fieldID, next); env->DeleteLocalRef(next); } }
}

void tvm_stackEntryCell::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmStackEntryCell");
    if (cell_ == nullptr) { s.store_field("cell", "null"); } else { cell_->store(s, "cell"); }
    s.store_class_end();
  }
}

void tvm_stackEntryCell::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntryCell").c_str());
  cell_fieldID = td::jni::get_field_id(env, Class, "cell", (PSLICE() << "L" << package_name << "/TonApi$TvmCell;").c_str());
}

jclass tvm_stackEntryNumber::Class;
jfieldID tvm_stackEntryNumber::number_fieldID;

tvm_stackEntryNumber::tvm_stackEntryNumber()
  : number_()
{}

tvm_stackEntryNumber::tvm_stackEntryNumber(object_ptr<tvm_numberDecimal> &&number_)
  : number_(std::move(number_))
{}

const std::int32_t tvm_stackEntryNumber::ID;

object_ptr<tvm_StackEntry> tvm_stackEntryNumber::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_stackEntryNumber> res = make_object<tvm_stackEntryNumber>();
  res->number_ = td::jni::fetch_tl_object<tvm_numberDecimal>(env, td::jni::fetch_object(env, p, res->number_fieldID));;
  return std::move(res);
}

void tvm_stackEntryNumber::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (number_ != nullptr) { jobject next; number_->store(env, next); if (next) { env->SetObjectField(s, number_fieldID, next); env->DeleteLocalRef(next); } }
}

void tvm_stackEntryNumber::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmStackEntryNumber");
    if (number_ == nullptr) { s.store_field("number", "null"); } else { number_->store(s, "number"); }
    s.store_class_end();
  }
}

void tvm_stackEntryNumber::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntryNumber").c_str());
  number_fieldID = td::jni::get_field_id(env, Class, "number", (PSLICE() << "L" << package_name << "/TonApi$TvmNumberDecimal;").c_str());
}

jclass tvm_stackEntryUnsupported::Class;

tvm_stackEntryUnsupported::tvm_stackEntryUnsupported() {
}

const std::int32_t tvm_stackEntryUnsupported::ID;

object_ptr<tvm_StackEntry> tvm_stackEntryUnsupported::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_stackEntryUnsupported> res = make_object<tvm_stackEntryUnsupported>();
  return std::move(res);
}

void tvm_stackEntryUnsupported::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void tvm_stackEntryUnsupported::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmStackEntryUnsupported");
    s.store_class_end();
  }
}

void tvm_stackEntryUnsupported::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntryUnsupported").c_str());
}

jclass uninited_accountState::Class;
jfieldID uninited_accountState::balance_fieldID;
jfieldID uninited_accountState::last_transaction_id_fieldID;
jfieldID uninited_accountState::frozen_hash_fieldID;
jfieldID uninited_accountState::sync_utime_fieldID;

uninited_accountState::uninited_accountState()
  : balance_()
  , last_transaction_id_()
  , frozen_hash_()
  , sync_utime_()
{}

uninited_accountState::uninited_accountState(std::int64_t balance_, object_ptr<internal_transactionId> &&last_transaction_id_, std::string const &frozen_hash_, std::int64_t sync_utime_)
  : balance_(balance_)
  , last_transaction_id_(std::move(last_transaction_id_))
  , frozen_hash_(std::move(frozen_hash_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t uninited_accountState::ID;

object_ptr<uninited_accountState> uninited_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<uninited_accountState> res = make_object<uninited_accountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->frozen_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->frozen_hash_fieldID));
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void uninited_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, frozen_hash_); if (nextBytes) { env->SetObjectField(s, frozen_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void uninited_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "UninitedAccountState");
    s.store_field("balance", balance_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    s.store_bytes_field("frozenHash", frozen_hash_);
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void uninited_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$UninitedAccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  frozen_hash_fieldID = td::jni::get_field_id(env, Class, "frozenHash", "[B");
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass wallet_accountState::Class;
jfieldID wallet_accountState::balance_fieldID;
jfieldID wallet_accountState::seqno_fieldID;
jfieldID wallet_accountState::last_transaction_id_fieldID;
jfieldID wallet_accountState::sync_utime_fieldID;

wallet_accountState::wallet_accountState()
  : balance_()
  , seqno_()
  , last_transaction_id_()
  , sync_utime_()
{}

wallet_accountState::wallet_accountState(std::int64_t balance_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_)
  : balance_(balance_)
  , seqno_(seqno_)
  , last_transaction_id_(std::move(last_transaction_id_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t wallet_accountState::ID;

object_ptr<wallet_accountState> wallet_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_accountState> res = make_object<wallet_accountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void wallet_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  env->SetIntField(s, seqno_fieldID, seqno_);
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void wallet_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletAccountState");
    s.store_field("balance", balance_);
    s.store_field("seqno", seqno_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void wallet_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletAccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass wallet_initialAccountState::Class;
jfieldID wallet_initialAccountState::public_key_fieldID;

wallet_initialAccountState::wallet_initialAccountState()
  : public_key_()
{}

wallet_initialAccountState::wallet_initialAccountState(std::string const &public_key_)
  : public_key_(std::move(public_key_))
{}

const std::int32_t wallet_initialAccountState::ID;

object_ptr<wallet_initialAccountState> wallet_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_initialAccountState> res = make_object<wallet_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  return res;
}

void wallet_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void wallet_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletInitialAccountState");
    s.store_field("publicKey", public_key_);
    s.store_class_end();
  }
}

void wallet_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletInitialAccountState").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
}

jclass wallet_v3_accountState::Class;
jfieldID wallet_v3_accountState::balance_fieldID;
jfieldID wallet_v3_accountState::wallet_id_fieldID;
jfieldID wallet_v3_accountState::seqno_fieldID;
jfieldID wallet_v3_accountState::last_transaction_id_fieldID;
jfieldID wallet_v3_accountState::sync_utime_fieldID;

wallet_v3_accountState::wallet_v3_accountState()
  : balance_()
  , wallet_id_()
  , seqno_()
  , last_transaction_id_()
  , sync_utime_()
{}

wallet_v3_accountState::wallet_v3_accountState(std::int64_t balance_, std::int64_t wallet_id_, std::int32_t seqno_, object_ptr<internal_transactionId> &&last_transaction_id_, std::int64_t sync_utime_)
  : balance_(balance_)
  , wallet_id_(wallet_id_)
  , seqno_(seqno_)
  , last_transaction_id_(std::move(last_transaction_id_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t wallet_v3_accountState::ID;

object_ptr<wallet_v3_accountState> wallet_v3_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_v3_accountState> res = make_object<wallet_v3_accountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void wallet_v3_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
  env->SetIntField(s, seqno_fieldID, seqno_);
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void wallet_v3_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletV3AccountState");
    s.store_field("balance", balance_);
    s.store_field("walletId", wallet_id_);
    s.store_field("seqno", seqno_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void wallet_v3_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletV3AccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass wallet_v3_initialAccountState::Class;
jfieldID wallet_v3_initialAccountState::public_key_fieldID;
jfieldID wallet_v3_initialAccountState::wallet_id_fieldID;

wallet_v3_initialAccountState::wallet_v3_initialAccountState()
  : public_key_()
  , wallet_id_()
{}

wallet_v3_initialAccountState::wallet_v3_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_)
  : public_key_(std::move(public_key_))
  , wallet_id_(wallet_id_)
{}

const std::int32_t wallet_v3_initialAccountState::ID;

object_ptr<wallet_v3_initialAccountState> wallet_v3_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_v3_initialAccountState> res = make_object<wallet_v3_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return res;
}

void wallet_v3_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void wallet_v3_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletV3InitialAccountState");
    s.store_field("publicKey", public_key_);
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void wallet_v3_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletV3InitialAccountState").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass addLogMessage::Class;
jfieldID addLogMessage::verbosity_level_fieldID;
jfieldID addLogMessage::text_fieldID;

addLogMessage::addLogMessage()
  : verbosity_level_()
  , text_()
{}

addLogMessage::addLogMessage(std::int32_t verbosity_level_, std::string const &text_)
  : verbosity_level_(verbosity_level_)
  , text_(std::move(text_))
{}

const std::int32_t addLogMessage::ID;

object_ptr<addLogMessage> addLogMessage::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<addLogMessage> res = make_object<addLogMessage>();
  res->verbosity_level_ = env->GetIntField(p, res->verbosity_level_fieldID);
  res->text_ = td::jni::fetch_string(env, p, res->text_fieldID);
  return res;
}

void addLogMessage::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, verbosity_level_fieldID, verbosity_level_);
  { jstring nextString = td::jni::to_jstring(env, text_); if (nextString) { env->SetObjectField(s, text_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void addLogMessage::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "AddLogMessage");
    s.store_field("verbosityLevel", verbosity_level_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

addLogMessage::ReturnType addLogMessage::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void addLogMessage::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$AddLogMessage").c_str());
  verbosity_level_fieldID = td::jni::get_field_id(env, Class, "verbosityLevel", "I");
  text_fieldID = td::jni::get_field_id(env, Class, "text", "Ljava/lang/String;");
}

jclass changeLocalPassword::Class;
jfieldID changeLocalPassword::input_key_fieldID;
jfieldID changeLocalPassword::new_local_password_fieldID;

changeLocalPassword::changeLocalPassword()
  : input_key_()
  , new_local_password_()
{}

changeLocalPassword::changeLocalPassword(object_ptr<InputKey> &&input_key_, td::SecureString &&new_local_password_)
  : input_key_(std::move(input_key_))
  , new_local_password_(std::move(new_local_password_))
{}

const std::int32_t changeLocalPassword::ID;

object_ptr<changeLocalPassword> changeLocalPassword::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<changeLocalPassword> res = make_object<changeLocalPassword>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  res->new_local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->new_local_password_fieldID));
  return res;
}

void changeLocalPassword::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, new_local_password_); if (nextBytes) { env->SetObjectField(s, new_local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void changeLocalPassword::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ChangeLocalPassword");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    s.store_bytes_field("newLocalPassword", new_local_password_);
    s.store_class_end();
  }
}

changeLocalPassword::ReturnType changeLocalPassword::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return key::fetch(env, p);
}

void changeLocalPassword::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ChangeLocalPassword").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  new_local_password_fieldID = td::jni::get_field_id(env, Class, "newLocalPassword", "[B");
}

jclass close::Class;

close::close() {
}

const std::int32_t close::ID;

object_ptr<close> close::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<close> res = make_object<close>();
  return res;
}

void close::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void close::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Close");
    s.store_class_end();
  }
}

close::ReturnType close::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void close::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Close").c_str());
}

jclass createNewKey::Class;
jfieldID createNewKey::local_password_fieldID;
jfieldID createNewKey::mnemonic_password_fieldID;
jfieldID createNewKey::random_extra_seed_fieldID;

createNewKey::createNewKey()
  : local_password_()
  , mnemonic_password_()
  , random_extra_seed_()
{}

createNewKey::createNewKey(td::SecureString &&local_password_, td::SecureString &&mnemonic_password_, td::SecureString &&random_extra_seed_)
  : local_password_(std::move(local_password_))
  , mnemonic_password_(std::move(mnemonic_password_))
  , random_extra_seed_(std::move(random_extra_seed_))
{}

const std::int32_t createNewKey::ID;

object_ptr<createNewKey> createNewKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<createNewKey> res = make_object<createNewKey>();
  res->local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->local_password_fieldID));
  res->mnemonic_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->mnemonic_password_fieldID));
  res->random_extra_seed_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->random_extra_seed_fieldID));
  return res;
}

void createNewKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, local_password_); if (nextBytes) { env->SetObjectField(s, local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, mnemonic_password_); if (nextBytes) { env->SetObjectField(s, mnemonic_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, random_extra_seed_); if (nextBytes) { env->SetObjectField(s, random_extra_seed_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void createNewKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "CreateNewKey");
    s.store_bytes_field("localPassword", local_password_);
    s.store_bytes_field("mnemonicPassword", mnemonic_password_);
    s.store_bytes_field("randomExtraSeed", random_extra_seed_);
    s.store_class_end();
  }
}

createNewKey::ReturnType createNewKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return key::fetch(env, p);
}

void createNewKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$CreateNewKey").c_str());
  local_password_fieldID = td::jni::get_field_id(env, Class, "localPassword", "[B");
  mnemonic_password_fieldID = td::jni::get_field_id(env, Class, "mnemonicPassword", "[B");
  random_extra_seed_fieldID = td::jni::get_field_id(env, Class, "randomExtraSeed", "[B");
}

jclass decrypt::Class;
jfieldID decrypt::encrypted_data_fieldID;
jfieldID decrypt::secret_fieldID;

decrypt::decrypt()
  : encrypted_data_()
  , secret_()
{}

decrypt::decrypt(td::SecureString &&encrypted_data_, td::SecureString &&secret_)
  : encrypted_data_(std::move(encrypted_data_))
  , secret_(std::move(secret_))
{}

const std::int32_t decrypt::ID;

object_ptr<decrypt> decrypt::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<decrypt> res = make_object<decrypt>();
  res->encrypted_data_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->encrypted_data_fieldID));
  res->secret_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->secret_fieldID));
  return res;
}

void decrypt::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, encrypted_data_); if (nextBytes) { env->SetObjectField(s, encrypted_data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, secret_); if (nextBytes) { env->SetObjectField(s, secret_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void decrypt::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Decrypt");
    s.store_bytes_field("encryptedData", encrypted_data_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

decrypt::ReturnType decrypt::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return data::fetch(env, p);
}

void decrypt::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Decrypt").c_str());
  encrypted_data_fieldID = td::jni::get_field_id(env, Class, "encryptedData", "[B");
  secret_fieldID = td::jni::get_field_id(env, Class, "secret", "[B");
}

jclass deleteAllKeys::Class;

deleteAllKeys::deleteAllKeys() {
}

const std::int32_t deleteAllKeys::ID;

object_ptr<deleteAllKeys> deleteAllKeys::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<deleteAllKeys> res = make_object<deleteAllKeys>();
  return res;
}

void deleteAllKeys::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void deleteAllKeys::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DeleteAllKeys");
    s.store_class_end();
  }
}

deleteAllKeys::ReturnType deleteAllKeys::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void deleteAllKeys::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DeleteAllKeys").c_str());
}

jclass deleteKey::Class;
jfieldID deleteKey::key_fieldID;

deleteKey::deleteKey()
  : key_()
{}

deleteKey::deleteKey(object_ptr<key> &&key_)
  : key_(std::move(key_))
{}

const std::int32_t deleteKey::ID;

object_ptr<deleteKey> deleteKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<deleteKey> res = make_object<deleteKey>();
  res->key_ = td::jni::fetch_tl_object<key>(env, td::jni::fetch_object(env, p, res->key_fieldID));;
  return res;
}

void deleteKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (key_ != nullptr) { jobject next; key_->store(env, next); if (next) { env->SetObjectField(s, key_fieldID, next); env->DeleteLocalRef(next); } }
}

void deleteKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DeleteKey");
    if (key_ == nullptr) { s.store_field("key", "null"); } else { key_->store(s, "key"); }
    s.store_class_end();
  }
}

deleteKey::ReturnType deleteKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void deleteKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DeleteKey").c_str());
  key_fieldID = td::jni::get_field_id(env, Class, "key", (PSLICE() << "L" << package_name << "/TonApi$Key;").c_str());
}

jclass encrypt::Class;
jfieldID encrypt::decrypted_data_fieldID;
jfieldID encrypt::secret_fieldID;

encrypt::encrypt()
  : decrypted_data_()
  , secret_()
{}

encrypt::encrypt(td::SecureString &&decrypted_data_, td::SecureString &&secret_)
  : decrypted_data_(std::move(decrypted_data_))
  , secret_(std::move(secret_))
{}

const std::int32_t encrypt::ID;

object_ptr<encrypt> encrypt::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<encrypt> res = make_object<encrypt>();
  res->decrypted_data_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->decrypted_data_fieldID));
  res->secret_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->secret_fieldID));
  return res;
}

void encrypt::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, decrypted_data_); if (nextBytes) { env->SetObjectField(s, decrypted_data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, secret_); if (nextBytes) { env->SetObjectField(s, secret_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void encrypt::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Encrypt");
    s.store_bytes_field("decryptedData", decrypted_data_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

encrypt::ReturnType encrypt::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return data::fetch(env, p);
}

void encrypt::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Encrypt").c_str());
  decrypted_data_fieldID = td::jni::get_field_id(env, Class, "decryptedData", "[B");
  secret_fieldID = td::jni::get_field_id(env, Class, "secret", "[B");
}

jclass exportEncryptedKey::Class;
jfieldID exportEncryptedKey::input_key_fieldID;
jfieldID exportEncryptedKey::key_password_fieldID;

exportEncryptedKey::exportEncryptedKey()
  : input_key_()
  , key_password_()
{}

exportEncryptedKey::exportEncryptedKey(object_ptr<InputKey> &&input_key_, td::SecureString &&key_password_)
  : input_key_(std::move(input_key_))
  , key_password_(std::move(key_password_))
{}

const std::int32_t exportEncryptedKey::ID;

object_ptr<exportEncryptedKey> exportEncryptedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportEncryptedKey> res = make_object<exportEncryptedKey>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  res->key_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->key_password_fieldID));
  return res;
}

void exportEncryptedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, key_password_); if (nextBytes) { env->SetObjectField(s, key_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void exportEncryptedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportEncryptedKey");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    s.store_bytes_field("keyPassword", key_password_);
    s.store_class_end();
  }
}

exportEncryptedKey::ReturnType exportEncryptedKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return exportedEncryptedKey::fetch(env, p);
}

void exportEncryptedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportEncryptedKey").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  key_password_fieldID = td::jni::get_field_id(env, Class, "keyPassword", "[B");
}

jclass exportKey::Class;
jfieldID exportKey::input_key_fieldID;

exportKey::exportKey()
  : input_key_()
{}

exportKey::exportKey(object_ptr<InputKey> &&input_key_)
  : input_key_(std::move(input_key_))
{}

const std::int32_t exportKey::ID;

object_ptr<exportKey> exportKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportKey> res = make_object<exportKey>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  return res;
}

void exportKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void exportKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportKey");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    s.store_class_end();
  }
}

exportKey::ReturnType exportKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return exportedKey::fetch(env, p);
}

void exportKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportKey").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
}

jclass exportPemKey::Class;
jfieldID exportPemKey::input_key_fieldID;
jfieldID exportPemKey::key_password_fieldID;

exportPemKey::exportPemKey()
  : input_key_()
  , key_password_()
{}

exportPemKey::exportPemKey(object_ptr<InputKey> &&input_key_, td::SecureString &&key_password_)
  : input_key_(std::move(input_key_))
  , key_password_(std::move(key_password_))
{}

const std::int32_t exportPemKey::ID;

object_ptr<exportPemKey> exportPemKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportPemKey> res = make_object<exportPemKey>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  res->key_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->key_password_fieldID));
  return res;
}

void exportPemKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, key_password_); if (nextBytes) { env->SetObjectField(s, key_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void exportPemKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportPemKey");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    s.store_bytes_field("keyPassword", key_password_);
    s.store_class_end();
  }
}

exportPemKey::ReturnType exportPemKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return exportedPemKey::fetch(env, p);
}

void exportPemKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportPemKey").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  key_password_fieldID = td::jni::get_field_id(env, Class, "keyPassword", "[B");
}

jclass generic_createSendGramsQuery::Class;
jfieldID generic_createSendGramsQuery::private_key_fieldID;
jfieldID generic_createSendGramsQuery::source_fieldID;
jfieldID generic_createSendGramsQuery::destination_fieldID;
jfieldID generic_createSendGramsQuery::amount_fieldID;
jfieldID generic_createSendGramsQuery::timeout_fieldID;
jfieldID generic_createSendGramsQuery::allow_send_to_uninited_fieldID;
jfieldID generic_createSendGramsQuery::message_fieldID;

generic_createSendGramsQuery::generic_createSendGramsQuery()
  : private_key_()
  , source_()
  , destination_()
  , amount_()
  , timeout_()
  , allow_send_to_uninited_()
  , message_()
{}

generic_createSendGramsQuery::generic_createSendGramsQuery(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t amount_, std::int32_t timeout_, bool allow_send_to_uninited_, std::string const &message_)
  : private_key_(std::move(private_key_))
  , source_(std::move(source_))
  , destination_(std::move(destination_))
  , amount_(amount_)
  , timeout_(timeout_)
  , allow_send_to_uninited_(allow_send_to_uninited_)
  , message_(std::move(message_))
{}

const std::int32_t generic_createSendGramsQuery::ID;

object_ptr<generic_createSendGramsQuery> generic_createSendGramsQuery::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_createSendGramsQuery> res = make_object<generic_createSendGramsQuery>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  res->source_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->source_fieldID));;
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->amount_ = env->GetLongField(p, res->amount_fieldID);
  res->timeout_ = env->GetIntField(p, res->timeout_fieldID);
  res->allow_send_to_uninited_ = (env->GetBooleanField(p, res->allow_send_to_uninited_fieldID) != 0);
  res->message_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->message_fieldID));
  return res;
}

void generic_createSendGramsQuery::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (source_ != nullptr) { jobject next; source_->store(env, next); if (next) { env->SetObjectField(s, source_fieldID, next); env->DeleteLocalRef(next); } }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, amount_fieldID, amount_);
  env->SetIntField(s, timeout_fieldID, timeout_);
  env->SetBooleanField(s, allow_send_to_uninited_fieldID, allow_send_to_uninited_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, message_); if (nextBytes) { env->SetObjectField(s, message_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void generic_createSendGramsQuery::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericCreateSendGramsQuery");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    if (source_ == nullptr) { s.store_field("source", "null"); } else { source_->store(s, "source"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("amount", amount_);
    s.store_field("timeout", timeout_);
    s.store_field("allowSendToUninited", allow_send_to_uninited_);
    s.store_bytes_field("message", message_);
    s.store_class_end();
  }
}

generic_createSendGramsQuery::ReturnType generic_createSendGramsQuery::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return query_info::fetch(env, p);
}

void generic_createSendGramsQuery::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericCreateSendGramsQuery").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  source_fieldID = td::jni::get_field_id(env, Class, "source", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  amount_fieldID = td::jni::get_field_id(env, Class, "amount", "J");
  timeout_fieldID = td::jni::get_field_id(env, Class, "timeout", "I");
  allow_send_to_uninited_fieldID = td::jni::get_field_id(env, Class, "allowSendToUninited", "Z");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "[B");
}

jclass generic_getAccountState::Class;
jfieldID generic_getAccountState::account_address_fieldID;

generic_getAccountState::generic_getAccountState()
  : account_address_()
{}

generic_getAccountState::generic_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t generic_getAccountState::ID;

object_ptr<generic_getAccountState> generic_getAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_getAccountState> res = make_object<generic_getAccountState>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void generic_getAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void generic_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericGetAccountState");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

generic_getAccountState::ReturnType generic_getAccountState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return generic_AccountState::fetch(env, p);
}

void generic_getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericGetAccountState").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass generic_sendGrams::Class;
jfieldID generic_sendGrams::private_key_fieldID;
jfieldID generic_sendGrams::source_fieldID;
jfieldID generic_sendGrams::destination_fieldID;
jfieldID generic_sendGrams::amount_fieldID;
jfieldID generic_sendGrams::timeout_fieldID;
jfieldID generic_sendGrams::allow_send_to_uninited_fieldID;
jfieldID generic_sendGrams::message_fieldID;

generic_sendGrams::generic_sendGrams()
  : private_key_()
  , source_()
  , destination_()
  , amount_()
  , timeout_()
  , allow_send_to_uninited_()
  , message_()
{}

generic_sendGrams::generic_sendGrams(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t amount_, std::int32_t timeout_, bool allow_send_to_uninited_, std::string const &message_)
  : private_key_(std::move(private_key_))
  , source_(std::move(source_))
  , destination_(std::move(destination_))
  , amount_(amount_)
  , timeout_(timeout_)
  , allow_send_to_uninited_(allow_send_to_uninited_)
  , message_(std::move(message_))
{}

const std::int32_t generic_sendGrams::ID;

object_ptr<generic_sendGrams> generic_sendGrams::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<generic_sendGrams> res = make_object<generic_sendGrams>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  res->source_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->source_fieldID));;
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->amount_ = env->GetLongField(p, res->amount_fieldID);
  res->timeout_ = env->GetIntField(p, res->timeout_fieldID);
  res->allow_send_to_uninited_ = (env->GetBooleanField(p, res->allow_send_to_uninited_fieldID) != 0);
  res->message_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->message_fieldID));
  return res;
}

void generic_sendGrams::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (source_ != nullptr) { jobject next; source_->store(env, next); if (next) { env->SetObjectField(s, source_fieldID, next); env->DeleteLocalRef(next); } }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, amount_fieldID, amount_);
  env->SetIntField(s, timeout_fieldID, timeout_);
  env->SetBooleanField(s, allow_send_to_uninited_fieldID, allow_send_to_uninited_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, message_); if (nextBytes) { env->SetObjectField(s, message_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void generic_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GenericSendGrams");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    if (source_ == nullptr) { s.store_field("source", "null"); } else { source_->store(s, "source"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("amount", amount_);
    s.store_field("timeout", timeout_);
    s.store_field("allowSendToUninited", allow_send_to_uninited_);
    s.store_bytes_field("message", message_);
    s.store_class_end();
  }
}

generic_sendGrams::ReturnType generic_sendGrams::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return sendGramsResult::fetch(env, p);
}

void generic_sendGrams::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GenericSendGrams").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  source_fieldID = td::jni::get_field_id(env, Class, "source", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  amount_fieldID = td::jni::get_field_id(env, Class, "amount", "J");
  timeout_fieldID = td::jni::get_field_id(env, Class, "timeout", "I");
  allow_send_to_uninited_fieldID = td::jni::get_field_id(env, Class, "allowSendToUninited", "Z");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "[B");
}

jclass getBip39Hints::Class;
jfieldID getBip39Hints::prefix_fieldID;

getBip39Hints::getBip39Hints()
  : prefix_()
{}

getBip39Hints::getBip39Hints(std::string const &prefix_)
  : prefix_(std::move(prefix_))
{}

const std::int32_t getBip39Hints::ID;

object_ptr<getBip39Hints> getBip39Hints::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getBip39Hints> res = make_object<getBip39Hints>();
  res->prefix_ = td::jni::fetch_string(env, p, res->prefix_fieldID);
  return res;
}

void getBip39Hints::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, prefix_); if (nextString) { env->SetObjectField(s, prefix_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void getBip39Hints::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetBip39Hints");
    s.store_field("prefix", prefix_);
    s.store_class_end();
  }
}

getBip39Hints::ReturnType getBip39Hints::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return bip39Hints::fetch(env, p);
}

void getBip39Hints::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetBip39Hints").c_str());
  prefix_fieldID = td::jni::get_field_id(env, Class, "prefix", "Ljava/lang/String;");
}

jclass getLogStream::Class;

getLogStream::getLogStream() {
}

const std::int32_t getLogStream::ID;

object_ptr<getLogStream> getLogStream::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getLogStream> res = make_object<getLogStream>();
  return res;
}

void getLogStream::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void getLogStream::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetLogStream");
    s.store_class_end();
  }
}

getLogStream::ReturnType getLogStream::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return LogStream::fetch(env, p);
}

void getLogStream::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetLogStream").c_str());
}

jclass getLogTagVerbosityLevel::Class;
jfieldID getLogTagVerbosityLevel::tag_fieldID;

getLogTagVerbosityLevel::getLogTagVerbosityLevel()
  : tag_()
{}

getLogTagVerbosityLevel::getLogTagVerbosityLevel(std::string const &tag_)
  : tag_(std::move(tag_))
{}

const std::int32_t getLogTagVerbosityLevel::ID;

object_ptr<getLogTagVerbosityLevel> getLogTagVerbosityLevel::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getLogTagVerbosityLevel> res = make_object<getLogTagVerbosityLevel>();
  res->tag_ = td::jni::fetch_string(env, p, res->tag_fieldID);
  return res;
}

void getLogTagVerbosityLevel::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, tag_); if (nextString) { env->SetObjectField(s, tag_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void getLogTagVerbosityLevel::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

getLogTagVerbosityLevel::ReturnType getLogTagVerbosityLevel::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return logVerbosityLevel::fetch(env, p);
}

void getLogTagVerbosityLevel::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetLogTagVerbosityLevel").c_str());
  tag_fieldID = td::jni::get_field_id(env, Class, "tag", "Ljava/lang/String;");
}

jclass getLogTags::Class;

getLogTags::getLogTags() {
}

const std::int32_t getLogTags::ID;

object_ptr<getLogTags> getLogTags::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getLogTags> res = make_object<getLogTags>();
  return res;
}

void getLogTags::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void getLogTags::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetLogTags");
    s.store_class_end();
  }
}

getLogTags::ReturnType getLogTags::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return logTags::fetch(env, p);
}

void getLogTags::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetLogTags").c_str());
}

jclass getLogVerbosityLevel::Class;

getLogVerbosityLevel::getLogVerbosityLevel() {
}

const std::int32_t getLogVerbosityLevel::ID;

object_ptr<getLogVerbosityLevel> getLogVerbosityLevel::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getLogVerbosityLevel> res = make_object<getLogVerbosityLevel>();
  return res;
}

void getLogVerbosityLevel::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void getLogVerbosityLevel::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetLogVerbosityLevel");
    s.store_class_end();
  }
}

getLogVerbosityLevel::ReturnType getLogVerbosityLevel::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return logVerbosityLevel::fetch(env, p);
}

void getLogVerbosityLevel::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetLogVerbosityLevel").c_str());
}

jclass importEncryptedKey::Class;
jfieldID importEncryptedKey::local_password_fieldID;
jfieldID importEncryptedKey::key_password_fieldID;
jfieldID importEncryptedKey::exported_encrypted_key_fieldID;

importEncryptedKey::importEncryptedKey()
  : local_password_()
  , key_password_()
  , exported_encrypted_key_()
{}

importEncryptedKey::importEncryptedKey(td::SecureString &&local_password_, td::SecureString &&key_password_, object_ptr<exportedEncryptedKey> &&exported_encrypted_key_)
  : local_password_(std::move(local_password_))
  , key_password_(std::move(key_password_))
  , exported_encrypted_key_(std::move(exported_encrypted_key_))
{}

const std::int32_t importEncryptedKey::ID;

object_ptr<importEncryptedKey> importEncryptedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<importEncryptedKey> res = make_object<importEncryptedKey>();
  res->local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->local_password_fieldID));
  res->key_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->key_password_fieldID));
  res->exported_encrypted_key_ = td::jni::fetch_tl_object<exportedEncryptedKey>(env, td::jni::fetch_object(env, p, res->exported_encrypted_key_fieldID));;
  return res;
}

void importEncryptedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, local_password_); if (nextBytes) { env->SetObjectField(s, local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, key_password_); if (nextBytes) { env->SetObjectField(s, key_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (exported_encrypted_key_ != nullptr) { jobject next; exported_encrypted_key_->store(env, next); if (next) { env->SetObjectField(s, exported_encrypted_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void importEncryptedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ImportEncryptedKey");
    s.store_bytes_field("localPassword", local_password_);
    s.store_bytes_field("keyPassword", key_password_);
    if (exported_encrypted_key_ == nullptr) { s.store_field("exportedEncryptedKey", "null"); } else { exported_encrypted_key_->store(s, "exportedEncryptedKey"); }
    s.store_class_end();
  }
}

importEncryptedKey::ReturnType importEncryptedKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return key::fetch(env, p);
}

void importEncryptedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ImportEncryptedKey").c_str());
  local_password_fieldID = td::jni::get_field_id(env, Class, "localPassword", "[B");
  key_password_fieldID = td::jni::get_field_id(env, Class, "keyPassword", "[B");
  exported_encrypted_key_fieldID = td::jni::get_field_id(env, Class, "exportedEncryptedKey", (PSLICE() << "L" << package_name << "/TonApi$ExportedEncryptedKey;").c_str());
}

jclass importKey::Class;
jfieldID importKey::local_password_fieldID;
jfieldID importKey::mnemonic_password_fieldID;
jfieldID importKey::exported_key_fieldID;

importKey::importKey()
  : local_password_()
  , mnemonic_password_()
  , exported_key_()
{}

importKey::importKey(td::SecureString &&local_password_, td::SecureString &&mnemonic_password_, object_ptr<exportedKey> &&exported_key_)
  : local_password_(std::move(local_password_))
  , mnemonic_password_(std::move(mnemonic_password_))
  , exported_key_(std::move(exported_key_))
{}

const std::int32_t importKey::ID;

object_ptr<importKey> importKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<importKey> res = make_object<importKey>();
  res->local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->local_password_fieldID));
  res->mnemonic_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->mnemonic_password_fieldID));
  res->exported_key_ = td::jni::fetch_tl_object<exportedKey>(env, td::jni::fetch_object(env, p, res->exported_key_fieldID));;
  return res;
}

void importKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, local_password_); if (nextBytes) { env->SetObjectField(s, local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, mnemonic_password_); if (nextBytes) { env->SetObjectField(s, mnemonic_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (exported_key_ != nullptr) { jobject next; exported_key_->store(env, next); if (next) { env->SetObjectField(s, exported_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void importKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ImportKey");
    s.store_bytes_field("localPassword", local_password_);
    s.store_bytes_field("mnemonicPassword", mnemonic_password_);
    if (exported_key_ == nullptr) { s.store_field("exportedKey", "null"); } else { exported_key_->store(s, "exportedKey"); }
    s.store_class_end();
  }
}

importKey::ReturnType importKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return key::fetch(env, p);
}

void importKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ImportKey").c_str());
  local_password_fieldID = td::jni::get_field_id(env, Class, "localPassword", "[B");
  mnemonic_password_fieldID = td::jni::get_field_id(env, Class, "mnemonicPassword", "[B");
  exported_key_fieldID = td::jni::get_field_id(env, Class, "exportedKey", (PSLICE() << "L" << package_name << "/TonApi$ExportedKey;").c_str());
}

jclass importPemKey::Class;
jfieldID importPemKey::local_password_fieldID;
jfieldID importPemKey::key_password_fieldID;
jfieldID importPemKey::exported_key_fieldID;

importPemKey::importPemKey()
  : local_password_()
  , key_password_()
  , exported_key_()
{}

importPemKey::importPemKey(td::SecureString &&local_password_, td::SecureString &&key_password_, object_ptr<exportedPemKey> &&exported_key_)
  : local_password_(std::move(local_password_))
  , key_password_(std::move(key_password_))
  , exported_key_(std::move(exported_key_))
{}

const std::int32_t importPemKey::ID;

object_ptr<importPemKey> importPemKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<importPemKey> res = make_object<importPemKey>();
  res->local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->local_password_fieldID));
  res->key_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->key_password_fieldID));
  res->exported_key_ = td::jni::fetch_tl_object<exportedPemKey>(env, td::jni::fetch_object(env, p, res->exported_key_fieldID));;
  return res;
}

void importPemKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, local_password_); if (nextBytes) { env->SetObjectField(s, local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, key_password_); if (nextBytes) { env->SetObjectField(s, key_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (exported_key_ != nullptr) { jobject next; exported_key_->store(env, next); if (next) { env->SetObjectField(s, exported_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void importPemKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ImportPemKey");
    s.store_bytes_field("localPassword", local_password_);
    s.store_bytes_field("keyPassword", key_password_);
    if (exported_key_ == nullptr) { s.store_field("exportedKey", "null"); } else { exported_key_->store(s, "exportedKey"); }
    s.store_class_end();
  }
}

importPemKey::ReturnType importPemKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return key::fetch(env, p);
}

void importPemKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ImportPemKey").c_str());
  local_password_fieldID = td::jni::get_field_id(env, Class, "localPassword", "[B");
  key_password_fieldID = td::jni::get_field_id(env, Class, "keyPassword", "[B");
  exported_key_fieldID = td::jni::get_field_id(env, Class, "exportedKey", (PSLICE() << "L" << package_name << "/TonApi$ExportedPemKey;").c_str());
}

jclass init::Class;
jfieldID init::options_fieldID;

init::init()
  : options_()
{}

init::init(object_ptr<options> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t init::ID;

object_ptr<init> init::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<init> res = make_object<init>();
  res->options_ = td::jni::fetch_tl_object<options>(env, td::jni::fetch_object(env, p, res->options_fieldID));;
  return res;
}

void init::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (options_ != nullptr) { jobject next; options_->store(env, next); if (next) { env->SetObjectField(s, options_fieldID, next); env->DeleteLocalRef(next); } }
}

void init::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Init");
    if (options_ == nullptr) { s.store_field("options", "null"); } else { options_->store(s, "options"); }
    s.store_class_end();
  }
}

init::ReturnType init::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void init::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Init").c_str());
  options_fieldID = td::jni::get_field_id(env, Class, "options", (PSLICE() << "L" << package_name << "/TonApi$Options;").c_str());
}

jclass kdf::Class;
jfieldID kdf::password_fieldID;
jfieldID kdf::salt_fieldID;
jfieldID kdf::iterations_fieldID;

kdf::kdf()
  : password_()
  , salt_()
  , iterations_()
{}

kdf::kdf(td::SecureString &&password_, td::SecureString &&salt_, std::int32_t iterations_)
  : password_(std::move(password_))
  , salt_(std::move(salt_))
  , iterations_(iterations_)
{}

const std::int32_t kdf::ID;

object_ptr<kdf> kdf::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<kdf> res = make_object<kdf>();
  res->password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->password_fieldID));
  res->salt_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->salt_fieldID));
  res->iterations_ = env->GetIntField(p, res->iterations_fieldID);
  return res;
}

void kdf::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, password_); if (nextBytes) { env->SetObjectField(s, password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, salt_); if (nextBytes) { env->SetObjectField(s, salt_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  env->SetIntField(s, iterations_fieldID, iterations_);
}

void kdf::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Kdf");
    s.store_bytes_field("password", password_);
    s.store_bytes_field("salt", salt_);
    s.store_field("iterations", iterations_);
    s.store_class_end();
  }
}

kdf::ReturnType kdf::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return data::fetch(env, p);
}

void kdf::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Kdf").c_str());
  password_fieldID = td::jni::get_field_id(env, Class, "password", "[B");
  salt_fieldID = td::jni::get_field_id(env, Class, "salt", "[B");
  iterations_fieldID = td::jni::get_field_id(env, Class, "iterations", "I");
}

jclass liteServer_getInfo::Class;

liteServer_getInfo::liteServer_getInfo() {
}

const std::int32_t liteServer_getInfo::ID;

object_ptr<liteServer_getInfo> liteServer_getInfo::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<liteServer_getInfo> res = make_object<liteServer_getInfo>();
  return res;
}

void liteServer_getInfo::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void liteServer_getInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "LiteServerGetInfo");
    s.store_class_end();
  }
}

liteServer_getInfo::ReturnType liteServer_getInfo::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return liteServer_info::fetch(env, p);
}

void liteServer_getInfo::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$LiteServerGetInfo").c_str());
}

jclass onLiteServerQueryError::Class;
jfieldID onLiteServerQueryError::id_fieldID;
jfieldID onLiteServerQueryError::error_fieldID;

onLiteServerQueryError::onLiteServerQueryError()
  : id_()
  , error_()
{}

onLiteServerQueryError::onLiteServerQueryError(std::int64_t id_, object_ptr<error> &&error_)
  : id_(id_)
  , error_(std::move(error_))
{}

const std::int32_t onLiteServerQueryError::ID;

object_ptr<onLiteServerQueryError> onLiteServerQueryError::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<onLiteServerQueryError> res = make_object<onLiteServerQueryError>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->error_ = td::jni::fetch_tl_object<error>(env, td::jni::fetch_object(env, p, res->error_fieldID));;
  return res;
}

void onLiteServerQueryError::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  if (error_ != nullptr) { jobject next; error_->store(env, next); if (next) { env->SetObjectField(s, error_fieldID, next); env->DeleteLocalRef(next); } }
}

void onLiteServerQueryError::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OnLiteServerQueryError");
    s.store_field("id", id_);
    if (error_ == nullptr) { s.store_field("error", "null"); } else { error_->store(s, "error"); }
    s.store_class_end();
  }
}

onLiteServerQueryError::ReturnType onLiteServerQueryError::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void onLiteServerQueryError::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OnLiteServerQueryError").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  error_fieldID = td::jni::get_field_id(env, Class, "error", (PSLICE() << "L" << package_name << "/TonApi$Error;").c_str());
}

jclass onLiteServerQueryResult::Class;
jfieldID onLiteServerQueryResult::id_fieldID;
jfieldID onLiteServerQueryResult::bytes_fieldID;

onLiteServerQueryResult::onLiteServerQueryResult()
  : id_()
  , bytes_()
{}

onLiteServerQueryResult::onLiteServerQueryResult(std::int64_t id_, std::string const &bytes_)
  : id_(id_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t onLiteServerQueryResult::ID;

object_ptr<onLiteServerQueryResult> onLiteServerQueryResult::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<onLiteServerQueryResult> res = make_object<onLiteServerQueryResult>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->bytes_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->bytes_fieldID));
  return res;
}

void onLiteServerQueryResult::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, bytes_); if (nextBytes) { env->SetObjectField(s, bytes_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void onLiteServerQueryResult::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OnLiteServerQueryResult");
    s.store_field("id", id_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

onLiteServerQueryResult::ReturnType onLiteServerQueryResult::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void onLiteServerQueryResult::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OnLiteServerQueryResult").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "[B");
}

jclass options_setConfig::Class;
jfieldID options_setConfig::config_fieldID;

options_setConfig::options_setConfig()
  : config_()
{}

options_setConfig::options_setConfig(object_ptr<config> &&config_)
  : config_(std::move(config_))
{}

const std::int32_t options_setConfig::ID;

object_ptr<options_setConfig> options_setConfig::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<options_setConfig> res = make_object<options_setConfig>();
  res->config_ = td::jni::fetch_tl_object<config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  return res;
}

void options_setConfig::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
}

void options_setConfig::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OptionsSetConfig");
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    s.store_class_end();
  }
}

options_setConfig::ReturnType options_setConfig::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void options_setConfig::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OptionsSetConfig").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$Config;").c_str());
}

jclass options_validateConfig::Class;
jfieldID options_validateConfig::config_fieldID;

options_validateConfig::options_validateConfig()
  : config_()
{}

options_validateConfig::options_validateConfig(object_ptr<config> &&config_)
  : config_(std::move(config_))
{}

const std::int32_t options_validateConfig::ID;

object_ptr<options_validateConfig> options_validateConfig::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<options_validateConfig> res = make_object<options_validateConfig>();
  res->config_ = td::jni::fetch_tl_object<config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  return res;
}

void options_validateConfig::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
}

void options_validateConfig::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OptionsValidateConfig");
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    s.store_class_end();
  }
}

options_validateConfig::ReturnType options_validateConfig::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return options_configInfo::fetch(env, p);
}

void options_validateConfig::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OptionsValidateConfig").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$Config;").c_str());
}

jclass packAccountAddress::Class;
jfieldID packAccountAddress::account_address_fieldID;

packAccountAddress::packAccountAddress()
  : account_address_()
{}

packAccountAddress::packAccountAddress(object_ptr<unpackedAccountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t packAccountAddress::ID;

object_ptr<packAccountAddress> packAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<packAccountAddress> res = make_object<packAccountAddress>();
  res->account_address_ = td::jni::fetch_tl_object<unpackedAccountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void packAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void packAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PackAccountAddress");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

packAccountAddress::ReturnType packAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void packAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PackAccountAddress").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$UnpackedAccountAddress;").c_str());
}

jclass query_estimateFees::Class;
jfieldID query_estimateFees::id_fieldID;
jfieldID query_estimateFees::ignore_chksig_fieldID;

query_estimateFees::query_estimateFees()
  : id_()
  , ignore_chksig_()
{}

query_estimateFees::query_estimateFees(std::int64_t id_, bool ignore_chksig_)
  : id_(id_)
  , ignore_chksig_(ignore_chksig_)
{}

const std::int32_t query_estimateFees::ID;

object_ptr<query_estimateFees> query_estimateFees::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_estimateFees> res = make_object<query_estimateFees>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->ignore_chksig_ = (env->GetBooleanField(p, res->ignore_chksig_fieldID) != 0);
  return res;
}

void query_estimateFees::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  env->SetBooleanField(s, ignore_chksig_fieldID, ignore_chksig_);
}

void query_estimateFees::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryEstimateFees");
    s.store_field("id", id_);
    s.store_field("ignoreChksig", ignore_chksig_);
    s.store_class_end();
  }
}

query_estimateFees::ReturnType query_estimateFees::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return query_fees::fetch(env, p);
}

void query_estimateFees::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryEstimateFees").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  ignore_chksig_fieldID = td::jni::get_field_id(env, Class, "ignoreChksig", "Z");
}

jclass query_forget::Class;
jfieldID query_forget::id_fieldID;

query_forget::query_forget()
  : id_()
{}

query_forget::query_forget(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t query_forget::ID;

object_ptr<query_forget> query_forget::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_forget> res = make_object<query_forget>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void query_forget::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void query_forget::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryForget");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

query_forget::ReturnType query_forget::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void query_forget::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryForget").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass query_getInfo::Class;
jfieldID query_getInfo::id_fieldID;

query_getInfo::query_getInfo()
  : id_()
{}

query_getInfo::query_getInfo(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t query_getInfo::ID;

object_ptr<query_getInfo> query_getInfo::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_getInfo> res = make_object<query_getInfo>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void query_getInfo::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void query_getInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryGetInfo");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

query_getInfo::ReturnType query_getInfo::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return query_info::fetch(env, p);
}

void query_getInfo::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryGetInfo").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass query_send::Class;
jfieldID query_send::id_fieldID;

query_send::query_send()
  : id_()
{}

query_send::query_send(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t query_send::ID;

object_ptr<query_send> query_send::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_send> res = make_object<query_send>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void query_send::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void query_send::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QuerySend");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

query_send::ReturnType query_send::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void query_send::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QuerySend").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass raw_createAndSendMessage::Class;
jfieldID raw_createAndSendMessage::destination_fieldID;
jfieldID raw_createAndSendMessage::initial_account_state_fieldID;
jfieldID raw_createAndSendMessage::data_fieldID;

raw_createAndSendMessage::raw_createAndSendMessage()
  : destination_()
  , initial_account_state_()
  , data_()
{}

raw_createAndSendMessage::raw_createAndSendMessage(object_ptr<accountAddress> &&destination_, std::string const &initial_account_state_, std::string const &data_)
  : destination_(std::move(destination_))
  , initial_account_state_(std::move(initial_account_state_))
  , data_(std::move(data_))
{}

const std::int32_t raw_createAndSendMessage::ID;

object_ptr<raw_createAndSendMessage> raw_createAndSendMessage::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_createAndSendMessage> res = make_object<raw_createAndSendMessage>();
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->initial_account_state_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->initial_account_state_fieldID));
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return res;
}

void raw_createAndSendMessage::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, initial_account_state_); if (nextBytes) { env->SetObjectField(s, initial_account_state_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void raw_createAndSendMessage::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawCreateAndSendMessage");
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_bytes_field("initialAccountState", initial_account_state_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

raw_createAndSendMessage::ReturnType raw_createAndSendMessage::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void raw_createAndSendMessage::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawCreateAndSendMessage").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  initial_account_state_fieldID = td::jni::get_field_id(env, Class, "initialAccountState", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
}

jclass raw_createQuery::Class;
jfieldID raw_createQuery::destination_fieldID;
jfieldID raw_createQuery::init_code_fieldID;
jfieldID raw_createQuery::init_data_fieldID;
jfieldID raw_createQuery::body_fieldID;

raw_createQuery::raw_createQuery()
  : destination_()
  , init_code_()
  , init_data_()
  , body_()
{}

raw_createQuery::raw_createQuery(object_ptr<accountAddress> &&destination_, std::string const &init_code_, std::string const &init_data_, std::string const &body_)
  : destination_(std::move(destination_))
  , init_code_(std::move(init_code_))
  , init_data_(std::move(init_data_))
  , body_(std::move(body_))
{}

const std::int32_t raw_createQuery::ID;

object_ptr<raw_createQuery> raw_createQuery::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_createQuery> res = make_object<raw_createQuery>();
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->init_code_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->init_code_fieldID));
  res->init_data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->init_data_fieldID));
  res->body_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_fieldID));
  return res;
}

void raw_createQuery::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, init_code_); if (nextBytes) { env->SetObjectField(s, init_code_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, init_data_); if (nextBytes) { env->SetObjectField(s, init_data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_); if (nextBytes) { env->SetObjectField(s, body_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void raw_createQuery::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawCreateQuery");
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_bytes_field("initCode", init_code_);
    s.store_bytes_field("initData", init_data_);
    s.store_bytes_field("body", body_);
    s.store_class_end();
  }
}

raw_createQuery::ReturnType raw_createQuery::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return query_info::fetch(env, p);
}

void raw_createQuery::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawCreateQuery").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  init_code_fieldID = td::jni::get_field_id(env, Class, "initCode", "[B");
  init_data_fieldID = td::jni::get_field_id(env, Class, "initData", "[B");
  body_fieldID = td::jni::get_field_id(env, Class, "body", "[B");
}

jclass raw_getAccountAddress::Class;
jfieldID raw_getAccountAddress::initital_account_state_fieldID;

raw_getAccountAddress::raw_getAccountAddress()
  : initital_account_state_()
{}

raw_getAccountAddress::raw_getAccountAddress(object_ptr<raw_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t raw_getAccountAddress::ID;

object_ptr<raw_getAccountAddress> raw_getAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_getAccountAddress> res = make_object<raw_getAccountAddress>();
  res->initital_account_state_ = td::jni::fetch_tl_object<raw_initialAccountState>(env, td::jni::fetch_object(env, p, res->initital_account_state_fieldID));;
  return res;
}

void raw_getAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (initital_account_state_ != nullptr) { jobject next; initital_account_state_->store(env, next); if (next) { env->SetObjectField(s, initital_account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void raw_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawGetAccountAddress");
    if (initital_account_state_ == nullptr) { s.store_field("inititalAccountState", "null"); } else { initital_account_state_->store(s, "inititalAccountState"); }
    s.store_class_end();
  }
}

raw_getAccountAddress::ReturnType raw_getAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void raw_getAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawGetAccountAddress").c_str());
  initital_account_state_fieldID = td::jni::get_field_id(env, Class, "inititalAccountState", (PSLICE() << "L" << package_name << "/TonApi$RawInitialAccountState;").c_str());
}

jclass raw_getAccountState::Class;
jfieldID raw_getAccountState::account_address_fieldID;

raw_getAccountState::raw_getAccountState()
  : account_address_()
{}

raw_getAccountState::raw_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t raw_getAccountState::ID;

object_ptr<raw_getAccountState> raw_getAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_getAccountState> res = make_object<raw_getAccountState>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void raw_getAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void raw_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawGetAccountState");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

raw_getAccountState::ReturnType raw_getAccountState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return raw_accountState::fetch(env, p);
}

void raw_getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawGetAccountState").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass raw_getTransactions::Class;
jfieldID raw_getTransactions::account_address_fieldID;
jfieldID raw_getTransactions::from_transaction_id_fieldID;

raw_getTransactions::raw_getTransactions()
  : account_address_()
  , from_transaction_id_()
{}

raw_getTransactions::raw_getTransactions(object_ptr<accountAddress> &&account_address_, object_ptr<internal_transactionId> &&from_transaction_id_)
  : account_address_(std::move(account_address_))
  , from_transaction_id_(std::move(from_transaction_id_))
{}

const std::int32_t raw_getTransactions::ID;

object_ptr<raw_getTransactions> raw_getTransactions::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_getTransactions> res = make_object<raw_getTransactions>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  res->from_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->from_transaction_id_fieldID));;
  return res;
}

void raw_getTransactions::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
  if (from_transaction_id_ != nullptr) { jobject next; from_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, from_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
}

void raw_getTransactions::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawGetTransactions");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    if (from_transaction_id_ == nullptr) { s.store_field("fromTransactionId", "null"); } else { from_transaction_id_->store(s, "fromTransactionId"); }
    s.store_class_end();
  }
}

raw_getTransactions::ReturnType raw_getTransactions::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return raw_transactions::fetch(env, p);
}

void raw_getTransactions::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawGetTransactions").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  from_transaction_id_fieldID = td::jni::get_field_id(env, Class, "fromTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
}

jclass raw_sendMessage::Class;
jfieldID raw_sendMessage::body_fieldID;

raw_sendMessage::raw_sendMessage()
  : body_()
{}

raw_sendMessage::raw_sendMessage(std::string const &body_)
  : body_(std::move(body_))
{}

const std::int32_t raw_sendMessage::ID;

object_ptr<raw_sendMessage> raw_sendMessage::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_sendMessage> res = make_object<raw_sendMessage>();
  res->body_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_fieldID));
  return res;
}

void raw_sendMessage::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_); if (nextBytes) { env->SetObjectField(s, body_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void raw_sendMessage::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawSendMessage");
    s.store_bytes_field("body", body_);
    s.store_class_end();
  }
}

raw_sendMessage::ReturnType raw_sendMessage::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void raw_sendMessage::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawSendMessage").c_str());
  body_fieldID = td::jni::get_field_id(env, Class, "body", "[B");
}

jclass runTests::Class;
jfieldID runTests::dir_fieldID;

runTests::runTests()
  : dir_()
{}

runTests::runTests(std::string const &dir_)
  : dir_(std::move(dir_))
{}

const std::int32_t runTests::ID;

object_ptr<runTests> runTests::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<runTests> res = make_object<runTests>();
  res->dir_ = td::jni::fetch_string(env, p, res->dir_fieldID);
  return res;
}

void runTests::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, dir_); if (nextString) { env->SetObjectField(s, dir_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void runTests::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RunTests");
    s.store_field("dir", dir_);
    s.store_class_end();
  }
}

runTests::ReturnType runTests::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void runTests::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RunTests").c_str());
  dir_fieldID = td::jni::get_field_id(env, Class, "dir", "Ljava/lang/String;");
}

jclass setLogStream::Class;
jfieldID setLogStream::log_stream_fieldID;

setLogStream::setLogStream()
  : log_stream_()
{}

setLogStream::setLogStream(object_ptr<LogStream> &&log_stream_)
  : log_stream_(std::move(log_stream_))
{}

const std::int32_t setLogStream::ID;

object_ptr<setLogStream> setLogStream::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<setLogStream> res = make_object<setLogStream>();
  res->log_stream_ = td::jni::fetch_tl_object<LogStream>(env, td::jni::fetch_object(env, p, res->log_stream_fieldID));;
  return res;
}

void setLogStream::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (log_stream_ != nullptr) { jobject next; log_stream_->store(env, next); if (next) { env->SetObjectField(s, log_stream_fieldID, next); env->DeleteLocalRef(next); } }
}

void setLogStream::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SetLogStream");
    if (log_stream_ == nullptr) { s.store_field("logStream", "null"); } else { log_stream_->store(s, "logStream"); }
    s.store_class_end();
  }
}

setLogStream::ReturnType setLogStream::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void setLogStream::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SetLogStream").c_str());
  log_stream_fieldID = td::jni::get_field_id(env, Class, "logStream", (PSLICE() << "L" << package_name << "/TonApi$LogStream;").c_str());
}

jclass setLogTagVerbosityLevel::Class;
jfieldID setLogTagVerbosityLevel::tag_fieldID;
jfieldID setLogTagVerbosityLevel::new_verbosity_level_fieldID;

setLogTagVerbosityLevel::setLogTagVerbosityLevel()
  : tag_()
  , new_verbosity_level_()
{}

setLogTagVerbosityLevel::setLogTagVerbosityLevel(std::string const &tag_, std::int32_t new_verbosity_level_)
  : tag_(std::move(tag_))
  , new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogTagVerbosityLevel::ID;

object_ptr<setLogTagVerbosityLevel> setLogTagVerbosityLevel::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<setLogTagVerbosityLevel> res = make_object<setLogTagVerbosityLevel>();
  res->tag_ = td::jni::fetch_string(env, p, res->tag_fieldID);
  res->new_verbosity_level_ = env->GetIntField(p, res->new_verbosity_level_fieldID);
  return res;
}

void setLogTagVerbosityLevel::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, tag_); if (nextString) { env->SetObjectField(s, tag_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetIntField(s, new_verbosity_level_fieldID, new_verbosity_level_);
}

void setLogTagVerbosityLevel::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SetLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_field("newVerbosityLevel", new_verbosity_level_);
    s.store_class_end();
  }
}

setLogTagVerbosityLevel::ReturnType setLogTagVerbosityLevel::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void setLogTagVerbosityLevel::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SetLogTagVerbosityLevel").c_str());
  tag_fieldID = td::jni::get_field_id(env, Class, "tag", "Ljava/lang/String;");
  new_verbosity_level_fieldID = td::jni::get_field_id(env, Class, "newVerbosityLevel", "I");
}

jclass setLogVerbosityLevel::Class;
jfieldID setLogVerbosityLevel::new_verbosity_level_fieldID;

setLogVerbosityLevel::setLogVerbosityLevel()
  : new_verbosity_level_()
{}

setLogVerbosityLevel::setLogVerbosityLevel(std::int32_t new_verbosity_level_)
  : new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogVerbosityLevel::ID;

object_ptr<setLogVerbosityLevel> setLogVerbosityLevel::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<setLogVerbosityLevel> res = make_object<setLogVerbosityLevel>();
  res->new_verbosity_level_ = env->GetIntField(p, res->new_verbosity_level_fieldID);
  return res;
}

void setLogVerbosityLevel::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, new_verbosity_level_fieldID, new_verbosity_level_);
}

void setLogVerbosityLevel::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SetLogVerbosityLevel");
    s.store_field("newVerbosityLevel", new_verbosity_level_);
    s.store_class_end();
  }
}

setLogVerbosityLevel::ReturnType setLogVerbosityLevel::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void setLogVerbosityLevel::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SetLogVerbosityLevel").c_str());
  new_verbosity_level_fieldID = td::jni::get_field_id(env, Class, "newVerbosityLevel", "I");
}

jclass smc_getCode::Class;
jfieldID smc_getCode::id_fieldID;

smc_getCode::smc_getCode()
  : id_()
{}

smc_getCode::smc_getCode(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t smc_getCode::ID;

object_ptr<smc_getCode> smc_getCode::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_getCode> res = make_object<smc_getCode>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void smc_getCode::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void smc_getCode::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcGetCode");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

smc_getCode::ReturnType smc_getCode::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return tvm_cell::fetch(env, p);
}

void smc_getCode::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcGetCode").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass smc_getData::Class;
jfieldID smc_getData::id_fieldID;

smc_getData::smc_getData()
  : id_()
{}

smc_getData::smc_getData(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t smc_getData::ID;

object_ptr<smc_getData> smc_getData::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_getData> res = make_object<smc_getData>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void smc_getData::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void smc_getData::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcGetData");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

smc_getData::ReturnType smc_getData::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return tvm_cell::fetch(env, p);
}

void smc_getData::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcGetData").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass smc_getState::Class;
jfieldID smc_getState::id_fieldID;

smc_getState::smc_getState()
  : id_()
{}

smc_getState::smc_getState(std::int64_t id_)
  : id_(id_)
{}

const std::int32_t smc_getState::ID;

object_ptr<smc_getState> smc_getState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_getState> res = make_object<smc_getState>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  return res;
}

void smc_getState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
}

void smc_getState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcGetState");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

smc_getState::ReturnType smc_getState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return tvm_cell::fetch(env, p);
}

void smc_getState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcGetState").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
}

jclass smc_load::Class;
jfieldID smc_load::account_address_fieldID;

smc_load::smc_load()
  : account_address_()
{}

smc_load::smc_load(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t smc_load::ID;

object_ptr<smc_load> smc_load::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_load> res = make_object<smc_load>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void smc_load::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void smc_load::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcLoad");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

smc_load::ReturnType smc_load::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return smc_info::fetch(env, p);
}

void smc_load::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcLoad").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass smc_runGetMethod::Class;
jfieldID smc_runGetMethod::id_fieldID;
jfieldID smc_runGetMethod::method_fieldID;
jfieldID smc_runGetMethod::stack_fieldID;

smc_runGetMethod::smc_runGetMethod()
  : id_()
  , method_()
  , stack_()
{}

smc_runGetMethod::smc_runGetMethod(std::int64_t id_, object_ptr<smc_MethodId> &&method_, std::vector<object_ptr<tvm_StackEntry>> &&stack_)
  : id_(id_)
  , method_(std::move(method_))
  , stack_(std::move(stack_))
{}

const std::int32_t smc_runGetMethod::ID;

object_ptr<smc_runGetMethod> smc_runGetMethod::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<smc_runGetMethod> res = make_object<smc_runGetMethod>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->method_ = td::jni::fetch_tl_object<smc_MethodId>(env, td::jni::fetch_object(env, p, res->method_fieldID));;
  res->stack_ = td::jni::FetchVector<tvm_StackEntry>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->stack_fieldID));;
  return res;
}

void smc_runGetMethod::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  if (method_ != nullptr) { jobject next; method_->store(env, next); if (next) { env->SetObjectField(s, method_fieldID, next); env->DeleteLocalRef(next); } }
  { auto arr_tmp_ = td::jni::store_vector(env, stack_); if (arr_tmp_) { env->SetObjectField(s, stack_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void smc_runGetMethod::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "SmcRunGetMethod");
    s.store_field("id", id_);
    if (method_ == nullptr) { s.store_field("method", "null"); } else { method_->store(s, "method"); }
    { const std::vector<object_ptr<tvm_StackEntry>> &v = stack_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("stack", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

smc_runGetMethod::ReturnType smc_runGetMethod::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return smc_runResult::fetch(env, p);
}

void smc_runGetMethod::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$SmcRunGetMethod").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  method_fieldID = td::jni::get_field_id(env, Class, "method", (PSLICE() << "L" << package_name << "/TonApi$SmcMethodId;").c_str());
  stack_fieldID = td::jni::get_field_id(env, Class, "stack", (PSLICE() << "[L" << package_name << "/TonApi$TvmStackEntry;").c_str());
}

jclass sync::Class;

sync::sync() {
}

const std::int32_t sync::ID;

object_ptr<sync> sync::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<sync> res = make_object<sync>();
  return res;
}

void sync::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void sync::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "Sync");
    s.store_class_end();
  }
}

sync::ReturnType sync::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void sync::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Sync").c_str());
}

jclass testGiver_getAccountAddress::Class;

testGiver_getAccountAddress::testGiver_getAccountAddress() {
}

const std::int32_t testGiver_getAccountAddress::ID;

object_ptr<testGiver_getAccountAddress> testGiver_getAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testGiver_getAccountAddress> res = make_object<testGiver_getAccountAddress>();
  return res;
}

void testGiver_getAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void testGiver_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestGiverGetAccountAddress");
    s.store_class_end();
  }
}

testGiver_getAccountAddress::ReturnType testGiver_getAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void testGiver_getAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestGiverGetAccountAddress").c_str());
}

jclass testGiver_getAccountState::Class;

testGiver_getAccountState::testGiver_getAccountState() {
}

const std::int32_t testGiver_getAccountState::ID;

object_ptr<testGiver_getAccountState> testGiver_getAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testGiver_getAccountState> res = make_object<testGiver_getAccountState>();
  return res;
}

void testGiver_getAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void testGiver_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestGiverGetAccountState");
    s.store_class_end();
  }
}

testGiver_getAccountState::ReturnType testGiver_getAccountState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return testGiver_accountState::fetch(env, p);
}

void testGiver_getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestGiverGetAccountState").c_str());
}

jclass testGiver_sendGrams::Class;
jfieldID testGiver_sendGrams::destination_fieldID;
jfieldID testGiver_sendGrams::seqno_fieldID;
jfieldID testGiver_sendGrams::amount_fieldID;
jfieldID testGiver_sendGrams::message_fieldID;

testGiver_sendGrams::testGiver_sendGrams()
  : destination_()
  , seqno_()
  , amount_()
  , message_()
{}

testGiver_sendGrams::testGiver_sendGrams(object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t amount_, std::string const &message_)
  : destination_(std::move(destination_))
  , seqno_(seqno_)
  , amount_(amount_)
  , message_(std::move(message_))
{}

const std::int32_t testGiver_sendGrams::ID;

object_ptr<testGiver_sendGrams> testGiver_sendGrams::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testGiver_sendGrams> res = make_object<testGiver_sendGrams>();
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->amount_ = env->GetLongField(p, res->amount_fieldID);
  res->message_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->message_fieldID));
  return res;
}

void testGiver_sendGrams::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, seqno_fieldID, seqno_);
  env->SetLongField(s, amount_fieldID, amount_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, message_); if (nextBytes) { env->SetObjectField(s, message_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void testGiver_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestGiverSendGrams");
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("seqno", seqno_);
    s.store_field("amount", amount_);
    s.store_bytes_field("message", message_);
    s.store_class_end();
  }
}

testGiver_sendGrams::ReturnType testGiver_sendGrams::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return sendGramsResult::fetch(env, p);
}

void testGiver_sendGrams::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestGiverSendGrams").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  amount_fieldID = td::jni::get_field_id(env, Class, "amount", "J");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "[B");
}

jclass testWallet_getAccountAddress::Class;
jfieldID testWallet_getAccountAddress::initital_account_state_fieldID;

testWallet_getAccountAddress::testWallet_getAccountAddress()
  : initital_account_state_()
{}

testWallet_getAccountAddress::testWallet_getAccountAddress(object_ptr<testWallet_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t testWallet_getAccountAddress::ID;

object_ptr<testWallet_getAccountAddress> testWallet_getAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testWallet_getAccountAddress> res = make_object<testWallet_getAccountAddress>();
  res->initital_account_state_ = td::jni::fetch_tl_object<testWallet_initialAccountState>(env, td::jni::fetch_object(env, p, res->initital_account_state_fieldID));;
  return res;
}

void testWallet_getAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (initital_account_state_ != nullptr) { jobject next; initital_account_state_->store(env, next); if (next) { env->SetObjectField(s, initital_account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void testWallet_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestWalletGetAccountAddress");
    if (initital_account_state_ == nullptr) { s.store_field("inititalAccountState", "null"); } else { initital_account_state_->store(s, "inititalAccountState"); }
    s.store_class_end();
  }
}

testWallet_getAccountAddress::ReturnType testWallet_getAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void testWallet_getAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestWalletGetAccountAddress").c_str());
  initital_account_state_fieldID = td::jni::get_field_id(env, Class, "inititalAccountState", (PSLICE() << "L" << package_name << "/TonApi$TestWalletInitialAccountState;").c_str());
}

jclass testWallet_getAccountState::Class;
jfieldID testWallet_getAccountState::account_address_fieldID;

testWallet_getAccountState::testWallet_getAccountState()
  : account_address_()
{}

testWallet_getAccountState::testWallet_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t testWallet_getAccountState::ID;

object_ptr<testWallet_getAccountState> testWallet_getAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testWallet_getAccountState> res = make_object<testWallet_getAccountState>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void testWallet_getAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void testWallet_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestWalletGetAccountState");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

testWallet_getAccountState::ReturnType testWallet_getAccountState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return testWallet_accountState::fetch(env, p);
}

void testWallet_getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestWalletGetAccountState").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass testWallet_init::Class;
jfieldID testWallet_init::private_key_fieldID;

testWallet_init::testWallet_init()
  : private_key_()
{}

testWallet_init::testWallet_init(object_ptr<InputKey> &&private_key_)
  : private_key_(std::move(private_key_))
{}

const std::int32_t testWallet_init::ID;

object_ptr<testWallet_init> testWallet_init::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testWallet_init> res = make_object<testWallet_init>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  return res;
}

void testWallet_init::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void testWallet_init::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestWalletInit");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    s.store_class_end();
  }
}

testWallet_init::ReturnType testWallet_init::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void testWallet_init::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestWalletInit").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
}

jclass testWallet_sendGrams::Class;
jfieldID testWallet_sendGrams::private_key_fieldID;
jfieldID testWallet_sendGrams::destination_fieldID;
jfieldID testWallet_sendGrams::seqno_fieldID;
jfieldID testWallet_sendGrams::amount_fieldID;
jfieldID testWallet_sendGrams::message_fieldID;

testWallet_sendGrams::testWallet_sendGrams()
  : private_key_()
  , destination_()
  , seqno_()
  , amount_()
  , message_()
{}

testWallet_sendGrams::testWallet_sendGrams(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t amount_, std::string const &message_)
  : private_key_(std::move(private_key_))
  , destination_(std::move(destination_))
  , seqno_(seqno_)
  , amount_(amount_)
  , message_(std::move(message_))
{}

const std::int32_t testWallet_sendGrams::ID;

object_ptr<testWallet_sendGrams> testWallet_sendGrams::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<testWallet_sendGrams> res = make_object<testWallet_sendGrams>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->amount_ = env->GetLongField(p, res->amount_fieldID);
  res->message_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->message_fieldID));
  return res;
}

void testWallet_sendGrams::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, seqno_fieldID, seqno_);
  env->SetLongField(s, amount_fieldID, amount_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, message_); if (nextBytes) { env->SetObjectField(s, message_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void testWallet_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TestWalletSendGrams");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("seqno", seqno_);
    s.store_field("amount", amount_);
    s.store_bytes_field("message", message_);
    s.store_class_end();
  }
}

testWallet_sendGrams::ReturnType testWallet_sendGrams::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return sendGramsResult::fetch(env, p);
}

void testWallet_sendGrams::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TestWalletSendGrams").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  amount_fieldID = td::jni::get_field_id(env, Class, "amount", "J");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "[B");
}

jclass unpackAccountAddress::Class;
jfieldID unpackAccountAddress::account_address_fieldID;

unpackAccountAddress::unpackAccountAddress()
  : account_address_()
{}

unpackAccountAddress::unpackAccountAddress(std::string const &account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t unpackAccountAddress::ID;

object_ptr<unpackAccountAddress> unpackAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<unpackAccountAddress> res = make_object<unpackAccountAddress>();
  res->account_address_ = td::jni::fetch_string(env, p, res->account_address_fieldID);
  return res;
}

void unpackAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, account_address_); if (nextString) { env->SetObjectField(s, account_address_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void unpackAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "UnpackAccountAddress");
    s.store_field("accountAddress", account_address_);
    s.store_class_end();
  }
}

unpackAccountAddress::ReturnType unpackAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return unpackedAccountAddress::fetch(env, p);
}

void unpackAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$UnpackAccountAddress").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", "Ljava/lang/String;");
}

jclass wallet_getAccountAddress::Class;
jfieldID wallet_getAccountAddress::initital_account_state_fieldID;

wallet_getAccountAddress::wallet_getAccountAddress()
  : initital_account_state_()
{}

wallet_getAccountAddress::wallet_getAccountAddress(object_ptr<wallet_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t wallet_getAccountAddress::ID;

object_ptr<wallet_getAccountAddress> wallet_getAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_getAccountAddress> res = make_object<wallet_getAccountAddress>();
  res->initital_account_state_ = td::jni::fetch_tl_object<wallet_initialAccountState>(env, td::jni::fetch_object(env, p, res->initital_account_state_fieldID));;
  return res;
}

void wallet_getAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (initital_account_state_ != nullptr) { jobject next; initital_account_state_->store(env, next); if (next) { env->SetObjectField(s, initital_account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void wallet_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletGetAccountAddress");
    if (initital_account_state_ == nullptr) { s.store_field("inititalAccountState", "null"); } else { initital_account_state_->store(s, "inititalAccountState"); }
    s.store_class_end();
  }
}

wallet_getAccountAddress::ReturnType wallet_getAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void wallet_getAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletGetAccountAddress").c_str());
  initital_account_state_fieldID = td::jni::get_field_id(env, Class, "inititalAccountState", (PSLICE() << "L" << package_name << "/TonApi$WalletInitialAccountState;").c_str());
}

jclass wallet_getAccountState::Class;
jfieldID wallet_getAccountState::account_address_fieldID;

wallet_getAccountState::wallet_getAccountState()
  : account_address_()
{}

wallet_getAccountState::wallet_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t wallet_getAccountState::ID;

object_ptr<wallet_getAccountState> wallet_getAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_getAccountState> res = make_object<wallet_getAccountState>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void wallet_getAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void wallet_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletGetAccountState");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

wallet_getAccountState::ReturnType wallet_getAccountState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return wallet_accountState::fetch(env, p);
}

void wallet_getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletGetAccountState").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass wallet_init::Class;
jfieldID wallet_init::private_key_fieldID;

wallet_init::wallet_init()
  : private_key_()
{}

wallet_init::wallet_init(object_ptr<InputKey> &&private_key_)
  : private_key_(std::move(private_key_))
{}

const std::int32_t wallet_init::ID;

object_ptr<wallet_init> wallet_init::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_init> res = make_object<wallet_init>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  return res;
}

void wallet_init::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void wallet_init::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletInit");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    s.store_class_end();
  }
}

wallet_init::ReturnType wallet_init::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void wallet_init::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletInit").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
}

jclass wallet_sendGrams::Class;
jfieldID wallet_sendGrams::private_key_fieldID;
jfieldID wallet_sendGrams::destination_fieldID;
jfieldID wallet_sendGrams::seqno_fieldID;
jfieldID wallet_sendGrams::valid_until_fieldID;
jfieldID wallet_sendGrams::amount_fieldID;
jfieldID wallet_sendGrams::message_fieldID;

wallet_sendGrams::wallet_sendGrams()
  : private_key_()
  , destination_()
  , seqno_()
  , valid_until_()
  , amount_()
  , message_()
{}

wallet_sendGrams::wallet_sendGrams(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t valid_until_, std::int64_t amount_, std::string const &message_)
  : private_key_(std::move(private_key_))
  , destination_(std::move(destination_))
  , seqno_(seqno_)
  , valid_until_(valid_until_)
  , amount_(amount_)
  , message_(std::move(message_))
{}

const std::int32_t wallet_sendGrams::ID;

object_ptr<wallet_sendGrams> wallet_sendGrams::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_sendGrams> res = make_object<wallet_sendGrams>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->valid_until_ = env->GetLongField(p, res->valid_until_fieldID);
  res->amount_ = env->GetLongField(p, res->amount_fieldID);
  res->message_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->message_fieldID));
  return res;
}

void wallet_sendGrams::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, seqno_fieldID, seqno_);
  env->SetLongField(s, valid_until_fieldID, valid_until_);
  env->SetLongField(s, amount_fieldID, amount_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, message_); if (nextBytes) { env->SetObjectField(s, message_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void wallet_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletSendGrams");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("seqno", seqno_);
    s.store_field("validUntil", valid_until_);
    s.store_field("amount", amount_);
    s.store_bytes_field("message", message_);
    s.store_class_end();
  }
}

wallet_sendGrams::ReturnType wallet_sendGrams::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return sendGramsResult::fetch(env, p);
}

void wallet_sendGrams::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletSendGrams").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  valid_until_fieldID = td::jni::get_field_id(env, Class, "validUntil", "J");
  amount_fieldID = td::jni::get_field_id(env, Class, "amount", "J");
  message_fieldID = td::jni::get_field_id(env, Class, "message", "[B");
}

jclass wallet_v3_getAccountAddress::Class;
jfieldID wallet_v3_getAccountAddress::initital_account_state_fieldID;

wallet_v3_getAccountAddress::wallet_v3_getAccountAddress()
  : initital_account_state_()
{}

wallet_v3_getAccountAddress::wallet_v3_getAccountAddress(object_ptr<wallet_v3_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t wallet_v3_getAccountAddress::ID;

object_ptr<wallet_v3_getAccountAddress> wallet_v3_getAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_v3_getAccountAddress> res = make_object<wallet_v3_getAccountAddress>();
  res->initital_account_state_ = td::jni::fetch_tl_object<wallet_v3_initialAccountState>(env, td::jni::fetch_object(env, p, res->initital_account_state_fieldID));;
  return res;
}

void wallet_v3_getAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (initital_account_state_ != nullptr) { jobject next; initital_account_state_->store(env, next); if (next) { env->SetObjectField(s, initital_account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void wallet_v3_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletV3GetAccountAddress");
    if (initital_account_state_ == nullptr) { s.store_field("inititalAccountState", "null"); } else { initital_account_state_->store(s, "inititalAccountState"); }
    s.store_class_end();
  }
}

wallet_v3_getAccountAddress::ReturnType wallet_v3_getAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void wallet_v3_getAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletV3GetAccountAddress").c_str());
  initital_account_state_fieldID = td::jni::get_field_id(env, Class, "inititalAccountState", (PSLICE() << "L" << package_name << "/TonApi$WalletV3InitialAccountState;").c_str());
}
}  // namespace tonlib_api
}  // namespace ton
