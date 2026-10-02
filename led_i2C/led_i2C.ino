
 
// #include < Wire .h> we are removing this because it is already added in liquid crystal library
#include <LiquidCrystal_I2C.h>
 
// Create the lcd object address 0x3F and 16 columns x 2 rows 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
 int debut=0; 
  String chaine="Va niquer ta mere gros connard"; 
  int u=chaine.length(); 

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();  // Make sure backlight is on

  // Print a message on both lines of the LCD.
  lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
 
 
  lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
  lcd.print(chaine.substring(0,16));
}

void loop() {
  while(1){
    delay(200); 
    lcd.clear(); 
    lcd.setCursor(2, 1);
    debut=debut+1; 
    lcd.print(chaine.substring(debut,(debut+16)%chaine.length()));
  }
}