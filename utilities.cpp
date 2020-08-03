#include "utilities.h"

#include <random>

namespace Utilities {

double getRandomNum(int low, int high) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dsAlien(low, high);

    double size = dsAlien(mt);
    return size;
}

int mapNumbers(double current, double oldMin, double oldMax, double min, double max) {
    double OldRange = (oldMax - oldMin);
    double NewRange = (max - min);
    return  (((current - oldMin) * NewRange) / OldRange) + min;
}

}
