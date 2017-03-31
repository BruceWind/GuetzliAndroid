

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Guetzli
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
			png\




LOCAL_STATIC_LIBRARIES := png

LOCAL_C_INCLUDES += $(LOCAL_PATH)/png

LOCAL_LDLIBS    := -llog


LOCAL_CPPFLAGS  += -std=c99
LOCAL_CPPFLAGS += -std=c++11


include $(BUILD_SHARED_LIBRARY)

# include $(BUILD_EXECUTABLE)
