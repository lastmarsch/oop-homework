#ifndef SAMPLE
#define SAMPLE

#include <QtCore/QPointF>

class Sample {
public:
    Sample() {}
    virtual ~Sample() {}
    void setCenter(const QPointF& center) { this->center = center; }
    QPointF getCenter() const { return center; }
    virtual bool contains(const QPointF& p) const = 0;

private:
    QPointF center;
};

#endif
