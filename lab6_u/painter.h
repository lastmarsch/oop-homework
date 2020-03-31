#ifndef PAINTER_H
#define PAINTER_H

#include <QtGui/QPainterPath>
#include <memory>
#include "holst.h"

class Painter
{
public:
    Painter() = default;
    ~Painter() = default;

    void setHolst(const std::shared_ptr<Holst>& holst);
    QPointF getClickPoint();
    void add(QPainterPath& path);
    void clean();
    void draw();

private:
    std::shared_ptr<Holst> holst;
};

#endif // PAINTER_H
