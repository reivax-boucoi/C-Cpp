#include <stdio.h>
#include <cstddef>
#include <stdlib.h>
#include <time.h>

#define GRIDSIZE 10
#define DIFFICULTY 0.1f
#define UNKNOWN '.'
#define BLANK ' '
#define MARKER 'I'
#define MINE 'X'


int solugrid[GRIDSIZE][GRIDSIZE];
int currentgrid[GRIDSIZE][GRIDSIZE];

void initGrids(void){
    for(int i=0;i<GRIDSIZE;i++){
        for(int j=0;j<GRIDSIZE;j++){
            if(((float)rand() / RAND_MAX)<DIFFICULTY){
                solugrid[i][j]=MINE;
            }else{
                solugrid[i][j]=BLANK;
            }
            currentgrid[i][j]=UNKNOWN;
        }
    }
    for(int i=0;i<GRIDSIZE;i++){
        for(int j=0;j<GRIDSIZE;j++){
            if(solugrid[i][j]==BLANK){
                //count neighbours
                solugrid[i][j]='0';
            int minx=(i==0)?i:i-1;
            int miny=(j==0)?j:j-1;
            int maxx=(i==(GRIDSIZE-1))?i:i+1;
            int maxy=(j==(GRIDSIZE-1))?j:j+1;
            for(int x=minx;x<=maxx;x++){
                for(int y=miny;y<=maxy;y++){
                    if(solugrid[x][y]==MINE)solugrid[i][j]++;
                }
            }
            if(solugrid[i][j]=='0')solugrid[i][j]=' ';
            }
        }
    }
}
template<std::size_t N>
void drawGrid(int (&grid)[N][N]){
    printf("\r\n");
    for(int i=0;i<GRIDSIZE;i++){
        printf("|");
        for(int j=0;j<GRIDSIZE;j++){
            printf("%c",grid[i][j]);
        }
        printf("|\r\n");
    }
}
template<std::size_t N>
void drawGrid(int (&grid)[N][N], int (&grid1)[N][N]){
    printf("\r\n");
    printf("  0123456789 \t  0123456789 \r\n");
    for(int i=0;i<GRIDSIZE;i++){
        printf("%i|",i);
        for(int j=0;j<GRIDSIZE;j++){
            printf("%c",grid[i][j]);
        }
        printf("|%i\t%i|",i,i);
        for(int j=0;j<GRIDSIZE;j++){
            printf("%c",grid1[i][j]);
        }
        printf("|%i\r\n",i);
    }
    
}

bool solved(void){
    for(int i=0;i<GRIDSIZE;i++){
        for(int j=0;j<GRIDSIZE;j++){
            if(currentgrid[i][j]==UNKNOWN && currentgrid[i][j]!=MINE){
                return 0;
            }
        }
    }
    return 1;
}

void revealAdjacent(int i, int j){
    int minx=(i==0)?i:i-1;
    int miny=(j==0)?j:j-1;
    int maxx=(i==(GRIDSIZE-1))?i:i+1;
    int maxy=(j==(GRIDSIZE-1))?j:j+1;
    for(int x=minx;x<=maxx;x++){
        for(int y=miny;y<=maxy;y++){
            if(!(x==i && y==j) && !(x==maxx && y==maxy)){
                if(solugrid[x][y]==BLANK && currentgrid[x][y]==UNKNOWN){
                    currentgrid[x][y]=BLANK;
                    revealAdjacent(x,y);
                }
            }
        }
    }
    
}

bool uncover(int x, int y){
    currentgrid[x][y]=solugrid[x][y];
    if(currentgrid[x][y]==BLANK){
        revealAdjacent(x,y);
    }
    currentgrid[x][y]=solugrid[x][y];
    return currentgrid[x][y]==MINE;
}
int main(void){
    srand (time(NULL));
    printf("Hello world\r\n");
    initGrids();
    drawGrid(currentgrid, solugrid);
    int x,y;
    while(!solved()){
        x=-1;y=-1;
        scanf("%i,%i",&x,&y);
        if(x>=0 && x<GRIDSIZE && y>=0 && y<GRIDSIZE){
            printf("Uncovering at %i,%i\r\n",x,y);
            if(uncover(x,y)){
                drawGrid(currentgrid, solugrid);
                printf("Hit mine !\r\n");
                return -1;
            }
        }else{
            printf("Invalid input !\tPlease follow this format : X,Y\r\n");
        }
        drawGrid(currentgrid, solugrid);
    }
    printf("Solved !");
    return 0;
}
