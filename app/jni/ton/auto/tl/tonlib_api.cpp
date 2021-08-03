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
  return storer.move_as_str();
}

jclass Object::Class;

object_ptr<Object> Object::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case accountAddress::ID:
      return accountAddress::fetch(env, p);
    case accountList::ID:
      return accountList::fetch(env, p);
    case accountRevisionList::ID:
      return accountRevisionList::fetch(env, p);
    case raw_accountState::ID:
      return raw_accountState::fetch(env, p);
    case wallet_v3_accountState::ID:
      return wallet_v3_accountState::fetch(env, p);
    case wallet_highload_v1_accountState::ID:
      return wallet_highload_v1_accountState::fetch(env, p);
    case wallet_highload_v2_accountState::ID:
      return wallet_highload_v2_accountState::fetch(env, p);
    case dns_accountState::ID:
      return dns_accountState::fetch(env, p);
    case rwallet_accountState::ID:
      return rwallet_accountState::fetch(env, p);
    case pchan_accountState::ID:
      return pchan_accountState::fetch(env, p);
    case uninited_accountState::ID:
      return uninited_accountState::fetch(env, p);
    case actionNoop::ID:
      return actionNoop::fetch(env, p);
    case actionMsg::ID:
      return actionMsg::fetch(env, p);
    case actionDns::ID:
      return actionDns::fetch(env, p);
    case actionPchan::ID:
      return actionPchan::fetch(env, p);
    case actionRwallet::ID:
      return actionRwallet::fetch(env, p);
    case adnlAddress::ID:
      return adnlAddress::fetch(env, p);
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
    case exportedUnencryptedKey::ID:
      return exportedUnencryptedKey::fetch(env, p);
    case fees::ID:
      return fees::fetch(env, p);
    case fullAccountState::ID:
      return fullAccountState::fetch(env, p);
    case raw_initialAccountState::ID:
      return raw_initialAccountState::fetch(env, p);
    case wallet_v3_initialAccountState::ID:
      return wallet_v3_initialAccountState::fetch(env, p);
    case wallet_highload_v1_initialAccountState::ID:
      return wallet_highload_v1_initialAccountState::fetch(env, p);
    case wallet_highload_v2_initialAccountState::ID:
      return wallet_highload_v2_initialAccountState::fetch(env, p);
    case rwallet_initialAccountState::ID:
      return rwallet_initialAccountState::fetch(env, p);
    case dns_initialAccountState::ID:
      return dns_initialAccountState::fetch(env, p);
    case pchan_initialAccountState::ID:
      return pchan_initialAccountState::fetch(env, p);
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
    case dns_actionDeleteAll::ID:
      return dns_actionDeleteAll::fetch(env, p);
    case dns_actionDelete::ID:
      return dns_actionDelete::fetch(env, p);
    case dns_actionSet::ID:
      return dns_actionSet::fetch(env, p);
    case dns_entry::ID:
      return dns_entry::fetch(env, p);
    case dns_entryDataUnknown::ID:
      return dns_entryDataUnknown::fetch(env, p);
    case dns_entryDataText::ID:
      return dns_entryDataText::fetch(env, p);
    case dns_entryDataNextResolver::ID:
      return dns_entryDataNextResolver::fetch(env, p);
    case dns_entryDataSmcAddress::ID:
      return dns_entryDataSmcAddress::fetch(env, p);
    case dns_entryDataAdnlAddress::ID:
      return dns_entryDataAdnlAddress::fetch(env, p);
    case dns_resolved::ID:
      return dns_resolved::fetch(env, p);
    case ton_blockId::ID:
      return ton_blockId::fetch(env, p);
    case internal_transactionId::ID:
      return internal_transactionId::fetch(env, p);
    case liteServer_info::ID:
      return liteServer_info::fetch(env, p);
    case msg_dataRaw::ID:
      return msg_dataRaw::fetch(env, p);
    case msg_dataText::ID:
      return msg_dataText::fetch(env, p);
    case msg_dataDecryptedText::ID:
      return msg_dataDecryptedText::fetch(env, p);
    case msg_dataEncryptedText::ID:
      return msg_dataEncryptedText::fetch(env, p);
    case msg_dataDecrypted::ID:
      return msg_dataDecrypted::fetch(env, p);
    case msg_dataDecryptedArray::ID:
      return msg_dataDecryptedArray::fetch(env, p);
    case msg_dataEncrypted::ID:
      return msg_dataEncrypted::fetch(env, p);
    case msg_dataEncryptedArray::ID:
      return msg_dataEncryptedArray::fetch(env, p);
    case msg_message::ID:
      return msg_message::fetch(env, p);
    case options_configInfo::ID:
      return options_configInfo::fetch(env, p);
    case options_info::ID:
      return options_info::fetch(env, p);
    case pchan_actionInit::ID:
      return pchan_actionInit::fetch(env, p);
    case pchan_actionClose::ID:
      return pchan_actionClose::fetch(env, p);
    case pchan_actionTimeout::ID:
      return pchan_actionTimeout::fetch(env, p);
    case pchan_config::ID:
      return pchan_config::fetch(env, p);
    case pchan_promise::ID:
      return pchan_promise::fetch(env, p);
    case pchan_stateInit::ID:
      return pchan_stateInit::fetch(env, p);
    case pchan_stateClose::ID:
      return pchan_stateClose::fetch(env, p);
    case pchan_statePayout::ID:
      return pchan_statePayout::fetch(env, p);
    case query_fees::ID:
      return query_fees::fetch(env, p);
    case query_info::ID:
      return query_info::fetch(env, p);
    case raw_fullAccountState::ID:
      return raw_fullAccountState::fetch(env, p);
    case raw_message::ID:
      return raw_message::fetch(env, p);
    case raw_transaction::ID:
      return raw_transaction::fetch(env, p);
    case raw_transactions::ID:
      return raw_transactions::fetch(env, p);
    case rwallet_actionInit::ID:
      return rwallet_actionInit::fetch(env, p);
    case rwallet_config::ID:
      return rwallet_config::fetch(env, p);
    case rwallet_limit::ID:
      return rwallet_limit::fetch(env, p);
    case smc_info::ID:
      return smc_info::fetch(env, p);
    case smc_methodIdNumber::ID:
      return smc_methodIdNumber::fetch(env, p);
    case smc_methodIdName::ID:
      return smc_methodIdName::fetch(env, p);
    case smc_runResult::ID:
      return smc_runResult::fetch(env, p);
    case ton_blockIdExt::ID:
      return ton_blockIdExt::fetch(env, p);
    case tvm_cell::ID:
      return tvm_cell::fetch(env, p);
    case tvm_list::ID:
      return tvm_list::fetch(env, p);
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
    case tvm_stackEntryTuple::ID:
      return tvm_stackEntryTuple::fetch(env, p);
    case tvm_stackEntryList::ID:
      return tvm_stackEntryList::fetch(env, p);
    case tvm_stackEntryUnsupported::ID:
      return tvm_stackEntryUnsupported::fetch(env, p);
    case tvm_tuple::ID:
      return tvm_tuple::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void Object::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Object").c_str());
  accountAddress::init_jni_vars(env, package_name);
  accountList::init_jni_vars(env, package_name);
  accountRevisionList::init_jni_vars(env, package_name);
  AccountState::init_jni_vars(env, package_name);
  Action::init_jni_vars(env, package_name);
  adnlAddress::init_jni_vars(env, package_name);
  bip39Hints::init_jni_vars(env, package_name);
  config::init_jni_vars(env, package_name);
  data::init_jni_vars(env, package_name);
  error::init_jni_vars(env, package_name);
  exportedEncryptedKey::init_jni_vars(env, package_name);
  exportedKey::init_jni_vars(env, package_name);
  exportedPemKey::init_jni_vars(env, package_name);
  exportedUnencryptedKey::init_jni_vars(env, package_name);
  fees::init_jni_vars(env, package_name);
  fullAccountState::init_jni_vars(env, package_name);
  InitialAccountState::init_jni_vars(env, package_name);
  InputKey::init_jni_vars(env, package_name);
  key::init_jni_vars(env, package_name);
  KeyStoreType::init_jni_vars(env, package_name);
  LogStream::init_jni_vars(env, package_name);
  logTags::init_jni_vars(env, package_name);
  logVerbosityLevel::init_jni_vars(env, package_name);
  ok::init_jni_vars(env, package_name);
  options::init_jni_vars(env, package_name);
  SyncState::init_jni_vars(env, package_name);
  unpackedAccountAddress::init_jni_vars(env, package_name);
  Update::init_jni_vars(env, package_name);
  dns_Action::init_jni_vars(env, package_name);
  dns_entry::init_jni_vars(env, package_name);
  dns_EntryData::init_jni_vars(env, package_name);
  dns_resolved::init_jni_vars(env, package_name);
  ton_blockId::init_jni_vars(env, package_name);
  internal_transactionId::init_jni_vars(env, package_name);
  liteServer_info::init_jni_vars(env, package_name);
  msg_Data::init_jni_vars(env, package_name);
  msg_dataDecrypted::init_jni_vars(env, package_name);
  msg_dataDecryptedArray::init_jni_vars(env, package_name);
  msg_dataEncrypted::init_jni_vars(env, package_name);
  msg_dataEncryptedArray::init_jni_vars(env, package_name);
  msg_message::init_jni_vars(env, package_name);
  options_configInfo::init_jni_vars(env, package_name);
  options_info::init_jni_vars(env, package_name);
  pchan_Action::init_jni_vars(env, package_name);
  pchan_config::init_jni_vars(env, package_name);
  pchan_promise::init_jni_vars(env, package_name);
  pchan_State::init_jni_vars(env, package_name);
  query_fees::init_jni_vars(env, package_name);
  query_info::init_jni_vars(env, package_name);
  raw_fullAccountState::init_jni_vars(env, package_name);
  raw_message::init_jni_vars(env, package_name);
  raw_transaction::init_jni_vars(env, package_name);
  raw_transactions::init_jni_vars(env, package_name);
  rwallet_actionInit::init_jni_vars(env, package_name);
  rwallet_config::init_jni_vars(env, package_name);
  rwallet_limit::init_jni_vars(env, package_name);
  smc_info::init_jni_vars(env, package_name);
  smc_MethodId::init_jni_vars(env, package_name);
  smc_runResult::init_jni_vars(env, package_name);
  ton_blockIdExt::init_jni_vars(env, package_name);
  tvm_cell::init_jni_vars(env, package_name);
  tvm_list::init_jni_vars(env, package_name);
  tvm_numberDecimal::init_jni_vars(env, package_name);
  tvm_slice::init_jni_vars(env, package_name);
  tvm_StackEntry::init_jni_vars(env, package_name);
  tvm_tuple::init_jni_vars(env, package_name);
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
    case createQuery::ID:
      return createQuery::fetch(env, p);
    case decrypt::ID:
      return decrypt::fetch(env, p);
    case deleteAllKeys::ID:
      return deleteAllKeys::fetch(env, p);
    case deleteKey::ID:
      return deleteKey::fetch(env, p);
    case dns_resolve::ID:
      return dns_resolve::fetch(env, p);
    case encrypt::ID:
      return encrypt::fetch(env, p);
    case exportEncryptedKey::ID:
      return exportEncryptedKey::fetch(env, p);
    case exportKey::ID:
      return exportKey::fetch(env, p);
    case exportPemKey::ID:
      return exportPemKey::fetch(env, p);
    case exportUnencryptedKey::ID:
      return exportUnencryptedKey::fetch(env, p);
    case getAccountAddress::ID:
      return getAccountAddress::fetch(env, p);
    case getAccountState::ID:
      return getAccountState::fetch(env, p);
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
    case guessAccount::ID:
      return guessAccount::fetch(env, p);
    case guessAccountRevision::ID:
      return guessAccountRevision::fetch(env, p);
    case importEncryptedKey::ID:
      return importEncryptedKey::fetch(env, p);
    case importKey::ID:
      return importKey::fetch(env, p);
    case importPemKey::ID:
      return importPemKey::fetch(env, p);
    case importUnencryptedKey::ID:
      return importUnencryptedKey::fetch(env, p);
    case init::ID:
      return init::fetch(env, p);
    case kdf::ID:
      return kdf::fetch(env, p);
    case liteServer_getInfo::ID:
      return liteServer_getInfo::fetch(env, p);
    case msg_decrypt::ID:
      return msg_decrypt::fetch(env, p);
    case msg_decryptWithProof::ID:
      return msg_decryptWithProof::fetch(env, p);
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
    case pchan_packPromise::ID:
      return pchan_packPromise::fetch(env, p);
    case pchan_signPromise::ID:
      return pchan_signPromise::fetch(env, p);
    case pchan_unpackPromise::ID:
      return pchan_unpackPromise::fetch(env, p);
    case pchan_validatePromise::ID:
      return pchan_validatePromise::fetch(env, p);
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
    case unpackAccountAddress::ID:
      return unpackAccountAddress::fetch(env, p);
    case withBlock::ID:
      return withBlock::fetch(env, p);
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
  createQuery::init_jni_vars(env, package_name);
  decrypt::init_jni_vars(env, package_name);
  deleteAllKeys::init_jni_vars(env, package_name);
  deleteKey::init_jni_vars(env, package_name);
  dns_resolve::init_jni_vars(env, package_name);
  encrypt::init_jni_vars(env, package_name);
  exportEncryptedKey::init_jni_vars(env, package_name);
  exportKey::init_jni_vars(env, package_name);
  exportPemKey::init_jni_vars(env, package_name);
  exportUnencryptedKey::init_jni_vars(env, package_name);
  getAccountAddress::init_jni_vars(env, package_name);
  getAccountState::init_jni_vars(env, package_name);
  getBip39Hints::init_jni_vars(env, package_name);
  getLogStream::init_jni_vars(env, package_name);
  getLogTagVerbosityLevel::init_jni_vars(env, package_name);
  getLogTags::init_jni_vars(env, package_name);
  getLogVerbosityLevel::init_jni_vars(env, package_name);
  guessAccount::init_jni_vars(env, package_name);
  guessAccountRevision::init_jni_vars(env, package_name);
  importEncryptedKey::init_jni_vars(env, package_name);
  importKey::init_jni_vars(env, package_name);
  importPemKey::init_jni_vars(env, package_name);
  importUnencryptedKey::init_jni_vars(env, package_name);
  init::init_jni_vars(env, package_name);
  kdf::init_jni_vars(env, package_name);
  liteServer_getInfo::init_jni_vars(env, package_name);
  msg_decrypt::init_jni_vars(env, package_name);
  msg_decryptWithProof::init_jni_vars(env, package_name);
  onLiteServerQueryError::init_jni_vars(env, package_name);
  onLiteServerQueryResult::init_jni_vars(env, package_name);
  options_setConfig::init_jni_vars(env, package_name);
  options_validateConfig::init_jni_vars(env, package_name);
  packAccountAddress::init_jni_vars(env, package_name);
  pchan_packPromise::init_jni_vars(env, package_name);
  pchan_signPromise::init_jni_vars(env, package_name);
  pchan_unpackPromise::init_jni_vars(env, package_name);
  pchan_validatePromise::init_jni_vars(env, package_name);
  query_estimateFees::init_jni_vars(env, package_name);
  query_forget::init_jni_vars(env, package_name);
  query_getInfo::init_jni_vars(env, package_name);
  query_send::init_jni_vars(env, package_name);
  raw_createAndSendMessage::init_jni_vars(env, package_name);
  raw_createQuery::init_jni_vars(env, package_name);
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
  unpackAccountAddress::init_jni_vars(env, package_name);
  withBlock::init_jni_vars(env, package_name);
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

jclass accountList::Class;
jfieldID accountList::accounts_fieldID;

accountList::accountList()
  : accounts_()
{}

accountList::accountList(std::vector<object_ptr<fullAccountState>> &&accounts_)
  : accounts_(std::move(accounts_))
{}

const std::int32_t accountList::ID;

object_ptr<accountList> accountList::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<accountList> res = make_object<accountList>();
  res->accounts_ = td::jni::FetchVector<fullAccountState>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->accounts_fieldID));;
  return res;
}

void accountList::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, accounts_); if (arr_tmp_) { env->SetObjectField(s, accounts_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void accountList::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "AccountList");
    { const std::vector<object_ptr<fullAccountState>> &v = accounts_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("accounts", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void accountList::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$AccountList").c_str());
  accounts_fieldID = td::jni::get_field_id(env, Class, "accounts", (PSLICE() << "[L" << package_name << "/TonApi$FullAccountState;").c_str());
}

jclass accountRevisionList::Class;
jfieldID accountRevisionList::revisions_fieldID;

accountRevisionList::accountRevisionList()
  : revisions_()
{}

accountRevisionList::accountRevisionList(std::vector<object_ptr<fullAccountState>> &&revisions_)
  : revisions_(std::move(revisions_))
{}

const std::int32_t accountRevisionList::ID;

object_ptr<accountRevisionList> accountRevisionList::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<accountRevisionList> res = make_object<accountRevisionList>();
  res->revisions_ = td::jni::FetchVector<fullAccountState>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->revisions_fieldID));;
  return res;
}

void accountRevisionList::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, revisions_); if (arr_tmp_) { env->SetObjectField(s, revisions_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void accountRevisionList::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "AccountRevisionList");
    { const std::vector<object_ptr<fullAccountState>> &v = revisions_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("revisions", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void accountRevisionList::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$AccountRevisionList").c_str());
  revisions_fieldID = td::jni::get_field_id(env, Class, "revisions", (PSLICE() << "[L" << package_name << "/TonApi$FullAccountState;").c_str());
}

jclass AccountState::Class;

object_ptr<AccountState> AccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case raw_accountState::ID:
      return raw_accountState::fetch(env, p);
    case wallet_v3_accountState::ID:
      return wallet_v3_accountState::fetch(env, p);
    case wallet_highload_v1_accountState::ID:
      return wallet_highload_v1_accountState::fetch(env, p);
    case wallet_highload_v2_accountState::ID:
      return wallet_highload_v2_accountState::fetch(env, p);
    case dns_accountState::ID:
      return dns_accountState::fetch(env, p);
    case rwallet_accountState::ID:
      return rwallet_accountState::fetch(env, p);
    case pchan_accountState::ID:
      return pchan_accountState::fetch(env, p);
    case uninited_accountState::ID:
      return uninited_accountState::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void AccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$AccountState").c_str());
  raw_accountState::init_jni_vars(env, package_name);
  wallet_v3_accountState::init_jni_vars(env, package_name);
  wallet_highload_v1_accountState::init_jni_vars(env, package_name);
  wallet_highload_v2_accountState::init_jni_vars(env, package_name);
  dns_accountState::init_jni_vars(env, package_name);
  rwallet_accountState::init_jni_vars(env, package_name);
  pchan_accountState::init_jni_vars(env, package_name);
  uninited_accountState::init_jni_vars(env, package_name);
}

jclass raw_accountState::Class;
jfieldID raw_accountState::code_fieldID;
jfieldID raw_accountState::data_fieldID;
jfieldID raw_accountState::frozen_hash_fieldID;

raw_accountState::raw_accountState()
  : code_()
  , data_()
  , frozen_hash_()
{}

raw_accountState::raw_accountState(std::string const &code_, std::string const &data_, std::string const &frozen_hash_)
  : code_(std::move(code_))
  , data_(std::move(data_))
  , frozen_hash_(std::move(frozen_hash_))
{}

const std::int32_t raw_accountState::ID;

object_ptr<AccountState> raw_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_accountState> res = make_object<raw_accountState>();
  res->code_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->code_fieldID));
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  res->frozen_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->frozen_hash_fieldID));
  return std::move(res);
}

