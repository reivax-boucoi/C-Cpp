#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <GL/glut.h>
using namespace std;
class Terrain{
    
    struct Terr_t{
        const char* name;
        const float level;
        const float col[3];
    };
    
public:
    Terrain();
    ~Terrain();
    void setColor(float heigth);
    
private:
    const int nbTerrain=5;
    const Terr_t t[5]={
        {"sea",0.3f,{0.03f, 0.32f, 0.56f}},
        {"sand",0.35f,{0.98f, 0.83f, 0.54f}},
        {"earth",0.55f,{0.38f, 0.49f, 0.06f}},
        {"hill",0.85f,{0.31f, 0.31f, 0.24f}},
        {"peak",1.0f,{1.00f, 0.98f, 0.96f}}
    };
    
};

#endif
