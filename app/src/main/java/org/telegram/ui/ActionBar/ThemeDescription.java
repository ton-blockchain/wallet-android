/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019.
 */

package org.telegram.ui.ActionBar;

import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffColorFilter;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.graphics.drawable.RippleDrawable;
import android.graphics.drawable.ShapeDrawable;
import android.graphics.drawable.StateListDrawable;
import android.os.Build;
import android.text.SpannedString;
import android.text.TextPaint;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ScrollView;
import android.widget.TextView;

import org.telegram.messenger.AndroidUtilities;
import org.telegram.messenger.FileLog;
import org.telegram.ui.Components.CombinedDrawable;
import org.telegram.ui.Components.EditTextBoldCursor;
import org.telegram.ui.Components.LineProgressView;
import org.telegram.ui.Components.RLottieDrawable;
import org.telegram.ui.Components.RLottieImageView;
import org.telegram.ui.Components.RadialProgressView;
import org.telegram.ui.Components.RecyclerListView;
import org.telegram.ui.Components.TypefaceSpan;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.HashMap;

public class ThemeDescription {

    public static int FLAG_BACKGROUND                   = 0x00000001;
    public static int FLAG_LINKCOLOR                    = 0x00000002;
    public static int FLAG_TEXTCOLOR                    = 0x00000004;
    public static int FLAG_IMAGECOLOR                   = 0x00000008;
    public static int FLAG_CELLBACKGROUNDCOLOR          = 0x00000010;
    public static int FLAG_BACKGROUNDFILTER             = 0x00000020;
    public static int FLAG_AB_ITEMSCOLOR                = 0x00000040;
    public static int FLAG_AB_TITLECOLOR                = 0x00000080;
    public static int FLAG_AB_SELECTORCOLOR             = 0x00000100;
    public static int FLAG_AB_AM_ITEMSCOLOR             = 0x00000200;
    public static int FLAG_AB_SUBTITLECOLOR             = 0x00000400;
    public static int FLAG_PROGRESSBAR                  = 0x00000800;
    public static int FLAG_SELECTOR                     = 0x00001000;
    public static int FLAG_CHECKBOX                     = 0x00002000;
    public static int FLAG_CHECKBOXCHECK                = 0x00004000;
    public static int FLAG_LISTGLOWCOLOR                = 0x00008000;
    public static int FLAG_DRAWABLESELECTEDSTATE        = 0x00010000;
    public static int FLAG_USEBACKGROUNDDRAWABLE        = 0x00020000;
    public static int FLAG_CHECKTAG                     = 0x00040000;
    public static int FLAG_SECTIONS                     = 0x00080000;
    public static int FLAG_AB_AM_BACKGROUND             = 0x00100000;
    public static int FLAG_AB_AM_TOPBACKGROUND          = 0x00200000;
    public static int FLAG_AB_AM_SELECTORCOLOR          = 0x00400000;
    public static int FLAG_HINTTEXTCOLOR                = 0x00800000;
    public static int FLAG_CURSORCOLOR                  = 0x01000000;
    public static int FLAG_FASTSCROLL                   = 0x02000000;
    public static int FLAG_AB_SEARCHPLACEHOLDER         = 0x04000000;
    public static int FLAG_AB_SEARCH                    = 0x08000000;
    public static int FLAG_SELECTORWHITE                = 0x10000000;
    public static int FLAG_SERVICEBACKGROUND            = 0x20000000;
    public static int FLAG_AB_SUBMENUITEM               = 0x40000000;
    public static int FLAG_AB_SUBMENUBACKGROUND         = 0x80000000;

    private View viewToInvalidate;
    private int alphaOverride = -1;
    private Paint[] paintToUpdate;
    private Drawable[] drawablesToUpdate;
    private Class[] listClasses;
    private String currentKey;
    private String lottieLayerName;
    private ThemeDescriptionDelegate delegate;
    private int previousColor;
    private int defaultColor;
    private int currentColor;
    private int changeFlags;
    private String[] listClassesFieldName;

    private HashMap<String, Field> cachedFields;
    private HashMap<String, Boolean> notFoundCachedFields;

    public interface ThemeDescriptionDelegate {
        void didSetColor();
    }

