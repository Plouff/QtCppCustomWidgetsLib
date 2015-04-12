#ifndef PICHISTOGRAM_H
#define PICHISTOGRAM_H

#include <QWidget>
//#include "qcustomplot.h"

#include "fillcolorbehav.h"

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

signals:

public slots:

protected:
    GrayFiller * grayFiller;
    RedFiller * redFiller;
    GreenFiller * greenFiller;
    BlueFiller * blueFiller;

private:
    Ui::PicHistogram *ui;
};

#endif // PICHISTOGRAM_H
