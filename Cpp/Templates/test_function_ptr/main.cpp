#include <iostream>
#include <map>
using namespace std;

void fun1(int i){
 cout<<"fun 1 arg "<<i<<endl;   
}
void fun2(int i, int j){
 cout<<"fun 2 args "<<i<<" and "<<j<<endl;   
}

map<string , float> cmdLookUp;
    

int main(void){
    cmdLookUp["test"]=5.15;
    cmdLookUp["tes"]=15;
    cout<<"hi"<<cmdLookUp["test"]<<endl;
    return 0;
}
