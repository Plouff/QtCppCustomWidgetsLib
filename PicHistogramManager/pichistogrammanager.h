#ifndef PICHISTOGRAM_H
#define PICHISTOGRAM_H

#include <QWidget>
//#include "qcustomplot.h"

#include "fillcolorbehav.h"
#include "histogramcalculator.h"
#include "histowitheditboxes.h"

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
    void setHist(const HistogramCalculator *hist);

signals:

public slots:

protected:
    GrayFiller * grayFiller;
    RedFiller * redFiller;
    GreenFiller * greenFiller;
    BlueFiller * blueFiller;

private:
    Ui::PicHistogram *ui;
    HistoWithEditboxes *rgbHist;
    HistoWithEditboxes *redHist;
    HistoWithEditboxes *greenHist;
    HistoWithEditboxes *blueHist;
};

#endif // PICHISTOGRAM_H
