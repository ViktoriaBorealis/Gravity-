//
// Created by Vikky on 05/12/2025.
//

#ifndef GRAVITY_DRAWER_HPP
#define GRAVITY_DRAWER_HPP
#include "Planet.hpp"
#include "scri.hpp"

class Drawer {
    threepp::Scene& scene;
public:
    Drawer(threepp::Scene& scene):scene(scene) {

    };

    void draw(Planet* plont) {
        float radius=plont->getRadius();
        coords pos=plont->getPos();
    }


};

#endif //GRAVITY_DRAWER_HPP