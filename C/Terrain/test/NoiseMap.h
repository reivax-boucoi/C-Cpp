#ifndef NOISEMAP_H
#define NOISEMAP_H

#include <iostream>
#include <GL/glut.h>
#include "PerlinNoise.h"
#include "Terrain.h"

using namespace std;

class NoiseMap{
    enum ColorMode { NoiseMode, TerrainMode};
public:
    NoiseMap(int s);
    ~NoiseMap();
    float getNoise(int x, int y);
    void setColor(int x, int y);
    float getScale(void);
    void setScale(float scale);
    void toggleColorMode(void);
    void setDrawMode(int m);
    
    void resetOffsets(void);
    void moveOffset(int axis, float speed);
    
    
    void reComputeArray(void);
private:
    int size=0;
    float scl=0.2;
    ColorMode colorMode=NoiseMode;
    int drawMode=0;
    float persistance=0.5f;
    float lacunarity=2.0f;
    int octaves=1;
    PerlinNoise noise;
    float *values;
    float *offsets;
    float *origin;
    Terrain terrain;
    
};

#endif
