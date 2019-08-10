#ifndef MESH_H
#define MESH_H

#include <iostream>
#include "Noisemap.h"
using namespace std;
class Mesh
{
public:
    Mesh();
    Mesh(int s);
    Mesh(int s, int oct, float per, float lac);
    Mesh(int s, int oct, float per, float lac, int seed);
    NoiseMap *nm;
private:
        int size=1;
};

#endif // MESH_H
