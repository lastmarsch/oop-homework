#ifndef HOLST_H
#define HOLST_H

#include <QWidget>
#include <QMouseEvent>
#include "painter.h"

namespace Ui {
class Holst;
}

class Holst : public QWidget
{
    Q_OBJECT

public:
    explicit Holst(QWidget *parent = nullptr, Painter * painter = nullptr);
    ~Holst();

    void paintEvent(QPaintEvent *event);

    void draw(const QPolygonF& polygon);

    void setPainter(Painter * painter);

private:
    void mousePressEvent(QMouseEvent *event) final;
    QPointF   _clickPoint{0,0};
    QPolygonF _polygon;
    Ui::Holst *ui;
    Painter * painter;
};

#endif // HOLST_H
