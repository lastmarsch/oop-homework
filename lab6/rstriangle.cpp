#include "rstriangle.h"
#include "math.h"

RSTriangle::RSTriangle(QPointF p1, QPointF p2)
    :RBTriangle(p1, p2, getHeight(p1, p2))
{

}

double RSTriangle::getHeight(const QPointF &p1, const QPointF &p2)
{
    double len = sqrt(pow((p1.x() - p2.x()), 2) + pow((p1.y() - p2.y()), 2));
    return (sin(3 * M_PI / 2) * len);
}
