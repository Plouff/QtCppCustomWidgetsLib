#include "opencvglpicviewer.h"
#include "Shared/opencvhelpers.h"

OpenCVGLPicViewer::OpenCVGLPicViewer(
        QWidget *parent, Qt::AspectRatioMode aspectRatioMode,
        bool enableDragDrop) :
    OpenGLPicViewer(parent, aspectRatioMode, enableDragDrop)
{
    matPic = new cv::Mat();
}

OpenCVGLPicViewer::~OpenCVGLPicViewer()
{
    delete matPic;
}

void OpenCVGLPicViewer::setCvMat(cv::Mat &pMat)
{
    matPic = &pMat;
    setPixmap(cvMatToQPixmap(*matPic));
}

void OpenCVGLPicViewer::setCvMatWithPath(cv::String const path)
{
    // Read picture in matPic
    *matPic = cv::imread(path, 1);

    // Convert cv::Mat into a Qpixmap
    localPixMap = cvMatToQPixmap(*matPic);

    // Update openGL pointer to the picture
    setPixmap(localPixMap);
}

cv::Mat *OpenCVGLPicViewer::getMatPic() const
{
    return matPic;
}

void OpenCVGLPicViewer::setMatPic(cv::Mat *value)
{
    matPic = value;
}


