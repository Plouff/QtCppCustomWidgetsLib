#include "histowitheditboxes.h"
#include "ui_histowitheditboxes.h"

HistoWithEditboxes::HistoWithEditboxes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoWithEditboxes)
{
    ui->setupUi(this);

    // Copy startup values in the text boxes
    setMinInTextBox(ui->hist->getUserInputMin());
    setMaxInTextBox(ui->hist->getUserInputMax());

    // connect signals
    connectSignals();
}

HistoWithEditboxes::~HistoWithEditboxes()
{
    delete ui;
}

void HistoWithEditboxes::setMinInTextBox(int min)
{
    ui->minBox->setValue(min);
}

void HistoWithEditboxes::setMaxInTextBox(int max)
{
    ui->maxBox->setValue(max);
}

void HistoWithEditboxes::connectSignals()
{
    // Histogram to spin boxes
    connect(ui->hist, SIGNAL(newMinFromHist(int)),
            this, SLOT(updateMinFromHist(int)));
    connect(ui->hist, SIGNAL(newMaxFromHist(int)),
            this, SLOT(updateMaxFromHist(int)));

    // Spin boxes to histogram
    connect(ui->maxBox, SIGNAL(valueChanged(int)),
            ui->hist, SLOT(setUserInputMax(int)));
    connect(ui->minBox, SIGNAL(valueChanged(int)),
            ui->hist, SLOT(setUserInputMin(int)));

    //
    //
    // TOOOOOOOODOOOOOOOO : update min max of spinbox dynamically
    // TOOOOOOOODOOOOOOOO : update min max of spinbox dynamically
    // TOOOOOOOODOOOOOOOO : update min max of spinbox dynamically
    //
    //
}

void HistoWithEditboxes::updateMinFromHist(int min)
{
    setMinInTextBox(min);
}

void HistoWithEditboxes::updateMaxFromHist(int max)
{
    setMaxInTextBox(max);
}