void raw_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, code_); if (nextBytes) { env->SetObjectField(s, code_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, frozen_hash_); if (nextBytes) { env->SetObjectField(s, frozen_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void raw_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawAccountState");
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    s.store_bytes_field("frozenHash", frozen_hash_);
    s.store_class_end();
  }
}

void raw_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawAccountState").c_str());
  code_fieldID = td::jni::get_field_id(env, Class, "code", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
  frozen_hash_fieldID = td::jni::get_field_id(env, Class, "frozenHash", "[B");
}

jclass wallet_v3_accountState::Class;
jfieldID wallet_v3_accountState::wallet_id_fieldID;
jfieldID wallet_v3_accountState::seqno_fieldID;

wallet_v3_accountState::wallet_v3_accountState()
  : wallet_id_()
  , seqno_()
{}

wallet_v3_accountState::wallet_v3_accountState(std::int64_t wallet_id_, std::int32_t seqno_)
  : wallet_id_(wallet_id_)
  , seqno_(seqno_)
{}

const std::int32_t wallet_v3_accountState::ID;

object_ptr<AccountState> wallet_v3_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_v3_accountState> res = make_object<wallet_v3_accountState>();
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  return std::move(res);
}

void wallet_v3_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
  env->SetIntField(s, seqno_fieldID, seqno_);
}

void wallet_v3_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletV3AccountState");
    s.store_field("walletId", wallet_id_);
    s.store_field("seqno", seqno_);
    s.store_class_end();
  }
}

void wallet_v3_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletV3AccountState").c_str());
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
}

jclass wallet_highload_v1_accountState::Class;
jfieldID wallet_highload_v1_accountState::wallet_id_fieldID;
jfieldID wallet_highload_v1_accountState::seqno_fieldID;

wallet_highload_v1_accountState::wallet_highload_v1_accountState()
  : wallet_id_()
  , seqno_()
{}

wallet_highload_v1_accountState::wallet_highload_v1_accountState(std::int64_t wallet_id_, std::int32_t seqno_)
  : wallet_id_(wallet_id_)
  , seqno_(seqno_)
{}

const std::int32_t wallet_highload_v1_accountState::ID;

object_ptr<AccountState> wallet_highload_v1_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_highload_v1_accountState> res = make_object<wallet_highload_v1_accountState>();
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  return std::move(res);
}

void wallet_highload_v1_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
  env->SetIntField(s, seqno_fieldID, seqno_);
}

void wallet_highload_v1_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletHighloadV1AccountState");
    s.store_field("walletId", wallet_id_);
    s.store_field("seqno", seqno_);
    s.store_class_end();
  }
}

void wallet_highload_v1_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletHighloadV1AccountState").c_str());
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
}

jclass wallet_highload_v2_accountState::Class;
jfieldID wallet_highload_v2_accountState::wallet_id_fieldID;

wallet_highload_v2_accountState::wallet_highload_v2_accountState()
  : wallet_id_()
{}

wallet_highload_v2_accountState::wallet_highload_v2_accountState(std::int64_t wallet_id_)
  : wallet_id_(wallet_id_)
{}

const std::int32_t wallet_highload_v2_accountState::ID;

object_ptr<AccountState> wallet_highload_v2_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_highload_v2_accountState> res = make_object<wallet_highload_v2_accountState>();
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
}

void wallet_highload_v2_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void wallet_highload_v2_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletHighloadV2AccountState");
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void wallet_highload_v2_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletHighloadV2AccountState").c_str());
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass dns_accountState::Class;
jfieldID dns_accountState::wallet_id_fieldID;

dns_accountState::dns_accountState()
  : wallet_id_()
{}

dns_accountState::dns_accountState(std::int64_t wallet_id_)
  : wallet_id_(wallet_id_)
{}

const std::int32_t dns_accountState::ID;

object_ptr<AccountState> dns_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_accountState> res = make_object<dns_accountState>();
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
}

void dns_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void dns_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsAccountState");
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void dns_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsAccountState").c_str());
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass rwallet_accountState::Class;
jfieldID rwallet_accountState::wallet_id_fieldID;
jfieldID rwallet_accountState::seqno_fieldID;
jfieldID rwallet_accountState::unlocked_balance_fieldID;
jfieldID rwallet_accountState::config_fieldID;

rwallet_accountState::rwallet_accountState()
  : wallet_id_()
  , seqno_()
  , unlocked_balance_()
  , config_()
{}

rwallet_accountState::rwallet_accountState(std::int64_t wallet_id_, std::int32_t seqno_, std::int64_t unlocked_balance_, object_ptr<rwallet_config> &&config_)
  : wallet_id_(wallet_id_)
  , seqno_(seqno_)
  , unlocked_balance_(unlocked_balance_)
  , config_(std::move(config_))
{}

const std::int32_t rwallet_accountState::ID;

object_ptr<AccountState> rwallet_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<rwallet_accountState> res = make_object<rwallet_accountState>();
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->unlocked_balance_ = env->GetLongField(p, res->unlocked_balance_fieldID);
  res->config_ = td::jni::fetch_tl_object<rwallet_config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  return std::move(res);
}

void rwallet_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
  env->SetIntField(s, seqno_fieldID, seqno_);
  env->SetLongField(s, unlocked_balance_fieldID, unlocked_balance_);
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
}

void rwallet_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RwalletAccountState");
    s.store_field("walletId", wallet_id_);
    s.store_field("seqno", seqno_);
    s.store_field("unlockedBalance", unlocked_balance_);
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    s.store_class_end();
  }
}

void rwallet_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RwalletAccountState").c_str());
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  unlocked_balance_fieldID = td::jni::get_field_id(env, Class, "unlockedBalance", "J");
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$RwalletConfig;").c_str());
}

jclass pchan_accountState::Class;
jfieldID pchan_accountState::config_fieldID;
jfieldID pchan_accountState::state_fieldID;
jfieldID pchan_accountState::description_fieldID;

pchan_accountState::pchan_accountState()
  : config_()
  , state_()
  , description_()
{}

pchan_accountState::pchan_accountState(object_ptr<pchan_config> &&config_, object_ptr<pchan_State> &&state_, std::string const &description_)
  : config_(std::move(config_))
  , state_(std::move(state_))
  , description_(std::move(description_))
{}

const std::int32_t pchan_accountState::ID;

object_ptr<AccountState> pchan_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_accountState> res = make_object<pchan_accountState>();
  res->config_ = td::jni::fetch_tl_object<pchan_config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  res->state_ = td::jni::fetch_tl_object<pchan_State>(env, td::jni::fetch_object(env, p, res->state_fieldID));;
  res->description_ = td::jni::fetch_string(env, p, res->description_fieldID);
  return std::move(res);
}

void pchan_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
  if (state_ != nullptr) { jobject next; state_->store(env, next); if (next) { env->SetObjectField(s, state_fieldID, next); env->DeleteLocalRef(next); } }
  { jstring nextString = td::jni::to_jstring(env, description_); if (nextString) { env->SetObjectField(s, description_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void pchan_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanAccountState");
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    if (state_ == nullptr) { s.store_field("state", "null"); } else { state_->store(s, "state"); }
    s.store_field("description", description_);
    s.store_class_end();
  }
}

void pchan_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanAccountState").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$PchanConfig;").c_str());
  state_fieldID = td::jni::get_field_id(env, Class, "state", (PSLICE() << "L" << package_name << "/TonApi$PchanState;").c_str());
  description_fieldID = td::jni::get_field_id(env, Class, "description", "Ljava/lang/String;");
}

jclass uninited_accountState::Class;
jfieldID uninited_accountState::frozen_hash_fieldID;

uninited_accountState::uninited_accountState()
  : frozen_hash_()
{}

uninited_accountState::uninited_accountState(std::string const &frozen_hash_)
  : frozen_hash_(std::move(frozen_hash_))
{}

const std::int32_t uninited_accountState::ID;

object_ptr<AccountState> uninited_accountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<uninited_accountState> res = make_object<uninited_accountState>();
  res->frozen_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->frozen_hash_fieldID));
  return std::move(res);
}

void uninited_accountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, frozen_hash_); if (nextBytes) { env->SetObjectField(s, frozen_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void uninited_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "UninitedAccountState");
    s.store_bytes_field("frozenHash", frozen_hash_);
    s.store_class_end();
  }
}

void uninited_accountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$UninitedAccountState").c_str());
  frozen_hash_fieldID = td::jni::get_field_id(env, Class, "frozenHash", "[B");
}

jclass Action::Class;

object_ptr<Action> Action::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case actionNoop::ID:
      return actionNoop::fetch(env, p);
    case actionMsg::ID:
      return actionMsg::fetch(env, p);
    case actionDns::ID:
      return actionDns::fetch(env, p);
    case actionPchan::ID:
      return actionPchan::fetch(env, p);
    case actionRwallet::ID:
      return actionRwallet::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void Action::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Action").c_str());
  actionNoop::init_jni_vars(env, package_name);
  actionMsg::init_jni_vars(env, package_name);
  actionDns::init_jni_vars(env, package_name);
  actionPchan::init_jni_vars(env, package_name);
  actionRwallet::init_jni_vars(env, package_name);
}

jclass actionNoop::Class;

actionNoop::actionNoop() {
}

const std::int32_t actionNoop::ID;

object_ptr<Action> actionNoop::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<actionNoop> res = make_object<actionNoop>();
  return std::move(res);
}

void actionNoop::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void actionNoop::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ActionNoop");
    s.store_class_end();
  }
}

void actionNoop::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ActionNoop").c_str());
}

jclass actionMsg::Class;
jfieldID actionMsg::messages_fieldID;
jfieldID actionMsg::allow_send_to_uninited_fieldID;

actionMsg::actionMsg()
  : messages_()
  , allow_send_to_uninited_()
{}

actionMsg::actionMsg(std::vector<object_ptr<msg_message>> &&messages_, bool allow_send_to_uninited_)
  : messages_(std::move(messages_))
  , allow_send_to_uninited_(allow_send_to_uninited_)
{}

const std::int32_t actionMsg::ID;

object_ptr<Action> actionMsg::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<actionMsg> res = make_object<actionMsg>();
  res->messages_ = td::jni::FetchVector<msg_message>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->messages_fieldID));;
  res->allow_send_to_uninited_ = (env->GetBooleanField(p, res->allow_send_to_uninited_fieldID) != 0);
  return std::move(res);
}

void actionMsg::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, messages_); if (arr_tmp_) { env->SetObjectField(s, messages_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
  env->SetBooleanField(s, allow_send_to_uninited_fieldID, allow_send_to_uninited_);
}

void actionMsg::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ActionMsg");
    { const std::vector<object_ptr<msg_message>> &v = messages_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("messages", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_field("allowSendToUninited", allow_send_to_uninited_);
    s.store_class_end();
  }
}

void actionMsg::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ActionMsg").c_str());
  messages_fieldID = td::jni::get_field_id(env, Class, "messages", (PSLICE() << "[L" << package_name << "/TonApi$MsgMessage;").c_str());
  allow_send_to_uninited_fieldID = td::jni::get_field_id(env, Class, "allowSendToUninited", "Z");
}

jclass actionDns::Class;
jfieldID actionDns::actions_fieldID;

actionDns::actionDns()
  : actions_()
{}

actionDns::actionDns(std::vector<object_ptr<dns_Action>> &&actions_)
  : actions_(std::move(actions_))
{}

const std::int32_t actionDns::ID;

object_ptr<Action> actionDns::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<actionDns> res = make_object<actionDns>();
  res->actions_ = td::jni::FetchVector<dns_Action>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->actions_fieldID));;
  return std::move(res);
}

void actionDns::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, actions_); if (arr_tmp_) { env->SetObjectField(s, actions_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void actionDns::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ActionDns");
    { const std::vector<object_ptr<dns_Action>> &v = actions_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("actions", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void actionDns::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ActionDns").c_str());
  actions_fieldID = td::jni::get_field_id(env, Class, "actions", (PSLICE() << "[L" << package_name << "/TonApi$DnsAction;").c_str());
}

jclass actionPchan::Class;
jfieldID actionPchan::action_fieldID;

actionPchan::actionPchan()
  : action_()
{}

actionPchan::actionPchan(object_ptr<pchan_Action> &&action_)
  : action_(std::move(action_))
{}

const std::int32_t actionPchan::ID;

object_ptr<Action> actionPchan::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<actionPchan> res = make_object<actionPchan>();
  res->action_ = td::jni::fetch_tl_object<pchan_Action>(env, td::jni::fetch_object(env, p, res->action_fieldID));;
  return std::move(res);
}

void actionPchan::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (action_ != nullptr) { jobject next; action_->store(env, next); if (next) { env->SetObjectField(s, action_fieldID, next); env->DeleteLocalRef(next); } }
}

void actionPchan::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ActionPchan");
    if (action_ == nullptr) { s.store_field("action", "null"); } else { action_->store(s, "action"); }
    s.store_class_end();
  }
}

void actionPchan::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ActionPchan").c_str());
  action_fieldID = td::jni::get_field_id(env, Class, "action", (PSLICE() << "L" << package_name << "/TonApi$PchanAction;").c_str());
}

jclass actionRwallet::Class;
jfieldID actionRwallet::action_fieldID;

actionRwallet::actionRwallet()
  : action_()
{}

actionRwallet::actionRwallet(object_ptr<rwallet_actionInit> &&action_)
  : action_(std::move(action_))
{}

const std::int32_t actionRwallet::ID;

object_ptr<Action> actionRwallet::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<actionRwallet> res = make_object<actionRwallet>();
  res->action_ = td::jni::fetch_tl_object<rwallet_actionInit>(env, td::jni::fetch_object(env, p, res->action_fieldID));;
  return std::move(res);
}

void actionRwallet::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (action_ != nullptr) { jobject next; action_->store(env, next); if (next) { env->SetObjectField(s, action_fieldID, next); env->DeleteLocalRef(next); } }
}

void actionRwallet::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ActionRwallet");
    if (action_ == nullptr) { s.store_field("action", "null"); } else { action_->store(s, "action"); }
    s.store_class_end();
  }
}

void actionRwallet::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ActionRwallet").c_str());
  action_fieldID = td::jni::get_field_id(env, Class, "action", (PSLICE() << "L" << package_name << "/TonApi$RwalletActionInit;").c_str());
}

jclass adnlAddress::Class;
jfieldID adnlAddress::adnl_address_fieldID;

adnlAddress::adnlAddress()
  : adnl_address_()
{}

adnlAddress::adnlAddress(std::string const &adnl_address_)
  : adnl_address_(std::move(adnl_address_))
{}

const std::int32_t adnlAddress::ID;

object_ptr<adnlAddress> adnlAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<adnlAddress> res = make_object<adnlAddress>();
  res->adnl_address_ = td::jni::fetch_string(env, p, res->adnl_address_fieldID);
  return res;
}

void adnlAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, adnl_address_); if (nextString) { env->SetObjectField(s, adnl_address_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void adnlAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "AdnlAddress");
    s.store_field("adnlAddress", adnl_address_);
    s.store_class_end();
  }
}

void adnlAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$AdnlAddress").c_str());
  adnl_address_fieldID = td::jni::get_field_id(env, Class, "adnlAddress", "Ljava/lang/String;");
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

jclass exportedUnencryptedKey::Class;
jfieldID exportedUnencryptedKey::data_fieldID;

exportedUnencryptedKey::exportedUnencryptedKey()
  : data_()
{}

exportedUnencryptedKey::exportedUnencryptedKey(td::SecureString &&data_)
  : data_(std::move(data_))
{}

const std::int32_t exportedUnencryptedKey::ID;

object_ptr<exportedUnencryptedKey> exportedUnencryptedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportedUnencryptedKey> res = make_object<exportedUnencryptedKey>();
  res->data_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return res;
}

void exportedUnencryptedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void exportedUnencryptedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportedUnencryptedKey");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

void exportedUnencryptedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportedUnencryptedKey").c_str());
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
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

jclass fullAccountState::Class;
jfieldID fullAccountState::address_fieldID;
jfieldID fullAccountState::balance_fieldID;
jfieldID fullAccountState::last_transaction_id_fieldID;
jfieldID fullAccountState::block_id_fieldID;
jfieldID fullAccountState::sync_utime_fieldID;
jfieldID fullAccountState::account_state_fieldID;
jfieldID fullAccountState::revision_fieldID;

fullAccountState::fullAccountState()
  : address_()
  , balance_()
  , last_transaction_id_()
  , block_id_()
  , sync_utime_()
  , account_state_()
  , revision_()
{}

fullAccountState::fullAccountState(object_ptr<accountAddress> &&address_, std::int64_t balance_, object_ptr<internal_transactionId> &&last_transaction_id_, object_ptr<ton_blockIdExt> &&block_id_, std::int64_t sync_utime_, object_ptr<AccountState> &&account_state_, std::int32_t revision_)
  : address_(std::move(address_))
  , balance_(balance_)
  , last_transaction_id_(std::move(last_transaction_id_))
  , block_id_(std::move(block_id_))
  , sync_utime_(sync_utime_)
  , account_state_(std::move(account_state_))
  , revision_(revision_)
{}

const std::int32_t fullAccountState::ID;

object_ptr<fullAccountState> fullAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<fullAccountState> res = make_object<fullAccountState>();
  res->address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->address_fieldID));;
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->block_id_ = td::jni::fetch_tl_object<ton_blockIdExt>(env, td::jni::fetch_object(env, p, res->block_id_fieldID));;
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  res->account_state_ = td::jni::fetch_tl_object<AccountState>(env, td::jni::fetch_object(env, p, res->account_state_fieldID));;
  res->revision_ = env->GetIntField(p, res->revision_fieldID);
  return res;
}

void fullAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (address_ != nullptr) { jobject next; address_->store(env, next); if (next) { env->SetObjectField(s, address_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, balance_fieldID, balance_);
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  if (block_id_ != nullptr) { jobject next; block_id_->store(env, next); if (next) { env->SetObjectField(s, block_id_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
  if (account_state_ != nullptr) { jobject next; account_state_->store(env, next); if (next) { env->SetObjectField(s, account_state_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, revision_fieldID, revision_);
}

void fullAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "FullAccountState");
    if (address_ == nullptr) { s.store_field("address", "null"); } else { address_->store(s, "address"); }
    s.store_field("balance", balance_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    if (block_id_ == nullptr) { s.store_field("blockId", "null"); } else { block_id_->store(s, "blockId"); }
    s.store_field("syncUtime", sync_utime_);
    if (account_state_ == nullptr) { s.store_field("accountState", "null"); } else { account_state_->store(s, "accountState"); }
    s.store_field("revision", revision_);
    s.store_class_end();
  }
}

void fullAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$FullAccountState").c_str());
  address_fieldID = td::jni::get_field_id(env, Class, "address", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  block_id_fieldID = td::jni::get_field_id(env, Class, "blockId", (PSLICE() << "L" << package_name << "/TonApi$TonBlockIdExt;").c_str());
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
  account_state_fieldID = td::jni::get_field_id(env, Class, "accountState", (PSLICE() << "L" << package_name << "/TonApi$AccountState;").c_str());
  revision_fieldID = td::jni::get_field_id(env, Class, "revision", "I");
}

jclass InitialAccountState::Class;

object_ptr<InitialAccountState> InitialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case raw_initialAccountState::ID:
      return raw_initialAccountState::fetch(env, p);
    case wallet_v3_initialAccountState::ID:
      return wallet_v3_initialAccountState::fetch(env, p);
    case wallet_highload_v1_initialAccountState::ID:
      return wallet_highload_v1_initialAccountState::fetch(env, p);
    case wallet_highload_v2_initialAccountState::ID:
      return wallet_highload_v2_initialAccountState::fetch(env, p);
    case rwallet_initialAccountState::ID:
      return rwallet_initialAccountState::fetch(env, p);
    case dns_initialAccountState::ID:
      return dns_initialAccountState::fetch(env, p);
    case pchan_initialAccountState::ID:
      return pchan_initialAccountState::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void InitialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$InitialAccountState").c_str());
  raw_initialAccountState::init_jni_vars(env, package_name);
  wallet_v3_initialAccountState::init_jni_vars(env, package_name);
  wallet_highload_v1_initialAccountState::init_jni_vars(env, package_name);
  wallet_highload_v2_initialAccountState::init_jni_vars(env, package_name);
  rwallet_initialAccountState::init_jni_vars(env, package_name);
  dns_initialAccountState::init_jni_vars(env, package_name);
  pchan_initialAccountState::init_jni_vars(env, package_name);
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

object_ptr<InitialAccountState> raw_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_initialAccountState> res = make_object<raw_initialAccountState>();
  res->code_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->code_fieldID));
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return std::move(res);
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

object_ptr<InitialAccountState> wallet_v3_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_v3_initialAccountState> res = make_object<wallet_v3_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
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

jclass wallet_highload_v1_initialAccountState::Class;
jfieldID wallet_highload_v1_initialAccountState::public_key_fieldID;
jfieldID wallet_highload_v1_initialAccountState::wallet_id_fieldID;

wallet_highload_v1_initialAccountState::wallet_highload_v1_initialAccountState()
  : public_key_()
  , wallet_id_()
{}

wallet_highload_v1_initialAccountState::wallet_highload_v1_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_)
  : public_key_(std::move(public_key_))
  , wallet_id_(wallet_id_)
{}

const std::int32_t wallet_highload_v1_initialAccountState::ID;

object_ptr<InitialAccountState> wallet_highload_v1_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_highload_v1_initialAccountState> res = make_object<wallet_highload_v1_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
}

void wallet_highload_v1_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void wallet_highload_v1_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletHighloadV1InitialAccountState");
    s.store_field("publicKey", public_key_);
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void wallet_highload_v1_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletHighloadV1InitialAccountState").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass wallet_highload_v2_initialAccountState::Class;
jfieldID wallet_highload_v2_initialAccountState::public_key_fieldID;
jfieldID wallet_highload_v2_initialAccountState::wallet_id_fieldID;

wallet_highload_v2_initialAccountState::wallet_highload_v2_initialAccountState()
  : public_key_()
  , wallet_id_()
{}

wallet_highload_v2_initialAccountState::wallet_highload_v2_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_)
  : public_key_(std::move(public_key_))
  , wallet_id_(wallet_id_)
{}

const std::int32_t wallet_highload_v2_initialAccountState::ID;

object_ptr<InitialAccountState> wallet_highload_v2_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<wallet_highload_v2_initialAccountState> res = make_object<wallet_highload_v2_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
}

void wallet_highload_v2_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void wallet_highload_v2_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WalletHighloadV2InitialAccountState");
    s.store_field("publicKey", public_key_);
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void wallet_highload_v2_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WalletHighloadV2InitialAccountState").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass rwallet_initialAccountState::Class;
jfieldID rwallet_initialAccountState::init_public_key_fieldID;
jfieldID rwallet_initialAccountState::public_key_fieldID;
jfieldID rwallet_initialAccountState::wallet_id_fieldID;

rwallet_initialAccountState::rwallet_initialAccountState()
  : init_public_key_()
  , public_key_()
  , wallet_id_()
{}

rwallet_initialAccountState::rwallet_initialAccountState(std::string const &init_public_key_, std::string const &public_key_, std::int64_t wallet_id_)
  : init_public_key_(std::move(init_public_key_))
  , public_key_(std::move(public_key_))
  , wallet_id_(wallet_id_)
{}

const std::int32_t rwallet_initialAccountState::ID;

object_ptr<InitialAccountState> rwallet_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<rwallet_initialAccountState> res = make_object<rwallet_initialAccountState>();
  res->init_public_key_ = td::jni::fetch_string(env, p, res->init_public_key_fieldID);
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
}

void rwallet_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, init_public_key_); if (nextString) { env->SetObjectField(s, init_public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void rwallet_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RwalletInitialAccountState");
    s.store_field("initPublicKey", init_public_key_);
    s.store_field("publicKey", public_key_);
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void rwallet_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RwalletInitialAccountState").c_str());
  init_public_key_fieldID = td::jni::get_field_id(env, Class, "initPublicKey", "Ljava/lang/String;");
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass dns_initialAccountState::Class;
jfieldID dns_initialAccountState::public_key_fieldID;
jfieldID dns_initialAccountState::wallet_id_fieldID;

dns_initialAccountState::dns_initialAccountState()
  : public_key_()
  , wallet_id_()
{}

dns_initialAccountState::dns_initialAccountState(std::string const &public_key_, std::int64_t wallet_id_)
  : public_key_(std::move(public_key_))
  , wallet_id_(wallet_id_)
{}

const std::int32_t dns_initialAccountState::ID;

object_ptr<InitialAccountState> dns_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_initialAccountState> res = make_object<dns_initialAccountState>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->wallet_id_ = env->GetLongField(p, res->wallet_id_fieldID);
  return std::move(res);
}

void dns_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, wallet_id_fieldID, wallet_id_);
}

void dns_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsInitialAccountState");
    s.store_field("publicKey", public_key_);
    s.store_field("walletId", wallet_id_);
    s.store_class_end();
  }
}

void dns_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsInitialAccountState").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  wallet_id_fieldID = td::jni::get_field_id(env, Class, "walletId", "J");
}

jclass pchan_initialAccountState::Class;
jfieldID pchan_initialAccountState::config_fieldID;

pchan_initialAccountState::pchan_initialAccountState()
  : config_()
{}

pchan_initialAccountState::pchan_initialAccountState(object_ptr<pchan_config> &&config_)
  : config_(std::move(config_))
{}

const std::int32_t pchan_initialAccountState::ID;

object_ptr<InitialAccountState> pchan_initialAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_initialAccountState> res = make_object<pchan_initialAccountState>();
  res->config_ = td::jni::fetch_tl_object<pchan_config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  return std::move(res);
}

void pchan_initialAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
}

void pchan_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanInitialAccountState");
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    s.store_class_end();
  }
}

void pchan_initialAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanInitialAccountState").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$PchanConfig;").c_str());
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

jclass dns_Action::Class;

object_ptr<dns_Action> dns_Action::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case dns_actionDeleteAll::ID:
      return dns_actionDeleteAll::fetch(env, p);
    case dns_actionDelete::ID:
      return dns_actionDelete::fetch(env, p);
    case dns_actionSet::ID:
      return dns_actionSet::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void dns_Action::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsAction").c_str());
  dns_actionDeleteAll::init_jni_vars(env, package_name);
  dns_actionDelete::init_jni_vars(env, package_name);
  dns_actionSet::init_jni_vars(env, package_name);
}

jclass dns_actionDeleteAll::Class;

dns_actionDeleteAll::dns_actionDeleteAll() {
}

const std::int32_t dns_actionDeleteAll::ID;

object_ptr<dns_Action> dns_actionDeleteAll::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_actionDeleteAll> res = make_object<dns_actionDeleteAll>();
  return std::move(res);
}

void dns_actionDeleteAll::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void dns_actionDeleteAll::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsActionDeleteAll");
    s.store_class_end();
  }
}

void dns_actionDeleteAll::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsActionDeleteAll").c_str());
}

jclass dns_actionDelete::Class;
jfieldID dns_actionDelete::name_fieldID;
jfieldID dns_actionDelete::category_fieldID;

dns_actionDelete::dns_actionDelete()
  : name_()
  , category_()
{}

dns_actionDelete::dns_actionDelete(std::string const &name_, std::int32_t category_)
  : name_(std::move(name_))
  , category_(category_)
{}

const std::int32_t dns_actionDelete::ID;

object_ptr<dns_Action> dns_actionDelete::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_actionDelete> res = make_object<dns_actionDelete>();
  res->name_ = td::jni::fetch_string(env, p, res->name_fieldID);
  res->category_ = env->GetIntField(p, res->category_fieldID);
  return std::move(res);
}

void dns_actionDelete::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, name_); if (nextString) { env->SetObjectField(s, name_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetIntField(s, category_fieldID, category_);
}

void dns_actionDelete::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsActionDelete");
    s.store_field("name", name_);
    s.store_field("category", category_);
    s.store_class_end();
  }
}

void dns_actionDelete::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsActionDelete").c_str());
  name_fieldID = td::jni::get_field_id(env, Class, "name", "Ljava/lang/String;");
  category_fieldID = td::jni::get_field_id(env, Class, "category", "I");
}

jclass dns_actionSet::Class;
jfieldID dns_actionSet::entry_fieldID;

dns_actionSet::dns_actionSet()
  : entry_()
{}

dns_actionSet::dns_actionSet(object_ptr<dns_entry> &&entry_)
  : entry_(std::move(entry_))
{}

const std::int32_t dns_actionSet::ID;

object_ptr<dns_Action> dns_actionSet::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_actionSet> res = make_object<dns_actionSet>();
  res->entry_ = td::jni::fetch_tl_object<dns_entry>(env, td::jni::fetch_object(env, p, res->entry_fieldID));;
  return std::move(res);
}

void dns_actionSet::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (entry_ != nullptr) { jobject next; entry_->store(env, next); if (next) { env->SetObjectField(s, entry_fieldID, next); env->DeleteLocalRef(next); } }
}

void dns_actionSet::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsActionSet");
    if (entry_ == nullptr) { s.store_field("entry", "null"); } else { entry_->store(s, "entry"); }
    s.store_class_end();
  }
}

void dns_actionSet::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsActionSet").c_str());
  entry_fieldID = td::jni::get_field_id(env, Class, "entry", (PSLICE() << "L" << package_name << "/TonApi$DnsEntry;").c_str());
}

jclass dns_entry::Class;
jfieldID dns_entry::name_fieldID;
jfieldID dns_entry::category_fieldID;
jfieldID dns_entry::entry_fieldID;

dns_entry::dns_entry()
  : name_()
  , category_()
  , entry_()
{}

dns_entry::dns_entry(std::string const &name_, std::int32_t category_, object_ptr<dns_EntryData> &&entry_)
  : name_(std::move(name_))
  , category_(category_)
  , entry_(std::move(entry_))
{}

const std::int32_t dns_entry::ID;

object_ptr<dns_entry> dns_entry::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_entry> res = make_object<dns_entry>();
  res->name_ = td::jni::fetch_string(env, p, res->name_fieldID);
  res->category_ = env->GetIntField(p, res->category_fieldID);
  res->entry_ = td::jni::fetch_tl_object<dns_EntryData>(env, td::jni::fetch_object(env, p, res->entry_fieldID));;
  return res;
}

void dns_entry::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, name_); if (nextString) { env->SetObjectField(s, name_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetIntField(s, category_fieldID, category_);
  if (entry_ != nullptr) { jobject next; entry_->store(env, next); if (next) { env->SetObjectField(s, entry_fieldID, next); env->DeleteLocalRef(next); } }
}

void dns_entry::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsEntry");
    s.store_field("name", name_);
    s.store_field("category", category_);
    if (entry_ == nullptr) { s.store_field("entry", "null"); } else { entry_->store(s, "entry"); }
    s.store_class_end();
  }
}

void dns_entry::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntry").c_str());
  name_fieldID = td::jni::get_field_id(env, Class, "name", "Ljava/lang/String;");
  category_fieldID = td::jni::get_field_id(env, Class, "category", "I");
  entry_fieldID = td::jni::get_field_id(env, Class, "entry", (PSLICE() << "L" << package_name << "/TonApi$DnsEntryData;").c_str());
}

jclass dns_EntryData::Class;

object_ptr<dns_EntryData> dns_EntryData::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case dns_entryDataUnknown::ID:
      return dns_entryDataUnknown::fetch(env, p);
    case dns_entryDataText::ID:
      return dns_entryDataText::fetch(env, p);
    case dns_entryDataNextResolver::ID:
      return dns_entryDataNextResolver::fetch(env, p);
    case dns_entryDataSmcAddress::ID:
      return dns_entryDataSmcAddress::fetch(env, p);
    case dns_entryDataAdnlAddress::ID:
      return dns_entryDataAdnlAddress::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void dns_EntryData::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntryData").c_str());
  dns_entryDataUnknown::init_jni_vars(env, package_name);
  dns_entryDataText::init_jni_vars(env, package_name);
  dns_entryDataNextResolver::init_jni_vars(env, package_name);
  dns_entryDataSmcAddress::init_jni_vars(env, package_name);
  dns_entryDataAdnlAddress::init_jni_vars(env, package_name);
}

jclass dns_entryDataUnknown::Class;
jfieldID dns_entryDataUnknown::bytes_fieldID;

dns_entryDataUnknown::dns_entryDataUnknown()
  : bytes_()
{}

dns_entryDataUnknown::dns_entryDataUnknown(std::string const &bytes_)
  : bytes_(std::move(bytes_))
{}

const std::int32_t dns_entryDataUnknown::ID;

object_ptr<dns_EntryData> dns_entryDataUnknown::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_entryDataUnknown> res = make_object<dns_entryDataUnknown>();
  res->bytes_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->bytes_fieldID));
  return std::move(res);
}

void dns_entryDataUnknown::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, bytes_); if (nextBytes) { env->SetObjectField(s, bytes_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void dns_entryDataUnknown::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsEntryDataUnknown");
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

void dns_entryDataUnknown::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntryDataUnknown").c_str());
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "[B");
}

jclass dns_entryDataText::Class;
jfieldID dns_entryDataText::text_fieldID;

dns_entryDataText::dns_entryDataText()
  : text_()
{}

dns_entryDataText::dns_entryDataText(std::string const &text_)
  : text_(std::move(text_))
{}

const std::int32_t dns_entryDataText::ID;

object_ptr<dns_EntryData> dns_entryDataText::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_entryDataText> res = make_object<dns_entryDataText>();
  res->text_ = td::jni::fetch_string(env, p, res->text_fieldID);
  return std::move(res);
}

void dns_entryDataText::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, text_); if (nextString) { env->SetObjectField(s, text_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void dns_entryDataText::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsEntryDataText");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

void dns_entryDataText::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntryDataText").c_str());
  text_fieldID = td::jni::get_field_id(env, Class, "text", "Ljava/lang/String;");
}

jclass dns_entryDataNextResolver::Class;
jfieldID dns_entryDataNextResolver::resolver_fieldID;

dns_entryDataNextResolver::dns_entryDataNextResolver()
  : resolver_()
{}

dns_entryDataNextResolver::dns_entryDataNextResolver(object_ptr<accountAddress> &&resolver_)
  : resolver_(std::move(resolver_))
{}

const std::int32_t dns_entryDataNextResolver::ID;

object_ptr<dns_EntryData> dns_entryDataNextResolver::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_entryDataNextResolver> res = make_object<dns_entryDataNextResolver>();
  res->resolver_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->resolver_fieldID));;
  return std::move(res);
}

void dns_entryDataNextResolver::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (resolver_ != nullptr) { jobject next; resolver_->store(env, next); if (next) { env->SetObjectField(s, resolver_fieldID, next); env->DeleteLocalRef(next); } }
}

void dns_entryDataNextResolver::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsEntryDataNextResolver");
    if (resolver_ == nullptr) { s.store_field("resolver", "null"); } else { resolver_->store(s, "resolver"); }
    s.store_class_end();
  }
}

void dns_entryDataNextResolver::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntryDataNextResolver").c_str());
  resolver_fieldID = td::jni::get_field_id(env, Class, "resolver", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass dns_entryDataSmcAddress::Class;
jfieldID dns_entryDataSmcAddress::smc_address_fieldID;

dns_entryDataSmcAddress::dns_entryDataSmcAddress()
  : smc_address_()
{}

dns_entryDataSmcAddress::dns_entryDataSmcAddress(object_ptr<accountAddress> &&smc_address_)
  : smc_address_(std::move(smc_address_))
{}

const std::int32_t dns_entryDataSmcAddress::ID;

object_ptr<dns_EntryData> dns_entryDataSmcAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_entryDataSmcAddress> res = make_object<dns_entryDataSmcAddress>();
  res->smc_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->smc_address_fieldID));;
  return std::move(res);
}

