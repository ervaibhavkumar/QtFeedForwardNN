#ifndef TRAINING_H
#define TRAINING_H

#include <vector>

#include "config.h"

class Training
{
public:
    Training(v_d vd, double answer);
    double getOutput();
    v_d getInput();

private:
    v_d input;
    double output;
};

#endif // TRAINING_H
