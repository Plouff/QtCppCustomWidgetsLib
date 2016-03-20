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

INCLUDEPATH +=

SOURCES += main.cpp \
    qtcppcustomwidgets.cpp

HEADERS += qtcppcustomwidgets.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS +=

# Add sub projects
include(QtCppCustomWidgets.pri)


