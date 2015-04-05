#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T12:37:11
#
#-------------------------------------------------

##################################################
# GENERAL CONFIG #################################
##################################################

QT       += core gui widgets testlib printsupport

TARGET = QtCppCustomWidgets
TEMPLATE = app
#TEMPLATE = lib
#CONFIG += staticlib

# C++11 support
CONFIG += c++11


##################################################
# OPENCV LIB #####################################
##################################################
INCLUDEPATH += "D:/Developpements/Cpp/ExternalCppLibs/opencv-mingw/release/include"

LIBS += -L"D:/Developpements/Cpp/ExternalCppLibs/opencv-mingw/release/x64/mingw/lib"
#LIBS += -lopencv_core300 -lopencv_highgui300 -lopencv_imgproc300

LIBS += -lopencv_core300 \
#        -lopencv_features2d300 \
#        -lopencv_flann300 \
        -lopencv_highgui300 \
        -lopencv_imgcodecs300 \
        -lopencv_imgproc300 \
#        -lopencv_ml300 \
#        -lopencv_objdetect300 \
#        -lopencv_photo300 \
#        -lopencv_shape300 \
#        -lopencv_stitching300\
#        -lopencv_superres300 \
#        -lopencv_ts300 \
#        -lopencv_video300 \
#        -lopencv_videoio300\
#        -lopencv_videostab300

##################################################

##################################################
# PROJECT SRC ####################################
##################################################

INCLUDEPATH += ../../QtExternalLibs/qcustomplot \
    PicHistogramManager \
    PicHistogramManager/SingleHistogram \
    Shared

SOURCES += main.cpp \
    qtcppcustomwidgets.cpp \
    ../../QtExternalLibs/qcustomplot/qcustomplot.cpp \
    PicHistogramManager/pichistogrammanager.cpp \
    PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.cpp \
    PicHistogramManager/SingleHistogram/singlehistogram.cpp \
    PicHistogramManager/SingleHistogram/histowitheditboxes.cpp \
    PicHistogramManager/SingleHistogram/fillcolorbehav.cpp \
    PicViewerWithHistUpdates/picviewerwithhistupdates.cpp \
    smalldemos.cpp \
    Shared/openglpicviewer.cpp \
    Shared/glpicviewerwithcommands.cpp \
    Shared/opencvglpicviewer.cpp



HEADERS += qtcppcustomwidgets.h \
    ../../QtExternalLibs/qcustomplot/qcustomplot.h \
    PicHistogramManager/pichistogrammanager.h \
    PicHistogramManager/SingleHistogram/singlehistogram.h \
    PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.h \
    PicHistogramManager/SingleHistogram/histowitheditboxes.h \
    PicHistogramManager/SingleHistogram/fillcolorbehav.h \
    PicViewerWithHistUpdates/picviewerwithhistupdates.h \
    Shared/openglpicviewer.h \
    debugmacros.h \
    Shared/glpicviewerwithcommands.h \
    Shared/opencvglpicviewer.h \
    Shared/opencvhelpers.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    PicHistogramManager/SingleHistogram/singlehistogram.ui \
    PicHistogramManager/SingleHistogram/histowitheditboxes.ui \
    PicHistogramManager/pichistogram.ui \
    PicViewerWithHistUpdates/picviewerwithhistupdates.ui \
    Shared/glpicviewerwithcommands.ui

