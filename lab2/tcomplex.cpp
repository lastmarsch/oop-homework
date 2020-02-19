#include "tcomplex.h"

TComplex::TComplex()
    : _real(0)
    , _img(0)
{

}

TComplex::TComplex(double real, double img)
    : _real(real)
    , _img(img)
{

}

TComplex::TComplex(const TComplex &other)
{
    _real = other._real;
    _img = other._img;
}

TComplex operator+(int left, TComplex right)
{
    TComplex c;
    c._real = right._real + left;
    c._img = right._real;
    return c;
}

TComplex operator+(TComplex left, int right)
{
    TComplex c;
    c._real = left._real + right;
    c._img = left._real;
    return c;
}

TComplex &TComplex::operator=(const int &right)
{
    if (right == 0) {
        this->_real = 0;
        this->_img = 0;
    }
    return *this;
}

bool operator>(const TComplex &left, const int &right)
{
    return true;
}

TComplex sqrt(TComplex &c)
{
    double r = sqrt(c._real * c._real + c._img * c._img); // модуль
    double phi = std::atan(c._img / c._real); //угол
    TComplex c1;
    c1._real = std::sqrt(r) * (std::cos(phi / 2));
    c1._img = std::sqrt(r) * (std::sin(phi / 2));
    return c1;
}

TComplex operator+(TComplex left, TComplex right)
{
    TComplex c;
    c._real = left._real + right._real;
    c._img = left._img + right._img;
    return c;
}

TComplex operator-(TComplex left, TComplex right)
{
    TComplex c;
    c._real = left._real - right._real;
    c._img = left._img - right._img;
    if (std::abs(left._img - right._img) < 0.001)
        c._img = 0;
    return c;
}

TComplex operator*(TComplex left, TComplex right)
{
    TComplex c;
    c._real = left._real * right._real - left._img * right._img;
    c._img = left._real * right._img + left._img * right._real;
    return c;
}

TComplex operator*(TComplex left, int right)
{
    TComplex c;
    c._real = left._real * right;
    c._img = left._img * right;
    return c;
}

TComplex operator*(int left, TComplex right)
{
    TComplex c;
    c._real = right._real * left;
    c._img = right._img * left;
    return c;
}

TComplex operator/(TComplex left, TComplex right)
{
    TComplex c;
    double tmp = right._real * right._real + right._img * right._img;
    c._real = (left._real * right._real + left._img * right._img)
            / tmp;
    c._img = (left._img * right._real - left._real * right._img)
            / tmp;
    return c;
}

bool operator==(const TComplex &left, const TComplex &right)
{
    if (left._real == right._real && left._img == right._img)
        return true;
    return false;
}

bool operator==(const TComplex &left, const int &right)
{
    if (left._real == right && left._img == right && right == 0)
        return true;
    return false;
}

istream& operator>>(istream &is, TComplex &p)
{
    cout << "real = ";
    is >> p._real;
    cout << "img = ";
    is >> p._img;
    return is;
}

ostream& operator<<(ostream &os, TComplex &p)
{
    if (p.real() != 0) {
        if (p.img() > 0)
            os << "(" << p.real() << " + " << p.img() << " * i)";
        else if (p.img() < 0)
            os << "(" << p.real() << " - " << p.img() * -1 << " * i)";
        else os << p.real();
    }
    else {
        if (p.img() > 0)
            os << "(" << p.img() << " * i)";
        else if (p.img() < 0)
            os << "( - " << p.img() * -1 << " * i)";
        else os << p.real();
    }
    return os;
}

