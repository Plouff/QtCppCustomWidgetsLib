#ifndef HISTOWITHEDITBOXES_H
#define HISTOWITHEDITBOXES_H

#include <QWidget>

namespace Ui {
class HistoWithEditboxes;
}

class HistoWithEditboxes : public QWidget
{
    Q_OBJECT

public:
    explicit HistoWithEditboxes(QWidget *parent = 0);
    ~HistoWithEditboxes();

private:
    Ui::HistoWithEditboxes *ui;
    void setMinInTextBox(int min);
    void setMaxInTextBox(int max);
    void connectSignals();

private slots:
    void updateMinFromHist(int min);
    void updateMaxFromHist(int max);
};

#endif // HISTOWITHEDITBOXES_H
