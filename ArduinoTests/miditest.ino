//file version 0.0.1 ali undestanding

#include <MIDI.h>

const int Nota = 7; //pin D4
int stato=0;
MIDI_CREATE_DEFAULT_INSTANCE();


void setup()
{
  pinMode(Nota, INPUT);
    MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
}
void loop()
{
  stato=digitalRead(Nota);
  if(stato==HIGH)
  {
    MIDI.sendNoteOn(42,127,1);
    //midi_note_on(1,42,127);
    MIDI.read();
    delay(500);
    MIDI.sendNoteOff(42,127,1);
  }
}
