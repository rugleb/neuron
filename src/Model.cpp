#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "Model.h"
#include "Support.h"


Model::Model(std::vector<Dataset> sets)
{
    datasets = std::move(sets);
}

Model::~Model()
{
    W.clear();
    datasets.clear();
}

void Model::train(std::ofstream &file)
{
    unsigned int epoch;
    unsigned int errors;

    W = D_VECTOR(datasets.front().X.size() + 1, .1);
    updateOutputFile(file);

    for (epoch = 0, errors = 0; epoch < 1e+2; epoch++) {
        std::random_shuffle(datasets.begin(), datasets.end());

        for (auto set : datasets) {
            D_VECTOR X = set.X;
            X.insert(X.begin(), 1.);

            std::size_t y = heaviside(W * X);

            if (y != set.y) {
                W = W + X * (set.y - y);
                updateOutputFile(file);
                errors++;
            }
        }

        if (errors == 0) break;
    }
}

void Model::updateOutputFile(std::ofstream &file)
{
    file << "plot (" << -W[0] / W[1] << ") + (" << -W[1] / W[2] << ") * x, \\" << std::endl;
    file << "'zeros.txt' using 1:2 w p lt rgb 'blue', \\" << std::endl;
    file << "'ones.txt' using 1:2 w p lt rgb 'red'" << std::endl;
    file << "pause 0.25" << std::endl;
}
