#include <cmath>
#include <fstream>

#include "src/Model.h"

#define PI          3.14
#define R           10

double rand(double min, double max)
{
    double f = (double) rand() / RAND_MAX;
    return min + f * (max - min);
}

Dataset generate(int group, double x0, double y0, std::ofstream &file)
{
    Dataset dataset;

    for (auto i = 0; i < 1e+3; i++) {
        double r = R * rand(0., 1.);
        double angle = rand(0., 1.) * 2. * PI;

        double x = r * cos(angle) + x0;
        double y = r * sin(angle) + y0;

        Sample set = {{x, y}, group};
        dataset.push_back(set);

        file << x << '\t' << y << std::endl;
    }

    return dataset;
}

Dataset concat(Dataset a, Dataset b)
{
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void prepareOutputFile(std::ofstream &file)
{
    file << "set xrange[" << -3 * R << ":" << 3 * R << "]" << std::endl;
    file << "set yrange[" << -1 * R << ":" << 3 * R << "]" << std::endl;
    file << "set xlabel 'x1'" << std::endl;
    file << "set ylabel 'x2'" << std::endl;
}

int main()
{
    std::ofstream ones("ones.txt");
    std::ofstream zeros("zeros.txt");

    Dataset set1 = generate(1, R * 1.5, R, ones);
    Dataset set0 = generate(0, -R * 1.5, R, zeros);

    Dataset dataset = concat(set0, set1);

    std::ofstream file("output.txt");
    prepareOutputFile(file);

    Model model;
    model.train(dataset, 2, file);

    return 0;
}
