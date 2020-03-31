#ifndef RBTRIANGLE_H
#define RBTRIANGLE_H

#include "triangle.h"

class RBTriangle : public Triangle
{
public:
    RBTriangle(double a, double angle);
    virtual ~RBTriangle() = default;
};

#endif // RBTRIANGLE_H
