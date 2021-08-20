QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Image_Processing.cpp \
    Input_Output.cpp \
    ipmainwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Image_Processing.hpp \
    Input_Output.hpp \
    ipmainwindow.h \
    mainwindow.h

FORMS += \
    ipmainwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


INCLUDEPATH += C:\Users\aktas\opencv_3.2\opencv\build\include

LIBS += C:\Users\aktas\opencv-build\bin\libopencv_core320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_highgui320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_imgcodecs320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_imgproc320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_features2d320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_calib3d320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_video320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_videoio320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_features2d320.dll.a
LIBS += C:\Users\aktas\opencv-build\bin\libopencv_flann320.dll.a

