#include <iostream>
#include "system.cpp"
#include "box.cpp"


int main() {
    System system(100, 20.0, 0.5, 0.1);
    system.updateRule();
    std::cout << "Box side x: " << system.simulationBox.getSidex();
};