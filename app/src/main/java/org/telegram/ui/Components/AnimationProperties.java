/*
 * This is the source code of Wallet for Android v. 1.0.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 * Copyright Nikolai Kudashov, 2019.
 */

package org.telegram.ui.Components;

import android.graphics.Paint;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.ShapeDrawable;
import android.util.Property;

import org.telegram.messenger.FileLog;

public class AnimationProperties {

    public static abstract class FloatProperty<T> extends Property<T, Float> {

        public FloatProperty(String name) {
            super(Float.class, name);
        }

        public abstract void setValue(T object, float value);

        @Override
        final public void set(T object, Float value) {
            setValue(object, value);
        }
    }

    public static abstract class IntProperty<T> extends Property<T, Integer> {

        public IntProperty(String name) {
            super(Integer.class, name);
        }

        public abstract void setValue(T object, int value);

        @Override
        final public void set(T object, Integer value) {
            setValue(object, value);
        }
    }

    public static final Property<Paint, Integer> PAINT_ALPHA = new IntProperty<Paint>("alpha") {
        @Override
        public void setValue(Paint object, int value) {
            object.setAlpha(value);
        }

        @Override
        public Integer get(Paint object) {
            return object.getAlpha();
        }
    };

    public static final Property<ColorDrawable, Integer> COLOR_DRAWABLE_ALPHA = new IntProperty<ColorDrawable>("alpha") {
        @Override
        public void setValue(ColorDrawable object, int value) {
            object.setAlpha(value);
        }

        @Override
        public Integer get(ColorDrawable object) {
            return object.getAlpha();
        }
    };

    public static final Property<ShapeDrawable, Integer> SHAPE_DRAWABLE_ALPHA = new IntProperty<ShapeDrawable>("alpha") {
        @Override
        public void setValue(ShapeDrawable object, int value) {
            object.getPaint().setAlpha(value);
        }

        @Override
        public Integer get(ShapeDrawable object) {
            return object.getPaint().getAlpha();
        }
    };

    /*public static final Property<ClippingImageView, Float> CLIPPING_IMAGE_VIEW_PROGRESS = new FloatProperty<ClippingImageView>("animationProgress") {
        @Override
        public void setValue(ClippingImageView object, float value) {
            object.setAnimationProgress(value);
        }

        @Override
        public Float get(ClippingImageView object) {
            return object.getAnimationProgress();
        }
    };

    public static final Property<PhotoViewer, Float> PHOTO_VIEWER_ANIMATION_VALUE = new FloatProperty<PhotoViewer>("animationValue") {
        @Override
        public void setValue(PhotoViewer object, float value) {
            object.setAnimationValue(value);
        }

        @Override
        public Float get(PhotoViewer object) {
            return object.getAnimationValue();
        }
    };*/
}
