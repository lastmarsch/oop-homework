#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QStringList>

class UdpClient : public QUdpSocket
{
    Q_OBJECT
public:
    UdpClient(QObject *parent = nullptr);

private slots:
    void onReadyRead();
    void sendData(QStringList& data);

signals:
    void dataReceivedRoots(QString& x1, QString& x2);
    void dataReceivedPoly(QString& poly);
    void error(QString& msg);

private:
    void processTheDatagram(QString data);
};

#endif // UDPCLIENT_H
