#include "ellipse.h"
#include <math.h>

Ellipse::Ellipse(double halfw, double halfh)
    : Sample(), halfw(halfw), halfh(halfh)
{}

bool Ellipse::contains(const QPointF& p) const
{
    return std::pow((p.x() - getCenter().x()), 2) / std::pow(halfw, 2) +
           std::pow((p.y() - getCenter().y()), 2) / std::pow(halfh, 2) <= 1 ? true : false;
}
