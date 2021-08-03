#include "auto/tl/ton_api_json.h"

#include "auto/tl/ton_api.h"
#include "auto/tl/ton_api.hpp"

#include "tl/tl_json.h"

#include "td/utils/base64.h"
#include "td/utils/common.h"
#include "td/utils/Slice.h"

#include <functional>
#include <unordered_map>

namespace ton {
namespace ton_api{
  using namespace td;
Result<int32> tl_constructor_from_string(ton_api::Hashable *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"hashable.bool", -815709156},
    {"hashable.int32", -743074986},
    {"hashable.int64", -405107134},
    {"hashable.int256", 975377359},
    {"hashable.bytes", 118742546},
    {"hashable.pair", -941266795},
    {"hashable.vector", -550190227},
    {"hashable.validatorSessionOldRound", 1200318377},
    {"hashable.validatorSessionRoundAttempt", 1276247981},
    {"hashable.validatorSessionRound", 897011683},
    {"hashable.blockSignature", 937530018},
    {"hashable.sentBlock", -1111911125},
    {"hashable.sentBlockEmpty", -1628289361},
    {"hashable.vote", -1363203131},
    {"hashable.blockCandidate", 195670285},
    {"hashable.blockVoteCandidate", -821202971},
    {"hashable.blockCandidateAttempt", 1063025931},
    {"hashable.cntVector", 187199288},
    {"hashable.cntSortedVector", 2073445977},
    {"hashable.validatorSession", 1746035669}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::PrivateKey *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"pk.unenc", -1311007952},
    {"pk.ed25519", 1231561495},
    {"pk.aes", -1511501513},
    {"pk.overlay", 933623387}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::PublicKey *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"pub.unenc", -1239464694},
    {"pub.ed25519", 1209251014},
    {"pub.aes", 767339988},
    {"pub.overlay", 884622795}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::TestObject *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"testObject", -1521006198},
    {"testString", -934972983},
    {"testInt", 731271633},
    {"testVectorBytes", 1267407827}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::adnl_Address *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"adnl.address.udp", 1728947943},
    {"adnl.address.udp6", -484613126},
    {"adnl.address.tunnel", 153813739}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::adnl_Message *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"adnl.message.createChannel", -428620869},
    {"adnl.message.confirmChannel", 1625103721},
    {"adnl.message.custom", 541595893},
    {"adnl.message.nop", 402186202},
    {"adnl.message.reinit", 281150752},
    {"adnl.message.query", -1265895046},
    {"adnl.message.answer", 262964246},
    {"adnl.message.part", -45798087}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::adnl_Proxy *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"adnl.proxy.none", 892487803},
    {"adnl.proxy.fast", 982205877}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::adnl_ProxyControlPacket *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"adnl.proxyControlPacketPing", 932635723},
    {"adnl.proxyControlPacketPong", 1272044540},
    {"adnl.proxyControlPacketRegister", -1022774721}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::catchain_BlockResult *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"catchain.blockNotFound", -1240397692},
    {"catchain.blockResult", -1658179513}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::catchain_Difference *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"catchain.difference", 336974282},
    {"catchain.differenceFork", 1227341935}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::catchain_block_inner_Data *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"catchain.block.data.badBlock", -1241359786},
    {"catchain.block.data.fork", 1685731922},
    {"catchain.block.data.nop", 1417852112},
    {"catchain.block.data.vector", 1688809258}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_block_Info *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.block.info", 1254549287},
    {"db.block.packedInfo", 1186697618},
    {"db.block.archivedInfo", 543128145}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_blockdb_Key *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.blockdb.key.lru", 1354536506},
    {"db.blockdb.key.value", 2136461683}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_filedb_Key *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.filedb.key.empty", 2080319307},
    {"db.filedb.key.blockFile", -1326783375},
    {"db.filedb.key.zeroStateFile", 307398205},
    {"db.filedb.key.persistentStateFile", -1346996660},
    {"db.filedb.key.proof", -627749396},
    {"db.filedb.key.proofLink", -1728330290},
    {"db.filedb.key.signatures", -685175541},
    {"db.filedb.key.candidate", -494269767},
    {"db.filedb.key.blockInfo", -996551428}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_files_Key *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.files.index.key", 2109998338},
    {"db.files.package.key", -1526463682}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_lt_Key *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.lt.el.key", -1523442974},
    {"db.lt.desc.key", -236722287},
    {"db.lt.shard.key", 1353120015},
    {"db.lt.status.key", 2003591255}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_root_Key *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.root.key.cellDb", 1928966974},
    {"db.root.key.blockDb", 806534976},
    {"db.root.key.config", 331559556}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::db_state_Key *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"db.state.key.destroyedSessions", -386404007},
    {"db.state.key.initBlockId", 1971484899},
    {"db.state.key.gcBlockId", -1015417890},
    {"db.state.key.shardClient", -912576121},
    {"db.state.key.asyncSerializer", 699304479},
    {"db.state.key.hardforks", -420206662},
    {"db.state.key.dbVersion", 1917788500}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::dht_UpdateRule *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"dht.updateRule.signature", -861982217},
    {"dht.updateRule.anybody", 1633127956},
    {"dht.updateRule.overlayNodes", 645370755}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::dht_ValueResult *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"dht.valueNotFound", -1570634392},
    {"dht.valueFound", -468912268}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::dht_config_Local *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"dht.config.local", 1981827695},
    {"dht.config.random.local", -1679088265}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::engine_Addr *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"engine.addr", -281993236},
    {"engine.addrProxy", -1965071031}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::fec_Type *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"fec.raptorQ", -1953257504},
    {"fec.roundRobin", 854927588},
    {"fec.online", 19359244}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::liteserver_config_Local *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"liteserver.config.local", 1182002063},
    {"liteserver.config.random.local", 2093565243}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::overlay_Broadcast *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"overlay.fec.received", -715385620},
    {"overlay.fec.completed", 165112084},
    {"overlay.unicast", 861097508},
    {"overlay.broadcast", -1319490709},
    {"overlay.broadcastFec", -1160264854},
    {"overlay.broadcastFecShort", -242740414},
    {"overlay.broadcastNotFound", -1786366428}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::overlay_Certificate *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"overlay.certificate", -526461135},
    {"overlay.emptyCertificate", 853195983}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::rldp_Message *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"rldp.message", 2098973982},
    {"rldp.query", -1971761815},
    {"rldp.answer", -1543742461}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::rldp_MessagePart *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"rldp.messagePart", 408691404},
    {"rldp.confirm", -175973288},
    {"rldp.complete", -1140018497}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::rldp2_MessagePart *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"rldp2.messagePart", 289934190},
    {"rldp2.confirm", 602315077},
    {"rldp2.complete", 918095903}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::storage_Update *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"storage.updateInit", 1851782872},
    {"storage.updateHavePieces", 1006116937},
    {"storage.updateState", 95433909}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tcp_Message *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tcp.authentificate", 1146858258},
    {"tcp.authentificationNonce", -480425290},
    {"tcp.authentificationComplete", -139616602}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::ton_BlockId *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"ton.blockId", -989106576},
    {"ton.blockIdApprove", 768887369}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_ArchiveInfo *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.archiveNotFound", -1725360509},
    {"tonNode.archiveInfo", 435158924}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_BlockDescription *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.blockDescriptionEmpty", -2088456555},
    {"tonNode.blockDescription", 1185009800}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_Broadcast *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.blockBroadcast", -1372712699},
    {"tonNode.ihrMessageBroadcast", 1381868723},
    {"tonNode.externalMessageBroadcast", 1025185895},
    {"tonNode.newShardBlockBroadcast", 183696060}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_DataFull *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.dataFull", -1101488237},
    {"tonNode.dataFullEmpty", 1466861002}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_Prepared *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.prepared", -356205619},
    {"tonNode.notFound", -490521178}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_PreparedProof *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.preparedProofEmpty", -949370502},
    {"tonNode.preparedProof", -1986028981},
    {"tonNode.preparedProofLink", 1040134797}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::tonNode_PreparedState *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"tonNode.preparedState", 928762733},
    {"tonNode.notFoundState", 842598993}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::validator_Group *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"validator.group", -120029535},
    {"validator.groupEx", 479350270},
    {"validator.groupNew", -1740398259}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::validator_config_Local *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"validator.config.local", 1716256616},
    {"validator.config.random.local", 1501795426}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::validatorSession_Config *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"validatorSession.config", -1235092029},
    {"validatorSession.configNew", -139482724}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::validatorSession_Message *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"validatorSession.message.startSession", -1767807279},
    {"validatorSession.message.finishSession", -879025437}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::validatorSession_round_Message *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"validatorSession.message.submittedBlock", 309732534},
    {"validatorSession.message.approvedBlock", 77968769},
    {"validatorSession.message.rejectedBlock", -1786229141},
    {"validatorSession.message.commit", -1408065803},
    {"validatorSession.message.vote", -1707978297},
    {"validatorSession.message.voteFor", 1643183663},
    {"validatorSession.message.precommit", -1470843566},
    {"validatorSession.message.empty", 1243619241}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::Object *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"hashable.bool", -815709156},
    {"hashable.int32", -743074986},
    {"hashable.int64", -405107134},
    {"hashable.int256", 975377359},
    {"hashable.bytes", 118742546},
    {"hashable.pair", -941266795},
    {"hashable.vector", -550190227},
    {"hashable.validatorSessionOldRound", 1200318377},
    {"hashable.validatorSessionRoundAttempt", 1276247981},
    {"hashable.validatorSessionRound", 897011683},
    {"hashable.blockSignature", 937530018},
    {"hashable.sentBlock", -1111911125},
    {"hashable.sentBlockEmpty", -1628289361},
    {"hashable.vote", -1363203131},
    {"hashable.blockCandidate", 195670285},
    {"hashable.blockVoteCandidate", -821202971},
    {"hashable.blockCandidateAttempt", 1063025931},
    {"hashable.cntVector", 187199288},
    {"hashable.cntSortedVector", 2073445977},
    {"hashable.validatorSession", 1746035669},
    {"storage.ok", -1020584955},
    {"pk.unenc", -1311007952},
    {"pk.ed25519", 1231561495},
    {"pk.aes", -1511501513},
    {"pk.overlay", 933623387},
    {"pub.unenc", -1239464694},
    {"pub.ed25519", 1209251014},
    {"pub.aes", 767339988},
    {"pub.overlay", 884622795},
    {"testObject", -1521006198},
    {"testString", -934972983},
    {"testInt", 731271633},
    {"testVectorBytes", 1267407827},
    {"adnl.address.udp", 1728947943},
    {"adnl.address.udp6", -484613126},
    {"adnl.address.tunnel", 153813739},
    {"adnl.addressList", 573040216},
    {"adnl.message.createChannel", -428620869},
    {"adnl.message.confirmChannel", 1625103721},
    {"adnl.message.custom", 541595893},
    {"adnl.message.nop", 402186202},
    {"adnl.message.reinit", 281150752},
    {"adnl.message.query", -1265895046},
    {"adnl.message.answer", 262964246},
    {"adnl.message.part", -45798087},
    {"adnl.node", 1800802949},
    {"adnl.nodes", -1576412330},
    {"adnl.packetContents", -784151159},
    {"adnl.pong", 544504846},
    {"adnl.proxy.none", 892487803},
    {"adnl.proxy.fast", 982205877},
    {"adnl.proxyControlPacketPing", 932635723},
    {"adnl.proxyControlPacketPong", 1272044540},
    {"adnl.proxyControlPacketRegister", -1022774721},
    {"adnl.proxyPacketHeader", 141114488},
    {"adnl.proxyToFastHash", -574752674},
    {"adnl.proxyToFast", -1259462186},
    {"adnl.tunnelPacketContents", -980338508},
    {"adnl.config.global", -1099988784},
    {"adnl.db.node.key", -979114962},
    {"adnl.db.node.value", 1415390983},
    {"adnl.id.short", 1044342095},
    {"catchain.block", -699055756},
    {"catchain.blockNotFound", -1240397692},
    {"catchain.blockResult", -1658179513},
    {"catchain.blocks", 1357697473},
    {"catchain.difference", 336974282},
    {"catchain.differenceFork", 1227341935},
    {"catchain.firstblock", 281609467},
    {"catchain.sent", -84454993},
    {"catchain.blockUpdate", 593975492},
    {"catchain.block.data", -122903008},
    {"catchain.block.dep", 1511706959},
    {"catchain.block.id", 620665018},
    {"catchain.block.data.badBlock", -1241359786},
    {"catchain.block.data.fork", 1685731922},
    {"catchain.block.data.nop", 1417852112},
    {"catchain.block.data.vector", 1688809258},
    {"catchain.config.global", 1757918801},
    {"config.global", -198795310},
    {"config.local", 2023657820},
    {"control.config.local", 1964895469},
    {"db.candidate", 1708747482},
    {"db.block.info", 1254549287},
    {"db.block.packedInfo", 1186697618},
    {"db.block.archivedInfo", 543128145},
    {"db.blockdb.key.lru", 1354536506},
    {"db.blockdb.key.value", 2136461683},
    {"db.blockdb.lru", -1055500877},
    {"db.blockdb.value", -1299266515},
    {"db.candidate.id", 935375495},
    {"db.celldb.value", -435153856},
    {"db.celldb.key.value", 1538341155},
    {"db.filedb.key.empty", 2080319307},
    {"db.filedb.key.blockFile", -1326783375},
    {"db.filedb.key.zeroStateFile", 307398205},
    {"db.filedb.key.persistentStateFile", -1346996660},
    {"db.filedb.key.proof", -627749396},
    {"db.filedb.key.proofLink", -1728330290},
    {"db.filedb.key.signatures", -685175541},
    {"db.filedb.key.candidate", -494269767},
    {"db.filedb.key.blockInfo", -996551428},
    {"db.filedb.value", -220390867},
    {"db.files.index.key", 2109998338},
    {"db.files.package.key", -1526463682},
    {"db.files.index.value", -1565402372},
    {"db.files.package.firstBlock", 1880254951},
    {"db.files.package.value", -464726741},
    {"db.lt.el.key", -1523442974},
    {"db.lt.desc.key", -236722287},
    {"db.lt.shard.key", 1353120015},
    {"db.lt.status.key", 2003591255},
    {"db.lt.desc.value", 1907315124},
    {"db.lt.el.value", -1780064412},
    {"db.lt.shard.value", 1014209147},
    {"db.lt.status.value", -88150727},
    {"db.root.config", -703495519},
    {"db.root.dbDescription", -1273465869},
    {"db.root.key.cellDb", 1928966974},
    {"db.root.key.blockDb", 806534976},
    {"db.root.key.config", 331559556},
    {"db.state.asyncSerializer", -751883871},
    {"db.state.dbVersion", -650698505},
    {"db.state.destroyedSessions", -1381443196},
    {"db.state.gcBlockId", -550453937},
    {"db.state.hardforks", -2047668988},
    {"db.state.initBlockId", 1932303605},
    {"db.state.key.destroyedSessions", -386404007},
    {"db.state.key.initBlockId", 1971484899},
    {"db.state.key.gcBlockId", -1015417890},
    {"db.state.key.shardClient", -912576121},
    {"db.state.key.asyncSerializer", 699304479},
    {"db.state.key.hardforks", -420206662},
    {"db.state.key.dbVersion", 1917788500},
    {"db.state.shardClient", 186033821},
    {"dht.key", -160964977},
    {"dht.keyDescription", 673009157},
    {"dht.message", -1140008050},
    {"dht.node", -2074922424},
    {"dht.nodes", 2037686462},
    {"dht.pong", 1519054721},
    {"dht.stored", 1881602824},
    {"dht.updateRule.signature", -861982217},
    {"dht.updateRule.anybody", 1633127956},
    {"dht.updateRule.overlayNodes", 645370755},
    {"dht.value", -1867700277},
    {"dht.valueNotFound", -1570634392},
    {"dht.valueFound", -468912268},
    {"dht.config.global", -2066822649},
    {"dht.config.local", 1981827695},
    {"dht.config.random.local", -1679088265},
    {"dht.db.bucket", -1281557908},
    {"dht.db.key.bucket", -1553420724},
    {"dummyworkchain0.config.global", -631148845},
    {"engine.addr", -281993236},
    {"engine.addrProxy", -1965071031},
    {"engine.adnl", 1658283344},
    {"engine.controlInterface", 830566315},
    {"engine.controlProcess", 1790986263},
    {"engine.dht", 1575613178},
    {"engine.gc", -1078093701},
    {"engine.liteServer", -1150251266},
    {"engine.validator", -2006980055},
    {"engine.validatorAdnlAddress", -750434882},
    {"engine.validatorTempKey", 1581962974},
    {"engine.adnlProxy.config", 1848000769},
    {"engine.adnlProxy.port", -117344950},
    {"engine.dht.config", -197295930},
    {"engine.validator.config", -826140252},
    {"engine.validator.controlQueryError", 1999018527},
    {"engine.validator.dhtServerStatus", -1323440290},
    {"engine.validator.dhtServersStatus", 725155112},
    {"engine.validator.electionBid", 598899261},
    {"engine.validator.fullNodeMaster", -2071595416},
    {"engine.validator.fullNodeSlave", -2010813575},
    {"validator.groupMember", -1953208860},
    {"engine.validator.jsonConfig", 321753611},
    {"engine.validator.keyHash", -1027168946},
    {"engine.validator.oneStat", -1533527315},
    {"engine.validator.proposalVote", 2137401069},
    {"engine.validator.signature", -76791000},
    {"engine.validator.stats", 1565119343},
    {"engine.validator.success", -1276860789},
    {"engine.validator.time", -547380738},
    {"fec.raptorQ", -1953257504},
    {"fec.roundRobin", 854927588},
    {"fec.online", 19359244},
    {"http.header", -1902385903},
    {"http.payloadPart", 693819236},
    {"http.response", -273307789},
    {"http.server.config", 974419964},
    {"http.server.dnsEntry", -663592810},
    {"http.server.host", -981605721},
    {"id.config.local", -1834367090},
    {"liteclient.config.global", 143507704},
    {"liteserver.desc", -1001806732},
    {"liteserver.config.local", 1182002063},
    {"liteserver.config.random.local", 2093565243},
    {"overlay.fec.received", -715385620},
    {"overlay.fec.completed", 165112084},
    {"overlay.unicast", 861097508},
    {"overlay.broadcast", -1319490709},
    {"overlay.broadcastFec", -1160264854},
    {"overlay.broadcastFecShort", -242740414},
    {"overlay.broadcastNotFound", -1786366428},
    {"overlay.broadcastList", 416407263},
    {"overlay.certificate", -526461135},
    {"overlay.emptyCertificate", 853195983},
    {"overlay.certificateId", -1884397383},
    {"overlay.message", 1965368352},
    {"overlay.node", -1200911741},
    {"overlay.nodes", -460904178},
    {"overlay.broadcast.id", 1375565978},
    {"overlay.broadcast.toSign", -97038724},
    {"overlay.broadcastFec.id", -80652890},
    {"overlay.broadcastFec.partId", -1536597296},
    {"overlay.db.key.nodes", -992972010},
    {"overlay.db.nodes", -712454630},
    {"overlay.node.toSign", 64530657},
    {"rldp.message", 2098973982},
    {"rldp.query", -1971761815},
    {"rldp.answer", -1543742461},
    {"rldp.messagePart", 408691404},
    {"rldp.confirm", -175973288},
    {"rldp.complete", -1140018497},
    {"rldp2.messagePart", 289934190},
    {"rldp2.confirm", 602315077},
    {"rldp2.complete", 918095903},
    {"storage.piece", -2135623155},
    {"storage.pong", 1828046501},
    {"storage.state", 856912010},
    {"storage.updateInit", 1851782872},
    {"storage.updateHavePieces", 1006116937},
    {"storage.updateState", 95433909},
    {"tcp.authentificate", 1146858258},
    {"tcp.authentificationNonce", -480425290},
    {"tcp.authentificationComplete", -139616602},
    {"tcp.pong", -597034237},
    {"ton.blockId", -989106576},
    {"ton.blockIdApprove", 768887369},
    {"tonNode.archiveNotFound", -1725360509},
    {"tonNode.archiveInfo", 435158924},
    {"tonNode.blockDescriptionEmpty", -2088456555},
    {"tonNode.blockDescription", 1185009800},
    {"tonNode.blockId", -1211256473},
    {"tonNode.blockIdExt", 1733487480},
    {"tonNode.blockSignature", 1357921331},
    {"tonNode.blocksDescription", -701865684},
    {"tonNode.blockBroadcast", -1372712699},
    {"tonNode.ihrMessageBroadcast", 1381868723},
    {"tonNode.externalMessageBroadcast", 1025185895},
    {"tonNode.newShardBlockBroadcast", 183696060},
    {"tonNode.capabilities", -172007232},
    {"tonNode.data", 1443505284},
    {"tonNode.dataFull", -1101488237},
    {"tonNode.dataFullEmpty", 1466861002},
    {"tonNode.dataList", 351548179},
    {"tonNode.externalMessage", -596270583},
    {"tonNode.ihrMessage", 1161085703},
    {"tonNode.keyBlocks", 124144985},
    {"tonNode.newShardBlock", -1533165015},
    {"tonNode.prepared", -356205619},
    {"tonNode.notFound", -490521178},
    {"tonNode.preparedProofEmpty", -949370502},
    {"tonNode.preparedProof", -1986028981},
    {"tonNode.preparedProofLink", 1040134797},
    {"tonNode.preparedState", 928762733},
    {"tonNode.notFoundState", 842598993},
    {"tonNode.sessionId", 2056402618},
    {"tonNode.shardPublicOverlayId", 1302254377},
    {"tonNode.success", -1063902129},
    {"tonNode.zeroStateIdExt", 494024110},
    {"validator.group", -120029535},
    {"validator.groupEx", 479350270},
    {"validator.groupNew", -1740398259},
    {"validator.config.global", -2038562966},
    {"validator.config.local", 1716256616},
    {"validator.config.random.local", 1501795426},
    {"validatorSession.blockUpdate", -1836855753},
    {"validatorSession.candidate", 2100525125},
    {"validatorSession.candidateId", 436135276},
    {"validatorSession.config", -1235092029},
    {"validatorSession.configNew", -139482724},
    {"validatorSession.message.startSession", -1767807279},
    {"validatorSession.message.finishSession", -879025437},
    {"validatorSession.pong", -590989459},
    {"validatorSession.round.id", 2477989},
    {"validatorSession.message.submittedBlock", 309732534},
    {"validatorSession.message.approvedBlock", 77968769},
    {"validatorSession.message.rejectedBlock", -1786229141},
    {"validatorSession.message.commit", -1408065803},
    {"validatorSession.message.vote", -1707978297},
    {"validatorSession.message.voteFor", 1643183663},
    {"validatorSession.message.precommit", -1470843566},
    {"validatorSession.message.empty", 1243619241},
    {"validatorSession.candidate.id", -1126743751}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(ton_api::Function *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"adnl.ping", 531276223},
    {"catchain.getBlock", 155049336},
    {"catchain.getBlockHistory", -1470730762},
    {"catchain.getBlocks", 53062594},
    {"catchain.getDifference", -798175528},
    {"dht.findNode", 1826803307},
    {"dht.findValue", -1370791919},
    {"dht.getSignedAddressList", -1451669267},
    {"dht.ping", -873775336},
    {"dht.query", 2102593385},
    {"dht.store", 882065938},
    {"engine.validator.addAdnlId", -310029141},
    {"engine.validator.addControlInterface", 881587196},
    {"engine.validator.addControlProcess", 1524692816},
    {"engine.validator.addDhtId", -183755124},
    {"engine.validator.addListeningPort", -362051147},
    {"engine.validator.addLiteserver", -259387577},
    {"engine.validator.addProxy", -151178251},
    {"engine.validator.addValidatorAdnlAddress", -624187774},
    {"engine.validator.addValidatorPermanentKey", -1844116104},
    {"engine.validator.addValidatorTempKey", -1926009038},
    {"engine.validator.changeFullNodeAdnlAddress", -1094268539},
    {"engine.validator.checkDhtServers", -773578550},
    {"engine.validator.controlQuery", -1535722048},
    {"engine.validator.createComplaintVote", -1333526742},
    {"engine.validator.createElectionBid", -451038907},
    {"engine.validator.createProposalVote", 498278765},
    {"engine.validator.delAdnlId", 691696882},
    {"engine.validator.delDhtId", -2063770818},
    {"engine.validator.delListeningPort", 828094543},
    {"engine.validator.delProxy", 1970850941},
    {"engine.validator.delValidatorAdnlAddress", -150453414},
    {"engine.validator.delValidatorPermanentKey", 390777082},
    {"engine.validator.delValidatorTempKey", -1595481903},
    {"engine.validator.exportPrivateKey", -864911288},
    {"engine.validator.exportPublicKey", 1647618233},
    {"engine.validator.generateKeyPair", -349872005},
    {"engine.validator.getConfig", 1504518693},
    {"engine.validator.getStats", 1389740817},
    {"engine.validator.getTime", -515850543},
    {"engine.validator.importPrivateKey", 360741575},
    {"engine.validator.setVerbosity", -1316856190},
    {"engine.validator.sign", 451549736},
    {"getTestObject", 197109379},
    {"http.getNextPayloadPart", -1871422196},
    {"http.request", 1639027169},
    {"overlay.getBroadcast", 758510240},
    {"overlay.getBroadcastList", 1109141562},
    {"overlay.getRandomPeers", 1223582891},
    {"overlay.query", -855800765},
    {"storage.addUpdate", 1295070674},
    {"storage.getPiece", -2139429280},
    {"storage.ping", 1156837905},
    {"storage.queryPrefix", -333845113},
    {"tcp.ping", 1292381082},
    {"tonNode.downloadBlock", -495814205},
    {"tonNode.downloadBlockFull", 1780991133},
    {"tonNode.downloadBlockProof", 1272334218},
    {"tonNode.downloadBlockProofLink", 632488134},
    {"tonNode.downloadBlockProofLinks", 684796771},
    {"tonNode.downloadBlockProofs", -1515170827},
    {"tonNode.downloadBlocks", 1985594749},
    {"tonNode.downloadKeyBlockProof", -333232070},
    {"tonNode.downloadKeyBlockProofLink", 316943058},
    {"tonNode.downloadKeyBlockProofLinks", 1975747920},
    {"tonNode.downloadKeyBlockProofs", -1020797382},
    {"tonNode.downloadNextBlockFull", 1855993674},
    {"tonNode.downloadPersistentState", 2140791736},
    {"tonNode.downloadPersistentStateSlice", -169220381},
    {"tonNode.downloadZeroState", -1379131814},
    {"tonNode.getArchiveInfo", 2066602305},
    {"tonNode.getArchiveSlice", 540758376},
    {"tonNode.getCapabilities", -555345672},
    {"tonNode.getNextBlockDescription", 341160179},
    {"tonNode.getNextBlocksDescription", 1059590852},
    {"tonNode.getNextKeyBlockIds", -219689029},
    {"tonNode.getPrevBlocksDescription", 1550675145},
    {"tonNode.prepareBlock", 1973649230},
    {"tonNode.prepareBlockProof", -2024000760},
    {"tonNode.prepareBlockProofs", -310791496},
    {"tonNode.prepareBlocks", 1795140604},
    {"tonNode.prepareKeyBlockProof", 2000047160},
    {"tonNode.prepareKeyBlockProofs", -1939014684},
    {"tonNode.preparePersistentState", -18209122},
    {"tonNode.prepareZeroState", 1104021541},
    {"tonNode.query", 1777542355},
    {"tonNode.slave.sendExtMessage", 58127017},
    {"validatorSession.downloadCandidate", -520274443},
    {"validatorSession.ping", 1745111469}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(ton_api::hashable_bool &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_int32 &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_int64 &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_int256 &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_bytes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_pair &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "left", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.left_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "right", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.right_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_vector &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_validatorSessionOldRound &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signatures", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.signatures_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "approve_signatures", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.approve_signatures_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_validatorSessionRoundAttempt &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "votes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.votes_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "precommitted", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.precommitted_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "vote_for_inited", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.vote_for_inited_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "vote_for", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.vote_for_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_validatorSessionRound &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "locked_round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.locked_round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "locked_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.locked_block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "precommitted", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.precommitted_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "first_attempt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.first_attempt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "approved_blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.approved_blocks_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signatures", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.signatures_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "attempts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.attempts_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_blockSignature &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_sentBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "collated_data_file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.collated_data_file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_sentBlockEmpty &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::hashable_vote &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "node", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.node_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_blockCandidate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "approved", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.approved_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_blockVoteCandidate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "approved", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.approved_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_blockCandidateAttempt &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "votes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.votes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_cntVector &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_cntSortedVector &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::hashable_validatorSession &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ts_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "old_rounds", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.old_rounds_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "cur_round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.cur_round_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_ok &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::pk_unenc &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pk_ed25519 &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pk_aes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pk_overlay &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "name", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.name_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pub_unenc &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pub_ed25519 &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pub_aes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::pub_overlay &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "name", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.name_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::testObject &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "o", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.o_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "f", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.f_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::testString &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::testInt &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::testVectorBytes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_vector_bytes(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_address_udp &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_address_udp6 &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_address_tunnel &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "to", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.to_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "pubkey", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.pubkey_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_addressList &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "addrs", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addrs_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "reinit_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.reinit_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "expire_at", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.expire_at_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_createChannel &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_confirmChannel &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "peer_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.peer_key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_custom &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_nop &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::adnl_message_reinit &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_query &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "query_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.query_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "query", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.query_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_answer &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "query_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.query_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "answer", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.answer_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_message_part &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "total_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.total_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "offset", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.offset_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_node &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "addr_list", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addr_list_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_nodes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_packetContents &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "rand1", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.rand1_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "from", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.from_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "from_short", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.from_short_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.message_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "messages", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.messages_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "address", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.address_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_address", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_address_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "confirm_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.confirm_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "recv_addr_list_version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.recv_addr_list_version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "recv_priority_addr_list_version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.recv_priority_addr_list_version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "reinit_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.reinit_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "dst_reinit_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dst_reinit_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "rand2", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.rand2_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_pong &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxy_none &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxy_fast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shared_secret", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.shared_secret_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxyControlPacketPing &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxyControlPacketPong &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxyControlPacketRegister &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxyPacketHeader &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "proxy_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.proxy_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl_start_time", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_start_time_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxyToFastHash &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shared_secret", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shared_secret_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_proxyToFast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_tunnelPacketContents &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "rand1", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.rand1_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "from_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.from_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "from_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.from_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.message_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "statistics", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.statistics_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "payment", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.payment_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "rand2", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.rand2_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "static_nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.static_nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_db_node_key &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "local_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.local_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "peer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.peer_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_db_node_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "addr_list", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addr_list_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_addr_list", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_addr_list_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_id_short &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "incarnation", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.incarnation_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "height", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.height_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_blockNotFound &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::catchain_blockResult &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_blocks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_difference &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "sent_upto", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.sent_upto_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_differenceFork &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "left", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.left_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "right", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.right_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_firstblock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "unique_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.unique_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_sent &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "cnt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.cnt_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_blockUpdate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block_data &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "prev", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "deps", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.deps_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block_dep &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "height", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.height_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block_id &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "incarnation", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.incarnation_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "height", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.height_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block_data_badBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block_data_fork &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "left", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.left_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "right", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.right_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_block_data_nop &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::catchain_block_data_vector &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "msgs", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_vector_bytes(to.msgs_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "tag", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.tag_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "dht", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dht_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "validator", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.validator_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::config_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "local_ids", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.local_ids_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "dht", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dht_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "validators", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.validators_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "liteservers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.liteservers_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "control", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.control_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::control_config_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "priv", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priv_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "pub", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.pub_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_candidate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "source", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.source_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "collated_data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.collated_data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_block_info &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "prev_left", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_left_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "prev_right", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_right_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next_left", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_left_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next_right", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_right_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "lt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.lt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ts_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.state_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "masterchain_ref_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.masterchain_ref_seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_block_packedInfo &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "unixtime", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.unixtime_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "offset", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.offset_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_block_archivedInfo &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_blockdb_key_lru &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_blockdb_key_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_blockdb_lru &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "prev", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_blockdb_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "next", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_candidate_id &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "source", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.source_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "collated_data_file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.collated_data_file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_celldb_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "prev", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_celldb_key_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_empty &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_blockFile &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_zeroStateFile &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_persistentStateFile &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "masterchain_block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.masterchain_block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_proof &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_proofLink &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_signatures &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_candidate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_key_blockInfo &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_filedb_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "prev", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_files_index_key &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_files_package_key &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "package_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.package_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "temp", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.temp_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_files_index_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "packages", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.packages_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key_packages", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_packages_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "temp_packages", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.temp_packages_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_files_package_firstBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "unixtime", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.unixtime_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "lt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.lt_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_files_package_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "package_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.package_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "temp", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.temp_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "firstblocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.firstblocks_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "deleted", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.deleted_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_el_key &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "idx", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.idx_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_desc_key &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_shard_key &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "idx", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.idx_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_status_key &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_lt_desc_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "first_idx", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.first_idx_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last_idx", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_idx_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last_lt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_lt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last_ts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_ts_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_el_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "lt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.lt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ts_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_shard_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_lt_status_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "total_shards", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.total_shards_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_root_config &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "celldb_version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.celldb_version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "blockdb_version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blockdb_version_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_root_dbDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "first_masterchain_block_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.first_masterchain_block_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_root_key_cellDb &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_root_key_blockDb &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_root_key_config &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_asyncSerializer &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last_ts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_ts_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_state_dbVersion &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_state_destroyedSessions &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "sessions", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.sessions_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_state_gcBlockId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_state_hardforks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_state_initBlockId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::db_state_key_destroyedSessions &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_key_initBlockId &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_key_gcBlockId &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_key_shardClient &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_key_asyncSerializer &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_key_hardforks &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_key_dbVersion &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::db_state_shardClient &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_key &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "name", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.name_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "idx", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.idx_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_keyDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "update_rule", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.update_rule_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_message &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "node", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.node_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_node &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "addr_list", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addr_list_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_nodes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_pong &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "random_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.random_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_stored &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::dht_updateRule_signature &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::dht_updateRule_anybody &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::dht_updateRule_overlayNodes &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::dht_value &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.value_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ttl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ttl_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_valueNotFound &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_valueFound &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "static_nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.static_nodes_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "k", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.k_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "a", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.a_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_config_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_config_random_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "cnt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.cnt_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_db_bucket &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_db_key_bucket &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dummyworkchain0_config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "zero_state_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.zero_state_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_addr &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.categories_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_categories_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_addrProxy &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "in_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.in_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "in_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.in_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "out_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "out_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "proxy_type", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.proxy_type_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.categories_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_categories_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_adnl &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "category", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.category_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_controlInterface &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "allowed", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.allowed_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_controlProcess &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "permissions", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.permissions_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_dht &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_gc &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ids", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ids_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_liteServer &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "temp_keys", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.temp_keys_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl_addrs", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_addrs_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "election_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.election_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "expire_at", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.expire_at_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validatorAdnlAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "expire_at", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.expire_at_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validatorTempKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "expire_at", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.expire_at_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_adnlProxy_config &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ports", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ports_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_adnlProxy_port &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "in_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.in_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "out_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "dst_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dst_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "dst_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dst_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "proxy_type", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.proxy_type_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_dht_config &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "dht", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dht_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "gc", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.gc_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_config &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "out_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "addrs", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addrs_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "dht", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dht_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "validators", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.validators_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "fullnode", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.fullnode_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "fullnodeslaves", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.fullnodeslaves_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "fullnodemasters", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.fullnodemasters_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "liteservers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.liteservers_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "control", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.control_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "gc", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.gc_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_controlQueryError &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "code", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.code_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.message_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_dhtServerStatus &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "status", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.status_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_dhtServersStatus &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "servers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.servers_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_electionBid &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "election_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.election_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "perm_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.perm_key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl_addr", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_addr_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "to_send_payload", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.to_send_payload_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_fullNodeMaster &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_fullNodeSlave &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_groupMember &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "public_key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.public_key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "weight", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.weight_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_jsonConfig &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_keyHash &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_oneStat &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_proposalVote &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "perm_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.perm_key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "to_send", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.to_send_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_signature &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_stats &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "stats", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.stats_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_success &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::engine_validator_time &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "time", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.time_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::fec_raptorQ &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "symbol_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.symbol_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "symbols_count", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.symbols_count_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::fec_roundRobin &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "symbol_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.symbol_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "symbols_count", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.symbols_count_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::fec_online &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "symbol_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.symbol_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "symbols_count", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.symbols_count_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_header &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "name", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.name_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_payloadPart &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "trailer", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.trailer_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_response &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "http_version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.http_version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "status_code", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.status_code_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "reason", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.reason_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "headers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.headers_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_server_config &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "dhs", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dhs_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "local_hosts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.local_hosts_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_server_dnsEntry &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "domain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.domain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "addr", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addr_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_server_host &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "domains", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.domains_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::id_config_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::liteclient_config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "liteservers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.liteservers_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "validator", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.validator_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::liteserver_desc &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::liteserver_config_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::liteserver_config_random_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_fec_received &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_fec_completed &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_unicast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "certificate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.certificate_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcastFec &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "certificate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.certificate_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "fec", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.fec_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcastFecShort &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "certificate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.certificate_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "broadcast_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.broadcast_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part_data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcastNotFound &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcastList &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hashes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hashes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_certificate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "issued_by", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.issued_by_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "expire_at", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.expire_at_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_emptyCertificate &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::overlay_certificateId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "overlay_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.overlay_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "node", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.node_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "expire_at", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.expire_at_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_size_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_message &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "overlay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.overlay_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_node &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "overlay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.overlay_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_nodes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcast_id &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcast_toSign &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.date_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcastFec_id &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "type", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.type_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "flags", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.flags_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_broadcastFec_partId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "broadcast_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.broadcast_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.data_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_db_key_nodes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "local_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.local_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "overlay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.overlay_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_db_nodes &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nodes", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.nodes_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_node_toSign &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "overlay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.overlay_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp_message &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp_query &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "query_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.query_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_answer_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_answer_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "timeout", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.timeout_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp_answer &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "query_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.query_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp_messagePart &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "transfer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.transfer_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "fec_type", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.fec_type_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "total_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.total_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp_confirm &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "transfer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.transfer_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp_complete &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "transfer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.transfer_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp2_messagePart &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "transfer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.transfer_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "fec_type", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.fec_type_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "total_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.total_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp2_confirm &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "transfer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.transfer_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "received_mask", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.received_mask_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "received_count", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.received_count_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::rldp2_complete &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "transfer_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.transfer_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "part", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.part_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_piece &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "proof", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.proof_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_pong &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::storage_state &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "will_upload", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.will_upload_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "want_download", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.want_download_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_updateInit &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "have_pieces", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.have_pieces_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.state_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_updateHavePieces &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "piece_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.piece_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_updateState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.state_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tcp_authentificate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nonce", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.nonce_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tcp_authentificationNonce &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "nonce", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.nonce_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tcp_authentificationComplete &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tcp_pong &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "random_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.random_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::ton_blockId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "root_cell_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_cell_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::ton_blockIdApprove &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "root_cell_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_cell_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_archiveNotFound &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_archiveInfo &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_blockDescriptionEmpty &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_blockDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_blockId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_blockIdExt &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_blockSignature &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "who", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.who_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_blocksDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ids", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ids_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "incomplete", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.incomplete_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_blockBroadcast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "validator_set_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.validator_set_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signatures", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.signatures_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "proof", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.proof_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_ihrMessageBroadcast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.message_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_externalMessageBroadcast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.message_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_newShardBlockBroadcast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_capabilities &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "capabilities", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.capabilities_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_data &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_dataFull &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "proof", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.proof_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "is_link", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.is_link_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_dataFullEmpty &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_dataList &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_vector_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_externalMessage &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_ihrMessage &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_keyBlocks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "incomplete", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.incomplete_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "error", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.error_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_newShardBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "cc_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.cc_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepared &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_notFound &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_preparedProofEmpty &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_preparedProof &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_preparedProofLink &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_preparedState &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_notFoundState &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_sessionId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "cc_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.cc_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "opts_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.opts_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_shardPublicOverlayId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "zero_state_file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.zero_state_file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_success &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_zeroStateIdExt &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_group &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "config_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.config_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "members", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.members_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_groupEx &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "vertical_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.vertical_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "config_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.config_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "members", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.members_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_groupNew &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "workchain", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.workchain_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "shard", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.shard_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "vertical_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.vertical_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "last_key_block_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.last_key_block_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "config_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.config_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "members", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.members_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_config_global &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "zero_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.zero_state_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "init_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.init_block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "hardforks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hardforks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_config_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validator_config_random_local &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "addr_list", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.addr_list_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_blockUpdate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ts_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "actions", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.actions_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.state_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_candidate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "collated_data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.collated_data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_candidateId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "src", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.src_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "collated_data_file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.collated_data_file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_config &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_idle_timeout", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_idle_timeout_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_max_deps", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_max_deps_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "round_candidates", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_candidates_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next_candidate_delay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_candidate_delay_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "round_attempt_duration", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_attempt_duration_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_round_attempts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_round_attempts_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_block_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_block_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_collated_data_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_collated_data_size_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_configNew &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_idle_timeout", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_idle_timeout_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "catchain_max_deps", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.catchain_max_deps_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "round_candidates", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_candidates_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "next_candidate_delay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_candidate_delay_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "round_attempt_duration", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_attempt_duration_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_round_attempts", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_round_attempts_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_block_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_block_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_collated_data_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_collated_data_size_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "new_catchain_ids", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.new_catchain_ids_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_startSession &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_finishSession &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::validatorSession_pong &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_round_id &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "session", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.session_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "height", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.height_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "prev_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_submittedBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "root_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.root_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.file_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "collated_data_file_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.collated_data_file_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_approvedBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "candidate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.candidate_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_rejectedBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "candidate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.candidate_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "reason", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.reason_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_commit &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "candidate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.candidate_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "signature", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.signature_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_vote &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "attempt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.attempt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "candidate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.candidate_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_voteFor &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "attempt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.attempt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "candidate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.candidate_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_precommit &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "attempt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.attempt_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "candidate", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.candidate_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_message_empty &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "attempt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.attempt_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_candidate_id &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "block_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::adnl_ping &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_getBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_getBlockHistory &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "height", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.height_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "stop_if", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.stop_if_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_getBlocks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::catchain_getDifference &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "rt", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.rt_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_findNode &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "k", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.k_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_findValue &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "k", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.k_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_getSignedAddressList &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::dht_ping &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "random_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.random_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_query &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "node", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.node_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::dht_store &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "value", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.value_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addAdnlId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "category", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.category_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addControlInterface &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addControlProcess &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "peer_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.peer_key_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "permissions", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.permissions_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addDhtId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addListeningPort &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.categories_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_categories_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addLiteserver &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addProxy &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "in_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.in_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "in_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.in_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "out_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "out_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "proxy", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.proxy_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.categories_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_categories_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addValidatorAdnlAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "permanent_key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.permanent_key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ttl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ttl_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addValidatorPermanentKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "election_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.election_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ttl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ttl_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_addValidatorTempKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "permanent_key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.permanent_key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "ttl", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ttl_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_changeFullNodeAdnlAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "adnl_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.adnl_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_checkDhtServers &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_controlQuery &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_createComplaintVote &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "election_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.election_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "vote", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.vote_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_createElectionBid &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "election_date", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.election_date_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "election_addr", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.election_addr_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "wallet", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.wallet_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_createProposalVote &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "vote", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.vote_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delAdnlId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delDhtId &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delListeningPort &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.categories_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_categories_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delProxy &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "out_ip", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_ip_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "out_port", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.out_port_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.categories_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "priority_categories", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.priority_categories_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delValidatorAdnlAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "permanent_key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.permanent_key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delValidatorPermanentKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_delValidatorTempKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "permanent_key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.permanent_key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_exportPrivateKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_exportPublicKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_generateKeyPair &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::engine_validator_getConfig &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::engine_validator_getStats &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::engine_validator_getTime &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::engine_validator_importPrivateKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_setVerbosity &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "verbosity", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.verbosity_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::engine_validator_sign &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key_hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.key_hash_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::getTestObject &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::http_getNextPayloadPart &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_chunk_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_chunk_size_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::http_request &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "method", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.method_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "url", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.url_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "http_version", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.http_version_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "headers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.headers_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_getBroadcast &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_getBroadcastList &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "list", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.list_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_getRandomPeers &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "peers", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.peers_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::overlay_query &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "overlay", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.overlay_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_addUpdate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "session_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.session_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "update", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.update_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_getPiece &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "piece_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.piece_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_ping &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "session_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.session_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::storage_queryPrefix &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tcp_ping &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "random_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.random_id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlockFull &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlockProof &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlockProofLink &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlockProofLinks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlockProofs &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadBlocks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadKeyBlockProof &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadKeyBlockProofLink &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadKeyBlockProofLinks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadKeyBlockProofs &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadNextBlockFull &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "prev_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadPersistentState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "masterchain_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.masterchain_block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadPersistentStateSlice &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "masterchain_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.masterchain_block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "offset", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.offset_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_size_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_downloadZeroState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_getArchiveInfo &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "masterchain_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.masterchain_seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_getArchiveSlice &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "archive_id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.archive_id_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "offset", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.offset_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_size_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_getCapabilities &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_getNextBlockDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "prev_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_getNextBlocksDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "prev_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.prev_block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "limit", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.limit_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_getNextKeyBlockIds &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "max_size", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.max_size_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_getPrevBlocksDescription &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "next_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.next_block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "limit", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.limit_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "cutoff_seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.cutoff_seqno_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareBlock &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareBlockProof &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "allow_partial", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.allow_partial_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareBlockProofs &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "allow_partial", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.allow_partial_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareBlocks &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareKeyBlockProof &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "allow_partial", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.allow_partial_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareKeyBlockProofs &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "blocks", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.blocks_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "allow_partial", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.allow_partial_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_preparePersistentState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "masterchain_block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.masterchain_block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_prepareZeroState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "block", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.block_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::tonNode_query &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(ton_api::tonNode_slave_sendExtMessage &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.message_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_downloadCandidate &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "round", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.round_, std::move(value)));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "id", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.id_, std::move(value)));
    }
  }
  return Status::OK();
}
Status from_json(ton_api::validatorSession_ping &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "hash", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.hash_, std::move(value)));
    }
  }
  return Status::OK();
}
void to_json(JsonValueScope &jv, const ton_api::Hashable &object) {
  ton_api::downcast_call(const_cast<ton_api::Hashable &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::hashable_bool &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.bool");
  jo("value", ToJson(JsonBool{object.value_}));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_int32 &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.int32");
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_int64 &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.int64");
  jo("value", ToJson(JsonInt64{object.value_}));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_int256 &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.int256");
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_bytes &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.bytes");
  jo("value", ToJson(JsonBytes{object.value_}));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_pair &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.pair");
  jo("left", ToJson(object.left_));
  jo("right", ToJson(object.right_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_vector &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.vector");
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_validatorSessionOldRound &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.validatorSessionOldRound");
  jo("seqno", ToJson(object.seqno_));
  jo("block", ToJson(object.block_));
  jo("signatures", ToJson(object.signatures_));
  jo("approve_signatures", ToJson(object.approve_signatures_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_validatorSessionRoundAttempt &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.validatorSessionRoundAttempt");
  jo("seqno", ToJson(object.seqno_));
  jo("votes", ToJson(object.votes_));
  jo("precommitted", ToJson(object.precommitted_));
  jo("vote_for_inited", ToJson(object.vote_for_inited_));
  jo("vote_for", ToJson(object.vote_for_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_validatorSessionRound &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.validatorSessionRound");
  jo("locked_round", ToJson(object.locked_round_));
  jo("locked_block", ToJson(object.locked_block_));
  jo("seqno", ToJson(object.seqno_));
  jo("precommitted", ToJson(JsonBool{object.precommitted_}));
  jo("first_attempt", ToJson(object.first_attempt_));
  jo("approved_blocks", ToJson(object.approved_blocks_));
  jo("signatures", ToJson(object.signatures_));
  jo("attempts", ToJson(object.attempts_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_blockSignature &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.blockSignature");
  jo("signature", ToJson(object.signature_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_sentBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.sentBlock");
  jo("src", ToJson(object.src_));
  jo("root_hash", ToJson(object.root_hash_));
  jo("file_hash", ToJson(object.file_hash_));
  jo("collated_data_file_hash", ToJson(object.collated_data_file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_sentBlockEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.sentBlockEmpty");
}
void to_json(JsonValueScope &jv, const ton_api::hashable_vote &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.vote");
  jo("block", ToJson(object.block_));
  jo("node", ToJson(object.node_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_blockCandidate &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.blockCandidate");
  jo("block", ToJson(object.block_));
  jo("approved", ToJson(object.approved_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_blockVoteCandidate &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.blockVoteCandidate");
  jo("block", ToJson(object.block_));
  jo("approved", ToJson(object.approved_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_blockCandidateAttempt &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.blockCandidateAttempt");
  jo("block", ToJson(object.block_));
  jo("votes", ToJson(object.votes_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_cntVector &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.cntVector");
  jo("data", ToJson(object.data_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_cntSortedVector &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.cntSortedVector");
  jo("data", ToJson(object.data_));
}
void to_json(JsonValueScope &jv, const ton_api::hashable_validatorSession &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashable.validatorSession");
  jo("ts", ToJson(object.ts_));
  jo("old_rounds", ToJson(object.old_rounds_));
  jo("cur_round", ToJson(object.cur_round_));
}
void to_json(JsonValueScope &jv, const ton_api::storage_ok &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.ok");
}
void to_json(JsonValueScope &jv, const ton_api::PrivateKey &object) {
  ton_api::downcast_call(const_cast<ton_api::PrivateKey &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::pk_unenc &object) {
  auto jo = jv.enter_object();
  jo("@type", "pk.unenc");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::pk_ed25519 &object) {
  auto jo = jv.enter_object();
  jo("@type", "pk.ed25519");
  jo("key", ToJson(object.key_));
}
void to_json(JsonValueScope &jv, const ton_api::pk_aes &object) {
  auto jo = jv.enter_object();
  jo("@type", "pk.aes");
  jo("key", ToJson(object.key_));
}
void to_json(JsonValueScope &jv, const ton_api::pk_overlay &object) {
  auto jo = jv.enter_object();
  jo("@type", "pk.overlay");
  jo("name", ToJson(JsonBytes{object.name_}));
}
void to_json(JsonValueScope &jv, const ton_api::PublicKey &object) {
  ton_api::downcast_call(const_cast<ton_api::PublicKey &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::pub_unenc &object) {
  auto jo = jv.enter_object();
  jo("@type", "pub.unenc");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::pub_ed25519 &object) {
  auto jo = jv.enter_object();
  jo("@type", "pub.ed25519");
  jo("key", ToJson(object.key_));
}
void to_json(JsonValueScope &jv, const ton_api::pub_aes &object) {
  auto jo = jv.enter_object();
  jo("@type", "pub.aes");
  jo("key", ToJson(object.key_));
}
void to_json(JsonValueScope &jv, const ton_api::pub_overlay &object) {
  auto jo = jv.enter_object();
  jo("@type", "pub.overlay");
  jo("name", ToJson(JsonBytes{object.name_}));
}
void to_json(JsonValueScope &jv, const ton_api::TestObject &object) {
  ton_api::downcast_call(const_cast<ton_api::TestObject &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::testObject &object) {
  auto jo = jv.enter_object();
  jo("@type", "testObject");
  jo("value", ToJson(object.value_));
  jo("o", ToJson(object.o_));
  jo("f", ToJson(object.f_));
}
void to_json(JsonValueScope &jv, const ton_api::testString &object) {
  auto jo = jv.enter_object();
  jo("@type", "testString");
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::testInt &object) {
  auto jo = jv.enter_object();
  jo("@type", "testInt");
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::testVectorBytes &object) {
  auto jo = jv.enter_object();
  jo("@type", "testVectorBytes");
  jo("value", ToJson(JsonVectorBytes(object.value_)));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_Address &object) {
  ton_api::downcast_call(const_cast<ton_api::adnl_Address &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::adnl_address_udp &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.address.udp");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_address_udp6 &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.address.udp6");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_address_tunnel &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.address.tunnel");
  jo("to", ToJson(object.to_));
  if (object.pubkey_) {
    jo("pubkey", ToJson(object.pubkey_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::adnl_addressList &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.addressList");
  jo("addrs", ToJson(object.addrs_));
  jo("version", ToJson(object.version_));
  jo("reinit_date", ToJson(object.reinit_date_));
  jo("priority", ToJson(object.priority_));
  jo("expire_at", ToJson(object.expire_at_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_Message &object) {
  ton_api::downcast_call(const_cast<ton_api::adnl_Message &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_createChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.createChannel");
  jo("key", ToJson(object.key_));
  jo("date", ToJson(object.date_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_confirmChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.confirmChannel");
  jo("key", ToJson(object.key_));
  jo("peer_key", ToJson(object.peer_key_));
  jo("date", ToJson(object.date_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_custom &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.custom");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_nop &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.nop");
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_reinit &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.reinit");
  jo("date", ToJson(object.date_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_query &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.query");
  jo("query_id", ToJson(object.query_id_));
  jo("query", ToJson(JsonBytes{object.query_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_answer &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.answer");
  jo("query_id", ToJson(object.query_id_));
  jo("answer", ToJson(JsonBytes{object.answer_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_message_part &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.message.part");
  jo("hash", ToJson(object.hash_));
  jo("total_size", ToJson(object.total_size_));
  jo("offset", ToJson(object.offset_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_node &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.node");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  if (object.addr_list_) {
    jo("addr_list", ToJson(object.addr_list_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::adnl_nodes &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.nodes");
  jo("nodes", ToJson(object.nodes_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_packetContents &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.packetContents");
  jo("rand1", ToJson(JsonBytes{object.rand1_}));
  if (object.flags_) {
    jo("flags", ToJson(object.flags_));
  }
  if (object.from_) {
    jo("from", ToJson(object.from_));
  }
  if (object.from_short_) {
    jo("from_short", ToJson(object.from_short_));
  }
  if (object.message_) {
    jo("message", ToJson(object.message_));
  }
  jo("messages", ToJson(object.messages_));
  if (object.address_) {
    jo("address", ToJson(object.address_));
  }
  if (object.priority_address_) {
    jo("priority_address", ToJson(object.priority_address_));
  }
  jo("seqno", ToJson(JsonInt64{object.seqno_}));
  jo("confirm_seqno", ToJson(JsonInt64{object.confirm_seqno_}));
  jo("recv_addr_list_version", ToJson(object.recv_addr_list_version_));
  jo("recv_priority_addr_list_version", ToJson(object.recv_priority_addr_list_version_));
  jo("reinit_date", ToJson(object.reinit_date_));
  jo("dst_reinit_date", ToJson(object.dst_reinit_date_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
  jo("rand2", ToJson(JsonBytes{object.rand2_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_pong &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.pong");
  jo("value", ToJson(JsonInt64{object.value_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_Proxy &object) {
  ton_api::downcast_call(const_cast<ton_api::adnl_Proxy &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxy_none &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxy.none");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxy_fast &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxy.fast");
  jo("id", ToJson(object.id_));
  jo("shared_secret", ToJson(JsonBytes{object.shared_secret_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_ProxyControlPacket &object) {
  ton_api::downcast_call(const_cast<ton_api::adnl_ProxyControlPacket &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxyControlPacketPing &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxyControlPacketPing");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxyControlPacketPong &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxyControlPacketPong");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxyControlPacketRegister &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxyControlPacketRegister");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxyPacketHeader &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxyPacketHeader");
  jo("proxy_id", ToJson(object.proxy_id_));
  if (object.flags_) {
    jo("flags", ToJson(object.flags_));
  }
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  jo("adnl_start_time", ToJson(object.adnl_start_time_));
  jo("seqno", ToJson(JsonInt64{object.seqno_}));
  jo("date", ToJson(object.date_));
  jo("signature", ToJson(object.signature_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxyToFastHash &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxyToFastHash");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  jo("date", ToJson(object.date_));
  jo("data_hash", ToJson(object.data_hash_));
  jo("shared_secret", ToJson(object.shared_secret_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_proxyToFast &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.proxyToFast");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  jo("date", ToJson(object.date_));
  jo("signature", ToJson(object.signature_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_tunnelPacketContents &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.tunnelPacketContents");
  jo("rand1", ToJson(JsonBytes{object.rand1_}));
  if (object.flags_) {
    jo("flags", ToJson(object.flags_));
  }
  jo("from_ip", ToJson(object.from_ip_));
  jo("from_port", ToJson(object.from_port_));
  jo("message", ToJson(JsonBytes{object.message_}));
  jo("statistics", ToJson(JsonBytes{object.statistics_}));
  jo("payment", ToJson(JsonBytes{object.payment_}));
  jo("rand2", ToJson(JsonBytes{object.rand2_}));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.config.global");
  if (object.static_nodes_) {
    jo("static_nodes", ToJson(object.static_nodes_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::adnl_db_node_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.db.node.key");
  jo("local_id", ToJson(object.local_id_));
  jo("peer_id", ToJson(object.peer_id_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_db_node_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.db.node.value");
  jo("date", ToJson(object.date_));
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  if (object.addr_list_) {
    jo("addr_list", ToJson(object.addr_list_));
  }
  if (object.priority_addr_list_) {
    jo("priority_addr_list", ToJson(object.priority_addr_list_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::adnl_id_short &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.id.short");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block");
  jo("incarnation", ToJson(object.incarnation_));
  jo("src", ToJson(object.src_));
  jo("height", ToJson(object.height_));
  if (object.data_) {
    jo("data", ToJson(object.data_));
  }
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_BlockResult &object) {
  ton_api::downcast_call(const_cast<ton_api::catchain_BlockResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::catchain_blockNotFound &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.blockNotFound");
}
void to_json(JsonValueScope &jv, const ton_api::catchain_blockResult &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.blockResult");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::catchain_blocks &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.blocks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_Difference &object) {
  ton_api::downcast_call(const_cast<ton_api::catchain_Difference &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::catchain_difference &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.difference");
  jo("sent_upto", ToJson(object.sent_upto_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_differenceFork &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.differenceFork");
  if (object.left_) {
    jo("left", ToJson(object.left_));
  }
  if (object.right_) {
    jo("right", ToJson(object.right_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::catchain_firstblock &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.firstblock");
  jo("unique_hash", ToJson(object.unique_hash_));
  jo("nodes", ToJson(object.nodes_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_sent &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.sent");
  jo("cnt", ToJson(object.cnt_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_blockUpdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.blockUpdate");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_data &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.data");
  if (object.prev_) {
    jo("prev", ToJson(object.prev_));
  }
  jo("deps", ToJson(object.deps_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_dep &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.dep");
  jo("src", ToJson(object.src_));
  jo("height", ToJson(object.height_));
  jo("data_hash", ToJson(object.data_hash_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_id &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.id");
  jo("incarnation", ToJson(object.incarnation_));
  jo("src", ToJson(object.src_));
  jo("height", ToJson(object.height_));
  jo("data_hash", ToJson(object.data_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_inner_Data &object) {
  ton_api::downcast_call(const_cast<ton_api::catchain_block_inner_Data &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_data_badBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.data.badBlock");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_data_fork &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.data.fork");
  if (object.left_) {
    jo("left", ToJson(object.left_));
  }
  if (object.right_) {
    jo("right", ToJson(object.right_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_data_nop &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.data.nop");
}
void to_json(JsonValueScope &jv, const ton_api::catchain_block_data_vector &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.block.data.vector");
  jo("msgs", ToJson(JsonVectorBytes(object.msgs_)));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.config.global");
  jo("tag", ToJson(object.tag_));
  jo("nodes", ToJson(object.nodes_));
}
void to_json(JsonValueScope &jv, const ton_api::config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "config.global");
  if (object.adnl_) {
    jo("adnl", ToJson(object.adnl_));
  }
  if (object.dht_) {
    jo("dht", ToJson(object.dht_));
  }
  if (object.validator_) {
    jo("validator", ToJson(object.validator_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::config_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "config.local");
  jo("local_ids", ToJson(object.local_ids_));
  jo("dht", ToJson(object.dht_));
  jo("validators", ToJson(object.validators_));
  jo("liteservers", ToJson(object.liteservers_));
  jo("control", ToJson(object.control_));
}
void to_json(JsonValueScope &jv, const ton_api::control_config_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "control.config.local");
  if (object.priv_) {
    jo("priv", ToJson(object.priv_));
  }
  jo("pub", ToJson(object.pub_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::db_candidate &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.candidate");
  if (object.source_) {
    jo("source", ToJson(object.source_));
  }
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("data", ToJson(JsonBytes{object.data_}));
  jo("collated_data", ToJson(JsonBytes{object.collated_data_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_block_Info &object) {
  ton_api::downcast_call(const_cast<ton_api::db_block_Info &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_block_info &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.block.info");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  if (object.flags_) {
    jo("flags", ToJson(object.flags_));
  }
  if (object.prev_left_) {
    jo("prev_left", ToJson(object.prev_left_));
  }
  if (object.prev_right_) {
    jo("prev_right", ToJson(object.prev_right_));
  }
  if (object.next_left_) {
    jo("next_left", ToJson(object.next_left_));
  }
  if (object.next_right_) {
    jo("next_right", ToJson(object.next_right_));
  }
  jo("lt", ToJson(JsonInt64{object.lt_}));
  jo("ts", ToJson(object.ts_));
  jo("state", ToJson(object.state_));
  jo("masterchain_ref_seqno", ToJson(object.masterchain_ref_seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::db_block_packedInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.block.packedInfo");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("unixtime", ToJson(object.unixtime_));
  jo("offset", ToJson(JsonInt64{object.offset_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_block_archivedInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.block.archivedInfo");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  if (object.flags_) {
    jo("flags", ToJson(object.flags_));
  }
  if (object.next_) {
    jo("next", ToJson(object.next_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_blockdb_Key &object) {
  ton_api::downcast_call(const_cast<ton_api::db_blockdb_Key &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_blockdb_key_lru &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.blockdb.key.lru");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_blockdb_key_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.blockdb.key.value");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_blockdb_lru &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.blockdb.lru");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("prev", ToJson(object.prev_));
  jo("next", ToJson(object.next_));
}
void to_json(JsonValueScope &jv, const ton_api::db_blockdb_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.blockdb.value");
  if (object.next_) {
    jo("next", ToJson(object.next_));
  }
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_candidate_id &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.candidate.id");
  if (object.source_) {
    jo("source", ToJson(object.source_));
  }
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("collated_data_file_hash", ToJson(object.collated_data_file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::db_celldb_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.celldb.value");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
  jo("prev", ToJson(object.prev_));
  jo("next", ToJson(object.next_));
  jo("root_hash", ToJson(object.root_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::db_celldb_key_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.celldb.key.value");
  jo("hash", ToJson(object.hash_));
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_Key &object) {
  ton_api::downcast_call(const_cast<ton_api::db_filedb_Key &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_empty &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.empty");
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_blockFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.blockFile");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_zeroStateFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.zeroStateFile");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_persistentStateFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.persistentStateFile");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
  if (object.masterchain_block_id_) {
    jo("masterchain_block_id", ToJson(object.masterchain_block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_proof &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.proof");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_proofLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.proofLink");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_signatures &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.signatures");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_candidate &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.candidate");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_key_blockInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.key.blockInfo");
  if (object.block_id_) {
    jo("block_id", ToJson(object.block_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_filedb_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.filedb.value");
  if (object.key_) {
    jo("key", ToJson(object.key_));
  }
  jo("prev", ToJson(object.prev_));
  jo("next", ToJson(object.next_));
  jo("file_hash", ToJson(object.file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::db_files_Key &object) {
  ton_api::downcast_call(const_cast<ton_api::db_files_Key &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_files_index_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.files.index.key");
}
void to_json(JsonValueScope &jv, const ton_api::db_files_package_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.files.package.key");
  jo("package_id", ToJson(object.package_id_));
  jo("key", ToJson(JsonBool{object.key_}));
  jo("temp", ToJson(JsonBool{object.temp_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_files_index_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.files.index.value");
  jo("packages", ToJson(object.packages_));
  jo("key_packages", ToJson(object.key_packages_));
  jo("temp_packages", ToJson(object.temp_packages_));
}
void to_json(JsonValueScope &jv, const ton_api::db_files_package_firstBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.files.package.firstBlock");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("seqno", ToJson(object.seqno_));
  jo("unixtime", ToJson(object.unixtime_));
  jo("lt", ToJson(JsonInt64{object.lt_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_files_package_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.files.package.value");
  jo("package_id", ToJson(object.package_id_));
  jo("key", ToJson(JsonBool{object.key_}));
  jo("temp", ToJson(JsonBool{object.temp_}));
  jo("firstblocks", ToJson(object.firstblocks_));
  jo("deleted", ToJson(JsonBool{object.deleted_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_Key &object) {
  ton_api::downcast_call(const_cast<ton_api::db_lt_Key &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_el_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.el.key");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("idx", ToJson(object.idx_));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_desc_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.desc.key");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_shard_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.shard.key");
  jo("idx", ToJson(object.idx_));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_status_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.status.key");
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_desc_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.desc.value");
  jo("first_idx", ToJson(object.first_idx_));
  jo("last_idx", ToJson(object.last_idx_));
  jo("last_seqno", ToJson(object.last_seqno_));
  jo("last_lt", ToJson(JsonInt64{object.last_lt_}));
  jo("last_ts", ToJson(object.last_ts_));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_el_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.el.value");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("lt", ToJson(JsonInt64{object.lt_}));
  jo("ts", ToJson(object.ts_));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_shard_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.shard.value");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
}
void to_json(JsonValueScope &jv, const ton_api::db_lt_status_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.lt.status.value");
  jo("total_shards", ToJson(object.total_shards_));
}
void to_json(JsonValueScope &jv, const ton_api::db_root_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.root.config");
  jo("celldb_version", ToJson(object.celldb_version_));
  jo("blockdb_version", ToJson(object.blockdb_version_));
}
void to_json(JsonValueScope &jv, const ton_api::db_root_dbDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.root.dbDescription");
  jo("version", ToJson(object.version_));
  if (object.first_masterchain_block_id_) {
    jo("first_masterchain_block_id", ToJson(object.first_masterchain_block_id_));
  }
  jo("flags", ToJson(object.flags_));
}
void to_json(JsonValueScope &jv, const ton_api::db_root_Key &object) {
  ton_api::downcast_call(const_cast<ton_api::db_root_Key &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_root_key_cellDb &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.root.key.cellDb");
  jo("version", ToJson(object.version_));
}
void to_json(JsonValueScope &jv, const ton_api::db_root_key_blockDb &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.root.key.blockDb");
  jo("version", ToJson(object.version_));
}
void to_json(JsonValueScope &jv, const ton_api::db_root_key_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.root.key.config");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_asyncSerializer &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.asyncSerializer");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  if (object.last_) {
    jo("last", ToJson(object.last_));
  }
  jo("last_ts", ToJson(object.last_ts_));
}
void to_json(JsonValueScope &jv, const ton_api::db_state_dbVersion &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.dbVersion");
  jo("version", ToJson(object.version_));
}
void to_json(JsonValueScope &jv, const ton_api::db_state_destroyedSessions &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.destroyedSessions");
  jo("sessions", ToJson(object.sessions_));
}
void to_json(JsonValueScope &jv, const ton_api::db_state_gcBlockId &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.gcBlockId");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_state_hardforks &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.hardforks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::db_state_initBlockId &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.initBlockId");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::db_state_Key &object) {
  ton_api::downcast_call(const_cast<ton_api::db_state_Key &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_destroyedSessions &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.destroyedSessions");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_initBlockId &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.initBlockId");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_gcBlockId &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.gcBlockId");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_shardClient &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.shardClient");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_asyncSerializer &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.asyncSerializer");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_hardforks &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.hardforks");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_key_dbVersion &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.key.dbVersion");
}
void to_json(JsonValueScope &jv, const ton_api::db_state_shardClient &object) {
  auto jo = jv.enter_object();
  jo("@type", "db.state.shardClient");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_key &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.key");
  jo("id", ToJson(object.id_));
  jo("name", ToJson(JsonBytes{object.name_}));
  jo("idx", ToJson(object.idx_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_keyDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.keyDescription");
  if (object.key_) {
    jo("key", ToJson(object.key_));
  }
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  if (object.update_rule_) {
    jo("update_rule", ToJson(object.update_rule_));
  }
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::dht_message &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.message");
  if (object.node_) {
    jo("node", ToJson(object.node_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_node &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.node");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  if (object.addr_list_) {
    jo("addr_list", ToJson(object.addr_list_));
  }
  jo("version", ToJson(object.version_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::dht_nodes &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.nodes");
  jo("nodes", ToJson(object.nodes_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_pong &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.pong");
  jo("random_id", ToJson(JsonInt64{object.random_id_}));
}
void to_json(JsonValueScope &jv, const ton_api::dht_stored &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.stored");
}
void to_json(JsonValueScope &jv, const ton_api::dht_UpdateRule &object) {
  ton_api::downcast_call(const_cast<ton_api::dht_UpdateRule &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::dht_updateRule_signature &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.updateRule.signature");
}
void to_json(JsonValueScope &jv, const ton_api::dht_updateRule_anybody &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.updateRule.anybody");
}
void to_json(JsonValueScope &jv, const ton_api::dht_updateRule_overlayNodes &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.updateRule.overlayNodes");
}
void to_json(JsonValueScope &jv, const ton_api::dht_value &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.value");
  if (object.key_) {
    jo("key", ToJson(object.key_));
  }
  jo("value", ToJson(JsonBytes{object.value_}));
  jo("ttl", ToJson(object.ttl_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::dht_ValueResult &object) {
  ton_api::downcast_call(const_cast<ton_api::dht_ValueResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::dht_valueNotFound &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.valueNotFound");
  if (object.nodes_) {
    jo("nodes", ToJson(object.nodes_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_valueFound &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.valueFound");
  if (object.value_) {
    jo("value", ToJson(object.value_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.config.global");
  if (object.static_nodes_) {
    jo("static_nodes", ToJson(object.static_nodes_));
  }
  jo("k", ToJson(object.k_));
  jo("a", ToJson(object.a_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_config_Local &object) {
  ton_api::downcast_call(const_cast<ton_api::dht_config_Local &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::dht_config_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.config.local");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_config_random_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.config.random.local");
  jo("cnt", ToJson(object.cnt_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_db_bucket &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.db.bucket");
  if (object.nodes_) {
    jo("nodes", ToJson(object.nodes_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_db_key_bucket &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.db.key.bucket");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::dummyworkchain0_config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "dummyworkchain0.config.global");
  jo("zero_state_hash", ToJson(object.zero_state_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_Addr &object) {
  ton_api::downcast_call(const_cast<ton_api::engine_Addr &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::engine_addr &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.addr");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  jo("categories", ToJson(object.categories_));
  jo("priority_categories", ToJson(object.priority_categories_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_addrProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.addrProxy");
  jo("in_ip", ToJson(object.in_ip_));
  jo("in_port", ToJson(object.in_port_));
  jo("out_ip", ToJson(object.out_ip_));
  jo("out_port", ToJson(object.out_port_));
  if (object.proxy_type_) {
    jo("proxy_type", ToJson(object.proxy_type_));
  }
  jo("categories", ToJson(object.categories_));
  jo("priority_categories", ToJson(object.priority_categories_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_adnl &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.adnl");
  jo("id", ToJson(object.id_));
  jo("category", ToJson(object.category_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_controlInterface &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.controlInterface");
  jo("id", ToJson(object.id_));
  jo("port", ToJson(object.port_));
  jo("allowed", ToJson(object.allowed_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_controlProcess &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.controlProcess");
  jo("id", ToJson(object.id_));
  jo("permissions", ToJson(object.permissions_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_dht &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.dht");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_gc &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.gc");
  jo("ids", ToJson(object.ids_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_liteServer &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.liteServer");
  jo("id", ToJson(object.id_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator");
  jo("id", ToJson(object.id_));
  jo("temp_keys", ToJson(object.temp_keys_));
  jo("adnl_addrs", ToJson(object.adnl_addrs_));
  jo("election_date", ToJson(object.election_date_));
  jo("expire_at", ToJson(object.expire_at_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validatorAdnlAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validatorAdnlAddress");
  jo("id", ToJson(object.id_));
  jo("expire_at", ToJson(object.expire_at_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validatorTempKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validatorTempKey");
  jo("key", ToJson(object.key_));
  jo("expire_at", ToJson(object.expire_at_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_adnlProxy_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.adnlProxy.config");
  jo("ports", ToJson(object.ports_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_adnlProxy_port &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.adnlProxy.port");
  jo("in_port", ToJson(object.in_port_));
  jo("out_port", ToJson(object.out_port_));
  jo("dst_ip", ToJson(object.dst_ip_));
  jo("dst_port", ToJson(object.dst_port_));
  if (object.proxy_type_) {
    jo("proxy_type", ToJson(object.proxy_type_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::engine_dht_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.dht.config");
  jo("dht", ToJson(object.dht_));
  if (object.gc_) {
    jo("gc", ToJson(object.gc_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.config");
  jo("out_port", ToJson(object.out_port_));
  jo("addrs", ToJson(object.addrs_));
  jo("adnl", ToJson(object.adnl_));
  jo("dht", ToJson(object.dht_));
  jo("validators", ToJson(object.validators_));
  jo("fullnode", ToJson(object.fullnode_));
  jo("fullnodeslaves", ToJson(object.fullnodeslaves_));
  jo("fullnodemasters", ToJson(object.fullnodemasters_));
  jo("liteservers", ToJson(object.liteservers_));
  jo("control", ToJson(object.control_));
  if (object.gc_) {
    jo("gc", ToJson(object.gc_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_controlQueryError &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.controlQueryError");
  jo("code", ToJson(object.code_));
  jo("message", ToJson(object.message_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_dhtServerStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.dhtServerStatus");
  jo("id", ToJson(object.id_));
  jo("status", ToJson(object.status_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_dhtServersStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.dhtServersStatus");
  jo("servers", ToJson(object.servers_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_electionBid &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.electionBid");
  jo("election_date", ToJson(object.election_date_));
  jo("perm_key", ToJson(object.perm_key_));
  jo("adnl_addr", ToJson(object.adnl_addr_));
  jo("to_send_payload", ToJson(JsonBytes{object.to_send_payload_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_fullNodeMaster &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.fullNodeMaster");
  jo("port", ToJson(object.port_));
  jo("adnl", ToJson(object.adnl_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_fullNodeSlave &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.fullNodeSlave");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  if (object.adnl_) {
    jo("adnl", ToJson(object.adnl_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::validator_groupMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.groupMember");
  jo("public_key_hash", ToJson(object.public_key_hash_));
  jo("adnl", ToJson(object.adnl_));
  jo("weight", ToJson(JsonInt64{object.weight_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_jsonConfig &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.jsonConfig");
  jo("data", ToJson(object.data_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_keyHash &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.keyHash");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_oneStat &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.oneStat");
  jo("key", ToJson(object.key_));
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_proposalVote &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.proposalVote");
  jo("perm_key", ToJson(object.perm_key_));
  jo("to_send", ToJson(JsonBytes{object.to_send_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_signature &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.signature");
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_stats &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.stats");
  jo("stats", ToJson(object.stats_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_success &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.success");
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_time &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.time");
  jo("time", ToJson(object.time_));
}
void to_json(JsonValueScope &jv, const ton_api::fec_Type &object) {
  ton_api::downcast_call(const_cast<ton_api::fec_Type &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::fec_raptorQ &object) {
  auto jo = jv.enter_object();
  jo("@type", "fec.raptorQ");
  jo("data_size", ToJson(object.data_size_));
  jo("symbol_size", ToJson(object.symbol_size_));
  jo("symbols_count", ToJson(object.symbols_count_));
}
void to_json(JsonValueScope &jv, const ton_api::fec_roundRobin &object) {
  auto jo = jv.enter_object();
  jo("@type", "fec.roundRobin");
  jo("data_size", ToJson(object.data_size_));
  jo("symbol_size", ToJson(object.symbol_size_));
  jo("symbols_count", ToJson(object.symbols_count_));
}
void to_json(JsonValueScope &jv, const ton_api::fec_online &object) {
  auto jo = jv.enter_object();
  jo("@type", "fec.online");
  jo("data_size", ToJson(object.data_size_));
  jo("symbol_size", ToJson(object.symbol_size_));
  jo("symbols_count", ToJson(object.symbols_count_));
}
void to_json(JsonValueScope &jv, const ton_api::http_header &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.header");
  jo("name", ToJson(object.name_));
  jo("value", ToJson(object.value_));
}
void to_json(JsonValueScope &jv, const ton_api::http_payloadPart &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.payloadPart");
  jo("data", ToJson(JsonBytes{object.data_}));
  jo("trailer", ToJson(object.trailer_));
  jo("last", ToJson(JsonBool{object.last_}));
}
void to_json(JsonValueScope &jv, const ton_api::http_response &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.response");
  jo("http_version", ToJson(object.http_version_));
  jo("status_code", ToJson(object.status_code_));
  jo("reason", ToJson(object.reason_));
  jo("headers", ToJson(object.headers_));
}
void to_json(JsonValueScope &jv, const ton_api::http_server_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.server.config");
  jo("dhs", ToJson(object.dhs_));
  jo("local_hosts", ToJson(object.local_hosts_));
}
void to_json(JsonValueScope &jv, const ton_api::http_server_dnsEntry &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.server.dnsEntry");
  jo("domain", ToJson(object.domain_));
  if (object.addr_) {
    jo("addr", ToJson(object.addr_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::http_server_host &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.server.host");
  jo("domains", ToJson(object.domains_));
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  if (object.adnl_id_) {
    jo("adnl_id", ToJson(object.adnl_id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::id_config_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "id.config.local");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::liteclient_config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "liteclient.config.global");
  jo("liteservers", ToJson(object.liteservers_));
  if (object.validator_) {
    jo("validator", ToJson(object.validator_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::liteserver_desc &object) {
  auto jo = jv.enter_object();
  jo("@type", "liteserver.desc");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::liteserver_config_Local &object) {
  ton_api::downcast_call(const_cast<ton_api::liteserver_config_Local &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::liteserver_config_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "liteserver.config.local");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::liteserver_config_random_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "liteserver.config.random.local");
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_Broadcast &object) {
  ton_api::downcast_call(const_cast<ton_api::overlay_Broadcast &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::overlay_fec_received &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.fec.received");
  jo("hash", ToJson(object.hash_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_fec_completed &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.fec.completed");
  jo("hash", ToJson(object.hash_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_unicast &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.unicast");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcast &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcast");
  if (object.src_) {
    jo("src", ToJson(object.src_));
  }
  if (object.certificate_) {
    jo("certificate", ToJson(object.certificate_));
  }
  jo("flags", ToJson(object.flags_));
  jo("data", ToJson(JsonBytes{object.data_}));
  jo("date", ToJson(object.date_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcastFec &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcastFec");
  if (object.src_) {
    jo("src", ToJson(object.src_));
  }
  if (object.certificate_) {
    jo("certificate", ToJson(object.certificate_));
  }
  jo("data_hash", ToJson(object.data_hash_));
  jo("data_size", ToJson(object.data_size_));
  jo("flags", ToJson(object.flags_));
  jo("data", ToJson(JsonBytes{object.data_}));
  jo("seqno", ToJson(object.seqno_));
  if (object.fec_) {
    jo("fec", ToJson(object.fec_));
  }
  jo("date", ToJson(object.date_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcastFecShort &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcastFecShort");
  if (object.src_) {
    jo("src", ToJson(object.src_));
  }
  if (object.certificate_) {
    jo("certificate", ToJson(object.certificate_));
  }
  jo("broadcast_hash", ToJson(object.broadcast_hash_));
  jo("part_data_hash", ToJson(object.part_data_hash_));
  jo("seqno", ToJson(object.seqno_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcastNotFound &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcastNotFound");
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcastList &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcastList");
  jo("hashes", ToJson(object.hashes_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_Certificate &object) {
  ton_api::downcast_call(const_cast<ton_api::overlay_Certificate &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::overlay_certificate &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.certificate");
  if (object.issued_by_) {
    jo("issued_by", ToJson(object.issued_by_));
  }
  jo("expire_at", ToJson(object.expire_at_));
  jo("max_size", ToJson(object.max_size_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_emptyCertificate &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.emptyCertificate");
}
void to_json(JsonValueScope &jv, const ton_api::overlay_certificateId &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.certificateId");
  jo("overlay_id", ToJson(object.overlay_id_));
  jo("node", ToJson(object.node_));
  jo("expire_at", ToJson(object.expire_at_));
  jo("max_size", ToJson(object.max_size_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_message &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.message");
  jo("overlay", ToJson(object.overlay_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_node &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.node");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("overlay", ToJson(object.overlay_));
  jo("version", ToJson(object.version_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_nodes &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.nodes");
  jo("nodes", ToJson(object.nodes_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcast_id &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcast.id");
  jo("src", ToJson(object.src_));
  jo("data_hash", ToJson(object.data_hash_));
  jo("flags", ToJson(object.flags_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcast_toSign &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcast.toSign");
  jo("hash", ToJson(object.hash_));
  jo("date", ToJson(object.date_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcastFec_id &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcastFec.id");
  jo("src", ToJson(object.src_));
  jo("type", ToJson(object.type_));
  jo("data_hash", ToJson(object.data_hash_));
  jo("size", ToJson(object.size_));
  jo("flags", ToJson(object.flags_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_broadcastFec_partId &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.broadcastFec.partId");
  jo("broadcast_hash", ToJson(object.broadcast_hash_));
  jo("data_hash", ToJson(object.data_hash_));
  jo("seqno", ToJson(object.seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_db_key_nodes &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.db.key.nodes");
  jo("local_id", ToJson(object.local_id_));
  jo("overlay", ToJson(object.overlay_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_db_nodes &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.db.nodes");
  if (object.nodes_) {
    jo("nodes", ToJson(object.nodes_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::overlay_node_toSign &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.node.toSign");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("overlay", ToJson(object.overlay_));
  jo("version", ToJson(object.version_));
}
void to_json(JsonValueScope &jv, const ton_api::rldp_Message &object) {
  ton_api::downcast_call(const_cast<ton_api::rldp_Message &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::rldp_message &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp.message");
  jo("id", ToJson(object.id_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::rldp_query &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp.query");
  jo("query_id", ToJson(object.query_id_));
  jo("max_answer_size", ToJson(JsonInt64{object.max_answer_size_}));
  jo("timeout", ToJson(object.timeout_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::rldp_answer &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp.answer");
  jo("query_id", ToJson(object.query_id_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::rldp_MessagePart &object) {
  ton_api::downcast_call(const_cast<ton_api::rldp_MessagePart &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::rldp_messagePart &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp.messagePart");
  jo("transfer_id", ToJson(object.transfer_id_));
  if (object.fec_type_) {
    jo("fec_type", ToJson(object.fec_type_));
  }
  jo("part", ToJson(object.part_));
  jo("total_size", ToJson(JsonInt64{object.total_size_}));
  jo("seqno", ToJson(object.seqno_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::rldp_confirm &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp.confirm");
  jo("transfer_id", ToJson(object.transfer_id_));
  jo("part", ToJson(object.part_));
  jo("seqno", ToJson(object.seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::rldp_complete &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp.complete");
  jo("transfer_id", ToJson(object.transfer_id_));
  jo("part", ToJson(object.part_));
}
void to_json(JsonValueScope &jv, const ton_api::rldp2_MessagePart &object) {
  ton_api::downcast_call(const_cast<ton_api::rldp2_MessagePart &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::rldp2_messagePart &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp2.messagePart");
  jo("transfer_id", ToJson(object.transfer_id_));
  if (object.fec_type_) {
    jo("fec_type", ToJson(object.fec_type_));
  }
  jo("part", ToJson(object.part_));
  jo("total_size", ToJson(JsonInt64{object.total_size_}));
  jo("seqno", ToJson(object.seqno_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::rldp2_confirm &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp2.confirm");
  jo("transfer_id", ToJson(object.transfer_id_));
  jo("part", ToJson(object.part_));
  jo("max_seqno", ToJson(object.max_seqno_));
  jo("received_mask", ToJson(object.received_mask_));
  jo("received_count", ToJson(object.received_count_));
}
void to_json(JsonValueScope &jv, const ton_api::rldp2_complete &object) {
  auto jo = jv.enter_object();
  jo("@type", "rldp2.complete");
  jo("transfer_id", ToJson(object.transfer_id_));
  jo("part", ToJson(object.part_));
}
void to_json(JsonValueScope &jv, const ton_api::storage_piece &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.piece");
  jo("proof", ToJson(JsonBytes{object.proof_}));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::storage_pong &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.pong");
}
void to_json(JsonValueScope &jv, const ton_api::storage_state &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.state");
  jo("will_upload", ToJson(JsonBool{object.will_upload_}));
  jo("want_download", ToJson(JsonBool{object.want_download_}));
}
void to_json(JsonValueScope &jv, const ton_api::storage_Update &object) {
  ton_api::downcast_call(const_cast<ton_api::storage_Update &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::storage_updateInit &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.updateInit");
  jo("have_pieces", ToJson(JsonBytes{object.have_pieces_}));
  if (object.state_) {
    jo("state", ToJson(object.state_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::storage_updateHavePieces &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.updateHavePieces");
  jo("piece_id", ToJson(object.piece_id_));
}
void to_json(JsonValueScope &jv, const ton_api::storage_updateState &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.updateState");
  if (object.state_) {
    jo("state", ToJson(object.state_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tcp_Message &object) {
  ton_api::downcast_call(const_cast<ton_api::tcp_Message &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tcp_authentificate &object) {
  auto jo = jv.enter_object();
  jo("@type", "tcp.authentificate");
  jo("nonce", ToJson(JsonBytes{object.nonce_}));
}
void to_json(JsonValueScope &jv, const ton_api::tcp_authentificationNonce &object) {
  auto jo = jv.enter_object();
  jo("@type", "tcp.authentificationNonce");
  jo("nonce", ToJson(JsonBytes{object.nonce_}));
}
void to_json(JsonValueScope &jv, const ton_api::tcp_authentificationComplete &object) {
  auto jo = jv.enter_object();
  jo("@type", "tcp.authentificationComplete");
  if (object.key_) {
    jo("key", ToJson(object.key_));
  }
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::tcp_pong &object) {
  auto jo = jv.enter_object();
  jo("@type", "tcp.pong");
  jo("random_id", ToJson(JsonInt64{object.random_id_}));
}
void to_json(JsonValueScope &jv, const ton_api::ton_BlockId &object) {
  ton_api::downcast_call(const_cast<ton_api::ton_BlockId &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::ton_blockId &object) {
  auto jo = jv.enter_object();
  jo("@type", "ton.blockId");
  jo("root_cell_hash", ToJson(object.root_cell_hash_));
  jo("file_hash", ToJson(object.file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::ton_blockIdApprove &object) {
  auto jo = jv.enter_object();
  jo("@type", "ton.blockIdApprove");
  jo("root_cell_hash", ToJson(object.root_cell_hash_));
  jo("file_hash", ToJson(object.file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_ArchiveInfo &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_ArchiveInfo &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_archiveNotFound &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.archiveNotFound");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_archiveInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.archiveInfo");
  jo("id", ToJson(JsonInt64{object.id_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_BlockDescription &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_BlockDescription &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blockDescriptionEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blockDescriptionEmpty");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blockDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blockDescription");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blockId &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blockId");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("seqno", ToJson(object.seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blockIdExt &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blockIdExt");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("seqno", ToJson(object.seqno_));
  jo("root_hash", ToJson(object.root_hash_));
  jo("file_hash", ToJson(object.file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blockSignature &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blockSignature");
  jo("who", ToJson(object.who_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blocksDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blocksDescription");
  jo("ids", ToJson(object.ids_));
  jo("incomplete", ToJson(JsonBool{object.incomplete_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_Broadcast &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_Broadcast &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_blockBroadcast &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.blockBroadcast");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("catchain_seqno", ToJson(object.catchain_seqno_));
  jo("validator_set_hash", ToJson(object.validator_set_hash_));
  jo("signatures", ToJson(object.signatures_));
  jo("proof", ToJson(JsonBytes{object.proof_}));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_ihrMessageBroadcast &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.ihrMessageBroadcast");
  if (object.message_) {
    jo("message", ToJson(object.message_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_externalMessageBroadcast &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.externalMessageBroadcast");
  if (object.message_) {
    jo("message", ToJson(object.message_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_newShardBlockBroadcast &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.newShardBlockBroadcast");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_capabilities &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.capabilities");
  jo("version", ToJson(object.version_));
  jo("capabilities", ToJson(JsonInt64{object.capabilities_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_data &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.data");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_DataFull &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_DataFull &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_dataFull &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.dataFull");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
  jo("proof", ToJson(JsonBytes{object.proof_}));
  jo("block", ToJson(JsonBytes{object.block_}));
  jo("is_link", ToJson(JsonBool{object.is_link_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_dataFullEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.dataFullEmpty");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_dataList &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.dataList");
  jo("data", ToJson(JsonVectorBytes(object.data_)));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_externalMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.externalMessage");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_ihrMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.ihrMessage");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_keyBlocks &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.keyBlocks");
  jo("blocks", ToJson(object.blocks_));
  jo("incomplete", ToJson(JsonBool{object.incomplete_}));
  jo("error", ToJson(JsonBool{object.error_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_newShardBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.newShardBlock");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  jo("cc_seqno", ToJson(object.cc_seqno_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_Prepared &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_Prepared &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepared &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepared");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_notFound &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.notFound");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_PreparedProof &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_PreparedProof &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_preparedProofEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.preparedProofEmpty");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_preparedProof &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.preparedProof");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_preparedProofLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.preparedProofLink");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_PreparedState &object) {
  ton_api::downcast_call(const_cast<ton_api::tonNode_PreparedState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_preparedState &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.preparedState");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_notFoundState &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.notFoundState");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_sessionId &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.sessionId");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("cc_seqno", ToJson(object.cc_seqno_));
  jo("opts_hash", ToJson(object.opts_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_shardPublicOverlayId &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.shardPublicOverlayId");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("zero_state_file_hash", ToJson(object.zero_state_file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_success &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.success");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_zeroStateIdExt &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.zeroStateIdExt");
  jo("workchain", ToJson(object.workchain_));
  jo("root_hash", ToJson(object.root_hash_));
  jo("file_hash", ToJson(object.file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::validator_Group &object) {
  ton_api::downcast_call(const_cast<ton_api::validator_Group &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::validator_group &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.group");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("catchain_seqno", ToJson(object.catchain_seqno_));
  jo("config_hash", ToJson(object.config_hash_));
  jo("members", ToJson(object.members_));
}
void to_json(JsonValueScope &jv, const ton_api::validator_groupEx &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.groupEx");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("vertical_seqno", ToJson(object.vertical_seqno_));
  jo("catchain_seqno", ToJson(object.catchain_seqno_));
  jo("config_hash", ToJson(object.config_hash_));
  jo("members", ToJson(object.members_));
}
void to_json(JsonValueScope &jv, const ton_api::validator_groupNew &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.groupNew");
  jo("workchain", ToJson(object.workchain_));
  jo("shard", ToJson(JsonInt64{object.shard_}));
  jo("vertical_seqno", ToJson(object.vertical_seqno_));
  jo("last_key_block_seqno", ToJson(object.last_key_block_seqno_));
  jo("catchain_seqno", ToJson(object.catchain_seqno_));
  jo("config_hash", ToJson(object.config_hash_));
  jo("members", ToJson(object.members_));
}
void to_json(JsonValueScope &jv, const ton_api::validator_config_global &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.config.global");
  if (object.zero_state_) {
    jo("zero_state", ToJson(object.zero_state_));
  }
  if (object.init_block_) {
    jo("init_block", ToJson(object.init_block_));
  }
  jo("hardforks", ToJson(object.hardforks_));
}
void to_json(JsonValueScope &jv, const ton_api::validator_config_Local &object) {
  ton_api::downcast_call(const_cast<ton_api::validator_config_Local &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::validator_config_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.config.local");
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::validator_config_random_local &object) {
  auto jo = jv.enter_object();
  jo("@type", "validator.config.random.local");
  if (object.addr_list_) {
    jo("addr_list", ToJson(object.addr_list_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_blockUpdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.blockUpdate");
  jo("ts", ToJson(JsonInt64{object.ts_}));
  jo("actions", ToJson(object.actions_));
  jo("state", ToJson(object.state_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_candidate &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.candidate");
  jo("src", ToJson(object.src_));
  jo("round", ToJson(object.round_));
  jo("root_hash", ToJson(object.root_hash_));
  jo("data", ToJson(JsonBytes{object.data_}));
  jo("collated_data", ToJson(JsonBytes{object.collated_data_}));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_candidateId &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.candidateId");
  jo("src", ToJson(object.src_));
  jo("root_hash", ToJson(object.root_hash_));
  jo("file_hash", ToJson(object.file_hash_));
  jo("collated_data_file_hash", ToJson(object.collated_data_file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_Config &object) {
  ton_api::downcast_call(const_cast<ton_api::validatorSession_Config &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_config &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.config");
  jo("catchain_idle_timeout", ToJson(object.catchain_idle_timeout_));
  jo("catchain_max_deps", ToJson(object.catchain_max_deps_));
  jo("round_candidates", ToJson(object.round_candidates_));
  jo("next_candidate_delay", ToJson(object.next_candidate_delay_));
  jo("round_attempt_duration", ToJson(object.round_attempt_duration_));
  jo("max_round_attempts", ToJson(object.max_round_attempts_));
  jo("max_block_size", ToJson(object.max_block_size_));
  jo("max_collated_data_size", ToJson(object.max_collated_data_size_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_configNew &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.configNew");
  jo("catchain_idle_timeout", ToJson(object.catchain_idle_timeout_));
  jo("catchain_max_deps", ToJson(object.catchain_max_deps_));
  jo("round_candidates", ToJson(object.round_candidates_));
  jo("next_candidate_delay", ToJson(object.next_candidate_delay_));
  jo("round_attempt_duration", ToJson(object.round_attempt_duration_));
  jo("max_round_attempts", ToJson(object.max_round_attempts_));
  jo("max_block_size", ToJson(object.max_block_size_));
  jo("max_collated_data_size", ToJson(object.max_collated_data_size_));
  jo("new_catchain_ids", ToJson(JsonBool{object.new_catchain_ids_}));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_Message &object) {
  ton_api::downcast_call(const_cast<ton_api::validatorSession_Message &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_startSession &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.startSession");
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_finishSession &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.finishSession");
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_pong &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.pong");
  jo("hash", ToJson(JsonInt64{object.hash_}));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_round_id &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.round.id");
  jo("session", ToJson(object.session_));
  jo("height", ToJson(JsonInt64{object.height_}));
  jo("prev_block", ToJson(object.prev_block_));
  jo("seqno", ToJson(object.seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_round_Message &object) {
  ton_api::downcast_call(const_cast<ton_api::validatorSession_round_Message &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_submittedBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.submittedBlock");
  jo("round", ToJson(object.round_));
  jo("root_hash", ToJson(object.root_hash_));
  jo("file_hash", ToJson(object.file_hash_));
  jo("collated_data_file_hash", ToJson(object.collated_data_file_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_approvedBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.approvedBlock");
  jo("round", ToJson(object.round_));
  jo("candidate", ToJson(object.candidate_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_rejectedBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.rejectedBlock");
  jo("round", ToJson(object.round_));
  jo("candidate", ToJson(object.candidate_));
  jo("reason", ToJson(JsonBytes{object.reason_}));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_commit &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.commit");
  jo("round", ToJson(object.round_));
  jo("candidate", ToJson(object.candidate_));
  jo("signature", ToJson(JsonBytes{object.signature_}));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_vote &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.vote");
  jo("round", ToJson(object.round_));
  jo("attempt", ToJson(object.attempt_));
  jo("candidate", ToJson(object.candidate_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_voteFor &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.voteFor");
  jo("round", ToJson(object.round_));
  jo("attempt", ToJson(object.attempt_));
  jo("candidate", ToJson(object.candidate_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_precommit &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.precommit");
  jo("round", ToJson(object.round_));
  jo("attempt", ToJson(object.attempt_));
  jo("candidate", ToJson(object.candidate_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_message_empty &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.message.empty");
  jo("round", ToJson(object.round_));
  jo("attempt", ToJson(object.attempt_));
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_candidate_id &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.candidate.id");
  jo("round", ToJson(object.round_));
  jo("block_hash", ToJson(object.block_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::adnl_ping &object) {
  auto jo = jv.enter_object();
  jo("@type", "adnl.ping");
  jo("value", ToJson(JsonInt64{object.value_}));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_getBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.getBlock");
  jo("block", ToJson(object.block_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_getBlockHistory &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.getBlockHistory");
  jo("block", ToJson(object.block_));
  jo("height", ToJson(JsonInt64{object.height_}));
  jo("stop_if", ToJson(object.stop_if_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_getBlocks &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.getBlocks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::catchain_getDifference &object) {
  auto jo = jv.enter_object();
  jo("@type", "catchain.getDifference");
  jo("rt", ToJson(object.rt_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_findNode &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.findNode");
  jo("key", ToJson(object.key_));
  jo("k", ToJson(object.k_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_findValue &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.findValue");
  jo("key", ToJson(object.key_));
  jo("k", ToJson(object.k_));
}
void to_json(JsonValueScope &jv, const ton_api::dht_getSignedAddressList &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.getSignedAddressList");
}
void to_json(JsonValueScope &jv, const ton_api::dht_ping &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.ping");
  jo("random_id", ToJson(JsonInt64{object.random_id_}));
}
void to_json(JsonValueScope &jv, const ton_api::dht_query &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.query");
  if (object.node_) {
    jo("node", ToJson(object.node_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::dht_store &object) {
  auto jo = jv.enter_object();
  jo("@type", "dht.store");
  if (object.value_) {
    jo("value", ToJson(object.value_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addAdnlId &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addAdnlId");
  jo("key_hash", ToJson(object.key_hash_));
  jo("category", ToJson(object.category_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addControlInterface &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addControlInterface");
  jo("key_hash", ToJson(object.key_hash_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addControlProcess &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addControlProcess");
  jo("key_hash", ToJson(object.key_hash_));
  jo("port", ToJson(object.port_));
  jo("peer_key", ToJson(object.peer_key_));
  jo("permissions", ToJson(object.permissions_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addDhtId &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addDhtId");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addListeningPort &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addListeningPort");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  jo("categories", ToJson(object.categories_));
  jo("priority_categories", ToJson(object.priority_categories_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addLiteserver &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addLiteserver");
  jo("key_hash", ToJson(object.key_hash_));
  jo("port", ToJson(object.port_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addProxy");
  jo("in_ip", ToJson(object.in_ip_));
  jo("in_port", ToJson(object.in_port_));
  jo("out_ip", ToJson(object.out_ip_));
  jo("out_port", ToJson(object.out_port_));
  if (object.proxy_) {
    jo("proxy", ToJson(object.proxy_));
  }
  jo("categories", ToJson(object.categories_));
  jo("priority_categories", ToJson(object.priority_categories_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addValidatorAdnlAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addValidatorAdnlAddress");
  jo("permanent_key_hash", ToJson(object.permanent_key_hash_));
  jo("key_hash", ToJson(object.key_hash_));
  jo("ttl", ToJson(object.ttl_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addValidatorPermanentKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addValidatorPermanentKey");
  jo("key_hash", ToJson(object.key_hash_));
  jo("election_date", ToJson(object.election_date_));
  jo("ttl", ToJson(object.ttl_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_addValidatorTempKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.addValidatorTempKey");
  jo("permanent_key_hash", ToJson(object.permanent_key_hash_));
  jo("key_hash", ToJson(object.key_hash_));
  jo("ttl", ToJson(object.ttl_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_changeFullNodeAdnlAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.changeFullNodeAdnlAddress");
  jo("adnl_id", ToJson(object.adnl_id_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_checkDhtServers &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.checkDhtServers");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_controlQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.controlQuery");
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_createComplaintVote &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.createComplaintVote");
  jo("election_id", ToJson(object.election_id_));
  jo("vote", ToJson(JsonBytes{object.vote_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_createElectionBid &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.createElectionBid");
  jo("election_date", ToJson(object.election_date_));
  jo("election_addr", ToJson(object.election_addr_));
  jo("wallet", ToJson(object.wallet_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_createProposalVote &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.createProposalVote");
  jo("vote", ToJson(JsonBytes{object.vote_}));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delAdnlId &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delAdnlId");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delDhtId &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delDhtId");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delListeningPort &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delListeningPort");
  jo("ip", ToJson(object.ip_));
  jo("port", ToJson(object.port_));
  jo("categories", ToJson(object.categories_));
  jo("priority_categories", ToJson(object.priority_categories_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delProxy");
  jo("out_ip", ToJson(object.out_ip_));
  jo("out_port", ToJson(object.out_port_));
  jo("categories", ToJson(object.categories_));
  jo("priority_categories", ToJson(object.priority_categories_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delValidatorAdnlAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delValidatorAdnlAddress");
  jo("permanent_key_hash", ToJson(object.permanent_key_hash_));
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delValidatorPermanentKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delValidatorPermanentKey");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_delValidatorTempKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.delValidatorTempKey");
  jo("permanent_key_hash", ToJson(object.permanent_key_hash_));
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_exportPrivateKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.exportPrivateKey");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_exportPublicKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.exportPublicKey");
  jo("key_hash", ToJson(object.key_hash_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_generateKeyPair &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.generateKeyPair");
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_getConfig &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.getConfig");
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_getStats &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.getStats");
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_getTime &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.getTime");
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_importPrivateKey &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.importPrivateKey");
  if (object.key_) {
    jo("key", ToJson(object.key_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_setVerbosity &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.setVerbosity");
  jo("verbosity", ToJson(object.verbosity_));
}
void to_json(JsonValueScope &jv, const ton_api::engine_validator_sign &object) {
  auto jo = jv.enter_object();
  jo("@type", "engine.validator.sign");
  jo("key_hash", ToJson(object.key_hash_));
  jo("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const ton_api::getTestObject &object) {
  auto jo = jv.enter_object();
  jo("@type", "getTestObject");
}
void to_json(JsonValueScope &jv, const ton_api::http_getNextPayloadPart &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.getNextPayloadPart");
  jo("id", ToJson(object.id_));
  jo("seqno", ToJson(object.seqno_));
  jo("max_chunk_size", ToJson(object.max_chunk_size_));
}
void to_json(JsonValueScope &jv, const ton_api::http_request &object) {
  auto jo = jv.enter_object();
  jo("@type", "http.request");
  jo("id", ToJson(object.id_));
  jo("method", ToJson(object.method_));
  jo("url", ToJson(object.url_));
  jo("http_version", ToJson(object.http_version_));
  jo("headers", ToJson(object.headers_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_getBroadcast &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.getBroadcast");
  jo("hash", ToJson(object.hash_));
}
void to_json(JsonValueScope &jv, const ton_api::overlay_getBroadcastList &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.getBroadcastList");
  if (object.list_) {
    jo("list", ToJson(object.list_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::overlay_getRandomPeers &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.getRandomPeers");
  if (object.peers_) {
    jo("peers", ToJson(object.peers_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::overlay_query &object) {
  auto jo = jv.enter_object();
  jo("@type", "overlay.query");
  jo("overlay", ToJson(object.overlay_));
}
void to_json(JsonValueScope &jv, const ton_api::storage_addUpdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.addUpdate");
  jo("session_id", ToJson(JsonInt64{object.session_id_}));
  jo("seqno", ToJson(object.seqno_));
  if (object.update_) {
    jo("update", ToJson(object.update_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::storage_getPiece &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.getPiece");
  jo("piece_id", ToJson(object.piece_id_));
}
void to_json(JsonValueScope &jv, const ton_api::storage_ping &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.ping");
  jo("session_id", ToJson(JsonInt64{object.session_id_}));
}
void to_json(JsonValueScope &jv, const ton_api::storage_queryPrefix &object) {
  auto jo = jv.enter_object();
  jo("@type", "storage.queryPrefix");
  jo("id", ToJson(object.id_));
}
void to_json(JsonValueScope &jv, const ton_api::tcp_ping &object) {
  auto jo = jv.enter_object();
  jo("@type", "tcp.ping");
  jo("random_id", ToJson(JsonInt64{object.random_id_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlock");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlockFull &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlockFull");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlockProof &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlockProof");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlockProofLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlockProofLink");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlockProofLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlockProofLinks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlockProofs &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlockProofs");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadBlocks &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadBlocks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadKeyBlockProof &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadKeyBlockProof");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadKeyBlockProofLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadKeyBlockProofLink");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadKeyBlockProofLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadKeyBlockProofLinks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadKeyBlockProofs &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadKeyBlockProofs");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadNextBlockFull &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadNextBlockFull");
  if (object.prev_block_) {
    jo("prev_block", ToJson(object.prev_block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadPersistentState &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadPersistentState");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  if (object.masterchain_block_) {
    jo("masterchain_block", ToJson(object.masterchain_block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadPersistentStateSlice &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadPersistentStateSlice");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  if (object.masterchain_block_) {
    jo("masterchain_block", ToJson(object.masterchain_block_));
  }
  jo("offset", ToJson(JsonInt64{object.offset_}));
  jo("max_size", ToJson(JsonInt64{object.max_size_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_downloadZeroState &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.downloadZeroState");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getArchiveInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getArchiveInfo");
  jo("masterchain_seqno", ToJson(object.masterchain_seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getArchiveSlice &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getArchiveSlice");
  jo("archive_id", ToJson(JsonInt64{object.archive_id_}));
  jo("offset", ToJson(JsonInt64{object.offset_}));
  jo("max_size", ToJson(object.max_size_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getCapabilities &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getCapabilities");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getNextBlockDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getNextBlockDescription");
  if (object.prev_block_) {
    jo("prev_block", ToJson(object.prev_block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getNextBlocksDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getNextBlocksDescription");
  if (object.prev_block_) {
    jo("prev_block", ToJson(object.prev_block_));
  }
  jo("limit", ToJson(object.limit_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getNextKeyBlockIds &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getNextKeyBlockIds");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  jo("max_size", ToJson(object.max_size_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_getPrevBlocksDescription &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.getPrevBlocksDescription");
  if (object.next_block_) {
    jo("next_block", ToJson(object.next_block_));
  }
  jo("limit", ToJson(object.limit_));
  jo("cutoff_seqno", ToJson(object.cutoff_seqno_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareBlock");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareBlockProof &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareBlockProof");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  jo("allow_partial", ToJson(JsonBool{object.allow_partial_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareBlockProofs &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareBlockProofs");
  jo("blocks", ToJson(object.blocks_));
  jo("allow_partial", ToJson(JsonBool{object.allow_partial_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareBlocks &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareBlocks");
  jo("blocks", ToJson(object.blocks_));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareKeyBlockProof &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareKeyBlockProof");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  jo("allow_partial", ToJson(JsonBool{object.allow_partial_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareKeyBlockProofs &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareKeyBlockProofs");
  jo("blocks", ToJson(object.blocks_));
  jo("allow_partial", ToJson(JsonBool{object.allow_partial_}));
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_preparePersistentState &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.preparePersistentState");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
  if (object.masterchain_block_) {
    jo("masterchain_block", ToJson(object.masterchain_block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_prepareZeroState &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.prepareZeroState");
  if (object.block_) {
    jo("block", ToJson(object.block_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_query &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.query");
}
void to_json(JsonValueScope &jv, const ton_api::tonNode_slave_sendExtMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonNode.slave.sendExtMessage");
  if (object.message_) {
    jo("message", ToJson(object.message_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_downloadCandidate &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.downloadCandidate");
  jo("round", ToJson(object.round_));
  if (object.id_) {
    jo("id", ToJson(object.id_));
  }
}
void to_json(JsonValueScope &jv, const ton_api::validatorSession_ping &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatorSession.ping");
  jo("hash", ToJson(JsonInt64{object.hash_}));
}
}  // namespace ton_api
}  // namespace ton
