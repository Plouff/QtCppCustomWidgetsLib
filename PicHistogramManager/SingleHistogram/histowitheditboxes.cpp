#include "histowitheditboxes.h"
#include "ui_histowitheditboxes.h"

HistoWithEditboxes::HistoWithEditboxes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoWithEditboxes)
{
    ui->setupUi(this);

    // Copy startup values in the text boxes
    setMinInTextBox(ui->hist->getMin());
    setMaxInTextBox(ui->hist->getMax());

    // connect signals
    connectSignals();

}

HistoWithEditboxes::~HistoWithEditboxes()
{
    delete ui;
}

void HistoWithEditboxes::setMinInTextBox(int min)
{
    QString minStr = QString::number(min);
    ui->minBox->setText(minStr);
}

void HistoWithEditboxes::setMaxInTextBox(int max)
{
    QString maxStr = QString::number(max);
    ui->maxBox->setText(maxStr);
}

void HistoWithEditboxes::connectSignals()
{
    connect(ui->hist, SIGNAL(newMinFromHist(int)),
            this, SLOT(updateMinFromHist(int)));

    connect(ui->hist, SIGNAL(newMaxFromHist(int)),
            this, SLOT(updateMaxFromHist(int)));
}

void HistoWithEditboxes::updateMinFromHist(int min)
{
    setMinInTextBox(min);
}

void HistoWithEditboxes::updateMaxFromHist(int max)
{
    setMaxInTextBox(max);
}
