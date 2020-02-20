#ifndef PAINTER_H
#define PAINTER_H

#include "sample.h"
#include <QPainter>

class Painter : public QPainter
{
public:
    Painter(QWidget *parent = nullptr) { Q_UNUSED(parent)}
    void setList(QList<Sample> s) { _s = s; }
    int size() { return _s.size(); }
    QPolygonF print(int i) {
        if (!_s.isEmpty())
            return _s[i].getPolygon();
        return QPolygonF();
    }
private:
    QList<Sample> _s;
};

#endif // PAINTER_H
