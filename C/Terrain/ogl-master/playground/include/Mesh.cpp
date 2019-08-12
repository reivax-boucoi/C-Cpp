#include "Mesh.h"

Mesh::Mesh()
{
    nm=new NoiseMap(size);
    cout << "Mesh init !"<<endl;
}

Mesh::Mesh(unsigned int s)
{
    size=s;
    nm=new NoiseMap(s);
    cout << "Mesh init !"<<endl;

}

Mesh::Mesh(unsigned int s, unsigned int oct, float per, float lac)
{
    size=s;
    nm=new NoiseMap(s,oct,per,lac);
    cout << "Mesh init !"<<endl;

}

Mesh::Mesh(unsigned int s, unsigned int oct, float per, float lac, unsigned int seed)
{
    size=s;
    nm=new NoiseMap(s,oct,per,lac,seed);
    cout << "Mesh init !"<<endl;
}

GLfloat* Mesh::generateVertexData()
{
    GLfloat *vbo=new GLfloat [getVertexCount()];
    unsigned int index=0;
    float spacing =1.8f/size;
    float xoff=-0.9f;
    for(unsigned int i=0;i<size;i++){
        float yoff=-0.9f;
        for(unsigned int j=0;j<size;j++){
            cout <<"["<< xoff <<','<< yoff <<"]"<<endl;
            //(0,0)
            vbo[index]=xoff;//x
            vbo[index+1]=yoff;//y
            vbo[index+2]=0.0f;//z

            //(0,1)
            vbo[index+3]=xoff;//x
            vbo[index+4]=yoff+spacing;//y
            vbo[index+5]=0.0f;//z

            //(1,1)
            vbo[index+6]=xoff+spacing;//x
            vbo[index+7]=yoff+spacing;//y
            vbo[index+8]=0.0f;//z

            //(0,0)
            vbo[index+9]=xoff;//x
            vbo[index+10]=yoff;//y
            vbo[index+11]=0.0f;//z

            //(1,1)
            vbo[index+12]=xoff+spacing;//x
            vbo[index+13]=yoff+spacing;//y
            vbo[index+14]=0.0f;//z

            //(1,0)
            vbo[index+15]=xoff+spacing;//x
            vbo[index+16]=yoff;//y
            vbo[index+17]=0.0f;//z
            yoff+=spacing;

            index+=18;
        }
        xoff+=spacing;
    }
    return vbo;
}

unsigned int Mesh::getVertexCount()
{
    return (size+1)*(size+1)*2*3*3;
}
