#ifndef NOISEMAP_H
#define NOISEMAP_H

#include <iostream>
#include <GL/glut.h>
#include "PerlinNoise.h"
using namespace std;

class NoiseMap{
    enum ColorMode { Noise, Terrain};
public:
    NoiseMap(int s);
    ~NoiseMap();
    float getNoise(int x, int y);
    void setColor(int x, int y);
private:
    int size=0;
    float scl=10;
    ColorMode mode=Noise;
    float persistance=0.5f;
    float lacunarity=2.0f;
    PerlinNoise noise;
    float *values;
};

#endif
