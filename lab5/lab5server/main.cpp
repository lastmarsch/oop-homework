#include <QCoreApplication>
#include "UdpServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    UdpServer udp;
    udp.start();

    return a.exec();
}
