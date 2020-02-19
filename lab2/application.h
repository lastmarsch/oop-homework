#ifndef APPLICATION_H
#define APPLICATION_H

#include "polynom.h"

/*
предназначен для ввода коэффициентов полинома, значения
аргумента, инициализации процесса вычисления корней,
инициализации процесса вычисления значения и вывода
результатов
*/

class Application
{
    void menu();
public:
    Application();
    int exec();
};

#endif // APPLICATION_H
