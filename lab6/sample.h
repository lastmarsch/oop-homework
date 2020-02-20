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

    SampleData (Type type, double x_a, double y_a,
                double x_b, double y_b,
                double x_c, double y_c);
    SampleData() {}

    Type _type{triangle};
    double _x_a; double _y_a;
    double _x_b; double _y_b;
    double _x_c; double _y_c;
};

class Sample
{
public:
    Sample(SampleData data);
    const QPolygonF getPolygon() { return poly; }
private:
    QPolygonF poly;
    Triangle data;
};

#endif // SAMPLE_H
