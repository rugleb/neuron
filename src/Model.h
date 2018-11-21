#ifndef NEURON_MODEL_H
#define NEURON_MODEL_H

#include <vector>
#include <fstream>


struct Dataset {
    std::vector<double> X;
    size_t y;
};


class Model {
protected:
    std::vector<double> W;
    std::vector<Dataset> datasets;
    void updateOutputFile(std::ofstream &file);
public:
    explicit Model(std::vector<Dataset> datasets);
    ~Model();
    void train(std::ofstream &file);
};

#endif
