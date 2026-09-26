/**
 * Play a simple repeating tone on a piezo buzzer.
 *
 * See: https://makeabilitylab.github.io/physcomp/esp32/tone

EN fait les interruptions c'est le bazar, cette version devrait marcher
 */
#include <Arduino.h>
int analogValue=100; 
int newValue=analogValue; 

int n=0; 

void setup() {
  
  Serial.begin(115200);
 
}

void loop() {
 n=n+1; 
 newValue=analogRead(34); 
 if (n%10000==0){
  Serial.print(n); 
  Serial.print(" ");
  if(abs(newValue-analogValue)>0.5*analogValue){
    analogValue=newValue; 
  }
  Serial.println(analogValue);
 }
}

