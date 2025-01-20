#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {

    public:

        Particle();
        Particle(double x, double y, double angle, double velocity, double interaction_radius);

        double x;
        double y;
        double angle;
        double velocity;
        double interaction_radius;

};

#endif