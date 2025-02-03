#include <iostream>
#include "system.h"
#include <math.h>
#include <fstream>

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
    // std::cout << "\nupdating\n";

    double new_angles[this->particles.size()];

    for (int i = 0; i < this->particles.size(); ++i) {

        Particle current = particles[i];

        if (current.x > this->simulationBox.getSidex()) {
            particles[i].x -= this->simulationBox.getSidex();
        } else if (current.x < 0) {
            particles[i].x += this->simulationBox.getSidex();
        }

        if (current.y > this->simulationBox.getSidey()) {
            particles[i].y -= this->simulationBox.getSidey();
        } else if (current.y < 0) {
            particles[i].y += this->simulationBox.getSidey();
        }

        int total = 1;
        double total_x_dir = 0; //sin(current.angle);
        double total_y_dir = 0; //cos(current.angle);


        for (int j = 0; j < this->particles.size(); ++j) {

            // if (i == j) { continue; }

            Particle neighbour = particles[j];

            double distance = sqrt(pow(current.x-neighbour.x, 2)+pow(current.y-neighbour.y, 2));
            // double distance = abs(sqrt(pow(current.x, 2)+pow(current.y, 2))-sqrt(pow(neighbour.x, 2)+pow(neighbour.y, 2)));
            
            // std::cout << distance;

            double offsetX = 0;
            double offsetY = 0;

            if (current.x < current.interaction_radius) {
                offsetX += this->simulationBox.getSidex();
            } else if (current.x > this->simulationBox.getSidex()-current.interaction_radius) {
                offsetX -= this->simulationBox.getSidex();
            }

            if (current.y < current.interaction_radius) {
                offsetY += this->simulationBox.getSidey();
            } else if (current.y > this->simulationBox.getSidey()-current.interaction_radius) {
                offsetY -= this->simulationBox.getSidey();
            }

            double distanceWrapped = abs(sqrt((current.x+offsetX, 2)+pow(current.y+offsetY, 2))-sqrt((neighbour.x, 2)+pow(neighbour.y, 2)));

            if (distance <= current.interaction_radius) {// || distanceWrapped <= current.interaction_radius) {
                
                total++;

                double x_dir = sin(neighbour.angle);
                double y_dir = cos(neighbour.angle);
                total_x_dir += x_dir;
                total_y_dir += y_dir;


            }


        }

        total_x_dir /= total;
        total_y_dir /= total;


        double avg_angle = atan2(total_x_dir, total_y_dir);

        avg_angle += this->uniform(-this->noiseStrength/2, this->noiseStrength/2);

        new_angles[i] = avg_angle;
    
    }


    for (int i = 0; i < this->particles.size(); ++i) {
        particles[i].x += cos(new_angles[i]) * particles[i].velocity * this->timeStep;
        particles[i].y += sin(new_angles[i]) * particles[i].velocity * this->timeStep;
        particles[i].angle = new_angles[i];
    } 


}

double System::uniform(double min, double max) {
    return (max-min)*this->uniformDist(this->gen)+min;
}

void System::randomStart() {

    for (Particle &p : this->particles) {
        p.x = this->uniform(0, this->simulationBox.getSidex());
        p.y = this->uniform(0, this->simulationBox.getSidey());
        p.angle = this->uniform(-M_PI, M_PI);

    }

}

void System::saveConfig(const std::string &filename) {

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error you fucking idiot, cannot open file: " << filename << std::endl;
        return;
    }

    outFile << std::to_string(particles.size()) + "\nParticles" << std::endl;

    for (size_t i = 0; i < particles.size(); ++i) {
        outFile << i << " " << particles[i].x << " " << particles[i].y << " " << particles[i].angle << std::endl;
    }

    outFile.close();

}
