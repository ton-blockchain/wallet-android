/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019.
 */

package org.telegram.ui;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Intent;
import android.content.res.Configuration;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.ActionMode;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewTreeObserver;
import android.view.Window;

import org.telegram.messenger.AndroidUtilities;
import org.telegram.messenger.BuildVars;
import org.telegram.messenger.ApplicationLoader;
import org.telegram.messenger.FileLog;
import org.telegram.messenger.LocaleController;
import org.telegram.messenger.R;
import org.telegram.messenger.UserConfig;
import org.telegram.ui.ActionBar.AlertDialog;
import org.telegram.ui.ActionBar.ActionBarLayout;
import org.telegram.ui.ActionBar.BaseFragment;
import org.telegram.ui.ActionBar.DrawerLayoutContainer;
import org.telegram.ui.ActionBar.Theme;
import org.telegram.ui.Wallet.WalletActivity;
import org.telegram.ui.Wallet.WalletCreateActivity;

import java.util.ArrayList;
import java.util.HashMap;

public class LaunchActivity extends Activity implements ActionBarLayout.ActionBarLayoutDelegate {

    private boolean finished;
    private static ArrayList<BaseFragment> mainFragmentsStack = new ArrayList<>();
    private ViewTreeObserver.OnGlobalLayoutListener onGlobalLayoutListener;

    private ActionMode visibleActionMode;

    private ActionBarLayout actionBarLayout;
    protected DrawerLayoutContainer drawerLayoutContainer;
    private AlertDialog visibleDialog;

    private int currentAccount;

    private AlertDialog localeDialog;
    private boolean loadingLocaleDialog;
    private HashMap<String, String> systemLocaleStrings;
    private HashMap<String, String> englishLocaleStrings;

    private boolean tabletFullSize;

