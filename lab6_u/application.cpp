#include "application.h"
#include <memory>

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{
    interface = new GUI();
    interface->show();
    holst = std::make_shared<Holst>();
    painter = std::make_shared<Painter>();
    painter->setHolst(holst);
    holst->show();

    connect(interface, &GUI::addSampleToList, this, &Application::addToList);
}

void Application::draw()
{
    painter->clean();
    sample.first().triangle().draw(painter);
    sample.removeFirst();
}

void Application::addToList(Sample s)
{
    sample.append(s);
    qDebug() << sample.size();
    draw();
}
