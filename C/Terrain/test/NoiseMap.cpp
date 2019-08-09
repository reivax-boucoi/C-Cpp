#include "NoiseMap.h"

NoiseMap::NoiseMap(int s){
    size=s+1;
    
    origin=new float[octaves*2];
    offsets=new float[octaves*2];
    values=new float[size*size];
    
    for(int i=0;i<2*octaves;i++){
        origin[i]=0.0f;
        offsets[i]=origin[i];
    }
    
    reComputeArray();
    cout << "NoiseMap init"<<endl;
};

void NoiseMap::reComputeArray(void){
    for(int i=0;i<size;i++){        
        for(int j=0;j<size;j++){  
            values[j+i*size]=noise.noise((i+offsets[0])/(scl*size),(j+offsets[1])/(scl*size),0.0f);
            //cout<<values[j+i*size]<<endl;
        }
    }
}


void NoiseMap::resetOffsets(void){
    for(int i=0;i<2*octaves;i++){
        offsets[i]=origin[i];
    }
    reComputeArray();    
}

void NoiseMap::moveOffset(int axis, float speed){
    for(int i=0;i<octaves;i++){
        cout <<offsets[(i*2)+axis]<<"   "<<(i*2)+axis<<endl;
        offsets[(i*2)+axis]+=speed;
        cout <<offsets[(i*2)+axis]<<endl;
    }
    reComputeArray();
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

void NoiseMap::setDrawMode(int m){
    drawMode=m;
}

void NoiseMap::toggleColorMode(void){
    if(colorMode==NoiseMode){
        colorMode=TerrainMode;
    }else{
        colorMode=NoiseMode;
    }
    
}

float NoiseMap::getNoise(int x, int y){
    return drawMode? values[x*size+y] : 0.0f;
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
