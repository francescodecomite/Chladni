/**
 * Play a simple repeating tone on a piezo buzzer.
 *
 * See: https://makeabilitylab.github.io/physcomp/esp32/tone

EN fait les interruptions c'est le bazar, cette version devrait marcher
 */
#include <Arduino.h>
int analogValue=100; 
int newValue=analogValue;
int freq=440;
const int BUZZER_PIN=26; 

int n=0; 

void setup() {
  
  Serial.begin(115200);
  analogValue=analogRead(34); 
  Serial.println("ça commence...");
  pinMode(BUZZER_PIN, OUTPUT);
  


}

void loop() {
 n=n+1; 
 newValue=analogRead(34); 
 if (n%10000==0){
 
  if(abs(newValue-analogValue)>0.5*analogValue){
    analogValue=newValue; 
    freq = map(analogValue, 0, 4095, 100, 1500);
    Serial.println(freq);
    tone(BUZZER_PIN, freq); 
  }
 
 }
  
}

