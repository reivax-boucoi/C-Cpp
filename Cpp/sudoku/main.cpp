#include <iostream>
#include <fstream>

using namespace std;

struct boxType{
    int nums[9]={1,2,3,4,5,6,7,8,9};
    int num =9;
};
boxType grid[81];
void removeNum(int index, int numIndex){
    while(numIndex<8 && grid[index].nums[numIndex]!=0){//stop si fin ou deja 0s
        grid[index].nums[numIndex]=grid[index].nums[numIndex+1]; //shift gauche
        numIndex++;
    }
    grid[index].num--; // enleve 1 valeur
}
void setBox(int index,int val){
    grid[index].nums[0]=val;
    grid[index].num=1;
   // cout<< index << "  :  "<<grid[index].nums[0]<< "   "<<val<<endl;
}
void printBox(int i){
    cout << "Box : "<< i << " length : " << grid[i].num<< " : [ ";
    for(int x=0;x<grid[i].num;x++){
        cout << grid[i].nums[x] << ' ';
    }
    cout << ']' << endl;
}
void printGrid(){
cout << "Begin Grid"<<endl;
cout << "-------------"<< endl;
    for(int i=0;i<9;i++){
        cout << '|';
        for(int j=0;j<9;j++){
            char c;
            if(grid[i*9+j].num>1){
                c='.';
            }else{
                c=grid[i*9+j].nums[0]+48;
            }
            cout << c ;
            if(j%3==2){
            cout << '|';
            }
        }
        cout << endl;
        if(i%3==2){
        cout << "-------------"<<endl;;
        }
    }
cout << "End Grid"<<endl;
}
bool checkRow(int i){
bool found=false;
    for(int j=0;j<9;j++){//pour chaque box ds ligne
        if(grid[(i/9)*9+j].num==1){ // si element fini
            for(int x=0;x<grid[i].num;x++){ // chercher similaire ds box consideree ( while + efficient ici !)
                if(grid[(i/9)*9+j].nums[x]==grid[i].nums[0]){ // si trouve similaire
                    printBox(i);
                    removeNum(i,x); // enlever posibilites
                    printBox(i);
                    found=true;
                }
            }
        }
    }
    return found;
}
bool simplify(int i){
bool simplified=false;
//simplified|=checkSquare(i);
simplified |= checkRow(i);
//simplified|=checkCol(i);
return simplified;
}
int main(){

    ifstream infile;
    infile.open ("puzzles/test.txt", ifstream::in);
    for( int i=0;i<81;i++){
        if(infile.good()){
            char c = (char)infile.get();
            if( c != '.'){
                setBox(i,c-48);
                //printBox(i);
            }
        }else{
            cout << "issue loading file" << endl;
        }
    }
    infile.close();
    printGrid();
    printBox(0);
    printBox(1);
    printBox(2);
    printBox(8);
    for(int i=0;i<81;i++){
        if(grid[i].num>1){
            if(simplify(i)){
                i=0;
                }
        }
    }
    printGrid();
    printBox(0);
    printBox(1);
    printBox(2);
    printBox(8);
    return 0;
}
