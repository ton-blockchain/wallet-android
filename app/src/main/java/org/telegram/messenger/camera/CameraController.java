/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019-2020.
 */

package org.telegram.messenger.camera;

import android.app.Activity;
import android.content.SharedPreferences;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.media.MediaRecorder;
import android.os.Build;
import android.util.Base64;

import org.telegram.messenger.AndroidUtilities;
import org.telegram.messenger.ApplicationLoader;
import org.telegram.messenger.BuildVars;
import org.telegram.messenger.FileLog;
import org.telegram.messenger.NotificationCenter;
import org.telegram.tgnet.SerializedData;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class CameraController {

    private static final int CORE_POOL_SIZE = 1;
    private static final int MAX_POOL_SIZE = 1;
    private static final int KEEP_ALIVE_SECONDS = 60;

    private ThreadPoolExecutor threadPool;
    protected ArrayList<String> availableFlashModes = new ArrayList<>();
    private MediaRecorder recorder;
    private String recordedFile;
    protected volatile ArrayList<CameraInfo> cameraInfos;
    private VideoTakeCallback onVideoTakeCallback;
    private boolean cameraInitied;
    private boolean loadingCameras;

    private ArrayList<Runnable> onFinishCameraInitRunnables = new ArrayList<>();

    private static volatile CameraController Instance = null;

    public interface VideoTakeCallback {
        void onFinishVideoRecording(String thumbPath, long duration);
    }

    public static CameraController getInstance() {
        CameraController localInstance = Instance;
        if (localInstance == null) {
            synchronized (CameraController.class) {
                localInstance = Instance;
                if (localInstance == null) {
                    Instance = localInstance = new CameraController();
                }
            }
        }
        return localInstance;
    }

    public CameraController() {
        threadPool = new ThreadPoolExecutor(CORE_POOL_SIZE, MAX_POOL_SIZE, KEEP_ALIVE_SECONDS, TimeUnit.SECONDS, new LinkedBlockingQueue<>());
    }

    public void cancelOnInitRunnable(final Runnable onInitRunnable) {
        onFinishCameraInitRunnables.remove(onInitRunnable);
    }

    public void initCamera(final Runnable onInitRunnable) {
        initCamera(onInitRunnable, false);
    }

    private void initCamera(final Runnable onInitRunnable, boolean withDelay) {
        if (cameraInitied) {
            return;
        }
        if (onInitRunnable != null && !onFinishCameraInitRunnables.contains(onInitRunnable)) {
            onFinishCameraInitRunnables.add(onInitRunnable);
        }
        if (loadingCameras || cameraInitied) {
            return;
        }
        loadingCameras = true;
        threadPool.execute(() -> {
            try {
                if (cameraInfos == null) {
                    SharedPreferences preferences = ApplicationLoader.applicationContext.getSharedPreferences("camera_cache", Activity.MODE_PRIVATE);
                    String cache = preferences.getString("cameraCache", null);
                    Comparator<Size> comparator = (o1, o2) -> {
                        if (o1.mWidth < o2.mWidth) {
                            return 1;
                        } else if (o1.mWidth > o2.mWidth) {
                            return -1;
                        } else {
                            if (o1.mHeight < o2.mHeight) {
                                return 1;
                            } else if (o1.mHeight > o2.mHeight) {
                                return -1;
                            }
                            return 0;
                        }
                    };
                    ArrayList<CameraInfo> result = new ArrayList<>();
                    if (cache != null) {
                        SerializedData serializedData = new SerializedData(Base64.decode(cache, Base64.DEFAULT));
                        int count = serializedData.readInt32(false);
                        for (int a = 0; a < count; a++) {
                            CameraInfo cameraInfo = new CameraInfo(serializedData.readInt32(false), serializedData.readInt32(false));
                            int pCount = serializedData.readInt32(false);
                            for (int b = 0; b < pCount; b++) {
                                cameraInfo.previewSizes.add(new Size(serializedData.readInt32(false), serializedData.readInt32(false)));
                            }
                            pCount = serializedData.readInt32(false);
                            for (int b = 0; b < pCount; b++) {
                                cameraInfo.pictureSizes.add(new Size(serializedData.readInt32(false), serializedData.readInt32(false)));
                            }
                            result.add(cameraInfo);

                            Collections.sort(cameraInfo.previewSizes, comparator);
                            Collections.sort(cameraInfo.pictureSizes, comparator);
                        }
                        serializedData.cleanup();
                    } else {
                        int count = Camera.getNumberOfCameras();
                        Camera.CameraInfo info = new Camera.CameraInfo();

                        int bufferSize = 4;
                        for (int cameraId = 0; cameraId < count; cameraId++) {
                            Camera.getCameraInfo(cameraId, info);
                            CameraInfo cameraInfo = new CameraInfo(cameraId, info.facing);

                            if (ApplicationLoader.mainInterfacePaused) {
                                throw new RuntimeException("APP_PAUSED");
                            }
                            Camera camera = Camera.open(cameraInfo.getCameraId());
                            Camera.Parameters params = camera.getParameters();

                            List<Camera.Size> list = params.getSupportedPreviewSizes();
                            for (int a = 0; a < list.size(); a++) {
                                Camera.Size size = list.get(a);
                                if (size.width == 1280 && size.height != 720) {
                                    continue;
                                }
                                if (size.height < 2160 && size.width < 2160) {
                                    cameraInfo.previewSizes.add(new Size(size.width, size.height));
                                    if (BuildVars.LOGS_ENABLED) {
                                        FileLog.d("preview size = " + size.width + " " + size.height);
                                    }
                                }
                            }

                            list = params.getSupportedPictureSizes();
                            for (int a = 0; a < list.size(); a++) {
                                Camera.Size size = list.get(a);
                                if (size.width == 1280 && size.height != 720) {
                                    continue;
                                }
                                if (!"samsung".equals(Build.MANUFACTURER) || !"jflteuc".equals(Build.PRODUCT) || size.width < 2048) {
                                    cameraInfo.pictureSizes.add(new Size(size.width, size.height));
                                    if (BuildVars.LOGS_ENABLED) {
                                        FileLog.d("picture size = " + size.width + " " + size.height);
                                    }
                                }
                            }

                            camera.release();
                            result.add(cameraInfo);

                            Collections.sort(cameraInfo.previewSizes, comparator);
                            Collections.sort(cameraInfo.pictureSizes, comparator);

                            bufferSize += 4 + 4 + 8 * (cameraInfo.previewSizes.size() + cameraInfo.pictureSizes.size());
                        }

                        SerializedData serializedData = new SerializedData(bufferSize);
                        serializedData.writeInt32(result.size());
                        for (int a = 0; a < count; a++) {
                            CameraInfo cameraInfo = result.get(a);
                            serializedData.writeInt32(cameraInfo.cameraId);
                            serializedData.writeInt32(cameraInfo.frontCamera);

                            int pCount = cameraInfo.previewSizes.size();
                            serializedData.writeInt32(pCount);
                            for (int b = 0; b < pCount; b++) {
                                Size size = cameraInfo.previewSizes.get(b);
                                serializedData.writeInt32(size.mWidth);
                                serializedData.writeInt32(size.mHeight);
                            }
                            pCount = cameraInfo.pictureSizes.size();
                            serializedData.writeInt32(pCount);
                            for (int b = 0; b < pCount; b++) {
                                Size size = cameraInfo.pictureSizes.get(b);
                                serializedData.writeInt32(size.mWidth);
                                serializedData.writeInt32(size.mHeight);
                            }
                        }
                        preferences.edit().putString("cameraCache", Base64.encodeToString(serializedData.toByteArray(), Base64.DEFAULT)).commit();
                        serializedData.cleanup();
                    }
                    cameraInfos = result;
                }
                AndroidUtilities.runOnUIThread(() -> {
                    loadingCameras = false;
                    cameraInitied = true;
                    if (!onFinishCameraInitRunnables.isEmpty()) {
                        for (int a = 0; a < onFinishCameraInitRunnables.size(); a++) {
                            onFinishCameraInitRunnables.get(a).run();
                        }
                        onFinishCameraInitRunnables.clear();
                    }
                    NotificationCenter.getGlobalInstance().postNotificationName(NotificationCenter.cameraInitied);
                });
            } catch (Exception e) {
                AndroidUtilities.runOnUIThread(() -> {
                    onFinishCameraInitRunnables.clear();
                    loadingCameras = false;
                    cameraInitied = false;
                    if (!withDelay && "APP_PAUSED".equals(e.getMessage())) {
                        AndroidUtilities.runOnUIThread(() -> initCamera(onInitRunnable, true), 1000);
                    }
                });

            }
        });
    }

    public boolean isCameraInitied() {
        return cameraInitied && cameraInfos != null && !cameraInfos.isEmpty();
    }

    public void runOnThreadPool(Runnable runnable) {
        threadPool.execute(runnable);
    }

    public void close(final CameraSession session, final CountDownLatch countDownLatch, final Runnable beforeDestroyRunnable) {
        session.destroy();
        threadPool.execute(() -> {
            if (beforeDestroyRunnable != null) {
                beforeDestroyRunnable.run();
            }
            if (session.cameraInfo.camera != null) {
                try {
                    session.cameraInfo.camera.stopPreview();
                    session.cameraInfo.camera.setPreviewCallbackWithBuffer(null);
                } catch (Exception e) {
                    FileLog.e(e);
                }
                try {
                    session.cameraInfo.camera.release();
                } catch (Exception e) {
                    FileLog.e(e);
                }
                session.cameraInfo.camera = null;
            }
            if (countDownLatch != null) {
                countDownLatch.countDown();
            }
        });
        if (countDownLatch != null) {
            try {
                countDownLatch.await();
            } catch (Exception e) {
                FileLog.e(e);
            }
        }
    }

    public ArrayList<CameraInfo> getCameras() {
        return cameraInfos;
    }

    private static int getOrientation(byte[] jpeg) {
        if (jpeg == null) {
            return 0;
        }

        int offset = 0;
        int length = 0;

        while (offset + 3 < jpeg.length && (jpeg[offset++] & 0xFF) == 0xFF) {
            int marker = jpeg[offset] & 0xFF;

            if (marker == 0xFF) {
                continue;
            }
            offset++;

            if (marker == 0xD8 || marker == 0x01) {
                continue;
            }
            if (marker == 0xD9 || marker == 0xDA) {
                break;
            }

            length = pack(jpeg, offset, 2, false);
            if (length < 2 || offset + length > jpeg.length) {
                return 0;
            }

            // Break if the marker is EXIF in APP1.
            if (marker == 0xE1 && length >= 8 &&
                    pack(jpeg, offset + 2, 4, false) == 0x45786966 &&
                    pack(jpeg, offset + 6, 2, false) == 0) {
                offset += 8;
                length -= 8;
                break;
            }

            offset += length;
            length = 0;
        }

        if (length > 8) {
            int tag = pack(jpeg, offset, 4, false);
            if (tag != 0x49492A00 && tag != 0x4D4D002A) {
                return 0;
            }
            boolean littleEndian = (tag == 0x49492A00);

            int count = pack(jpeg, offset + 4, 4, littleEndian) + 2;
            if (count < 10 || count > length) {
                return 0;
            }
            offset += count;
            length -= count;

            count = pack(jpeg, offset - 2, 2, littleEndian);
            while (count-- > 0 && length >= 12) {
                tag = pack(jpeg, offset, 2, littleEndian);
                if (tag == 0x0112) {
                    int orientation = pack(jpeg, offset + 8, 2, littleEndian);
                    switch (orientation) {
                        case 1:
                            return 0;
                        case 3:
                            return 180;
                        case 6:
                            return 90;
                        case 8:
                            return 270;
                    }
                    return 0;
                }
                offset += 12;
                length -= 12;
            }
        }
        return 0;
    }

    private static int pack(byte[] bytes, int offset, int length, boolean littleEndian) {
        int step = 1;
        if (littleEndian) {
            offset += length - 1;
            step = -1;
        }

        int value = 0;
        while (length-- > 0) {
            value = (value << 8) | (bytes[offset] & 0xFF);
            offset += step;
        }
        return value;
    }

    public void startPreview(final CameraSession session) {
        if (session == null) {
            return;
        }
        threadPool.execute(() -> {
            Camera camera = session.cameraInfo.camera;
            try {
                if (camera == null) {
                    camera = session.cameraInfo.camera = Camera.open(session.cameraInfo.cameraId);
                }
                camera.startPreview();
            } catch (Exception e) {
                session.cameraInfo.camera = null;
                if (camera != null) {
                    camera.release();
                }
                FileLog.e(e);
            }
        });
    }

    public void stopPreview(final CameraSession session) {
        if (session == null) {
            return;
        }
        threadPool.execute(() -> {
            Camera camera = session.cameraInfo.camera;
            try {
                if (camera == null) {
                    camera = session.cameraInfo.camera = Camera.open(session.cameraInfo.cameraId);
                }
                camera.stopPreview();
            } catch (Exception e) {
                session.cameraInfo.camera = null;
                if (camera != null) {
                    camera.release();
                }
                FileLog.e(e);
            }
        });
    }

    public void openRound(final CameraSession session, final SurfaceTexture texture, final Runnable callback, final Runnable configureCallback) {
        if (session == null || texture == null) {
            if (BuildVars.LOGS_ENABLED) {
                FileLog.d("failed to open round " + session + " tex = " + texture);
            }
            return;
        }
        threadPool.execute(() -> {
            Camera camera = session.cameraInfo.camera;
            try {
                if (BuildVars.LOGS_ENABLED) {
                    FileLog.d("start creating round camera session");
                }
                if (camera == null) {
                    camera = session.cameraInfo.camera = Camera.open(session.cameraInfo.cameraId);
                }
                Camera.Parameters params = camera.getParameters();

                session.configureRoundCamera();
                if (configureCallback != null) {
                    configureCallback.run();
                }
                camera.setPreviewTexture(texture);
                camera.startPreview();
                if (callback != null) {
                    AndroidUtilities.runOnUIThread(callback);
                }
                if (BuildVars.LOGS_ENABLED) {
                    FileLog.d("round camera session created");
                }
            } catch (Exception e) {
                session.cameraInfo.camera = null;
                if (camera != null) {
                    camera.release();
                }
                FileLog.e(e);
            }
        });
    }

    public void open(final CameraSession session, final SurfaceTexture texture, final Runnable callback, final Runnable prestartCallback) {
        if (session == null || texture == null) {
            return;
        }
        threadPool.execute(() -> {
            Camera camera = session.cameraInfo.camera;
            try {
                if (camera == null) {
                    camera = session.cameraInfo.camera = Camera.open(session.cameraInfo.cameraId);
                }
                Camera.Parameters params = camera.getParameters();
                List<String> rawFlashModes = params.getSupportedFlashModes();

                availableFlashModes.clear();
                if (rawFlashModes != null) {
                    for (int a = 0; a < rawFlashModes.size(); a++) {
                        String rawFlashMode = rawFlashModes.get(a);
                        if (rawFlashMode.equals(Camera.Parameters.FLASH_MODE_OFF) || rawFlashMode.equals(Camera.Parameters.FLASH_MODE_ON) || rawFlashMode.equals(Camera.Parameters.FLASH_MODE_AUTO)) {
                            availableFlashModes.add(rawFlashMode);
                        }
                    }
                    session.checkFlashMode(availableFlashModes.get(0));
                }

                if (prestartCallback != null) {
                    prestartCallback.run();
                }

                session.configurePhotoCamera();
                camera.setPreviewTexture(texture);
                camera.startPreview();
                if (callback != null) {
                    AndroidUtilities.runOnUIThread(callback);
                }
            } catch (Exception e) {
                session.cameraInfo.camera = null;
                if (camera != null) {
                    camera.release();
                }
                FileLog.e(e);
            }
        });
    }

    public static Size chooseOptimalSize(List<Size> choices, int width, int height, Size aspectRatio) {
        List<Size> bigEnough = new ArrayList<>();
        int w = aspectRatio.getWidth();
        int h = aspectRatio.getHeight();
        for (int a = 0; a < choices.size(); a++) {
            Size option = choices.get(a);
            if (option.getHeight() == option.getWidth() * h / w && option.getWidth() >= width && option.getHeight() >= height) {
                bigEnough.add(option);
            }
        }
        if (bigEnough.size() > 0) {
            return Collections.min(bigEnough, new CompareSizesByArea());
        } else {
            return Collections.max(choices, new CompareSizesByArea());
        }
    }

    static class CompareSizesByArea implements Comparator<Size> {
        @Override
        public int compare(Size lhs, Size rhs) {
            return Long.signum((long) lhs.getWidth() * lhs.getHeight() - (long) rhs.getWidth() * rhs.getHeight());
        }
    }
}
