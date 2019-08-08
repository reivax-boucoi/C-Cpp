#include "NoiseMap.h"

NoiseMap::NoiseMap(int s){
    size=s;
    cout << "NoiseMap init"<<endl;
    values=new float[(size+1)*(size+1)];
    
    for(int i=0;i<=size;i++){        
        for(int j=0;j<=size;j++){  
            values[i+j*size]=noise.noise(i/scl,j/scl,0.0f);
            cout<<values[i+j*size]<<endl;
        }
    }
};

NoiseMap::~NoiseMap(){};

float NoiseMap::getNoise(int x, int y){
    return 0.0f;//values[x*size+y];
}

void NoiseMap::setColor(int x, int y){
    if(mode==Noise){
        glColor3f(values[x*size+y],values[x*size+y],values[x*size+y]);
    }else if(mode==Terrain){
        
        
    }else{
        cout << "Panic"<<endl;
    }
}
