#include <iostream>
#include "system.cpp"
#include "box.cpp"
#include "particle.cpp"


int main() {
    System system(100, 20.0, 0.5, 0.1, 1234);
    system.updateRule();
    std::cout << "Box side x: " << system.simulationBox.getSidex();

    std::cout << "\nRandom: " << system.uniform(10, 20);

};