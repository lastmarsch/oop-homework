#include "sample.h"

Sample::Sample(SampleData data)
{
    switch (data._type) {
    case SampleData::rbtriangle: {
        this->data = RBTriangle(QPointF(data._x_a, data._y_a),
                                QPointF(data._x_b, data._y_b),
                                data._x_c);
        break;
    }
    case SampleData::rstriangle: {
        this->data = RSTriangle(QPointF(data._x_a, data._y_a),
                                QPointF(data._x_b, data._y_b));
        break;
    }
    default: {
        this->data = Triangle(QPointF(data._x_a, data._y_a),
                              QPointF(data._x_b, data._y_b),
                              QPointF(data._x_c, data._y_c));
        break;
    }
    }
    this->poly = this->data.getPolygon();
}

SampleData::SampleData(SampleData::Type type, double x_a, double y_a, double x_b, double y_b, double x_c, double y_c)
{
    _type = type;
    _x_a = x_a;
    _y_a = y_a;
    _x_b = x_b;
    _y_b = y_b;
    _x_c = x_c;
    _y_c = y_c;
}