void dns_entryDataSmcAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (smc_address_ != nullptr) { jobject next; smc_address_->store(env, next); if (next) { env->SetObjectField(s, smc_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void dns_entryDataSmcAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsEntryDataSmcAddress");
    if (smc_address_ == nullptr) { s.store_field("smcAddress", "null"); } else { smc_address_->store(s, "smcAddress"); }
    s.store_class_end();
  }
}

void dns_entryDataSmcAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntryDataSmcAddress").c_str());
  smc_address_fieldID = td::jni::get_field_id(env, Class, "smcAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass dns_entryDataAdnlAddress::Class;
jfieldID dns_entryDataAdnlAddress::adnl_address_fieldID;

dns_entryDataAdnlAddress::dns_entryDataAdnlAddress()
  : adnl_address_()
{}

dns_entryDataAdnlAddress::dns_entryDataAdnlAddress(object_ptr<adnlAddress> &&adnl_address_)
  : adnl_address_(std::move(adnl_address_))
{}

const std::int32_t dns_entryDataAdnlAddress::ID;

object_ptr<dns_EntryData> dns_entryDataAdnlAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_entryDataAdnlAddress> res = make_object<dns_entryDataAdnlAddress>();
  res->adnl_address_ = td::jni::fetch_tl_object<adnlAddress>(env, td::jni::fetch_object(env, p, res->adnl_address_fieldID));;
  return std::move(res);
}

void dns_entryDataAdnlAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (adnl_address_ != nullptr) { jobject next; adnl_address_->store(env, next); if (next) { env->SetObjectField(s, adnl_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void dns_entryDataAdnlAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsEntryDataAdnlAddress");
    if (adnl_address_ == nullptr) { s.store_field("adnlAddress", "null"); } else { adnl_address_->store(s, "adnlAddress"); }
    s.store_class_end();
  }
}

void dns_entryDataAdnlAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsEntryDataAdnlAddress").c_str());
  adnl_address_fieldID = td::jni::get_field_id(env, Class, "adnlAddress", (PSLICE() << "L" << package_name << "/TonApi$AdnlAddress;").c_str());
}

jclass dns_resolved::Class;
jfieldID dns_resolved::entries_fieldID;

dns_resolved::dns_resolved()
  : entries_()
{}

dns_resolved::dns_resolved(std::vector<object_ptr<dns_entry>> &&entries_)
  : entries_(std::move(entries_))
{}

const std::int32_t dns_resolved::ID;

object_ptr<dns_resolved> dns_resolved::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_resolved> res = make_object<dns_resolved>();
  res->entries_ = td::jni::FetchVector<dns_entry>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->entries_fieldID));;
  return res;
}

void dns_resolved::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, entries_); if (arr_tmp_) { env->SetObjectField(s, entries_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void dns_resolved::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsResolved");
    { const std::vector<object_ptr<dns_entry>> &v = entries_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("entries", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void dns_resolved::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsResolved").c_str());
  entries_fieldID = td::jni::get_field_id(env, Class, "entries", (PSLICE() << "[L" << package_name << "/TonApi$DnsEntry;").c_str());
}

jclass ton_blockId::Class;
jfieldID ton_blockId::workchain_fieldID;
jfieldID ton_blockId::shard_fieldID;
jfieldID ton_blockId::seqno_fieldID;

ton_blockId::ton_blockId()
  : workchain_()
  , shard_()
  , seqno_()
{}

ton_blockId::ton_blockId(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_)
  : workchain_(workchain_)
  , shard_(shard_)
  , seqno_(seqno_)
{}

const std::int32_t ton_blockId::ID;

object_ptr<ton_blockId> ton_blockId::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<ton_blockId> res = make_object<ton_blockId>();
  res->workchain_ = env->GetIntField(p, res->workchain_fieldID);
  res->shard_ = env->GetLongField(p, res->shard_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  return res;
}

void ton_blockId::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, workchain_fieldID, workchain_);
  env->SetLongField(s, shard_fieldID, shard_);
  env->SetIntField(s, seqno_fieldID, seqno_);
}

void ton_blockId::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TonBlockId");
    s.store_field("workchain", workchain_);
    s.store_field("shard", shard_);
    s.store_field("seqno", seqno_);
    s.store_class_end();
  }
}

void ton_blockId::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TonBlockId").c_str());
  workchain_fieldID = td::jni::get_field_id(env, Class, "workchain", "I");
  shard_fieldID = td::jni::get_field_id(env, Class, "shard", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
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

jclass msg_Data::Class;

object_ptr<msg_Data> msg_Data::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case msg_dataRaw::ID:
      return msg_dataRaw::fetch(env, p);
    case msg_dataText::ID:
      return msg_dataText::fetch(env, p);
    case msg_dataDecryptedText::ID:
      return msg_dataDecryptedText::fetch(env, p);
    case msg_dataEncryptedText::ID:
      return msg_dataEncryptedText::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void msg_Data::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgData").c_str());
  msg_dataRaw::init_jni_vars(env, package_name);
  msg_dataText::init_jni_vars(env, package_name);
  msg_dataDecryptedText::init_jni_vars(env, package_name);
  msg_dataEncryptedText::init_jni_vars(env, package_name);
}

jclass msg_dataRaw::Class;
jfieldID msg_dataRaw::body_fieldID;
jfieldID msg_dataRaw::init_state_fieldID;

msg_dataRaw::msg_dataRaw()
  : body_()
  , init_state_()
{}

msg_dataRaw::msg_dataRaw(std::string const &body_, std::string const &init_state_)
  : body_(std::move(body_))
  , init_state_(std::move(init_state_))
{}

const std::int32_t msg_dataRaw::ID;

object_ptr<msg_Data> msg_dataRaw::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataRaw> res = make_object<msg_dataRaw>();
  res->body_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_fieldID));
  res->init_state_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->init_state_fieldID));
  return std::move(res);
}

void msg_dataRaw::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_); if (nextBytes) { env->SetObjectField(s, body_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, init_state_); if (nextBytes) { env->SetObjectField(s, init_state_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void msg_dataRaw::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataRaw");
    s.store_bytes_field("body", body_);
    s.store_bytes_field("initState", init_state_);
    s.store_class_end();
  }
}

void msg_dataRaw::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataRaw").c_str());
  body_fieldID = td::jni::get_field_id(env, Class, "body", "[B");
  init_state_fieldID = td::jni::get_field_id(env, Class, "initState", "[B");
}

jclass msg_dataText::Class;
jfieldID msg_dataText::text_fieldID;

msg_dataText::msg_dataText()
  : text_()
{}

msg_dataText::msg_dataText(std::string const &text_)
  : text_(std::move(text_))
{}

const std::int32_t msg_dataText::ID;

object_ptr<msg_Data> msg_dataText::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataText> res = make_object<msg_dataText>();
  res->text_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->text_fieldID));
  return std::move(res);
}

void msg_dataText::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, text_); if (nextBytes) { env->SetObjectField(s, text_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void msg_dataText::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataText");
    s.store_bytes_field("text", text_);
    s.store_class_end();
  }
}

void msg_dataText::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataText").c_str());
  text_fieldID = td::jni::get_field_id(env, Class, "text", "[B");
}

jclass msg_dataDecryptedText::Class;
jfieldID msg_dataDecryptedText::text_fieldID;

msg_dataDecryptedText::msg_dataDecryptedText()
  : text_()
{}

msg_dataDecryptedText::msg_dataDecryptedText(std::string const &text_)
  : text_(std::move(text_))
{}

const std::int32_t msg_dataDecryptedText::ID;

object_ptr<msg_Data> msg_dataDecryptedText::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataDecryptedText> res = make_object<msg_dataDecryptedText>();
  res->text_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->text_fieldID));
  return std::move(res);
}

void msg_dataDecryptedText::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, text_); if (nextBytes) { env->SetObjectField(s, text_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void msg_dataDecryptedText::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataDecryptedText");
    s.store_bytes_field("text", text_);
    s.store_class_end();
  }
}

void msg_dataDecryptedText::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataDecryptedText").c_str());
  text_fieldID = td::jni::get_field_id(env, Class, "text", "[B");
}

jclass msg_dataEncryptedText::Class;
jfieldID msg_dataEncryptedText::text_fieldID;

msg_dataEncryptedText::msg_dataEncryptedText()
  : text_()
{}

msg_dataEncryptedText::msg_dataEncryptedText(std::string const &text_)
  : text_(std::move(text_))
{}

const std::int32_t msg_dataEncryptedText::ID;

object_ptr<msg_Data> msg_dataEncryptedText::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataEncryptedText> res = make_object<msg_dataEncryptedText>();
  res->text_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->text_fieldID));
  return std::move(res);
}

void msg_dataEncryptedText::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, text_); if (nextBytes) { env->SetObjectField(s, text_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void msg_dataEncryptedText::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataEncryptedText");
    s.store_bytes_field("text", text_);
    s.store_class_end();
  }
}

void msg_dataEncryptedText::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataEncryptedText").c_str());
  text_fieldID = td::jni::get_field_id(env, Class, "text", "[B");
}

jclass msg_dataDecrypted::Class;
jfieldID msg_dataDecrypted::proof_fieldID;
jfieldID msg_dataDecrypted::data_fieldID;

msg_dataDecrypted::msg_dataDecrypted()
  : proof_()
  , data_()
{}

msg_dataDecrypted::msg_dataDecrypted(std::string const &proof_, object_ptr<msg_Data> &&data_)
  : proof_(std::move(proof_))
  , data_(std::move(data_))
{}

const std::int32_t msg_dataDecrypted::ID;

object_ptr<msg_dataDecrypted> msg_dataDecrypted::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataDecrypted> res = make_object<msg_dataDecrypted>();
  res->proof_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->proof_fieldID));
  res->data_ = td::jni::fetch_tl_object<msg_Data>(env, td::jni::fetch_object(env, p, res->data_fieldID));;
  return res;
}

void msg_dataDecrypted::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, proof_); if (nextBytes) { env->SetObjectField(s, proof_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (data_ != nullptr) { jobject next; data_->store(env, next); if (next) { env->SetObjectField(s, data_fieldID, next); env->DeleteLocalRef(next); } }
}

void msg_dataDecrypted::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataDecrypted");
    s.store_bytes_field("proof", proof_);
    if (data_ == nullptr) { s.store_field("data", "null"); } else { data_->store(s, "data"); }
    s.store_class_end();
  }
}

void msg_dataDecrypted::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataDecrypted").c_str());
  proof_fieldID = td::jni::get_field_id(env, Class, "proof", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", (PSLICE() << "L" << package_name << "/TonApi$MsgData;").c_str());
}

jclass msg_dataDecryptedArray::Class;
jfieldID msg_dataDecryptedArray::elements_fieldID;

msg_dataDecryptedArray::msg_dataDecryptedArray()
  : elements_()
{}

msg_dataDecryptedArray::msg_dataDecryptedArray(std::vector<object_ptr<msg_dataDecrypted>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t msg_dataDecryptedArray::ID;

object_ptr<msg_dataDecryptedArray> msg_dataDecryptedArray::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataDecryptedArray> res = make_object<msg_dataDecryptedArray>();
  res->elements_ = td::jni::FetchVector<msg_dataDecrypted>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->elements_fieldID));;
  return res;
}

void msg_dataDecryptedArray::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, elements_); if (arr_tmp_) { env->SetObjectField(s, elements_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void msg_dataDecryptedArray::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataDecryptedArray");
    { const std::vector<object_ptr<msg_dataDecrypted>> &v = elements_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("elements", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void msg_dataDecryptedArray::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataDecryptedArray").c_str());
  elements_fieldID = td::jni::get_field_id(env, Class, "elements", (PSLICE() << "[L" << package_name << "/TonApi$MsgDataDecrypted;").c_str());
}

jclass msg_dataEncrypted::Class;
jfieldID msg_dataEncrypted::source_fieldID;
jfieldID msg_dataEncrypted::data_fieldID;

msg_dataEncrypted::msg_dataEncrypted()
  : source_()
  , data_()
{}

msg_dataEncrypted::msg_dataEncrypted(object_ptr<accountAddress> &&source_, object_ptr<msg_Data> &&data_)
  : source_(std::move(source_))
  , data_(std::move(data_))
{}

const std::int32_t msg_dataEncrypted::ID;

object_ptr<msg_dataEncrypted> msg_dataEncrypted::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataEncrypted> res = make_object<msg_dataEncrypted>();
  res->source_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->source_fieldID));;
  res->data_ = td::jni::fetch_tl_object<msg_Data>(env, td::jni::fetch_object(env, p, res->data_fieldID));;
  return res;
}

void msg_dataEncrypted::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (source_ != nullptr) { jobject next; source_->store(env, next); if (next) { env->SetObjectField(s, source_fieldID, next); env->DeleteLocalRef(next); } }
  if (data_ != nullptr) { jobject next; data_->store(env, next); if (next) { env->SetObjectField(s, data_fieldID, next); env->DeleteLocalRef(next); } }
}

void msg_dataEncrypted::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataEncrypted");
    if (source_ == nullptr) { s.store_field("source", "null"); } else { source_->store(s, "source"); }
    if (data_ == nullptr) { s.store_field("data", "null"); } else { data_->store(s, "data"); }
    s.store_class_end();
  }
}

void msg_dataEncrypted::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataEncrypted").c_str());
  source_fieldID = td::jni::get_field_id(env, Class, "source", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  data_fieldID = td::jni::get_field_id(env, Class, "data", (PSLICE() << "L" << package_name << "/TonApi$MsgData;").c_str());
}

jclass msg_dataEncryptedArray::Class;
jfieldID msg_dataEncryptedArray::elements_fieldID;

msg_dataEncryptedArray::msg_dataEncryptedArray()
  : elements_()
{}

msg_dataEncryptedArray::msg_dataEncryptedArray(std::vector<object_ptr<msg_dataEncrypted>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t msg_dataEncryptedArray::ID;

object_ptr<msg_dataEncryptedArray> msg_dataEncryptedArray::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_dataEncryptedArray> res = make_object<msg_dataEncryptedArray>();
  res->elements_ = td::jni::FetchVector<msg_dataEncrypted>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->elements_fieldID));;
  return res;
}

void msg_dataEncryptedArray::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, elements_); if (arr_tmp_) { env->SetObjectField(s, elements_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void msg_dataEncryptedArray::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDataEncryptedArray");
    { const std::vector<object_ptr<msg_dataEncrypted>> &v = elements_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("elements", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void msg_dataEncryptedArray::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDataEncryptedArray").c_str());
  elements_fieldID = td::jni::get_field_id(env, Class, "elements", (PSLICE() << "[L" << package_name << "/TonApi$MsgDataEncrypted;").c_str());
}

jclass msg_message::Class;
jfieldID msg_message::destination_fieldID;
jfieldID msg_message::public_key_fieldID;
jfieldID msg_message::amount_fieldID;
jfieldID msg_message::data_fieldID;

msg_message::msg_message()
  : destination_()
  , public_key_()
  , amount_()
  , data_()
{}

msg_message::msg_message(object_ptr<accountAddress> &&destination_, std::string const &public_key_, std::int64_t amount_, object_ptr<msg_Data> &&data_)
  : destination_(std::move(destination_))
  , public_key_(std::move(public_key_))
  , amount_(amount_)
  , data_(std::move(data_))
{}

const std::int32_t msg_message::ID;

object_ptr<msg_message> msg_message::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_message> res = make_object<msg_message>();
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->amount_ = env->GetLongField(p, res->amount_fieldID);
  res->data_ = td::jni::fetch_tl_object<msg_Data>(env, td::jni::fetch_object(env, p, res->data_fieldID));;
  return res;
}

void msg_message::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetLongField(s, amount_fieldID, amount_);
  if (data_ != nullptr) { jobject next; data_->store(env, next); if (next) { env->SetObjectField(s, data_fieldID, next); env->DeleteLocalRef(next); } }
}

void msg_message::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgMessage");
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("publicKey", public_key_);
    s.store_field("amount", amount_);
    if (data_ == nullptr) { s.store_field("data", "null"); } else { data_->store(s, "data"); }
    s.store_class_end();
  }
}

void msg_message::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgMessage").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  amount_fieldID = td::jni::get_field_id(env, Class, "amount", "J");
  data_fieldID = td::jni::get_field_id(env, Class, "data", (PSLICE() << "L" << package_name << "/TonApi$MsgData;").c_str());
}

jclass options_configInfo::Class;
jfieldID options_configInfo::default_wallet_id_fieldID;
jfieldID options_configInfo::default_rwallet_init_public_key_fieldID;

options_configInfo::options_configInfo()
  : default_wallet_id_()
  , default_rwallet_init_public_key_()
{}

options_configInfo::options_configInfo(std::int64_t default_wallet_id_, std::string const &default_rwallet_init_public_key_)
  : default_wallet_id_(default_wallet_id_)
  , default_rwallet_init_public_key_(std::move(default_rwallet_init_public_key_))
{}

const std::int32_t options_configInfo::ID;

object_ptr<options_configInfo> options_configInfo::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<options_configInfo> res = make_object<options_configInfo>();
  res->default_wallet_id_ = env->GetLongField(p, res->default_wallet_id_fieldID);
  res->default_rwallet_init_public_key_ = td::jni::fetch_string(env, p, res->default_rwallet_init_public_key_fieldID);
  return res;
}

void options_configInfo::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, default_wallet_id_fieldID, default_wallet_id_);
  { jstring nextString = td::jni::to_jstring(env, default_rwallet_init_public_key_); if (nextString) { env->SetObjectField(s, default_rwallet_init_public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void options_configInfo::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OptionsConfigInfo");
    s.store_field("defaultWalletId", default_wallet_id_);
    s.store_field("defaultRwalletInitPublicKey", default_rwallet_init_public_key_);
    s.store_class_end();
  }
}

void options_configInfo::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OptionsConfigInfo").c_str());
  default_wallet_id_fieldID = td::jni::get_field_id(env, Class, "defaultWalletId", "J");
  default_rwallet_init_public_key_fieldID = td::jni::get_field_id(env, Class, "defaultRwalletInitPublicKey", "Ljava/lang/String;");
}

jclass options_info::Class;
jfieldID options_info::config_info_fieldID;

options_info::options_info()
  : config_info_()
{}

options_info::options_info(object_ptr<options_configInfo> &&config_info_)
  : config_info_(std::move(config_info_))
{}

const std::int32_t options_info::ID;

object_ptr<options_info> options_info::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<options_info> res = make_object<options_info>();
  res->config_info_ = td::jni::fetch_tl_object<options_configInfo>(env, td::jni::fetch_object(env, p, res->config_info_fieldID));;
  return res;
}

