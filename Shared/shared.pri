INCLUDEPATH += $$PWD
DEPENDPATH+= $$PWD

SOURCES += $$PWD/openglpicviewer.cpp \
    $$PWD/glpicviewerwithcommands.cpp \
    $$PWD/topixmapconverter.cpp \
    $$PWD/opencvhelpers.cpp

HEADERS += Shared/openglpicviewer.h \
    $$PWD/glpicviewerwithcommands.h \
    $$PWD/opencvhelpers.h \
    $$PWD/topixmapconverter.h \

FORMS += \
    $$PWD/glpicviewerwithcommands.ui


