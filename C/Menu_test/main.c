#include <stdio.h>
#include "menu.h"

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
void setHour(int i){
    printf("Executed setHour with parameter %d\r\n",i);
}

void setMode(int i){
    printf("Executed setMode with parameter %d\r\n",i);
}
struct Menu;
typedef const struct Menu{
    const char* name;
    const char* color;
    const int nb_optn;
    void (*fptr)(int);
    struct{
        const int led;
        const struct Menu* submenu;
    }sub[];
};
struct Menu Mmain;
struct Menu M1={"First Menu","RED",3,setHour,{{1,0},{2,0},{12,&Mmain}}};
struct Menu M2={"Second Menu","BLUE",3,setMode,{{1,0},{2,0},{12,&Mmain}}};
struct Menu Mmain={"Main","WHITE",3,0,{{1,&M1},{2,&M2},{4,0}}};

int findNextEntry(struct Menu* m,int i){
    if((i+2)>m->nb_optn)return 0;
    return i+1;
}

struct Menu* getSubMenu(struct Menu* m,int index){
 if(m->sub[index].submenu==0)return &Mmain;//if executed NULL, return to main menu
 return m->sub[index].submenu;
}
int main(void){
    char c=' ';
    int index=0;
    struct Menu* Mcurrent=&Mmain;
    printf("%lu\r\n",sizeof(int));
    printf("%lu\r\n",sizeof(Mcurrent));
    while(c!='q'){
        if(c!='\n'){
            if(c=='e'){
                if(Mcurrent->fptr!=0)Mcurrent->fptr(index);
                Mcurrent=getSubMenu(Mcurrent,index);
                index=0;
            }else if(c=='+'){
                leds[Mcurrent->sub[index].led].on=0;
                index=findNextEntry(Mcurrent,index);
                leds[Mcurrent->sub[index].led].on=1;
            }
            for(int i=0;i<19;i++){
                if(leds[i].on)printf("Led :%s ",leds[i].name);
            }
            printf("\r\nCurrent Menu :%s, pointing to %s\r\n",Mcurrent->name,Mcurrent->sub[index].submenu?Mcurrent->sub[index].submenu->name:"NULL");
        }
        scanf("%c",&c);
    }
    
    return 0;
}
