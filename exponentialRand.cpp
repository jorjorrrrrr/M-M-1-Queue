#include "exponentialRand.h"
#include <iostream>
#include <cmath>

exponentialRand::exponentialRand() {
    srand(0);
    this->seed = 0;
    this->lambda = 0.05;
}

exponentialRand::exponentialRand(unsigned int seed, double lambda) {
    srand(seed);
    this->seed = seed;
    this->lambda = lambda;
}

double exponentialRand::eRand() {
    double r = rand() / (RAND_MAX + 1.0);   // generate r ∈ [0, 1]
    return ((-1 * log(r)) / lambda);
}