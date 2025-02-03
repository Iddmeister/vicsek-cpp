#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "box.h"
#include "particle.h"
#include <random>

class System {
  public:

    System(int particleNumber, double sideLength, double timeStep, double noiseStrength, int seed);
    
    void updateRule();

    double uniform(double min, double max);
    
    void randomStart();

    void saveConfig(const std::string &filename);

    int particleNumber;
    double noiseStrength;
    double sideLength;
    double timeStep;

    Box simulationBox;

    std::vector<Particle> particles;
    std::mt19937 gen;
    std::uniform_real_distribution<double> uniformDist;

};

#endif