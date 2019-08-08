#include "NoiseMap.h"

NoiseMap::NoiseMap(int s){
    size=s+1;
    cout << "NoiseMap init"<<endl;
    offsets[0]=0.0f;
    offsets[1]=0.0f;
    offsets[2]=0.0f;
    values=new float[size*size];
    reComputeArray();
};

void NoiseMap::reComputeArray(void){
    for(int i=0;i<size;i++){        
        for(int j=0;j<size;j++){  
            values[j+i*size]=noise.noise((i+offsets[0])/(scl*size),(j+offsets[1])/(scl*size),offsets[2]);
            //cout<<values[j+i*size]<<endl;
        }
    }
}


float NoiseMap::getScale(void){
    return scl;
}
void NoiseMap::setScale(float scale){
    scl=scale;
    reComputeArray();
}

NoiseMap::~NoiseMap(){
    
};


void NoiseMap::toggleColorMode(void){
    if(colorMode==NoiseMode){
        colorMode=TerrainMode;
    }else{
        colorMode=NoiseMode;
    }
    
}

float NoiseMap::getNoise(int x, int y){
    return 0.0f;//values[x*size+y];
}

void NoiseMap::setColor(int x, int y){
    if(colorMode==NoiseMode){
        // cout << "c["<<x<<','<<y<<"]="<<values[x*size+y]<<endl;
        glColor3f(values[x*size+y],values[x*size+y],values[x*size+y]);
    }else if(colorMode==TerrainMode){
        terrain.setColor(values[x*size+y]);
        
    }else{
        cout << "Panic"<<endl;
    }
}
