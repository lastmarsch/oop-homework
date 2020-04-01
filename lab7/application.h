#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include "interface.h"
#include "result.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char **argv);
    virtual ~Application();

private:
    Interface * gui;
    Target * target;
    Result * result;
};

#endif // APPLICATION_H
