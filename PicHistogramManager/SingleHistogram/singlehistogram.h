#ifndef SINGLEHISTOGRAM_H
#define SINGLEHISTOGRAM_H

#include "qcustomplot.h"
#include "opencv2/opencv.hpp"

#include "fillcolorbehav.h"
#include "histogramcalculator.h"

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
    void updateRectFill(FillerInterface &prectFiller);
    void displayMat(cv::Mat * pMat, int numPoints);

    // Friend functions
//    friend void OCVhelpers::histMat2QVector(const cv::Mat * mat,
//                                            QVector<double> &vect);

    void setHist(const helper::coord_s<double> *histCoords);

signals:
    void newMinFromHist(int min);
    void newMaxFromHist(int max);

public slots:
    void setUserInputMin(int value);
    void setUserInputMax(int value);

protected:
    void initPlot();
    void initBorders();
    void fillBorders(QCPXOneDirSlidingRect *leftRect,
                     QCPXOneDirSlidingRect *rightRect);
    QCPXOneDirSlidingRect * leftRect;
    QCPXOneDirSlidingRect * rightRect;
    int leftBorderCoord;
    int rightBorderCoord;
    FillerInterface * rectFiller;

    QVector<double> x;
    QVector<double> y;

private slots:

};

#endif // SINGLEHISTOGRAM_H
