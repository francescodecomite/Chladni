/**
 * Play a simple repeating tone on a piezo buzzer.
 *
 * See: https://makeabilitylab.github.io/physcomp/esp32/tone
 */
const int BUZZER_PIN = 26;

void setup() {
  Serial.begin(115200);
  Serial.println("Playing concert A (440 Hz)...");
}

void loop() {
  tone(BUZZER_PIN, 440);       // Play concert A (440 Hz)
  delay(100000);                 // Let it play for one second
  noTone(BUZZER_PIN);          // Stop the tone
  delay(500);                  // Pause for half a second
}