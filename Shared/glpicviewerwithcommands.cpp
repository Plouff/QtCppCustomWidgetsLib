#include "glpicviewerwithcommands.h"
#include "ui_glpicviewerwithcommands.h"
#include "debugmacros.h"

GLPicViewerWithCommands::GLPicViewerWithCommands(
        QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GLPicViewerWithCommands)
{
    ui->setupUi(this);

    // Fit by default
    ui->radioFit->setChecked(true);
    ui->picViewer->setAspectRatioMode(Qt::KeepAspectRatio);

    // Connect signals/slots
    connect(ui->aspectRatioGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(_updateAspectRatio(QAbstractButton*)));
}

GLPicViewerWithCommands::~GLPicViewerWithCommands()
{
    delete ui;
}

void GLPicViewerWithCommands::setPixmapWithPath(QString path)
{
    ui->picViewer->setPixmapWithPath(path);
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

void GLPicViewerWithCommands::_updateAspectRatio(QAbstractButton *button)
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
