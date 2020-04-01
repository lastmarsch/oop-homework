#ifndef ELLIPSE
#define ELLIPSE

#include "sample.h"

class Ellipse : public Sample
{
public:
    Ellipse(double halfw, double halfh);
    virtual ~Ellipse() {}

    bool contains(const QPointF& p) const;
    
private:
    double halfw;
    double halfh;
};

#endif
