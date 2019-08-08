#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain{
    struct Terr_t{
        char* name;
        float level;
        float col[3];
    };
public:
    Terrain();
    ~Terrain();
private:
    Terr_t t;//={"water",0.3f,{0.0f,0.0f,1.0f}};
    
};

#endif
