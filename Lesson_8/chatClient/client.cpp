#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    socket = new QTcpSocket();
    ui->sb_port->setRange(0, 65535);

    ui->e_address->setText("127.0.0.1");
    ui->sb_port->setValue(8080);

    connect (ui->b_connect, &QPushButton::clicked, this, &Client::connectToServer);
    connect (ui->b_send, &QPushButton::clicked, this, &Client::send);

    connect (socket, &QTcpSocket::connected, this, &Client::connectedToServer);
    connect (socket, &QTcpSocket::readyRead, this, &Client::receive);

}

Client::~Client()
{
    delete ui;
}

void Client::connectToServer()
{
    QString ip = ui->e_address->text();
    int port = ui->sb_port->value();
    socket->connectToHost(ip, port);
}

void Client::connectedToServer()
{
    ui->stackedWidget->setCurrentWidget(ui->messages);
    ui->statusbar->showMessage("Connected to " + ui->e_address->text());
}

void Client::send()
{
    QString message = ui->e_nickname->text();
    message += ": ";
    message += ui->t_message->toPlainText();
    socket->write(message.toUtf8());
}

void Client::receive()
{
    QString message = QString::fromUtf8(socket->readAll());
    ui->t_messages->setHtml(ui->t_messages->toHtml() + message);
}