void options_info::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_info_ != nullptr) { jobject next; config_info_->store(env, next); if (next) { env->SetObjectField(s, config_info_fieldID, next); env->DeleteLocalRef(next); } }
}

void options_info::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "OptionsInfo");
    if (config_info_ == nullptr) { s.store_field("configInfo", "null"); } else { config_info_->store(s, "configInfo"); }
    s.store_class_end();
  }
}

void options_info::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$OptionsInfo").c_str());
  config_info_fieldID = td::jni::get_field_id(env, Class, "configInfo", (PSLICE() << "L" << package_name << "/TonApi$OptionsConfigInfo;").c_str());
}

jclass pchan_Action::Class;

object_ptr<pchan_Action> pchan_Action::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case pchan_actionInit::ID:
      return pchan_actionInit::fetch(env, p);
    case pchan_actionClose::ID:
      return pchan_actionClose::fetch(env, p);
    case pchan_actionTimeout::ID:
      return pchan_actionTimeout::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void pchan_Action::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanAction").c_str());
  pchan_actionInit::init_jni_vars(env, package_name);
  pchan_actionClose::init_jni_vars(env, package_name);
  pchan_actionTimeout::init_jni_vars(env, package_name);
}

jclass pchan_actionInit::Class;
jfieldID pchan_actionInit::inc_A_fieldID;
jfieldID pchan_actionInit::inc_B_fieldID;
jfieldID pchan_actionInit::min_A_fieldID;
jfieldID pchan_actionInit::min_B_fieldID;

pchan_actionInit::pchan_actionInit()
  : inc_A_()
  , inc_B_()
  , min_A_()
  , min_B_()
{}

pchan_actionInit::pchan_actionInit(std::int64_t inc_A_, std::int64_t inc_B_, std::int64_t min_A_, std::int64_t min_B_)
  : inc_A_(inc_A_)
  , inc_B_(inc_B_)
  , min_A_(min_A_)
  , min_B_(min_B_)
{}

const std::int32_t pchan_actionInit::ID;

object_ptr<pchan_Action> pchan_actionInit::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_actionInit> res = make_object<pchan_actionInit>();
  res->inc_A_ = env->GetLongField(p, res->inc_A_fieldID);
  res->inc_B_ = env->GetLongField(p, res->inc_B_fieldID);
  res->min_A_ = env->GetLongField(p, res->min_A_fieldID);
  res->min_B_ = env->GetLongField(p, res->min_B_fieldID);
  return std::move(res);
}

void pchan_actionInit::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, inc_A_fieldID, inc_A_);
  env->SetLongField(s, inc_B_fieldID, inc_B_);
  env->SetLongField(s, min_A_fieldID, min_A_);
  env->SetLongField(s, min_B_fieldID, min_B_);
}

void pchan_actionInit::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanActionInit");
    s.store_field("incA", inc_A_);
    s.store_field("incB", inc_B_);
    s.store_field("minA", min_A_);
    s.store_field("minB", min_B_);
    s.store_class_end();
  }
}

void pchan_actionInit::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanActionInit").c_str());
  inc_A_fieldID = td::jni::get_field_id(env, Class, "incA", "J");
  inc_B_fieldID = td::jni::get_field_id(env, Class, "incB", "J");
  min_A_fieldID = td::jni::get_field_id(env, Class, "minA", "J");
  min_B_fieldID = td::jni::get_field_id(env, Class, "minB", "J");
}

jclass pchan_actionClose::Class;
jfieldID pchan_actionClose::extra_A_fieldID;
jfieldID pchan_actionClose::extra_B_fieldID;
jfieldID pchan_actionClose::promise_fieldID;

pchan_actionClose::pchan_actionClose()
  : extra_A_()
  , extra_B_()
  , promise_()
{}

pchan_actionClose::pchan_actionClose(std::int64_t extra_A_, std::int64_t extra_B_, object_ptr<pchan_promise> &&promise_)
  : extra_A_(extra_A_)
  , extra_B_(extra_B_)
  , promise_(std::move(promise_))
{}

const std::int32_t pchan_actionClose::ID;

object_ptr<pchan_Action> pchan_actionClose::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_actionClose> res = make_object<pchan_actionClose>();
  res->extra_A_ = env->GetLongField(p, res->extra_A_fieldID);
  res->extra_B_ = env->GetLongField(p, res->extra_B_fieldID);
  res->promise_ = td::jni::fetch_tl_object<pchan_promise>(env, td::jni::fetch_object(env, p, res->promise_fieldID));;
  return std::move(res);
}

void pchan_actionClose::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, extra_A_fieldID, extra_A_);
  env->SetLongField(s, extra_B_fieldID, extra_B_);
  if (promise_ != nullptr) { jobject next; promise_->store(env, next); if (next) { env->SetObjectField(s, promise_fieldID, next); env->DeleteLocalRef(next); } }
}

void pchan_actionClose::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanActionClose");
    s.store_field("extraA", extra_A_);
    s.store_field("extraB", extra_B_);
    if (promise_ == nullptr) { s.store_field("promise", "null"); } else { promise_->store(s, "promise"); }
    s.store_class_end();
  }
}

void pchan_actionClose::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanActionClose").c_str());
  extra_A_fieldID = td::jni::get_field_id(env, Class, "extraA", "J");
  extra_B_fieldID = td::jni::get_field_id(env, Class, "extraB", "J");
  promise_fieldID = td::jni::get_field_id(env, Class, "promise", (PSLICE() << "L" << package_name << "/TonApi$PchanPromise;").c_str());
}

jclass pchan_actionTimeout::Class;

pchan_actionTimeout::pchan_actionTimeout() {
}

const std::int32_t pchan_actionTimeout::ID;

object_ptr<pchan_Action> pchan_actionTimeout::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_actionTimeout> res = make_object<pchan_actionTimeout>();
  return std::move(res);
}

void pchan_actionTimeout::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
}

void pchan_actionTimeout::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanActionTimeout");
    s.store_class_end();
  }
}

void pchan_actionTimeout::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanActionTimeout").c_str());
}

jclass pchan_config::Class;
jfieldID pchan_config::alice_public_key_fieldID;
jfieldID pchan_config::alice_address_fieldID;
jfieldID pchan_config::bob_public_key_fieldID;
jfieldID pchan_config::bob_address_fieldID;
jfieldID pchan_config::init_timeout_fieldID;
jfieldID pchan_config::close_timeout_fieldID;
jfieldID pchan_config::channel_id_fieldID;

pchan_config::pchan_config()
  : alice_public_key_()
  , alice_address_()
  , bob_public_key_()
  , bob_address_()
  , init_timeout_()
  , close_timeout_()
  , channel_id_()
{}

pchan_config::pchan_config(std::string const &alice_public_key_, object_ptr<accountAddress> &&alice_address_, std::string const &bob_public_key_, object_ptr<accountAddress> &&bob_address_, std::int32_t init_timeout_, std::int32_t close_timeout_, std::int64_t channel_id_)
  : alice_public_key_(std::move(alice_public_key_))
  , alice_address_(std::move(alice_address_))
  , bob_public_key_(std::move(bob_public_key_))
  , bob_address_(std::move(bob_address_))
  , init_timeout_(init_timeout_)
  , close_timeout_(close_timeout_)
  , channel_id_(channel_id_)
{}

const std::int32_t pchan_config::ID;

object_ptr<pchan_config> pchan_config::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_config> res = make_object<pchan_config>();
  res->alice_public_key_ = td::jni::fetch_string(env, p, res->alice_public_key_fieldID);
  res->alice_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->alice_address_fieldID));;
  res->bob_public_key_ = td::jni::fetch_string(env, p, res->bob_public_key_fieldID);
  res->bob_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->bob_address_fieldID));;
  res->init_timeout_ = env->GetIntField(p, res->init_timeout_fieldID);
  res->close_timeout_ = env->GetIntField(p, res->close_timeout_fieldID);
  res->channel_id_ = env->GetLongField(p, res->channel_id_fieldID);
  return res;
}

void pchan_config::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, alice_public_key_); if (nextString) { env->SetObjectField(s, alice_public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  if (alice_address_ != nullptr) { jobject next; alice_address_->store(env, next); if (next) { env->SetObjectField(s, alice_address_fieldID, next); env->DeleteLocalRef(next); } }
  { jstring nextString = td::jni::to_jstring(env, bob_public_key_); if (nextString) { env->SetObjectField(s, bob_public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  if (bob_address_ != nullptr) { jobject next; bob_address_->store(env, next); if (next) { env->SetObjectField(s, bob_address_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, init_timeout_fieldID, init_timeout_);
  env->SetIntField(s, close_timeout_fieldID, close_timeout_);
  env->SetLongField(s, channel_id_fieldID, channel_id_);
}

void pchan_config::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanConfig");
    s.store_field("alicePublicKey", alice_public_key_);
    if (alice_address_ == nullptr) { s.store_field("aliceAddress", "null"); } else { alice_address_->store(s, "aliceAddress"); }
    s.store_field("bobPublicKey", bob_public_key_);
    if (bob_address_ == nullptr) { s.store_field("bobAddress", "null"); } else { bob_address_->store(s, "bobAddress"); }
    s.store_field("initTimeout", init_timeout_);
    s.store_field("closeTimeout", close_timeout_);
    s.store_field("channelId", channel_id_);
    s.store_class_end();
  }
}

void pchan_config::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanConfig").c_str());
  alice_public_key_fieldID = td::jni::get_field_id(env, Class, "alicePublicKey", "Ljava/lang/String;");
  alice_address_fieldID = td::jni::get_field_id(env, Class, "aliceAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  bob_public_key_fieldID = td::jni::get_field_id(env, Class, "bobPublicKey", "Ljava/lang/String;");
  bob_address_fieldID = td::jni::get_field_id(env, Class, "bobAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  init_timeout_fieldID = td::jni::get_field_id(env, Class, "initTimeout", "I");
  close_timeout_fieldID = td::jni::get_field_id(env, Class, "closeTimeout", "I");
  channel_id_fieldID = td::jni::get_field_id(env, Class, "channelId", "J");
}

jclass pchan_promise::Class;
jfieldID pchan_promise::signature_fieldID;
jfieldID pchan_promise::promise_A_fieldID;
jfieldID pchan_promise::promise_B_fieldID;
jfieldID pchan_promise::channel_id_fieldID;

pchan_promise::pchan_promise()
  : signature_()
  , promise_A_()
  , promise_B_()
  , channel_id_()
{}

pchan_promise::pchan_promise(std::string const &signature_, std::int64_t promise_A_, std::int64_t promise_B_, std::int64_t channel_id_)
  : signature_(std::move(signature_))
  , promise_A_(promise_A_)
  , promise_B_(promise_B_)
  , channel_id_(channel_id_)
{}

const std::int32_t pchan_promise::ID;

object_ptr<pchan_promise> pchan_promise::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_promise> res = make_object<pchan_promise>();
  res->signature_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->signature_fieldID));
  res->promise_A_ = env->GetLongField(p, res->promise_A_fieldID);
  res->promise_B_ = env->GetLongField(p, res->promise_B_fieldID);
  res->channel_id_ = env->GetLongField(p, res->channel_id_fieldID);
  return res;
}

void pchan_promise::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, signature_); if (nextBytes) { env->SetObjectField(s, signature_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  env->SetLongField(s, promise_A_fieldID, promise_A_);
  env->SetLongField(s, promise_B_fieldID, promise_B_);
  env->SetLongField(s, channel_id_fieldID, channel_id_);
}

void pchan_promise::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanPromise");
    s.store_bytes_field("signature", signature_);
    s.store_field("promiseA", promise_A_);
    s.store_field("promiseB", promise_B_);
    s.store_field("channelId", channel_id_);
    s.store_class_end();
  }
}

void pchan_promise::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanPromise").c_str());
  signature_fieldID = td::jni::get_field_id(env, Class, "signature", "[B");
  promise_A_fieldID = td::jni::get_field_id(env, Class, "promiseA", "J");
  promise_B_fieldID = td::jni::get_field_id(env, Class, "promiseB", "J");
  channel_id_fieldID = td::jni::get_field_id(env, Class, "channelId", "J");
}

jclass pchan_State::Class;

object_ptr<pchan_State> pchan_State::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) { return nullptr; }
  auto id = env->CallIntMethod(p, td::jni::GetConstructorID);
  switch (id) {
    case pchan_stateInit::ID:
      return pchan_stateInit::fetch(env, p);
    case pchan_stateClose::ID:
      return pchan_stateClose::fetch(env, p);
    case pchan_statePayout::ID:
      return pchan_statePayout::fetch(env, p);
    default:
      LOG(WARNING) << "Unknown constructor found: " << id;
      return nullptr;
  }
}

void pchan_State::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanState").c_str());
  pchan_stateInit::init_jni_vars(env, package_name);
  pchan_stateClose::init_jni_vars(env, package_name);
  pchan_statePayout::init_jni_vars(env, package_name);
}

jclass pchan_stateInit::Class;
jfieldID pchan_stateInit::signed_A_fieldID;
jfieldID pchan_stateInit::signed_B_fieldID;
jfieldID pchan_stateInit::min_A_fieldID;
jfieldID pchan_stateInit::min_B_fieldID;
jfieldID pchan_stateInit::expire_at_fieldID;
jfieldID pchan_stateInit::A_fieldID;
jfieldID pchan_stateInit::B_fieldID;

pchan_stateInit::pchan_stateInit()
  : signed_A_()
  , signed_B_()
  , min_A_()
  , min_B_()
  , expire_at_()
  , A_()
  , B_()
{}

pchan_stateInit::pchan_stateInit(bool signed_A_, bool signed_B_, std::int64_t min_A_, std::int64_t min_B_, std::int64_t expire_at_, std::int64_t A_, std::int64_t B_)
  : signed_A_(signed_A_)
  , signed_B_(signed_B_)
  , min_A_(min_A_)
  , min_B_(min_B_)
  , expire_at_(expire_at_)
  , A_(A_)
  , B_(B_)
{}

const std::int32_t pchan_stateInit::ID;

object_ptr<pchan_State> pchan_stateInit::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_stateInit> res = make_object<pchan_stateInit>();
  res->signed_A_ = (env->GetBooleanField(p, res->signed_A_fieldID) != 0);
  res->signed_B_ = (env->GetBooleanField(p, res->signed_B_fieldID) != 0);
  res->min_A_ = env->GetLongField(p, res->min_A_fieldID);
  res->min_B_ = env->GetLongField(p, res->min_B_fieldID);
  res->expire_at_ = env->GetLongField(p, res->expire_at_fieldID);
  res->A_ = env->GetLongField(p, res->A_fieldID);
  res->B_ = env->GetLongField(p, res->B_fieldID);
  return std::move(res);
}

void pchan_stateInit::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetBooleanField(s, signed_A_fieldID, signed_A_);
  env->SetBooleanField(s, signed_B_fieldID, signed_B_);
  env->SetLongField(s, min_A_fieldID, min_A_);
  env->SetLongField(s, min_B_fieldID, min_B_);
  env->SetLongField(s, expire_at_fieldID, expire_at_);
  env->SetLongField(s, A_fieldID, A_);
  env->SetLongField(s, B_fieldID, B_);
}

void pchan_stateInit::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanStateInit");
    s.store_field("signedA", signed_A_);
    s.store_field("signedB", signed_B_);
    s.store_field("minA", min_A_);
    s.store_field("minB", min_B_);
    s.store_field("expireAt", expire_at_);
    s.store_field("A", A_);
    s.store_field("B", B_);
    s.store_class_end();
  }
}

void pchan_stateInit::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanStateInit").c_str());
  signed_A_fieldID = td::jni::get_field_id(env, Class, "signedA", "Z");
  signed_B_fieldID = td::jni::get_field_id(env, Class, "signedB", "Z");
  min_A_fieldID = td::jni::get_field_id(env, Class, "minA", "J");
  min_B_fieldID = td::jni::get_field_id(env, Class, "minB", "J");
  expire_at_fieldID = td::jni::get_field_id(env, Class, "expireAt", "J");
  A_fieldID = td::jni::get_field_id(env, Class, "A", "J");
  B_fieldID = td::jni::get_field_id(env, Class, "B", "J");
}

jclass pchan_stateClose::Class;
jfieldID pchan_stateClose::signed_A_fieldID;
jfieldID pchan_stateClose::signed_B_fieldID;
jfieldID pchan_stateClose::min_A_fieldID;
jfieldID pchan_stateClose::min_B_fieldID;
jfieldID pchan_stateClose::expire_at_fieldID;
jfieldID pchan_stateClose::A_fieldID;
jfieldID pchan_stateClose::B_fieldID;

pchan_stateClose::pchan_stateClose()
  : signed_A_()
  , signed_B_()
  , min_A_()
  , min_B_()
  , expire_at_()
  , A_()
  , B_()
{}

pchan_stateClose::pchan_stateClose(bool signed_A_, bool signed_B_, std::int64_t min_A_, std::int64_t min_B_, std::int64_t expire_at_, std::int64_t A_, std::int64_t B_)
  : signed_A_(signed_A_)
  , signed_B_(signed_B_)
  , min_A_(min_A_)
  , min_B_(min_B_)
  , expire_at_(expire_at_)
  , A_(A_)
  , B_(B_)
{}

const std::int32_t pchan_stateClose::ID;

object_ptr<pchan_State> pchan_stateClose::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_stateClose> res = make_object<pchan_stateClose>();
  res->signed_A_ = (env->GetBooleanField(p, res->signed_A_fieldID) != 0);
  res->signed_B_ = (env->GetBooleanField(p, res->signed_B_fieldID) != 0);
  res->min_A_ = env->GetLongField(p, res->min_A_fieldID);
  res->min_B_ = env->GetLongField(p, res->min_B_fieldID);
  res->expire_at_ = env->GetLongField(p, res->expire_at_fieldID);
  res->A_ = env->GetLongField(p, res->A_fieldID);
  res->B_ = env->GetLongField(p, res->B_fieldID);
  return std::move(res);
}

void pchan_stateClose::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetBooleanField(s, signed_A_fieldID, signed_A_);
  env->SetBooleanField(s, signed_B_fieldID, signed_B_);
  env->SetLongField(s, min_A_fieldID, min_A_);
  env->SetLongField(s, min_B_fieldID, min_B_);
  env->SetLongField(s, expire_at_fieldID, expire_at_);
  env->SetLongField(s, A_fieldID, A_);
  env->SetLongField(s, B_fieldID, B_);
}

void pchan_stateClose::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanStateClose");
    s.store_field("signedA", signed_A_);
    s.store_field("signedB", signed_B_);
    s.store_field("minA", min_A_);
    s.store_field("minB", min_B_);
    s.store_field("expireAt", expire_at_);
    s.store_field("A", A_);
    s.store_field("B", B_);
    s.store_class_end();
  }
}

