#ifndef OPENGLPICVIEWER_H
#define OPENGLPICVIEWER_H

#include <QOpenGLWidget>

// Qt::AspectRatioMode: IgnoreAspectRatio, KeepAspectRatio,
// KeepAspectRatioByExpanding

class OpenGLPicViewer : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenGLPicViewer(QWidget *parent = 0,
                    Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio,
                    bool enableDragDrop = true);
    ~OpenGLPicViewer();
    void setPixmap(const QPixmap &p);
    void setPixmapWithPath(QString path);
    virtual void paintEvent(QPaintEvent *ev);
    void computeScaler(int neww, int newh);
    void resetPixmapSize();

    Qt::AspectRatioMode getAspectRatioMode() const;
    void setAspectRatioMode(const Qt::AspectRatioMode &value);

public slots:
    void update();

protected:
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void constrainDrawingOrigin();

    const QPixmap *pixmap;
    QSize pixmapsizescaled;
    QTransform scaler;
    Qt::AspectRatioMode aspectRatioMode;
    bool dragDropEnabled;

    // Drawing origin management
    QPoint drawingOrigin;
    QPoint lastDrawingOrigin;
    QPoint mouseClicOrigin;
    bool beingDragged;

private:
    typedef QOpenGLWidget super;
};

#endif // OPENGLPICVIEWER_H
