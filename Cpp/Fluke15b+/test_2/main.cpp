#include <stdio.h>
#include <string.h>
#include "SerialPort.cpp"

#define I1_AMP		(1<<0)
#define I1_MILLIV	(1<<1)
#define I1_FARAD	(1<<2)
#define I1_HZ		(1<<3)
#define I1_DIODE	(1<<4)
#define I1_PCT		(1<<5)
#define I1_MEGA		(1<<6)
#define I1_KILO		(1<<7)

#define I2_NANOF	(1<<0)
#define I2_MICROF	(1<<1)
#define I2_OHM		(1<<2)
#define I2_VOLT		(1<<4)
#define I2_DC		(1<<5)
#define I2_AC		(1<<6)
#define I2_AUTO		(1<<7)

#define I3_CONT		(1<<0) //continuency test
#define I3_HOLD		(1<<1)
#define I3_MINUS	(1<<3)

#define I4_MILLIA	(1<<0)
#define I4_MICROA	(1<<3)
#define I4_MANUAL	(1<<7)

#define DIGIT_DP 0x80
#define DIGIT_0 0x7D
#define DIGIT_1 0x05
#define DIGIT_2 0x5B
#define DIGIT_3 0x1F
#define DIGIT_4 0x27
#define DIGIT_5 0x3E
#define DIGIT_6 0x7E
#define DIGIT_7 0x15
#define DIGIT_8 0x7F
#define DIGIT_9 0x3F


using namespace mn::CppLinuxSerial;

static int lcdToDec(int lcd, int digit) {
	const int digits[]={DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, 
			DIGIT_7, DIGIT_8, DIGIT_9};
	int x;
	for (x=0; x<10; x++) if (lcd==digits[x]) return x;
	return 0;
}
//int data[8]={0x02,0x30,0x95,0x7D,0x15,0x05,0x00,0x80};
std::string data="blank data";
float value;
int pow(int b){
    int r=1;
    for(int i=0;i<b;i++){
        r*=10;
    }
    return r;
}

int main(void){
    int i=1;
    SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_2400);
    serialPort.Open();
    serialPort.Write("n");
    serialPort.Write("n");
    
        serialPort.Write("d");
        serialPort.Read(data);
        serialPort.Write("d");
        serialPort.Read(data);
    
    while(i){
        char unit[10]="";
        value=0.0;
        serialPort.Write("d");
        serialPort.Read(data);
        
        for(int j=0;j<4;j++){
            int a=lcdToDec(data[j+2]&0x7f, j)*pow(j);
            if(a==-1){
                printf("Invalid data received !\r\n");
                break;
            }
            value+=a;
        }
        if (data[2]&0x80) value/=10.0;
        if (data[3]&0x80) value/=100.0;
        if (data[4]&0x80) value/=1000.0;

        if (data[6]&I3_MINUS) value=-value;

        if (data[0]&I1_MILLIV) strcpy(unit,"m");
        if (data[0]&I1_MEGA) strcpy(unit,"M");
        if (data[0]&I1_KILO) strcpy(unit,"k");
        if (data[1]&I2_NANOF) strcpy(unit,"n");
        if (data[1]&I2_MICROF) strcpy(unit,"u");
        if (data[7]&I4_MILLIA) strcpy(unit,"m");
        if (data[7]&I4_MICROA) strcpy(unit,"u");

        if (data[0]&I1_FARAD) strncat(unit,"F",5);
        if (data[0]&I1_AMP) strncat(unit,"A",5);
        if (data[0]&I1_PCT) strncat(unit,"%",5);
        if (data[0]&I1_HZ) strncat(unit,"Hz",5);
        if (data[1]&I2_OHM) strncat(unit,"Ohm",5);
        if (data[1]&I2_VOLT) strncat(unit,"V",5);

        if (data[1]&I2_AC) strncat(unit,"AC",5);
        if (data[1]&I2_DC) strncat(unit,"DC",5);
        
        printf("%4.3f%s\r\n",value,unit);
        printf("Enter 1 for a read, 0 to exit : ");
        scanf("%d",&i);
    }
    serialPort.Close();
	return 0;
}
