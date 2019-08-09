#include "Mesh.h"

Mesh::Mesh(int s){
    size=s;
};

Mesh::~Mesh(){};

void Mesh::build(void){
    nm=new NoiseMap(size,0.5f,2.0f,8);
    cout << "Mesh init"<<endl;  
};

void Mesh::draw(int m){
    
    float xoff=-0.95f;
    float spacing=1.9f/size;
    
    nm->setDrawMode(m);
    
    glBegin(GL_TRIANGLES);
    for(int i=0;i<size;i++){//draw every vertex centered on (0,0) with appropriate color and heigth (if m==1)
        
        float yoff=-0.95f;
        
        for(int j=0;j<size;j++){
            nm->setColor(i,j);
            glVertex3f(xoff,yoff,nm->getNoise(i,j));
            
            nm->setColor(i,j);
            glVertex3f(xoff+spacing,yoff+spacing,nm->getNoise(i+1,j+1));
            
            nm->setColor(i,j);
            glVertex3f( xoff, yoff+spacing, nm->getNoise(i,j+1));
            
            
            nm->setColor(i,j);
            glVertex3f(xoff,yoff, nm->getNoise(i,j));
            
            nm->setColor(i,j);
            glVertex3f( xoff+spacing,yoff+spacing, nm->getNoise(i+1,j+1));
            
            nm->setColor(i,j);
            glVertex3f(xoff+spacing, yoff, nm->getNoise(i+1,j));
            yoff+=spacing;
        }
        xoff+=spacing;
    }
    glEnd();
    
}
