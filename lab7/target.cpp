#include "target.h"
#include <random>

Target::Target()
{

}

void Target::clearList()
{
    w = h = i = j = 0;
    figures.clear();
}

void Target::createRectangle(double x, double y)
{
    figures.push_back(new Rectangle(x, y));
    figures.last()->setCenter(centerPoint);
}

void Target::createSquare(double side)
{
    figures.push_back(new Square(side));
    figures.last()->setCenter(centerPoint);
}

void Target::createEllipse(double x, double y)
{
    figures.push_back(new Ellipse(x, y));
    figures.last()->setCenter(centerPoint);
}

void Target::createCircle(double radius)
{
    figures.push_back(new Circle(radius));
    figures.last()->setCenter(centerPoint);
}

int Target::calculate(bool type)
{
    int ret = 0;

    if (type)
        ret = randomMethod();
    else ret = regularMethod();

    return ret;
}

int Target::randomMethod()
{
    int totalPoints = 0;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < this->i * j; i++) {
        if (!contains({distribution(generator) * w,
                      distribution(generator) * h})) {
            ++totalPoints;
        }
    }
    return totalPoints;
}

int Target::regularMethod()
{
    int totalPoints = 0;
    double dx = static_cast<double>(w)  / (i + 1);
    double dy = static_cast<double>(h) / (j + 1);
    for (auto i = 1; i <= this->i; ++i) {
        for (auto j = 1; j <= this->j; ++j) {
            if (!contains({dx * i, dy * j})) {
                ++totalPoints;
            }
        }
    }
    return totalPoints;
}

bool Target::contains(const QPointF& point)
{
    for (auto& figure : figures) {
        if (figure->contains(point))
            return true;
    }
    return false;
}
