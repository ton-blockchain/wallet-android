/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019-2020.
 */

package org.telegram.messenger;

import android.content.Context;
import android.content.SharedPreferences;
import android.util.Base64;

public class UserConfig extends BaseController {

    public static int selectedAccount;
    public final static int MAX_ACCOUNT_COUNT = 3;

    private final Object sync = new Object();
    private boolean configLoaded;

    public String tonEncryptedData;
    public String tonPublicKey;
    public String tonAccountAddress;
    public int tonPasscodeType = -1;
    public byte[] tonPasscodeSalt;
    public long tonPasscodeRetryInMs;
    public long tonLastUptimeMillis;
    public int tonBadPasscodeTries;
    public String tonKeyName;
    public boolean tonCreationFinished;
    public int tonWalletVersion;

    private String[] walletConfig = new String[2];
    private String[] walletBlockchainName = new String[2];
    private String[] walletConfigUrl = new String[2];
    private String[] walletConfigFromUrl = new String[2];
    private int[] walletConfigType = new int[2];

    private int currentNetworkType;

    public static int NETWORK_TYPE_TEST = 0;
    public static int NETWORK_TYPE_MAIN = 1;

    private static volatile UserConfig[] Instance = new UserConfig[UserConfig.MAX_ACCOUNT_COUNT];
    public static UserConfig getInstance(int num) {
        UserConfig localInstance = Instance[num];
        if (localInstance == null) {
            synchronized (UserConfig.class) {
                localInstance = Instance[num];
                if (localInstance == null) {
                    Instance[num] = localInstance = new UserConfig(num);
                }
            }
        }
        return localInstance;
    }

    public UserConfig(int instance) {
        super(instance);
    }

    public void saveConfig(boolean all) {
        synchronized (sync) {
            try {
                SharedPreferences.Editor editor = getPreferences().edit();
                if (tonEncryptedData != null) {
                    editor.putString("tonEncryptedData", tonEncryptedData);
                    editor.putString("tonPublicKey", tonPublicKey);
                    if (tonAccountAddress != null) {
                        editor.putString("tonAccountAddress", tonAccountAddress);
                    }
                    editor.putString("tonKeyName", tonKeyName);
                    editor.putBoolean("tonCreationFinished", tonCreationFinished);
                    editor.putInt("tonWalletVersion", tonWalletVersion);
                    if (tonPasscodeSalt != null) {
                        editor.putInt("tonPasscodeType", tonPasscodeType);
                        editor.putString("tonPasscodeSalt", Base64.encodeToString(tonPasscodeSalt, Base64.DEFAULT));
                        editor.putLong("tonPasscodeRetryInMs", tonPasscodeRetryInMs);
                        editor.putLong("tonLastUptimeMillis", tonLastUptimeMillis);
                        editor.putInt("tonBadPasscodeTries", tonBadPasscodeTries);
                    }
                } else {
                    editor.remove("tonEncryptedData").remove("tonPublicKey").remove("tonKeyName").remove("tonPasscodeType").remove("tonPasscodeSalt").remove("tonPasscodeRetryInMs").remove("tonBadPasscodeTries").remove("tonLastUptimeMillis").remove("tonCreationFinished");
                }
                editor.putString("walletConfig", walletConfig[NETWORK_TYPE_TEST]);
                editor.putString("walletConfigUrl", walletConfigUrl[NETWORK_TYPE_TEST]);
                editor.putInt("walletConfigType", walletConfigType[NETWORK_TYPE_TEST]);
                editor.putString("walletBlockchainName", walletBlockchainName[NETWORK_TYPE_TEST]);
                editor.putString("walletConfigFromUrl", walletConfigFromUrl[NETWORK_TYPE_TEST]);

                editor.putString("walletConfigMain", walletConfig[NETWORK_TYPE_MAIN]);
                editor.putString("walletConfigUrlMain", walletConfigUrl[NETWORK_TYPE_MAIN]);
                editor.putInt("walletConfigTypeMain", walletConfigType[NETWORK_TYPE_MAIN]);
                editor.putString("walletBlockchainNameMain", walletBlockchainName[NETWORK_TYPE_MAIN]);
                editor.putString("walletConfigFromUrlMain", walletConfigFromUrl[NETWORK_TYPE_MAIN]);

                editor.putInt("walletCurrentNetworkType", currentNetworkType);

                editor.commit();
            } catch (Exception e) {
                FileLog.e(e);
            }
        }
    }

