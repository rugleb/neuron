#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "Model.h"
#include "Dataset.h"

#define DVector std::vector<double>


double multiply(DVector A, DVector B) {
    double y = 0.;
    for (size_t i = 0; i < A.size(); i++) {
        y += A[i] * B[i];
    }
    return y;
}

DVector multiply(DVector A, double b) {
    DVector y;
    for (size_t i = 0; i < A.size(); i++) {
        y.push_back(A[i] * b);
    }
    return y;
}

DVector sum(DVector A, DVector B) {
    DVector y;
    for (size_t i = 0; i < A.size(); i++) {
        y.push_back(A[i] + B[i]);
    }
    return y;
}

int heaviside(double x) {
    return x < 0 ? 0 : 1;
}

Model::Model(std::vector<Dataset> sets) {
    datasets = std::move(sets);
}

Model::~Model() {
    W.clear();
    datasets.clear();
}

void Model::train(std::ofstream &file) {

    unsigned int epoch;
    unsigned int errors;

    W = DVector(datasets.front().X.size() + 1, .1);
    updateOutputFile(file);

    for (epoch = 0, errors = 0; epoch < 1e+2; epoch++) {
        std::random_shuffle(datasets.begin(), datasets.end());

        for (auto set : datasets) {
            DVector X = set.X;
            X.insert(X.begin(), 1.);

            int y = heaviside(multiply(W, X));

            if (y != set.y) {
                W = sum(W, multiply(X, set.y - y));
                updateOutputFile(file);
                errors++;
            }
        }

        if (errors == 0) break;
    }
}

void Model::updateOutputFile(std::ofstream &file) {
    file << "plot (" << -W[0] / W[1] << ") + (" << -W[1] / W[2] << ") * x, \\" << std::endl;
    file << "'zeros.txt' using 1:2 w p lt rgb 'blue', \\" << std::endl;
    file << "'ones.txt' using 1:2 w p lt rgb 'red'" << std::endl;
    file << "pause 1.5" << std::endl;
}
