//
//  CScene.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"

#include<fstream>

/// \fn create(void)
/// \brief Adds components to the scene.
///
void CScene::create() {
    
    lightList.clear(); // clears vector with the light data
    objectList.clear(); // clears vector of pointers to objects
    
    // add camera, light sources, and objects
    cam.eyep = glm::vec3 (0.0,0.0,10.0);
    cam.lookp = glm::vec3 (0.0,0.0,0.0);
    cam.up = glm::vec3 (0.0,1.0,0.0);
    cam.fov = 50;
    cam.width = 500;
    cam.height = 400;

    //create objects
    CSphere * sphere1 = new CSphere({-2.5,1.3,-3},1.0);
    CSphere * sphere2 = new CSphere({0,0,0},1.6);
    //testowy obiekt
    //CSphere * sphere3 = new CSphere({0,0,0},5.0);

    //add objects to list
    objectList.push_back(sphere1);
    objectList.push_back(sphere2);
    //objectList.push_back(sphere3);


}

