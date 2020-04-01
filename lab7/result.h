#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include "target.h"

class Result : public QObject
{
    Q_OBJECT
public:
    Result();
    void setTarget(Target * target) { this->target = target; }

public slots:
    void addRectangle(double x, double y);
    void addEllipse(double x, double y);
    void addSquare(double side);
    void addCircle(double radius);
    void setCenterPoint(double x, double y);
    void clearTargetList();
    void calc(double i, double j, double w, double h, bool type);

signals:
    void setResult(QString message);

private:
    Target * target;
};

#endif // RESULT_H
