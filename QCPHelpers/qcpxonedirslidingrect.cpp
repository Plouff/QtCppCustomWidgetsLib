#include "qcpxonedirslidingrect.h"

QCPXOneDirSlidingRect::QCPXOneDirSlidingRect(
        double topLeftX, double topLeftY,
        double bottomRightX, double bottomRightY,
        mainCoord maincoord, QCustomPlot * plot, QCPAxis axis) :
    QCPItemRect(plot),
    topLeftX (topLeftX), topLeftY(topLeftY), bottomRightX(bottomRightX),
    maincoord(maincoord), plot(plot), axis(axis)
{
    // Initialize the size ***************************************
    switch (maincoord)
    {
        case leftX :
            xCoord = bottomRightX;
        case rightX :
            xCoord = topLeftX;
        default :
            throw std::exception("maincoord case not implemented: "+maincoord);
    }

    topLeft->setCoords(topLeftX, topLeftY);
    bottomRight->setCoords(bottomRightX, bottomRightY);

    //************************************************************

    // Initialize the fill pattern *******************************
    const QBrush * brush = new QBrush(Qt::darkGray);
    setBrush(*brush);
}

QCPXOneDirSlidingRect::~QCPXOneDirSlidingRect()
{

}
int QCPXOneDirSlidingRect::getXCoord() const
{
    return xCoord;
}

void QCPXOneDirSlidingRect::setXCoord(int value)
{
    xCoord = value;
}

void QCPXOneDirSlidingRect::setNewCoord(double newMainCoord)
{
    switch (maincoord)
    {
        case leftX :
            bottomRight->setCoords(newMainCoord, bottomRightY);
        case rightX :
            topLeftX->setCoords(newMainCoord, topLeftY);
        default :
            throw std::exception("maincoord case not implemented");
    }

    xCoord = newMainCoord;
}

//******************************************************************************
//******************************************************************************
// SLOTS
//******************************************************************************
//******************************************************************************

void QCPXOneDirSlidingRect::onMousePressed(QMouseEvent *event)
{
    if (selectTest(event->pos(), false) > 0)
    {
        isBeingDragged = true;
        xCoordAtMousePressed = mouseEventToxCoord(event);
    }
}

void QCPXOneDirSlidingRect::onMouseMoved(QMouseEvent *event)
{
    if (isBeingDragged)
      {
        double newXCoord;

        // Compute x delta (from clic to current mouse position)
        const double xDelta = xCoordAtMousePressed - mouseEventToxCoord(event);

        // Compute new coordinates
        newXCoord = plot.validateXCoord(currentLeftBorderXCoord-xDelta);
        setNewCoord(newXCoord);

        plot.replot();
    }
}

void QCPXOneDirSlidingRect::onMouseReleased(QMouseEvent *event)
{
    Q_UNUSED(event)

    // Round delta to closest integer
    const int xDelta = round(xCoordAtMousePressed - mouseEventToxCoord(event));
    if (xDelta != 0)
    {
        int finalXCoord = (int) plot.validateXCoord(currentLeftBorderXCoord-xDelta);
        setNewCoord(newXCoord);
        xCoord = finalXCoord;
        plot.replot();
    }
    isBeingDragged = false;
}

double QCPXOneDirSlidingRect::mouseEventToxCoord(QMouseEvent *event)
{
    return axis->pixelToCoord(event->pos().x());
}
