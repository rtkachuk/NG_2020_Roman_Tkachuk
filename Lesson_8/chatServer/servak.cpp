#include "servak.h"

Servak::Servak()
{

}

void Servak::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QByteArray data = client->readAll();

    for (QTcpSocket *buffer : clients) {
        buffer->write(data);
    }
}

void Servak::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client " << client->peerAddress().toString() << " disconnected!";

    disconnect (client, &QTcpSocket::readyRead, this, &Servak::readyRead);
    disconnect (client, &QTcpSocket::disconnected, this, &Servak::disconnected);

    clients.remove(clients.indexOf(client));
}

void Servak::incomingConnection(qintptr handle)
{
    QTcpSocket *client = new QTcpSocket();
    client->setSocketDescriptor(handle);
    clients.append(client);

    qDebug() << "New connection from: " << client->peerAddress().toString();

    connect (client, &QTcpSocket::readyRead, this, &Servak::readyRead);
    connect (client, &QTcpSocket::disconnected, this, &Servak::disconnected);
}
