#include "holst.h"
#include "ui_holst.h"

#include <QDebug>

Holst::Holst(QWidget *parent, Painter *painter) :
    QWidget(parent),
    ui(new Ui::Holst),
    painter(painter)
{
    ui->setupUi(this);
}

Holst::~Holst()
{
    delete ui;
}

void Holst::draw(const QPolygonF& polygon)
{
    _polygon = polygon;
    update();
}

void Holst::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);
    if (_clickPoint.isNull())
        return;
    QPointF offset(_clickPoint - _polygon.first());
    _polygon.translate(offset);
    if (!_polygon.isEmpty()) {
        qDebug() << _polygon;
        paint.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
        paint.fillRect(rect(), Qt::GlobalColor::white);
        paint.drawPolygon(_polygon);
    }
}

void Holst::setPainter(Painter *painter)
{
    this->painter = painter;
}

void Holst::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        _clickPoint = event->pos();
        qDebug() << "New point: " << _clickPoint.x() << ", " << _clickPoint.y() << '\n';
    }
}

