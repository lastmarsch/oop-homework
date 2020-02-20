#ifndef RBTRIANGLE_H
#define RBTRIANGLE_H

#include "triangle.h"

class RBTriangle : public Triangle
{
public:
    RBTriangle(QPointF p1, QPointF p2, double height);
    virtual ~RBTriangle() = default;

private:
    QPointF getP3(const QPointF& p1, const QPointF& p2, double height);
};

#endif // RBTRIANGLE_H