    private static final int PLAY_SERVICES_REQUEST_CHECK_SETTINGS = 140;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        ApplicationLoader.postInitApplication();
        AndroidUtilities.checkDisplaySize(this, getResources().getConfiguration());


        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setTheme(R.style.Theme_TMessages);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            try {
                setTaskDescription(new ActivityManager.TaskDescription(null, null, Theme.getColor(Theme.key_actionBarDefault) | 0xff000000));
            } catch (Exception ignore) {

            }
            try {
                getWindow().setNavigationBarColor(0xff000000);
            } catch (Exception ignore) {

            }
        }

        getWindow().setBackgroundDrawableResource(R.drawable.transparent);
        super.onCreate(savedInstanceState);
        if (Build.VERSION.SDK_INT >= 24) {
            AndroidUtilities.isInMultiwindow = isInMultiWindowMode();
        }

        Theme.createCommonResources(this);
        AndroidUtilities.fillStatusBarHeight(this);
        actionBarLayout = new ActionBarLayout(this);

        drawerLayoutContainer = new DrawerLayoutContainer(this);
        drawerLayoutContainer.setBehindKeyboardColor(Theme.getColor(Theme.key_windowBackgroundWhite));
        setContentView(drawerLayoutContainer, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        drawerLayoutContainer.addView(actionBarLayout, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        drawerLayoutContainer.setParentActionBarLayout(actionBarLayout);
        actionBarLayout.setDrawerLayoutContainer(drawerLayoutContainer);
        actionBarLayout.init(mainFragmentsStack);
        actionBarLayout.setDelegate(this);

        if (actionBarLayout.fragmentsStack.isEmpty()) {
            BaseFragment fragment = getCurrentWalletFragment(null);
            actionBarLayout.addFragmentToStack(fragment);
        }
        drawerLayoutContainer.setAllowOpenDrawer(false, false);

        handleIntent(getIntent(), false, savedInstanceState != null, false);

        try {
            String os1 = Build.DISPLAY;
            String os2 = Build.USER;
            if (os1 != null) {
                os1 = os1.toLowerCase();
            } else {
                os1 = "";
            }
            if (os2 != null) {
                os2 = os1.toLowerCase();
            } else {
                os2 = "";
            }
            if (BuildVars.LOGS_ENABLED) {
                FileLog.d("OS name " + os1 + " " + os2);
            }
            if (os1.contains("flyme") || os2.contains("flyme")) {
                AndroidUtilities.incorrectDisplaySizeFix = true;
                final View view = getWindow().getDecorView().getRootView();
                view.getViewTreeObserver().addOnGlobalLayoutListener(onGlobalLayoutListener = () -> {
                    int height = view.getMeasuredHeight();
                    FileLog.d("height = " + height + " displayHeight = " + AndroidUtilities.displaySize.y);
                    if (Build.VERSION.SDK_INT >= 21) {
                        height -= AndroidUtilities.statusBarHeight;
                    }
                    if (height > AndroidUtilities.dp(100) && height < AndroidUtilities.displaySize.y && height + AndroidUtilities.dp(100) > AndroidUtilities.displaySize.y) {
                        AndroidUtilities.displaySize.y = height;
                        if (BuildVars.LOGS_ENABLED) {
                            FileLog.d("fix display size y to " + AndroidUtilities.displaySize.y);
                        }
                    }
                });
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
    }

    private BaseFragment getCurrentWalletFragment(String transferWalletUrl) {
        BaseFragment fragment;
        UserConfig userConfig = UserConfig.getInstance(currentAccount);
        if (TextUtils.isEmpty(userConfig.tonEncryptedData)) {
            if (!TextUtils.isEmpty(transferWalletUrl)) {
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setTitle(LocaleController.getString("Wallet", R.string.Wallet));
                builder.setMessage(LocaleController.getString("WalletTonLinkNoWalletText", R.string.WalletTonLinkNoWalletText));
                builder.setNegativeButton(LocaleController.getString("Cancel", R.string.Cancel), null);
                builder.setPositiveButton(LocaleController.getString("WalletTonLinkNoWalletCreateWallet", R.string.WalletTonLinkNoWalletCreateWallet), (dialog, which) -> presentFragment(new WalletCreateActivity(WalletCreateActivity.TYPE_CREATE)));
                builder.show();
                fragment = null;
            } else {
                fragment = new WalletCreateActivity(WalletCreateActivity.TYPE_CREATE);
            }
        } else if (!userConfig.tonCreationFinished) {
            WalletCreateActivity activity = new WalletCreateActivity(WalletCreateActivity.TYPE_KEY_GENERATED);
            activity.setResumeCreation();
            fragment = activity;
        } else if (!TextUtils.isEmpty(transferWalletUrl)) {
            fragment = new WalletActivity(transferWalletUrl);
        } else {
            fragment = new WalletActivity();
        }
        return fragment;
    }

    public int getMainFragmentsCount() {
        return mainFragmentsStack.size();
    }

    private boolean handleIntent(Intent intent, boolean isNew, boolean restore, boolean fromPassword) {
        /*if (PhotoViewer.hasInstance() && PhotoViewer.getInstance().isVisible()) {
            if (intent == null || !Intent.ACTION_MAIN.equals(intent.getAction())) {
                PhotoViewer.getInstance().closePhoto(false, true);
            }
        }*/
        int flags = intent.getFlags();
        boolean pushOpened = false;
        String transferWalletUrl = null;

        if ((flags & Intent.FLAG_ACTIVITY_LAUNCHED_FROM_HISTORY) == 0 && intent != null && intent.getAction() != null && !restore && Intent.ACTION_VIEW.equals(intent.getAction())) {
            Uri data = intent.getData();
            if (data != null) {
                String scheme = data.getScheme();
                if (scheme != null) {
                    if ("ton".equals(scheme)) {
                        String url = data.toString();
                        if (url.startsWith("ton:transfer") || url.startsWith("ton://transfer")) {
                            transferWalletUrl = url.replace("ton:transfer", "ton://transfer");
                        }
                    }
                }
            }
        }

        if (transferWalletUrl != null) {
            BaseFragment fragment = getCurrentWalletFragment(transferWalletUrl);
            if (fragment != null) {
                AndroidUtilities.runOnUIThread(() -> presentFragment(fragment));
            }
            pushOpened = true;
        }

        if (!pushOpened && !isNew) {
            if (actionBarLayout.fragmentsStack.isEmpty()) {
                BaseFragment fragment = getCurrentWalletFragment(null);
                actionBarLayout.addFragmentToStack(fragment);
            }
            actionBarLayout.showLastFragment();
        }

        intent.setAction(null);
        return pushOpened;
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        handleIntent(intent, true, false, false);
    }

    private void onFinish() {
        if (finished) {
            return;
        }
        finished = true;
    }

    public void presentFragment(BaseFragment fragment) {
        actionBarLayout.presentFragment(fragment);
    }

    public boolean presentFragment(final BaseFragment fragment, final boolean removeLast, boolean forceWithoutAnimation) {
        return actionBarLayout.presentFragment(fragment, removeLast, forceWithoutAnimation, true, false);
    }

    public ActionBarLayout getActionBarLayout() {
        return actionBarLayout;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (actionBarLayout.fragmentsStack.size() != 0) {
            BaseFragment fragment = actionBarLayout.fragmentsStack.get(actionBarLayout.fragmentsStack.size() - 1);
            fragment.onActivityResultFragment(requestCode, resultCode, data);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (grantResults == null) {
            grantResults = new int[0];
        }
        if (permissions == null) {
            permissions = new String[0];
        }
        if (actionBarLayout.fragmentsStack.size() != 0) {
            BaseFragment fragment = actionBarLayout.fragmentsStack.get(actionBarLayout.fragmentsStack.size() - 1);
            fragment.onRequestPermissionsResultFragment(requestCode, permissions, grantResults);
        }
    }

    private void showPermissionErrorAlert(String message) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle(LocaleController.getString("AppName", R.string.AppName));
        builder.setMessage(message);
        builder.setNegativeButton(LocaleController.getString("PermissionOpenSettings", R.string.PermissionOpenSettings), (dialog, which) -> {
            try {
                Intent intent = new Intent(android.provider.Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
                intent.setData(Uri.parse("package:" + ApplicationLoader.applicationContext.getPackageName()));
                startActivity(intent);
            } catch (Exception e) {
                FileLog.e(e);
            }
        });
        builder.setPositiveButton(LocaleController.getString("OK", R.string.OK), null);
        builder.show();
    }

    @Override
    protected void onPause() {
        super.onPause();
        ApplicationLoader.mainInterfacePaused = true;
        actionBarLayout.onPause();
        AndroidUtilities.unregisterUpdates();
        /*if (PhotoViewer.hasInstance() && PhotoViewer.getInstance().isVisible()) {
            PhotoViewer.getInstance().onPause();
        }*/
    }

    @Override
    protected void onStart() {
        super.onStart();
        //Browser.bindCustomTabsService(this);
    }

    @Override
    protected void onStop() {
        super.onStop();
        //Browser.unbindCustomTabsService(this);
    }

    @Override
    protected void onDestroy() {
        /*if (PhotoViewer.getPipInstance() != null) {
            PhotoViewer.getPipInstance().destroyPhotoViewer();
        }
        if (PhotoViewer.hasInstance()) {
            PhotoViewer.getInstance().destroyPhotoViewer();
        }*/
        try {
            if (visibleDialog != null) {
                visibleDialog.dismiss();
                visibleDialog = null;
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
        try {
            if (onGlobalLayoutListener != null) {
                final View view = getWindow().getDecorView().getRootView();
                view.getViewTreeObserver().removeOnGlobalLayoutListener(onGlobalLayoutListener);
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
        super.onDestroy();
        onFinish();
    }

    @Override
    protected void onResume() {
        super.onResume();
        ApplicationLoader.mainInterfacePaused = false;

        actionBarLayout.onResume();

        AndroidUtilities.checkForCrashes(this);
        //AndroidUtilities.checkForUpdates(this);
        /*if (PhotoViewer.hasInstance() && PhotoViewer.getInstance().isVisible()) {
            PhotoViewer.getInstance().onResume();
        }*/
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        AndroidUtilities.checkDisplaySize(this, newConfig);
        super.onConfigurationChanged(newConfig);
        /*PhotoViewer photoViewer = PhotoViewer.getPipInstance();
        if (photoViewer != null) {
            photoViewer.onConfigurationChanged(newConfig);
        }*/
    }

    @Override
    public void onMultiWindowModeChanged(boolean isInMultiWindowMode) {
        AndroidUtilities.isInMultiwindow = isInMultiWindowMode;
    }

    private String getStringForLanguageAlert(HashMap<String, String> map, String key, int intKey) {
        String value = map.get(key);
        if (value == null) {
            return LocaleController.getString(key, intKey);
        }
        return value;
    }

    public void hideVisibleActionMode() {
        if (visibleActionMode == null) {
            return;
        }
        visibleActionMode.finish();
    }

    @Override
    public void onBackPressed() {
        /*if (PhotoViewer.hasInstance() && PhotoViewer.getInstance().isVisible()) {
            PhotoViewer.getInstance().closePhoto(true, false);
        } else */if (drawerLayoutContainer.isDrawerOpened()) {
            drawerLayoutContainer.closeDrawer(false);
        } else {
            actionBarLayout.onBackPressed();
        }
    }

    @Override
    public void onLowMemory() {
        super.onLowMemory();
        actionBarLayout.onLowMemory();
    }

    @Override
    public void onActionModeStarted(ActionMode mode) {
        super.onActionModeStarted(mode);
        visibleActionMode = mode;
        try {
            Menu menu = mode.getMenu();
            if (menu != null) {
                actionBarLayout.extendActionMode(menu);
            }
        } catch (Exception e) {
            FileLog.e(e);
        }
        if (Build.VERSION.SDK_INT >= 23 && mode.getType() == ActionMode.TYPE_FLOATING) {
            return;
        }
        actionBarLayout.onActionModeStarted(mode);
    }

    @Override
    public void onActionModeFinished(ActionMode mode) {
        super.onActionModeFinished(mode);
        if (visibleActionMode == mode) {
            visibleActionMode = null;
        }
        if (Build.VERSION.SDK_INT >= 23 && mode.getType() == ActionMode.TYPE_FLOATING) {
            return;
        }
        actionBarLayout.onActionModeFinished(mode);
    }

    @Override
    public boolean onPreIme() {
        /*if (PhotoViewer.hasInstance() && PhotoViewer.getInstance().isVisible()) {
            PhotoViewer.getInstance().closePhoto(true, false);
            return true;
        }*/
        return false;
    }

    @Override
    public boolean dispatchKeyEvent(KeyEvent event) {
        /*int keyCode = event.getKeyCode();
        if (!mainFragmentsStack.isEmpty() && (!PhotoViewer.hasInstance() || !PhotoViewer.getInstance().isVisible()) && event.getRepeatCount() == 0 && event.getAction() == KeyEvent.ACTION_DOWN && (event.getKeyCode() == KeyEvent.KEYCODE_VOLUME_UP || event.getKeyCode() == KeyEvent.KEYCODE_VOLUME_DOWN)) {

        }*/
        return super.dispatchKeyEvent(event);
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_MENU) {
            /*if (PhotoViewer.hasInstance() && PhotoViewer.getInstance().isVisible()) {
                return super.onKeyUp(keyCode, event);
            }*/
            if (actionBarLayout.fragmentsStack.size() == 1) {
                if (!drawerLayoutContainer.isDrawerOpened()) {
                    if (getCurrentFocus() != null) {
                        AndroidUtilities.hideKeyboard(getCurrentFocus());
                    }
                    drawerLayoutContainer.openDrawer(false);
                } else {
                    drawerLayoutContainer.closeDrawer(false);
                }
            } else {
                actionBarLayout.onKeyUp(keyCode, event);
            }
        }
        return super.onKeyUp(keyCode, event);
    }

    @Override
    public boolean needPresentFragment(BaseFragment fragment, boolean removeLast, boolean forceWithoutAnimation, ActionBarLayout layout) {
        return true;
    }

    @Override
    public boolean needAddFragmentToStack(BaseFragment fragment, ActionBarLayout layout) {
        return true;
    }

    @Override
    public boolean needCloseLastFragment(ActionBarLayout layout) {
        if (layout.fragmentsStack.size() <= 1) {
            onFinish();
            finish();
            return false;
        }
        return true;
    }

    public void rebuildAllFragments(boolean last) {
        actionBarLayout.rebuildAllFragmentViews(last, last);
    }

    @Override
    public void onRebuildAllFragments(ActionBarLayout layout, boolean last) {

    }
}
