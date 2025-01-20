#include <iostream>
#include "system.h"

System::System(int particleNumber, double sideLength, double timeStep, double noiseStrength) {
    this->particleNumber = particleNumber;
    this->noiseStrength = noiseStrength;
    this->sideLength = sideLength;
    this->timeStep = timeStep;
    std::cout << "\ncreated system object\n";
}

void System::updateRule() {
    std::cout << "\nupdating\n";
}