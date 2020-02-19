#include "polynom.h"
#include <QDebug>
#include <math.h>

Polynom::Polynom()
{
    a = 0;
    b = 0;
    c = 0;
}

Polynom::Polynom(number a, number b, number c)
    : a(a)
    , b(b)
    , c(c)
{
}

bool Polynom::check()
{
    if (a == 0)
        return false;
    return true;
}

int Polynom::roots(number *x)
{
    number D = b * b - 4 * a * c;
    if (D > 0) {
        x[0] = (-1 * b + sqrt(D)) / (2 * a);
        x[1] = (-1 * b - sqrt(D)) / (2 * a);
        return 2;
    }
    if (D == 0) {
        x[0] = -1 * b / (2 * a);
        x[1] = x[0];
        return 1;
    }
    return 0;
}


ostream & operator<<(ostream &os, Polynom &p)
{
    os << p.a << " * x^2 + " << p.b << " * x + " << p.c << endl;
    return os;
}
