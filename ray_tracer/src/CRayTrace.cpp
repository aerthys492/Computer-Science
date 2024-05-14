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
    glm::mat3 PRM=m;
    glm::vec3 eyep = cam.eyep;
    glm::vec3 lookp = cam.lookp;
    glm::vec3 up = cam.up;
    float fov = cam.fov;
    int width = cam.width;
    int height = cam.height;

    glm::vec3 look = lookp - eyep;
    glm::vec3 u = glm::cross(up, look) / glm::length(glm::cross(up, look));
    glm::vec3 v = glm::cross(u, look) / glm::length(glm::cross(u, look));
    float radian = (fov/2) * 3.14f / 180.0f;
    glm::vec3 o = (look / glm::length(look)) * (float)(width / 2) * tan(radian) - (width / 2.0f * u + height / 2.0f * v);

    glm::vec3 normal1 = glm::normalize(glm::cross(u, v));
    glm::vec3 normal2 = glm::normalize(glm::cross(v, o));
    glm::vec3 normal3 = glm::normalize(glm::cross(o, u));
    PRM[0] = normal1;
    PRM[1] = normal2;
    PRM[2] = normal3;

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

