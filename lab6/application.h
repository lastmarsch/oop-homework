#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDebug>
#include "gui.h"
#include "holst.h"


class Application : public QApplication
{
public:
    Application(int &argc, char **argv);
    virtual ~Application() = default;

    void draw();

public slots:
    void addToList(Sample s);

private:
    Holst * holst;
    Painter * painter;
    GUI * interface;
    QList<Sample> sample;
};

#endif // APPLICATION_H
