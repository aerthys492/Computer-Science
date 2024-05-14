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
    CCamera cam;
    cam.eyep = glm::vec3 (0.0,0.0,10.0);
    cam.lookp = glm::vec3 (0.0,0.0,0.0);
    cam.up = glm::vec3 (0.0,1.0,0.0);
    cam.fov = 50;
    cam.width = 500;
    cam.height = 400;


}