    public ThemeDescription(View view, int flags, Class[] classes, Paint[] paint, Drawable[] drawables, ThemeDescriptionDelegate themeDescriptionDelegate, String key, Object unused) {
        currentKey = key;
        paintToUpdate = paint;
        drawablesToUpdate = drawables;
        viewToInvalidate = view;
        changeFlags = flags;
        listClasses = classes;
        delegate = themeDescriptionDelegate;
    }

    public ThemeDescription(View view, int flags, Class[] classes, Paint paint, Drawable[] drawables, ThemeDescriptionDelegate themeDescriptionDelegate, String key) {
        currentKey = key;
        if (paint != null) {
            paintToUpdate = new Paint[]{paint};
        }
        drawablesToUpdate = drawables;
        viewToInvalidate = view;
        changeFlags = flags;
        listClasses = classes;
        delegate = themeDescriptionDelegate;
    }

    public ThemeDescription(View view, int flags, Class[] classes, RLottieDrawable[] drawables, String layerName, String key) {
        currentKey = key;
        lottieLayerName = layerName;
        drawablesToUpdate = drawables;
        viewToInvalidate = view;
        changeFlags = flags;
        listClasses = classes;
    }

    public ThemeDescription(View view, int flags, Class[] classes, String[] classesFields, Paint[] paint, Drawable[] drawables, ThemeDescriptionDelegate themeDescriptionDelegate, String key) {
        this(view, flags, classes, classesFields, paint, drawables, -1, themeDescriptionDelegate, key);
    }

    public ThemeDescription(View view, int flags, Class[] classes, String[] classesFields, Paint[] paint, Drawable[] drawables, int alpha, ThemeDescriptionDelegate themeDescriptionDelegate, String key) {
        currentKey = key;
        paintToUpdate = paint;
        drawablesToUpdate = drawables;
        viewToInvalidate = view;
        changeFlags = flags;
        listClasses = classes;
        listClassesFieldName = classesFields;
        alphaOverride = alpha;
        delegate = themeDescriptionDelegate;
        cachedFields = new HashMap<>();
        notFoundCachedFields = new HashMap<>();
    }

    public ThemeDescription(View view, int flags, Class[] classes, String[] classesFields, String layerName, String key) {
        currentKey = key;
        lottieLayerName = layerName;
        viewToInvalidate = view;
        changeFlags = flags;
        listClasses = classes;
        listClassesFieldName = classesFields;
        cachedFields = new HashMap<>();
        notFoundCachedFields = new HashMap<>();
    }

    public ThemeDescriptionDelegate setDelegateDisabled() {
        ThemeDescriptionDelegate oldDelegate = delegate;
        delegate = null;
        return oldDelegate;
    }

    public void setColor(int color, boolean useDefault) {
        setColor(color, useDefault, true);
    }

    private boolean checkTag(String key, View view) {
        if (key == null || view == null) {
            return false;
        }
        Object viewTag = view.getTag();
        if (viewTag instanceof String) {
            return ((String) viewTag).contains(key);
        }
        return false;
    }

