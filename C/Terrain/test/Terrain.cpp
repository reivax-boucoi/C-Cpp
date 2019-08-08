#include "Terrain.h"

Terrain::Terrain(){
    cout<<"Terrain init"<<endl;
};
Terrain::~Terrain(){
    
};


void Terrain::setColor(float heigth){
    
    int i=nbTerrain-1;
    while(i>=0 && heigth<t[i].level)i--;
    i++;
    //cout << "Terrain for heigth="<< heigth <<" is "<< t[i].name << " @ "<< t[i].level << endl;
    
    glColor3f(t[i].col[0],t[i].col[1],t[i].col[2]);
}
