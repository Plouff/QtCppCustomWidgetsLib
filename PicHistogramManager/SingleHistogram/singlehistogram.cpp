#include <iostream>
#include <math.h>

#include "singlehistogram.h"
#include "ui_singlehistogram.h"

SingleHistogram::SingleHistogram(QWidget *parent) :
    QCustomPlot(parent)
{
    // Initialise dragging bool
    draggingRightBorder = false;
    draggingLeftBorder = false;
    this->axisRect()->insetLayout()->setInsetPlacement(
                0, QCPLayoutInset::ipFree);

    // Init histograms
    initPlot();
//    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // Deal with rectangle boundaries
    QCPItemRect * rectBorder[2];
    rectBorder[0] = new QCPItemRect(this);
    rectBorder[1] = new QCPItemRect(this);
    leftRect = rectBorder[0];
    rightRect = rectBorder[1];

    initBorders(rectBorder);

    // Connect signals and slots
    connectSignals();
}

SingleHistogram::~SingleHistogram()
{

}

void SingleHistogram::initPlot()
{

    // Deal with axes *******************************
    addGraph();
    xAxis->setRange(-20, 275);
    yAxis->setRange(0, 1);
    yAxis2->setVisible(true);

    for (auto axe : {xAxis, yAxis, yAxis2})
    {

        break;
        // Disable ticks
        axe->setTicks(false);
        axe->setTickLabels(false);

        // Disable grid
        axe->grid()->setVisible(false);
    }

    // Margins **************************************
    // TODO: FIXME
//        QCPAxisRect * axeRect = axisRect();
//        const QMargins * zeroMargin = new QMargins(0, 0, 0, 0);
//        //axeRect->setMargins(*zeroMargin);
//        axeRect()->setMargins(*zeroMargin);
//        delete zeroMargin;

    replot();
}

void SingleHistogram::initBorders(QCPItemRect *rects[])
{
    // Init borders
    initBorder(rects[0]);
    initBorder(rects[1]);

    // Left rectangle
    currentLeftBorderXCoord = 0;
    rects[0]->topLeft->setCoords(-7000, 7000);
    rects[0]->bottomRight->setCoords(currentLeftBorderXCoord, -7000);

    // Right rectangle
    currentRightBorderXCoord = 255;
    rects[1]->topLeft->setCoords(currentRightBorderXCoord, 7000);
    rects[1]->bottomRight->setCoords(7000, -7000);
}

void SingleHistogram::initBorder(QCPItemRect *rect)
{
    this->addItem(rect);
    // Create fill pattern
    const QBrush * brush = new QBrush(Qt::darkGray);
    rect->setBrush(*brush);
}

void SingleHistogram::connectSignals()
{
    connect(this, SIGNAL(mousePress(QMouseEvent*)),
            this, SLOT(onMousePressed(QMouseEvent*)));

    connect(this, SIGNAL(mouseMove(QMouseEvent*)),
            this, SLOT(onMouseMoved(QMouseEvent*)));

    connect(this, SIGNAL(mouseRelease(QMouseEvent*)),
            this, SLOT(onMouseReleased(QMouseEvent*)));
}

inline double SingleHistogram::validateXCoord(double x, double min, double max)
{
    if (x <= min)
        return min;
    else if (x >= max)
        return max;
    else
        return x;
}

double SingleHistogram::mouseEventToxCoord(QMouseEvent *event)
{
    return xAxis->pixelToCoord(event->pos().x());
}

void SingleHistogram::onMousePressed(QMouseEvent *event)
{
    if (leftRect->selectTest(event->pos(), false) > 0)
    {
        draggingLeftBorder = true;
        xCoordAtMousePressed = mouseEventToxCoord(event);

    }
    else if (rightRect->selectTest(event->pos(), false) > 0)
    {
        draggingRightBorder = true;
    }
}

void SingleHistogram::onMouseMoved(QMouseEvent *event)
{
    if (draggingLeftBorder)
      {
        double newXCoord;

        // Compute x delta (from clic to current mouse position)
        const double xDelta = xCoordAtMousePressed - mouseEventToxCoord(event);

        // Compute new coordinates
        newXCoord = validateXCoord(currentLeftBorderXCoord-xDelta);


        leftRect->bottomRight->setCoords(newXCoord, -7000);
        this->replot();
    }
}

void SingleHistogram::onMouseReleased(QMouseEvent *event)
{
    Q_UNUSED(event)
    // Round delta to closest integer
    const int xDelta = round(xCoordAtMousePressed - mouseEventToxCoord(event));
    if (xDelta != 0)
    {
        int finalXCoord = (int) validateXCoord(currentLeftBorderXCoord-xDelta);
        leftRect->bottomRight->setCoords(finalXCoord, -7000);
        currentLeftBorderXCoord = finalXCoord;
        this->replot();
    }
    draggingLeftBorder = false;
    draggingRightBorder = false;
}
