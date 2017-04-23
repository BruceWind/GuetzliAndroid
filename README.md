# GuetzliAndroid


 - [x] 已经导入 libpng libjpeg 依赖  并编译通过
 - [x] 测试压缩png可用.
 - [x] 把一些无法压缩的原因，在日志中显示出来。
 - [ ] libgpng 无法在arm64-v8a上编译。




如你所见，Guetzli目前处于第一版发布，性能不好，有些情况压缩出现失败的情况。等等问题。
但是未来的趋势他必然成为一个跨平台的最好的图片压缩工具.
[https://github.com/google/guetzli/releases](https://github.com/google/guetzli/releases)

目前这个库存在的问题：

1.不能压缩BMP，BMP格式比较特殊，请查阅BMP这个格式的文档，这个格式肯定不可被压缩。以后也不会被压缩。
2.部分图片因为色彩，或者不遵守规范等等其他原因，无法压缩，经过测试在官方发布的打包好的x64的版本也无法被压缩。
3.压缩耗时太长了，这个问题，我经过测试，我拿官方代码在树莓派这个arm64机器上跑了测试，结果一样的，耗时也很久，大图一般都要3分钟以上。

## 期待
谷歌既然发布了1.0版本，后面肯定会修复杂七杂八的问题，我们期待，未来，这个库可以很好的性能，和很低的出错率，那么就会很好的移植到android平台上了。
毕竟他的内存消耗实在时低，跟android平台这种一个像素就2-4个字节的高效压缩方案比起来是高端很多。而且，他可以做无损压缩，超高的压缩比，超轻的文件大小，简直碉堡。

