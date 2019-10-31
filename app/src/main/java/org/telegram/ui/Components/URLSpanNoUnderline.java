/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019.
 */

package org.telegram.ui.Components;

import android.net.Uri;
import android.text.TextPaint;
import android.text.style.URLSpan;
import android.view.View;

import org.telegram.messenger.browser.Browser;

public class URLSpanNoUnderline extends URLSpan {

    public URLSpanNoUnderline(String url) {
        super(url);
    }

    @Override
    public void onClick(View widget) {
        String url = getURL();
        if (url.startsWith("@")) {
            Uri uri = Uri.parse("https://t.me/" + url.substring(1));
            Browser.openUrl(widget.getContext(), uri);
        } else {
            Browser.openUrl(widget.getContext(), url);
        }
    }

    @Override
    public void updateDrawState(TextPaint p) {
        super.updateDrawState(p);
        p.setUnderlineText(false);
    }
}
