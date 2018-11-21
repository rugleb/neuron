#ifndef NEURON_DATASET_H
#define NEURON_DATASET_H

#include <vector>

struct Dataset {
    std::vector<double> X;
    size_t y;
};

#endif
