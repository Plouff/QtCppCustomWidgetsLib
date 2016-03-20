INCLUDEPATH += $$PWD
DEPENDPATH+= $$PWD


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

INCLUDEPATH += \
    $$PWD/qCustomPlot \
    $$PWD/PicHistogramManager \
    $$PWD/PicHistogramManager/SingleHistogram \
    $$PWD/Shared

SOURCES += \
    $$PWD/qCustomPlot/qcustomplot.cpp \
    $$PWD/PicHistogramManager/pichistogrammanager.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/singlehistogram.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/histowitheditboxes.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/fillcolorbehav.cpp \
    $$PWD/PicViewerWithHistUpdates/picviewerwithhistupdates.cpp \
    $$PWD/PicHistogramManager/histogramcalculator.cpp

HEADERS += \
    $$PWD/qCustomPlot/qcustomplot.h \
    $$PWD/PicHistogramManager/pichistogrammanager.h \
    $$PWD/PicHistogramManager/SingleHistogram/singlehistogram.h \
    $$PWD/PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.h \
    $$PWD/PicHistogramManager/SingleHistogram/histowitheditboxes.h \
    $$PWD/PicHistogramManager/SingleHistogram/fillcolorbehav.h \
    $$PWD/PicViewerWithHistUpdates/picviewerwithhistupdates.h \
    $$PWD/debugmacros.h \
    $$PWD/PicHistogramManager/histogramcalculator.h

FORMS += \
    $$PWD/PicHistogramManager/SingleHistogram/singlehistogram.ui \
    $$PWD/PicHistogramManager/SingleHistogram/histowitheditboxes.ui \
    $$PWD/PicHistogramManager/pichistogram.ui \
    $$PWD/PicViewerWithHistUpdates/picviewerwithhistupdates.ui

# Add sub projects
include(Shared/shared.pri)
#include(Shared/helpers/helpers.pri)

