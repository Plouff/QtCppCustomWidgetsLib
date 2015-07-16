#ifndef HISTOGRAMCALCULATOR_H
#define HISTOGRAMCALCULATOR_H

#include <QObject>
#include <QVector>

#include "opencv2/opencv.hpp"

class HistogramCalculator : public QObject
{
    Q_OBJECT
public:
    explicit HistogramCalculator(
            cv::Mat * pMat = nullptr,
            QObject *parent = nullptr);
    ~HistogramCalculator();
    void configure(int pBins = 256, float pRange[2] = nullptr);
    void computeHist();
    void normalizeHists();
    void displayHists();
    QVector<double> redX, redY, greenX, greenY, blueX, blueY;

protected:
    cv::Mat * mat;
    cv::Mat bHist, gHist, rHist;
    cv::Mat bHistNorm, gHistNorm, rHistNorm;
    std::vector<cv::Mat> bgrPlanes;

    int bins;
    float histRange[2];
//    float constHistRange[2];
    bool uniform;
    bool accumulate;
    bool configured;

    void displayHist(cv::Mat pHist);
    void matBins2QVector(
            const cv::Mat &pHist, QVector<double> &x, QVector<double> &y);
signals:

public slots:
};

#endif // HISTOGRAMCALCULATOR_H
