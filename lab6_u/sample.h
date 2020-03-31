#ifndef SAMPLE_H
#define SAMPLE_H

#include "triangle.h"
#include "rbtriangle.h"
#include "rstriangle.h"

struct SampleData
{
    enum Type {
        triangle = 0,
        rbtriangle,
        rstriangle
    };

    SampleData (Type type, double a,
                double b,
                double angle);
    SampleData() {}

    Type _type{triangle};
    double _a;
    double _b;
    double _angle;
    QPointF _clickP;
};

class Sample
{
public:
    Sample(SampleData data);
    Triangle triangle() { return data; }
private:
    Triangle data;
};

#endif // SAMPLE_H
