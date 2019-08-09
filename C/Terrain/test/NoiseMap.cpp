#include "NoiseMap.h"

NoiseMap::NoiseMap(int s, float per, float lac, int nbOct){
    size=s+1;
    persistance=per;
    lacunarity=lac;
    octaves=nbOct;
    
    origin=new float[octaves*2];
    offsets=new float[octaves*2];
    
    values=new float[size*size];
    
    for(int i=0;i<size;i++){        
        for(int j=0;j<size;j++){  
            values[j+i*size]=0.0f;
        }
    }
    
    for(int i=0;i<2*octaves;i++){
        origin[i]=0.0f;
        offsets[i]=origin[i];
    }
    
    reComputeArray();
    cout << "NoiseMap init"<<endl;
};

float inverseLerp(float min, float max, float value){
    return (value-min)/(max-min);
}

float lerp(float min, float max, float time){
    return min+time*(max-min);
}

void NoiseMap::reComputeArray(void){
    minMax[0]=numeric_limits<float>::max();
    minMax[1]=-numeric_limits<float>::max();
    float amplitude=1.0f;
    float frequency=1.0f;
    for(int oct=0;oct<octaves;oct++){
        for(int i=0;i<size;i++){        
            for(int j=0;j<size;j++){  
                values[j+i*size]+=amplitude*noise.noise(frequency*(i+offsets[0])/(scl*size),frequency*(j+offsets[1])/(scl*size),0.0f);
                if(values[j+i*size]>=minMax[1])minMax[1]=values[j+i*size];
                if(values[j+i*size]<=minMax[0])minMax[0]=values[j+i*size];
                //cout<<values[j+i*size]<<endl;
            }
        }
        amplitude*=persistance;
        frequency*=lacunarity;
    }
        for(int i=0;i<size;i++){        
            for(int j=0;j<size;j++){  
                values[j+i*size]=inverseLerp(minMax[0],minMax[1],values[j+i*size]);
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
    return drawMode? 0.5f*values[x*size+y] : 0.0f;
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
