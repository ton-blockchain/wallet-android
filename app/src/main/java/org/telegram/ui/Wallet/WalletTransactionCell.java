/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019.
 */

package org.telegram.ui.Wallet;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffColorFilter;
import android.graphics.Typeface;
import android.text.SpannableStringBuilder;
import android.text.Spanned;
import android.text.TextUtils;
import android.util.TypedValue;
import android.view.Gravity;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import org.telegram.messenger.AndroidUtilities;
import org.telegram.messenger.FileLog;
import org.telegram.messenger.LocaleController;
import org.telegram.messenger.R;
import org.telegram.messenger.TonController;
import org.telegram.messenger.UserConfig;
import org.telegram.ui.ActionBar.Theme;
import org.telegram.ui.Components.LayoutHelper;
import org.telegram.ui.Components.TypefaceSpan;

import drinkless.org.ton.TonApi;

@SuppressWarnings("FieldCanBeLocal")
public class WalletTransactionCell extends LinearLayout {

    private TextView valueTextView;
    private ImageView gemImageView;
    private TextView fromTextView;
    private TextView dateTextView;
    private TextView addressValueTextView;
    private TextView commentTextView;
    private TextView feeTextView;
    private ImageView clockImage;
    private ImageView encryptedImageView;
    private LinearLayout addressLinearLayout;

    private boolean drawDivider;
    private Typeface defaultTypeFace;
    private long currentAmount;
    private long currentDate;
    private long currentStorageFee;
    private long currentTransactionFee;
    private boolean isEmpty;
    private WalletTransaction currentTransaction;

    private int currentAccount = UserConfig.selectedAccount;