    public void setColor(int color, boolean useDefault, boolean save) {
        currentColor = color;
        if (alphaOverride > 0) {
            color = Color.argb(alphaOverride, Color.red(color), Color.green(color), Color.blue(color));
        }
        if (paintToUpdate != null) {
            for (int a = 0; a < paintToUpdate.length; a++) {
                if ((changeFlags & FLAG_LINKCOLOR) != 0 && paintToUpdate[a] instanceof TextPaint) {
                    ((TextPaint) paintToUpdate[a]).linkColor = color;
                } else {
                    paintToUpdate[a].setColor(color);
                }
            }
        }
        if (drawablesToUpdate != null) {
            for (int a = 0; a < drawablesToUpdate.length; a++) {
                if (drawablesToUpdate[a] == null) {
                    continue;
                }
                if (drawablesToUpdate[a] instanceof RLottieDrawable) {
                    if (lottieLayerName != null) {
                        ((RLottieDrawable) drawablesToUpdate[a]).setLayerColor(lottieLayerName + ".**", color);
                    }
                } else if (drawablesToUpdate[a] instanceof CombinedDrawable) {
                    if ((changeFlags & FLAG_BACKGROUNDFILTER) != 0) {
                        ((CombinedDrawable) drawablesToUpdate[a]).getBackground().setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                    } else {
                        ((CombinedDrawable) drawablesToUpdate[a]).getIcon().setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                    }
                } else {
                    drawablesToUpdate[a].setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                }
            }
        }
        if (viewToInvalidate != null && listClasses == null && listClassesFieldName == null) {
            if ((changeFlags & FLAG_CHECKTAG) == 0 || checkTag(currentKey, viewToInvalidate)) {
                if ((changeFlags & FLAG_BACKGROUND) != 0) {
                    Drawable background = viewToInvalidate.getBackground();
                    viewToInvalidate.setBackgroundColor(color);
                }
                if ((changeFlags & FLAG_BACKGROUNDFILTER) != 0) {
                    if ((changeFlags & FLAG_PROGRESSBAR) != 0) {
                        if (viewToInvalidate instanceof EditTextBoldCursor) {
                            ((EditTextBoldCursor) viewToInvalidate).setErrorLineColor(color);
                        }
                    } else {
                        Drawable drawable = viewToInvalidate.getBackground();
                        if (drawable instanceof CombinedDrawable) {
                            if ((changeFlags & FLAG_DRAWABLESELECTEDSTATE) != 0) {
                                drawable = ((CombinedDrawable) drawable).getBackground();
                            } else {
                                drawable = ((CombinedDrawable) drawable).getIcon();
                            }
                        }
                        if (drawable != null) {
                            if (drawable instanceof StateListDrawable || Build.VERSION.SDK_INT >= 21 && drawable instanceof RippleDrawable) {
                                Theme.setSelectorDrawableColor(drawable, color, (changeFlags & FLAG_DRAWABLESELECTEDSTATE) != 0);
                            } else if (drawable instanceof ShapeDrawable) {
                                ((ShapeDrawable) drawable).getPaint().setColor(color);
                            } else {
                                drawable.setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                            }
                        }
                    }
                }
            }
        }
        if (viewToInvalidate instanceof ActionBar) {
            if ((changeFlags & FLAG_AB_ITEMSCOLOR) != 0) {
                ((ActionBar) viewToInvalidate).setItemsColor(color, false);
            }
            if ((changeFlags & FLAG_AB_TITLECOLOR) != 0) {
                ((ActionBar) viewToInvalidate).setTitleColor(color);
            }
            if ((changeFlags & FLAG_AB_SELECTORCOLOR) != 0) {
                ((ActionBar) viewToInvalidate).setItemsBackgroundColor(color, false);
            }
            if ((changeFlags & FLAG_AB_AM_SELECTORCOLOR) != 0) {
                ((ActionBar) viewToInvalidate).setItemsBackgroundColor(color, true);
            }
            if ((changeFlags & FLAG_AB_AM_ITEMSCOLOR) != 0) {
                ((ActionBar) viewToInvalidate).setItemsColor(color, true);
            }
            if ((changeFlags & FLAG_AB_SUBTITLECOLOR) != 0) {
                ((ActionBar) viewToInvalidate).setSubtitleColor(color);
            }
            if ((changeFlags & FLAG_AB_AM_BACKGROUND) != 0) {
                ((ActionBar) viewToInvalidate).setActionModeColor(color);
            }
            if ((changeFlags & FLAG_AB_AM_TOPBACKGROUND) != 0) {
                ((ActionBar) viewToInvalidate).setActionModeTopColor(color);
            }
            if ((changeFlags & FLAG_AB_SEARCHPLACEHOLDER) != 0) {
                ((ActionBar) viewToInvalidate).setSearchTextColor(color, true);
            }
            if ((changeFlags & FLAG_AB_SEARCH) != 0) {
                ((ActionBar) viewToInvalidate).setSearchTextColor(color, false);
            }
            if ((changeFlags & FLAG_AB_SUBMENUITEM) != 0) {
                ((ActionBar) viewToInvalidate).setPopupItemsColor(color, (changeFlags & FLAG_IMAGECOLOR) != 0);
            }
            if ((changeFlags & FLAG_AB_SUBMENUBACKGROUND) != 0) {
                ((ActionBar) viewToInvalidate).setPopupBackgroundColor(color);
            }
        }
        if (viewToInvalidate instanceof RadialProgressView) {
            ((RadialProgressView) viewToInvalidate).setProgressColor(color);
        } else if (viewToInvalidate instanceof LineProgressView) {
            if ((changeFlags & FLAG_PROGRESSBAR) != 0) {
                ((LineProgressView) viewToInvalidate).setProgressColor(color);
            } else {
                ((LineProgressView) viewToInvalidate).setBackColor(color);
            }
        }
        if ((changeFlags & FLAG_TEXTCOLOR) != 0) {
            if ((changeFlags & FLAG_CHECKTAG) == 0 || checkTag(currentKey, viewToInvalidate)) {
                if (viewToInvalidate instanceof TextView) {
                    ((TextView) viewToInvalidate).setTextColor(color);
                } else if (viewToInvalidate instanceof SimpleTextView) {
                    ((SimpleTextView) viewToInvalidate).setTextColor(color);
                }

            }
        }
        if ((changeFlags & FLAG_CURSORCOLOR) != 0) {
            if (viewToInvalidate instanceof EditTextBoldCursor) {
                ((EditTextBoldCursor) viewToInvalidate).setCursorColor(color);
            }
        }
        if ((changeFlags & FLAG_HINTTEXTCOLOR) != 0) {
            if (viewToInvalidate instanceof EditTextBoldCursor) {
                if ((changeFlags & FLAG_PROGRESSBAR) != 0) {
                    ((EditTextBoldCursor) viewToInvalidate).setHeaderHintColor(color);
                } else {
                    ((EditTextBoldCursor) viewToInvalidate).setHintColor(color);
                }
            } else if (viewToInvalidate instanceof EditText) {
                ((EditText) viewToInvalidate).setHintTextColor(color);
            }
        }
        if ((changeFlags & FLAG_IMAGECOLOR) != 0) {
            if ((changeFlags & FLAG_CHECKTAG) == 0 || checkTag(currentKey, viewToInvalidate)) {
                if (viewToInvalidate instanceof ImageView) {
                    if ((changeFlags & FLAG_USEBACKGROUNDDRAWABLE) != 0) {
                        Drawable drawable = ((ImageView) viewToInvalidate).getDrawable();
                        if (drawable instanceof StateListDrawable || Build.VERSION.SDK_INT >= 21 && drawable instanceof RippleDrawable) {
                            Theme.setSelectorDrawableColor(drawable, color, (changeFlags & FLAG_DRAWABLESELECTEDSTATE) != 0);
                        }
                    } else {
                        ((ImageView) viewToInvalidate).setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                    }
                } else if (viewToInvalidate instanceof SimpleTextView) {
                    SimpleTextView textView = (SimpleTextView) viewToInvalidate;
                    textView.setSideDrawablesColor(color);
                }
            }
        }
        if (viewToInvalidate instanceof ScrollView) {
            if ((changeFlags & FLAG_LISTGLOWCOLOR) != 0) {
                AndroidUtilities.setScrollViewEdgeEffectColor((ScrollView) viewToInvalidate, color);
            }
        }
        if (viewToInvalidate instanceof RecyclerListView) {
            RecyclerListView recyclerListView = (RecyclerListView) viewToInvalidate;
            if ((changeFlags & FLAG_SELECTOR) != 0) {
                if (currentKey.equals(Theme.key_listSelector)) {
                    recyclerListView.setListSelectorColor(color);
                }
            }
            if ((changeFlags & FLAG_FASTSCROLL) != 0) {
                recyclerListView.updateFastScrollColors();
            }
            if ((changeFlags & FLAG_LISTGLOWCOLOR) != 0) {
                recyclerListView.setGlowColor(color);
            }
            if ((changeFlags & FLAG_SECTIONS) != 0) {
                ArrayList<View> headers = recyclerListView.getHeaders();
                if (headers != null) {
                    for (int a = 0; a < headers.size(); a++) {
                        processViewColor(headers.get(a), color);
                    }
                }
                headers = recyclerListView.getHeadersCache();
                if (headers != null) {
                    for (int a = 0; a < headers.size(); a++) {
                        processViewColor(headers.get(a), color);
                    }
                }
                View header = recyclerListView.getPinnedHeader();
                if (header != null) {
                    processViewColor(header, color);
                }
            }
        } else if (viewToInvalidate != null && (listClasses == null || listClasses.length == 0)) {
            if ((changeFlags & FLAG_SELECTOR) != 0) {
                viewToInvalidate.setBackgroundDrawable(Theme.getSelectorDrawable(false));
            } else if ((changeFlags & FLAG_SELECTORWHITE) != 0) {
                viewToInvalidate.setBackgroundDrawable(Theme.getSelectorDrawable(true));
            }
        }
        if (listClasses != null) {
            if (viewToInvalidate instanceof RecyclerListView) {
                RecyclerListView recyclerListView = (RecyclerListView) viewToInvalidate;
                recyclerListView.getRecycledViewPool().clear();
                int count = recyclerListView.getHiddenChildCount();
                for (int a = 0; a < count; a++) {
                    processViewColor(recyclerListView.getHiddenChildAt(a), color);
                }
                count = recyclerListView.getCachedChildCount();
                for (int a = 0; a < count; a++) {
                    processViewColor(recyclerListView.getCachedChildAt(a), color);
                }
                count = recyclerListView.getAttachedScrapChildCount();
                for (int a = 0; a < count; a++) {
                    processViewColor(recyclerListView.getAttachedScrapChildAt(a), color);
                }
            }
            if (viewToInvalidate instanceof ViewGroup) {
                ViewGroup viewGroup = (ViewGroup) viewToInvalidate;
                int count = viewGroup.getChildCount();
                for (int a = 0; a < count; a++) {
                    processViewColor(viewGroup.getChildAt(a), color);
                }
            }
            processViewColor(viewToInvalidate, color);
        }
        if (delegate != null) {
            delegate.didSetColor();
        }
        if (viewToInvalidate != null) {
            viewToInvalidate.invalidate();
        }
    }

