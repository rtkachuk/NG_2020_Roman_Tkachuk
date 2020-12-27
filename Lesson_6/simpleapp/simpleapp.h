#ifndef SIMPLEAPP_H
#define SIMPLEAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class simpleapp; }
QT_END_NAMESPACE

class simpleapp : public QMainWindow
{
    Q_OBJECT

public:
    simpleapp(QWidget *parent = nullptr);
    ~simpleapp();

private slots:
    void rezultatNazhatia();
    void setLcdNumber(int value);

private:
    Ui::simpleapp *ui;
};
#endif // SIMPLEAPP_H
