#include "simpleapp.h"
#include "ui_simpleapp.h"

simpleapp::simpleapp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::simpleapp)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &simpleapp::rezultatNazhatia);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &simpleapp::setLcdNumber);
}

simpleapp::~simpleapp()
{
    delete ui;
}

void simpleapp::rezultatNazhatia()
{
    QString text1 = "Привет!";
    QString text2 = "Пока!";
    if (ui->label->text() == text1)
        ui->label->setText(text2);
    else
        ui->label->setText(text1);
}

void simpleapp::setLcdNumber(int value)
{
    ui->lcdNumber->display(value);
}

