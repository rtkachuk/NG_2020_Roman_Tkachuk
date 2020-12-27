#include "tabsexample.h"
#include "ui_tabsexample.h"

tabsexample::tabsexample(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tabsexample)
{
    ui->setupUi(this);
    connect (ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
}

tabsexample::~tabsexample()
{
    delete ui;
}

