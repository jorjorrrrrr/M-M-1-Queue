#ifndef EXPONENTIALRAND_H
#define EXPONENTIALRAND_H

class exponentialRand {
public:
    exponentialRand();
    exponentialRand(unsigned int seed, double lambda);
    double eRand();
private:
    unsigned int seed;
    double lambda;
};

#endif