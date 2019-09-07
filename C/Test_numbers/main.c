#include <iostream>

using namespace std;
int main(){
    int min=9999;
    int minn=0;
    
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    
                    if(j<i && k<j && l<k && l>0){
                        long nb=999*i+90*j-90*k-999*l;
                        int n=1000*i+100*j+10*k+l;
                        if(nb<min){
                            min=nb;
                            minn=n;
                        }
                        cout<< "D = "<<nb<<" for N="<<n<<endl;
                    }
                }
            }
        }
    }
    cout<< "Minimum absolu : D = "<<min<<" for N="<<minn<<endl;
    return 0;
}
