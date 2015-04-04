#include <algorithm>
#include <iostream>
#include <stdio.h>

#include <QPainter>
#include <QPaintEvent>

#include "debugmacros.h"
#include "openglpicviewer.h"

OpenGLPicViewer::OpenGLPicViewer(
        QWidget *parent, Qt::AspectRatioMode ratiomode, bool enableDragDrop) :
    QOpenGLWidget(parent), pixmap(nullptr), aspectRatioMode(ratiomode),
    dragDropEnabled(enableDragDrop)
{
    setAutoFillBackground(true);
    scaler = QTransform();
    pixmapsizescaled = QSize();

    drawingOrigin = QPoint(0, 0);
    lastDrawingOrigin = QPoint(0, 0);
    mouseClicOrigin = QPoint();
    beingDragged = false;
}

OpenGLPicViewer::~OpenGLPicViewer()
{
    delete pixmap;
}

void OpenGLPicViewer::setPixmap(const QPixmap &p)
{
    pixmap = &p;
    update();
}

void OpenGLPicViewer::setPixmapWithPath(QString path)
{
    pixmap = new QPixmap(path);
    update();
}

void OpenGLPicViewer::resetPixmapSize()
{
    pixmapsizescaled.setWidth(pixmap->width());
    pixmapsizescaled.setHeight(pixmap->height());
}

Qt::AspectRatioMode OpenGLPicViewer::getAspectRatioMode() const
{
    return aspectRatioMode;
}

void OpenGLPicViewer::setAspectRatioMode(const Qt::AspectRatioMode &value)
{
    if (aspectRatioMode != value)
    {
        aspectRatioMode = value;
        drawingOrigin.setX(0);
        drawingOrigin.setY(0);
        lastDrawingOrigin.setX(0);
        lastDrawingOrigin.setY(0);
        update();
    }
}

void OpenGLPicViewer::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);

    QPainter painter(this);
    if (!pixmap) {
        painter.fillRect(this->rect(), QBrush(Qt::darkGray, Qt::BDiagPattern));
        return;
    }

    // Set interpolation type
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    //Constraint drawing origin to keep image in the display area
    if(aspectRatioMode == Qt::KeepAspectRatioByExpanding)
        constrainDrawingOrigin();

    painter.setWorldTransform(scaler);
// Could be used as a template to optimize the updated area
//    QRect damaged = scalerI.mapRect(ev->rect());
//    painter.drawPixmap(damaged, *pixmap, damaged);
    painter.drawPixmap(drawingOrigin.x(), drawingOrigin.y(), *pixmap);
//    painter.drawPixmap(0, 0, *pixmap);
}

void OpenGLPicViewer::computeScaler(int neww, int newh)
{
    if (!pixmap)
        return;
    else
    {
        // We must reset to cope with rounding when scaling to a very small size
        // Indeed the rounding alters the aspect ratio with the pictures is
        // enlarged again.
        resetPixmapSize();
        pixmapsizescaled.scale(neww, newh, aspectRatioMode);
        qreal xratio = pixmapsizescaled.width() / (qreal)pixmap->width();
        qreal yratio = pixmapsizescaled.height() / (qreal)pixmap->height();

        // Set the scaler with previous ratios
        scaler.reset();
        scaler.scale(xratio, yratio);
//        scalerI = scaler.inverted();
    }
}

//############################################
//############################################
// Public Slots
//############################################
//############################################
void OpenGLPicViewer::update()
{
    if (pixmap != nullptr && isVisible() == true)
    {
        if (!beingDragged)
            computeScaler(width(), height());
        super::update();
    }
}

//############################################
//############################################
// Protected Methods
//############################################
//############################################
void OpenGLPicViewer::resizeGL(int w, int h)
{
    if (!pixmap)
        return;
    else
    {
        computeScaler(w, h);
    }
}

void OpenGLPicViewer::mousePressEvent(QMouseEvent *event)
{
    if (dragDropEnabled && aspectRatioMode == Qt::KeepAspectRatioByExpanding)
    {
        mouseClicOrigin.setX(event->x());
        mouseClicOrigin.setY(event->y());
        beingDragged = true;
    }
}

void OpenGLPicViewer::mouseMoveEvent(QMouseEvent *event)
{
    if (dragDropEnabled && aspectRatioMode == Qt::KeepAspectRatioByExpanding)
    {
        const int dx = event->x() - mouseClicOrigin.x();
        const int dy = event->y() - mouseClicOrigin.y();

        // We must convert the delta into the GL coordinate system
        drawingOrigin = lastDrawingOrigin +
                scaler.inverted().map(QPoint(dx, dy));
        update();
    }
}

void OpenGLPicViewer::mouseReleaseEvent(QMouseEvent *event)
{
    if (dragDropEnabled && aspectRatioMode == Qt::KeepAspectRatioByExpanding)
    {
        const int dx = event->x() - mouseClicOrigin.x();
        const int dy = event->y() - mouseClicOrigin.y();

        // We must convert the delta into the GL coordinate system
        drawingOrigin = lastDrawingOrigin +
                scaler.inverted().map(QPoint(dx, dy));

        beingDragged = false;
        update();

    }
}

void OpenGLPicViewer::constrainDrawingOrigin()
{
    // Set the margin for the move to 5% of the smallest dimension
    int margin = round(std::min(0.05*width(), 0.05*height()));
    // Set a minimum margin in pixels
    margin = std::max(margin, 30);

    // Convert the drawing origin in Qt coordinate system
    drawingOrigin = scaler.map(drawingOrigin);

    // Constraint X position
    int newx = drawingOrigin.x();
    if(newx < (-pixmapsizescaled.width()+margin))
        newx = -pixmapsizescaled.width()+margin;
    else if(newx > width()-margin)
        newx = width()-margin;

    // Constraint X position
    int newy = drawingOrigin.y();
    if(newy < (-pixmapsizescaled.height()+margin))
        newy = -pixmapsizescaled.height()+margin;
    else if(newy > height()-margin)
        newy = height()-margin;

    drawingOrigin.setX(newx);
    drawingOrigin.setY(newy);

    // Convert the drawing origin in GL coordinate system
    drawingOrigin = scaler.inverted().map(drawingOrigin);

    // On mouse release save position of the origin
    if(!beingDragged)
        lastDrawingOrigin = drawingOrigin;
}
