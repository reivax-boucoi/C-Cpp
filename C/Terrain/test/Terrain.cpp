#include "Terrain.h"

Terrain::Terrain(){
    
    t[0]={"sea",0.3f,"276CAD"};
    t[1]={"water",0.4f,"3E7AB0"};
    t[2]={"sand",0.45f,"DCA86E"};
    t[3]={"grass",0.55f,"596415"};
    t[4]={"grass2",0.6f,"7C5C2A"};
    t[5]={"hill",0.7f,"9B8E7F"};
    t[6]={"hill1",0.9f,"31343F"};
    t[7]={"snow",1.0f,"FFFCF7"};
    cout<<"Terrain init "<<endl;
};

Terrain::~Terrain(){
};

Color Terrain::getColorFromHex(string col){
    Color c;
    c.r= stoi(col.substr(0,2),nullptr,16)/256.0f;
    c.g= stoi(col.substr(2,2),nullptr,16)/256.0f;
    c.b= stoi(col.substr(4,2),nullptr,16)/256.0f;
    return c;
}

void Terrain::setColor(Color c){
    glColor3f(c.r,c.g,c.b);
}

Color Terrain::getColor(float heigth){
    if(heigth>=1.0f){
        return getColorFromHex(t[nbTerrain-1].color);
    }
    int i=nbTerrain-1;
    while(i>=0 && heigth<t[i].level){
        i--;
    }
    i++;
    //cout << "Terrain for heigth="<< heigth <<" is "<< t[i].name << t[i].level << endl;
    return getColorFromHex(t[i].color);
}
