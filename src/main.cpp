#include <iostream>
#include "system.cpp"
#include "box.cpp"
#include "particle.cpp"


int main() {

    System system(500, 100.0, 0.5, 1, 12345);
    // system.updateRule();
    std::cout << "Box side x: " << system.simulationBox.getSidex();

    std::cout << "\nRandom: " << system.uniform(10, 20);

    system.randomStart();

    for (int i = 0; i < 1000 ; ++i) {
        system.updateRule();
        system.saveConfig("frames/frame"+std::to_string(i));
    }

};