#include "topixmapconverter.h"

#include "Shared/opencvhelpers.h"


//******************************************************************************
//******************************************************************************
// cv::Mat to QPixmap converter
//******************************************************************************
//******************************************************************************

void CvMat2QPixmapConverter::convert()
{
    Q_ASSERT(rawPic != nullptr);
    // Convert cv::Mat into a Qpixmap
    *pixMapDest = OCVhelpers::cvMatToQPixmap(*rawPic);
}

void CvMat2QPixmapConverter::convertFromPath(cv::String const path)
{
    // Read picture in matPic
    *rawPic = cv::imread(path, 1);

    // Convert cv::Mat into a Qpixmap
    *pixMapDest = OCVhelpers::cvMatToQPixmap(*rawPic);
}
