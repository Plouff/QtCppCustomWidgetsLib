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
    rgbHist = ui->rgbHist;
    redHist = ui->redHist;
    greenHist = ui->greenHist;
    blueHist = ui->blueHist;

    grayFiller = new GrayFiller ();
    rgbHist->updateRectFill(*grayFiller);

    redFiller = new RedFiller();
    redHist->updateRectFill(*redFiller);

    greenFiller = new GreenFiller();
    greenHist->updateRectFill(*greenFiller);

    blueFiller = new BlueFiller();
    blueHist->updateRectFill(*blueFiller);
}

void PicHistogramManager::setHist(const HistogramCalculator *hist)
{
//    rgbHist->updateRectFill(*grayFiller);
    redHist->setHist(hist->redX, hist->redY);
    greenHist->setHist(hist->greenX, hist->greenY);
    blueHist->setHist(hist->blueX, hist->blueY);
}

PicHistogramManager::~PicHistogramManager()
{
    delete ui;
    delete grayFiller;
    delete redFiller;
    delete greenFiller;
    delete blueFiller;
}

