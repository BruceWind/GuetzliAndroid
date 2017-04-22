
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


void printD(char *str,const char *str2)
{
    LOGD("%s", strcat(str,str2));
}

void printD(char *str,const char *str2,const char *str3)
{
    str=strcat(str,str2);
    str=strcat(str,str3);
    LOGD("%s", str);
}


void printI(const char *str)
{
    LOGI("%s", str);
}


void printI(char *str,const char *str2)
{
    LOGI("%s", strcat(str,str2));
}

void printE(const char *str)
{
    LOGE("%s", str);
}


void printE(char *str,const char *str2)
{
    LOGE("%s", strcat(str,str2));
}

}