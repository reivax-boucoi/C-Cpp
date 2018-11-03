#include <iostream>
#include <map>
using namespace std;

void fun1(int i){
 cout<<"fun 1 arg "<<i<<endl;   
}
void fun2(int i, int j){
 cout<<"fun 2 args "<<i<<" and "<<j<<endl;   
}
typedef void (*fn_ptr)(int);

map<string , fn_ptr> cmdLookUp;
    

int main(void){
    cmdLookUp["test"]=fun1;
    cmdLookUp["test2"]=fun2;
    cmdLookUp["test"](3);
    cout<<"hi"<<endl;
    return 0;
}
