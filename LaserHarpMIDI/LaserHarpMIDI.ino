#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

// LDR's
const int NPots = 4; // Number of LDRs
int potPin[NPots] = {A0, A1, A2, A3}; // LDR pins
int potCState[NPots] = {0}; // Current LDR state

int midiCState[NPots] = {0}; // Current state of the MIDI value

bool block1 = false; //Used the check if a beam is blocked
bool block2 = false;
bool block3 = false;
bool block4 = false;
byte midiCh = 1; // MIDI channel to be used
int threshold = 400;

void setup() {

  Serial.begin(115200); 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

}

void loop() {
  potentiometers();
}

// POTENTIOMETERS
void potentiometers() {

  delay(10);
  
  
  potCState[0] = analogRead(potPin[0]);
  //Serial.println(potCState[0]);
  if(potCState[0] > threshold) {
    if(!block1) {
      MIDI.sendNoteOn(40, 127, midiCh);
      block1 = true;
    } else {
      midiCState[0] = map(potCState[0], threshold, 1000, 127, 0); // Maps the LDR value to be used in MIDI
      MIDI.sendControlChange(1, midiCState[0], midiCh); // controller number, controller value, MIDI channel
    }
  } else {
    MIDI.sendNoteOn(40, 0, midiCh);
    block1 = false;
  }
  
  potCState[1] = analogRead(potPin[1]);
  //Serial.println(potCState[1]);
  if(potCState[1] > threshold) {
    if(!block2) {
      MIDI.sendNoteOn(50, 127, midiCh);
      block2 = true;
    } else {
      midiCState[1] = map(potCState[1], threshold, 1000, 127, 0); // Maps the LDR value to be used in MIDI
      MIDI.sendControlChange(1, midiCState[1], midiCh); // controller number, controller value, MIDI channel
    }
  } else {
    MIDI.sendNoteOn(50, 0, midiCh);
    block2 = false;
  }

  potCState[2] = analogRead(potPin[2]);
  //Serial.println(potCState[2]);
  if(potCState[2] > threshold) {
    if(!block3) {
      MIDI.sendNoteOn(60, 127, midiCh);
      block3 = true;
    } else {
      midiCState[2] = map(potCState[2], threshold, 1000, 127, 0); // Maps the LDR value to be used in MIDI
      MIDI.sendControlChange(1, midiCState[2], midiCh); // controller number, controller value, MIDI channel
    }
  } else {
    MIDI.sendNoteOn(60, 0, midiCh);
    block3 = false;
  }

  potCState[3] = analogRead(potPin[3]);
  //Serial.println(potCState[3]);
  if(potCState[3] > threshold) { 
    if(!block4) {
      MIDI.sendNoteOn(70, 127, midiCh);
      block4 = true;
    } else {
      midiCState[3] = map(potCState[3], threshold, 1000, 127, 0); // Maps the LDR value to be used in MIDI
      MIDI.sendControlChange(1, midiCState[3], midiCh); // controller number, controller value, MIDI channel
    }
  } else {
    MIDI.sendNoteOn(70, 0, midiCh);
    block4 = false;
  }
}
