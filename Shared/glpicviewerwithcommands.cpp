#include "debugmacros.h"
#include "glpicviewerwithcommands.h"
#include "ui_glpicviewerwithcommands.h"

GLPicViewerWithCommands::GLPicViewerWithCommands(
        QWidget *parent, Qt::AspectRatioMode initialAspectRatio) :
    QWidget(parent),
    ui(new Ui::GLPicViewerWithCommands),
    pixmap(nullptr)
{
    ui->setupUi(this);

    // Set default aspect ratio
    setAspectRatio(initialAspectRatio);

    // Connect signals/slots
    connect(ui->aspectRatioGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(updateAspectRatio(QAbstractButton*)));

}

GLPicViewerWithCommands::~GLPicViewerWithCommands()
{
    delete ui;
}

void GLPicViewerWithCommands::setPixmapWithPath(QString path)
{
    ui->glPicViewer->setPixmapWithPath(path);
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
    ui->glPicViewer->setAspectRatioMode(aspectRatio);
}

void GLPicViewerWithCommands::setPixmap(QPixmap *pixmap)
{
    ui->glPicViewer->setPixmap(pixmap);
}

//############################################
//############################################
// Protected functions
//############################################
//############################################
/**
 * @brief A slot to update the aspect ratio
 *
 * When an aspect ratio button is checked, this slot transmits the new aspect
 * ratio to be used to the GL picviewer
 * @param button
 */
void GLPicViewerWithCommands::updateAspectRatio(QAbstractButton *button)
{
    if(button == ui->radioFit)
    {
        ui->glPicViewer->setAspectRatioMode(Qt::KeepAspectRatio);
    }
    else if (button == ui->radioExpand)
    {
        ui->glPicViewer->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);
    }
    else if (button == ui->radioFill)
    {
        ui->glPicViewer->setAspectRatioMode(Qt::IgnoreAspectRatio);
    }
}
