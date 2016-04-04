#ifndef PICHISTOGRAM_H
#define PICHISTOGRAM_H

#include <QWidget>
//#include "qcustomplot.h"

#include "fillcolorbehav.h"
#include "histogramcalculator.h"
#include "histowitheditboxes.h"
#include "histogramtypes.h"

namespace Ui {
class PicHistogram;
}

class PicHistogramManager : public QWidget
{
    Q_OBJECT
public:
    explicit PicHistogramManager(QWidget *parent = 0);
    ~PicHistogramManager();
    void initWidget();
    void setHist(const helper::histGraphs_s<double> *hists);

signals:

public slots:

protected:
    GrayFiller * grayFiller;
    RedFiller * redFiller;
    GreenFiller * greenFiller;
    BlueFiller * blueFiller;

private:
    Ui::PicHistogram *ui;
    HistoWithEditboxes *rgbHistViewer;
    HistoWithEditboxes *redHistViewer;
    HistoWithEditboxes *greenHistViewer;
    HistoWithEditboxes *blueHistViewer;
};

#endif // PICHISTOGRAM_H
