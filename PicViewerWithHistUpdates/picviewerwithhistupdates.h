#ifndef PICVIEWERWITHHISTUPDATES_H
#define PICVIEWERWITHHISTUPDATES_H

//#include <QWidget>
#include <QOpenGLWidget>
#include <opencv2/opencv.hpp>

namespace Ui {
class PicViewerWithHistUpdates;
}

class PicViewerWithHistUpdates : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit PicViewerWithHistUpdates(QWidget *parent = 0);
    ~PicViewerWithHistUpdates();

    cv::Mat *getInitialPic() const;
    void setInitialPic(cv::Mat *value);

private:
    Ui::PicViewerWithHistUpdates *ui;
    cv::Mat *InitialPic;
    cv::Mat *ViewerPic;
};

#endif // PICVIEWERWITHHISTUPDATES_H
