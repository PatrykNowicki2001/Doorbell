#include <OneButton.h>
#include "notes.h"
const int BTN_PIN = 2;
const int BTN2_PIN = 4;
const int SEN_PIN = 3;
int buzzer = 10;
OneButton button1(BTN_PIN, true);
OneButton button2(BTN2_PIN, true);
int sensor_state;
int counter = 0;
int tempo = 135;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;


void setup() 
{
  button1.attachClick(music);
  button2.attachClick(add);
  pinMode(SEN_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Setup done");
}

void loop() {
  button1.tick();
  button2.tick();
}

void music()
{
  if(counter==0)
  {
  Serial.println("music playing");
  for (int thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2) 
  {
    divider = melody1[thisNote + 1];
    ;
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    tone(buzzer, melody1[thisNote], noteDuration * 0.9);
    sensor_state = digitalRead(SEN_PIN);
    delay(noteDuration);
    sensor_state = digitalRead(SEN_PIN);
    noTone(buzzer);
    sensor_state = digitalRead(SEN_PIN);
    if(sensor_state==1)
    {
      Serial.println("music stopped");
      break;
    }
    } 
  }
  else
  {
      for (int thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2) 
  {
    divider = melody2[thisNote + 1];
    ;
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    tone(buzzer, melody2[thisNote], noteDuration * 0.9);
    sensor_state = digitalRead(SEN_PIN);
    delay(noteDuration);
    sensor_state = digitalRead(SEN_PIN);
    noTone(buzzer);
    sensor_state = digitalRead(SEN_PIN);
    if(sensor_state==1)
    {
      Serial.println("music stopped");
      break;
    }
    } 
  }
}
void add()
{
  counter=!counter;
  Serial.println(counter);
}
