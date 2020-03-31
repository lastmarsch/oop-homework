#ifndef RSTRIANGLE_H
#define RSTRIANGLE_H

#include "rbtriangle.h"

class RSTriangle : public RBTriangle
{
public:
    RSTriangle(double a);
    virtual ~RSTriangle() = default;
};

#endif // RSTRIANGLE_H
