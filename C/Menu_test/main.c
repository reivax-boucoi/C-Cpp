#include <stdio.h>

struct Led{
    const char* name;
    int on;
}leds[19]={  
    {"Ilest",0},//0
    {"1",1},
    {"2",0},
    {"3",0},
    {"4",0},
    {"5",0},
    {"6",0},
    {"7",0},
    {"8",0},
    {"9",0},
    {"10",0},//10
    {"11",0},
    {"HEURE",0},//12
    {"MIDI",0},
    {"MINUIT",0},//14
    {"MOINS",0},
    {"DIX",0},//16
    {"1/2",0},
    {"VINGT",0}//18
};

void setMode(int i){
}
void setColorMode(int i){
}
void setNightMode(int i){
}
void setNightOff(int i){
}
void setNightOn(int i){
}
void setHouram(int i){
}
void setHourpm(int i){
}
void setMinam(int i){
}
void setMinpm(int i){
}
void setEventMode(int i){
}
void reset(int i){
}
void setRainbow(int i){
}
struct Menu;
typedef const struct Menu{
    const char* name;
    const char* color;
    const int nb_optn;
    void (*fptr)(int);
    const struct{
        const int led;
        const struct Menu* submenu;
    }sub[];
};
struct Menu M0main;
struct Menu M1mode;
struct Menu M1cmode;
struct Menu M1nightmode;
struct Menu M2offhour;
struct Menu M3onhour;
struct Menu M1setTime;
struct Menu M2sethouram;
struct Menu M2sethourpm;
struct Menu M2setminam;
struct Menu M2setminpm;
struct Menu M1eventMode;
struct Menu M1reset;
struct Menu M1rainbow;

struct Menu M0main={"Main","WHITE",7,0,{
    {1,&M1mode},
    {2,&M1cmode},
    {3,&M1nightmode},
    {4,&M1setTime},
    {5,&M1eventMode},
    {6,&M1reset},
    {7,&M1rainbow}    
}};
struct Menu M1mode={"Mode","CYAN",5,setMode,{
    {1,0},//Hour only
    {2,0},//Hour + temp (slow)
    {3,0},//Hour + temp (fast)
    {4,0},//temp only
    {12,&M0main}//return    
}};
struct Menu M1cmode={"Color Mode","BLUE",8,setColorMode,{
    {1,0},//fixed
    {2,0},//random single (slow)
    {3,0},//random single (fast)
    {4,0},//random all (slow)
    {5,0},//random all (fast)
    {6,0},//cycle (slow)
    {7,0},//cycle (fast)
    {12,&M0main}//return    
}};
struct Menu M1nightmode={"Night Mode","MAGENTA",4,setNightMode,{
    {1,0},//none
    {2,&M2offhour},//Half brightness
    {3,&M2offhour},//Off completely
    {12,&M0main}//return
}};
struct Menu M2offhour={"Night off Hour","RED",12,setNightOff,{
    {1,&M3onhour},//heures
    {2,&M3onhour},
    {3,&M3onhour},
    {4,&M3onhour},
    {5,&M3onhour},
    {6,&M3onhour},
    {7,&M3onhour},
    {8,&M3onhour},
    {9,&M3onhour},
    {10,&M3onhour},
    {11,&M3onhour},
    {12,&M1nightmode}//return
}};
struct Menu M3onhour={"Night on Hour","BLUE",12,setNightOn,{
    {1,0},//heure
    {2,0},
    {3,0},
    {4,0},
    {5,0},
    {6,0},
    {7,0},
    {8,0},
    {9,0},
    {10,0},
    {11,0},
    {12,&M1nightmode}//return
}};
struct Menu M1setTime={"Set Time","YELLOW",5,0,{
    {1,&M2sethouram},//hour am
    {2,&M2sethourpm},//hour pm
    {3,&M2setminam},//min am
    {4,&M2setminpm},//min pm
    {12,&M0main}//return
}};
struct Menu M2sethouram={"Set hour AM","GREEN",13,setHouram,{
    {1,0},//heure
    {2,0},
    {3,0},
    {4,0},
    {5,0},
    {6,0},
    {7,0},
    {8,0},
    {9,0},
    {10,0},
    {11,0},
    {13,0},//midi
    {12,&M1setTime}//return
}};
struct Menu M2sethourpm={"Set hour PM","GREEN",13,setHourpm,{
    {1,0},//heure
    {2,0},
    {3,0},
    {4,0},
    {5,0},
    {6,0},
    {7,0},
    {8,0},
    {9,0},
    {10,0},
    {11,0},
    {14,0},//minuit
    {12,&M1setTime}//return
}};
struct Menu M2setminam={"Set min AM","RED",4,setMinam,{
    {16,0},//dix
    {18,0},//vingt
    {17,0},//1/2
    {12,&M1setTime}//return
}};
struct Menu M2setminpm={"Set min PM","RED",4,setMinpm,{
    {16,0},//dix
    {18,0},//vingt
    {17,0},//1/2
    {12,&M1setTime}//return
}};
struct Menu M1eventMode={"Event","MAGENTA",3,setEventMode,{
    {1,0},//Event on
    {2,0},//Event off
    {12,&M0main}//return
}};
struct Menu M1reset={"RESET","RED",3,reset,{
    {1,0},//yes
    {12,&M0main}//return
}};
struct Menu M1rainbow={"Rainbow!","WHITE",3,setRainbow,{
    {1,0},//Rainbow on
    {2,0},//Rainbow off
    {12,&M0main}//return
}};

int findNextEntry(struct Menu* m,int i){
    if((i+2)>m->nb_optn)return 0;
    return i+1;
}

struct Menu* getSubMenu(struct Menu* m,int index){
    if(m->sub[index].submenu==0)return 0;//if executed NULL, return blank menu (==exit setup)
    return m->sub[index].submenu;
}
int main(void){
    char c=' ';
    int index=0;
    struct Menu* Mcurrent=0;
    while(c!='q'){
        if(c!='\n'){
            if(c=='e'){
                if(Mcurrent){
                    if(Mcurrent->fptr!=0 && Mcurrent->sub[index].submenu==0)Mcurrent->fptr(index);//check if function is associated and selected value is not a navigation move
                    Mcurrent=getSubMenu(Mcurrent,index);//get new menu
                    index=0;
                }else{
                    Mcurrent=&M0main;
                }
            }else if(c=='+' && Mcurrent){
                leds[Mcurrent->sub[index].led].on=0;
                index=findNextEntry(Mcurrent,index);//get following option
                leds[Mcurrent->sub[index].led].on=1;
            }
            for(int i=0;i<19;i++){
                if(leds[i].on)printf("Led :%s ",leds[i].name);
            }
            if(Mcurrent)printf("\r\nCurrent Menu :%s, pointing to %s\r\n",Mcurrent->name,Mcurrent->sub[index].submenu?Mcurrent->sub[index].submenu->name:"NULL");
        }
        scanf("%c",&c);
    }
    
    return 0;
}
