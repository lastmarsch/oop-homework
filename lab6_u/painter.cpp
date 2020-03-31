#include "painter.h"

void Painter::setHolst(const std::shared_ptr<Holst>& holst)
{
    this->holst = holst;
}

QPointF Painter::getClickPoint()
{
    return holst->getClickPoint();
}

void Painter::add(QPainterPath& path)
{
    holst->addObject(path);
}

void Painter::clean()
{
    holst->clean();
}

void Painter::draw()
{
    holst->update();
}
