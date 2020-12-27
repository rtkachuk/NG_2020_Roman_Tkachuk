#ifndef SIMPLETEXTWORKER_H
#define SIMPLETEXTWORKER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class simpletextworker; }
QT_END_NAMESPACE

class simpletextworker : public QMainWindow
{
    Q_OBJECT

public:
    simpletextworker(QWidget *parent = nullptr);
    ~simpletextworker();

private slots:
    void textProcessing();

private:
    Ui::simpletextworker *ui;
};
#endif // SIMPLETEXTWORKER_H
