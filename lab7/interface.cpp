#include "interface.h"
#include "ui_interface.h"

#include <QMessageBox>

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
}

Interface::~Interface()
{
    delete ui;
}


void Interface::on_add_clicked()
{
    if (!centerSet) {
        QMessageBox::warning(this, "Error",
                             "Please, set center first.");
        return;
    }

    if (ui->rect->isChecked()) {
        emit addRect(ui->xx->text().toDouble(),
                     ui->yy->text().toDouble());
        isEmpty = false;
    }
    if (ui->square->isChecked()) {
        emit addSquare(ui->xx->text().toDouble());
        isEmpty = false;
    }
    if (ui->ellipse->isChecked()) {
        emit addEllipse(ui->xx->text().toDouble() / 2,
                        ui->yy->text().toDouble() / 2);
        isEmpty = false;
    }
    if (ui->circle->isChecked()) {
        emit addCircle(ui->xx->text().toDouble());
        isEmpty = false;
    }
}

void Interface::on_setCenter_clicked()
{
    centerSet = true;
    emit setCenter(ui->xxc->text().toDouble(), ui->yyc->text().toDouble());
}

void Interface::on_reset_clicked()
{
    ui->hh->setValue(0);
    ui->ww->setValue(0);
    ui->ii->setValue(0);
    ui->jj->setValue(0);
    ui->xx->setValue(0);
    ui->yy->setValue(0);
    ui->xxc->setValue(0);
    ui->yyc->setValue(0);
    isEmpty = true;
    emit clearFigureList();
}

void Interface::on_rect_clicked()
{
    ui->xx->setValue(0);
    ui->x_l->setText("X");
    ui->yy->setValue(0);
    ui->yy->setHidden(false);
    ui->y_l->setText("Y");
    ui->y_l->setHidden(false);
}

void Interface::on_square_clicked()
{
    ui->xx->setValue(0);
    ui->x_l->setText("Side");
    ui->yy->setValue(0);
    ui->yy->setHidden(true);
    ui->y_l->setHidden(true);
}

void Interface::on_ellipse_clicked()
{
    ui->xx->setValue(0);
    ui->x_l->setText("X");
    ui->yy->setValue(0);
    ui->yy->setHidden(false);
    ui->y_l->setText("Y");
    ui->y_l->setHidden(false);
}

void Interface::on_circle_clicked()
{
    ui->xx->setValue(0);
    ui->x_l->setText("Radius");
    ui->yy->setValue(0);
    ui->yy->setHidden(true);
    ui->y_l->setHidden(true);
}

void Interface::on_calc_clicked()
{
    if (!centerSet) {
        QMessageBox::warning(this, "Error",
                             "Please, set center first.");
        return;
    }

    if (isEmpty) {
        QMessageBox::warning(this, "Error",
                             "Please, add figures.");
        return;
    }

    if (!ui->random->isChecked() && !ui->regular->isChecked()) {
        QMessageBox::warning(this, "Error",
                             "Please, choose type.");
        return;
    }

    if (ui->random->isChecked())
        type = true;

    if (ui->regular->isChecked())
        type = false;

    emit calc(ui->ii->text().toDouble(),
              ui->jj->text().toDouble(),
              ui->ww->text().toDouble(),
              ui->hh->text().toDouble(),
              type);
}

void Interface::setResult(QString message)
{
    ui->res_field->setText(message);
}
