#include "application.h"

Application::Application(int argc, char **argv)
    : QApplication(argc, argv)
{
    gui = new Interface();
    gui->show();
    target = new Target();
    result = new Result();
    result->setTarget(target);

    connect(gui, &Interface::setCenter, result, &Result::setCenterPoint);
    connect(gui, &Interface::addRect, result, &Result::addRectangle);
    connect(gui, &Interface::addCircle, result, &Result::addCircle);
    connect(gui, &Interface::addSquare, result, &Result::addSquare);
    connect(gui, &Interface::addEllipse, result, &Result::addEllipse);
    connect(gui, &Interface::calc, result, &Result::calc);
    connect(gui, &Interface::clearFigureList, result, &Result::clearTargetList);
    connect(result, &Result::setResult, gui, &Interface::setResult);
}

Application::~Application()
{
    if (this->gui)
        delete gui;
    if (this->result)
        delete result;
    if (this->target)
        delete target;
}

