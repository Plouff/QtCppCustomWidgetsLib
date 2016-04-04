#ifndef HISTOGRAMCALCULATOR_H
#define HISTOGRAMCALCULATOR_H

#include <QObject>
#include <QVector>

#include "opencv2/opencv.hpp"

#include "histogramtypes.h"

class HistogramCalculator : public QObject
{
    Q_OBJECT
public:
    explicit HistogramCalculator(
            cv::Mat *pMat,
            helper::histMats_s *phistMatRaw,
            helper::histMats_s *phistMatNormalizes,
            helper::histGraphs_s<double> * pHistGraphs,
            QObject *parent = nullptr);

    ~HistogramCalculator();
    void configure(int pBins = 256, float pRange[2] = nullptr);
    void computeHist();
    void normalizeHists();
    void displayHists();

protected:
    cv::Mat *mat;
    helper::histMats_s *histMatRaw;
    helper::histMats_s *histMatNormalized;
    helper::histGraphs_s<double> *histGraphs;

    int bins;
    float histRange[2];
//    float constHistRange[2];
    bool uniform;
    bool accumulate;
    bool configured;

    void displayHist(cv::Mat pHist);

    template <typename T>
    void matBins2QVector(const cv::Mat &pHist, QVector<T> &x, QVector<T> &y);
signals:

public slots:
};

#endif // HISTOGRAMCALCULATOR_H
