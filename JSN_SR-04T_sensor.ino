#include <LiquidCrystal_I2C.h> //Lcd library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

#define trig 9   
#define echo 8 
#define led 7
#define relay 10

void setup() {
  lcd.init();                  
  lcd.backlight();
  Serial.begin(9600); 
  
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT_PULLUP);  
  pinMode(led, OUTPUT); 
  pinMode(relay, OUTPUT); 
  } 
  
  void loop() { 
    
    digitalWrite(trig, LOW); 
    delayMicroseconds(2); 
    
    digitalWrite(trig, HIGH); 
    delayMicroseconds(20); 
    
    digitalWrite(trig, LOW); 
    float Cm = pulseIn(echo, HIGH,26000); 
    
    Cm= Cm/58;
                          
    lcd.clear();
    lcd.print("Cm:");
    lcd.setCursor(0,1);
    lcd.print(Cm,1);
    lcd.setCursor(6,1);
    lcd.print("cm");
    delay(500);

      if (Cm<=20)
   {
 digitalWrite(led,HIGH);
 digitalWrite(relay,LOW);
 
 delay(1000);
}
   else 
   {
 digitalWrite(led,LOW);
  digitalWrite(relay,HIGH);
 
 delay(1000);
 }

}
    
