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
    std::shared_ptr<Holst> holst;
    std::shared_ptr<Painter> painter;
    GUI * interface;
    QList<Sample> sample;
};

#endif // APPLICATION_H