void pchan_stateClose::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanStateClose").c_str());
  signed_A_fieldID = td::jni::get_field_id(env, Class, "signedA", "Z");
  signed_B_fieldID = td::jni::get_field_id(env, Class, "signedB", "Z");
  min_A_fieldID = td::jni::get_field_id(env, Class, "minA", "J");
  min_B_fieldID = td::jni::get_field_id(env, Class, "minB", "J");
  expire_at_fieldID = td::jni::get_field_id(env, Class, "expireAt", "J");
  A_fieldID = td::jni::get_field_id(env, Class, "A", "J");
  B_fieldID = td::jni::get_field_id(env, Class, "B", "J");
}

jclass pchan_statePayout::Class;
jfieldID pchan_statePayout::A_fieldID;
jfieldID pchan_statePayout::B_fieldID;

pchan_statePayout::pchan_statePayout()
  : A_()
  , B_()
{}

pchan_statePayout::pchan_statePayout(std::int64_t A_, std::int64_t B_)
  : A_(A_)
  , B_(B_)
{}

const std::int32_t pchan_statePayout::ID;

object_ptr<pchan_State> pchan_statePayout::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_statePayout> res = make_object<pchan_statePayout>();
  res->A_ = env->GetLongField(p, res->A_fieldID);
  res->B_ = env->GetLongField(p, res->B_fieldID);
  return std::move(res);
}

void pchan_statePayout::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, A_fieldID, A_);
  env->SetLongField(s, B_fieldID, B_);
}

void pchan_statePayout::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanStatePayout");
    s.store_field("A", A_);
    s.store_field("B", B_);
    s.store_class_end();
  }
}

void pchan_statePayout::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanStatePayout").c_str());
  A_fieldID = td::jni::get_field_id(env, Class, "A", "J");
  B_fieldID = td::jni::get_field_id(env, Class, "B", "J");
}

jclass query_fees::Class;
jfieldID query_fees::source_fees_fieldID;
jfieldID query_fees::destination_fees_fieldID;

query_fees::query_fees()
  : source_fees_()
  , destination_fees_()
{}

query_fees::query_fees(object_ptr<fees> &&source_fees_, std::vector<object_ptr<fees>> &&destination_fees_)
  : source_fees_(std::move(source_fees_))
  , destination_fees_(std::move(destination_fees_))
{}

const std::int32_t query_fees::ID;

object_ptr<query_fees> query_fees::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_fees> res = make_object<query_fees>();
  res->source_fees_ = td::jni::fetch_tl_object<fees>(env, td::jni::fetch_object(env, p, res->source_fees_fieldID));;
  res->destination_fees_ = td::jni::FetchVector<fees>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->destination_fees_fieldID));;
  return res;
}

void query_fees::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (source_fees_ != nullptr) { jobject next; source_fees_->store(env, next); if (next) { env->SetObjectField(s, source_fees_fieldID, next); env->DeleteLocalRef(next); } }
  { auto arr_tmp_ = td::jni::store_vector(env, destination_fees_); if (arr_tmp_) { env->SetObjectField(s, destination_fees_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void query_fees::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryFees");
    if (source_fees_ == nullptr) { s.store_field("sourceFees", "null"); } else { source_fees_->store(s, "sourceFees"); }
    { const std::vector<object_ptr<fees>> &v = destination_fees_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("destinationFees", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void query_fees::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryFees").c_str());
  source_fees_fieldID = td::jni::get_field_id(env, Class, "sourceFees", (PSLICE() << "L" << package_name << "/TonApi$Fees;").c_str());
  destination_fees_fieldID = td::jni::get_field_id(env, Class, "destinationFees", (PSLICE() << "[L" << package_name << "/TonApi$Fees;").c_str());
}

jclass query_info::Class;
jfieldID query_info::id_fieldID;
jfieldID query_info::valid_until_fieldID;
jfieldID query_info::body_hash_fieldID;
jfieldID query_info::body_fieldID;
jfieldID query_info::init_state_fieldID;

query_info::query_info()
  : id_()
  , valid_until_()
  , body_hash_()
  , body_()
  , init_state_()
{}

query_info::query_info(std::int64_t id_, std::int64_t valid_until_, std::string const &body_hash_, std::string const &body_, std::string const &init_state_)
  : id_(id_)
  , valid_until_(valid_until_)
  , body_hash_(std::move(body_hash_))
  , body_(std::move(body_))
  , init_state_(std::move(init_state_))
{}

const std::int32_t query_info::ID;

object_ptr<query_info> query_info::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<query_info> res = make_object<query_info>();
  res->id_ = env->GetLongField(p, res->id_fieldID);
  res->valid_until_ = env->GetLongField(p, res->valid_until_fieldID);
  res->body_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_hash_fieldID));
  res->body_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_fieldID));
  res->init_state_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->init_state_fieldID));
  return res;
}

void query_info::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, id_fieldID, id_);
  env->SetLongField(s, valid_until_fieldID, valid_until_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_hash_); if (nextBytes) { env->SetObjectField(s, body_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_); if (nextBytes) { env->SetObjectField(s, body_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, init_state_); if (nextBytes) { env->SetObjectField(s, init_state_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void query_info::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "QueryInfo");
    s.store_field("id", id_);
    s.store_field("validUntil", valid_until_);
    s.store_bytes_field("bodyHash", body_hash_);
    s.store_bytes_field("body", body_);
    s.store_bytes_field("initState", init_state_);
    s.store_class_end();
  }
}

void query_info::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$QueryInfo").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", "J");
  valid_until_fieldID = td::jni::get_field_id(env, Class, "validUntil", "J");
  body_hash_fieldID = td::jni::get_field_id(env, Class, "bodyHash", "[B");
  body_fieldID = td::jni::get_field_id(env, Class, "body", "[B");
  init_state_fieldID = td::jni::get_field_id(env, Class, "initState", "[B");
}

jclass raw_fullAccountState::Class;
jfieldID raw_fullAccountState::balance_fieldID;
jfieldID raw_fullAccountState::code_fieldID;
jfieldID raw_fullAccountState::data_fieldID;
jfieldID raw_fullAccountState::last_transaction_id_fieldID;
jfieldID raw_fullAccountState::block_id_fieldID;
jfieldID raw_fullAccountState::frozen_hash_fieldID;
jfieldID raw_fullAccountState::sync_utime_fieldID;

raw_fullAccountState::raw_fullAccountState()
  : balance_()
  , code_()
  , data_()
  , last_transaction_id_()
  , block_id_()
  , frozen_hash_()
  , sync_utime_()
{}

raw_fullAccountState::raw_fullAccountState(std::int64_t balance_, std::string const &code_, std::string const &data_, object_ptr<internal_transactionId> &&last_transaction_id_, object_ptr<ton_blockIdExt> &&block_id_, std::string const &frozen_hash_, std::int64_t sync_utime_)
  : balance_(balance_)
  , code_(std::move(code_))
  , data_(std::move(data_))
  , last_transaction_id_(std::move(last_transaction_id_))
  , block_id_(std::move(block_id_))
  , frozen_hash_(std::move(frozen_hash_))
  , sync_utime_(sync_utime_)
{}

const std::int32_t raw_fullAccountState::ID;

object_ptr<raw_fullAccountState> raw_fullAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_fullAccountState> res = make_object<raw_fullAccountState>();
  res->balance_ = env->GetLongField(p, res->balance_fieldID);
  res->code_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->code_fieldID));
  res->data_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  res->last_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->last_transaction_id_fieldID));;
  res->block_id_ = td::jni::fetch_tl_object<ton_blockIdExt>(env, td::jni::fetch_object(env, p, res->block_id_fieldID));;
  res->frozen_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->frozen_hash_fieldID));
  res->sync_utime_ = env->GetLongField(p, res->sync_utime_fieldID);
  return res;
}

void raw_fullAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, balance_fieldID, balance_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, code_); if (nextBytes) { env->SetObjectField(s, code_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (last_transaction_id_ != nullptr) { jobject next; last_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, last_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
  if (block_id_ != nullptr) { jobject next; block_id_->store(env, next); if (next) { env->SetObjectField(s, block_id_fieldID, next); env->DeleteLocalRef(next); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, frozen_hash_); if (nextBytes) { env->SetObjectField(s, frozen_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  env->SetLongField(s, sync_utime_fieldID, sync_utime_);
}

void raw_fullAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawFullAccountState");
    s.store_field("balance", balance_);
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    if (last_transaction_id_ == nullptr) { s.store_field("lastTransactionId", "null"); } else { last_transaction_id_->store(s, "lastTransactionId"); }
    if (block_id_ == nullptr) { s.store_field("blockId", "null"); } else { block_id_->store(s, "blockId"); }
    s.store_bytes_field("frozenHash", frozen_hash_);
    s.store_field("syncUtime", sync_utime_);
    s.store_class_end();
  }
}

void raw_fullAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawFullAccountState").c_str());
  balance_fieldID = td::jni::get_field_id(env, Class, "balance", "J");
  code_fieldID = td::jni::get_field_id(env, Class, "code", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
  last_transaction_id_fieldID = td::jni::get_field_id(env, Class, "lastTransactionId", (PSLICE() << "L" << package_name << "/TonApi$InternalTransactionId;").c_str());
  block_id_fieldID = td::jni::get_field_id(env, Class, "blockId", (PSLICE() << "L" << package_name << "/TonApi$TonBlockIdExt;").c_str());
  frozen_hash_fieldID = td::jni::get_field_id(env, Class, "frozenHash", "[B");
  sync_utime_fieldID = td::jni::get_field_id(env, Class, "syncUtime", "J");
}

jclass raw_message::Class;
jfieldID raw_message::source_fieldID;
jfieldID raw_message::destination_fieldID;
jfieldID raw_message::value_fieldID;
jfieldID raw_message::fwd_fee_fieldID;
jfieldID raw_message::ihr_fee_fieldID;
jfieldID raw_message::created_lt_fieldID;
jfieldID raw_message::body_hash_fieldID;
jfieldID raw_message::msg_data_fieldID;

raw_message::raw_message()
  : source_()
  , destination_()
  , value_()
  , fwd_fee_()
  , ihr_fee_()
  , created_lt_()
  , body_hash_()
  , msg_data_()
{}

raw_message::raw_message(object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t value_, std::int64_t fwd_fee_, std::int64_t ihr_fee_, std::int64_t created_lt_, std::string const &body_hash_, object_ptr<msg_Data> &&msg_data_)
  : source_(std::move(source_))
  , destination_(std::move(destination_))
  , value_(value_)
  , fwd_fee_(fwd_fee_)
  , ihr_fee_(ihr_fee_)
  , created_lt_(created_lt_)
  , body_hash_(std::move(body_hash_))
  , msg_data_(std::move(msg_data_))
{}

const std::int32_t raw_message::ID;

object_ptr<raw_message> raw_message::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_message> res = make_object<raw_message>();
  res->source_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->source_fieldID));;
  res->destination_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->destination_fieldID));;
  res->value_ = env->GetLongField(p, res->value_fieldID);
  res->fwd_fee_ = env->GetLongField(p, res->fwd_fee_fieldID);
  res->ihr_fee_ = env->GetLongField(p, res->ihr_fee_fieldID);
  res->created_lt_ = env->GetLongField(p, res->created_lt_fieldID);
  res->body_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->body_hash_fieldID));
  res->msg_data_ = td::jni::fetch_tl_object<msg_Data>(env, td::jni::fetch_object(env, p, res->msg_data_fieldID));;
  return res;
}

void raw_message::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (source_ != nullptr) { jobject next; source_->store(env, next); if (next) { env->SetObjectField(s, source_fieldID, next); env->DeleteLocalRef(next); } }
  if (destination_ != nullptr) { jobject next; destination_->store(env, next); if (next) { env->SetObjectField(s, destination_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetLongField(s, value_fieldID, value_);
  env->SetLongField(s, fwd_fee_fieldID, fwd_fee_);
  env->SetLongField(s, ihr_fee_fieldID, ihr_fee_);
  env->SetLongField(s, created_lt_fieldID, created_lt_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, body_hash_); if (nextBytes) { env->SetObjectField(s, body_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (msg_data_ != nullptr) { jobject next; msg_data_->store(env, next); if (next) { env->SetObjectField(s, msg_data_fieldID, next); env->DeleteLocalRef(next); } }
}

void raw_message::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawMessage");
    if (source_ == nullptr) { s.store_field("source", "null"); } else { source_->store(s, "source"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("value", value_);
    s.store_field("fwdFee", fwd_fee_);
    s.store_field("ihrFee", ihr_fee_);
    s.store_field("createdLt", created_lt_);
    s.store_bytes_field("bodyHash", body_hash_);
    if (msg_data_ == nullptr) { s.store_field("msgData", "null"); } else { msg_data_->store(s, "msgData"); }
    s.store_class_end();
  }
}

void raw_message::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawMessage").c_str());
  source_fieldID = td::jni::get_field_id(env, Class, "source", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  destination_fieldID = td::jni::get_field_id(env, Class, "destination", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  value_fieldID = td::jni::get_field_id(env, Class, "value", "J");
  fwd_fee_fieldID = td::jni::get_field_id(env, Class, "fwdFee", "J");
  ihr_fee_fieldID = td::jni::get_field_id(env, Class, "ihrFee", "J");
  created_lt_fieldID = td::jni::get_field_id(env, Class, "createdLt", "J");
  body_hash_fieldID = td::jni::get_field_id(env, Class, "bodyHash", "[B");
  msg_data_fieldID = td::jni::get_field_id(env, Class, "msgData", (PSLICE() << "L" << package_name << "/TonApi$MsgData;").c_str());
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

jclass rwallet_actionInit::Class;
jfieldID rwallet_actionInit::config_fieldID;

rwallet_actionInit::rwallet_actionInit()
  : config_()
{}

rwallet_actionInit::rwallet_actionInit(object_ptr<rwallet_config> &&config_)
  : config_(std::move(config_))
{}

const std::int32_t rwallet_actionInit::ID;

object_ptr<rwallet_actionInit> rwallet_actionInit::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<rwallet_actionInit> res = make_object<rwallet_actionInit>();
  res->config_ = td::jni::fetch_tl_object<rwallet_config>(env, td::jni::fetch_object(env, p, res->config_fieldID));;
  return res;
}

void rwallet_actionInit::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (config_ != nullptr) { jobject next; config_->store(env, next); if (next) { env->SetObjectField(s, config_fieldID, next); env->DeleteLocalRef(next); } }
}

void rwallet_actionInit::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RwalletActionInit");
    if (config_ == nullptr) { s.store_field("config", "null"); } else { config_->store(s, "config"); }
    s.store_class_end();
  }
}

void rwallet_actionInit::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RwalletActionInit").c_str());
  config_fieldID = td::jni::get_field_id(env, Class, "config", (PSLICE() << "L" << package_name << "/TonApi$RwalletConfig;").c_str());
}

jclass rwallet_config::Class;
jfieldID rwallet_config::start_at_fieldID;
jfieldID rwallet_config::limits_fieldID;

rwallet_config::rwallet_config()
  : start_at_()
  , limits_()
{}

rwallet_config::rwallet_config(std::int64_t start_at_, std::vector<object_ptr<rwallet_limit>> &&limits_)
  : start_at_(start_at_)
  , limits_(std::move(limits_))
{}

const std::int32_t rwallet_config::ID;

object_ptr<rwallet_config> rwallet_config::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<rwallet_config> res = make_object<rwallet_config>();
  res->start_at_ = env->GetLongField(p, res->start_at_fieldID);
  res->limits_ = td::jni::FetchVector<rwallet_limit>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->limits_fieldID));;
  return res;
}

void rwallet_config::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetLongField(s, start_at_fieldID, start_at_);
  { auto arr_tmp_ = td::jni::store_vector(env, limits_); if (arr_tmp_) { env->SetObjectField(s, limits_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void rwallet_config::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RwalletConfig");
    s.store_field("startAt", start_at_);
    { const std::vector<object_ptr<rwallet_limit>> &v = limits_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("limits", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void rwallet_config::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RwalletConfig").c_str());
  start_at_fieldID = td::jni::get_field_id(env, Class, "startAt", "J");
  limits_fieldID = td::jni::get_field_id(env, Class, "limits", (PSLICE() << "[L" << package_name << "/TonApi$RwalletLimit;").c_str());
}

jclass rwallet_limit::Class;
jfieldID rwallet_limit::seconds_fieldID;
jfieldID rwallet_limit::value_fieldID;

rwallet_limit::rwallet_limit()
  : seconds_()
  , value_()
{}

rwallet_limit::rwallet_limit(std::int32_t seconds_, std::int64_t value_)
  : seconds_(seconds_)
  , value_(value_)
{}

const std::int32_t rwallet_limit::ID;

object_ptr<rwallet_limit> rwallet_limit::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<rwallet_limit> res = make_object<rwallet_limit>();
  res->seconds_ = env->GetIntField(p, res->seconds_fieldID);
  res->value_ = env->GetLongField(p, res->value_fieldID);
  return res;
}

void rwallet_limit::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, seconds_fieldID, seconds_);
  env->SetLongField(s, value_fieldID, value_);
}

void rwallet_limit::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RwalletLimit");
    s.store_field("seconds", seconds_);
    s.store_field("value", value_);
    s.store_class_end();
  }
}

void rwallet_limit::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RwalletLimit").c_str());
  seconds_fieldID = td::jni::get_field_id(env, Class, "seconds", "I");
  value_fieldID = td::jni::get_field_id(env, Class, "value", "J");
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

jclass ton_blockIdExt::Class;
jfieldID ton_blockIdExt::workchain_fieldID;
jfieldID ton_blockIdExt::shard_fieldID;
jfieldID ton_blockIdExt::seqno_fieldID;
jfieldID ton_blockIdExt::root_hash_fieldID;
jfieldID ton_blockIdExt::file_hash_fieldID;

ton_blockIdExt::ton_blockIdExt()
  : workchain_()
  , shard_()
  , seqno_()
  , root_hash_()
  , file_hash_()
{}

ton_blockIdExt::ton_blockIdExt(std::int32_t workchain_, std::int64_t shard_, std::int32_t seqno_, std::string const &root_hash_, std::string const &file_hash_)
  : workchain_(workchain_)
  , shard_(shard_)
  , seqno_(seqno_)
  , root_hash_(std::move(root_hash_))
  , file_hash_(std::move(file_hash_))
{}

const std::int32_t ton_blockIdExt::ID;

