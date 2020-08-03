#include "training.h"

Training::Training(v_d vd, double answer)
    : input(vd),
      output(answer)
{

}

double Training::getOutput() {
    return output;
}
