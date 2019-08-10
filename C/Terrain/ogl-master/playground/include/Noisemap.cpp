#include "Noisemap.h"



NoiseMap::NoiseMap(int s)
{
    size=s;
noise=new PerlinNoise();
}

NoiseMap::NoiseMap(int s, int oct, float per, float lac)
{
    size=s;
    octaves=oct;
    persistance=per;
    lacunarity=lac;
    noise=new PerlinNoise();

}

NoiseMap::NoiseMap(int s, int oct, float per, float lac, int seed)
{
    size=s;
    octaves=oct;
    persistance=per;
    lacunarity=lac;
    noise=new PerlinNoise(seed);

}
