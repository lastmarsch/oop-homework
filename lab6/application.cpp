#include "application.h"

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{
    interface = new GUI();
    interface->show();
    holst = new Holst();
    painter = new Painter(holst);
    holst->setPainter(painter);
    holst->show();

    connect(interface, &GUI::addSampleToList, this, &Application::addToList);
}

void Application::draw()
{
    painter->setList(this->sample);
    if (painter->size() == 0)
        return;
    for (int i = 0; i < painter->size(); i++)
        holst->draw(painter->print(i));
}

void Application::addToList(Sample s)
{
    sample.append(s);
    qDebug() << sample.size();
    draw();
}
