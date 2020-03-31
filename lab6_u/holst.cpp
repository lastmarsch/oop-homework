#include "holst.h"
#include <QtGui/QPainter>

Holst::Holst(QWidget *parent)
    : QWidget(parent)
    , clickP(0,0)
{

}

QSize Holst::sizeHint() const
{
    return QSize(400, 800);
}


void Holst::addObject(const QPainterPath& path)
{
    objects.push_back(path);
}

void Holst::clean()
{
    objects.clear();
}

const QPointF& Holst::getClickPoint() const
{
    return clickP;
}

void Holst::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setPen(QPen{Qt::black, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin});
    painter.fillRect(rect(), Qt::white);
    for (auto& object: objects) {
        painter.drawPath(object);
    }
}

void Holst::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        clickP = event->pos();
    }
}

