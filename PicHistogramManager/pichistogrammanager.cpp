#include "histowitheditboxes.h"
#include "pichistogrammanager.h"
#include "ui_pichistogram.h"
#include <iostream>
#include <typeinfo>

using namespace std;

PicHistogramManager::PicHistogramManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PicHistogram)
{
    // Initialize the UI
    ui->setupUi(this);
    initWidget();
}

void PicHistogramManager::initWidget()
{
    HistoWithEditboxes *rgbHist = ui->rgbHist;
    HistoWithEditboxes *redHist = ui->redHist;
    HistoWithEditboxes *greenHist = ui->greenHist;
    HistoWithEditboxes *blueHist = ui->blueHist;

    grayFiller = new GrayFiller ();
    rgbHist->updateRectFill(*grayFiller);

    redFiller = new RedFiller();
    redHist->updateRectFill(*redFiller);

    greenFiller = new GreenFiller();
    greenHist->updateRectFill(*greenFiller);

    blueFiller = new BlueFiller();
    blueHist->updateRectFill(*blueFiller);

    // Create a vector containing the histogram plots
//    HistoWithEditboxes *hists[4] = { rgbHist, redHist, greenHist, blueHist};

//    // generate some data:
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }
//    // create graph and assign data to it:
//    rgbHist->addGraph();
//    rgbHist->graph(0)->setData(x, y);
//    // give the axes some labels:
//    rgbHist->xAxis->setLabel("x");
//    rgbHist->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    rgbHist->xAxis->setRange(-1, 1);
//    rgbHist->yAxis->setRange(0, 1);
//    rgbHist->replot();


}

PicHistogramManager::~PicHistogramManager()
{
    delete ui;
    delete grayFiller;
    delete redFiller;
    delete greenFiller;
    delete blueFiller;
}

