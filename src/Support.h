#ifndef NEURON_SUPPORT_H
#define NEURON_SUPPORT_H

#include <vector>

#define D_VECTOR    std::vector<double>


int heaviside(double x);

D_VECTOR operator* (const D_VECTOR &, double);
double   operator* (const D_VECTOR &, const D_VECTOR &);
D_VECTOR operator+ (const D_VECTOR &, const D_VECTOR &);
D_VECTOR operator- (const D_VECTOR &, const D_VECTOR &);

double sum (const D_VECTOR &);
double mid (const D_VECTOR &);

#endif
