#include <string>
#include <assert.h>
#include <iostream>

#include "singlehistogram.h"
#include "qcpxonedirslidingrect.h"

QCPXOneDirSlidingRect::QCPXOneDirSlidingRect(SingleHistogram *plot,
        int topLeftX, int topLeftY,
        int bottomRightX, int bottomRightY, int min, int max,
        mainCoord maincoord, QCPAxis *axis) :
    QCPItemRect(plot),
    plot(plot),
    topLeftX (topLeftX), topLeftY(topLeftY),
    bottomRightX(bottomRightX), bottomRightY(bottomRightY),
    min(min), max(max),
    maincoord(maincoord), axis(axis)
{
    // Initialize the size ***************************************
    switch (maincoord)
    {
        case mainCoord::leftX :
            xCoord = topLeftX;
            break;
        case mainCoord::rightX :
            xCoord = bottomRightX;
            break;
        default :
            assert(false);
            break;
    }

    topLeft->setCoords(topLeftX, topLeftY);
    bottomRight->setCoords(bottomRightX, bottomRightY);

    //************************************************************

    // Initialize the fill pattern *******************************
    const QBrush * brush = new QBrush(Qt::darkGray);
    setBrush(*brush);

    connectSignals();
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
    plot->replot();
}

void QCPXOneDirSlidingRect::setNewCoord(double newMainCoord)
{
    switch (maincoord)
    {
        case mainCoord::rightX :
            this->bottomRight->setCoords(newMainCoord, bottomRightY);
            break;
        case mainCoord::leftX :
            this->topLeft->setCoords(newMainCoord, topLeftY);
            break;
        default :
            assert(false);
            break;
    }
//    std::cout << "newMainCoord: " << newMainCoord << std::endl;
    xCoord = newMainCoord;
}

bool QCPXOneDirSlidingRect::isPressed(double xCoordAtMousePressed)
{
    if (xCoordAtMousePressed <= xCoord && maincoord == mainCoord::rightX)
        return true;
    else if (xCoordAtMousePressed >= xCoord && maincoord == mainCoord::leftX)
        return true;
    else
        return false;
}

int QCPXOneDirSlidingRect::getMax() const
{
    return max;
}

void QCPXOneDirSlidingRect::setMax(int value)
{
    max = value;
}

int QCPXOneDirSlidingRect::getMin() const
{
    return min;
}

void QCPXOneDirSlidingRect::setMin(int value)
{
    min = value;
}



//******************************************************************************
//******************************************************************************
// SLOTS
//******************************************************************************
//******************************************************************************

void QCPXOneDirSlidingRect::onMousePressed(QMouseEvent *event)
{
    xCoordAtMousePressed = mouseEventToxCoord(event);
    isBeingDragged = isPressed(xCoordAtMousePressed);

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Select test doesn't work.......
//
//    std::cout << "selecTest: " << (double) this->selectTest(event->pos(), false) << std::endl;
//    if (this->selectTest(event->pos(), false) > 0)
//    {
//        isBeingDragged = true;
//        xCoordAtMousePressed = mouseEventToxCoord(event);
//        std::cout << "Clic at " << xCoordAtMousePressed << std::endl;
//    }
}

void QCPXOneDirSlidingRect::onMouseMoved(QMouseEvent *event)
{
    if (isBeingDragged)
      {
        double newXCoord;

        // Compute x delta (from clic to current mouse position)
        int xDelta = round(mouseEventToxCoord(event) - xCoordAtMousePressed);

        if (xDelta != 0 && xDelta != lastXDelta)
        {
            // Compute new coordinates
            newXCoord = validateXCoord(xCoord + xDelta - lastXDelta);
            setNewCoord(newXCoord);
            // Replot
            plot->replot();
        }

        lastXDelta = xDelta;
    }

}

void QCPXOneDirSlidingRect::onMouseReleased(QMouseEvent *event)
{
    Q_UNUSED(event)

    isBeingDragged = false;
    plot->updateCoord(this, xCoord);
}

void QCPXOneDirSlidingRect::connectSignals()
{
    connect(plot, SIGNAL(mousePress(QMouseEvent*)),
            this, SLOT(onMousePressed(QMouseEvent*)));

    connect(plot, SIGNAL(mouseMove(QMouseEvent*)),
            this, SLOT(onMouseMoved(QMouseEvent*)));

    connect(plot, SIGNAL(mouseRelease(QMouseEvent*)),
            this, SLOT(onMouseReleased(QMouseEvent*)));
}

double QCPXOneDirSlidingRect::validateXCoord(double x)
{
    if (x <= min)
        return min;
    else if (x >= max)
        return max;
    else
        return x;
}

double QCPXOneDirSlidingRect::mouseEventToxCoord(QMouseEvent *event)
{
    return axis->pixelToCoord(event->pos().x());
}
