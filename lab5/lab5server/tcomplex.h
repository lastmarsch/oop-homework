#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include <iostream>
#include <QByteArray>
#include <math.h>
using namespace std;

class TComplex
{
    double _real, _img;
public:
    TComplex();
    TComplex(double real, double img);
    TComplex(const TComplex &other);
    TComplex(int other);

    double real() { return _real; }
    double img() { return _img; }

    void setReal(double real) { _real = real; }
    void setImg(double img) { _img = img; }

    friend  TComplex operator+(TComplex left, TComplex right);
    friend  TComplex operator+(TComplex left, int right);
    friend  TComplex operator+(int left, TComplex right);
    friend  TComplex operator-(TComplex left, TComplex right);
    friend  TComplex operator*(TComplex left, TComplex right);
    friend  TComplex operator*(TComplex left, int right);
    friend  TComplex operator*(int left, TComplex right);
    friend  TComplex operator/(TComplex left, TComplex right);

    TComplex& operator=(int& right);
    friend bool operator==(const TComplex& left, const TComplex& right);
    friend bool operator==(const TComplex& left, const int& right);
    friend  bool operator>(const TComplex& left, const int& right);

    friend TComplex sqrt( TComplex& c);

    friend ostream &operator<< (ostream& os, TComplex& p);
    friend istream &operator>> (istream& is, TComplex& p);
};

#endif // TCOMPLEX_H
