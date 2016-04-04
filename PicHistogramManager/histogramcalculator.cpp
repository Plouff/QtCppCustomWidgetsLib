#include "histogramcalculator.h"

#include "assert.h"

// Source:
// http://docs.opencv.org/doc/tutorials/imgproc/histograms/histogram_calculation/histogram_calculation.html

HistogramCalculator::HistogramCalculator(cv::Mat *pMat,
        helper::histMats_s *phistMatRaw,
        helper::histMats_s *phistMatNormalized,
        helper::histGraphs_s<double> *pHistGraphs,
        QObject *parent) :
    QObject(parent),
    mat(pMat),
    histMatRaw(phistMatRaw),
    histMatNormalized(phistMatNormalized),
    histGraphs(pHistGraphs)
{
    configured = false;
    uniform = true;
    accumulate = false;
}

HistogramCalculator::~HistogramCalculator()
{
}

void HistogramCalculator::configure(int pBins, float pRange[2])
{
    bins = pBins;
    if (pRange == nullptr)
    {
        histRange[0] = 0;
        histRange[1] = bins; // defaults to 256
    }
    else
    {
        histRange[0] = pRange[0];
        histRange[1] = pRange[1];
    }
    configured = true;
}

void HistogramCalculator::computeHist()
{
    std::vector<cv::Mat> bgrPlanes;

    assert(configured);

    // Separate the image in 3 places (B, G and R)
    cv::split(*mat, bgrPlanes);

    const float* constHistRange = { histRange };

    cv::calcHist(&bgrPlanes[0], 1, 0, cv::Mat(), histMatRaw->blue, 1, &bins,
            &constHistRange, uniform, accumulate);
    cv::calcHist(&bgrPlanes[1], 1, 0, cv::Mat(), histMatRaw->green, 1, &bins,
            &constHistRange, uniform, accumulate );
    cv::calcHist(&bgrPlanes[2], 1, 0, cv::Mat(), histMatRaw->red, 1, &bins,
            &constHistRange, uniform, accumulate );

    // Normalize histograms (avoids finding a maximum and scaling the plot)
    normalizeHists();

    // Convert the RGB planes into Qvector
    matBins2QVector(histMatNormalized->red, histGraphs->red.x, histGraphs->red.y);
    matBins2QVector(histMatNormalized->green, histGraphs->green.x, histGraphs->green.y);
    matBins2QVector(histMatNormalized->blue, histGraphs->blue.x, histGraphs->blue.y);
}

void HistogramCalculator::normalizeHists()
{
    cv::normalize(histMatRaw->blue, histMatNormalized->blue, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(histMatRaw->green, histMatNormalized->green, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(histMatRaw->red, histMatNormalized->red, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
}

void HistogramCalculator::displayHist(cv::Mat pHist)
{
    cv::MatIterator_<float> it, end;
    int i = 0;
    for( it = pHist.begin<float>(), end = pHist.end<float>(); it != end;
         ++it, i++)
        printf("%0d;%0.0f\n", i, *it);
}


void HistogramCalculator::displayHists()
{
    displayHist(histMatRaw->red);
    displayHist(histMatRaw->green);
    displayHist(histMatRaw->blue);
    std::cout << std::flush;
}

template <typename T>
void HistogramCalculator::matBins2QVector(
        const cv::Mat &pHist, QVector<T> &x, QVector<T> &y)
{
    cv::MatConstIterator_<float> it, end;
    int i = 0;

    for( it = pHist.begin<float>(), end = pHist.end<float>(); it != end;
         ++it, i++)
    {
        x.append(i);
        y.append((T) *it);
        // Or try float directly
    }
}
