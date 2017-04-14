
#include <android/log.h>


#define LOG_TAG "JNILOG" // 这个是自定义的LOG的标识

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define CBC 1
#define ECB 1

namespace{

void printD(const char *str)
{
    LOGD("%s", str);
}


void printI(const char *str)
{
    LOGI("%s", str);
}


void printE(const char *str)
{
    LOGE("%s", str);
}

}