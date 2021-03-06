//This sketch is allowing us to change state of LED (turning it on and off) by hitting the breadboard
int VIB_PIN = 7; //connect SW-420 sensor to desired pin
int LED_PIN = 3; //connect LED diode to desired pwm pin
int sensor_state = 1; //initialising sensor state variable ( =1 is not needed)
int diode_state = 1; //initialising LED state (starting from LED being on)
void setup() 
{
  pinMode(LED_PIN, OUTPUT); //setting up LED as output of digital pins and sensors as input
  pinMode(VIB_PIN, INPUT);
  Serial.begin(9600); //setting up serial monitor
}

void loop()
{
  Serial.print("Vibration status: "); //printing every 100ms "Vibration status:" in serial monitor
  sensor_state = digitalRead(VIB_PIN); //checking if sensor was hit
  if (sensor_state == 1)  //if sensor is hit- HIGH on the D0 PIN
  {
    Serial.println("Sensing vibration");  //printing that it is sensing vibration and changing diode state to opposite
    diode_state = !diode_state ;
  }
  else
  {
    Serial.println("No vibration");  //if it is not hit it prints that there is no vibration
  }
  analogWrite(LED_PIN, diode_state*10);  //lighting up LED dependant on led state - if diode state = 1 lights up LED of brightness 10/256
  delay(100);
}
