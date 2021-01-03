#ifndef PAPERTAIL_H
#define PAPERTAIL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PaperTail; }
QT_END_NAMESPACE

class PaperTail : public QMainWindow
{
    Q_OBJECT

public:
    PaperTail(QWidget *parent = nullptr);
    ~PaperTail();

public slots:
    void save();
    void load();
    void setFont();
    void changeFontSize();

private:
    Ui::PaperTail *ui;
};
#endif // PAPERTAIL_H
