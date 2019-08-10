#include "Mesh.h"

Mesh::Mesh()
{
    nm=new NoiseMap(size);
    cout << "Mesh init !"<<endl;
}

Mesh::Mesh(int s)
{
    size=s;
    nm=new NoiseMap(s);
    cout << "Mesh init !"<<endl;

}

Mesh::Mesh(int s, int oct, float per, float lac)
{
    size=s;
    nm=new NoiseMap(s,oct,per,lac);
    cout << "Mesh init !"<<endl;

}

Mesh::Mesh(int s, int oct, float per, float lac, int seed)
{
    size=s;
    nm=new NoiseMap(s,oct,per,lac,seed);
    cout << "Mesh init !"<<endl;
}