    public WalletTransactionCell(Context context) {
        super(context);
        setOrientation(VERTICAL);

        LinearLayout linearLayout = new LinearLayout(context);
        linearLayout.setOrientation(HORIZONTAL);
        addView(linearLayout, LayoutHelper.createLinear(LayoutHelper.MATCH_PARENT, LayoutHelper.WRAP_CONTENT, 18, 0, 18, 0));

        valueTextView = new TextView(context);
        valueTextView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 16);
        defaultTypeFace = valueTextView.getTypeface();
        valueTextView.setTypeface(AndroidUtilities.getTypeface("fonts/rmedium.ttf"));
        linearLayout.addView(valueTextView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, 0, 8, 0, 0));

        gemImageView = new ImageView(context);
        gemImageView.setImageResource(R.drawable.gem_s);
        linearLayout.addView(gemImageView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, 3, 11, 0, 0));

        fromTextView = new TextView(context);
        fromTextView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 15);
        fromTextView.setTextColor(Theme.getColor(Theme.key_wallet_blackText));
        linearLayout.addView(fromTextView, LayoutHelper.createLinear(0, LayoutHelper.WRAP_CONTENT, 1.0f, 7, 8, 0, 0));

        clockImage = new ImageView(context);
        clockImage.setImageResource(R.drawable.msg_clock);
        clockImage.setColorFilter(new PorterDuffColorFilter(Theme.getColor(Theme.key_wallet_dateText), PorterDuff.Mode.MULTIPLY));
        linearLayout.addView(clockImage, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, Gravity.RIGHT | Gravity.TOP, 0, 14, 4, 0));

        dateTextView = new TextView(context);
        dateTextView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 14);
        dateTextView.setTextColor(Theme.getColor(Theme.key_wallet_dateText));
        linearLayout.addView(dateTextView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, Gravity.RIGHT | Gravity.TOP, 0, 8, 0, 0));

        addressLinearLayout = new LinearLayout(context);
        addressLinearLayout.setOrientation(HORIZONTAL);
        addView(addressLinearLayout, LayoutHelper.createLinear(LayoutHelper.MATCH_PARENT, LayoutHelper.WRAP_CONTENT, 18, 6, 16, 6));

        addressValueTextView = new TextView(context);
        addressValueTextView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 15);
        addressValueTextView.setTypeface(AndroidUtilities.getTypeface("fonts/rmono.ttf"));
        addressValueTextView.setTextColor(Theme.getColor(Theme.key_wallet_blackText));
        addressLinearLayout.addView(addressValueTextView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, 1.0f, Gravity.LEFT | Gravity.TOP));

        encryptedImageView = new ImageView(context);
        encryptedImageView.setImageResource(R.drawable.wallet_lock);
        encryptedImageView.setColorFilter(new PorterDuffColorFilter(Theme.getColor(Theme.key_wallet_dateText), PorterDuff.Mode.MULTIPLY));
        addressLinearLayout.addView(encryptedImageView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, Gravity.RIGHT | Gravity.CENTER_VERTICAL));

        commentTextView = new TextView(context);
        commentTextView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 14);
        commentTextView.setTextColor(Theme.getColor(Theme.key_wallet_commentText));
        addView(commentTextView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, 18, 0, 18, 9));

        feeTextView = new TextView(context);
        feeTextView.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 14);
        feeTextView.setTextColor(Theme.getColor(Theme.key_wallet_commentText));
        addView(feeTextView, LayoutHelper.createLinear(LayoutHelper.WRAP_CONTENT, LayoutHelper.WRAP_CONTENT, 18, 0, 18, 9));
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(MeasureSpec.makeMeasureSpec(MeasureSpec.getSize(widthMeasureSpec), MeasureSpec.EXACTLY), MeasureSpec.makeMeasureSpec(0, MeasureSpec.UNSPECIFIED));
    }
    
    private String getMessageText(WalletTransaction walletTransaction, TonApi.AccountAddress accountAddress, TonApi.MsgData messageData) {
        try {
            if (messageData instanceof TonApi.MsgDataRaw) {
                return null;
            } else if (messageData instanceof TonApi.MsgDataText) {
                TonApi.MsgDataText msgData = (TonApi.MsgDataText) messageData;
                if (encryptedImageView.getVisibility() != INVISIBLE) {
                    encryptedImageView.setVisibility(INVISIBLE);
                }
                return new String(msgData.text, 0, msgData.text.length, "UTF-8");
            } else if (messageData instanceof TonApi.MsgDataDecryptedText) {
                TonApi.MsgDataDecryptedText msgData = (TonApi.MsgDataDecryptedText) messageData;
                if (encryptedImageView.getVisibility() != VISIBLE) {
                    encryptedImageView.setVisibility(VISIBLE);
                }
                return new String(msgData.text, 0, msgData.text.length, "UTF-8");
            } else if (messageData instanceof TonApi.MsgDataEncryptedText) {
                String text = walletTransaction.getDecryptedMessage(messageData);
                if (text == null) {
                    TonController.getInstance(currentAccount).decryptMessage(messageData, accountAddress, (msgData, comment) -> {
                        walletTransaction.putDecryptedMessage(msgData, comment);
                        updateRowWithTransaction(walletTransaction);
                    });
                }
                if (encryptedImageView.getVisibility() != VISIBLE) {
                    encryptedImageView.setVisibility(VISIBLE);
                }
                return text != null ? text : LocaleController.getString("WalletEncryptedMessage", R.string.WalletEncryptedMessage);
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
        return null;
    }

    public WalletTransaction getCurrentTransaction() {
        return currentTransaction;
    }

    protected void updateRowWithTransaction(WalletTransaction transaction) {

    }

    public void setTransaction(WalletTransaction walletTransaction, boolean divider) {
        currentTransaction = walletTransaction;
        encryptedImageView.setVisibility(INVISIBLE);
        TonApi.RawTransaction transaction = walletTransaction.rawTransaction;
        StringBuilder builder;
        long value = 0;
        String message = null;
        if (transaction.inMsg != null) {
            value += transaction.inMsg.value;
            message = getMessageText(walletTransaction, transaction.inMsg.source, transaction.inMsg.msgData);
        }
        if (transaction.outMsgs != null && transaction.outMsgs.length > 0) {
            for (int a = 0; a < transaction.outMsgs.length; a++) {
                value -= transaction.outMsgs[a].value;
                if (TextUtils.isEmpty(message)) {
                    message = getMessageText(walletTransaction, transaction.outMsgs[a].source, transaction.outMsgs[a].msgData);
                }
            }
        }
        clockImage.setVisibility(GONE);
        CharSequence text;
        isEmpty = false;
        boolean isPending = false;
        if (value > 0) {
            builder = new StringBuilder(transaction.inMsg.source.accountAddress);
            valueTextView.setTextColor(Theme.getColor(Theme.key_wallet_greenText));
            fromTextView.setText(LocaleController.getString("WalletFrom", R.string.WalletFrom));
            text = String.format("+%s", TonController.formatCurrency(value));
        } else {
            if (transaction.transactionId.lt == 0) {
                builder = new StringBuilder(transaction.inMsg.destination.accountAddress);
                fromTextView.setText(LocaleController.getString("WalletTo", R.string.WalletTo));
                clockImage.setVisibility(VISIBLE);
                isPending = true;
            } else if (transaction.outMsgs != null && transaction.outMsgs.length > 0) {
                builder = new StringBuilder(transaction.outMsgs[0].destination.accountAddress);
                fromTextView.setText(LocaleController.getString("WalletTo", R.string.WalletTo));
            } else {
                //builder = new StringBuilder(LocaleController.getString("WalletProcessingFee", R.string.WalletProcessingFee));
                builder = new StringBuilder("");
                isEmpty = true;
                fromTextView.setText("");
            }
            valueTextView.setTextColor(Theme.getColor(Theme.key_wallet_redText));
            text = String.format("%s", TonController.formatCurrency(value));
        }
        currentAmount = value;
        currentDate = transaction.utime;
        int index = TextUtils.indexOf(text, '.');
        if (index >= 0) {
            SpannableStringBuilder spannableStringBuilder = new SpannableStringBuilder(text);
            spannableStringBuilder.setSpan(new TypefaceSpan(defaultTypeFace, AndroidUtilities.dp(14)), index + 1, text.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
            text = spannableStringBuilder;
        }
        valueTextView.setText(text);
        dateTextView.setText(LocaleController.getInstance().formatterDay.format(transaction.utime * 1000));
        if (!isEmpty && builder != null) {
            builder.insert(builder.length() / 2, '\n');
        }
        addressValueTextView.setText(builder);

        if (isPending) {
            currentStorageFee = 0;
            currentTransactionFee = 0;
        } else {
            currentStorageFee = transaction.storageFee;
            currentTransactionFee = transaction.otherFee;
        }

        if (currentStorageFee != 0 || currentTransactionFee != 0) {
            feeTextView.setText(LocaleController.formatString("WalletBlockchainFees", R.string.WalletBlockchainFees, TonController.formatCurrency(-currentStorageFee - currentTransactionFee)));
            feeTextView.setVisibility(VISIBLE);
        } else {
            feeTextView.setVisibility(GONE);
        }

        if (!TextUtils.isEmpty(message)) {
            commentTextView.setText(message);
            commentTextView.setVisibility(VISIBLE);
        } else {
            commentTextView.setVisibility(GONE);
        }

        LinearLayout.LayoutParams layoutParams = (LinearLayout.LayoutParams) addressLinearLayout.getLayoutParams();
        if (commentTextView.getVisibility() == VISIBLE || feeTextView.getVisibility() == VISIBLE) {
            layoutParams.bottomMargin = AndroidUtilities.dp(1);
        } else {
            layoutParams.bottomMargin = AndroidUtilities.dp(10);
        }

        if (commentTextView.getVisibility() == VISIBLE) {
            layoutParams = (LinearLayout.LayoutParams) commentTextView.getLayoutParams();
            if (feeTextView.getVisibility() == VISIBLE) {
                layoutParams.bottomMargin = AndroidUtilities.dp(3);
            } else {
                layoutParams.bottomMargin = AndroidUtilities.dp(9);
            }
        }

        drawDivider = divider;
        setWillNotDraw(!divider);
    }

    public String getAddress() {
        return addressValueTextView.getText().toString();
    }

    public String getComment() {
        return commentTextView.getVisibility() == VISIBLE ? commentTextView.getText().toString() : "";
    }

    public long getAmount() {
        return currentAmount;
    }

    public long getDate() {
        return currentDate;
    }

    public boolean isEmpty() {
        return isEmpty;
    }

    public long getStorageFee() {
        return currentStorageFee;
    }

    public long getTransactionFee() {
        return currentTransactionFee;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        if (drawDivider) {
            canvas.drawLine(AndroidUtilities.dp(17), getMeasuredHeight() - 1, getMeasuredWidth(), getMeasuredHeight() - 1, Theme.dividerPaint);
        }
    }
}
