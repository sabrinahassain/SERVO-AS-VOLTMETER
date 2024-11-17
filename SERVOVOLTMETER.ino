/*servo motor's position correspond to the voltage level that can be interpreted as a voltmeter, the main theme is using PWM control and mapping values*/ 
 
#include <Servo.h>  
  
Servo myservo;  // create servo object to control the servo 
  
int potpin = A0;  // analog pin used to connect the potentiometer (acts as voltage input) 
int val;           // variable to read the value from the analog pin 
  
void setup() {  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);  
} 
  
void loop() {  
  val = analogRead(potpin);    // reads the value of the potentiometer (value between 0 and 1023) 
  int pos = map(val, 0, 1023, 0, 180);   // scale the potentiometer value to use it with the servo (0 to 180) 
  
  // Calculate the voltage corresponding to the potentiometer value (0-1023) 
  float voltage = val * (5.0 / 1023.0);  // Map the value to 0 to 5V 
   
  Serial.print("Voltage: "); 
  Serial.println(voltage);  // Print the voltage to the Serial Monitor 
  
  myservo.write(pos);    // set the servo position according to the scaled potentiometer value (position = voltage) 
  delay(15);   // wait for the servo to get there 
} 