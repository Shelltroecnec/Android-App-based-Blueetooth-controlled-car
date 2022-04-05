//*LCD INITIALIZATION*//
#include <LiquidCrystal.h>
const int rs=47,rw=46, en=45, d0=44, d1=43, d2=42, d3=41, d4 = 40, d5 = 39, d6 = 38, d7 = 37;
LiquidCrystal lcd(rs, rw,en,d0,d1,d2,d3, d4, d5, d6, d7);

int Relay=32;
int buzzer=31;
int LED1=22;
int LED2=23;
//*BLUETOOTH INITIALIZATION*//
char c[4];
int count1=0;
char a[4]={'0','7','0','1'};

//*MOTOR INITIALIZATION*//
int Motor1=33;
int Motor2=34;

void setup() {
 lcd.begin(16,2); //SELECTING LCD COLUMNS & ROWS
 Serial.begin(9600); //INITALIZING SERIAL COMMUNICATION
 Serial2.begin(9600); //INITALIZING BLUETOOTH SERIAL COMMUNICATION
 pinMode(Motor1,OUTPUT); //DIFINING MOTOR1 AS OUTPUT DEVICE
 pinMode(Motor2,OUTPUT); //DIFINING MOTOR2 AS OUTPUT DEVICE
  pinMode(Relay,INPUT); //DIFINING RELAY AS INPUT DEVICE
  pinMode(LED1,OUTPUT); //DIFINING LED1 AS OUTPUT DEVICE
  pinMode(LED2,OUTPUT); //DIFINING LED21 AS OUTPUT DEVICE
  pinMode(buzzer,OUTPUT); //DIFINING BUZZER AS OUTPUT DEVICE
  digitalWrite(Relay,LOW);//INITIALIZING RELAY OFF
  digitalWrite(LED1,HIGH); //INITIALIZING LED1 OFF
  digitalWrite(LED2,HIGH); //INITIALIZING LED2 OFF
  digitalWrite(Motor1,LOW); //INITIALIZING MOTOR1 OFF
  digitalWrite(Motor2,LOW); //INITIALIZING MOTOR2 OFF
  while(i!=3){              //MAKING MSG BLINK FOR 3 TIMES
  lcd.noDisplay(); 
delay(500);
lcd.display();
  lcd.print("! BLUETOOTH ! ");
  lcd.setCursor(0,1);
  lcd.print("HOME APPLIANCES ");
  delay(500);
  i++;
}}

void loop() {
   if (Serial2.available()){  //IF BLUETOOTH IS CONNECTED  
  c=Serial2.read();    //SERIALLY READ FROM BLUETOOTH IS 'c'
  }
  if(c=='1')
  {
   lcd.clear();   //MAKING LCD CLEAR FOR PRINTING
  lcd.write("ROOM1-ON"); //LCD OUTPUT
  lcd.setCursor(0,1);
  lcd.write("LIGHT1/FAN1-0N");
  digitalWrite(LED1,LOW);   //LED1 ON
  digitalWrite(Motor1,HIGH);  //FAN ON
  Serial2.println("ROOM_1: FAN1-ON & LIGHT1-ON");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  }
  if(c=='2')
  {
   lcd.clear();
   lcd.write("ROOM2-ON"); //LCD OUTPUT
  lcd.setCursor(0,1);
  lcd.write("LIGHT2/FAN2-0N");
  digitalWrite(LED2,LOW);   //LED1 ON
  digitalWrite(Motor2,HIGH);  //FAN ON
  Serial2.println("ROOM_2: FAN2-ON & LIGHT2-ON");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  }
  if(c=='3')
  {
   lcd.clear();
   lcd.write("ROOM1-OFF"); //LCD OUTPUT
  lcd.setCursor(0,1);
  lcd.write("LIGHT1/FAN1-0FF");
  digitalWrite(LED2,HIGH);   //LED1 ON
  digitalWrite(Motor2,LOW);  //FAN ON
  Serial2.println("ROOM_1: FAN1-OFF & LIGHT1-OFF");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  }
  if(c=='4')
  {
   lcd.clear();
   lcd.write("ROOM2-OFF"); //LCD OUTPUT
  lcd.setCursor(0,1);
  lcd.write("LIGHT2/FAN2-0FF");
  digitalWrite(LED2,HIGH);   //LED1 ON
  digitalWrite(Motor2,LOW);  //FAN ON
  Serial2.println("ROOM_2: FAN2-OFF & LIGHT2-OFF");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  }
  if(c=='5')
  {
   lcd.clear();
   lcd.write("AC-ON"); //LCD OUTPUT
  digitalWrite(Relay,HIGH);   //AC ON
  delay(2000);
  digitalWrite(Relay,LOW);  //AC OFF
  lcd.clear();
  lcd.write("AC-OFF");
  Serial2.println("AC OFF AFTER 2 SECONDS");  //PRINTING OUTPUT ON BLUETOOTH TERMINAL THROUGH BLUETOOTH 
  }}
  
