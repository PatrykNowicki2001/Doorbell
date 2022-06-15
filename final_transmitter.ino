#include <VirtualWire.h>
#include <OneButton.h>
 
// definiujemy piny 
#define BTN_PIN 2
#define led_pin 3
#define transmit_pin 10
OneButton button1(BTN_PIN, true);

void setup()
{
  // przygotowujemy potrzebne informacje dla biblioteki
    button1.attachClick(funkcja);
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
    pinMode(led_pin, OUTPUT);
    Serial.begin(9600);
    Serial.println("setup");
}
 
void loop()
{
  button1.tick(); 
}

void funkcja()
{
  String toSend = ("hello world"); // tekst wiadomości
  char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy char'ów
  
  analogWrite(led_pin, 50); // zapalamy LED
  vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
  vw_wait_tx(); 
  Serial.println("dupa");
  analogWrite(led_pin, 0); // gasimy LED
}
