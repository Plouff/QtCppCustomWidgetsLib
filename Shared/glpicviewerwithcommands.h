#ifndef GLPICVIEWERWITHCOMMANDS_H
#define GLPICVIEWERWITHCOMMANDS_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class GLPicViewerWithCommands;
}

class GLPicViewerWithCommands : public QWidget
{
    Q_OBJECT

public:
    explicit GLPicViewerWithCommands(
            QWidget *parent = 0,
            Qt::AspectRatioMode initialAspectRatio = Qt::KeepAspectRatio);
    ~GLPicViewerWithCommands();
    void setPixmapWithPath(QString path);
    void setAspectRatio(Qt::AspectRatioMode aspectRatio);

private:
    Ui::GLPicViewerWithCommands *ui;

protected slots:
    void updateAspectRatio(QAbstractButton * button);
};

#endif // GLPICVIEWERWITHCOMMANDS_H