object_ptr<ton_blockIdExt> ton_blockIdExt::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<ton_blockIdExt> res = make_object<ton_blockIdExt>();
  res->workchain_ = env->GetIntField(p, res->workchain_fieldID);
  res->shard_ = env->GetLongField(p, res->shard_fieldID);
  res->seqno_ = env->GetIntField(p, res->seqno_fieldID);
  res->root_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->root_hash_fieldID));
  res->file_hash_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->file_hash_fieldID));
  return res;
}

void ton_blockIdExt::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  env->SetIntField(s, workchain_fieldID, workchain_);
  env->SetLongField(s, shard_fieldID, shard_);
  env->SetIntField(s, seqno_fieldID, seqno_);
  { jbyteArray nextBytes = td::jni::to_bytes(env, root_hash_); if (nextBytes) { env->SetObjectField(s, root_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  { jbyteArray nextBytes = td::jni::to_bytes(env, file_hash_); if (nextBytes) { env->SetObjectField(s, file_hash_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void ton_blockIdExt::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TonBlockIdExt");
    s.store_field("workchain", workchain_);
    s.store_field("shard", shard_);
    s.store_field("seqno", seqno_);
    s.store_bytes_field("rootHash", root_hash_);
    s.store_bytes_field("fileHash", file_hash_);
    s.store_class_end();
  }
}

void ton_blockIdExt::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TonBlockIdExt").c_str());
  workchain_fieldID = td::jni::get_field_id(env, Class, "workchain", "I");
  shard_fieldID = td::jni::get_field_id(env, Class, "shard", "J");
  seqno_fieldID = td::jni::get_field_id(env, Class, "seqno", "I");
  root_hash_fieldID = td::jni::get_field_id(env, Class, "rootHash", "[B");
  file_hash_fieldID = td::jni::get_field_id(env, Class, "fileHash", "[B");
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
  res->bytes_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->bytes_fieldID));
  return res;
}

void tvm_cell::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, bytes_); if (nextBytes) { env->SetObjectField(s, bytes_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void tvm_cell::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmCell");
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

void tvm_cell::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmCell").c_str());
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "[B");
}

jclass tvm_list::Class;
jfieldID tvm_list::elements_fieldID;

tvm_list::tvm_list()
  : elements_()
{}

tvm_list::tvm_list(std::vector<object_ptr<tvm_StackEntry>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t tvm_list::ID;

object_ptr<tvm_list> tvm_list::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_list> res = make_object<tvm_list>();
  res->elements_ = td::jni::FetchVector<tvm_StackEntry>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->elements_fieldID));;
  return res;
}

void tvm_list::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, elements_); if (arr_tmp_) { env->SetObjectField(s, elements_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void tvm_list::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmList");
    { const std::vector<object_ptr<tvm_StackEntry>> &v = elements_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("elements", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void tvm_list::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmList").c_str());
  elements_fieldID = td::jni::get_field_id(env, Class, "elements", (PSLICE() << "[L" << package_name << "/TonApi$TvmStackEntry;").c_str());
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
  res->bytes_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->bytes_fieldID));
  return res;
}

void tvm_slice::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, bytes_); if (nextBytes) { env->SetObjectField(s, bytes_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void tvm_slice::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmSlice");
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

void tvm_slice::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmSlice").c_str());
  bytes_fieldID = td::jni::get_field_id(env, Class, "bytes", "[B");
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
    case tvm_stackEntryTuple::ID:
      return tvm_stackEntryTuple::fetch(env, p);
    case tvm_stackEntryList::ID:
      return tvm_stackEntryList::fetch(env, p);
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
  tvm_stackEntryTuple::init_jni_vars(env, package_name);
  tvm_stackEntryList::init_jni_vars(env, package_name);
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

jclass tvm_stackEntryTuple::Class;
jfieldID tvm_stackEntryTuple::tuple_fieldID;

tvm_stackEntryTuple::tvm_stackEntryTuple()
  : tuple_()
{}

tvm_stackEntryTuple::tvm_stackEntryTuple(object_ptr<tvm_tuple> &&tuple_)
  : tuple_(std::move(tuple_))
{}

const std::int32_t tvm_stackEntryTuple::ID;

object_ptr<tvm_StackEntry> tvm_stackEntryTuple::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_stackEntryTuple> res = make_object<tvm_stackEntryTuple>();
  res->tuple_ = td::jni::fetch_tl_object<tvm_tuple>(env, td::jni::fetch_object(env, p, res->tuple_fieldID));;
  return std::move(res);
}

void tvm_stackEntryTuple::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (tuple_ != nullptr) { jobject next; tuple_->store(env, next); if (next) { env->SetObjectField(s, tuple_fieldID, next); env->DeleteLocalRef(next); } }
}

void tvm_stackEntryTuple::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmStackEntryTuple");
    if (tuple_ == nullptr) { s.store_field("tuple", "null"); } else { tuple_->store(s, "tuple"); }
    s.store_class_end();
  }
}

void tvm_stackEntryTuple::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntryTuple").c_str());
  tuple_fieldID = td::jni::get_field_id(env, Class, "tuple", (PSLICE() << "L" << package_name << "/TonApi$TvmTuple;").c_str());
}

jclass tvm_stackEntryList::Class;
jfieldID tvm_stackEntryList::list_fieldID;

tvm_stackEntryList::tvm_stackEntryList()
  : list_()
{}

tvm_stackEntryList::tvm_stackEntryList(object_ptr<tvm_list> &&list_)
  : list_(std::move(list_))
{}

const std::int32_t tvm_stackEntryList::ID;

object_ptr<tvm_StackEntry> tvm_stackEntryList::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_stackEntryList> res = make_object<tvm_stackEntryList>();
  res->list_ = td::jni::fetch_tl_object<tvm_list>(env, td::jni::fetch_object(env, p, res->list_fieldID));;
  return std::move(res);
}

void tvm_stackEntryList::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (list_ != nullptr) { jobject next; list_->store(env, next); if (next) { env->SetObjectField(s, list_fieldID, next); env->DeleteLocalRef(next); } }
}

void tvm_stackEntryList::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmStackEntryList");
    if (list_ == nullptr) { s.store_field("list", "null"); } else { list_->store(s, "list"); }
    s.store_class_end();
  }
}

void tvm_stackEntryList::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmStackEntryList").c_str());
  list_fieldID = td::jni::get_field_id(env, Class, "list", (PSLICE() << "L" << package_name << "/TonApi$TvmList;").c_str());
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

jclass tvm_tuple::Class;
jfieldID tvm_tuple::elements_fieldID;

tvm_tuple::tvm_tuple()
  : elements_()
{}

tvm_tuple::tvm_tuple(std::vector<object_ptr<tvm_StackEntry>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t tvm_tuple::ID;

object_ptr<tvm_tuple> tvm_tuple::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<tvm_tuple> res = make_object<tvm_tuple>();
  res->elements_ = td::jni::FetchVector<tvm_StackEntry>::fetch(env, (jobjectArray)td::jni::fetch_object(env, p, res->elements_fieldID));;
  return res;
}

void tvm_tuple::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { auto arr_tmp_ = td::jni::store_vector(env, elements_); if (arr_tmp_) { env->SetObjectField(s, elements_fieldID, arr_tmp_); env->DeleteLocalRef(arr_tmp_); } }
}

void tvm_tuple::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "TvmTuple");
    { const std::vector<object_ptr<tvm_StackEntry>> &v = elements_; const std::uint32_t multiplicity = static_cast<std::uint32_t>(v.size()); const auto vector_name = "Array[" + td::to_string(multiplicity)+ "]"; s.store_class_begin("elements", vector_name.c_str()); for (std::uint32_t i = 0; i < multiplicity; i++) { if (v[i] == nullptr) { s.store_field("", "null"); } else { v[i]->store(s, ""); } } s.store_class_end(); }
    s.store_class_end();
  }
}

void tvm_tuple::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$TvmTuple").c_str());
  elements_fieldID = td::jni::get_field_id(env, Class, "elements", (PSLICE() << "[L" << package_name << "/TonApi$TvmStackEntry;").c_str());
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

jclass createQuery::Class;
jfieldID createQuery::private_key_fieldID;
jfieldID createQuery::address_fieldID;
jfieldID createQuery::timeout_fieldID;
jfieldID createQuery::action_fieldID;
jfieldID createQuery::initial_account_state_fieldID;

createQuery::createQuery()
  : private_key_()
  , address_()
  , timeout_()
  , action_()
  , initial_account_state_()
{}

createQuery::createQuery(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&address_, std::int32_t timeout_, object_ptr<Action> &&action_, object_ptr<InitialAccountState> &&initial_account_state_)
  : private_key_(std::move(private_key_))
  , address_(std::move(address_))
  , timeout_(timeout_)
  , action_(std::move(action_))
  , initial_account_state_(std::move(initial_account_state_))
{}

const std::int32_t createQuery::ID;

object_ptr<createQuery> createQuery::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<createQuery> res = make_object<createQuery>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  res->address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->address_fieldID));;
  res->timeout_ = env->GetIntField(p, res->timeout_fieldID);
  res->action_ = td::jni::fetch_tl_object<Action>(env, td::jni::fetch_object(env, p, res->action_fieldID));;
  res->initial_account_state_ = td::jni::fetch_tl_object<InitialAccountState>(env, td::jni::fetch_object(env, p, res->initial_account_state_fieldID));;
  return res;
}

void createQuery::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (address_ != nullptr) { jobject next; address_->store(env, next); if (next) { env->SetObjectField(s, address_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, timeout_fieldID, timeout_);
  if (action_ != nullptr) { jobject next; action_->store(env, next); if (next) { env->SetObjectField(s, action_fieldID, next); env->DeleteLocalRef(next); } }
  if (initial_account_state_ != nullptr) { jobject next; initial_account_state_->store(env, next); if (next) { env->SetObjectField(s, initial_account_state_fieldID, next); env->DeleteLocalRef(next); } }
}

void createQuery::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "CreateQuery");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
    if (address_ == nullptr) { s.store_field("address", "null"); } else { address_->store(s, "address"); }
    s.store_field("timeout", timeout_);
    if (action_ == nullptr) { s.store_field("action", "null"); } else { action_->store(s, "action"); }
    if (initial_account_state_ == nullptr) { s.store_field("initialAccountState", "null"); } else { initial_account_state_->store(s, "initialAccountState"); }
    s.store_class_end();
  }
}

createQuery::ReturnType createQuery::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return query_info::fetch(env, p);
}

void createQuery::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$CreateQuery").c_str());
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  address_fieldID = td::jni::get_field_id(env, Class, "address", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  timeout_fieldID = td::jni::get_field_id(env, Class, "timeout", "I");
  action_fieldID = td::jni::get_field_id(env, Class, "action", (PSLICE() << "L" << package_name << "/TonApi$Action;").c_str());
  initial_account_state_fieldID = td::jni::get_field_id(env, Class, "initialAccountState", (PSLICE() << "L" << package_name << "/TonApi$InitialAccountState;").c_str());
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

jclass dns_resolve::Class;
jfieldID dns_resolve::account_address_fieldID;
jfieldID dns_resolve::name_fieldID;
jfieldID dns_resolve::category_fieldID;
jfieldID dns_resolve::ttl_fieldID;

dns_resolve::dns_resolve()
  : account_address_()
  , name_()
  , category_()
  , ttl_()
{}

dns_resolve::dns_resolve(object_ptr<accountAddress> &&account_address_, std::string const &name_, std::int32_t category_, std::int32_t ttl_)
  : account_address_(std::move(account_address_))
  , name_(std::move(name_))
  , category_(category_)
  , ttl_(ttl_)
{}

const std::int32_t dns_resolve::ID;

object_ptr<dns_resolve> dns_resolve::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<dns_resolve> res = make_object<dns_resolve>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  res->name_ = td::jni::fetch_string(env, p, res->name_fieldID);
  res->category_ = env->GetIntField(p, res->category_fieldID);
  res->ttl_ = env->GetIntField(p, res->ttl_fieldID);
  return res;
}

void dns_resolve::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
  { jstring nextString = td::jni::to_jstring(env, name_); if (nextString) { env->SetObjectField(s, name_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  env->SetIntField(s, category_fieldID, category_);
  env->SetIntField(s, ttl_fieldID, ttl_);
}

void dns_resolve::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "DnsResolve");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_field("name", name_);
    s.store_field("category", category_);
    s.store_field("ttl", ttl_);
    s.store_class_end();
  }
}

dns_resolve::ReturnType dns_resolve::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return dns_resolved::fetch(env, p);
}

void dns_resolve::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$DnsResolve").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
  name_fieldID = td::jni::get_field_id(env, Class, "name", "Ljava/lang/String;");
  category_fieldID = td::jni::get_field_id(env, Class, "category", "I");
  ttl_fieldID = td::jni::get_field_id(env, Class, "ttl", "I");
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

jclass exportUnencryptedKey::Class;
jfieldID exportUnencryptedKey::input_key_fieldID;

exportUnencryptedKey::exportUnencryptedKey()
  : input_key_()
{}

exportUnencryptedKey::exportUnencryptedKey(object_ptr<InputKey> &&input_key_)
  : input_key_(std::move(input_key_))
{}

const std::int32_t exportUnencryptedKey::ID;

object_ptr<exportUnencryptedKey> exportUnencryptedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<exportUnencryptedKey> res = make_object<exportUnencryptedKey>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  return res;
}

void exportUnencryptedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void exportUnencryptedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ExportUnencryptedKey");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    s.store_class_end();
  }
}

exportUnencryptedKey::ReturnType exportUnencryptedKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return exportedUnencryptedKey::fetch(env, p);
}

void exportUnencryptedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ExportUnencryptedKey").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
}

jclass getAccountAddress::Class;
jfieldID getAccountAddress::initial_account_state_fieldID;
jfieldID getAccountAddress::revision_fieldID;
jfieldID getAccountAddress::workchain_id_fieldID;

getAccountAddress::getAccountAddress()
  : initial_account_state_()
  , revision_()
  , workchain_id_()
{}

getAccountAddress::getAccountAddress(object_ptr<InitialAccountState> &&initial_account_state_, std::int32_t revision_, std::int32_t workchain_id_)
  : initial_account_state_(std::move(initial_account_state_))
  , revision_(revision_)
  , workchain_id_(workchain_id_)
{}

const std::int32_t getAccountAddress::ID;

object_ptr<getAccountAddress> getAccountAddress::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getAccountAddress> res = make_object<getAccountAddress>();
  res->initial_account_state_ = td::jni::fetch_tl_object<InitialAccountState>(env, td::jni::fetch_object(env, p, res->initial_account_state_fieldID));;
  res->revision_ = env->GetIntField(p, res->revision_fieldID);
  res->workchain_id_ = env->GetIntField(p, res->workchain_id_fieldID);
  return res;
}

void getAccountAddress::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (initial_account_state_ != nullptr) { jobject next; initial_account_state_->store(env, next); if (next) { env->SetObjectField(s, initial_account_state_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, revision_fieldID, revision_);
  env->SetIntField(s, workchain_id_fieldID, workchain_id_);
}

void getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetAccountAddress");
    if (initial_account_state_ == nullptr) { s.store_field("initialAccountState", "null"); } else { initial_account_state_->store(s, "initialAccountState"); }
    s.store_field("revision", revision_);
    s.store_field("workchainId", workchain_id_);
    s.store_class_end();
  }
}

getAccountAddress::ReturnType getAccountAddress::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountAddress::fetch(env, p);
}

void getAccountAddress::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetAccountAddress").c_str());
  initial_account_state_fieldID = td::jni::get_field_id(env, Class, "initialAccountState", (PSLICE() << "L" << package_name << "/TonApi$InitialAccountState;").c_str());
  revision_fieldID = td::jni::get_field_id(env, Class, "revision", "I");
  workchain_id_fieldID = td::jni::get_field_id(env, Class, "workchainId", "I");
}

jclass getAccountState::Class;
jfieldID getAccountState::account_address_fieldID;

getAccountState::getAccountState()
  : account_address_()
{}

getAccountState::getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t getAccountState::ID;

object_ptr<getAccountState> getAccountState::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<getAccountState> res = make_object<getAccountState>();
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  return res;
}

void getAccountState::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
}

void getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GetAccountState");
    if (account_address_ == nullptr) { s.store_field("accountAddress", "null"); } else { account_address_->store(s, "accountAddress"); }
    s.store_class_end();
  }
}

getAccountState::ReturnType getAccountState::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return fullAccountState::fetch(env, p);
}

void getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GetAccountState").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
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

jclass guessAccount::Class;
jfieldID guessAccount::public_key_fieldID;
jfieldID guessAccount::rwallet_init_public_key_fieldID;

guessAccount::guessAccount()
  : public_key_()
  , rwallet_init_public_key_()
{}

guessAccount::guessAccount(std::string const &public_key_, std::string const &rwallet_init_public_key_)
  : public_key_(std::move(public_key_))
  , rwallet_init_public_key_(std::move(rwallet_init_public_key_))
{}

const std::int32_t guessAccount::ID;

object_ptr<guessAccount> guessAccount::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<guessAccount> res = make_object<guessAccount>();
  res->public_key_ = td::jni::fetch_string(env, p, res->public_key_fieldID);
  res->rwallet_init_public_key_ = td::jni::fetch_string(env, p, res->rwallet_init_public_key_fieldID);
  return res;
}

void guessAccount::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jstring nextString = td::jni::to_jstring(env, public_key_); if (nextString) { env->SetObjectField(s, public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
  { jstring nextString = td::jni::to_jstring(env, rwallet_init_public_key_); if (nextString) { env->SetObjectField(s, rwallet_init_public_key_fieldID, nextString); env->DeleteLocalRef(nextString); } }
}

void guessAccount::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GuessAccount");
    s.store_field("publicKey", public_key_);
    s.store_field("rwalletInitPublicKey", rwallet_init_public_key_);
    s.store_class_end();
  }
}

guessAccount::ReturnType guessAccount::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountRevisionList::fetch(env, p);
}

void guessAccount::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GuessAccount").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "Ljava/lang/String;");
  rwallet_init_public_key_fieldID = td::jni::get_field_id(env, Class, "rwalletInitPublicKey", "Ljava/lang/String;");
}

jclass guessAccountRevision::Class;
jfieldID guessAccountRevision::initial_account_state_fieldID;
jfieldID guessAccountRevision::workchain_id_fieldID;

guessAccountRevision::guessAccountRevision()
  : initial_account_state_()
  , workchain_id_()
{}

guessAccountRevision::guessAccountRevision(object_ptr<InitialAccountState> &&initial_account_state_, std::int32_t workchain_id_)
  : initial_account_state_(std::move(initial_account_state_))
  , workchain_id_(workchain_id_)
{}

