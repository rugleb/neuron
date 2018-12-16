#include "Model.h"

int heaviside(double x)
{
    return x < 0. ? 0 : 1;
}

template <typename T>
void shuffle(std::vector<T> vector)
{
    std::random_device device;
    std::mt19937 generator(device());
    std::shuffle(vector.begin(), vector.end(), generator);
}

Model::Model()
{
    w = {};
}

void Model::train(Dataset dataset, std::size_t epochs, std::ofstream &file)
{
    w = vector(dataset.front().x.size() + 1, .1);
    updateOutputFile(file);

    auto error = 0;
    printf("Training started\n");

    for (auto epoch = 0; epoch < epochs; epoch++) {

        shuffle(dataset);
        error = 0;

        for (const Sample &set : dataset) {
            vector x = set.x;
            x.insert(x.begin(), 1.);

            int y = heaviside(w * x);

            if (y != set.y) {
                w = w + x * (set.y - y);
                updateOutputFile(file);
                error++;
            }
        }

        printf("---- Epoch: %2d, error: %2d (%ld)\n", epoch + 1, error, dataset.size());

        if (error == 0) break;
    }

    updateOutputFile(file);
    printf("Training finished\n");
}

void Model::updateOutputFile(std::ofstream &file)
{
    file << "plot (" << -w[0] / w[1] << ") + (" << -w[1] / w[2] << ") * x, \\" << std::endl;
    file << "'zeros.txt' using 1:2 w p lt rgb 'blue', \\" << std::endl;
    file << "'ones.txt' using 1:2 w p lt rgb 'red'" << std::endl;
    file << "pause 0.5" << std::endl;
}
