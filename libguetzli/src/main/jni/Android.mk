LOCAL_PATH := $(call my-dir)

#链接静态库 jpeg
include $(CLEAR_VARS)
LOCAL_MODULE := jpeg
LOCAL_SRC_FILES := jpeg//libjpeg.a
include $(PREBUILT_STATIC_LIBRARY)

LOCAL_STATIC_LIBRARIES += jpeg


include $(CLEAR_VARS)

LOCAL_MODULE    := libguetzli
LOCAL_SRC_FILES := guetzli.cc           \
                   gamma_correct.h       jpeg_huffman_decode.cc\
                   jpeg_huffman_decode.h \
                   butteraugli_comparator.cc \ idct.cc    \           order.inc \
                   butteraugli_comparator.h   idct.h                output_image.cc \
                   color_transform.h         jpeg_bit_writer.h     output_image.h \
                   comparator.h               jpeg_data.cc          preprocess_downsample.cc \
                   dct_double.cc              jpeg_data_decoder.cc  preprocess_downsample.h \
                   dct_double.h               jpeg_data_decoder.h   processor.cc \
                   debug_print.cc             jpeg_data_encoder.cc  processor.h \
                   debug_print.h              jpeg_data_encoder.h   quality.cc \
                   entropy_encode.cc          jpeg_data.h           quality.h \
                   entropy_encode.h           jpeg_data_reader.cc   quantize.cc \
                   fast_log.h                jpeg_data_reader.h    quantize.h \
                   fdct.cc                    jpeg_data_writer.cc   score.cc \
                   fdct.h                    jpeg_data_writer.h   score.h \
                   gamma_correct.cc           jpeg_error.h          stats.h \
                   butteraugli/butteraugli.cc   \
                   butteraugli/butteraugli.h    \
                   butteraugli/butteraugli_main.cc  \
                     png/config.h    \
                     png/png.c    \
                     png/pngconf.h    \
                     png/pngdebug.h    \
                     png/pngerror.c    \
                     png/pngget.c    \
                     png/png.h    \
                     png/pnginfo.h    \
                     png/pnglibconf.h    \
                     png/pngmem.c    \
                     png/pngpread.c    \
                     png/pngprefix.h    \
                     png/pngpriv.h    \
                     png/pngread.c    \
                     png/pngrio.c    \
                     png/pngrtran.c    \
                     png/pngrutil.c    \
                     png/pngset.c    \
                     png/pngstruct.h    \
                     png/pngtest.c    \
                     png/pngtrans.c    \
                     png/pngwio.c    \
                     png/pngwrite.c    \
                     png/pngwtran.c    \
                    png/pngwutil.c






# -lz
LOCAL_SHARED_LIBRARIES +=  -lpng -ljpeg

LOCAL_C_INCLUDES += $(LOCAL_PATH)/png  jpeg/include
# LOCAL_STATIC_LIBRARIES := libpng


LOCAL_LDLIBS    := -llog -lz


LOCAL_CPPFLAGS  += -std=c99
LOCAL_CPPFLAGS += -std=c++11



include $(BUILD_SHARED_LIBRARY)

# include $(BUILD_EXECUTABLE)
