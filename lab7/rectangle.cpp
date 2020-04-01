#include "rectangle.h"

Rectangle::Rectangle(double w, double h)
    : Sample(), w(w), h(h)
{

}

bool Rectangle::contains(const QPointF& p) const
{
    return p.x() <= (getCenter().x() + w / 2)  &&
           p.x() >= (getCenter().x() - w / 2)  &&
           p.y() <= (getCenter().y() + h / 2) &&
           p.y() >= (getCenter().y() - h / 2);
}
