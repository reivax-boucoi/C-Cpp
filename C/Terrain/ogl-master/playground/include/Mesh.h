#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "Noisemap.h"

using namespace std;
class Mesh
{
public:
    Mesh();
    Mesh(unsigned int s);
    Mesh(unsigned int s, unsigned int oct, float per, float lac);
    Mesh(unsigned int s, unsigned int oct, float per, float lac, unsigned int seed);

    GLfloat* generateVertexData(void);
    unsigned int getVertexCount(void);

    NoiseMap *nm;
private:
        unsigned int size=1;
};

#endif // MESH_H
