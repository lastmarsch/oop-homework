#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include "number.h"

/*
класс полинома
*/

using namespace std;

class Polynom
{
    number a, b, c;
public:
    Polynom();
    Polynom(number, number, number);

    bool check();
    int roots(number *x);
    double res(number x);
    friend ostream& operator<< (ostream& os, Polynom& p);
};

#endif // POLYNOM_H
