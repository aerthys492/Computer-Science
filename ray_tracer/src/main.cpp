
#include <iostream>


#include "rt.h"

extern void draw_robot();
extern void draw_triangles();

///
int main (int argc, char * const argv[]) {

    // draw_triangles();
    // return 0;
    
    std::cout << "ray tracing ... \n";

    CScene scene;
    scene.create(); // defines sample scene parameters
    if(scene.cam.width == 0) {
        std::cout << "WARNING: scene not defined" << std::endl;
        return -1;
    }

    CRayTrace rt;
    CRay ray;
    COutput results;

    /// computes primary ray matrix
    glm::mat3 ray_matrix;
    CRayTrace::compPrimaryRayMatrix(scene.cam, ray_matrix);
    std::cout << "Camera projection matrix:" << std::endl;
    PRINT_MAT3(ray_matrix);

    /// computes ray direction for sample pixel positions
    ray.pos = scene.cam.eyep;
    float fx = scene.cam.width/2 - 1 + 0.5;
    float fy = scene.cam.height/2 - 1 + 0.5;

    ray.dir = glm::normalize((ray_matrix * glm::vec3 {fx,fy,1}));

    PRINT_VEC3("", glm::round(ray.dir));

    /////////test przecięcia promienia z kulą////////
    //ray.dir = {0.3,0.3,-1};
    //ray.pos ={0,0,10};
    //std::cout<< scene.objectList[2]->intersect(ray);
    /////////test////////

    /// creates raster image object
    CImage image(scene.cam.width, scene.cam.height);
    CImage image2(scene.cam.width, scene.cam.height);
    CImage image3(scene.cam.width, scene.cam.height);

    /// main loop
    for (int j = 0; j < scene.cam.height; j++) {
        for (int i = 0; i < scene.cam.width; i++){
            /// position of the image point
            float fx = (float)i +0.5f;
            float fy = (float)j +0.5f;
            ray.pos = scene.cam.eyep;

            /// primary ray
            ray.dir = glm::normalize(ray_matrix * glm::vec3 {fx,fy,1});

            //glm::vec3 rgb(0.0f, 0.0f, 0.0f);
            //rgb.x = (ray.dir.x + 1.0f)/2.0f;
            //rgb.y = (ray.dir.y + 1.0f)/2.0f;
            //rgb.z = (ray.dir.z + 1.0f)/2.0f;
            //image.setPixel(i, j, rgb);

            /// background color
            results.col = {0,0,0};
            /// secondary ray counter
            results.tree = 0;
            /// ray energy
            results.energy = 1.0f;

            /// rendering
            rt.rayTrace(scene, ray, results);

            /// handles pixel over-saturation
            if(results.col.x > 1 || results.col.y > 1 || results.col.z > 1) {
                results.col = {1,1,1};
            }

            /// writes pixel to output image
            image.setPixel(i, j, results.col);

            //glm::vec3 rgb(0.0f, 0.0f, 0.0f);
            //rgb.x = (ray.dir.x + 1.0f)/2.0f;
            //rgb.y = (ray.dir.y + 1.0f)/2.0f;
            //rgb.z = (ray.dir.z + 1.0f)/2.0f;
            //image.setPixel(i, j, rgb);
            glm::vec3 rgbX(0.0f, 0.0f, 0.0f);
            rgbX.x = (ray.dir.x + 1.0f) / 2.0f;
            glm::vec3 rgbY(0.0f, 0.0f, 0.0f);
            rgbY.y = (ray.dir.y + 1.0f) / 2.0f;
            glm::vec3 rgbZ(0.0f, 0.0f, 0.0f);
            rgbZ.z = (ray.dir.z + 1.0f) / 2.0f;
        }
    }
    /*for (int j = 0; j < scene.cam.height; j++) {
        for (int i = 0; i < scene.cam.width; i++) {
            /// position of the image point
            float fx = (float)i +0.5f;
            float fy = (float)j +0.5f;
            ray.pos = scene.cam.eyep;

            /// primary ray
            ray.dir = glm::normalize(ray_matrix * glm::vec3 {fx,fy,1});

            //glm::vec3 rgb(0.0f, 0.0f, 0.0f);
            //rgb.x = (ray.dir.x + 1.0f)/2.0f;
            //rgb.y = (ray.dir.y + 1.0f)/2.0f;
            //rgb.z = (ray.dir.z + 1.0f)/2.0f;
            image.setPixel(i, j, rgb);
            /// background color
            results.col = {0,0,0};
            /// secondary ray counter
            results.tree = 0;
            /// ray energy
            results.energy = 1.0f;

            /// rendering
            rt.rayTrace(scene, ray, results);

            /// handles pixel over-saturation
            if(results.col.x > 1 || results.col.y > 1 || results.col.z > 1) {
                results.col = {1,1,1};
            }

            /// writes pixel to output image
            image.setPixel(i, j, results.col);
        }
    }*/

    /// writes image to disk file with gamma correction
    //image.save("image.png", true);
    //image2.save("image2.png", true);
    //image3.save("image3.png", true);

     //cv::imshow("image", image.getImage());
     //cv::waitKey();
    //cv::imshow("image", image.getImage());
    //cv::imshow("image2", image2.getImage());
    //cv::imshow("image3", image3.getImage());
    //cv::waitKey();

    /// writes image to disk file with gamma correction
    image.save("output.png", false);
    std::cout << std::endl << std::endl;
    return 0;
}


/// Draws two trianges
void draw_triangles() {

    CImage img(1000, 1000);
    
    glm::vec3 color1(0.9,0.1,0.1); // red
    glm::vec3 color2(0.1,0.9,0.1); // green
    
    // draw circle
    glm::vec3 pp(0.0,0.0,1.0);
    float radius = 0.1f;
//    img.drawCircle(pp, radius, color1);
    
    // triangle vertices
    glm::vec3 pp0(0.4, 0.3, 1);
    glm::vec3 pp1(-0.4, 0.3, 1);
    glm::vec3 pp2(0.4, -0.3, 1);
    
    // draws triangle in 2D
    img.drawLine(pp0, pp1, color1);
    img.drawLine(pp1, pp2, color1);
    img.drawLine(pp2, pp0, color1);
    
    // translation
    float tX = 0.2f; // OX translation
    float tY = 0.1f; // OY translation
    glm::mat3x3 mTrans {{1,0,0}, {0,1,0}, {tX,tY,1}}; // translation matrix
    PRINT_MAT3(mTrans);

    // translation of vertices
    pp0 = mTrans * pp0;
    pp1 = mTrans * pp1;
    pp2 = mTrans * pp2;

    // draws triangle after translation
    img.drawLine(pp0, pp1, color2);
    img.drawLine(pp1, pp2, color2);
    img.drawLine(pp2, pp0, color2);

    img.save("robot.png");
    cv::imshow("ROBOT", img.getImage());
    cv::waitKey();

}

/// Draws robot.
void draw_robot() {

}
