#ifndef QCPXMOVABLERECT_H
#define QCPXMOVABLERECT_H

/// Define the main coordinate that will be
enum class mainCoord {leftX, rightX, topX, bottomX,
                      leftY, rightY, topY, bottomY
                     };

class QCPXOneDirSlidingRect : public QCPItemRect
{
    Q_OBJECT
public:
    QCPXOneDirSlidingRect(double topLeftX, double topLeftY,
                          double bottomRightX, double bottomRightY,
                          mainCoord maincoord, QCustomPlot * plot) :
        topLeftX(topLeftX);
    ~QCPXOneDirSlidingRect();

    int getXCoord() const;
    void setXCoord(int value);
    void setNewCoord(double newMainCoord);

public slots:
    void onMousePressed(QMouseEvent* event);
    void onMouseMoved(QMouseEvent *event);
    void onMouseReleased(QMouseEvent *event);

private:
    QCustomPlot plot;
    bool isBeingDragged;
    int xCoord;
    double topLeftX;
    double topLeftY;
    double bottomRightX;
    double bottomRightY;
    mainCoord maincoord;
    double xCoordAtMousePressed;
    inline double validateXCoord(double x, double min=0, double max=255);

};

#endif // QCPXMOVABLERECT_H
