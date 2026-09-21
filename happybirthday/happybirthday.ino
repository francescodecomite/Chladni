// set piano notes (frequencies)
#define c 3830 
#define d 3400 
#define e 3038 
#define f 2864 
#define g 2550 
#define a 2272 
#define b 2028 
#define C 1912 
#define R 0

// buzzer pin is D26 on ESP32 

int buzzOut  = 26;
int startFlag = 1;
int flagPlay=1;
// this rhythm_measure is the tempo of the song
long rhythm_measure = 10000;
 
int pauseTime = 500;
int do_nothing = 2; 
 
int audioTone = 0;
int beat1 = 0;
long timedur  = 0;

void setup() {
   // set the buzzer as output component for melody
   pinMode(buzzOut, OUTPUT);
   if (startFlag) {
      // specify the baud rate
      Serial.begin(9600); 
   }
}

// these are the music notes for Twinkle twinkle little star poem
double songNotes[] = {
   c,c,g,g,a,a,g,
   f,f,e,e,d,d,c,
   g,g,f,f,e,e,d,
   g,g,f,f,e,e,d,
   c,c,g,g,a,a,g,
   f,f,e,e,d,d,c
};

int MAX_COUNT = sizeof(songNotes) / 2; 
 
// this is the function which makes the buzzer high and low while playing the poem notes
void playNotes() {
   long passed_time = 0;
   if (audioTone > 0) { 
     
      while (passed_time < timedur) {
      digitalWrite(buzzOut,HIGH);
      delayMicroseconds(audioTone / 2);
      digitalWrite(buzzOut, LOW);
      delayMicroseconds(audioTone / 2);
      passed_time += (audioTone);
      }
   }
   else { 
      for (int n = 0; n < do_nothing; n++) { 
         delayMicroseconds(timedur); 
      }   
   } 
                           
}
void loop() {
   for (int m=0; m<MAX_COUNT; m++) {
      audioTone = songNotes[m];
       beat1 = 50;


       timedur = beat1 * rhythm_measure; 
       if( flagPlay != 0)        {
         playNotes();
      }
     
      delayMicroseconds(pauseTime);
   }
   delay(500);
} 