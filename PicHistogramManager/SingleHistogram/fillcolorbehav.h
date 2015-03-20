#ifndef FILLCOLORBEHAVS_H
#define FILLCOLORBEHAVS_H

#include <QObject>

class QCPXOneDirSlidingRect;

class FillColorBehav: public QObject
{
    Q_OBJECT
public:
    FillColorBehav();
    ~FillColorBehav();

    void fillDark(QCPXOneDirSlidingRect *rect);
    void fillLight(QCPXOneDirSlidingRect *rect);
    virtual const QBrush *getDarkBrush() =0;
    virtual const QBrush *getLightBrush() =0;
};

class RedFiller: public FillColorBehav
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

class GreenFiller: public FillColorBehav
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

class BlueFiller: public FillColorBehav
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

class GrayFiller: public FillColorBehav
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

#endif // FILLCOLORBEHAVS_H
