#include "UdpServer.h"
#include <QStringList>
#include <iostream>
#include <QDebug>

UdpServer::UdpServer()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void UdpServer::start()
{
    std::cout << "Bind to port 1920\n";
    this->bind(QHostAddress::LocalHost, 1920, QUdpSocket::ReuseAddressHint);
}

void UdpServer::onReadyRead()
{
    std::cout << "Received packet from client\n";
    QByteArray datagram;
    QString data = "";
    while(this->hasPendingDatagrams())
    {
        datagram.resize(static_cast<int>(this->pendingDatagramSize()));
        this->readDatagram(datagram.data(), datagram.size());
        data += datagram;
    }
    qDebug() << data;
    processTheDatagram(data);
}

void UdpServer::processTheDatagram(QString& data)
{    
    QStringList packet = data.split(":");
    if (packet.size() < 1) {
        QByteArray datagram = QString("ERR:[Server] Received incorrect packet.").toUtf8();
        this->writeDatagram(datagram, QHostAddress::LocalHost, 1919);
        std::cout << "Send ERR\n";
        qDebug() << datagram;
        return;
    }

    if (packet[0] == "CALC")
    {
        if (packet.size() < 7) {
            QByteArray datagram = QString("ERR:[Server] Received incorrect packet.").toUtf8();
            this->writeDatagram(datagram, QHostAddress::LocalHost, 1919);
            std::cout << "Send ERR\n";
            return;
        }
        number a = number(packet[1].toDouble(), packet[2].toDouble());
        number b = number(packet[3].toDouble(), packet[4].toDouble());
        number c = number(packet[5].toDouble(), packet[6].toDouble());

        p = Polynom(a, b, c);
        QByteArray datagram;
        number x[2];
        int res = p.roots(x);
        if (res == 2 || res == 1) {
            datagram = QString("ROOTS:X1:%1:X2:%2")
                    .arg(numberToChar(x[0]).constData())
                    .arg(numberToChar(x[1]).constData()).toUtf8();
            std::cout << "Send ROOTS\n";
        }
        if (res == 0) {
            datagram = QString("ERR:[Server] Equation has no roots.").toUtf8();
            std::cout << "Send ERR\n";
        }
        this->writeDatagram(datagram, QHostAddress::LocalHost, 1919);
        qDebug() << datagram;
        return;
    }
    if (packet[0] == "SHOW")
    {
        QByteArray datagram = (QString("VIEW:p(x) = %1 * x^2 + %2 * x + %3")
                               .arg(numberToChar(p.A()).constData())
                               .arg(numberToChar(p.B()).constData())
                               .arg(numberToChar(p.C()).constData())).toUtf8();
        this->writeDatagram(datagram, QHostAddress::LocalHost, 1919);
        qDebug() << datagram;
        std::cout << "Send VIEW\n";
        return;
    }
}

QByteArray UdpServer::numberToChar(number a)
{
    QByteArray ba;
    if (a.real() != 0) {
        if (a.img() != 0)
            ba.append("(");
        ba.append(QString::number(a.real()));
    }
    if (a.img() > 0) {
        if (a.real() != 0)
            ba.append(" + ");
        ba.append(QString::number(a.img()));
    }
    else if (a.img() < 0) {
        if (a.real() != 0)
            ba.append(" - ");
        ba.append(QString::number(a.img() * -1));
    }
    if (a.img() != 0)
        ba.append(" * i");
    if (a.real() != 0 && a.img() != 0)
        ba.append(")");
    return ba;
}
