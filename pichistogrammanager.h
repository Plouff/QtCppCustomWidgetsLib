#ifndef PICHISTOGRAM_H
#define PICHISTOGRAM_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class PicHistogram;
}

class PicHistogramManager : public QWidget
{
    Q_OBJECT
public:
    explicit PicHistogramManager(QWidget *parent = 0);
    ~PicHistogramManager();

signals:

public slots:

private:
    Ui::PicHistogram *ui;
    void initWidget();
};

#endif // PICHISTOGRAM_H
