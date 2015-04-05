#include "glpicviewerwithcommands.h"
#include "ui_glpicviewerwithcommands.h"
#include "debugmacros.h"

GLPicViewerWithCommands::GLPicViewerWithCommands(
        QWidget *parent, Qt::AspectRatioMode initialAspectRatio) :
    QWidget(parent),
    ui(new Ui::GLPicViewerWithCommands)
{
    ui->setupUi(this);

    // Set default aspect ratio
    setAspectRatio(initialAspectRatio);

    // Connect signals/slots
    connect(ui->aspectRatioGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(updateAspectRatio(QAbstractButton*)));

    cvMat2QPixmap = nullptr;
}

GLPicViewerWithCommands::~GLPicViewerWithCommands()
{
    delete ui;
}

void GLPicViewerWithCommands::setPixmapWithPath(QString path)
{
    ui->picViewer->setPixmapWithPath(path);
}

void GLPicViewerWithCommands::setCvMat(cv::Mat &pMat)
{
    if (!cvMat2QPixmap)
        // Add a cv::Mat to QPixmap converter
        cvMat2QPixmap = new cvMat2QPixmapConverter(this);

    pixmap = cvMat2QPixmap->convert(pMat);
    ui->picViewer->setPixmap(*pixmap);
}

void GLPicViewerWithCommands::setCvMatWithPath(const cv::String path)
{
    if (!cvMat2QPixmap)
        // Add a cv::Mat to QPixmap converter
        cvMat2QPixmap = new cvMat2QPixmapConverter(this);

    pixmap = cvMat2QPixmap->convertFromPath(path);
    ui->picViewer->setPixmap(*pixmap);
}

void GLPicViewerWithCommands::setAspectRatio(Qt::AspectRatioMode aspectRatio)
{
    switch(aspectRatio)
    {
    case Qt::KeepAspectRatio:
        ui->radioFit->setChecked(true);
        break;

    case Qt::KeepAspectRatioByExpanding:
        ui->radioExpand->setChecked(true);
        break;

    case Qt::IgnoreAspectRatio:
        ui->radioFill->setChecked(true);
        break;
    }
    ui->picViewer->setAspectRatioMode(aspectRatio);
}

//############################################
//############################################
// Protected functions
//############################################
//############################################

void GLPicViewerWithCommands::updateAspectRatio(QAbstractButton *button)
{
    if(button == ui->radioFit)
    {
        ui->picViewer->setAspectRatioMode(Qt::KeepAspectRatio);
    }
    else if (button == ui->radioExpand)
    {
        ui->picViewer->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);
    }
    else if (button == ui->radioFill)
    {
        ui->picViewer->setAspectRatioMode(Qt::IgnoreAspectRatio);
    }
}
