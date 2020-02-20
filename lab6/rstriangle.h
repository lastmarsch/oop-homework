#ifndef RSTRIANGLE_H
#define RSTRIANGLE_H

#include "rbtriangle.h"

class RSTriangle : public RBTriangle
{
public:
    RSTriangle(QPointF p1, QPointF p2);
    virtual ~RSTriangle() = default;

private:
    double getHeight(const QPointF& p1, const QPointF& p2);
};

#endif // RSTRIANGLE_H
