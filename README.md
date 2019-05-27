[中文](https://github.com/BruceWind/GuetzliAndroid/blob/master/README_zh.md)

# GuetzliAndroid
-----------------------------------------
As you can see, Guetzli is currently in the first release and the performance is poor.


 - [x] has imported libpng libjpeg dependencies and compiled.
 - [x] Test compression png is available.
 - [x] Display some uncompressible causes in the log.
 - [x] libgpng code modification allows ndk to compile arm64-v8a packages.



But in the future it will definitely be the best image compression tool.
The git repository, memory consumption is in native memory, not in the JVM stack, so don't worry about OOM, the memory is smaller than the Android official compression algorithm.

This library is of great significance in cases where only 64M of memory can be applied to some devices.

It can do lossless compression,and ultra-high compression ratio,and ultra-light file size.


the library has issues:

1. Can not compress BMP, BMP format is special, please refer to the BMP format document, this format must not be compressed. It will not be compressed in the future.

2. Some images cannot be compressed due to color, or non-compliance with specifications, etc., and the officially released packaged x64 version cannot be compressed.

3. Compression takes too long, this problem, I have been tested, I took the official code without modification, directly compile and run the test on the raspberry pie arm64 machine, the result is the same, it takes a long time, the big picture is generally It takes more than 3 minutes.


In summary, some of the problems I encountered in running this code are not changed by me. The official code also exists.
So, if you encounter similar problems, don't rush to mention issues, first build the official version.


## Future
Since Google released the 1.0 version, it will definitely solve the complicated problems. We hope that in the future, this library can have a low error rate, so it will be well transplanted to the mobile platform.


[https://github.com/google/guetzli/releases](https://github.com/google/guetzli/releases)



## A compromise between performance and memory issues

Guetzli's design does not consider CPU performance, as much as possible to ensure the high pressure and high quality of the picture, so: it is more suitable for a server.
If you have to put it on the mobile side: I recommend another repository: [OperatingImageBypassDalvik](https://github.com/weizongwei5/OperatingImageBypassDalvik), this library will take into account both OOM issues and CPU time-consuming issues.