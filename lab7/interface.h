#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_add_clicked();

    void on_setCenter_clicked();

    void on_reset_clicked();

    void on_rect_clicked();

    void on_square_clicked();

    void on_ellipse_clicked();

    void on_circle_clicked();

    void on_calc_clicked();

public slots:

    void setResult(QString message);

signals:
    void addRect(double w, double h);
    void addSquare(double side);
    void addCircle(double r);
    void addEllipse(double halfw, double halfh);
    void setCenter(double x, double y);
    void clearFigureList();
    void calc(double i, double j, double w, double h, bool type);

private:
    Ui::Interface *ui;
    bool isEmpty{true};
    bool type{false};
    bool centerSet{false};
};
#endif // INTERFACE_H
