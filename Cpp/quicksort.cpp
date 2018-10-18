// g++ -Wall -pedantic quicksort.cpp -o test1.exe

#include <iostream>
using namespace std;

int main(void){

	cout << "Start" << endl;
	
	int array[10]={1,9,7,3,5,4,6,5,0,5};
	int x=0;
	
	for(x=0;x<9;x++){
		cout << array[x] << ',';
	}
	cout  << array[++x] << endl;
	
	
	int truc=0;
	int min=0;
	int minIndex=0;
	int tera=0;
	
	//cout << truc << endl;
	
	for(int i=0;i<10;i++){
		min=array[i];
		minIndex=i;
		for(int y=i;y<10;y++){
			if(array[y]<min){
				min=array[y];
				minIndex=y;
			}
		}
		tera=array[i];
		array[minIndex]=tera;
		array[i]=min;
	}
	
	for(x=0;x<9;x++){
		cout << array[x] << ',';
	}
	cout << array[++x] << endl;
	cout << sizeof(array) << endl;
	/*while(1){
		
	}*/
	return 0;
}