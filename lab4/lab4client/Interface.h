#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "UdpClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

public slots:
    void setText(QString& poly);
    void setText(QString& x1, QString &x2);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void sendData(QStringList& data);

private:
    Ui::Interface *ui;
    UdpClient * udp;

};
#endif // INTERFACE_H
