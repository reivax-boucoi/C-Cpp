#ifndef NOISEMAP_H
#define NOISEMAP_H
#include "PerlinNoise.h"

#include <glm/glm.hpp>
class NoiseMap
{
public:
    NoiseMap(unsigned int s);
    NoiseMap(unsigned int s,unsigned int oct, float per,float lac);
    NoiseMap(unsigned int s,unsigned int oct, float per,float lac,unsigned int seed);
    float getNoiseAt(unsigned int x,unsigned int y);
    glm::vec3 getColorAt(unsigned int x,unsigned int y);
    void generateNoise();

private:

    void init();
    glm::vec2 localMinMax;
    glm::vec2 globalMinMax;

    float *noiseValues;
    glm::vec3 *colorValues;
    glm::vec2 *offsets;

    unsigned int size=1;
    float scl=0.2f;
    float persistance=0.5f;
    float lacunarity=2.0f;
    unsigned int octaves=1;

    PerlinNoise *noise;
};

#endif // NOISEMAP_H