    public void loadConfig() {
        synchronized (sync) {
            if (configLoaded) {
                return;
            }
            SharedPreferences preferences = getPreferences();
            tonEncryptedData = preferences.getString("tonEncryptedData", null);
            tonPublicKey = preferences.getString("tonPublicKey", null);
            tonAccountAddress = preferences.getString("tonAccountAddress", null);
            tonKeyName = preferences.getString("tonKeyName", "walletKey");
            tonCreationFinished = preferences.getBoolean("tonCreationFinished", true);
            tonWalletVersion = preferences.getInt("tonWalletVersion", 0);
            String salt = preferences.getString("tonPasscodeSalt", null);
            if (salt != null) {
                try {
                    tonPasscodeSalt = Base64.decode(salt, Base64.DEFAULT);
                    tonPasscodeType = preferences.getInt("tonPasscodeType", -1);
                    tonPasscodeRetryInMs = preferences.getLong("tonPasscodeRetryInMs", 0);
                    tonLastUptimeMillis = preferences.getLong("tonLastUptimeMillis", 0);
                    tonBadPasscodeTries = preferences.getInt("tonBadPasscodeTries", 0);
                } catch (Exception e) {
                    FileLog.e(e);
                }
            }
            walletConfig[NETWORK_TYPE_TEST] = preferences.getString("walletConfig", "");
            walletConfigUrl[NETWORK_TYPE_TEST] = preferences.getString("walletConfigUrl", "https://ton.org/global-config-wallet.json");
            walletConfigType[NETWORK_TYPE_TEST] = preferences.getInt("walletConfigType", TonController.CONFIG_TYPE_URL);
            walletBlockchainName[NETWORK_TYPE_TEST] = preferences.getString("walletBlockchainName", "mainnet");
            walletConfigFromUrl[NETWORK_TYPE_TEST] = preferences.getString("walletConfigFromUrl", "");

            walletConfig[NETWORK_TYPE_MAIN] = preferences.getString("walletConfigMain", "");
            walletConfigUrl[NETWORK_TYPE_MAIN] = preferences.getString("walletConfigUrlMain", "https://ton.org/config.json");
            walletConfigType[NETWORK_TYPE_MAIN] = preferences.getInt("walletConfigTypeMain", TonController.CONFIG_TYPE_URL);
            walletBlockchainName[NETWORK_TYPE_MAIN] = preferences.getString("walletBlockchainNameMain", "mainnet");
            walletConfigFromUrl[NETWORK_TYPE_MAIN] = preferences.getString("walletConfigFromUrlMain", "");

            currentNetworkType = preferences.getInt("walletCurrentNetworkType", NETWORK_TYPE_TEST);

            configLoaded = true;
        }
    }

    public String getWalletConfig() {
        return walletConfig[currentNetworkType];
    }

    public String getWalletConfig(int type) {
        return walletConfig[type];
    }


    public void setWalletConfig(int type, String config) {
        walletConfig[type] = config;
    }

    public String getWalletConfigUrl() {
        return walletConfigUrl[currentNetworkType];
    }

    public String getWalletConfigUrl(int type) {
        return walletConfigUrl[type];
    }

    public void setWalletConfigUrl(int type, String url) {
        walletConfigUrl[type] = url;
    }

    public int getWalletConfigType() {
        return walletConfigType[currentNetworkType];
    }

    public int getWalletConfigType(int type) {
        return walletConfigType[type];
    }

    public void setWalletConfigType(int type, int value) {
        walletConfigType[type] = value;
    }

    public String getWalletBlockchainName() {
        return walletBlockchainName[currentNetworkType];
    }

    public String getWalletBlockchainName(int type) {
        return walletBlockchainName[type];
    }

    public void setWalletBlockchainName(int type, String name) {
        walletBlockchainName[type] = name;
    }

    public String getWalletConfigFromUrl() {
        return walletConfigFromUrl[currentNetworkType];
    }

    public String getWalletConfigFromUrl(int type) {
        return walletConfigFromUrl[type];
    }

    public void setWalletConfigFromUrl(int type, String config) {
        walletConfigFromUrl[type] = config;
    }

    public int getCurrentNetworkType() {
        return currentNetworkType;
    }

    public void setCurrentNetworkType(int type) {
        currentNetworkType = type;
    }

    private SharedPreferences getPreferences() {
        return ApplicationLoader.applicationContext.getSharedPreferences("userconfig", Context.MODE_PRIVATE);
    }

    public void clearTonConfig() {
        tonEncryptedData = null;
        tonKeyName = null;
        tonPublicKey = null;
        tonPasscodeType = -1;
        tonPasscodeSalt = null;
        tonCreationFinished = false;
        tonAccountAddress = null;
        tonWalletVersion = 1;
        tonPasscodeRetryInMs = 0;
        tonLastUptimeMillis = 0;
        tonBadPasscodeTries = 0;
    }

    public void clearConfig() {
        getPreferences().edit().clear().commit();
        clearTonConfig();
        saveConfig(true);
    }
}
