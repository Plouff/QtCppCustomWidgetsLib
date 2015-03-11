#ifndef SINGLEHISTOGRAM_H
#define SINGLEHISTOGRAM_H

#include "qcustomplot.h"

class QCPXOneDirSlidingRect;

class SingleHistogram : public QCustomPlot
{
    Q_OBJECT
public:
    explicit SingleHistogram(QWidget *parent = 0);
    ~SingleHistogram();
    void updateCoord(QCPXOneDirSlidingRect *rect, int newCoord);
    int getMin();
    int getMax();

signals:
    void newMinFromHist(int min);
    void newMaxFromHist(int max);

public slots:

private:
    void initPlot();
    void initBorders();
    void initBorder(QCPXOneDirSlidingRect *rect);
    QCPXOneDirSlidingRect * leftRect;
    QCPXOneDirSlidingRect * rightRect;
    int leftBorderCoord;
    int rightBorderCoord;

private slots:

};

#endif // SINGLEHISTOGRAM_H
