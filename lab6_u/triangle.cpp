#include "triangle.h"
#include "math.h"
#include <QDebug>

Triangle::Triangle(double a, double b, double angle)
    : _a(a), _b(b), _angle(angle)
{
    qDebug() << _a << _b << _angle;
}

void Triangle::draw(std::shared_ptr<Painter> painter) const
{
    QPointF A = painter->getClickPoint();
    QPointF B(A.x() - _a * sin(M_PI/180 * _angle/2), A.y() + _a * cos(M_PI/180 * _angle/2));
    QPointF C(A.x() + _b * sin(M_PI/180 * _angle/2), A.y() + _b * cos(M_PI/180 * _angle/2));
    QPainterPath path;
    path.moveTo(A);
    path.lineTo(B);
    path.lineTo(C);
    path.lineTo(A);
    painter->add(path);
    painter->draw();
}
