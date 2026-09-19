// Define the buzzer pin
int buzzerPin = 8;
// entrées du haut-parleur : ground et 8
// Note definitions for the melody
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_C5 523

// Define the "Happy Birthday" melody
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, // "Happy Birthday to You"
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, // "Happy Birthday to You"
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, // "Happy Birthday dear [Name]"
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4 // "Happy Birthday to You"
};

// Define the note durations
int noteDurations[] = {
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2
};



void setup() {
  while(1){
  // Iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 24; thisNote++) {
    // To calculate the note duration, take one second divided by the note type.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // To distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing:
    noTone(buzzerPin);
  }
   
  }
}

void loop() {
  // No need to repeat the melody in the loop for this example.
  // The setup() is enough to play it once.
}