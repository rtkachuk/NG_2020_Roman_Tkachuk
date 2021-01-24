#ifndef SERVAK_H
#define SERVAK_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class Servak : public QTcpServer
{
    Q_OBJECT
public:
    Servak();

private slots:
    void readyRead();
    void disconnected();

protected:
    void incomingConnection(qintptr handle);

private:
    QVector<QTcpSocket*> clients;
};

#endif // SERVAK_H
