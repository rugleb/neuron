#include "vector.h"

vector operator*(const vector &a, double b)
{
    auto size = a.size();
    vector y(size);

    for (auto i = 0; i < size; i++) {
        y[i] = a[i] * b;
    }

    return y;
}

double operator*(const vector &a, const vector &b)
{
    auto size = a.size();
    double y = 0.;

    for (auto i = 0; i < size; i++) {
        y = a[i] * b[i];
    }

    return y;
}

vector operator+(const vector &a, const vector &b)
{
    auto size = a.size();
    vector y(size);

    for (auto i = 0; i < size; i++) {
        y[i] = a[i] + b[i];
    }

    return y;
}

vector operator-(const vector &a, const vector &b)
{
    auto size = a.size();
    vector y(size);

    for (auto i = 0; i < size; i++) {
        y[i] = a[i] - b[i];
    }

    return y;
}
