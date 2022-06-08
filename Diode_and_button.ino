//controlling LED with a button
#include <OneButton.h>

int BTN_PIN = 3;
int LED_PIN = 6; //use pwm pin 
int ledstate = 0;

OneButton button(BTN_PIN, true); //create object of a button

void setup() //set up components
{
  pinMode(LED_PIN,OUTPUT);
  analogWrite(LED_PIN,ledstate);
  button.attachClick(turn_on_and_off); //all the actions are taking place in the additional function (not in the loop) - very convenient
  Serial.begin(9600);
}
void loop()
{
  button.tick(); // remember to always check for the button ticks
}
void turn_on_and_off()
{
  
  if(ledstate==0)
  {
    Serial.println("Turned off");
    analogWrite(LED_PIN,ledstate); //using analogwrite to use full potential of pwn pins(pins which allows to send more complex signals than 0 and 1) 
    ledstate=10;                   //in this case we choose 10 as the brightness of our LED
  }
  else
  {
    Serial.println("Turned on");
    analogWrite(LED_PIN,ledstate);
    ledstate=0;
  }
}
