LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ksu_surfaceflinger_guard
LOCAL_SRC_FILES := \
    ksu_module.c \
    sf_tuner.c \
    thermal_guard.c

include $(BUILD_KERNELSU_MODULE)