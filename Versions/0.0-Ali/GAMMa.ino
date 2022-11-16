//file version 0.0.1 ali undestanding

#include <MIDI.h>     //midi

#include "TM1637.h"   //display
#define CLK 2         //
#define DIO 3         //

#define tou 6         //touch sensors

//midi
int stato=0;
MIDI_CREATE_DEFAULT_INSTANCE();

//display
TM1637 tm1637(CLK, DIO);
int n=0;
int notes[12]={12,23,13,24,14,15,16,6,20,10,21,11};//note decode C=12, Db=22=(10+12) so if n>16 is b
void displayWriter(int n);
void tmconv(int n);
void noteWriter(int n);

//touch sensor
bool touchPre[10]={false};
void midiPlayer(int note);
void midiPlayer(int note, int power, int channel);

//trimmer
int sensorPin = A4;
int sensorValue = 0;
int shifter = 0;
int oldshift = 1;
int smartTrimmer();

void setup(){
  //midi
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
    
  //display
  tm1637.init();
  tm1637.set(0);
  
  //touch sensor
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  //trimmer
}
void loop()
{
  displayWriter(shifter);
  smartTrimmer();
  int note=shifter;

  for(int i=0;i<10;i++)
  {
    if(digitalRead(4+i)==HIGH && !touchPre[i])
    {
      MIDI.sendNoteOn(note+i,127,1);
      MIDI.read();
      touchPre[i]=true;
    }
    if(digitalRead(4+i)==LOW && touchPre[i])
    {
      MIDI.sendNoteOff(note+i,127,1);
      MIDI.read();
      touchPre[i]=false;
    }
  }
    /*if(digitalRead(6)==HIGH && !touchPre[0])
    {
      MIDI.sendNoteOn(note,127,1);
      touchPre[0]=true;
    }
    if(digitalRead(6)==LOW && touchPre[0])
    {
      MIDI.sendNoteOff(note,127,1);
      touchPre[0]=false;
    }*/
    delay(10);
}
void midiPlayer(int note){
  midiPlayer(note,127,1);
}
void midiPlayer(int note, int power, int channel){
  MIDI.sendNoteOn(note,power,channel);
  while(digitalRead(tou)!=LOW)
    delay(10);
  MIDI.sendNoteOff(note,127,1);
}
void displayWriter(int n){
  int octave=(n/12)%12;
  tmconv(octave);
  noteWriter(n%12);
}
void noteWriter(int n){  //converts 0-11 to C-B with b
  if(notes[n]>15)
  {
    tm1637.display(2,notes[n]-10);
    tm1637.display(3,11);
  }
  else
  {
    tm1637.display(2,notes[n]);
    tm1637.display(3,17);
  }
}
void tmconv(int n){
  tm1637.display(1,n%10);
  if((n/10)!=0)
    tm1637.display(0,(n/10)%10);
  else
    tm1637.display(0,17);
}
int smartTrimmer(){
  if(shifter>=0 && shifter<=117)
  {
    switch(map(analogRead(sensorPin), 0, 1023, 1, 5))
    {
      case 1:
        if(shifter>0)
          shifter--;
        delay(100);
        break;
      case 2:
        if(shifter>0)
          shifter--;
        delay(500);
        break;
      case 4:
        if (shifter<117)
          shifter++;
        delay(500);
        break;
      case 5:
        if (shifter<117)
          shifter++;
        delay(100);
        break;
    }
  }
}
