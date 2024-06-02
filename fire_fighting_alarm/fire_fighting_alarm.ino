#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define flamePin A0
#define red 9
#define green 10
#define buzzer 11

void setup() {
   lcd.begin(16, 2);
   pinMode(flamePin, INPUT_PULLUP);
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
   pinMode(buzzer, OUTPUT);
    lcd.setCursor(0, 0);
    lcd.print(" FIRE DETECTOR ");
    lcd.setCursor(0, 1);
    lcd.print("  SYSTEM - EIF  ");
    delay(2000);
    lcd.clear();
}

void loop() {

int fire_value = digitalRead(flamePin);

if(fire_value == HIGH)
{
digitalWrite(green, LOW);
digitalWrite(buzzer, HIGH);
ledon();
lcdon();
  
}
else
{
lcdoff();
ledoff();
}
  
}

void ledon()
{
digitalWrite(red, HIGH);   
  delay(200);                       
  digitalWrite(red, LOW);    
  delay(200);    
}

void ledoff()
{
digitalWrite(red, LOW);
digitalWrite(green, HIGH);
digitalWrite(buzzer, LOW);
}


void lcdon()
{
  lcd.setCursor(0, 0);
  lcd.print(" FIRE DETECTED  ");
  lcd.setCursor(0, 1);
  lcd.print(" ALERT ALERT !! ");
  delay(300);
  lcd.clear();
}

void lcdoff()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    NO FIRE  ");
  lcd.setCursor(0, 1);
  lcd.print("  DETECTED !! ");
  delay(300);
}
