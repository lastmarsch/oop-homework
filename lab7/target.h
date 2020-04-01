#ifndef TARGET_H
#define TARGET_H

#include "circle.h"
#include "square.h"
#include "ellipse.h"
#include "rectangle.h"
#include <QtCore>

class Target
{
public:
    Target();

    void setCenterPoint(QPointF p) { centerPoint = p; }
    void setSize(double w, double h) { this->w = w;
                                       this->h = h;}
    void setIJ(double i, double j) { this->i = i;
                                     this->j = j;}
    void clearList();

    void createRectangle(double x, double y);
    void createSquare(double side);
    void createEllipse(double x, double y);
    void createCircle(double radius);

    int calculate(bool type);
    int randomMethod();
    int regularMethod();
    bool contains(const QPointF& point);

private:
    QList<Sample *> figures;
    QPointF centerPoint;
    int w, h, i, j;
};

#endif // TARGET_H
