//
// Created by Vikky on 04/12/2025.
//

#ifndef GRAVITY_PLANET_HPP
#define GRAVITY_PLANET_HPP
#include <cmath>
#include "scri.hpp"
#include "threepp/threepp.hpp"


float lambda=6.674*std::pow(10,-11);

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

    void act(float dt) {
        speed.x+=acceleration.x*dt;
        speed.y+=acceleration.y*dt;
        speed.z+=acceleration.z*dt;
        pos.x+=speed.x*dt;
        pos.y+=speed.y*dt;
        pos.z+=speed.z*dt;

    }
    void update() {
        mesh->position.set(pos.x,pos.y,pos.z);
    }



    void setAcc(coords newAcceleration) {
        acceleration=newAcceleration;
    }
    float Mass(){
        return mass*std::pow(10,24);
    }
    float getRadius() {
        return radius;
    }
    float correctDistance(float value){
        return value*1000000;
    }
    void setSpeed(coords newSpeed) {
        speed=newSpeed;
    }
    void setPos(coords newPos) {
        pos=newPos;
    }
    coords getPos() {
        return pos;
    }

    float getDist(Planet other) {
        float xdiff=other.pos.x-pos.x; //må bare sjekke om det er riktig vei eller ikke
        float ydiff=other.pos.y-pos.y;
        float zdiff=other.pos.z-pos.z;
        float totalDiff=std::sqrt(xdiff*xdiff+ydiff*ydiff+zdiff*zdiff);
        return totalDiff;
    }
    coords determineAccelerationGenerated(Planet other){
        float xdiff=other.pos.x-pos.x; //må bare sjekke om det er riktig vei eller ikke
        float ydiff=other.pos.y-pos.y;
        float zdiff=other.pos.z-pos.z;
        float totalDiff=std::sqrt(xdiff*xdiff+ydiff*ydiff+zdiff*zdiff);
        coords angles={xdiff/totalDiff,ydiff/totalDiff,zdiff/totalDiff}; //normalized vecot
        float r=correctDistance(totalDiff);
        float acce=other.Mass()*lambda/(r*r);
        coords accelerationGenerated={acce*angles.x,acce*angles.y,acce*angles.z};
        return accelerationGenerated;

    }


    void makeMesh(threepp::Scene& scene) {
        geometry = threepp::SphereGeometry::create(radius);
        material = threepp::MeshBasicMaterial::create();
        material->color=threepp::Color::black;
        mesh = threepp::Mesh::create(geometry, material);
        scene.add(mesh);
    }
    std::shared_ptr<threepp::SphereGeometry> geometry;
    std::shared_ptr<threepp::MeshBasicMaterial> material;
    std::shared_ptr<threepp::Mesh> mesh;
};

#endif //GRAVITY_PLANET_HPP