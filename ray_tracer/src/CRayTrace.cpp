//
//  CRayTrace.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"


/// \fn compPrimaryRayMatrix(CCamera cam, glm::mat3& m)
/// \brief Computation of the projection matrix.
/// \param cam Camera parameters.
/// \param m Output projection matrix.
///
bool CRayTrace::compPrimaryRayMatrix(const CCamera& cam, glm::mat3& m) {
    glm::vec3 eyep = cam.eyep;
    glm::vec3 lookp = cam.lookp;
    glm::vec3 up = cam.up;
    float fov = cam.fov;
    int width = cam.width;
    int height = cam.height;
    float radian = fov/2.0f * (3.14f / 180.0f);

    glm::vec3 look = lookp - eyep;
    glm::vec3 u = glm::cross(up, look) / glm::length(glm::cross(up, look));
    glm::vec3 v = glm::cross(u, look) / glm::length(glm::cross(u, look));
    glm::vec3 o = (look / glm::length(look)) * (width /( 2.0f * tan(radian))) - ((width / 2.0f) * u + (height / 2.0f) * v);

    m[0] = u;
    m[1] = v;
    m[2] = o;

    return true;
}



/// \fn rayTrace(CScene scene, CRay& ray, COutput& out)
/// \brief Traces single ray.
/// \param scene Object with all scene components including a camera.
/// \param ray Ray parameter (primary and secondary rays).
/// \param out Object with output color and parameters used in recursion.
///
bool CRayTrace::rayTrace(const CScene& scene, CRay& ray, COutput& out) {

    /// looks for the closest object along the ray path
    /// returns false if there are no intersection
    CObject* hit_obj;
    float t_min = FLT_MAX;
    const float EPS = 0.0001f;
    bool is_intersection = false;

    // for each object in CScene::objectList
    for (auto &obj : scene.objectList) {
        float t = obj->intersect(ray);
        if (t > EPS && t < t_min) {
            t_min = t;
            hit_obj = obj;
            is_intersection = true;
        }
    }
    if(is_intersection == true){
        ;out.col = {0,0.6,0};
    }else{
        out.col = {0,0,0};
        return false;
    }

    /// computes 3D position of the intersection point

    /// computes normal vector at intersection point

    /// for each light source defined in the scene

        /// computes if the intersection point is in the shadows

        /// computes diffuse color component

        /// computes specular color component

    /// adds texture for textured spheres

    /// computes ambient color component

    /// if the surface is reflective

        /// if out.tree >= MAX_RAY_TREE return from function

        /// computes the secondary ray parameters (reflected ray)

        /// recursion
        //   rayTrace(scene, secondary_ray, out);


    return true;
}


/// \fn reflectedRay(CRay ray, glm::vec3 n, glm::vec3 pos)
/// \brief Computes parameters of the ray reflected at the surface point with given normal vector.
/// \param ray Input ray.
/// \param n Surface normal vector.
/// \param pos Position of reflection point.
/// \return Reflected ray.
///
CRay CRayTrace::reflectedRay(const CRay& ray, const glm::vec3& n, const glm::vec3& pos) {
    CRay reflected_ray;
    
    return reflected_ray;
}