    private void processViewColor(View child, int color) {
        for (int b = 0; b < listClasses.length; b++) {
            if (listClasses[b].isInstance(child)) {
                child.invalidate();
                boolean passedCheck;
                if ((changeFlags & FLAG_CHECKTAG) == 0 || checkTag(currentKey, child)) {
                    passedCheck = true;
                    child.invalidate();
                    if ((changeFlags & FLAG_BACKGROUNDFILTER) != 0) {
                        Drawable drawable = child.getBackground();
                        if (drawable != null) {
                            if ((changeFlags & FLAG_CELLBACKGROUNDCOLOR) != 0) {
                                if (drawable instanceof CombinedDrawable) {
                                    Drawable back = ((CombinedDrawable) drawable).getBackground();
                                    if (back instanceof ColorDrawable) {
                                        ((ColorDrawable) back).setColor(color);
                                    }
                                }
                            } else {
                                if (drawable instanceof CombinedDrawable) {
                                    drawable = ((CombinedDrawable) drawable).getIcon();
                                } else if (drawable instanceof StateListDrawable || Build.VERSION.SDK_INT >= 21 && drawable instanceof RippleDrawable) {
                                    Theme.setSelectorDrawableColor(drawable, color, (changeFlags & FLAG_DRAWABLESELECTEDSTATE) != 0);
                                }
                                drawable.setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                            }
                        }
                    } else if ((changeFlags & FLAG_CELLBACKGROUNDCOLOR) != 0) {
                        child.setBackgroundColor(color);
                    } else if ((changeFlags & FLAG_TEXTCOLOR) != 0) {
                        if (child instanceof TextView) {
                            ((TextView) child).setTextColor(color);
                        }
                    } else if ((changeFlags & FLAG_SELECTOR) != 0) {
                        child.setBackgroundDrawable(Theme.getSelectorDrawable(false));
                    } else if ((changeFlags & FLAG_SELECTORWHITE) != 0) {
                        child.setBackgroundDrawable(Theme.getSelectorDrawable(true));
                    }
                } else {
                    passedCheck = false;
                }
                if (listClassesFieldName != null) {
                    String key = listClasses[b] + "_" + listClassesFieldName[b];
                    if (notFoundCachedFields != null && notFoundCachedFields.containsKey(key)) {
                        continue;
                    }
                    try {
                        Field field = cachedFields.get(key);
                        if (field == null) {
                            field = listClasses[b].getDeclaredField(listClassesFieldName[b]);
                            if (field != null) {
                                field.setAccessible(true);
                                cachedFields.put(key, field);
                            }
                        }
                        if (field != null) {
                            Object object = field.get(child);
                            if (object != null) {
                                if (!passedCheck && object instanceof View && !checkTag(currentKey, (View) object)) {
                                    continue;
                                }
                                if (object instanceof View) {
                                    ((View) object).invalidate();
                                }
                                if (lottieLayerName != null && object instanceof RLottieImageView) {
                                    ((RLottieImageView) object).setLayerColor(lottieLayerName + ".**", color);
                                }
                                if ((changeFlags & FLAG_USEBACKGROUNDDRAWABLE) != 0 && object instanceof View) {
                                    object = ((View) object).getBackground();
                                }
                                if ((changeFlags & FLAG_BACKGROUND) != 0 && object instanceof View) {
                                    View view = (View) object;
                                    Drawable background = view.getBackground();
                                    view.setBackgroundColor(color);
                                } else if (object instanceof SimpleTextView) {
                                    if ((changeFlags & FLAG_LINKCOLOR) != 0) {
                                        ((SimpleTextView) object).setLinkTextColor(color);
                                    } else {
                                        ((SimpleTextView) object).setTextColor(color);
                                    }
                                } else if (object instanceof TextView) {
                                    TextView textView = (TextView) object;
                                    if ((changeFlags & FLAG_IMAGECOLOR) != 0) {
                                        Drawable[] drawables = textView.getCompoundDrawables();
                                        if (drawables != null) {
                                            for (int a = 0; a < drawables.length; a++) {
                                                if (drawables[a] != null) {
                                                    drawables[a].setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                                                }
                                            }
                                        }
                                    } else if ((changeFlags & FLAG_LINKCOLOR) != 0) {
                                        textView.getPaint().linkColor = color;
                                        textView.invalidate();
                                    } else if ((changeFlags & FLAG_FASTSCROLL) != 0) {
                                        CharSequence text = textView.getText();
                                        if (text instanceof SpannedString) {
                                            TypefaceSpan[] spans = ((SpannedString) text).getSpans(0, text.length(), TypefaceSpan.class);
                                            if (spans != null && spans.length > 0) {
                                                for (int i = 0; i < spans.length; i++) {
                                                    spans[i].setColor(color);
                                                }
                                            }
                                        }
                                    } else {
                                        textView.setTextColor(color);
                                    }
                                } else if (object instanceof ImageView) {
                                    ((ImageView) object).setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                                } else if (object instanceof Drawable) {
                                    if (object instanceof CombinedDrawable) {
                                        if ((changeFlags & FLAG_BACKGROUNDFILTER) != 0) {
                                            ((CombinedDrawable) object).getBackground().setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                                        } else {
                                            ((CombinedDrawable) object).getIcon().setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                                        }
                                    } else if (object instanceof StateListDrawable || Build.VERSION.SDK_INT >= 21 && object instanceof RippleDrawable) {
                                        Theme.setSelectorDrawableColor((Drawable) object, color, (changeFlags & FLAG_DRAWABLESELECTEDSTATE) != 0);
                                    } else if (object instanceof GradientDrawable) {
                                        ((GradientDrawable) object).setColor(color);
                                    } else {
                                        ((Drawable) object).setColorFilter(new PorterDuffColorFilter(color, PorterDuff.Mode.MULTIPLY));
                                    }
                                } else if (object instanceof Integer) {
                                    field.set(child, color);
                                } else if (object instanceof TextPaint) {
                                    if ((changeFlags & FLAG_LINKCOLOR) != 0) {
                                        ((TextPaint) object).linkColor = color;
                                    } else {
                                        ((TextPaint) object).setColor(color);
                                    }
                                } else if (object instanceof LineProgressView) {
                                    if ((changeFlags & FLAG_PROGRESSBAR) != 0) {
                                        ((LineProgressView) object).setProgressColor(color);
                                    } else {
                                        ((LineProgressView) object).setBackColor(color);
                                    }
                                } else if (object instanceof RadialProgressView) {
                                    ((RadialProgressView) object).setProgressColor(color);
                                } else if (object instanceof Paint) {
                                    ((Paint) object).setColor(color);
                                }
                            }
                        }
                    } catch (Throwable e) {
                        FileLog.e(e);
                        notFoundCachedFields.put(key, true);
                    }
                }
            }
        }
    }

    public String getCurrentKey() {
        return currentKey;
    }

    public int getCurrentColor() {
        return currentColor;
    }

    public int getSetColor() {
        return Theme.getColor(currentKey);
    }

    public String getTitle() {
        return currentKey;
    }
}
