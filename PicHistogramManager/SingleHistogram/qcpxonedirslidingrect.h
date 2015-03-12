#ifndef QCPXMOVABLERECT_H
#define QCPXMOVABLERECT_H

#include "qcustomplot.h"

class SingleHistogram;

/// Define the main coordinate that will be
enum class mainCoord {leftX, rightX, topX, bottomX,
                      leftY, rightY, topY, bottomY
                     };

class QCPXOneDirSlidingRect : public QCPItemRect
{
    Q_OBJECT
public:
    QCPXOneDirSlidingRect(SingleHistogram * plot, int topLeftX, int topLeftY,
                          int bottomRightX, int bottomRightY,
                          int min, int max,
                          mainCoord maincoord,
                          QCPAxis *axis);
    ~QCPXOneDirSlidingRect();

    int getXCoord() const;
    void setXCoord(int value);
    void setNewCoord(double newMainCoord);

    bool isPressed(double xCoordAtMousePressed);


    int getMin() const;
    void setMin(int value);

    int getMax() const;
    void setMax(int value);

private:
    SingleHistogram *plot;
    bool isBeingDragged;
    int xCoord;
    double topLeftX;
    double topLeftY;
    double bottomRightX;
    double bottomRightY;
    int min;
    int max;
    mainCoord maincoord;
    double xCoordAtMousePressed;
    QCPAxis * axis;
    void connectSignals();
    inline double validateXCoord(double x);
    double mouseEventToxCoord(QMouseEvent *event);
    int lastXDelta = 0;

private slots:
    void onMousePressed(QMouseEvent* event);
    void onMouseMoved(QMouseEvent *event);
    void onMouseReleased(QMouseEvent *event);

};

#endif // QCPXMOVABLERECT_H
