#ifndef NOISEMAP_H
#define NOISEMAP_H
#include "PerlinNoise.h"

class NoiseMap
{
public:
    NoiseMap(int s);
    NoiseMap(int s,int oct, float per,float lac);
    NoiseMap(int s,int oct, float per,float lac,int seed);
private:
    int size=1;
    float scl=0.2f;
    float persistance=0.5f;
    float lacunarity=2.0f;
    int octaves=1;
    PerlinNoise *noise;
};

#endif // NOISEMAP_H
