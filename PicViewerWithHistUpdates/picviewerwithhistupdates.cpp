#include "picviewerwithhistupdates.h"
#include "ui_picviewerwithhistupdates.h"

PicViewerWithHistUpdates::PicViewerWithHistUpdates(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::PicViewerWithHistUpdates)
{
    ui->setupUi(this);
}

PicViewerWithHistUpdates::~PicViewerWithHistUpdates()
{
    delete ui;
}
cv::Mat *PicViewerWithHistUpdates::getInitialPic() const
{
    return InitialPic;
}

void PicViewerWithHistUpdates::setInitialPic(cv::Mat *value)
{
    InitialPic = value;
}

