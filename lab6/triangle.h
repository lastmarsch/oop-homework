#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtCore/QPointF>
#include <QtGui/QPolygonF>

class Triangle
{
public:
    Triangle() {}
    Triangle(QPointF p1, QPointF p2, QPointF p3);
    virtual ~Triangle() = default;

    QPolygonF getPolygon() const;

private:
    QPointF m_P1;
    QPointF m_P2;
    QPointF m_P3;
};


#endif // TRIANGLE_H
