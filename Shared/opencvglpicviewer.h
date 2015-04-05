#ifndef OPENCVGLPICVIEWER_H
#define OPENCVGLPICVIEWER_H

#include "openglpicviewer.h"
#include <opencv2/opencv.hpp>

class OpenCVGLPicViewer : public OpenGLPicViewer
{
public:
    OpenCVGLPicViewer(QWidget *parent = 0,
                      Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio,
                      bool enableDragDrop = true);
    ~OpenCVGLPicViewer();

    void setCvMat(cv::Mat &pMat);
    void setCvMatWithPath(cv::String const path);

    cv::Mat *getMatPic() const;
    void setMatPic(cv::Mat *value);

private:
    typedef OpenGLPicViewer super;
    cv::Mat* matPic;
    QPixmap localPixMap;
};

#endif // OPENCVGLPICVIEWER_H
