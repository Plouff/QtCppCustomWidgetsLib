#ifndef SINGLEHISTOGRAM_H
#define SINGLEHISTOGRAM_H

#include "qcustomplot.h"

class SingleHistogram : public QCustomPlot
{
    Q_OBJECT
public:
    explicit SingleHistogram(QWidget *parent = 0);
    ~SingleHistogram();

signals:

public slots:

private:
    void initPlot();
    void initBorders(QCPItemRect *rects[]);
    void initBorder(QCPItemRect *rect);
    void connectSignals();
    inline double validateXCoord(double x, double min=0, double max=255);
    double mouseEventToxCoord(QMouseEvent *event);
    bool draggingRightBorder;
    bool draggingLeftBorder;
//    QCPItemRect * leftRect;
//    QCPItemRect * rightRect;
    double xCoordAtMousePressed;
    int currentRightBorderXCoord;

private slots:
    void onMousePressed(QMouseEvent* event);
    void onMouseMoved(QMouseEvent *event);
    void onMouseReleased(QMouseEvent *event);
};

#endif // SINGLEHISTOGRAM_H