const std::int32_t guessAccountRevision::ID;

object_ptr<guessAccountRevision> guessAccountRevision::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<guessAccountRevision> res = make_object<guessAccountRevision>();
  res->initial_account_state_ = td::jni::fetch_tl_object<InitialAccountState>(env, td::jni::fetch_object(env, p, res->initial_account_state_fieldID));;
  res->workchain_id_ = env->GetIntField(p, res->workchain_id_fieldID);
  return res;
}

void guessAccountRevision::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (initial_account_state_ != nullptr) { jobject next; initial_account_state_->store(env, next); if (next) { env->SetObjectField(s, initial_account_state_fieldID, next); env->DeleteLocalRef(next); } }
  env->SetIntField(s, workchain_id_fieldID, workchain_id_);
}

void guessAccountRevision::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "GuessAccountRevision");
    if (initial_account_state_ == nullptr) { s.store_field("initialAccountState", "null"); } else { initial_account_state_->store(s, "initialAccountState"); }
    s.store_field("workchainId", workchain_id_);
    s.store_class_end();
  }
}

guessAccountRevision::ReturnType guessAccountRevision::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return accountRevisionList::fetch(env, p);
}

void guessAccountRevision::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$GuessAccountRevision").c_str());
  initial_account_state_fieldID = td::jni::get_field_id(env, Class, "initialAccountState", (PSLICE() << "L" << package_name << "/TonApi$InitialAccountState;").c_str());
  workchain_id_fieldID = td::jni::get_field_id(env, Class, "workchainId", "I");
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

jclass importUnencryptedKey::Class;
jfieldID importUnencryptedKey::local_password_fieldID;
jfieldID importUnencryptedKey::exported_unencrypted_key_fieldID;

importUnencryptedKey::importUnencryptedKey()
  : local_password_()
  , exported_unencrypted_key_()
{}

importUnencryptedKey::importUnencryptedKey(td::SecureString &&local_password_, object_ptr<exportedUnencryptedKey> &&exported_unencrypted_key_)
  : local_password_(std::move(local_password_))
  , exported_unencrypted_key_(std::move(exported_unencrypted_key_))
{}

const std::int32_t importUnencryptedKey::ID;

object_ptr<importUnencryptedKey> importUnencryptedKey::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<importUnencryptedKey> res = make_object<importUnencryptedKey>();
  res->local_password_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->local_password_fieldID));
  res->exported_unencrypted_key_ = td::jni::fetch_tl_object<exportedUnencryptedKey>(env, td::jni::fetch_object(env, p, res->exported_unencrypted_key_fieldID));;
  return res;
}

void importUnencryptedKey::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, local_password_); if (nextBytes) { env->SetObjectField(s, local_password_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (exported_unencrypted_key_ != nullptr) { jobject next; exported_unencrypted_key_->store(env, next); if (next) { env->SetObjectField(s, exported_unencrypted_key_fieldID, next); env->DeleteLocalRef(next); } }
}

void importUnencryptedKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ImportUnencryptedKey");
    s.store_bytes_field("localPassword", local_password_);
    if (exported_unencrypted_key_ == nullptr) { s.store_field("exportedUnencryptedKey", "null"); } else { exported_unencrypted_key_->store(s, "exportedUnencryptedKey"); }
    s.store_class_end();
  }
}

importUnencryptedKey::ReturnType importUnencryptedKey::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return key::fetch(env, p);
}

void importUnencryptedKey::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$ImportUnencryptedKey").c_str());
  local_password_fieldID = td::jni::get_field_id(env, Class, "localPassword", "[B");
  exported_unencrypted_key_fieldID = td::jni::get_field_id(env, Class, "exportedUnencryptedKey", (PSLICE() << "L" << package_name << "/TonApi$ExportedUnencryptedKey;").c_str());
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
  return options_info::fetch(env, p);
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

jclass msg_decrypt::Class;
jfieldID msg_decrypt::input_key_fieldID;
jfieldID msg_decrypt::data_fieldID;

msg_decrypt::msg_decrypt()
  : input_key_()
  , data_()
{}

msg_decrypt::msg_decrypt(object_ptr<InputKey> &&input_key_, object_ptr<msg_dataEncryptedArray> &&data_)
  : input_key_(std::move(input_key_))
  , data_(std::move(data_))
{}

const std::int32_t msg_decrypt::ID;

object_ptr<msg_decrypt> msg_decrypt::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_decrypt> res = make_object<msg_decrypt>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  res->data_ = td::jni::fetch_tl_object<msg_dataEncryptedArray>(env, td::jni::fetch_object(env, p, res->data_fieldID));;
  return res;
}

void msg_decrypt::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (data_ != nullptr) { jobject next; data_->store(env, next); if (next) { env->SetObjectField(s, data_fieldID, next); env->DeleteLocalRef(next); } }
}

void msg_decrypt::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDecrypt");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    if (data_ == nullptr) { s.store_field("data", "null"); } else { data_->store(s, "data"); }
    s.store_class_end();
  }
}

msg_decrypt::ReturnType msg_decrypt::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return msg_dataDecryptedArray::fetch(env, p);
}

void msg_decrypt::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDecrypt").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  data_fieldID = td::jni::get_field_id(env, Class, "data", (PSLICE() << "L" << package_name << "/TonApi$MsgDataEncryptedArray;").c_str());
}

jclass msg_decryptWithProof::Class;
jfieldID msg_decryptWithProof::proof_fieldID;
jfieldID msg_decryptWithProof::data_fieldID;

msg_decryptWithProof::msg_decryptWithProof()
  : proof_()
  , data_()
{}

msg_decryptWithProof::msg_decryptWithProof(std::string const &proof_, object_ptr<msg_dataEncrypted> &&data_)
  : proof_(std::move(proof_))
  , data_(std::move(data_))
{}

const std::int32_t msg_decryptWithProof::ID;

object_ptr<msg_decryptWithProof> msg_decryptWithProof::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<msg_decryptWithProof> res = make_object<msg_decryptWithProof>();
  res->proof_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->proof_fieldID));
  res->data_ = td::jni::fetch_tl_object<msg_dataEncrypted>(env, td::jni::fetch_object(env, p, res->data_fieldID));;
  return res;
}

void msg_decryptWithProof::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, proof_); if (nextBytes) { env->SetObjectField(s, proof_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (data_ != nullptr) { jobject next; data_->store(env, next); if (next) { env->SetObjectField(s, data_fieldID, next); env->DeleteLocalRef(next); } }
}

void msg_decryptWithProof::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "MsgDecryptWithProof");
    s.store_bytes_field("proof", proof_);
    if (data_ == nullptr) { s.store_field("data", "null"); } else { data_->store(s, "data"); }
    s.store_class_end();
  }
}

msg_decryptWithProof::ReturnType msg_decryptWithProof::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return msg_Data::fetch(env, p);
}

void msg_decryptWithProof::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$MsgDecryptWithProof").c_str());
  proof_fieldID = td::jni::get_field_id(env, Class, "proof", "[B");
  data_fieldID = td::jni::get_field_id(env, Class, "data", (PSLICE() << "L" << package_name << "/TonApi$MsgDataEncrypted;").c_str());
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
  return options_configInfo::fetch(env, p);
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

jclass pchan_packPromise::Class;
jfieldID pchan_packPromise::promise_fieldID;

pchan_packPromise::pchan_packPromise()
  : promise_()
{}

pchan_packPromise::pchan_packPromise(object_ptr<pchan_promise> &&promise_)
  : promise_(std::move(promise_))
{}

const std::int32_t pchan_packPromise::ID;

object_ptr<pchan_packPromise> pchan_packPromise::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_packPromise> res = make_object<pchan_packPromise>();
  res->promise_ = td::jni::fetch_tl_object<pchan_promise>(env, td::jni::fetch_object(env, p, res->promise_fieldID));;
  return res;
}

void pchan_packPromise::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (promise_ != nullptr) { jobject next; promise_->store(env, next); if (next) { env->SetObjectField(s, promise_fieldID, next); env->DeleteLocalRef(next); } }
}

void pchan_packPromise::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanPackPromise");
    if (promise_ == nullptr) { s.store_field("promise", "null"); } else { promise_->store(s, "promise"); }
    s.store_class_end();
  }
}

pchan_packPromise::ReturnType pchan_packPromise::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return data::fetch(env, p);
}

void pchan_packPromise::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanPackPromise").c_str());
  promise_fieldID = td::jni::get_field_id(env, Class, "promise", (PSLICE() << "L" << package_name << "/TonApi$PchanPromise;").c_str());
}

jclass pchan_signPromise::Class;
jfieldID pchan_signPromise::input_key_fieldID;
jfieldID pchan_signPromise::promise_fieldID;

pchan_signPromise::pchan_signPromise()
  : input_key_()
  , promise_()
{}

pchan_signPromise::pchan_signPromise(object_ptr<InputKey> &&input_key_, object_ptr<pchan_promise> &&promise_)
  : input_key_(std::move(input_key_))
  , promise_(std::move(promise_))
{}

const std::int32_t pchan_signPromise::ID;

object_ptr<pchan_signPromise> pchan_signPromise::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_signPromise> res = make_object<pchan_signPromise>();
  res->input_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->input_key_fieldID));;
  res->promise_ = td::jni::fetch_tl_object<pchan_promise>(env, td::jni::fetch_object(env, p, res->promise_fieldID));;
  return res;
}

void pchan_signPromise::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (input_key_ != nullptr) { jobject next; input_key_->store(env, next); if (next) { env->SetObjectField(s, input_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (promise_ != nullptr) { jobject next; promise_->store(env, next); if (next) { env->SetObjectField(s, promise_fieldID, next); env->DeleteLocalRef(next); } }
}

void pchan_signPromise::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanSignPromise");
    if (input_key_ == nullptr) { s.store_field("inputKey", "null"); } else { input_key_->store(s, "inputKey"); }
    if (promise_ == nullptr) { s.store_field("promise", "null"); } else { promise_->store(s, "promise"); }
    s.store_class_end();
  }
}

pchan_signPromise::ReturnType pchan_signPromise::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return pchan_promise::fetch(env, p);
}

void pchan_signPromise::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanSignPromise").c_str());
  input_key_fieldID = td::jni::get_field_id(env, Class, "inputKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
  promise_fieldID = td::jni::get_field_id(env, Class, "promise", (PSLICE() << "L" << package_name << "/TonApi$PchanPromise;").c_str());
}

jclass pchan_unpackPromise::Class;
jfieldID pchan_unpackPromise::data_fieldID;

pchan_unpackPromise::pchan_unpackPromise()
  : data_()
{}

pchan_unpackPromise::pchan_unpackPromise(td::SecureString &&data_)
  : data_(std::move(data_))
{}

const std::int32_t pchan_unpackPromise::ID;

object_ptr<pchan_unpackPromise> pchan_unpackPromise::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_unpackPromise> res = make_object<pchan_unpackPromise>();
  res->data_ = td::jni::from_bytes_secure(env, (jbyteArray)td::jni::fetch_object(env, p, res->data_fieldID));
  return res;
}

void pchan_unpackPromise::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes_secure(env, data_); if (nextBytes) { env->SetObjectField(s, data_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
}

void pchan_unpackPromise::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanUnpackPromise");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

pchan_unpackPromise::ReturnType pchan_unpackPromise::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return pchan_promise::fetch(env, p);
}

void pchan_unpackPromise::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanUnpackPromise").c_str());
  data_fieldID = td::jni::get_field_id(env, Class, "data", "[B");
}

jclass pchan_validatePromise::Class;
jfieldID pchan_validatePromise::public_key_fieldID;
jfieldID pchan_validatePromise::promise_fieldID;

pchan_validatePromise::pchan_validatePromise()
  : public_key_()
  , promise_()
{}

pchan_validatePromise::pchan_validatePromise(std::string const &public_key_, object_ptr<pchan_promise> &&promise_)
  : public_key_(std::move(public_key_))
  , promise_(std::move(promise_))
{}

const std::int32_t pchan_validatePromise::ID;

object_ptr<pchan_validatePromise> pchan_validatePromise::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<pchan_validatePromise> res = make_object<pchan_validatePromise>();
  res->public_key_ = td::jni::from_bytes(env, (jbyteArray)td::jni::fetch_object(env, p, res->public_key_fieldID));
  res->promise_ = td::jni::fetch_tl_object<pchan_promise>(env, td::jni::fetch_object(env, p, res->promise_fieldID));;
  return res;
}

void pchan_validatePromise::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  { jbyteArray nextBytes = td::jni::to_bytes(env, public_key_); if (nextBytes) { env->SetObjectField(s, public_key_fieldID, nextBytes); env->DeleteLocalRef(nextBytes); } }
  if (promise_ != nullptr) { jobject next; promise_->store(env, next); if (next) { env->SetObjectField(s, promise_fieldID, next); env->DeleteLocalRef(next); } }
}

void pchan_validatePromise::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "PchanValidatePromise");
    s.store_bytes_field("publicKey", public_key_);
    if (promise_ == nullptr) { s.store_field("promise", "null"); } else { promise_->store(s, "promise"); }
    s.store_class_end();
  }
}

pchan_validatePromise::ReturnType pchan_validatePromise::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return ok::fetch(env, p);
}

void pchan_validatePromise::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$PchanValidatePromise").c_str());
  public_key_fieldID = td::jni::get_field_id(env, Class, "publicKey", "[B");
  promise_fieldID = td::jni::get_field_id(env, Class, "promise", (PSLICE() << "L" << package_name << "/TonApi$PchanPromise;").c_str());
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
  return raw_fullAccountState::fetch(env, p);
}

void raw_getAccountState::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$RawGetAccountState").c_str());
  account_address_fieldID = td::jni::get_field_id(env, Class, "accountAddress", (PSLICE() << "L" << package_name << "/TonApi$AccountAddress;").c_str());
}

jclass raw_getTransactions::Class;
jfieldID raw_getTransactions::private_key_fieldID;
jfieldID raw_getTransactions::account_address_fieldID;
jfieldID raw_getTransactions::from_transaction_id_fieldID;

raw_getTransactions::raw_getTransactions()
  : private_key_()
  , account_address_()
  , from_transaction_id_()
{}

raw_getTransactions::raw_getTransactions(object_ptr<InputKey> &&private_key_, object_ptr<accountAddress> &&account_address_, object_ptr<internal_transactionId> &&from_transaction_id_)
  : private_key_(std::move(private_key_))
  , account_address_(std::move(account_address_))
  , from_transaction_id_(std::move(from_transaction_id_))
{}

const std::int32_t raw_getTransactions::ID;

object_ptr<raw_getTransactions> raw_getTransactions::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<raw_getTransactions> res = make_object<raw_getTransactions>();
  res->private_key_ = td::jni::fetch_tl_object<InputKey>(env, td::jni::fetch_object(env, p, res->private_key_fieldID));;
  res->account_address_ = td::jni::fetch_tl_object<accountAddress>(env, td::jni::fetch_object(env, p, res->account_address_fieldID));;
  res->from_transaction_id_ = td::jni::fetch_tl_object<internal_transactionId>(env, td::jni::fetch_object(env, p, res->from_transaction_id_fieldID));;
  return res;
}

void raw_getTransactions::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (private_key_ != nullptr) { jobject next; private_key_->store(env, next); if (next) { env->SetObjectField(s, private_key_fieldID, next); env->DeleteLocalRef(next); } }
  if (account_address_ != nullptr) { jobject next; account_address_->store(env, next); if (next) { env->SetObjectField(s, account_address_fieldID, next); env->DeleteLocalRef(next); } }
  if (from_transaction_id_ != nullptr) { jobject next; from_transaction_id_->store(env, next); if (next) { env->SetObjectField(s, from_transaction_id_fieldID, next); env->DeleteLocalRef(next); } }
}

void raw_getTransactions::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "RawGetTransactions");
    if (private_key_ == nullptr) { s.store_field("privateKey", "null"); } else { private_key_->store(s, "privateKey"); }
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
  private_key_fieldID = td::jni::get_field_id(env, Class, "privateKey", (PSLICE() << "L" << package_name << "/TonApi$InputKey;").c_str());
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
  return ton_blockIdExt::fetch(env, p);
}

void sync::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$Sync").c_str());
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

jclass withBlock::Class;
jfieldID withBlock::id_fieldID;
jfieldID withBlock::function_fieldID;

withBlock::withBlock()
  : id_()
  , function_()
{}

withBlock::withBlock(object_ptr<ton_blockIdExt> &&id_, object_ptr<Function> &&function_)
  : id_(std::move(id_))
  , function_(std::move(function_))
{}

const std::int32_t withBlock::ID;

object_ptr<withBlock> withBlock::fetch(JNIEnv *env, jobject &p) {
  if (p == nullptr) return nullptr;
  object_ptr<withBlock> res = make_object<withBlock>();
  res->id_ = td::jni::fetch_tl_object<ton_blockIdExt>(env, td::jni::fetch_object(env, p, res->id_fieldID));;
  res->function_ = td::jni::fetch_tl_object<Function>(env, td::jni::fetch_object(env, p, res->function_fieldID));;
  return res;
}

void withBlock::store(JNIEnv *env, jobject &s) const {
  s = env->AllocObject(Class);
  if (!s) { return; }
  if (id_ != nullptr) { jobject next; id_->store(env, next); if (next) { env->SetObjectField(s, id_fieldID, next); env->DeleteLocalRef(next); } }
  if (function_ != nullptr) { jobject next; function_->store(env, next); if (next) { env->SetObjectField(s, function_fieldID, next); env->DeleteLocalRef(next); } }
}

void withBlock::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "WithBlock");
    if (id_ == nullptr) { s.store_field("id", "null"); } else { id_->store(s, "id"); }
    if (function_ == nullptr) { s.store_field("function", "null"); } else { function_->store(s, "function"); }
    s.store_class_end();
  }
}

withBlock::ReturnType withBlock::fetch_result(JNIEnv *env, jobject &p) {
  if (p == nullptr) return ReturnType();
  return Object::fetch(env, p);
}

void withBlock::init_jni_vars(JNIEnv *env, const char *package_name) {
  Class = td::jni::get_jclass(env, (PSLICE() << package_name << "/TonApi$WithBlock").c_str());
  id_fieldID = td::jni::get_field_id(env, Class, "id", (PSLICE() << "L" << package_name << "/TonApi$TonBlockIdExt;").c_str());
  function_fieldID = td::jni::get_field_id(env, Class, "function", (PSLICE() << "L" << package_name << "/TonApi$Function;").c_str());
}
}  // namespace tonlib_api
}  // namespace ton
