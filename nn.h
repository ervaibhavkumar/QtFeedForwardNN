#ifndef NN_H
#define NN_H

#include <QObject>

#include "config.h"
#include "utilities.h"

class NN : public QObject
{
    Q_OBJECT
public:
    NN(int units, double lr);
    void train(v_d input, double output);
    v_d getWeights();

private:
    void initWeights();
    int activation(double input);
    double sigmoidDerivative(double output);
    int feedForward(v_d input);
    void backPropagation(double error, v_d input);

    int hiddenUnits;
    double learningRate;

    v_d weights;
};

#endif // NN_H
