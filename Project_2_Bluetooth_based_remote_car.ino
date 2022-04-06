//*LCD INITIALIZATION*//
#include <LiquidCrystal.h>
const int rs=47,rw=46, en=45, d0=44, d1=43, d2=42, d3=41, d4 = 40, d5 = 39, d6 = 38, d7 = 37;
LiquidCrystal lcd(rs, rw,en,d0,d1,d2,d3, d4, d5, d6, d7);

int LED1=22;
int LED2=23;
int c;

//*MOTOR INITIALIZATION*//
int Motor1=33;
int Motor2=34;
int Motor3=35;
int Motor4=36;

void setup(){
lcd.begin(16,2); //SELECTING LCD COLUMNS & ROWS
 Serial.begin(9600); //INITALIZING SERIAL COMMUNICATION
 Serial2.begin(9600); //INITALIZING BLUETOOTH SERIAL COMMUNICATION
  pinMode(LED1,OUTPUT); //DIFINING LED1 AS OUTPUT DEVICE
  pinMode(LED2,OUTPUT); //DIFINING LED21 AS OUTPUT DEVICE
  digitalWrite(LED1,HIGH); //INITIALIZING LED1 OFF
  digitalWrite(LED2,HIGH); //INITIALIZING LED2 OFF
  lcd.write("START GO GO!!");
  }
void loop(){
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  if (Serial2.available()){  //IF BLUETOOTH IS CONNECTED  
  c=Serial2.read();    //SERIALLY READ FROM BLUETOOTH IS 'c'
  }
  if(c=='1')
  {
   lcd.clear();   //MAKING LCD CLEAR FOR PRINTING
  lcd.write("FORWARD"); //LCD OUTPUT
  digitalWrite(Motor1,HIGH);   //MOTOR1 ON
  digitalWrite(Motor3,HIGH);  //MOTOR2 ON
  }
  if(c=='2')
  {
   lcd.clear();
   lcd.write("TURNING RIGHT"); //LCD OUTPUT
  digitalWrite(Motor1,LOW);   //MOTOR1 OFF
  digitalWrite(Motor3,HIGH);  //MOTOR3 ON
  }
  if(c=='3')
  {
   lcd.clear();
   lcd.write("TURNING LEFT"); //LCD OUTPUT
  digitalWrite(Motor3,LOW);   //MOTOR3 OFF
  digitalWrite(Motor1,HIGH);  //MOTOR1 ON
  }
  if(c=='4')
  {
   lcd.clear();
   lcd.write("REVERSE"); //LCD OUTPUT
  digitalWrite(Motor2,HIGH);   //MOTOR2 ON
  digitalWrite(Motor4,HIGH);  //MOTOR4 ON
  }
}
