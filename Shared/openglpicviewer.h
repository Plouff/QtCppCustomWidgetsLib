#ifndef OPENGLPICVIEWER_H
#define OPENGLPICVIEWER_H

#include <QOpenGLWidget>

// Qt::AspectRatioMode: IgnoreAspectRatio, KeepAspectRatio, KeepAspectRatioByExpanding

class OpenGLPicViewer : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenGLPicViewer(QWidget *parent = 0,
                    Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio);
    ~OpenGLPicViewer();
    void setPixmap(const QPixmap &p);
    void setPixmapWithPath(QString path);
    virtual void paintEvent(QPaintEvent *ev);
    void computeScale(int neww, int newh);
    void updatePixmapSize();

    Qt::AspectRatioMode getAspectRatioMode() const;
    void setAspectRatioMode(const Qt::AspectRatioMode &value);

protected:
    void resizeGL(int w, int h);
    const QPixmap *pixmap;
    QSize pixmapsize;
    QTransform scaler;
    Qt::AspectRatioMode aspectRatioMode;
};

#endif // OPENGLPICVIEWER_H
