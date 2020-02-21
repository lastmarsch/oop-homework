#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include <QDebug>
#include <math.h>
/*
класс полинома
*/

using namespace std;

template<class T>
class Polynom
{
    T a, b, c;
public:
    Polynom();
    Polynom(T, T, T);

    T A() { return a; }
    T B() { return b; }
    T C() { return c; }

    bool check();
    int roots(T *x);
//    friend ostream& operator<< (ostream& os, Polynom p);

};

template<class T>
Polynom<T>::Polynom() : a(0), b(0), c(0)
{

}

template<class T>
Polynom<T>::Polynom(T a, T b, T c)
    : a(a)
    , b(b)
    , c(c)
{
}

template<class T>
bool Polynom<T>::check()
{
    if (a == 0)
        return false;
    return true;
}

template<class T>
int Polynom<T>::roots(T *x)
{
    T D = b * b - 4 * a * c;
    if (D > 0) {
        x[0] = (-1 * b + sqrt(D)) / (2 * a);
        x[1] = (-1 * b - sqrt(D)) / (2 * a);
        return 2;
    }
    if (D == 0) {
        x[0] = -1 * b / (2 * a);
        return 1;
    }
    return 0;
}

//template<class T>
//ostream & operator<<(ostream &os, Polynom<T> p)
//{
//    os << p.a << " * x^2 + " << p.b << " * x + " << p.c << endl;
//    return os;
//}


#endif // POLYNOM_H
