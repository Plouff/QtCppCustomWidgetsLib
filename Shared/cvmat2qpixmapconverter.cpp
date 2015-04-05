#include "cvmat2qpixmapconverter.h"

#include "Shared/opencvhelpers.h"

cvMat2QPixmapConverter::cvMat2QPixmapConverter(QObject *parent) :
    QObject(parent)
{
    matPic = new cv::Mat();
}

cvMat2QPixmapConverter::~cvMat2QPixmapConverter()
{
    delete matPic;
}

QPixmap * cvMat2QPixmapConverter::convert(cv::Mat &pMat)
{
    matPic = &pMat;

    // Convert cv::Mat into a Qpixmap
    localPixMap = cvMatToQPixmap(pMat);

    return &localPixMap;
}

QPixmap *cvMat2QPixmapConverter::convertFromPath(cv::String const path)
{
    // Read picture in matPic
    *matPic = cv::imread(path, 1);

    // Convert cv::Mat into a Qpixmap
    localPixMap = cvMatToQPixmap(*matPic);

    return &localPixMap;
}

cv::Mat* cvMat2QPixmapConverter::getMatPic() const
{
    return matPic;
}

void cvMat2QPixmapConverter::setMatPic(cv::Mat *value)
{
    matPic = value;
}
