/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019-2020.
 */

package org.telegram.ui.Wallet;

import android.text.TextUtils;

import java.util.HashMap;

import drinkless.org.ton.TonApi;

public class WalletTransaction {

    public TonApi.RawTransaction rawTransaction;
    public HashMap<TonApi.MsgData, String> decryptedMessages = new HashMap<>();
    public boolean isEmpty;
    public boolean isInit;
    public boolean isOut;

    public WalletTransaction(TonApi.RawTransaction transaction) {
        rawTransaction = transaction;
        isEmpty = isEmptyTransaction(transaction);
    }

    public String getDecryptedMessage(TonApi.MsgData msgData) {
        return decryptedMessages.get(msgData);
    }

    public void putDecryptedMessage(TonApi.MsgData msgData, String text) {
        decryptedMessages.put(msgData, text);
    }

    private boolean isEmptyTransaction(TonApi.RawTransaction transaction) {
        long value = 0;
        boolean hasMessage = false;
        boolean emptySource = true;
        if (transaction.inMsg != null) {
            value += transaction.inMsg.value;
            if (!(transaction.inMsg.msgData instanceof TonApi.MsgDataRaw)) {
                hasMessage = true;
            }
            emptySource = TextUtils.isEmpty(transaction.inMsg.source.accountAddress);
        }
        if (transaction.outMsgs != null && transaction.outMsgs.length > 0) {
            for (int a = 0; a < transaction.outMsgs.length; a++) {
                value -= transaction.outMsgs[a].value;
                isOut = true;
                if (!(transaction.outMsgs[a].msgData instanceof TonApi.MsgDataRaw)) {
                    hasMessage = true;
                }
            }
        }
        return !hasMessage && emptySource && value == 0;
    }
}
