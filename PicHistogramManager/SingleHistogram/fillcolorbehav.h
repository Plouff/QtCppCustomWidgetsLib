#ifndef FILLCOLORBEHAVS_H
#define FILLCOLORBEHAVS_H

#include <QObject>

class QCPXOneDirSlidingRect;

/// The filler interface
class FillerInterface: public QObject
{
    Q_OBJECT
public:
    FillerInterface();
    ~FillerInterface();

    void fillDark(QCPXOneDirSlidingRect *rect);
    void fillLight(QCPXOneDirSlidingRect *rect);
    virtual const QBrush *getDarkBrush() =0;
    virtual const QBrush *getLightBrush() =0;
};

class RedFiller: public FillerInterface
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

class GreenFiller: public FillerInterface
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

class BlueFiller: public FillerInterface
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

class GrayFiller: public FillerInterface
{
    public:
        const QBrush *getDarkBrush();
        const QBrush *getLightBrush();
};

#endif // FILLCOLORBEHAVS_H
