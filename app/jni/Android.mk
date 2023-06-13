LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := crypto

ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
    LOCAL_SRC_FILES := ./boringssl/lib/libcrypto_arm64-v8a.a
else ifeq ($(TARGET_ARCH_ABI),x86_64)
    LOCAL_SRC_FILES := ./boringssl/lib/libcrypto_x86_64.a
endif

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_ARM_MODE  := arm
LOCAL_MODULE := lz4
LOCAL_CFLAGS 	:= -w -std=c11 -O3

LOCAL_SRC_FILES     := \
./lz4/lz4.c \
./lz4/lz4frame.c \
./lz4/xxhash.c

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_ARM_MODE  := arm
LOCAL_MODULE := rlottie
LOCAL_CPPFLAGS := -DNDEBUG -Wall -std=c++14 -DANDROID -fno-rtti -DHAVE_PTHREAD -finline-functions -ffast-math -Os -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wnon-virtual-dtor -Woverloaded-virtual -Wno-unused-parameter -fvisibility=hidden
ifeq ($(TARGET_ARCH_ABI),$(filter $(TARGET_ARCH_ABI),arm64-v8a))
 LOCAL_CFLAGS := -DUSE_ARM_NEON -D__ARM64_NEON__ -fno-integrated-as
 LOCAL_CPPFLAGS += -DUSE_ARM_NEON -D__ARM64_NEON__ -fno-integrated-as
endif

LOCAL_C_INCLUDES := \
./jni/rlottie/inc \
./jni/rlottie/src/vector/ \
./jni/rlottie/src/vector/pixman \
./jni/rlottie/src/vector/freetype \
./jni/rlottie/src/vector/stb

LOCAL_SRC_FILES     := \
./rlottie/src/lottie/lottieanimation.cpp \
./rlottie/src/lottie/lottieitem.cpp \
./rlottie/src/lottie/lottiekeypath.cpp \
./rlottie/src/lottie/lottieloader.cpp \
./rlottie/src/lottie/lottiemodel.cpp \
./rlottie/src/lottie/lottieparser.cpp \
./rlottie/src/lottie/lottieproxymodel.cpp \
./rlottie/src/vector/freetype/v_ft_math.cpp \
./rlottie/src/vector/freetype/v_ft_raster.cpp \
./rlottie/src/vector/freetype/v_ft_stroker.cpp \
./rlottie/src/vector/pixman/vregion.cpp \
./rlottie/src/vector/stb/stb_image.cpp \
./rlottie/src/vector/vbezier.cpp \
./rlottie/src/vector/vbitmap.cpp \
./rlottie/src/vector/vbrush.cpp \
./rlottie/src/vector/vcompositionfunctions.cpp \
./rlottie/src/vector/vdasher.cpp \
./rlottie/src/vector/vdebug.cpp \
./rlottie/src/vector/vdrawable.cpp \
./rlottie/src/vector/vdrawhelper.cpp \
./rlottie/src/vector/vdrawhelper_neon.cpp \
./rlottie/src/vector/velapsedtimer.cpp \
./rlottie/src/vector/vimageloader.cpp \
./rlottie/src/vector/vinterpolator.cpp \
./rlottie/src/vector/vmatrix.cpp \
./rlottie/src/vector/vpainter.cpp \
./rlottie/src/vector/vpath.cpp \
./rlottie/src/vector/vpathmesure.cpp \
./rlottie/src/vector/vraster.cpp \
./rlottie/src/vector/vrect.cpp \
./rlottie/src/vector/vrle.cpp

ifeq ($(TARGET_ARCH_ABI),$(filter $(TARGET_ARCH_ABI),arm64-v8a))
    LOCAL_SRC_FILES += ./rlottie/src/vector/pixman/pixman-arma64-neon-asm.S.neon
endif

LOCAL_STATIC_LIBRARIES := cpufeatures
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_ARM_MODE  := arm
LOCAL_MODULE := tonlib
LOCAL_CPPFLAGS := -DNDEBUG -Wall -std=c++14 -DANDROID -frtti -DHAVE_PTHREAD -finline-functions -ffast-math -Os -fexceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wnon-virtual-dtor -Woverloaded-virtual -Wno-unused-parameter -fvisibility=hidden
LOCAL_STATIC_LIBRARIES := crypto
LOCAL_SHORT_COMMANDS := true
APP_SHORT_COMMANDS := true

LOCAL_C_INCLUDES := \
./jni/ton \
./jni/ton/crypto \
./jni/ton/third-party \
./jni/ton/third-party/crc32c/include \
./jni/boringssl/include

