package com.androidyuan.compress;

/**
 * Copyright (c) 2016. BiliBili Inc.
 * Created by wei on 17-4-10 ,email:602807247@qq.com
 *
 * =======guetzli client=============
 */

public class GuetzliClient {

    static GuetzliClient sGuetzliInstance;

    //生成者模式
    public static GuetzliClient build()
    {
        if(sGuetzliInstance==null)
        {
            sGuetzliInstance=new GuetzliClient();
        }
        return sGuetzliInstance;
    }

    public GuetzliClient(){
        System.loadLibrary("guetzli");
    }


    /**
     * 压缩图片仅仅支持 jpeg png 不支持 gif bmp
     * @param in
     * @param out
     * @return
     */
    public boolean compressIMG(String in,String out){
        return compress(in,out)==0;
    }


    /**
     *
     * @param in input img;
     * @param out out img;
     * @return 0:suc ,1:fail
     */
    native private static int compress(String in,String out);


}
