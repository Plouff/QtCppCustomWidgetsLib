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
    rgbHistViewer = ui->rgbHist;
    redHistViewer = ui->redHist;
    greenHistViewer = ui->greenHist;
    blueHistViewer = ui->blueHist;

    grayFiller = new GrayFiller ();
    rgbHistViewer->updateRectFill(*grayFiller);

    redFiller = new RedFiller();
    redHistViewer->updateRectFill(*redFiller);

    greenFiller = new GreenFiller();
    greenHistViewer->updateRectFill(*greenFiller);

    blueFiller = new BlueFiller();
    blueHistViewer->updateRectFill(*blueFiller);
}

void PicHistogramManager::setHist(const helper::histGraphs_s<double> *hists)
{
//    rgbHist->updateRectFill(*grayFiller);
    redHistViewer->setHist(&hists->red);
    greenHistViewer->setHist(&hists->green);
    blueHistViewer->setHist(&hists->blue);
}

PicHistogramManager::~PicHistogramManager()
{
    delete ui;
    delete grayFiller;
    delete redFiller;
    delete greenFiller;
    delete blueFiller;
}

