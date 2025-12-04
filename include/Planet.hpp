//
// Created by Vikky on 04/12/2025.
//

#ifndef GRAVITY_PLANET_HPP
#define GRAVITY_PLANET_HPP
#include <cmath>

struct coords {
    float x;
    float y;
    float z;
};


class Planet {
    float mass;
    float radius;
    coords pos;
    coords speed={0,0,0};
    coords acceleration={0,0,0};
public:

    Planet() {
        mass=5.9;
        radius=6.3;
        pos={0,0,0}; //1=1 000 000 så en radius på 6.3 er 6 300 000meter
    };
    float Mass(){
        return mass*std::pow(10,24);
    }
    float Radius(){
        return radius*1000000;
    }
    coords determineAccelerationGenerated(){
    }

};

#endif //GRAVITY_PLANET_HPP