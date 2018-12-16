#ifndef NEURON_SUPPORT_H
#define NEURON_SUPPORT_H

#include <vector>

typedef std::vector<double> vector;

vector operator* (const vector &, double);
double operator* (const vector &, const vector &);
vector operator+ (const vector &, const vector &);
vector operator- (const vector &, const vector &);

#endif
