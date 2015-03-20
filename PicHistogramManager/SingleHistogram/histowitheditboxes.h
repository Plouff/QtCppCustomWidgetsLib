#ifndef HISTOWITHEDITBOXES_H
#define HISTOWITHEDITBOXES_H

#include <QWidget>
#include "fillcolorbehav.h"

namespace Ui {
class HistoWithEditboxes;
}

class HistoWithEditboxes : public QWidget
{
    Q_OBJECT

public:
    explicit HistoWithEditboxes(QWidget *parent = 0);
    ~HistoWithEditboxes();
    void updateRectFill(FillColorBehav *rectFiller);


private:
    Ui::HistoWithEditboxes *ui;
    void setMinInTextBox(int min);
    void setMaxInTextBox(int max);
    void connectSignals();


private slots:
    void updateMinFromHist(int min);
    void updateMaxFromHist(int max);
    void setMaxToSpinBox(int max);
    void setMinToSpinBox(int min);
};

#endif // HISTOWITHEDITBOXES_H
