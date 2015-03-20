#include "fillcolorbehav.h"
#include "qcpxonedirslidingrect.h"


//*************************************************************
// Strategy Interface class
//*************************************************************
FillColorBehav::FillColorBehav() : QObject() {
}
FillColorBehav::~FillColorBehav() {}

void FillColorBehav::fillDark(QCPXOneDirSlidingRect *rect)
{
    rect->setBrush(*getDarkBrush());
}

void FillColorBehav::fillLight(QCPXOneDirSlidingRect *rect)
{
    rect->setBrush(*getLightBrush());
}

//*************************************************************
// RED BRUSHES
//*************************************************************

const QBrush* RedFiller::getDarkBrush()
{
    const QBrush * brush = new QBrush(QColor(166, 0, 0, 255));
    return brush;
}

const QBrush* RedFiller::getLightBrush()
{
    const QBrush * brush = new QBrush(QColor(255, 200, 200, 255));
    return brush;
}

//*************************************************************
// GREEN BRUSHES
//*************************************************************
const QBrush* GreenFiller::getDarkBrush()
{
    const QBrush * brush = new QBrush(QColor(0, 166, 0, 255));
    return brush;
}

const QBrush* GreenFiller::getLightBrush()
{
    const QBrush * brush = new QBrush(QColor(200, 255, 200, 255));
    return brush;
}

//*************************************************************
// BLUE BRUSHES
//*************************************************************
const QBrush* BlueFiller::getDarkBrush()
{
    const QBrush * brush = new QBrush(QColor(0, 0, 166, 255));
    return brush;
}

const QBrush* BlueFiller::getLightBrush()
{
    const QBrush * brush = new QBrush(QColor(200, 200, 255, 255));
    return brush;
}
//*************************************************************
// GRAY BRUSHES
//*************************************************************
const QBrush* GrayFiller::getDarkBrush()
{
    const QBrush * brush = new QBrush(QColor(80, 80, 80, 255));
    return brush;
}

const QBrush* GrayFiller::getLightBrush()
{
    const QBrush * brush = new QBrush(QColor(230, 230, 230, 255));
    return brush;
}
