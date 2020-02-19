#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include "polynom.h"

class UdpServer : public QUdpSocket
{
    Q_OBJECT
public:
    UdpServer();
    void start();

private slots:
    void onReadyRead();

signals:
    void error(QString error);

private:
    QUdpSocket * sock;
    Polynom p;

    void processTheDatagram(QString &data);
    QByteArray numberToChar(number a);
};

#endif // UDPSERVER_H
