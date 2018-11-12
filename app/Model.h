#ifndef NEURON_MODEL_H
#define NEURON_MODEL_H

#include <fstream>

class Model {
protected:
public:
    Model();
    void run();
    void dump(std::fstream &file);
    void load(std::fstream &file);
};

#endif
