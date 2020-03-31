#ifndef HOLST_H
#define HOLST_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainterPath>

namespace Ui {
class Holst;
}

class Holst : public QWidget
{
    Q_OBJECT

public:
    explicit Holst(QWidget *parent = nullptr);
    ~Holst() {}

    QSize sizeHint() const;
    void addObject(const QPainterPath& path);
    void clean();
    const QPointF& getClickPoint() const;

private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPointF clickP;
    QList<QPainterPath> objects;
};

#endif // HOLST_H
