#include <iostream>
#include <map>
using namespace std;


map<string , float> cmdLookUp;
    

int main(void){
    cmdLookUp["test"]=5.15;
    cmdLookUp["tes"]=15;
    cout<<"hi"<<cmdLookUp["test"]<<endl;
    return 0;
}
