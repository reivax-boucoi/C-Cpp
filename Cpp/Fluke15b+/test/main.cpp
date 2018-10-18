#include <iostream>
#include <windows.h>

#include <unistd.h>

#include "Serial.cpp"
// g++ -Wall -pedantic main1.cpp -o test1.exe

#define DIGIT_DP 0x80
using namespace std;
//				 I1   I2   D4   D3   D2   D1   I3   I4
int input[8] = {0};
const int digits[10]={0x7D,0x05,0x5B,0x1F,0x27,0x3E,0x7E,0x15,0x7F,0x3F};
void sendPing(char data);
void receiveData(int*data);
void displayData(int*data);
int showDigit(int code);
void delay(void);
	CSerial serial;

int main(void){
	if (serial.Open(3, 2400)){
	cout << "success connecting";
	while(serial.IsOpened()){
		sendPing('d');
		receiveData(input);
		/*
		for(int i=0;i<8;i++){
			cout<<input[i]<<' ';
		}
		cout <<endl;
		*/
		displayData(input);
		delay();
	}
	}else{
		cout << "Failed connecting to port";
		return -1;
	}
	serial.Close();
	return 0;
}

void delay(void){
	   for ( unsigned int c = 1 ; c <= 32767 ; c++ )
       for ( unsigned int d = 1 ; d <= 10000 ; d++ ){}
}
int showDigit(int code){
	for(int i=0;i<10;i++){if(code==digits[i])return i;}
	return -1;	
}

void sendPing(char data){
	serial.SendData(&data,1);
	cout << "sent ping" << endl;
}
void receiveData(int*data){
	cout << "starting read" << endl;
	/*while(serial.IsOpened() && serial.ReadDataWaiting() < 8){
	//	cout << serial.ReadDataWaiting()<< endl;
	}*/
	if(serial.IsOpened()){
		if(serial.ReadData(data, 8)==8)cout << "success reading"<<endl; else cout <<"failed reading"<<endl;
	}else{
		cout << "closed while receiving !" << endl;
	}
}
void displayData(int*data){

	if(data[6]&(1<<3)){cout << "-";}
	for(int i=5;i>1;i--){
		cout << showDigit(data[i]);
		if(data[i]&(1<<7)){cout << '.';}
	}
	if(data[1]&(1<<3)){cout << "Volts";}
	if(data[0]&(1<<1)){cout << "mV";}
	if(data[0]&(1<<0)){cout << "Amps";}
	if(data[7]&(1<<3)){cout << "µA";}
	if(data[7]&(1<<0)){cout << "mA";}
	if(data[1]&(1<<5)){cout << " DC";}
	if(data[1]&(1<<6)){cout << " AC";}
	if(data[1]&(1<<0)){cout << "nF";}
	if(data[1]&(1<<1)){cout << "µF";}
	if(data[1]&(1<<2)){cout << "F";}
	if(data[0]&(1<<4)){cout << "Vf";}
	if(data[0]&(1<<5)){cout << "%";}
	if(data[0]&(1<<6)){cout << "M";}
	if(data[0]&(1<<7)){cout << "k";}
	if(data[1]&(1<<2)){cout << "[Ohms]";}
	if(data[0]&(1<<3)){cout << "Hz";}
	cout << endl;
}