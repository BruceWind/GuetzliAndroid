package com.androidyuan.compress;

/**
 * Copyright (c) 2016. BiliBili Inc.
 * Created by wei on 17-4-10 ,email:602807247@qq.com
 */

public class CompressJNI {

    static {
        System.loadLibrary("guetzli");
    }


    native public static int compress(String in,String out);


}
