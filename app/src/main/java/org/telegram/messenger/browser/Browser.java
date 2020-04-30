/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019-2020.
 */

package org.telegram.messenger.browser;

import android.app.Activity;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ResolveInfo;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.text.TextUtils;

import org.telegram.messenger.BuildVars;
import org.telegram.messenger.CustomTabsCopyReceiver;
import org.telegram.messenger.FileLog;
import org.telegram.messenger.LocaleController;
import org.telegram.messenger.R;
import org.telegram.messenger.ShareBroadcastReceiver;
import org.telegram.messenger.support.customtabs.CustomTabsCallback;
import org.telegram.messenger.support.customtabs.CustomTabsClient;
import org.telegram.messenger.support.customtabs.CustomTabsIntent;
import org.telegram.messenger.support.customtabs.CustomTabsServiceConnection;
import org.telegram.messenger.support.customtabs.CustomTabsSession;
import org.telegram.messenger.support.customtabsclient.shared.CustomTabsHelper;
import org.telegram.messenger.support.customtabsclient.shared.ServiceConnection;
import org.telegram.messenger.support.customtabsclient.shared.ServiceConnectionCallback;
import org.telegram.ui.ActionBar.Theme;
import org.telegram.ui.LaunchActivity;
import org.telegram.messenger.ApplicationLoader;

import java.lang.ref.WeakReference;
import java.util.List;

public class Browser {

    private static WeakReference<CustomTabsSession> customTabsCurrentSession;
    private static CustomTabsSession customTabsSession;
    private static CustomTabsClient customTabsClient;
    private static CustomTabsServiceConnection customTabsServiceConnection;
    private static String customTabsPackageToBind;
    private static WeakReference<Activity> currentCustomTabsActivity;

    private static CustomTabsSession getCurrentSession() {
        return customTabsCurrentSession == null ? null : customTabsCurrentSession.get();
    }

    private static void setCurrentSession(CustomTabsSession session) {
        customTabsCurrentSession = new WeakReference<>(session);
    }

    private static CustomTabsSession getSession() {
        if (customTabsClient == null) {
            customTabsSession = null;
        } else if (customTabsSession == null) {
            customTabsSession = customTabsClient.newSession(new NavigationCallback());
            setCurrentSession(customTabsSession);
        }
        return customTabsSession;
    }

