#include "UdpClient.h"
#include <QDebug>

UdpClient::UdpClient(QObject *parent)
{
    this->bind(QHostAddress::LocalHost, 1919, QUdpSocket::ReuseAddressHint);
    connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(this, SIGNAL(dataReceivedRoots(QString&, QString&)), parent, SLOT(setText(QString&, QString&)));
    connect(this, SIGNAL(dataReceivedPoly(QString&)), parent, SLOT(setText(QString&)));
    connect(parent, SIGNAL(sendData(QStringList&)), this, SLOT(sendData(QStringList&)));
    connect(this, SIGNAL(error(QString&)), parent, SLOT(setText(QString&)));
}

void UdpClient::sendData(QStringList& data)
{
    qDebug() << data;
    QByteArray datagram;
    if (data[0] != "SHOW" && data[0] != "CALC") {
        QString msg = "Incorrect query.";
        emit error(msg);
        return;
    }

    if (data[0] == "CALC")
        foreach (QString part, data) {
            datagram += part.toUtf8() + ":";
        }
    if (data[0] == "SHOW")
        datagram = data[0].toUtf8() + ":" + data[1].toUtf8();

    this->writeDatagram(datagram, QHostAddress::LocalHost, 1920);
}

void UdpClient::onReadyRead()
{
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


void UdpClient::processTheDatagram(QString data)
{
    QStringList packet = data.split(":");
    if (packet.size() < 2) {
        QString msg = "Received incorrect packet.";
        emit error(msg);
        return;
    }

    if (packet[0] == "ROOTS")
    {
        if (packet.size() < 3) {
            QString msg = "Received incorrect packet.";
            emit error(msg);
            return;
        }
        QString x1, x2;
        if (packet[1] == "X1")
            x1 = packet[2];
        if (packet[3] == "X2")
            x2 = packet[4];
        emit dataReceivedRoots(x1, x2);
        return;
    }
    if (packet[0] == "VIEW" || packet[0] == "ERR")
    {
        emit dataReceivedPoly(packet[1]);
        return;
    }
}
