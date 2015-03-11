#include "pichistogrammanager.h"
#include "singlehistogram.h"
#include "histowitheditboxes.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    PicHistogramManager histmgr;
    SingleHistogram hist;
    HistoWithEditboxes histBoxed;


//    histmgr.show();
//    hist.show();
    histBoxed.show();

    return app.exec();
}

