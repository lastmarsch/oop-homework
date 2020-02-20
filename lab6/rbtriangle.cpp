#include "rbtriangle.h"
#include "math.h"

RBTriangle::RBTriangle(QPointF p1, QPointF p2, double height)
    : Triangle(p1, p2, getP3(p1, p2, height))
{

}

QPointF RBTriangle::getP3(const QPointF &p1, const QPointF &p2, double height)
{
    QPointF ortV((p1.y() - p2.y()), -(p1.x() - p2.x()));
    double length =  std::sqrt((ortV.x() * ortV.x()) + (ortV.y() * ortV.y()));
    QPointF norm(ortV.x() / length, ortV.y()/ length);
    QPointF mid((p1.x() + p2.x())/2 , (p1.y() + p2.y())/2);
    return mid + (norm * height);
}
