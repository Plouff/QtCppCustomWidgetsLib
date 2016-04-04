#ifndef HISTOGRAMTYPES_H
#define HISTOGRAMTYPES_H

#include <QVector>

#include "opencv2/opencv.hpp"

namespace helper
{

/// A structure of RGB histograms
struct histMats_s
{
    /// The red histogram
    cv::Mat red;
    /// The blue histogram
    cv::Mat blue;
    /// The green histogram
    cv::Mat green;
};

/// A generic X Y coordinates structure
template <typename T>
struct coord_s
{
    /// X coordinates vector
    QVector<T> x;
    /// Y coordinates vector
    QVector<T> y;
};

/// A structure for histograms represented as QVector of type T
template <typename T>
struct histGraphs_s
{
    /// X Y coordinates of red histogram
    coord_s<T> red;
    /// X Y coordinates of green histogram
    coord_s<T> green;
    /// X Y coordinates of blue histogram
    coord_s<T> blue;
};

}


#endif // HISTOGRAMTYPES_H
