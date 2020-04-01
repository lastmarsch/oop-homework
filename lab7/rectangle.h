#ifndef RECTANGLE
#define RECTANGLE

#include "sample.h"

class Rectangle : public Sample
{
public:
    Rectangle(double w, double h);
    virtual ~Rectangle() {}

    bool contains(const QPointF& p) const;
    
private:
    double w, h;
};

#endif
