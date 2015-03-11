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
    // Histogram to spinboxes
    connect(ui->hist, SIGNAL(newMinFromHist(int)),
            this, SLOT(updateMinFromHist(int)));
    connect(ui->hist, SIGNAL(newMaxFromHist(int)),
            this, SLOT(updateMaxFromHist(int)));

    // Spinboxes to histogram
    connect(ui->maxBox, SIGNAL(valueChanged(int)),
            ui->hist, SLOT(setUserInputMax(int)));
    connect(ui->minBox, SIGNAL(valueChanged(int)),
            ui->hist, SLOT(setUserInputMin(int)));

    // Spinboxes to spinboxes
    connect(ui->maxBox, SIGNAL(valueChanged(int)),
            this, SLOT(setMaxToSpinBox(int)));
    connect(ui->minBox, SIGNAL(valueChanged(int)),
            this, SLOT(setMinToSpinBox(int)));
}

void HistoWithEditboxes::updateMinFromHist(int min)
{
    setMinInTextBox(min);
    ui->maxBox->setMinimum(min);
}

void HistoWithEditboxes::updateMaxFromHist(int max)
{
    setMaxInTextBox(max);
    ui->minBox->setMaximum(max);
}

void HistoWithEditboxes::setMaxToSpinBox(int max)
{
    ui->minBox->setMaximum(max);
}

void HistoWithEditboxes::setMinToSpinBox(int min)
{
    ui->maxBox->setMinimum(min);
}
