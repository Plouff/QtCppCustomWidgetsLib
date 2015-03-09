#include "pichistogrammanager.h"
#include "singlehistogram.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    PicHistogramManager histmgr;
    SingleHistogram hist;

    histmgr.show();
    hist.show();

    return app.exec();
}

