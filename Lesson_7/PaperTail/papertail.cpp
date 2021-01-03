#include "papertail.h"
#include "ui_papertail.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

PaperTail::PaperTail(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PaperTail)
{
    ui->setupUi(this);
    connect (ui->b_save, &QPushButton::clicked, this, &PaperTail::save);
    connect (ui->b_load, &QPushButton::clicked, this, &PaperTail::load);
    connect (ui->fontComboBox, &QFontComboBox::currentFontChanged, this, &PaperTail::setFont);
    connect (ui->fontSize, QOverload<int>::of(&QSpinBox::valueChanged), this, &PaperTail::changeFontSize);

    ui->fontSize->setValue(12);
}

PaperTail::~PaperTail()
{
    delete ui;
}

void PaperTail::save()
{
    QString path = QFileDialog::getSaveFileName(this, "Сюда подошел",
                                              "/",
                                              "Всякая хрень (*);;Text files (*.txt)");
    if (path.isEmpty())
        return;

    QFile fileToSave(path);

    // In case if upper part seems to be complicated, you are free to use
    // just
    //
    // QFile fileToSave("/whatewer/path/you/want");
    //
    // and remove all code below
    //

    if (fileToSave.open(QIODevice::WriteOnly)) {

        QTextStream to(&fileToSave);
        to << ui->data->toHtml();

        fileToSave.close();
    } else {
        QMessageBox::warning(this, "Wow, we can't open the file!", fileToSave.errorString());
    }
}

void PaperTail::load()
{
    QString path = QFileDialog::getOpenFileName(this, "Откуда грузить",
                                                "/",
                                                "Всякая хрень (*);;Text files (*.txt)");
    if (path.isEmpty())
        return;

    QFile fileToLoad(path);
    if (fileToLoad.open(QIODevice::ReadOnly)) {

        QTextStream from(&fileToLoad);
        ui->data->setHtml(from.readAll());

        fileToLoad.close();
    } else {
        QMessageBox::warning(this, "Wow, we can't open the file!", fileToLoad.errorString());
    }
}

void PaperTail::setFont()
{
    QFont newFont = ui->fontComboBox->currentFont();
    newFont.setPixelSize(ui->fontSize->value());
    ui->data->setCurrentFont(newFont);
}

void PaperTail::changeFontSize()
{
    QFont existingFont = ui->data->currentFont();
    existingFont.setPixelSize(ui->fontSize->value());
    ui->data->setCurrentFont(existingFont);
}
