#include <jni.h>
#include <string.h>
#include <android/log.h>
#include "guetzli.cc"

#define LOG_TAG "JNILOG:" // 这个是自定义的LOG的标识

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define CBC 1
#define ECB 1


// 获取数组的大小
# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))
// 指定要注册的类，对应完整的java类名
#define JNIREG_CLASS "com/androidyuan/compress/CompressJNI"

const char *UNSIGNATURE = "UNSIGNATURE";


__attribute__((section (".mytext")))
JNIEXPORT jint JNICALL comps(JNIEnv *env, jobject instance, jstring j_input, jstring j_output) {



    const char *in = env->GetStringUTFChars( j_input, 0);
    const char *out = env->GetStringUTFChars(j_output, 0);

    int i = 0;
    LOGD("{%s}", in);

    LOGD("{%s}", out);

    //env->ReleaseStringUTFChars(j_output,0);//env,

    //env->ReleaseStringUTFChars(j_input,0);//env,

    return compressImg(in,out);;
}



//jstring charToJstring(JNIEnv *envPtr, char *src) {
//    JNIEnv env = *envPtr;
//
//    jsize len = strlen(src);
//    jclass clsstring = env->FindClass(envPtr, "java/lang/String");
//    jstring strencode = env->NewStringUTF(envPtr, "UTF-8");
//    jmethodID mid = env->GetMethodID(envPtr, clsstring, "<init>",
//                                     "([BLjava/lang/String;)V");
//    jbyteArray barr = env->NewByteArray(envPtr, len);
//    env->SetByteArrayRegion(envPtr, barr, 0, len, (jbyte *) src);
//
//    return (jstring) env->NewObject(envPtr, clsstring, mid, barr, strencode);
//}

// Java和JNI函数的绑定表
static JNINativeMethod method_table[] = {
        { "compress", "(Ljava/lang/String;Ljava/lang/String;)I", (void*)comps },
};

// 注册native方法到java中
static int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

int register_ndk_load(JNIEnv *env)
{
    // 调用注册方法
    return registerNativeMethods(env, JNIREG_CLASS,
                                 method_table, NELEM(method_table));
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    register_ndk_load(env);

    // 返回jni的版本
    return JNI_VERSION_1_4;
}

