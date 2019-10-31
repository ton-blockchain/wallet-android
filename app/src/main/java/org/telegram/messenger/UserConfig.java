/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019.
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
    public int tonPasscodeType = -1;
    public byte[] tonPasscodeSalt;
    public long tonPasscodeRetryInMs;
    public long tonLastUptimeMillis;
    public int tonBadPasscodeTries;
    public String tonKeyName;
    public boolean tonCreationFinished;

    public String walletConfig;
    public String walletBlockchainName;
    public String walletConfigUrl;
    public String walletConfigFromUrl;
    public int walletConfigType;

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
                    editor.putString("tonKeyName", tonKeyName);
                    editor.putBoolean("tonCreationFinished", tonCreationFinished);
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
                editor.putString("walletConfig", walletConfig);
                editor.putString("walletConfigUrl", walletConfigUrl);
                editor.putInt("walletConfigType", walletConfigType);
                editor.putString("walletBlockchainName", walletBlockchainName);
                editor.putString("walletConfigFromUrl", walletConfigFromUrl);
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
            tonKeyName = preferences.getString("tonKeyName", "walletKey");
            tonCreationFinished = preferences.getBoolean("tonCreationFinished", true);
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
            walletConfig = preferences.getString("walletConfig", "");
            walletConfigUrl = preferences.getString("walletConfigUrl", "https://test.ton.org/config.json");
            walletConfigType = preferences.getInt("walletConfigType", TonController.CONFIG_TYPE_URL);
            walletBlockchainName = preferences.getString("walletBlockchainName", "testnet");
            walletConfigFromUrl = preferences.getString("walletConfigFromUrl", "");

            configLoaded = true;
        }
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
