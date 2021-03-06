#ifndef HISTOWITHEDITBOXES_H
#define HISTOWITHEDITBOXES_H

#include <QWidget>
#include "fillcolorbehav.h"
#include "histogramtypes.h"

namespace Ui {
class HistoWithEditboxes;
}

class HistoWithEditboxes : public QWidget
{
    Q_OBJECT

public:
    explicit HistoWithEditboxes(QWidget *parent = 0);
    ~HistoWithEditboxes();
    void updateRectFill(FillerInterface &rectFiller);
    void setHist(const helper::coord_s<double> *histCoords);


private:
    Ui::HistoWithEditboxes *ui;

protected:
    void setMinInTextBox(int min);
    void setMaxInTextBox(int max);
    void connectSignals();


protected slots:
    void updateMinFromHist(int min);
    void updateMaxFromHist(int max);
    void setMaxToSpinBox(int max);
    void setMinToSpinBox(int min);
};

#endif // HISTOWITHEDITBOXES_H
