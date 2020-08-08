#include "nn.h"

#include <math.h>
#include <QDebug>

NN::NN(int units, double lr)
    : hiddenUnits(units),
      learningRate(lr)
{
    weights.reserve(hiddenUnits);
    initWeights();
}

void NN::initWeights() {
    for (auto i = 0;i < this->hiddenUnits; i++)
        weights.push_back(Utilities::getRandomNum(-1,1));
}

int NN::activation(double input) {
    if (input > 0.0) return 1;
    else if(input < 0.0) return -1;
    else return 0;
//     return (1.0 / ( 1.0 + exp(-input)));
}

double NN::sigmoidDerivative(double output) {
    return (output * (1.0 - output));
}

void NN::train(v_d input, double output) {
    int guess = feedForward(input);
    double error = (output - (double) guess);
//    error = error * error;
//    error *= sigmoidDerivative(error);
    backPropagation(error, input);
}

int NN::feedForward(v_d input) {
    Q_ASSERT(weights.size() == input.size());
    double sum = 0.0;
    for (int i = 0; i < (int) weights.size(); i++) {
        sum += weights[i] * input[i];
    }
    return activation(sum);
}

void NN::backPropagation(double error, v_d input) {
    Q_ASSERT(weights.size() == input.size());
    for (int i = 0; i < (int) weights.size(); i++) {
        weights[i] += learningRate * error * input[i];
    }
}

v_d NN::getWeights() {
    return weights;
}
