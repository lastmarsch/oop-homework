#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtCore/QPointF>
#include <QtGui/QPainterPath>
#include <memory>
#include "painter.h"

class Triangle
{
public:
    Triangle() {}
    Triangle(double a, double b, double angle);
    virtual ~Triangle() = default;

    void draw(std::shared_ptr<Painter> painter) const;

private:
    double _a;
    double _b;
    double _angle;
};


#endif // TRIANGLE_H
