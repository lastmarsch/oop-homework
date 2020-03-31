#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "sample.h"

namespace Ui {
class GUI;
}

class GUI : public QWidget
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = nullptr);
    ~GUI();

private slots:
    void on_tr_clicked();

    void on_rbtr_clicked();

    void on_rstr_clicked();

    void on_pushButton_clicked();

signals:
    void addSampleToList(Sample);

private:
    Ui::GUI *ui;
};

#endif // GUI_H
