#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "box.h"
#include "particle.h"

class System {
  public:
    System();
    void updateRule();
    
    int particleNumber;
    double noiseStrength;
    Box simulationBox;
    std::vector<Particle> particles;

};

#endif