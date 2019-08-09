#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

struct Color{
    float r;
    float g;
    float b;
};

class Terrain{
    
    struct Terr_t{
        string name;
        float level;
        string color;
        
    };
    
public:
    Terrain();
    ~Terrain();
    
    Color getColorFromHex(string col);
    void setColor(Color c);
    Color getColor(float heigth);
    
private:
    const int nbTerrain=8;
    Terr_t t[8];
    
};

#endif
