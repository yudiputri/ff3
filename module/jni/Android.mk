LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := zygisk_module
LOCAL_SRC_FILES := module.cpp
LOCAL_STATIC_LIBRARIES := libc++
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)
