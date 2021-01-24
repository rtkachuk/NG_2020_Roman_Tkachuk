#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void connectToServer();
    void connectedToServer();
    void send();
    void receive();

private:
    Ui::Client *ui;
    QTcpSocket *socket;
};
#endif // CLIENT_H
