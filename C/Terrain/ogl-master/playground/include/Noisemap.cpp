#include "Noisemap.h"



NoiseMap::NoiseMap(unsigned int s)
{
    size=s+1;
    noise=new PerlinNoise();
}

NoiseMap::NoiseMap(unsigned int s, unsigned int oct, float per, float lac)
{
    size=s+1;
    octaves=oct;
    persistance=per;
    lacunarity=lac;
    noise=new PerlinNoise();

}

NoiseMap::NoiseMap(unsigned int s, unsigned int oct, float per, float lac, unsigned int seed)
{
    size=s+1;
    octaves=oct;
    persistance=per;
    lacunarity=lac;
    noise=new PerlinNoise(seed);

}
void NoiseMap::init()
{
    offsets=new glm::vec2[octaves];

    for(unsigned int i=0;i<octaves;i++){
        offsets[i]={0.0f,0.0f};
    }

    noiseValues=new float[size*size];

    for(unsigned int i=0;i<size;i++){
        for(unsigned int j=0;j<size;j++){
            noiseValues[i+j*size]=0.0f;
        }
    }
}
float NoiseMap::getNoiseAt(unsigned int x,unsigned int y)
{
    return noiseValues[x+y*size];
}

glm::vec3 NoiseMap::getColorAt(unsigned int x, unsigned int y)
{
    return colorValues[x+y*size];
}

void NoiseMap::generateNoise()
{
    float amplitude=1.0f;
    float frequency=1.0f;
    for(unsigned int oct=0;oct<octaves;oct++){
        for(unsigned int i=0;i<size;i++){
            for(unsigned int j=0;j<size;j++){
                noiseValues[i+j*size]+=amplitude*noise->noise(frequency*(i+offsets[oct].x)/(scl*size),frequency*(j+offsets[oct].y)/(scl*size),0.0f);
            }
        }
    }

}


