#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

const int xMin = -1;
const int yMin = -1;
const int xMax = 1;
const int yMax = 1;
const int trainItems = 1000;

const double trainingSlope = 0.3;
const double trainingIntercept = 0.4;

const int hiddenUnits = 3;
const double learningRate = 0.001;

typedef std::vector<double> v_d;

#endif // CONFIG_H
