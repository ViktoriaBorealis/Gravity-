//
// Created by Vikky on 04/12/2025.
//

#include "Planet.hpp"
#include <iostream>
#include <vector>
#include "threepp/threepp.hpp"
#include "Drawer.hpp"

int main() {
    threepp::Canvas canvas("bleep");
    threepp::Scene scene;
    threepp::GLRenderer renderer(canvas.size());
    threepp::PerspectiveCamera camera(60, canvas.aspect(), 1.7, 1000);

    canvas.onWindowResize([&](threepp::WindowSize size) {
        camera.aspect = size.aspect();
        camera.updateProjectionMatrix();
        renderer.setSize(size);
    });
    threepp::Clock clock;
    scene.background = threepp::Color::aliceblue;

    std::vector<Planet*> planets;
    Planet bob;
    Planet matrise;
    planets.push_back(&bob);
    planets.push_back(&matrise);

    matrise.setPos({4,3,15});
    bob.setPos({-4,-3,-15});

    matrise.setSpeed({0,2,0});
    bob.setSpeed({0,-2,0});





    camera.position.set(40,0,0);
    bob.makeMesh(scene);
    matrise.makeMesh(scene);
    canvas.animate([&] {
        const auto dt = clock.getDelta();
        camera.lookAt({0,0,0});
        camera.updateProjectionMatrix();

        for(int i=0;i<planets.size();i++) {
            coords generatedAcceleration={0,0,0};
            for (int j=0;j<planets.size();j++) {
                if (planets[j]!=planets[i]) {
                   coords newacc=planets[i]->determineAccelerationGenerated(*planets[j]);
                    generatedAcceleration.x+=newacc.x;
                    generatedAcceleration.y+=newacc.y;
                    generatedAcceleration.z+=newacc.z;
                }
            }
            planets[i]->setAcc(generatedAcceleration);
        }


        bob.act(dt);
        matrise.act(dt);
        //std::cout<<bob.getDist(matrise)<<std::endl;
        bob.update();
        matrise.update();

        renderer.render(scene, camera);

    });
    return(1);
}