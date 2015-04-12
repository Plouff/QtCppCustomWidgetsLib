#ifndef GLPICVIEWERWITHCOMMANDS_H
#define GLPICVIEWERWITHCOMMANDS_H

#include <QWidget>
#include <QAbstractButton>

#include <opencv2/opencv.hpp>

#include "Shared/topixmapconverter.h"

namespace Ui {
class GLPicViewerWithCommands;
}

class GLPicViewerWithCommands : public QWidget
{
    Q_OBJECT

public:
    explicit GLPicViewerWithCommands(
            QWidget *parent = 0,
            Qt::AspectRatioMode initialAspectRatio = Qt::KeepAspectRatio);
    ~GLPicViewerWithCommands();
    void setAspectRatio(Qt::AspectRatioMode aspectRatio);

    void setPixmapWithPath(QString path);
    void setCvMat(cv::Mat &pMat);
    void setCvMatWithPath(cv::String const path);

protected :
    cv::Mat * cvMat;
    cv::Mat localCvMat;
    QPixmap * pixmap;
    ToQPixmapConverter * converter;

private:
    Ui::GLPicViewerWithCommands *ui;

protected slots:
    void updateAspectRatio(QAbstractButton * button);
};

#endif // GLPICVIEWERWITHCOMMANDS_H
