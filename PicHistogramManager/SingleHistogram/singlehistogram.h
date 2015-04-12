#ifndef SINGLEHISTOGRAM_H
#define SINGLEHISTOGRAM_H

#include "qcustomplot.h"
#include "fillcolorbehav.h"

class QCPXOneDirSlidingRect;

class SingleHistogram : public QCustomPlot
{
    Q_OBJECT
public:
    explicit SingleHistogram(QWidget *parent = 0);
    ~SingleHistogram();
    void updateCoord(QCPXOneDirSlidingRect *rect, int newCoord);
    int getUserInputMin();
    int getUserInputMax();
    void updateRectFill(FillColorBehav &prectFiller);

signals:
    void newMinFromHist(int min);
    void newMaxFromHist(int max);

public slots:
    void setUserInputMin(int value);
    void setUserInputMax(int value);

protected:
    void initPlot();
    void initBorders();
    void fillBorders(QCPXOneDirSlidingRect *leftRect, QCPXOneDirSlidingRect *rightRect);
    QCPXOneDirSlidingRect * leftRect;
    QCPXOneDirSlidingRect * rightRect;
    int leftBorderCoord;
    int rightBorderCoord;
    FillColorBehav * rectFiller;

private slots:

};

#endif // SINGLEHISTOGRAM_H
