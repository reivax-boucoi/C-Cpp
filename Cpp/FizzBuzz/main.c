#include <iostream>

using namespace std;

int main(void){
	unsigned int n=0;
	bool state;
	while(n<1000){
		n++;
		if(n%3==0){
			cout << "Fizz";
			state=true;
		}
		if(n%5==0){
			cout << "Buzz";
			state=true;
		}
		if(!state){
			cout << n;
		}
		cout << endl;
		state=false;
	}
	return 0;
}