    public static void bindCustomTabsService(Activity activity) {
        Activity currentActivity = currentCustomTabsActivity == null ? null : currentCustomTabsActivity.get();
        if (currentActivity != null && currentActivity != activity) {
            unbindCustomTabsService(currentActivity);
        }
        if (customTabsClient != null) {
            return;
        }
        currentCustomTabsActivity = new WeakReference<>(activity);
        try {
            if (TextUtils.isEmpty(customTabsPackageToBind)) {
                customTabsPackageToBind = CustomTabsHelper.getPackageNameToUse(activity);
                if (customTabsPackageToBind == null) {
                    return;
                }
            }
            customTabsServiceConnection = new ServiceConnection(new ServiceConnectionCallback() {
                @Override
                public void onServiceConnected(CustomTabsClient client) {
                    customTabsClient = client;
                    if (customTabsClient != null) {
                        try {
                            customTabsClient.warmup(0);
                        } catch (Exception e) {
                            FileLog.e(e);
                        }
                    }
                }

                @Override
                public void onServiceDisconnected() {
                    customTabsClient = null;
                }
            });
            if (!CustomTabsClient.bindCustomTabsService(activity, customTabsPackageToBind, customTabsServiceConnection)) {
                customTabsServiceConnection = null;
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
    }

    public static void unbindCustomTabsService(Activity activity) {
        if (customTabsServiceConnection == null) {
            return;
        }
        Activity currentActivity = currentCustomTabsActivity == null ? null : currentCustomTabsActivity.get();
        if (currentActivity == activity) {
            currentCustomTabsActivity.clear();
        }
        try {
            activity.unbindService(customTabsServiceConnection);
        } catch (Exception ignore) {

        }
        customTabsClient = null;
        customTabsSession = null;
    }

    private static class NavigationCallback extends CustomTabsCallback {
        @Override
        public void onNavigationEvent(int navigationEvent, Bundle extras) {

        }
    }

    public static void openUrl(Context context, String url) {
        if (url == null) {
            return;
        }
        openUrl(context, Uri.parse(url), true);
    }

    public static void openUrl(Context context, Uri uri) {
        openUrl(context, uri, true);
    }

    public static void openUrl(Context context, String url, boolean allowCustom) {
        if (context == null || url == null) {
            return;
        }
        openUrl(context, Uri.parse(url), allowCustom);
    }

    public static void openUrl(final Context context, Uri uri, final boolean allowCustom) {
        if (context == null || uri == null) {
            return;
        }
        boolean[] forceBrowser = new boolean[]{false};
        boolean internalUri = isInternalUri(uri, forceBrowser);
        try {
            String scheme = uri.getScheme() != null ? uri.getScheme().toLowerCase() : "";
            if ("http".equals(scheme) || "https".equals(scheme)) {
                try {
                    uri = uri.normalizeScheme();
                } catch (Exception e) {
                    FileLog.e(e);
                }
            }
            if (allowCustom && !internalUri && !scheme.equals("tel")) {
                String[] browserPackageNames = null;
                try {
                    Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.google.com"));
                    List<ResolveInfo> list = context.getPackageManager().queryIntentActivities(browserIntent, 0);
                    if (list != null && !list.isEmpty()) {
                        browserPackageNames = new String[list.size()];
                        for (int a = 0; a < list.size(); a++) {
                            browserPackageNames[a] = list.get(a).activityInfo.packageName;
                            if (BuildVars.LOGS_ENABLED) {
                                FileLog.d("default browser name = " + browserPackageNames[a]);
                            }
                        }
                    }
                } catch (Exception ignore) {

                }

                List<ResolveInfo> allActivities = null;
                try {
                    Intent viewIntent = new Intent(Intent.ACTION_VIEW, uri);
                    allActivities = context.getPackageManager().queryIntentActivities(viewIntent, 0);
                    if (browserPackageNames != null) {
                        for (int a = 0; a < allActivities.size(); a++) {
                            for (int b = 0; b < browserPackageNames.length; b++) {
                                if (browserPackageNames[b].equals(allActivities.get(a).activityInfo.packageName)) {
                                    allActivities.remove(a);
                                    a--;
                                    break;
                                }
                            }
                        }
                    } else {
                        for (int a = 0; a < allActivities.size(); a++) {
                            if (allActivities.get(a).activityInfo.packageName.toLowerCase().contains("browser") || allActivities.get(a).activityInfo.packageName.toLowerCase().contains("chrome")) {
                                allActivities.remove(a);
                                a--;
                            }
                        }
                    }
                    if (BuildVars.LOGS_ENABLED) {
                        for (int a = 0; a < allActivities.size(); a++) {
                            FileLog.d("device has " + allActivities.get(a).activityInfo.packageName + " to open " + uri.toString());
                        }
                    }
                } catch (Exception ignore) {

                }

                if (forceBrowser[0] || allActivities == null || allActivities.isEmpty()) {
                    Intent share = new Intent(ApplicationLoader.applicationContext, ShareBroadcastReceiver.class);
                    share.setAction(Intent.ACTION_SEND);

                    PendingIntent copy = PendingIntent.getBroadcast(ApplicationLoader.applicationContext, 0, new Intent(ApplicationLoader.applicationContext, CustomTabsCopyReceiver.class), PendingIntent.FLAG_UPDATE_CURRENT);

                    CustomTabsIntent.Builder builder = new CustomTabsIntent.Builder(getSession());
                    builder.addMenuItem(LocaleController.getString("CopyLink", R.string.CopyLink), copy);

                    builder.setToolbarColor(Theme.getColor(Theme.key_actionBarBrowser));
                    builder.setShowTitle(true);
                    builder.setActionButton(BitmapFactory.decodeResource(context.getResources(), R.drawable.abc_ic_menu_share_mtrl_alpha), LocaleController.getString("ShareFile", R.string.ShareFile), PendingIntent.getBroadcast(ApplicationLoader.applicationContext, 0, share, 0), false);
                    CustomTabsIntent intent = builder.build();
                    intent.setUseNewTask();
                    intent.launchUrl(context, uri);
                    return;
                }
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
        try {
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
            if (internalUri) {
                ComponentName componentName = new ComponentName(context.getPackageName(), LaunchActivity.class.getName());
                intent.setComponent(componentName);
            }
            intent.putExtra(android.provider.Browser.EXTRA_CREATE_NEW_TAB, true);
            intent.putExtra(android.provider.Browser.EXTRA_APPLICATION_ID, context.getPackageName());
            context.startActivity(intent);
        } catch (Exception e) {
            FileLog.e(e);
        }
    }

    public static boolean isInternalUrl(String url, boolean[] forceBrowser) {
        return isInternalUri(Uri.parse(url), forceBrowser);
    }

    public static boolean isPassportUrl(String url) {
        if (url == null) {
            return false;
        }
        try {
            url = url.toLowerCase();
            if (url.startsWith("tg:passport") || url.startsWith("tg://passport") || url.startsWith("tg:secureid") || url.contains("resolve") && url.contains("domain=telegrampassport")) {
                return true;
            }
        } catch (Throwable ignore) {

        }
        return false;
    }

    public static boolean isInternalUri(Uri uri, boolean[] forceBrowser) {
        String host = uri.getHost();
        host = host != null ? host.toLowerCase() : "";
        if ("ton".equals(uri.getScheme())) {
            return true;
        } else if ("tg".equals(uri.getScheme())) {
            return true;
        } else if ("telegram.dog".equals(host)) {
            String path = uri.getPath();
            if (path != null && path.length() > 1) {
                path = path.substring(1).toLowerCase();
                if (path.startsWith("blog") || path.equals("iv") || path.startsWith("faq") || path.equals("apps") || path.startsWith("s/")) {
                    if (forceBrowser != null) {
                        forceBrowser[0] = true;
                    }
                    return false;
                }
                return true;
            }
        } else if ("telegram.me".equals(host) || "t.me".equals(host)) {
            String path = uri.getPath();
            if (path != null && path.length() > 1) {
                path = path.substring(1).toLowerCase();
                if (path.equals("iv") || path.startsWith("s/")) {
                    if (forceBrowser != null) {
                        forceBrowser[0] = true;
                    }
                    return false;
                }
                return true;
            }
        }
        return false;
    }
}
