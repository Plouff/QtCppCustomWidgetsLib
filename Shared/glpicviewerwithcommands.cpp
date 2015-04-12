#include "debugmacros.h"
#include "glpicviewerwithcommands.h"
#include "ui_glpicviewerwithcommands.h"

GLPicViewerWithCommands::GLPicViewerWithCommands(
        QWidget *parent, Qt::AspectRatioMode initialAspectRatio) :
    QWidget(parent),
    ui(new Ui::GLPicViewerWithCommands)
{
    ui->setupUi(this);

    // Set default aspect ratio
    setAspectRatio(initialAspectRatio);

    // Init converter pointer
    converter = nullptr;

    // Connect signals/slots
    connect(ui->aspectRatioGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(updateAspectRatio(QAbstractButton*)));

}

GLPicViewerWithCommands::~GLPicViewerWithCommands()
{
    delete ui;
    delete converter;
}

void GLPicViewerWithCommands::setPixmapWithPath(QString path)
{
    ui->picViewer->setPixmapWithPath(path);
}

void GLPicViewerWithCommands::setCvMat(cv::Mat &pMat)
{
    // Create a cv::Mat to QPixmap converter
    converter = new FromCVMatToQPixmapConverter(this, &pMat);

    pixmap = converter->convert();
    ui->picViewer->setPixmap(*pixmap);
}

void GLPicViewerWithCommands::setCvMatWithPath(const cv::String path)
{
    // Create a cv::Mat to QPixmap converter
    converter = new FromCVMatToQPixmapConverter(this);

    pixmap = converter->convertFromPath(path);
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
