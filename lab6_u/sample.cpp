#include "sample.h"

Sample::Sample(SampleData data)
{
    switch (data._type) {
    case SampleData::rbtriangle: {
        this->data = RBTriangle(data._a,
                                data._angle);
        break;
    }
    case SampleData::rstriangle: {
        this->data = RSTriangle(data._a);
        break;
    }
    default: {
        this->data = Triangle(data._a,
                              data._b,
                              data._angle);
        break;
    }
    }
}

SampleData::SampleData(SampleData::Type type, double a, double b, double angle)
{
    _type = type;
    _a = a;
    _b = b;
    _angle = angle;
}
