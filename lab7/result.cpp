#include "result.h"

Result::Result() : QObject()
{

}

void Result::setCenterPoint(double x, double y)
{
    target->setCenterPoint(QPointF(x, y));
}

void Result::clearTargetList()
{
    target->clearList();
}

void Result::calc(double i, double j, double w, double h, bool type)
{
    target->setSize(w, h);
    target->setIJ(i, j);
    int res = target->calculate(type);
    emit setResult(QString("Free: %1%")
                   .arg(QString::number(static_cast<double>(res) / (i * j))));
}

void Result::addRectangle(double x, double y)
{
    target->createRectangle(x, y);
}

void Result::addEllipse(double x, double y)
{
    target->createEllipse(x, y);
}

void Result::addSquare(double side)
{
    target->createSquare(side);
}

void Result::addCircle(double radius)
{
    target->createCircle(radius);
}
