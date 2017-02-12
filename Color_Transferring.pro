QT       += core gui
CONFIG += c++11

TARGET = Color_Transferring
TEMPLATE = app

SOURCES += lib_c/Malloc2D_dbl.c \
    lib_c/Malloc2D_uchr.c \
    lib_c/arry_smpl_create.c \
    lib_c/arry_smpl_destruct.c \
    lib_c/generate_regular_samples.c \
    lib_c/img_rgb_create.c \
    lib_c/img_rgb_destruct.c \
    lib_c/img_to_map_rgb.c \
    lib_c/map_create.c \
    lib_c/map_destruct.c \
    lib_c/map_rgb_create.c \
    lib_c/map_rgb_destruct.c \
    lib_c/map_rgb_to_yuv.c \
    lib_c/map_to_img_rgb.c \
    lib_c/map_yuv_create.c \
    lib_c/map_yuv_destruct.c \
    lib_c/map_yuv_set_mean_and_var.c \
    lib_c/map_yuv_to_rgb.c \
    lib_c/match_get_index.c \
    lib_c/source_luminance_remapping.c \
    lib_c/transfer_color.c \
    lib_qc/QImage_to_img_rgb.cpp \
    lib_qc/img_rgb_to_QImage.cpp \
    main.cpp

HEADERS  += include/image.h \
    include/image_qt.h
