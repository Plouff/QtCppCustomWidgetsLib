#include "histogramcalculator.h"

#include "assert.h"

// Source:
// http://docs.opencv.org/doc/tutorials/imgproc/histograms/histogram_calculation/histogram_calculation.html

HistogramCalculator::HistogramCalculator(cv::Mat * pMat, QObject *parent) :
    QObject(parent), mat(pMat)
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
    assert(configured);

    // Separate the image in 3 places (B, G and R)
    cv::split(*mat, bgrPlanes);

    const float* constHistRange = { histRange };
    cv::calcHist(&bgrPlanes[0], 1, 0, cv::Mat(), bHist, 1, &bins,
            &constHistRange, uniform, accumulate);
    cv::calcHist(&bgrPlanes[1], 1, 0, cv::Mat(), gHist, 1, &bins,
            &constHistRange, uniform, accumulate );
    cv::calcHist(&bgrPlanes[2], 1, 0, cv::Mat(), rHist, 1, &bins,
            &constHistRange, uniform, accumulate );

    // Normalize histograms (avoid finding a maximum and scaling the plot)
    normalizeHists();

    // Convert the RGB planes into Qvector
    matBins2QVector(rHistNorm, redX, redY);
    matBins2QVector(gHistNorm, greenX, greenY);
    matBins2QVector(bHistNorm, blueX, blueY);
}

void HistogramCalculator::normalizeHists()
{
    cv::normalize(bHist, bHistNorm, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(gHist, gHistNorm, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(rHist, rHistNorm, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
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
    displayHist(bHist);
    displayHist(gHist);
    displayHist(rHist);
    std::cout << std::flush;
}

void HistogramCalculator::matBins2QVector(
        const cv::Mat &pHist, QVector<double> &x, QVector<double> &y)
{
    cv::MatConstIterator_<float> it, end;
    int i = 0;

    for( it = pHist.begin<float>(), end = pHist.end<float>(); it != end;
         ++it, i++)
    {
        x.append(i);
        y.append((double) *it); // TODO: convert float in double
        // Or try float directly
    }
}
