#-------------------------------------------------
#
# Project created by QtCreator 2019-05-02T10:53:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib
LIBS += -lopencv_calib3d
LIBS += -lopencv_core
LIBS += -lopencv_features2d
LIBS += -lopencv_flann
LIBS += -lopencv_highgui
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_imgproc
LIBS += -lopencv_ml
LIBS += -lopencv_objdetect
LIBS += -lopencv_photo
LIBS += -lopencv_shape
LIBS += -lopencv_stitching
LIBS += -lopencv_superres
LIBS += -lopencv_video
LIBS += -lopencv_videoio
LIBS += -lopencv_videostab

CONFIG += c++11

SOURCES += \
        convdialog.cpp \
        main.cpp \
        mainwindow.cpp \
        meshellipse.cpp \
        meshscene.cpp \
        transdialog.cpp

HEADERS += \
        convdialog.h \
        mainwindow.h \
        meshellipse.h \
        meshscene.h \
        transdialog.h

FORMS += \
        convdialog.ui \
        mainwindow.ui \
        transdialog.ui

#CUDA_SOURCES = cuda_code.cu

CUDA_DIR = /usr/local/cuda-9.0
#CUDA_ARCH = sm_50

#INCLUDEPATH += $$CUDA_DIR/include
LIBS += -L $$CUDA_DIR/lib64 -lcudart -lcuda

#cuda.commands = $$CUDA_DIR/bin/nvcc -c -arch=$$CUDA_ARCH -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#cuda.dependency_type = TYPE_C
#cuda.depend_command = $$CUDA_DIR/bin/nvcc -M ${QMAKE_FILE_NAME}
#cuda.input = CUDA_SOURCES
#cuda.output = ${QMAKE_FILE_BASE}_cuda.o
#QMAKE_EXTRA_COMPILERS += cuda

#DISTFILES += cuda_code.cu

