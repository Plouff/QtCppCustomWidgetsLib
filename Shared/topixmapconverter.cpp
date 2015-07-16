#include "topixmapconverter.h"

#include "Shared/opencvhelpers.h"


//******************************************************************************
//******************************************************************************
// cv::Mat converter
//******************************************************************************
//******************************************************************************

QPixmap * FromCVMatToQPixmapConverter::convert()
{

    Q_ASSERT(rawPic != nullptr);
    // Convert cv::Mat into a Qpixmap
    localPixMap = OCVhelpers::cvMatToQPixmap(*rawPic);

    return &localPixMap;
}

QPixmap * FromCVMatToQPixmapConverter::convertFromPath(cv::String const path)
{
    // Read picture in matPic
    *rawPic = cv::imread(path, 1);

    // Convert cv::Mat into a Qpixmap
    localPixMap = OCVhelpers::cvMatToQPixmap(*rawPic);

    return &localPixMap;
}
