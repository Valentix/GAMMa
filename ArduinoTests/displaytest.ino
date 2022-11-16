#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 tm1637(CLK, DIO);
void tmconv(int n);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tm1637.init();
  tm1637.set(0);
  tm1637.display(3,3);
  tm1637.display(2,2);
  tm1637.display(1,1);
  tm1637.display(0,0);
}

int n=0;

void loop() {
  // put your main code here, to run repeatedly:
  //tmconv(n);
  //n++;
  //delay(100);
  //tm1637.display(0,1);
  //if(n>9999)
  //  n=0;
}

void tmconv(int n)
{
  tm1637.display(3,n%16);
  tm1637.display(2,(n/10)%16);
  tm1637.display(1,(n/100)%16);
  tm1637.display(0,(n/1000)%16);
}
