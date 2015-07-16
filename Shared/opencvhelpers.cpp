#include "opencvhelpers.h"


namespace OCVhelpers {

void histMat2QVector(const cv::Mat * mat, QVector<double> &vect){
    assert(mat);
    assert(&vect != nullptr);
    cv::MatConstIterator_<double> it = mat->begin<double>();
    cv::MatConstIterator_<double> it_end = mat->end<double>();
    for(; it != it_end; ++it)
        vect.append(*it);
}

}
