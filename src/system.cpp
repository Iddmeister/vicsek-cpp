#include <iostream>
#include "system.h"

System::System(int particleNumber, double sideLength, double timeStep, double noiseStrength, int seed) {
    
    this->particleNumber = particleNumber;
    this->particles.resize(particleNumber);
    this->noiseStrength = noiseStrength;
    this->sideLength = sideLength;
    this->timeStep = timeStep;
    this->simulationBox = Box(sideLength, sideLength, 0, 0);

    this->gen = std::mt19937(seed);


    std::cout << "\ncreated system object\n";
}

void System::updateRule() {
    std::cout << "\nupdating\n";
}

double System::uniform(double min, double max) {
    return (max-min)*this->uniformDist(this->gen)+min;
}