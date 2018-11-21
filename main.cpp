#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "src/Model.h"

#define PI          3.14
#define RADIUS      10

double rand(double min, double max)
{
    double f = (double) rand() / RAND_MAX;
    return min + f * (max - min);
}

std::vector<Dataset> generate(size_t R, size_t group, double_t x0, double_t y0, std::ofstream &file)
{
    std::vector<Dataset> dataset;

    for (std::size_t size i = 0; i < 1e+3; i++) {
        double r = R * rand(0., 1.);
        double angle = rand(0., 1.) * 2. * PI;

        double_t x = r * cos(angle) + x0;
        double_t y = r * sin(angle) + y0;

        Dataset set = {{x, y}, group};
        dataset.push_back(set);

        file << x << '\t' << y << std::endl;
    }

    return dataset;
}

std::vector<Dataset> concat(std::vector<Dataset> a, std::vector<Dataset> b)
{
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void prepareOutputFile(std::ofstream &file)
{
    file << "set xrange[" << -3 * RADIUS << ":" << 3 * RADIUS << "]" << std::endl;
    file << "set yrange[" << -1 * RADIUS << ":" << 3 * RADIUS << "]" << std::endl;
    file << "set xlabel 'x1'" << std::endl;
    file << "set ylabel 'x2'" << std::endl;
}

int main()
{
    std::ofstream ones("ones.txt");
    std::ofstream zeros("zeros.txt");

    std::vector<Dataset> setA = generate(RADIUS, 1, RADIUS * 1.05, RADIUS, ones);
    std::vector<Dataset> setB = generate(RADIUS, 0, -RADIUS * 1.05, RADIUS, zeros);

    std::vector<Dataset> dataset = concat(setA, setB);

    std::ofstream file("output.txt");
    prepareOutputFile(file);

    Model model(dataset);
    model.train(file);

    return 0;
}