LOCAL_SRC_FILES     := \
./ton/adnl/adnl-address-list.cpp \
./ton/adnl/adnl-channel.cpp \
./ton/adnl/adnl-ext-client.cpp \
./ton/adnl/adnl-ext-connection.cpp \
./ton/adnl/adnl-ext-server.cpp \
./ton/adnl/adnl-local-id.cpp \
./ton/adnl/adnl-message.cpp \
./ton/adnl/adnl-network-manager.cpp \
./ton/adnl/adnl-node.cpp \
./ton/adnl/adnl-node-id.cpp \
./ton/adnl/adnl-packet.cpp \
./ton/adnl/adnl-peer.cpp \
./ton/adnl/adnl-pong.cpp \
./ton/adnl/adnl-proxy-types.cpp \
./ton/adnl/adnl-proxy.cpp \
./ton/adnl/adnl-query.cpp \
./ton/adnl/adnl-static-nodes.cpp \
./ton/adnl/adnl-test-loopback-implementation.cpp \
./ton/adnl/utils.cpp \
./ton/auto/tl/lite_api.cpp \
./ton/auto/tl/ton_api.cpp \
./ton/auto/tl/tonlib_api.cpp \
./ton/auto/tl/ton_api_json.cpp \
./ton/auto/tl/tonlib_api_json.cpp \
./ton/common/errorlog.cpp \
./ton/crypto/Ed25519.cpp \
./ton/crypto/block/adjust-block.cpp \
./ton/crypto/block/Binlog.cpp \
./ton/crypto/block/block-auto.cpp \
./ton/crypto/block/block-db.cpp \
./ton/crypto/block/block-parse.cpp \
./ton/crypto/block/block.cpp \
./ton/crypto/block/check-proof.cpp \
./ton/crypto/block/create-state.cpp \
./ton/crypto/block/dump-block.cpp \
./ton/crypto/block/mc-config.cpp \
./ton/crypto/block/output-queue-merger.cpp \
./ton/crypto/block/transaction.cpp \
./ton/crypto/common/bigexp.cpp \
./ton/crypto/common/bigint.cpp \
./ton/crypto/common/bitstring.cpp \
./ton/crypto/common/refcnt.cpp \
./ton/crypto/common/refint.cpp \
./ton/crypto/common/util.cpp \
./ton/crypto/ellcurve/Ed25519.cpp \
./ton/crypto/ellcurve/Fp25519.cpp \
./ton/crypto/ellcurve/Montgomery.cpp \
./ton/crypto/ellcurve/TwEdwards.cpp \
./ton/crypto/fift/Dictionary.cpp \
./ton/crypto/fift/Fift.cpp \
./ton/crypto/fift/IntCtx.cpp \
./ton/crypto/fift/SourceLookup.cpp \
./ton/crypto/fift/fift-main.cpp \
./ton/crypto/fift/utils.cpp \
./ton/crypto/fift/words.cpp \
./ton/crypto/func/abscode.cpp \
./ton/crypto/func/analyzer.cpp \
./ton/crypto/func/asmops.cpp \
./ton/crypto/func/builtins.cpp \
./ton/crypto/func/codegen.cpp \
./ton/crypto/func/func.cpp \
./ton/crypto/func/gen-abscode.cpp \
./ton/crypto/func/keywords.cpp \
./ton/crypto/func/optimize.cpp \
./ton/crypto/func/parse-func.cpp \
./ton/crypto/func/stack-transform.cpp \
./ton/crypto/func/unify-types.cpp \
./ton/crypto/openssl/bignum.cpp \
./ton/crypto/openssl/rand.cpp \
./ton/crypto/openssl/residue.cpp \
./ton/crypto/parser/lexer.cpp \
./ton/crypto/parser/srcread.cpp \
./ton/crypto/parser/symtable.cpp \
./ton/crypto/tl/tlbc.cpp \
./ton/crypto/tl/tlblib.cpp \
./ton/crypto/smc-envelope/GenericAccount.cpp \
./ton/crypto/smc-envelope/HighloadWallet.cpp \
./ton/crypto/smc-envelope/HighloadWalletV2.cpp \
./ton/crypto/smc-envelope/ManualDns.cpp \
./ton/crypto/smc-envelope/MultisigWallet.cpp \
./ton/crypto/smc-envelope/PaymentChannel.cpp \
./ton/crypto/smc-envelope/SmartContract.cpp \
./ton/crypto/smc-envelope/SmartContractCode.cpp \
./ton/crypto/smc-envelope/WalletInterface.cpp \
./ton/crypto/smc-envelope/WalletV3.cpp \
./ton/crypto/smc-envelope/GenericAccount.h \
./ton/crypto/smc-envelope/HighloadWallet.h \
./ton/crypto/smc-envelope/HighloadWalletV2.h \
./ton/crypto/smc-envelope/ManualDns.h \
./ton/crypto/smc-envelope/MultisigWallet.h \
./ton/crypto/smc-envelope/SmartContract.h \
./ton/crypto/smc-envelope/SmartContractCode.h \
./ton/crypto/smc-envelope/WalletInterface.h \
./ton/crypto/smc-envelope/WalletV3.h \
./ton/crypto/vm/arithops.cpp \
./ton/crypto/vm/atom.cpp \
./ton/crypto/vm/boc.cpp \
./ton/crypto/vm/cellops.cpp \
./ton/crypto/vm/continuation.cpp \
./ton/crypto/vm/contops.cpp \
./ton/crypto/vm/cp0.cpp \
./ton/crypto/vm/debugops.cpp \
./ton/crypto/vm/dict.cpp \
./ton/crypto/vm/dictops.cpp \
./ton/crypto/vm/memo.cpp \
./ton/crypto/vm/dispatch.cpp \
./ton/crypto/vm/opctable.cpp \
./ton/crypto/vm/stack.cpp \
./ton/crypto/vm/stackops.cpp \
./ton/crypto/vm/tonops.cpp \
./ton/crypto/vm/tupleops.cpp \
./ton/crypto/vm/utils.cpp \
./ton/crypto/vm/vm.cpp \
./ton/crypto/vm/cells/Cell.cpp \
./ton/crypto/vm/cells/CellBuilder.cpp \
./ton/crypto/vm/cells/CellHash.cpp \
./ton/crypto/vm/cells/CellSlice.cpp \
./ton/crypto/vm/cells/CellString.cpp \
./ton/crypto/vm/cells/CellTraits.cpp \
./ton/crypto/vm/cells/CellUsageTree.cpp \
./ton/crypto/vm/cells/DataCell.cpp \
./ton/crypto/vm/cells/LevelMask.cpp \
./ton/crypto/vm/cells/MerkleProof.cpp \
./ton/crypto/vm/cells/MerkleUpdate.cpp \
./ton/crypto/vm/db/CellStorage.cpp \
./ton/crypto/vm/db/DynamicBagOfCellsDb.cpp \
./ton/crypto/vm/db/StaticBagOfCellsDb.cpp \
./ton/crypto/vm/db/TonDb.cpp \
./ton/keyring/keyring.cpp \
./ton/keys/encryptor.cpp \
./ton/keys/keys.cpp \
./ton/lite-client/lite-client-common.cpp \
./ton/td/actor/MultiPromise.cpp \
./ton/td/actor/core/ActorExecutor.cpp \
./ton/td/actor/core/CpuWorker.cpp \
./ton/td/actor/core/IoWorker.cpp \
./ton/td/actor/core/Scheduler.cpp \
./ton/td/db/MemoryKeyValue.cpp \
./ton/td/db/binlog/Binlog.cpp \
./ton/td/db/binlog/BinlogReaderHelper.cpp \
./ton/td/db/utils/ChainBuffer.cpp \
./ton/td/db/utils/CyclicBuffer.cpp \
./ton/td/db/utils/FileSyncState.cpp \
./ton/td/db/utils/FileToStreamActor.cpp \
./ton/td/db/utils/StreamInterface.cpp \
./ton/td/db/utils/StreamToFileActor.cpp \
./ton/td/net/FdListener.cpp \
./ton/td/net/TcpListener.cpp \
./ton/td/net/UdpServer.cpp \
./ton/td/utils/BigNum.cpp \
./ton/td/utils/BufferedUdp.cpp \
./ton/td/utils/FileLog.cpp \
./ton/td/utils/Gzip.cpp \
./ton/td/utils/GzipByteFlow.cpp \
./ton/td/utils/Hints.cpp \
./ton/td/utils/HttpUrl.cpp \
./ton/td/utils/JsonBuilder.cpp \
./ton/td/utils/MimeType.cpp \
./ton/td/utils/MpmcQueue.cpp \
./ton/td/utils/OptionParser.cpp \
./ton/td/utils/PathView.cpp \
./ton/td/utils/Random.cpp \
./ton/td/utils/SharedSlice.cpp \
./ton/td/utils/Slice.cpp \
./ton/td/utils/StackAllocator.cpp \
./ton/td/utils/Status.cpp \
./ton/td/utils/StringBuilder.cpp \
./ton/td/utils/Time.cpp \
./ton/td/utils/Timer.cpp \
./ton/td/utils/TsFileLog.cpp \
./ton/td/utils/base64.cpp \
./ton/td/utils/buffer.cpp \
./ton/td/utils/check.cpp \
./ton/td/utils/crypto.cpp \
./ton/td/utils/filesystem.cpp \
./ton/td/utils/find_boundary.cpp \
./ton/td/utils/logging.cpp \
./ton/td/utils/misc.cpp \
./ton/td/utils/tests.cpp \
./ton/td/utils/tl_parsers.cpp \
./ton/td/utils/translit.cpp \
./ton/td/utils/unicode.cpp \
./ton/td/utils/utf8.cpp \
./ton/td/utils/port/Clocks.cpp \
./ton/td/utils/port/FileFd.cpp \
./ton/td/utils/port/IPAddress.cpp \
./ton/td/utils/port/MemoryMapping.cpp \
./ton/td/utils/port/PollFlags.cpp \
./ton/td/utils/port/ServerSocketFd.cpp \
./ton/td/utils/port/SocketFd.cpp \
./ton/td/utils/port/Stat.cpp \
./ton/td/utils/port/StdStreams.cpp \
./ton/td/utils/port/UdpSocketFd.cpp \
./ton/td/utils/port/path.cpp \
./ton/td/utils/port/rlimit.cpp \
./ton/td/utils/port/signals.cpp \
./ton/td/utils/port/sleep.cpp \
./ton/td/utils/port/stacktrace.cpp \
./ton/td/utils/port/thread_local.cpp \
./ton/td/utils/port/user.cpp \
./ton/td/utils/port/wstring_convert.cpp \
./ton/td/utils/port/detail/Epoll.cpp \
./ton/td/utils/port/detail/EventFdBsd.cpp \
./ton/td/utils/port/detail/EventFdLinux.cpp \
./ton/td/utils/port/detail/EventFdWindows.cpp \
./ton/td/utils/port/detail/Iocp.cpp \
./ton/td/utils/port/detail/KQueue.cpp \
./ton/td/utils/port/detail/NativeFd.cpp \
./ton/td/utils/port/detail/Poll.cpp \
./ton/td/utils/port/detail/Select.cpp \
./ton/td/utils/port/detail/ThreadIdGuard.cpp \
./ton/td/utils/port/detail/WineventPoll.cpp \
./ton/terminal/terminal.cpp \
./ton/third-party/crc32c/src/crc32c_portable.cc \
./ton/third-party/crc32c/src/crc32c.cc \
./ton/tl/tl_jni_object.cpp \
./ton/tl-utils/lite-utils.cpp \
./ton/tl-utils/tl-utils.cpp \
./ton/tonlib/Client.cpp \
./ton/tonlib/ClientActor.cpp \
./ton/tonlib/ClientJson.cpp \
./ton/tonlib/Config.cpp \
./ton/tonlib/ExtClient.cpp \
./ton/tonlib/ExtClientLazy.cpp \
./ton/tonlib/ExtClientOutbound.cpp \
./ton/tonlib/KeyStorage.cpp \
./ton/tonlib/KeyValue.cpp \
./ton/tonlib/LastBlock.cpp \
./ton/tonlib/LastBlockStorage.cpp \
./ton/tonlib/LastConfig.cpp \
./ton/tonlib/Logging.cpp \
./ton/tonlib/TonlibClient.cpp \
./ton/tonlib/tonlib_client_json.cpp \
./ton/tonlib/utils.cpp \
./ton/tonlib/keys/bip39.cpp \
./ton/tonlib/keys/DecryptedKey.cpp \
./ton/tonlib/keys/EncryptedKey.cpp \
./ton/tonlib/keys/Mnemonic.cpp \
./ton/tonlib/keys/SimpleEncryption.cpp

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_PRELINK_MODULE := false

