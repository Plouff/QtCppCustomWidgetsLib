#include "openglpicviewer.h"
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <stdio.h>
#include "debugmacros.h"

OpenGLPicViewer::OpenGLPicViewer(QWidget *parent, Qt::AspectRatioMode ratiomode) :
    QOpenGLWidget(parent), pixmap(NULL), aspectRatioMode(ratiomode)
{
    pixmap = new QPixmap("D:/Uluru.jpg");
}

OpenGLPicViewer::~OpenGLPicViewer()
{
    delete pixmap;
}

void OpenGLPicViewer::setPixmap(const QPixmap &p)
{
    pixmap = &p;
    resizeEvent(0);
    update();
}

void OpenGLPicViewer::resizeGL(int w, int h)
{
    if (!pixmap)
        return;
    else
    {
//        glViewport(0,0, w, h);
        computeScale(w, h);
    }
}
Qt::AspectRatioMode OpenGLPicViewer::getAspectRatioMode() const
{
    return aspectRatioMode;
}

void OpenGLPicViewer::setAspectRatioMode(const Qt::AspectRatioMode &value)
{
    aspectRatioMode = value;
}

void OpenGLPicViewer::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);

    QPainter painter(this);
    if (!pixmap) {
        painter.fillRect(this->rect(), QBrush(Qt::blue, Qt::BDiagPattern));
        return;
    }

    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    painter.setWorldTransform(scaler);
//    QRect damaged = scalerI.mapRect(ev->rect());
//    painter.drawPixmap(damaged, *pixmap, damaged);
    painter.drawPixmap(0, 0, *pixmap);
}

void OpenGLPicViewer::computeScale(int neww, int newh)
{
    if (!pixmap)
        return;
    else
    {
        QSize coords = QSize(pixmap->width(), pixmap->height());
        coords.scale(neww, newh, aspectRatioMode);
        qreal xratio = coords.width() / (qreal)pixmap->width();
        qreal yratio = coords.height() / (qreal)pixmap->height();

//        DBGPRINT(xratio)
//        DBGPRINT(yratio)
//        ENDLFLUSH

        scaler = QTransform();
        scaler.scale(xratio, yratio);
        scalerI = scaler.inverted();
    }
}
