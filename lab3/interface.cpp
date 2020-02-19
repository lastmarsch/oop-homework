#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
}

Interface::~Interface()
{
    delete ui;
}


void Interface::on_pushButton_clicked()
{
    if (ui->a_r->text().toDouble() == 0 && ui->a_i->text().toDouble() == 0) {
        ui->textBrowser->append("Coefficient A cannot be NULL. Fill in the fields.");
        return;
    }

    number a = number(ui->a_r->text().toDouble(), ui->a_i->text().toDouble());
    number b = number(ui->b_r->text().toDouble(), ui->b_i->text().toDouble());
    number c = number(ui->c_r->text().toDouble(), ui->c_i->text().toDouble());

    p = Polynom(a, b, c);

    number x[2];
    int res = p.roots(x);
    if (res == 2)
        ui->textBrowser->append(QString("X1 = %1\nX2 = %2\n")
                                 .arg(numberToChar(x[0]).constData())
                                 .arg(numberToChar(x[1]).constData()));
    if (res == 1)
        ui->textBrowser->append(QString("X1,X2 = %1\n")
                                 .arg(numberToChar(x[0]).constData()));
    if (res == 0)
        ui->textBrowser->append("This equation has no roots.\n");

}

QByteArray Interface::numberToChar(number a)
{
    QByteArray ba;
    if (a.real() != 0) {
        if (a.img() != 0)
            ba.append("(");
        ba.append(QString::number(a.real()));
    }
    if (a.img() > 0) {
        if (a.real() != 0)
            ba.append(" + ");
        ba.append(QString::number(a.img()));
    }
    else if (a.img() < 0) {
        if (a.real() != 0)
            ba.append(" - ");
        ba.append(QString::number(a.img() * -1));
    }
    if (a.img() != 0)
        ba.append(" * i");
    if (a.real() != 0 && a.img() != 0)
        ba.append(")");
    return ba;
}

void Interface::on_pushButton_2_clicked()
{
    ui->textBrowser->append(QString("p(x) = %1 * x^2 + %2 * x + %3")
                             .arg(numberToChar(p.A()).constData())
                             .arg(numberToChar(p.B()).constData())
                             .arg(numberToChar(p.C()).constData()));
}
