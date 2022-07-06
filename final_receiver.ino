#include <VirtualWire.h>
#include "notes.h"
#define led_pin 3
#define receive_pin 11
#define SEN_PIN  2
#define buzzer  10

int sensor_state;
int counter = 0;
int tempo = 135;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
 
void setup()
{
    Serial.begin(9600);
    Serial.println("setup");
// przygotowujemy potrzebne informacje dla biblioteki
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);   
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)
    pinMode(SEN_PIN, INPUT)
    pinMode(led_pin, OUTPUT);
}
 
void loop()
{
    
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
 
  if (vw_get_message(buf, &buflen)) // if we get data
  {
  int i;
  String wiadomosc;       
  for (i = 0; i < buflen; i++) // we look for data from receiver
  {
        wiadomosc+=char(buf[i]);
  }
  Serial.println(wiadomosc);
  music();
  }
}

void music()
{
 for (int thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2) 
  {
    divider = melody1[thisNote + 1];
    
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    tone(buzzer, melody1[thisNote], noteDuration * 0.9);
    sensor_state = digitalRead(SEN_PIN);
    if(sensor_state==1)
    {
      Serial.println("music stopped");
      break;
    }
    delay(noteDuration);
    sensor_state = digitalRead(SEN_PIN);
    if(sensor_state==1)
    {
      Serial.println("music stopped");
      break;
    }
    noTone(buzzer);
    sensor_state = digitalRead(SEN_PIN);
    if(sensor_state==1)
    {
      Serial.println("music stopped");
      break;
    }
  }
}
