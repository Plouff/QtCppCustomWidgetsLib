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
};

#endif // HISTOWITHEDITBOXES_H
