#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include "polynom.h"
#include "tcomplex.h"

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
    Polynom <double> d;
    Polynom <TComplex> p;
    void processTheDatagram(QString &data);
    QByteArray numberToChar(TComplex a);
};

#endif // UDPSERVER_H
