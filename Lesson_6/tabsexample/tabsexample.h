#ifndef TABSEXAMPLE_H
#define TABSEXAMPLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class tabsexample; }
QT_END_NAMESPACE

class tabsexample : public QMainWindow
{
    Q_OBJECT

public:
    tabsexample(QWidget *parent = nullptr);
    ~tabsexample();

private:
    Ui::tabsexample *ui;
};
#endif // TABSEXAMPLE_H
