/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2020.
 */

package org.telegram.ui.Wallet;

import java.util.HashMap;

import drinkless.org.ton.TonApi;

public class WalletTransaction {

    public TonApi.RawTransaction rawTransaction;
    public HashMap<TonApi.MsgData, String> decryptedMessages = new HashMap<>();

    public WalletTransaction(TonApi.RawTransaction transaction) {
        rawTransaction = transaction;
    }

    public String getDecryptedMessage(TonApi.MsgData msgData) {
        return decryptedMessages.get(msgData);
    }

    public void putDecryptedMessage(TonApi.MsgData msgData, String text) {
        decryptedMessages.put(msgData, text);
    }
}
