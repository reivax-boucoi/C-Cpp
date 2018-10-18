// g++ -Wall -pedantic nbToLetters.cpp -o test.exe

#include <iostream>
#include <string>

using namespace std;

void PrintNumber(int nb);
string NumberToText(int nb);
int WrittenNumberLength(int nb);
string GetSub100(int nb);
string GetSub1000(int nb);

string units[10]={"zero","un","deux","trois","quatre","cinq","six","sept","huit","neuf"};
string firstDozen[10]={"dix","onze","douze","treize","quatorze","quinze","seize","dix-sept","dix-huit","dix-neuf"};
string dozens[10]={"","","vingt","trente","quarante","cinquante","soixante","soixante-","quatre-vingt","quatre-vingt-"};

int main(void){

	int stats[100]={0};
	int max=0;
	int maxIndex=0;
	int temp=0;
	int searchSpan=0;
	
	cout << "enter searchSpan : ";
	cin >> searchSpan;
	
	for(int i=0;i<searchSpan;i++){
		temp=WrittenNumberLength(i);
		stats[temp]++;
		if(temp>max){
			max=temp;
			maxIndex=i;
			cout << "found longer at " << maxIndex << endl;
		}
	}
	cout << "max length of " << max << " at " << maxIndex << " (below " << searchSpan << ")" << endl;
	
	cout << endl << "distribution :" << endl;
	for(int y=0;y<100;y++){
		cout << y << " : " << stats[y] << endl;
	}

	return 0;
}

void PrintNumber(int nb){
	string number = NumberToText(nb);
	cout << nb <<" s'ecrit ainsi : " << number << endl; // spits out nb
}

int WrittenNumberLength(int nb){
	string number=NumberToText(nb);
	return number.size();
}

string NumberToText(int nb){ //gets >100 nbs

	string number="";
	
	if(nb>1000){
		if(nb>1999){
		number+=GetSub1000(nb/1000);
		number+=" ";
		}
		number+="mille ";
		nb=nb%1000;
	}
	number+=GetSub1000(nb);
	return number;
	
}

string GetSub1000(int nb){
	string number="";
	if(nb>99){ // hundreds
		if(nb>199){ // cent special case
			number+=GetSub100(nb/100);
			number+=" ";
		}
		number+="cent ";
		nb=nb%100;
	}
	number+=GetSub100(nb); // adds sub 100 text
	return number;
}

string GetSub100(int nb){ // gets sub 100 text
	if(nb==1){
		return "un";
	}
	string number="";
	int dozen = nb/10;
	
	number=dozens[dozen]; // 10's
	if(dozen == 1 || dozen == 7 || dozen == 9){ // special 10's, 70's, 90's
		number+=firstDozen[nb%10];
	}else{
	
		number+=" ";
		nb=nb%10;
		
		if(nb==1){
			number+="et un"; // special "et un"
		}else{
			number+=units[nb];
		}
	}
	return number;

}
