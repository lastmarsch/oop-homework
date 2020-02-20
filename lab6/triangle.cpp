#include "triangle.h"

Triangle::Triangle(QPointF p1, QPointF p2, QPointF p3)
    : m_P1(p1), m_P2(p2), m_P3(p3)
{}

QPolygonF Triangle::getPolygon() const
{
    QPolygonF polygon;
    polygon << m_P1 << m_P2 << m_P3;
    return polygon;
}
