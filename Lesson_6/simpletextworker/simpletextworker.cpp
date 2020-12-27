#include "simpletextworker.h"
#include "ui_simpletextworker.h"

simpletextworker::simpletextworker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::simpletextworker)
{
    ui->setupUi(this);

    ui->counter->setReadOnly(true);

    connect (ui->userText, &QTextEdit::textChanged, this, &simpletextworker::textProcessing);
}

simpletextworker::~simpletextworker()
{
    delete ui;
}

void simpletextworker::textProcessing()
{
    ui->counter->setValue(ui->userText->toPlainText().length());
}

