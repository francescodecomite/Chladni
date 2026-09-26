/**
 * Play a simple repeating tone on a piezo buzzer.
 *
 * See: https://makeabilitylab.github.io/physcomp/esp32/tone
 */
#include <Arduino.h>

const int BUZZER_PIN = 26;
const int potar=34; 
int analogValue=440; 
int freq=0; 

TimerHandle_t blinkTimer = NULL;

bool ledState = false;

void BlinkCallback(TimerHandle_t xTimer) {
 int newValue=analogRead(potar);
 if (abs(newValue-analogValue)>0.05*analogValue)
 {analogValue=newValue;
 }
}

void setup() {
  analogValue=analogRead(34); 
  Serial.begin(115200);
  Serial.println("Playing concert A (440 Hz)...");
  pinMode(BUZZER_PIN, OUTPUT);

   blinkTimer = xTimerCreate(
    "BlinkTimer",                   // Timer name
    10000 / portTICK_PERIOD_MS,      // 1s period
    pdTRUE,                         // Auto-reload (periodic timer)
    NULL,                           // Timer ID
    BlinkCallback                   // Callback function
  );
  if (blinkTimer == NULL) {
    Serial.println("Failed to create timer!");
    while (1);
  }

  xTimerStart(blinkTimer, 0); // Start timer immediately
}



void loop() {
   //int analogValue = analogRead(34);
  // Rescale to potentiometer's voltage (from 0V to 3.3V):
  freq = map(analogValue, 0, 4095, 100, 1500);
  
  

  tone(BUZZER_PIN, freq);       // Play concert A (440 Hz)
  
}

/*
*/