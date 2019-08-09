#include "NoiseMap.h"

NoiseMap::NoiseMap(int s, float per, float lac, int nbOct){
    size=s+1;
    persistance=per;
    lacunarity=lac;
    octaves=nbOct;
    
    origin=new float[octaves*2];
    offsets=new float[octaves*2];
    
    noiseValues=new float[size*size];
    colorValues=new Color[size*size];
    
    
    globalminMax[0]=0.0f;
    
    float amplitude=1.0f;
    for(int i=0;i<octaves;i++){
        globalminMax[0]+=amplitude;
        globalminMax[1]-=amplitude;
        amplitude*=persistance;
        origin[i]=0.0f;
        origin[i+octaves]=0.0f;
        offsets[i]=origin[i];
        offsets[i+octaves]=origin[i+octaves];
    }
    globalminMax[0]*=0.8f;
    globalminMax[1]=-globalminMax[0];
    
    reComputeArray();
    cout << "NoiseMap init"<<endl;
};

NoiseMap::~NoiseMap(){
    
};

float inverseLerp(float min, float max, float value){
    return (value-min)/(max-min);
}

float lerp(float min, float max, float time){
    return min+time*(max-min);
}

void NoiseMap::reComputeArray(void){
    
    for(int i=0;i<size;i++){        
        for(int j=0;j<size;j++){  
            noiseValues[j+i*size]=0.0f;
        }
    }
    
    localminMax[0]=numeric_limits<float>::max();
    localminMax[1]=-numeric_limits<float>::max();
    float amplitude=1.0f;
    float frequency=1.0f;
    for(int oct=0;oct<octaves;oct++){
        for(int i=0;i<size;i++){        
            for(int j=0;j<size;j++){  
                noiseValues[j+i*size]+=amplitude*noise.noise(frequency*(i+offsets[0])/(scl*size),frequency*(j+offsets[1])/(scl*size),0.0f);
                if(noiseValues[j+i*size]>=localminMax[1])localminMax[1]=noiseValues[j+i*size];
                if(noiseValues[j+i*size]<=localminMax[0])localminMax[0]=noiseValues[j+i*size];
                //cout<<noiseValues[j+i*size]<<endl;
            }
        }
        amplitude*=persistance;
        frequency*=lacunarity;
    }
        for(int i=0;i<size;i++){        
            for(int j=0;j<size;j++){  
                noiseValues[j+i*size]=inverseLerp(localminMax[0],localminMax[1],noiseValues[j+i*size]);
                noiseValues[j+i*size]=heightCurve(noiseValues[j+i*size]);
                colorValues[j+i*size]=terrain.getColor(noiseValues[j+i*size]);
            }
        }
       // cout << "Global minMax ["<< globalminMax[0]<<','<<globalminMax[1] <<"],\t local minMax ["<<localminMax[0]<<','<<localminMax[1]<<']'<<endl;
}


float NoiseMap::heightCurve(float x){
        return (heightCurveModifier +1.0f)*pow(x,heightCurveModifier) - heightCurveModifier*pow(x,heightCurveModifier+1.0f);
}

void NoiseMap::resetOffsets(void){
    for(int i=0;i<2*octaves;i++){
        offsets[i]=origin[i];
    }
    reComputeArray();    
}

void NoiseMap::moveOffset(int axis, float speed){
    for(int i=0;i<octaves;i++){
        offsets[(i*2)+axis]+=speed;
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
    if(drawMode){
        if(noiseValues[x*size+y]<0.4)return 0.0f;
        return scl*(noiseValues[x*size+y]-0.4f);
    }else{
        return 0.0f;
    }
}

void NoiseMap::setColor(int x, int y){
    if(colorMode==NoiseMode){
        // cout << "c["<<x<<','<<y<<"]="<<noiseValues[x*size+y]<<endl;
        glColor3f(noiseValues[x*size+y],noiseValues[x*size+y],noiseValues[x*size+y]);
    }else if(colorMode==TerrainMode){
        terrain.setColor(colorValues[x*size+y]);
        
    }else{
        cout << "Panic"<<endl;
    }
}