LOCAL_MODULE 	:= tmessages.30
LOCAL_CFLAGS 	:= -w -std=c11 -Os -DNULL=0 -DSOCKLEN_T=socklen_t -DLOCALE_NOT_USED -D_LARGEFILE_SOURCE=1
LOCAL_CFLAGS 	+= -Drestrict='' -D__EMX__ -DOPUS_BUILD -DFIXED_POINT -DUSE_ALLOCA -DHAVE_LRINT -DHAVE_LRINTF -fno-math-errno
LOCAL_CFLAGS 	+= -DANDROID_NDK -DDISABLE_IMPORTGL -fno-strict-aliasing -fprefetch-loop-arrays -DAVOID_TABLES -DANDROID_TILE_BASED_DECODE -DANDROID_ARMV6_IDCT -ffast-math -D__STDC_CONSTANT_MACROS
LOCAL_CPPFLAGS 	:= -DBSD=1 -ffast-math -Os -funroll-loops -std=c++14 -DPACKAGE_NAME='"drinkless/org/ton"'
LOCAL_LDLIBS 	:= -ljnigraphics -llog -lz -lEGL -lGLESv2 -landroid
LOCAL_STATIC_LIBRARIES := lz4 rlottie tonlib

LOCAL_C_INCLUDES    := \
./jni/boringssl/include \
./jni/rlottie/inc \
./jni/ton \
./jni/lz4

LOCAL_SRC_FILES     += \
./jni.c \
./lottie.cpp \
./tonlib.cpp

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/cpufeatures)