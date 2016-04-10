#ifndef OPENGLPICVIEWER_H
#define OPENGLPICVIEWER_H

#include <QOpenGLWidget>

// Qt::AspectRatioMode: IgnoreAspectRatio, KeepAspectRatio, KeepAspectRatioByExpanding


/**
 * @brief The OpenGLPicViewer class
 *
 * @attention
 * This class holds a pointer to an external QPixmap to be displayed.
 * Before deleting (ie. using @c delete) this external reference, must be
 * properly dereferenced in the #OpenGLPicViewer objects.
 * This dereference is acheived when calling #removePixmap function.
 */
class OpenGLPicViewer : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenGLPicViewer(QWidget *parent = 0,
                    Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio,
                    bool enableDragDrop = true);
    ~OpenGLPicViewer() {}
    void setPixmap(QPixmap * pPixmap);
    void setPixmapWithPath(QString path);
    virtual void paintEvent(QPaintEvent *ev);
    void computeScaler(int neww, int newh);
    void resetPixmapSize();
    void removePixmap();
    Qt::AspectRatioMode getAspectRatioMode() const;
    void setAspectRatioMode(const Qt::AspectRatioMode value);

public slots:
    void update();

protected:
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void constrainDrawingOrigin();

    QPixmap *pixmap;
    QPixmap locPixmap;
    QSize pixmapSizeScaled;
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
