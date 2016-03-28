##################################################
# PROJECT SRC ####################################
##################################################
QT       += testlib printsupport

DEPENDPATH+= $$PWD

INCLUDEPATH += \
    $$PWD \
    $$PWD/PicHistogramManager \
    $$PWD/PicHistogramManager/SingleHistogram \
    $$PWD/Shared

SOURCES += \
    $$PWD/PicHistogramManager/pichistogrammanager.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/singlehistogram.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/histowitheditboxes.cpp \
    $$PWD/PicHistogramManager/SingleHistogram/fillcolorbehav.cpp \
    $$PWD/PicViewerWithHistUpdates/picviewerwithhistupdates.cpp \
    $$PWD/PicHistogramManager/histogramcalculator.cpp



HEADERS += \
    $$PWD/PicHistogramManager/pichistogrammanager.h \
    $$PWD/PicHistogramManager/SingleHistogram/singlehistogram.h \
    $$PWD/PicHistogramManager/SingleHistogram/qcpxonedirslidingrect.h \
    $$PWD/PicHistogramManager/SingleHistogram/histowitheditboxes.h \
    $$PWD/PicHistogramManager/SingleHistogram/fillcolorbehav.h \
    $$PWD/PicViewerWithHistUpdates/picviewerwithhistupdates.h \
    $$PWD/PicHistogramManager/histogramcalculator.h \
    $$PWD/debugmacros.h


FORMS += \
    $$PWD/PicHistogramManager/SingleHistogram/singlehistogram.ui \
    $$PWD/PicHistogramManager/SingleHistogram/histowitheditboxes.ui \
    $$PWD/PicHistogramManager/pichistogram.ui \
    $$PWD/PicViewerWithHistUpdates/picviewerwithhistupdates.ui

# Add sub projects
include($$PWD/Shared/shared.pri)
include($$PWD/QCustomPlot/qcustomplot.pri)

