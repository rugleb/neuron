#ifndef NEURON_MODEL_H
#define NEURON_MODEL_H

#include <cmath>
#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "vector.h"

struct Sample {
    vector x;
    int y;
};

typedef std::vector<Sample> Dataset;

template <typename T>
void shuffle(std::vector<T>);

int heaviside(double x);

class Model {
protected:
    vector w;
    void updateOutputFile(std::ofstream &file);
public:
    explicit Model();
    void train(Dataset dataset, std::size_t epochs, std::ofstream &file);
};

#endif
