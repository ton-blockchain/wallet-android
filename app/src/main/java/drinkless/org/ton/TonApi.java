package drinkless.org.ton;

public class TonApi {
    /**
     * This class is a base class for all tonlib interface classes.
     */
    public abstract static class Object {
        /**
         * @return string representation of the object.
         */
        public native String toString();

        /**
         * @return identifier uniquely determining type of the object.
         */
        public abstract int getConstructor();
    }

    /**
     * This class is a base class for all tonlib interface function-classes.
     */
    public abstract static class Function extends Object {
        /**
         * @return string representation of the object.
         */
        public native String toString();
    }

    /**
     *
     */
    public static class AccountAddress extends Object {
        public String accountAddress;

        /**
         *
         */
        public AccountAddress() {
        }

        public AccountAddress(String accountAddress) {
            this.accountAddress = accountAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 755613099;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class AccountList extends Object {
        public FullAccountState[] accounts;

        /**
         *
         */
        public AccountList() {
        }

        public AccountList(FullAccountState[] accounts) {
            this.accounts = accounts;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 2017374805;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class AccountRevisionList extends Object {
        public FullAccountState[] revisions;

        /**
         *
         */
        public AccountRevisionList() {
        }

        public AccountRevisionList(FullAccountState[] revisions) {
            this.revisions = revisions;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 527197386;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class AccountState extends Object {
    }

    public static class RawAccountState extends AccountState {
        public byte[] code;
        public byte[] data;
        public byte[] frozenHash;

        /**
         *
         */
        public RawAccountState() {
        }

        public RawAccountState(byte[] code, byte[] data, byte[] frozenHash) {
            this.code = code;
            this.data = data;
            this.frozenHash = frozenHash;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -531917254;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TestWalletAccountState extends AccountState {
        public int seqno;

        /**
         *
         */
        public TestWalletAccountState() {
        }

        public TestWalletAccountState(int seqno) {
            this.seqno = seqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2053909931;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletAccountState extends AccountState {
        public int seqno;

        /**
         *
         */
        public WalletAccountState() {
        }

        public WalletAccountState(int seqno) {
            this.seqno = seqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -390017192;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletV3AccountState extends AccountState {
        public long walletId;
        public int seqno;

        /**
         *
         */
        public WalletV3AccountState() {
        }

        public WalletV3AccountState(long walletId, int seqno) {
            this.walletId = walletId;
            this.seqno = seqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1619351478;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletHighloadV1AccountState extends AccountState {
        public long walletId;
        public int seqno;

        /**
         *
         */
        public WalletHighloadV1AccountState() {
        }

        public WalletHighloadV1AccountState(long walletId, int seqno) {
            this.walletId = walletId;
            this.seqno = seqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1616372956;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletHighloadV2AccountState extends AccountState {
        public long walletId;

        /**
         *
         */
        public WalletHighloadV2AccountState() {
        }

        public WalletHighloadV2AccountState(long walletId) {
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1803723441;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TestGiverAccountState extends AccountState {
        public int seqno;

        /**
         *
         */
        public TestGiverAccountState() {
        }

        public TestGiverAccountState(int seqno) {
            this.seqno = seqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -696813142;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsAccountState extends AccountState {
        public long walletId;

        /**
         *
         */
        public DnsAccountState() {
        }

        public DnsAccountState(long walletId) {
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1727715434;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class RwalletAccountState extends AccountState {
        public long walletId;
        public int seqno;
        public long unlockedBalance;
        public RwalletConfig config;

        /**
         *
         */
        public RwalletAccountState() {
        }

        public RwalletAccountState(long walletId, int seqno, long unlockedBalance, RwalletConfig config) {
            this.walletId = walletId;
            this.seqno = seqno;
            this.unlockedBalance = unlockedBalance;
            this.config = config;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -739540008;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class PchanAccountState extends AccountState {
        public PchanConfig config;
        public PchanState state;
        public String description;

        /**
         *
         */
        public PchanAccountState() {
        }

        public PchanAccountState(PchanConfig config, PchanState state, String description) {
            this.config = config;
            this.state = state;
            this.description = description;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1612869496;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class UninitedAccountState extends AccountState {
        public byte[] frozenHash;

        /**
         *
         */
        public UninitedAccountState() {
        }

        public UninitedAccountState(byte[] frozenHash) {
            this.frozenHash = frozenHash;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1522374408;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class Action extends Object {
    }

    public static class ActionNoop extends Action {

        /**
         *
         */
        public ActionNoop() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1135848603;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class ActionMsg extends Action {
        public MsgMessage[] messages;
        public boolean allowSendToUninited;

        /**
         *
         */
        public ActionMsg() {
        }

        public ActionMsg(MsgMessage[] messages, boolean allowSendToUninited) {
            this.messages = messages;
            this.allowSendToUninited = allowSendToUninited;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 246839120;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class ActionDns extends Action {
        public DnsAction[] actions;

        /**
         *
         */
        public ActionDns() {
        }

        public ActionDns(DnsAction[] actions) {
            this.actions = actions;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1193750561;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class ActionPchan extends Action {
        public PchanAction action;

        /**
         *
         */
        public ActionPchan() {
        }

        public ActionPchan(PchanAction action) {
            this.action = action;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1490172447;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class ActionRwallet extends Action {
        public RwalletActionInit action;

        /**
         *
         */
        public ActionRwallet() {
        }

        public ActionRwallet(RwalletActionInit action) {
            this.action = action;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -117295163;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class AdnlAddress extends Object {
        public String adnlAddress;

        /**
         *
         */
        public AdnlAddress() {
        }

        public AdnlAddress(String adnlAddress) {
            this.adnlAddress = adnlAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 70358284;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Bip39Hints extends Object {
        public String[] words;

        /**
         *
         */
        public Bip39Hints() {
        }

        public Bip39Hints(String[] words) {
            this.words = words;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1012243456;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Config extends Object {
        public String config;
        public String blockchainName;
        public boolean useCallbacksForNetwork;
        public boolean ignoreCache;

        /**
         *
         */
        public Config() {
        }

        public Config(String config, String blockchainName, boolean useCallbacksForNetwork, boolean ignoreCache) {
            this.config = config;
            this.blockchainName = blockchainName;
            this.useCallbacksForNetwork = useCallbacksForNetwork;
            this.ignoreCache = ignoreCache;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1538391496;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Data extends Object {
        public byte[] bytes;

        /**
         *
         */
        public Data() {
        }

        public Data(byte[] bytes) {
            this.bytes = bytes;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -414733967;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Error extends Object {
        public int code;
        public String message;

        /**
         *
         */
        public Error() {
        }

        public Error(int code, String message) {
            this.code = code;
            this.message = message;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1679978726;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class ExportedEncryptedKey extends Object {
        public byte[] data;

        /**
         *
         */
        public ExportedEncryptedKey() {
        }

        public ExportedEncryptedKey(byte[] data) {
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 2024406612;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class ExportedKey extends Object {
        public String[] wordList;

        /**
         *
         */
        public ExportedKey() {
        }

        public ExportedKey(String[] wordList) {
            this.wordList = wordList;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1449248297;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class ExportedPemKey extends Object {
        public String pem;

        /**
         *
         */
        public ExportedPemKey() {
        }

        public ExportedPemKey(String pem) {
            this.pem = pem;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1425473725;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class ExportedUnencryptedKey extends Object {
        public byte[] data;

        /**
         *
         */
        public ExportedUnencryptedKey() {
        }

        public ExportedUnencryptedKey(byte[] data) {
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 730045160;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Fees extends Object {
        public long inFwdFee;
        public long storageFee;
        public long gasFee;
        public long fwdFee;

        /**
         *
         */
        public Fees() {
        }

        public Fees(long inFwdFee, long storageFee, long gasFee, long fwdFee) {
            this.inFwdFee = inFwdFee;
            this.storageFee = storageFee;
            this.gasFee = gasFee;
            this.fwdFee = fwdFee;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1676273340;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class FullAccountState extends Object {
        public AccountAddress address;
        public long balance;
        public InternalTransactionId lastTransactionId;
        public TonBlockIdExt blockId;
        public long syncUtime;
        public AccountState accountState;
        public int revision;

        /**
         *
         */
        public FullAccountState() {
        }

        public FullAccountState(AccountAddress address, long balance, InternalTransactionId lastTransactionId, TonBlockIdExt blockId, long syncUtime, AccountState accountState, int revision) {
            this.address = address;
            this.balance = balance;
            this.lastTransactionId = lastTransactionId;
            this.blockId = blockId;
            this.syncUtime = syncUtime;
            this.accountState = accountState;
            this.revision = revision;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1456618057;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class InitialAccountState extends Object {
    }

    public static class RawInitialAccountState extends InitialAccountState {
        public byte[] code;
        public byte[] data;

        /**
         *
         */
        public RawInitialAccountState() {
        }

        public RawInitialAccountState(byte[] code, byte[] data) {
            this.code = code;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -337945529;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TestGiverInitialAccountState extends InitialAccountState {

        /**
         *
         */
        public TestGiverInitialAccountState() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1448412176;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TestWalletInitialAccountState extends InitialAccountState {
        public String publicKey;

        /**
         *
         */
        public TestWalletInitialAccountState() {
        }

        public TestWalletInitialAccountState(String publicKey) {
            this.publicKey = publicKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 819380068;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletInitialAccountState extends InitialAccountState {
        public String publicKey;

        /**
         *
         */
        public WalletInitialAccountState() {
        }

        public WalletInitialAccountState(String publicKey) {
            this.publicKey = publicKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1122166790;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletV3InitialAccountState extends InitialAccountState {
        public String publicKey;
        public long walletId;

        /**
         *
         */
        public WalletV3InitialAccountState() {
        }

        public WalletV3InitialAccountState(String publicKey, long walletId) {
            this.publicKey = publicKey;
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -118074048;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletHighloadV1InitialAccountState extends InitialAccountState {
        public String publicKey;
        public long walletId;

        /**
         *
         */
        public WalletHighloadV1InitialAccountState() {
        }

        public WalletHighloadV1InitialAccountState(String publicKey, long walletId) {
            this.publicKey = publicKey;
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -327901626;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class WalletHighloadV2InitialAccountState extends InitialAccountState {
        public String publicKey;
        public long walletId;

        /**
         *
         */
        public WalletHighloadV2InitialAccountState() {
        }

        public WalletHighloadV2InitialAccountState(String publicKey, long walletId) {
            this.publicKey = publicKey;
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1966373161;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class RwalletInitialAccountState extends InitialAccountState {
        public String initPublicKey;
        public String publicKey;
        public long walletId;

        /**
         *
         */
        public RwalletInitialAccountState() {
        }

        public RwalletInitialAccountState(String initPublicKey, String publicKey, long walletId) {
            this.initPublicKey = initPublicKey;
            this.publicKey = publicKey;
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1169755156;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsInitialAccountState extends InitialAccountState {
        public String publicKey;
        public long walletId;

        /**
         *
         */
        public DnsInitialAccountState() {
        }

        public DnsInitialAccountState(String publicKey, long walletId) {
            this.publicKey = publicKey;
            this.walletId = walletId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1842062527;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class PchanInitialAccountState extends InitialAccountState {
        public PchanConfig config;

        /**
         *
         */
        public PchanInitialAccountState() {
        }

        public PchanInitialAccountState(PchanConfig config) {
            this.config = config;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1304552124;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class InputKey extends Object {
    }

    public static class InputKeyRegular extends InputKey {
        public Key key;
        public byte[] localPassword;

        /**
         *
         */
        public InputKeyRegular() {
        }

        public InputKeyRegular(Key key, byte[] localPassword) {
            this.key = key;
            this.localPassword = localPassword;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -555399522;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class InputKeyFake extends InputKey {

        /**
         *
         */
        public InputKeyFake() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1074054722;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Key extends Object {
        public String publicKey;
        public byte[] secret;

        /**
         *
         */
        public Key() {
        }

        public Key(String publicKey, byte[] secret) {
            this.publicKey = publicKey;
            this.secret = secret;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1978362923;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class KeyStoreType extends Object {
    }

    public static class KeyStoreTypeDirectory extends KeyStoreType {
        public String directory;

        /**
         *
         */
        public KeyStoreTypeDirectory() {
        }

        public KeyStoreTypeDirectory(String directory) {
            this.directory = directory;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -378990038;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class KeyStoreTypeInMemory extends KeyStoreType {

        /**
         *
         */
        public KeyStoreTypeInMemory() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2106848825;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * This class is an abstract base class.
     * Describes a stream to which tonlib internal log is written.
     */
    public abstract static class LogStream extends Object {
    }

    /**
     * The log is written to stderr or an OS specific log.
     */
    public static class LogStreamDefault extends LogStream {

        /**
         * The log is written to stderr or an OS specific log.
         */
        public LogStreamDefault() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1390581436;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * The log is written to a file.
     */
    public static class LogStreamFile extends LogStream {
        /**
         * Path to the file to where the internal tonlib log will be written.
         */
        public String path;
        /**
         * Maximum size of the file to where the internal tonlib log is written before the file will be auto-rotated.
         */
        public long maxFileSize;

        /**
         * The log is written to a file.
         */
        public LogStreamFile() {
        }

        /**
         * The log is written to a file.
         *
         * @param path Path to the file to where the internal tonlib log will be written.
         * @param maxFileSize Maximum size of the file to where the internal tonlib log is written before the file will be auto-rotated.
         */
        public LogStreamFile(String path, long maxFileSize) {
            this.path = path;
            this.maxFileSize = maxFileSize;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1880085930;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * The log is written nowhere.
     */
    public static class LogStreamEmpty extends LogStream {

        /**
         * The log is written nowhere.
         */
        public LogStreamEmpty() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -499912244;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Contains a list of available tonlib internal log tags.
     */
    public static class LogTags extends Object {
        /**
         * List of log tags.
         */
        public String[] tags;

        /**
         * Contains a list of available tonlib internal log tags.
         */
        public LogTags() {
        }

        /**
         * Contains a list of available tonlib internal log tags.
         *
         * @param tags List of log tags.
         */
        public LogTags(String[] tags) {
            this.tags = tags;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1604930601;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Contains a tonlib internal log verbosity level.
     */
    public static class LogVerbosityLevel extends Object {
        /**
         * Log verbosity level.
         */
        public int verbosityLevel;

        /**
         * Contains a tonlib internal log verbosity level.
         */
        public LogVerbosityLevel() {
        }

        /**
         * Contains a tonlib internal log verbosity level.
         *
         * @param verbosityLevel Log verbosity level.
         */
        public LogVerbosityLevel(int verbosityLevel) {
            this.verbosityLevel = verbosityLevel;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1734624234;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Ok extends Object {

        /**
         *
         */
        public Ok() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -722616727;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class Options extends Object {
        public Config config;
        public KeyStoreType keystoreType;

        /**
         *
         */
        public Options() {
        }

        public Options(Config config, KeyStoreType keystoreType) {
            this.config = config;
            this.keystoreType = keystoreType;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1924388359;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class SyncState extends Object {
    }

    public static class SyncStateDone extends SyncState {

        /**
         *
         */
        public SyncStateDone() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1408448777;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class SyncStateInProgress extends SyncState {
        public int fromSeqno;
        public int toSeqno;
        public int currentSeqno;

        /**
         *
         */
        public SyncStateInProgress() {
        }

        public SyncStateInProgress(int fromSeqno, int toSeqno, int currentSeqno) {
            this.fromSeqno = fromSeqno;
            this.toSeqno = toSeqno;
            this.currentSeqno = currentSeqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 107726023;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class UnpackedAccountAddress extends Object {
        public int workchainId;
        public boolean bounceable;
        public boolean testnet;
        public byte[] addr;

        /**
         *
         */
        public UnpackedAccountAddress() {
        }

        public UnpackedAccountAddress(int workchainId, boolean bounceable, boolean testnet, byte[] addr) {
            this.workchainId = workchainId;
            this.bounceable = bounceable;
            this.testnet = testnet;
            this.addr = addr;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1892946998;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class Update extends Object {
    }

    public static class UpdateSendLiteServerQuery extends Update {
        public long id;
        public byte[] data;

        /**
         *
         */
        public UpdateSendLiteServerQuery() {
        }

        public UpdateSendLiteServerQuery(long id, byte[] data) {
            this.id = id;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1555130916;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class UpdateSyncState extends Update {
        public SyncState syncState;

        /**
         *
         */
        public UpdateSyncState() {
        }

        public UpdateSyncState(SyncState syncState) {
            this.syncState = syncState;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1204298718;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class DnsAction extends Object {
    }

    public static class DnsActionDeleteAll extends DnsAction {

        /**
         *
         */
        public DnsActionDeleteAll() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1067356318;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsActionDelete extends DnsAction {
        public String name;
        public int category;

        /**
         *
         */
        public DnsActionDelete() {
        }

        public DnsActionDelete(String name, int category) {
            this.name = name;
            this.category = category;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 775206882;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsActionSet extends DnsAction {
        public DnsEntry entry;

        /**
         *
         */
        public DnsActionSet() {
        }

        public DnsActionSet(DnsEntry entry) {
            this.entry = entry;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1374965309;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class DnsEntry extends Object {
        public String name;
        public int category;
        public DnsEntryData entry;

        /**
         *
         */
        public DnsEntry() {
        }

        public DnsEntry(String name, int category, DnsEntryData entry) {
            this.name = name;
            this.category = category;
            this.entry = entry;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1842435400;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class DnsEntryData extends Object {
    }

    public static class DnsEntryDataUnknown extends DnsEntryData {
        public byte[] bytes;

        /**
         *
         */
        public DnsEntryDataUnknown() {
        }

        public DnsEntryDataUnknown(byte[] bytes) {
            this.bytes = bytes;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1285893248;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsEntryDataText extends DnsEntryData {
        public String text;

        /**
         *
         */
        public DnsEntryDataText() {
        }

        public DnsEntryDataText(String text) {
            this.text = text;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -792485614;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsEntryDataNextResolver extends DnsEntryData {
        public AccountAddress resolver;

        /**
         *
         */
        public DnsEntryDataNextResolver() {
        }

        public DnsEntryDataNextResolver(AccountAddress resolver) {
            this.resolver = resolver;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 330382792;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsEntryDataSmcAddress extends DnsEntryData {
        public AccountAddress smcAddress;

        /**
         *
         */
        public DnsEntryDataSmcAddress() {
        }

        public DnsEntryDataSmcAddress(AccountAddress smcAddress) {
            this.smcAddress = smcAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1759937982;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class DnsEntryDataAdnlAddress extends DnsEntryData {
        public AdnlAddress adnlAddress;

        /**
         *
         */
        public DnsEntryDataAdnlAddress() {
        }

        public DnsEntryDataAdnlAddress(AdnlAddress adnlAddress) {
            this.adnlAddress = adnlAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1114064368;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class DnsResolved extends Object {
        public DnsEntry[] entries;

        /**
         *
         */
        public DnsResolved() {
        }

        public DnsResolved(DnsEntry[] entries) {
            this.entries = entries;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 2090272150;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TonBlockId extends Object {
        public int workchain;
        public long shard;
        public int seqno;

        /**
         *
         */
        public TonBlockId() {
        }

        public TonBlockId(int workchain, long shard, int seqno) {
            this.workchain = workchain;
            this.shard = shard;
            this.seqno = seqno;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1185382494;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class InternalTransactionId extends Object {
        public long lt;
        public byte[] hash;

        /**
         *
         */
        public InternalTransactionId() {
        }

        public InternalTransactionId(long lt, byte[] hash) {
            this.lt = lt;
            this.hash = hash;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -989527262;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class LiteServerInfo extends Object {
        public long now;
        public int version;
        public long capabilities;

        /**
         *
         */
        public LiteServerInfo() {
        }

        public LiteServerInfo(long now, int version, long capabilities) {
            this.now = now;
            this.version = version;
            this.capabilities = capabilities;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1250165133;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class MsgData extends Object {
    }

    public static class MsgDataRaw extends MsgData {
        public byte[] body;
        public byte[] initState;

        /**
         *
         */
        public MsgDataRaw() {
        }

        public MsgDataRaw(byte[] body, byte[] initState) {
            this.body = body;
            this.initState = initState;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1928962698;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class MsgDataText extends MsgData {
        public byte[] text;

        /**
         *
         */
        public MsgDataText() {
        }

        public MsgDataText(byte[] text) {
            this.text = text;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -341560688;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class MsgDataDecryptedText extends MsgData {
        public byte[] text;

        /**
         *
         */
        public MsgDataDecryptedText() {
        }

        public MsgDataDecryptedText(byte[] text) {
            this.text = text;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1289133895;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class MsgDataEncryptedText extends MsgData {
        public byte[] text;

        /**
         *
         */
        public MsgDataEncryptedText() {
        }

        public MsgDataEncryptedText(byte[] text) {
            this.text = text;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -296612902;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class MsgDataDecrypted extends Object {
        public byte[] proof;
        public MsgData data;

        /**
         *
         */
        public MsgDataDecrypted() {
        }

        public MsgDataDecrypted(byte[] proof, MsgData data) {
            this.proof = proof;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 195649769;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class MsgDataDecryptedArray extends Object {
        public MsgDataDecrypted[] elements;

        /**
         *
         */
        public MsgDataDecryptedArray() {
        }

        public MsgDataDecryptedArray(MsgDataDecrypted[] elements) {
            this.elements = elements;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -480491767;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class MsgDataEncrypted extends Object {
        public AccountAddress source;
        public MsgData data;

        /**
         *
         */
        public MsgDataEncrypted() {
        }

        public MsgDataEncrypted(AccountAddress source, MsgData data) {
            this.source = source;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 564215121;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class MsgDataEncryptedArray extends Object {
        public MsgDataEncrypted[] elements;

        /**
         *
         */
        public MsgDataEncryptedArray() {
        }

        public MsgDataEncryptedArray(MsgDataEncrypted[] elements) {
            this.elements = elements;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 608655794;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class MsgMessage extends Object {
        public AccountAddress destination;
        public String publicKey;
        public long amount;
        public MsgData data;

        /**
         *
         */
        public MsgMessage() {
        }

        public MsgMessage(AccountAddress destination, String publicKey, long amount, MsgData data) {
            this.destination = destination;
            this.publicKey = publicKey;
            this.amount = amount;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2110533580;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class OptionsConfigInfo extends Object {
        public long defaultWalletId;
        public String defaultRwalletInitPublicKey;

        /**
         *
         */
        public OptionsConfigInfo() {
        }

        public OptionsConfigInfo(long defaultWalletId, String defaultRwalletInitPublicKey) {
            this.defaultWalletId = defaultWalletId;
            this.defaultRwalletInitPublicKey = defaultRwalletInitPublicKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 129457942;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class OptionsInfo extends Object {
        public OptionsConfigInfo configInfo;

        /**
         *
         */
        public OptionsInfo() {
        }

        public OptionsInfo(OptionsConfigInfo configInfo) {
            this.configInfo = configInfo;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -64676736;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class PchanAction extends Object {
    }

    public static class PchanActionInit extends PchanAction {
        public long incA;
        public long incB;
        public long minA;
        public long minB;

        /**
         *
         */
        public PchanActionInit() {
        }

        public PchanActionInit(long incA, long incB, long minA, long minB) {
            this.incA = incA;
            this.incB = incB;
            this.minA = minA;
            this.minB = minB;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 439088778;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class PchanActionClose extends PchanAction {
        public long extraA;
        public long extraB;
        public PchanPromise promise;

        /**
         *
         */
        public PchanActionClose() {
        }

        public PchanActionClose(long extraA, long extraB, PchanPromise promise) {
            this.extraA = extraA;
            this.extraB = extraB;
            this.promise = promise;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1671187222;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class PchanActionTimeout extends PchanAction {

        /**
         *
         */
        public PchanActionTimeout() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1998487795;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class PchanConfig extends Object {
        public String alicePublicKey;
        public AccountAddress aliceAddress;
        public String bobPublicKey;
        public AccountAddress bobAddress;
        public int initTimeout;
        public int closeTimeout;
        public long channelId;

        /**
         *
         */
        public PchanConfig() {
        }

        public PchanConfig(String alicePublicKey, AccountAddress aliceAddress, String bobPublicKey, AccountAddress bobAddress, int initTimeout, int closeTimeout, long channelId) {
            this.alicePublicKey = alicePublicKey;
            this.aliceAddress = aliceAddress;
            this.bobPublicKey = bobPublicKey;
            this.bobAddress = bobAddress;
            this.initTimeout = initTimeout;
            this.closeTimeout = closeTimeout;
            this.channelId = channelId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2071530442;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class PchanPromise extends Object {
        public byte[] signature;
        public long promiseA;
        public long promiseB;
        public long channelId;

        /**
         *
         */
        public PchanPromise() {
        }

        public PchanPromise(byte[] signature, long promiseA, long promiseB, long channelId) {
            this.signature = signature;
            this.promiseA = promiseA;
            this.promiseB = promiseB;
            this.channelId = channelId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1576102819;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class PchanState extends Object {
    }

    public static class PchanStateInit extends PchanState {
        public boolean signedA;
        public boolean signedB;
        public long minA;
        public long minB;
        public long expireAt;
        public long A;
        public long B;

        /**
         *
         */
        public PchanStateInit() {
        }

        public PchanStateInit(boolean signedA, boolean signedB, long minA, long minB, long expireAt, long A, long B) {
            this.signedA = signedA;
            this.signedB = signedB;
            this.minA = minA;
            this.minB = minB;
            this.expireAt = expireAt;
            this.A = A;
            this.B = B;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1188426504;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class PchanStateClose extends PchanState {
        public boolean signedA;
        public boolean signedB;
        public long minA;
        public long minB;
        public long expireAt;
        public long A;
        public long B;

        /**
         *
         */
        public PchanStateClose() {
        }

        public PchanStateClose(boolean signedA, boolean signedB, long minA, long minB, long expireAt, long A, long B) {
            this.signedA = signedA;
            this.signedB = signedB;
            this.minA = minA;
            this.minB = minB;
            this.expireAt = expireAt;
            this.A = A;
            this.B = B;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 887226867;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class PchanStatePayout extends PchanState {
        public long A;
        public long B;

        /**
         *
         */
        public PchanStatePayout() {
        }

        public PchanStatePayout(long A, long B) {
            this.A = A;
            this.B = B;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 664671303;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class QueryFees extends Object {
        public Fees sourceFees;
        public Fees[] destinationFees;

        /**
         *
         */
        public QueryFees() {
        }

        public QueryFees(Fees sourceFees, Fees[] destinationFees) {
            this.sourceFees = sourceFees;
            this.destinationFees = destinationFees;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1614616510;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class QueryInfo extends Object {
        public long id;
        public long validUntil;
        public byte[] bodyHash;
        public byte[] body;
        public byte[] initState;

        /**
         *
         */
        public QueryInfo() {
        }

        public QueryInfo(long id, long validUntil, byte[] bodyHash, byte[] body, byte[] initState) {
            this.id = id;
            this.validUntil = validUntil;
            this.bodyHash = bodyHash;
            this.body = body;
            this.initState = initState;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1451875440;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RawFullAccountState extends Object {
        public long balance;
        public byte[] code;
        public byte[] data;
        public InternalTransactionId lastTransactionId;
        public TonBlockIdExt blockId;
        public byte[] frozenHash;
        public long syncUtime;

        /**
         *
         */
        public RawFullAccountState() {
        }

        public RawFullAccountState(long balance, byte[] code, byte[] data, InternalTransactionId lastTransactionId, TonBlockIdExt blockId, byte[] frozenHash, long syncUtime) {
            this.balance = balance;
            this.code = code;
            this.data = data;
            this.lastTransactionId = lastTransactionId;
            this.blockId = blockId;
            this.frozenHash = frozenHash;
            this.syncUtime = syncUtime;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1465398385;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RawMessage extends Object {
        public AccountAddress source;
        public AccountAddress destination;
        public long value;
        public long fwdFee;
        public long ihrFee;
        public long createdLt;
        public byte[] bodyHash;
        public MsgData msgData;

        /**
         *
         */
        public RawMessage() {
        }

        public RawMessage(AccountAddress source, AccountAddress destination, long value, long fwdFee, long ihrFee, long createdLt, byte[] bodyHash, MsgData msgData) {
            this.source = source;
            this.destination = destination;
            this.value = value;
            this.fwdFee = fwdFee;
            this.ihrFee = ihrFee;
            this.createdLt = createdLt;
            this.bodyHash = bodyHash;
            this.msgData = msgData;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1368093263;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RawTransaction extends Object {
        public long utime;
        public byte[] data;
        public InternalTransactionId transactionId;
        public long fee;
        public long storageFee;
        public long otherFee;
        public RawMessage inMsg;
        public RawMessage[] outMsgs;

        /**
         *
         */
        public RawTransaction() {
        }

        public RawTransaction(long utime, byte[] data, InternalTransactionId transactionId, long fee, long storageFee, long otherFee, RawMessage inMsg, RawMessage[] outMsgs) {
            this.utime = utime;
            this.data = data;
            this.transactionId = transactionId;
            this.fee = fee;
            this.storageFee = storageFee;
            this.otherFee = otherFee;
            this.inMsg = inMsg;
            this.outMsgs = outMsgs;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1887601793;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RawTransactions extends Object {
        public RawTransaction[] transactions;
        public InternalTransactionId previousTransactionId;

        /**
         *
         */
        public RawTransactions() {
        }

        public RawTransactions(RawTransaction[] transactions, InternalTransactionId previousTransactionId) {
            this.transactions = transactions;
            this.previousTransactionId = previousTransactionId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2063931155;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RwalletActionInit extends Object {
        public RwalletConfig config;

        /**
         *
         */
        public RwalletActionInit() {
        }

        public RwalletActionInit(RwalletConfig config) {
            this.config = config;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 624147819;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RwalletConfig extends Object {
        public long startAt;
        public RwalletLimit[] limits;

        /**
         *
         */
        public RwalletConfig() {
        }

        public RwalletConfig(long startAt, RwalletLimit[] limits) {
            this.startAt = startAt;
            this.limits = limits;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -85490534;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class RwalletLimit extends Object {
        public int seconds;
        public long value;

        /**
         *
         */
        public RwalletLimit() {
        }

        public RwalletLimit(int seconds, long value) {
            this.seconds = seconds;
            this.value = value;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1222571646;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class SmcInfo extends Object {
        public long id;

        /**
         *
         */
        public SmcInfo() {
        }

        public SmcInfo(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1134270012;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class SmcMethodId extends Object {
    }

    public static class SmcMethodIdNumber extends SmcMethodId {
        public int number;

        /**
         *
         */
        public SmcMethodIdNumber() {
        }

        public SmcMethodIdNumber(int number) {
            this.number = number;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1541162500;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class SmcMethodIdName extends SmcMethodId {
        public String name;

        /**
         *
         */
        public SmcMethodIdName() {
        }

        public SmcMethodIdName(String name) {
            this.name = name;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -249036908;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class SmcRunResult extends Object {
        public long gasUsed;
        public TvmStackEntry[] stack;
        public int exitCode;

        /**
         *
         */
        public SmcRunResult() {
        }

        public SmcRunResult(long gasUsed, TvmStackEntry[] stack, int exitCode) {
            this.gasUsed = gasUsed;
            this.stack = stack;
            this.exitCode = exitCode;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1413805043;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TonBlockIdExt extends Object {
        public int workchain;
        public long shard;
        public int seqno;
        public byte[] rootHash;
        public byte[] fileHash;

        /**
         *
         */
        public TonBlockIdExt() {
        }

        public TonBlockIdExt(int workchain, long shard, int seqno, byte[] rootHash, byte[] fileHash) {
            this.workchain = workchain;
            this.shard = shard;
            this.seqno = seqno;
            this.rootHash = rootHash;
            this.fileHash = fileHash;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 2031156378;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TvmCell extends Object {
        public byte[] bytes;

        /**
         *
         */
        public TvmCell() {
        }

        public TvmCell(byte[] bytes) {
            this.bytes = bytes;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -413424735;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TvmList extends Object {
        public TvmStackEntry[] elements;

        /**
         *
         */
        public TvmList() {
        }

        public TvmList(TvmStackEntry[] elements) {
            this.elements = elements;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1270320392;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TvmNumberDecimal extends Object {
        public String number;

        /**
         *
         */
        public TvmNumberDecimal() {
        }

        public TvmNumberDecimal(String number) {
            this.number = number;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1172477619;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TvmSlice extends Object {
        public byte[] bytes;

        /**
         *
         */
        public TvmSlice() {
        }

        public TvmSlice(byte[] bytes) {
            this.bytes = bytes;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 537299687;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public abstract static class TvmStackEntry extends Object {
    }

    public static class TvmStackEntrySlice extends TvmStackEntry {
        public TvmSlice slice;

        /**
         *
         */
        public TvmStackEntrySlice() {
        }

        public TvmStackEntrySlice(TvmSlice slice) {
            this.slice = slice;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1395485477;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TvmStackEntryCell extends TvmStackEntry {
        public TvmCell cell;

        /**
         *
         */
        public TvmStackEntryCell() {
        }

        public TvmStackEntryCell(TvmCell cell) {
            this.cell = cell;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1303473952;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TvmStackEntryNumber extends TvmStackEntry {
        public TvmNumberDecimal number;

        /**
         *
         */
        public TvmStackEntryNumber() {
        }

        public TvmStackEntryNumber(TvmNumberDecimal number) {
            this.number = number;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1358642622;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TvmStackEntryTuple extends TvmStackEntry {
        public TvmTuple tuple;

        /**
         *
         */
        public TvmStackEntryTuple() {
        }

        public TvmStackEntryTuple(TvmTuple tuple) {
            this.tuple = tuple;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -157391908;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TvmStackEntryList extends TvmStackEntry {
        public TvmList list;

        /**
         *
         */
        public TvmStackEntryList() {
        }

        public TvmStackEntryList(TvmList list) {
            this.list = list;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1186714229;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    public static class TvmStackEntryUnsupported extends TvmStackEntry {

        /**
         *
         */
        public TvmStackEntryUnsupported() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 378880498;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     */
    public static class TvmTuple extends Object {
        public TvmStackEntry[] elements;

        /**
         *
         */
        public TvmTuple() {
        }

        public TvmTuple(TvmStackEntry[] elements) {
            this.elements = elements;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1363953053;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Adds a message to tonlib internal log. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class AddLogMessage extends Function {
        /**
         * Minimum verbosity level needed for the message to be logged, 0-1023.
         */
        public int verbosityLevel;
        /**
         * Text of a message to log.
         */
        public String text;

        /**
         * Default constructor for a function, which adds a message to tonlib internal log. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public AddLogMessage() {
        }

        /**
         * Creates a function, which adds a message to tonlib internal log. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         *
         * @param verbosityLevel Minimum verbosity level needed for the message to be logged, 0-1023.
         * @param text Text of a message to log.
         */
        public AddLogMessage(int verbosityLevel, String text) {
            this.verbosityLevel = verbosityLevel;
            this.text = text;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1597427692;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Key Key} </p>
     */
    public static class ChangeLocalPassword extends Function {
        public InputKey inputKey;
        public byte[] newLocalPassword;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Key Key} </p>
         */
        public ChangeLocalPassword() {
        }

        public ChangeLocalPassword(InputKey inputKey, byte[] newLocalPassword) {
            this.inputKey = inputKey;
            this.newLocalPassword = newLocalPassword;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -401590337;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class Close extends Function {

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public Close() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1187782273;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Key Key} </p>
     */
    public static class CreateNewKey extends Function {
        public byte[] localPassword;
        public byte[] mnemonicPassword;
        public byte[] randomExtraSeed;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Key Key} </p>
         */
        public CreateNewKey() {
        }

        public CreateNewKey(byte[] localPassword, byte[] mnemonicPassword, byte[] randomExtraSeed) {
            this.localPassword = localPassword;
            this.mnemonicPassword = mnemonicPassword;
            this.randomExtraSeed = randomExtraSeed;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1861385712;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link QueryInfo QueryInfo} </p>
     */
    public static class CreateQuery extends Function {
        public InputKey privateKey;
        public AccountAddress address;
        public int timeout;
        public Action action;
        public InitialAccountState initialAccountState;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link QueryInfo QueryInfo} </p>
         */
        public CreateQuery() {
        }

        public CreateQuery(InputKey privateKey, AccountAddress address, int timeout, Action action, InitialAccountState initialAccountState) {
            this.privateKey = privateKey;
            this.address = address;
            this.timeout = timeout;
            this.action = action;
            this.initialAccountState = initialAccountState;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -242540347;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Data Data} </p>
     */
    public static class Decrypt extends Function {
        public byte[] encryptedData;
        public byte[] secret;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Data Data} </p>
         */
        public Decrypt() {
        }

        public Decrypt(byte[] encryptedData, byte[] secret) {
            this.encryptedData = encryptedData;
            this.secret = secret;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 357991854;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class DeleteAllKeys extends Function {

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public DeleteAllKeys() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1608776483;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class DeleteKey extends Function {
        public Key key;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public DeleteKey() {
        }

        public DeleteKey(Key key) {
            this.key = key;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1579595571;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link DnsResolved DnsResolved} </p>
     */
    public static class DnsResolve extends Function {
        public AccountAddress accountAddress;
        public String name;
        public int category;
        public int ttl;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link DnsResolved DnsResolved} </p>
         */
        public DnsResolve() {
        }

        public DnsResolve(AccountAddress accountAddress, String name, int category, int ttl) {
            this.accountAddress = accountAddress;
            this.name = name;
            this.category = category;
            this.ttl = ttl;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -149238065;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Data Data} </p>
     */
    public static class Encrypt extends Function {
        public byte[] decryptedData;
        public byte[] secret;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Data Data} </p>
         */
        public Encrypt() {
        }

        public Encrypt(byte[] decryptedData, byte[] secret) {
            this.decryptedData = decryptedData;
            this.secret = secret;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1821422820;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link ExportedEncryptedKey ExportedEncryptedKey} </p>
     */
    public static class ExportEncryptedKey extends Function {
        public InputKey inputKey;
        public byte[] keyPassword;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link ExportedEncryptedKey ExportedEncryptedKey} </p>
         */
        public ExportEncryptedKey() {
        }

        public ExportEncryptedKey(InputKey inputKey, byte[] keyPassword) {
            this.inputKey = inputKey;
            this.keyPassword = keyPassword;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 218237311;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link ExportedKey ExportedKey} </p>
     */
    public static class ExportKey extends Function {
        public InputKey inputKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link ExportedKey ExportedKey} </p>
         */
        public ExportKey() {
        }

        public ExportKey(InputKey inputKey) {
            this.inputKey = inputKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1622353549;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link ExportedPemKey ExportedPemKey} </p>
     */
    public static class ExportPemKey extends Function {
        public InputKey inputKey;
        public byte[] keyPassword;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link ExportedPemKey ExportedPemKey} </p>
         */
        public ExportPemKey() {
        }

        public ExportPemKey(InputKey inputKey, byte[] keyPassword) {
            this.inputKey = inputKey;
            this.keyPassword = keyPassword;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -643259462;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link ExportedUnencryptedKey ExportedUnencryptedKey} </p>
     */
    public static class ExportUnencryptedKey extends Function {
        public InputKey inputKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link ExportedUnencryptedKey ExportedUnencryptedKey} </p>
         */
        public ExportUnencryptedKey() {
        }

        public ExportUnencryptedKey(InputKey inputKey) {
            this.inputKey = inputKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -634665152;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link AccountAddress AccountAddress} </p>
     */
    public static class GetAccountAddress extends Function {
        public InitialAccountState initialAccountState;
        public int revision;
        public int workchainId;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link AccountAddress AccountAddress} </p>
         */
        public GetAccountAddress() {
        }

        public GetAccountAddress(InitialAccountState initialAccountState, int revision, int workchainId) {
            this.initialAccountState = initialAccountState;
            this.revision = revision;
            this.workchainId = workchainId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 512468424;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link FullAccountState FullAccountState} </p>
     */
    public static class GetAccountState extends Function {
        public AccountAddress accountAddress;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link FullAccountState FullAccountState} </p>
         */
        public GetAccountState() {
        }

        public GetAccountState(AccountAddress accountAddress) {
            this.accountAddress = accountAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2116357050;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Bip39Hints Bip39Hints} </p>
     */
    public static class GetBip39Hints extends Function {
        public String prefix;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Bip39Hints Bip39Hints} </p>
         */
        public GetBip39Hints() {
        }

        public GetBip39Hints(String prefix) {
            this.prefix = prefix;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1889640982;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Returns information about currently used log stream for internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link LogStream LogStream} </p>
     */
    public static class GetLogStream extends Function {

        /**
         * Default constructor for a function, which returns information about currently used log stream for internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link LogStream LogStream} </p>
         */
        public GetLogStream() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1167608667;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Returns current verbosity level for a specified tonlib internal log tag. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link LogVerbosityLevel LogVerbosityLevel} </p>
     */
    public static class GetLogTagVerbosityLevel extends Function {
        /**
         * Logging tag to change verbosity level.
         */
        public String tag;

        /**
         * Default constructor for a function, which returns current verbosity level for a specified tonlib internal log tag. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link LogVerbosityLevel LogVerbosityLevel} </p>
         */
        public GetLogTagVerbosityLevel() {
        }

        /**
         * Creates a function, which returns current verbosity level for a specified tonlib internal log tag. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link LogVerbosityLevel LogVerbosityLevel} </p>
         *
         * @param tag Logging tag to change verbosity level.
         */
        public GetLogTagVerbosityLevel(String tag) {
            this.tag = tag;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 951004547;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Returns list of available tonlib internal log tags, for example, [&quot;actor&quot;, &quot;binlog&quot;, &quot;connections&quot;, &quot;notifications&quot;, &quot;proxy&quot;]. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link LogTags LogTags} </p>
     */
    public static class GetLogTags extends Function {

        /**
         * Default constructor for a function, which returns list of available tonlib internal log tags, for example, [&quot;actor&quot;, &quot;binlog&quot;, &quot;connections&quot;, &quot;notifications&quot;, &quot;proxy&quot;]. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link LogTags LogTags} </p>
         */
        public GetLogTags() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -254449190;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Returns current verbosity level of the internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link LogVerbosityLevel LogVerbosityLevel} </p>
     */
    public static class GetLogVerbosityLevel extends Function {

        /**
         * Default constructor for a function, which returns current verbosity level of the internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link LogVerbosityLevel LogVerbosityLevel} </p>
         */
        public GetLogVerbosityLevel() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 594057956;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link AccountRevisionList AccountRevisionList} </p>
     */
    public static class GuessAccount extends Function {
        public String publicKey;
        public String rwalletInitPublicKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link AccountRevisionList AccountRevisionList} </p>
         */
        public GuessAccount() {
        }

        public GuessAccount(String publicKey, String rwalletInitPublicKey) {
            this.publicKey = publicKey;
            this.rwalletInitPublicKey = rwalletInitPublicKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1737659296;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link AccountRevisionList AccountRevisionList} </p>
     */
    public static class GuessAccountRevision extends Function {
        public InitialAccountState initialAccountState;
        public int workchainId;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link AccountRevisionList AccountRevisionList} </p>
         */
        public GuessAccountRevision() {
        }

        public GuessAccountRevision(InitialAccountState initialAccountState, int workchainId) {
            this.initialAccountState = initialAccountState;
            this.workchainId = workchainId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1857589922;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Key Key} </p>
     */
    public static class ImportEncryptedKey extends Function {
        public byte[] localPassword;
        public byte[] keyPassword;
        public ExportedEncryptedKey exportedEncryptedKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Key Key} </p>
         */
        public ImportEncryptedKey() {
        }

        public ImportEncryptedKey(byte[] localPassword, byte[] keyPassword, ExportedEncryptedKey exportedEncryptedKey) {
            this.localPassword = localPassword;
            this.keyPassword = keyPassword;
            this.exportedEncryptedKey = exportedEncryptedKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 656724958;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Key Key} </p>
     */
    public static class ImportKey extends Function {
        public byte[] localPassword;
        public byte[] mnemonicPassword;
        public ExportedKey exportedKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Key Key} </p>
         */
        public ImportKey() {
        }

        public ImportKey(byte[] localPassword, byte[] mnemonicPassword, ExportedKey exportedKey) {
            this.localPassword = localPassword;
            this.mnemonicPassword = mnemonicPassword;
            this.exportedKey = exportedKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1607900903;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Key Key} </p>
     */
    public static class ImportPemKey extends Function {
        public byte[] localPassword;
        public byte[] keyPassword;
        public ExportedPemKey exportedKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Key Key} </p>
         */
        public ImportPemKey() {
        }

        public ImportPemKey(byte[] localPassword, byte[] keyPassword, ExportedPemKey exportedKey) {
            this.localPassword = localPassword;
            this.keyPassword = keyPassword;
            this.exportedKey = exportedKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 76385617;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Key Key} </p>
     */
    public static class ImportUnencryptedKey extends Function {
        public byte[] localPassword;
        public ExportedUnencryptedKey exportedUnencryptedKey;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Key Key} </p>
         */
        public ImportUnencryptedKey() {
        }

        public ImportUnencryptedKey(byte[] localPassword, ExportedUnencryptedKey exportedUnencryptedKey) {
            this.localPassword = localPassword;
            this.exportedUnencryptedKey = exportedUnencryptedKey;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1184671467;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link OptionsInfo OptionsInfo} </p>
     */
    public static class Init extends Function {
        public Options options;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link OptionsInfo OptionsInfo} </p>
         */
        public Init() {
        }

        public Init(Options options) {
            this.options = options;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1000594762;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Data Data} </p>
     */
    public static class Kdf extends Function {
        public byte[] password;
        public byte[] salt;
        public int iterations;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Data Data} </p>
         */
        public Kdf() {
        }

        public Kdf(byte[] password, byte[] salt, int iterations) {
            this.password = password;
            this.salt = salt;
            this.iterations = iterations;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1667861635;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link LiteServerInfo LiteServerInfo} </p>
     */
    public static class LiteServerGetInfo extends Function {

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link LiteServerInfo LiteServerInfo} </p>
         */
        public LiteServerGetInfo() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1435327470;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link MsgDataDecryptedArray MsgDataDecryptedArray} </p>
     */
    public static class MsgDecrypt extends Function {
        public InputKey inputKey;
        public MsgDataEncryptedArray data;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link MsgDataDecryptedArray MsgDataDecryptedArray} </p>
         */
        public MsgDecrypt() {
        }

        public MsgDecrypt(InputKey inputKey, MsgDataEncryptedArray data) {
            this.inputKey = inputKey;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 223596297;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link MsgData MsgData} </p>
     */
    public static class MsgDecryptWithProof extends Function {
        public byte[] proof;
        public MsgDataEncrypted data;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link MsgData MsgData} </p>
         */
        public MsgDecryptWithProof() {
        }

        public MsgDecryptWithProof(byte[] proof, MsgDataEncrypted data) {
            this.proof = proof;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2111649663;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class OnLiteServerQueryError extends Function {
        public long id;
        public Error error;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public OnLiteServerQueryError() {
        }

        public OnLiteServerQueryError(long id, Error error) {
            this.id = id;
            this.error = error;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -677427533;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class OnLiteServerQueryResult extends Function {
        public long id;
        public byte[] bytes;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public OnLiteServerQueryResult() {
        }

        public OnLiteServerQueryResult(long id, byte[] bytes) {
            this.id = id;
            this.bytes = bytes;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 2056444510;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link OptionsConfigInfo OptionsConfigInfo} </p>
     */
    public static class OptionsSetConfig extends Function {
        public Config config;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link OptionsConfigInfo OptionsConfigInfo} </p>
         */
        public OptionsSetConfig() {
        }

        public OptionsSetConfig(Config config) {
            this.config = config;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1870064579;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link OptionsConfigInfo OptionsConfigInfo} </p>
     */
    public static class OptionsValidateConfig extends Function {
        public Config config;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link OptionsConfigInfo OptionsConfigInfo} </p>
         */
        public OptionsValidateConfig() {
        }

        public OptionsValidateConfig(Config config) {
            this.config = config;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -346965447;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link AccountAddress AccountAddress} </p>
     */
    public static class PackAccountAddress extends Function {
        public UnpackedAccountAddress accountAddress;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link AccountAddress AccountAddress} </p>
         */
        public PackAccountAddress() {
        }

        public PackAccountAddress(UnpackedAccountAddress accountAddress) {
            this.accountAddress = accountAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1388561940;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Data Data} </p>
     */
    public static class PchanPackPromise extends Function {
        public PchanPromise promise;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Data Data} </p>
         */
        public PchanPackPromise() {
        }

        public PchanPackPromise(PchanPromise promise) {
            this.promise = promise;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -851703103;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link PchanPromise PchanPromise} </p>
     */
    public static class PchanSignPromise extends Function {
        public InputKey inputKey;
        public PchanPromise promise;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link PchanPromise PchanPromise} </p>
         */
        public PchanSignPromise() {
        }

        public PchanSignPromise(InputKey inputKey, PchanPromise promise) {
            this.inputKey = inputKey;
            this.promise = promise;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1814322974;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link PchanPromise PchanPromise} </p>
     */
    public static class PchanUnpackPromise extends Function {
        public byte[] data;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link PchanPromise PchanPromise} </p>
         */
        public PchanUnpackPromise() {
        }

        public PchanUnpackPromise(byte[] data) {
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1250106157;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class PchanValidatePromise extends Function {
        public byte[] publicKey;
        public PchanPromise promise;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public PchanValidatePromise() {
        }

        public PchanValidatePromise(byte[] publicKey, PchanPromise promise) {
            this.publicKey = publicKey;
            this.promise = promise;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 258262242;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link QueryFees QueryFees} </p>
     */
    public static class QueryEstimateFees extends Function {
        public long id;
        public boolean ignoreChksig;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link QueryFees QueryFees} </p>
         */
        public QueryEstimateFees() {
        }

        public QueryEstimateFees(long id, boolean ignoreChksig) {
            this.id = id;
            this.ignoreChksig = ignoreChksig;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -957002175;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class QueryForget extends Function {
        public long id;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public QueryForget() {
        }

        public QueryForget(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1211985313;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link QueryInfo QueryInfo} </p>
     */
    public static class QueryGetInfo extends Function {
        public long id;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link QueryInfo QueryInfo} </p>
         */
        public QueryGetInfo() {
        }

        public QueryGetInfo(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -799333669;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class QuerySend extends Function {
        public long id;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public QuerySend() {
        }

        public QuerySend(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 925242739;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class RawCreateAndSendMessage extends Function {
        public AccountAddress destination;
        public byte[] initialAccountState;
        public byte[] data;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public RawCreateAndSendMessage() {
        }

        public RawCreateAndSendMessage(AccountAddress destination, byte[] initialAccountState, byte[] data) {
            this.destination = destination;
            this.initialAccountState = initialAccountState;
            this.data = data;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -772224603;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link QueryInfo QueryInfo} </p>
     */
    public static class RawCreateQuery extends Function {
        public AccountAddress destination;
        public byte[] initCode;
        public byte[] initData;
        public byte[] body;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link QueryInfo QueryInfo} </p>
         */
        public RawCreateQuery() {
        }

        public RawCreateQuery(AccountAddress destination, byte[] initCode, byte[] initData, byte[] body) {
            this.destination = destination;
            this.initCode = initCode;
            this.initData = initData;
            this.body = body;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1928557909;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link RawFullAccountState RawFullAccountState} </p>
     */
    public static class RawGetAccountState extends Function {
        public AccountAddress accountAddress;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link RawFullAccountState RawFullAccountState} </p>
         */
        public RawGetAccountState() {
        }

        public RawGetAccountState(AccountAddress accountAddress) {
            this.accountAddress = accountAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1327847118;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link RawTransactions RawTransactions} </p>
     */
    public static class RawGetTransactions extends Function {
        public InputKey privateKey;
        public AccountAddress accountAddress;
        public InternalTransactionId fromTransactionId;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link RawTransactions RawTransactions} </p>
         */
        public RawGetTransactions() {
        }

        public RawGetTransactions(InputKey privateKey, AccountAddress accountAddress, InternalTransactionId fromTransactionId) {
            this.privateKey = privateKey;
            this.accountAddress = accountAddress;
            this.fromTransactionId = fromTransactionId;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = 1029612317;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class RawSendMessage extends Function {
        public byte[] body;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public RawSendMessage() {
        }

        public RawSendMessage(byte[] body) {
            this.body = body;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1789427488;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class RunTests extends Function {
        public String dir;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public RunTests() {
        }

        public RunTests(String dir) {
            this.dir = dir;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2039925427;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Sets new log stream for internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class SetLogStream extends Function {
        /**
         * New log stream.
         */
        public LogStream logStream;

        /**
         * Default constructor for a function, which sets new log stream for internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public SetLogStream() {
        }

        /**
         * Creates a function, which sets new log stream for internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         *
         * @param logStream New log stream.
         */
        public SetLogStream(LogStream logStream) {
            this.logStream = logStream;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1364199535;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Sets the verbosity level for a specified tonlib internal log tag. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class SetLogTagVerbosityLevel extends Function {
        /**
         * Logging tag to change verbosity level.
         */
        public String tag;
        /**
         * New verbosity level; 1-1024.
         */
        public int newVerbosityLevel;

        /**
         * Default constructor for a function, which sets the verbosity level for a specified tonlib internal log tag. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public SetLogTagVerbosityLevel() {
        }

        /**
         * Creates a function, which sets the verbosity level for a specified tonlib internal log tag. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         *
         * @param tag Logging tag to change verbosity level.
         * @param newVerbosityLevel New verbosity level; 1-1024.
         */
        public SetLogTagVerbosityLevel(String tag, int newVerbosityLevel) {
            this.tag = tag;
            this.newVerbosityLevel = newVerbosityLevel;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2095589738;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     * Sets the verbosity level of the internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
     *
     * <p> Returns {@link Ok Ok} </p>
     */
    public static class SetLogVerbosityLevel extends Function {
        /**
         * New value of the verbosity level for logging. Value 0 corresponds to fatal errors, value 1 corresponds to errors, value 2 corresponds to warnings and debug warnings, value 3 corresponds to informational, value 4 corresponds to debug, value 5 corresponds to verbose debug, value greater than 5 and up to 1023 can be used to enable even more logging.
         */
        public int newVerbosityLevel;

        /**
         * Default constructor for a function, which sets the verbosity level of the internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         */
        public SetLogVerbosityLevel() {
        }

        /**
         * Creates a function, which sets the verbosity level of the internal logging of tonlib. This is an offline method. Can be called before authorization. Can be called synchronously.
         *
         * <p> Returns {@link Ok Ok} </p>
         *
         * @param newVerbosityLevel New value of the verbosity level for logging. Value 0 corresponds to fatal errors, value 1 corresponds to errors, value 2 corresponds to warnings and debug warnings, value 3 corresponds to informational, value 4 corresponds to debug, value 5 corresponds to verbose debug, value greater than 5 and up to 1023 can be used to enable even more logging.
         */
        public SetLogVerbosityLevel(int newVerbosityLevel) {
            this.newVerbosityLevel = newVerbosityLevel;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -303429678;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link TvmCell TvmCell} </p>
     */
    public static class SmcGetCode extends Function {
        public long id;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link TvmCell TvmCell} </p>
         */
        public SmcGetCode() {
        }

        public SmcGetCode(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -2115626088;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link TvmCell TvmCell} </p>
     */
    public static class SmcGetData extends Function {
        public long id;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link TvmCell TvmCell} </p>
         */
        public SmcGetData() {
        }

        public SmcGetData(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -427601079;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link TvmCell TvmCell} </p>
     */
    public static class SmcGetState extends Function {
        public long id;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link TvmCell TvmCell} </p>
         */
        public SmcGetState() {
        }

        public SmcGetState(long id) {
            this.id = id;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -214390293;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link SmcInfo SmcInfo} </p>
     */
    public static class SmcLoad extends Function {
        public AccountAddress accountAddress;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link SmcInfo SmcInfo} </p>
         */
        public SmcLoad() {
        }

        public SmcLoad(AccountAddress accountAddress) {
            this.accountAddress = accountAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -903491521;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link SmcRunResult SmcRunResult} </p>
     */
    public static class SmcRunGetMethod extends Function {
        public long id;
        public SmcMethodId method;
        public TvmStackEntry[] stack;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link SmcRunResult SmcRunResult} </p>
         */
        public SmcRunGetMethod() {
        }

        public SmcRunGetMethod(long id, SmcMethodId method, TvmStackEntry[] stack) {
            this.id = id;
            this.method = method;
            this.stack = stack;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -255261270;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link TonBlockIdExt TonBlockIdExt} </p>
     */
    public static class Sync extends Function {

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link TonBlockIdExt TonBlockIdExt} </p>
         */
        public Sync() {
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -1875977070;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link UnpackedAccountAddress UnpackedAccountAddress} </p>
     */
    public static class UnpackAccountAddress extends Function {
        public String accountAddress;

        /**
         * Default constructor for a function, which
         *
         * <p> Returns {@link UnpackedAccountAddress UnpackedAccountAddress} </p>
         */
        public UnpackAccountAddress() {
        }

        public UnpackAccountAddress(String accountAddress) {
            this.accountAddress = accountAddress;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -682459063;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

    /**
     *
     *
     * <p> Returns {@link Object Object} </p>
     */
    public static class WithBlock extends Function {
        public TonBlockIdExt id;
        public Function function;

        /**
         * Default constructor for a function, which 
         *
         * <p> Returns {@link Object Object} </p>
         */
        public WithBlock() {
        }

        public WithBlock(TonBlockIdExt id, Function function) {
            this.id = id;
            this.function = function;
        }

        /**
         * Identifier uniquely determining type of the object.
         */
        public static final int CONSTRUCTOR = -789093723;

        /**
         * @return this.CONSTRUCTOR
         */
        @Override
        public int getConstructor() {
            return CONSTRUCTOR;
        }
    }

}
