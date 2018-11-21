#include <cmath>
#include "Support.h"

std::size_t heaviside(double x)
{
    return x < 0 ? 0 : 1;
}

D_VECTOR operator*(const D_VECTOR &a, double b)
{
    std::size_t size = a.size();
    D_VECTOR y(size);

    for (std::size_t i = 0; i < size; i++) {
        y[i] = a[i] * b;
    }

    return y;
}

double operator*(const D_VECTOR &a, const D_VECTOR &b)
{
    std::size_t size = a.size();
    double y = 0.;

    for (std::size_t i = 0; i < size; i++) {
        y = a[i] * b[i];
    }

    return y;
}

D_VECTOR operator+(const D_VECTOR &a, const D_VECTOR &b)
{
    std::size_t size = a.size();
    D_VECTOR y(size);

    for (std::size_t i = 0; i < size; i++) {
        y[i] = a[i] + b[i];
    }

    return y;
}

D_VECTOR operator-(const D_VECTOR &a, const D_VECTOR &b)
{
    std::size_t size = a.size();
    D_VECTOR y(size);

    for (std::size_t i = 0; i < size; i++) {
        y[i] = a[i] - b[i];
    }

    return y;
}

double sum(const D_VECTOR &x)
{
    double y = .0;

    for (double i : x) {
        y += i;
    }

    return y;
}

double mid(const D_VECTOR &x)
{
    return sum(x) / x.size();
}
