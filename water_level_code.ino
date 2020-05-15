
  #include <NewPing.h> 
  
  #define TRIGGER_PIN 12 // Arduino pin tied to trigger pin on the ultrasonic sensor.
  #define ECHO_PIN 11 // Arduino pin tied to echo pin on the ultrasonic sensor.
  #define MAX_DISTANCE 10 // Height of the Water Tank (in centimeters). 
  #include <LiquidCrystal.h> 
  
  int RS=A5, E=A4, D4=A3, D5=A2, D6=A1, D7=A0;
  LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // initialize the library with the numbers of the interface pins
  int Buzzer = 13;
  int Relay = 10;
  int val=0;
  NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
  
  // Creating Charaters for Bar Graph and Reverse Mode Icon
  byte Level0[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
  };
  byte Level1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111
  };
  byte Level2[8] = {
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
  };
  byte Level3[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
  };
  byte NoLevel[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
  };
  
  
  void setup() 
  {
  lcd.createChar(0, Level0);
  lcd.createChar(1, Level1);
  lcd.createChar(2, Level2);
  lcd.createChar(3, Level3);
  lcd.createChar(4, NoLevel);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows: 
  pinMode(Buzzer,OUTPUT); //Setup Buzzer pin as output pin
  pinMode(Relay,OUTPUT); //Setup Relay pin as output pin
  digitalWrite(Relay,LOW);
  
  }
  
  void loop() 
  {
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  val=sonar.ping_cm();
  lcd.setCursor(0, 1);
  lcd.print("LOW");
  lcd.setCursor(11, 1);
  lcd.print("HIGH");
  if(val<4) //Water level reaches the Top of the Tank
  {
  
  delay(50);
  lcd.setCursor(3, 1); 
  lcd.write(byte(0));
  lcd.setCursor(4, 1); 
  lcd.write(byte(0));
  lcd.setCursor(5, 1); 
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(1));
  lcd.setCursor(7, 1);
  lcd.write(byte(2));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(9, 1);
  lcd.write(byte(3));
  lcd.setCursor(10, 1);
  lcd.write(byte(3));
  digitalWrite(Relay,LOW); //Pump off
  lcd.setCursor(0,0);
  lcd.print("PUMP OFF ");
  }
  
  else if(val<=15&&val>4) //Water level is getting close to the tank
  {
  lcd.setCursor(3, 1); 
  lcd.write(byte(0));
  lcd.setCursor(4, 1); 
  lcd.write(byte(0));
  lcd.setCursor(5, 1); 
  lcd.write(byte(1));
  lcd.setCursor(6, 1); 
  lcd.write(byte(1));
  lcd.setCursor(7, 1);
  lcd.write(byte(2));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(9, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(4));
  
  
  }
  else if(val<=20&&val>15)
  { 
  lcd.setCursor(3, 1); 
  lcd.write(byte(0));
  lcd.setCursor(4, 1); 
  lcd.write(byte(0));
  lcd.setCursor(5, 1); 
  lcd.write(byte(1));
  lcd.setCursor(6, 1); 
  lcd.write(byte(1));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(9, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(4));
  
  
  
  }
  
  else if(val<=21&&val>20)
  {
  
  lcd.setCursor(3, 1); 
  lcd.write(byte(0));
  lcd.setCursor(4, 1); 
  lcd.write(byte(0));
  lcd.setCursor(5, 1); 
  lcd.write(byte(4));
  lcd.setCursor(6, 1); 
  lcd.write(byte(4));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(9, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(4));
  
  
  }
  else if(val>21) // Water is empty on the Tank
  {
  
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  digitalWrite(Buzzer,LOW);
  delay(1000);
  digitalWrite(Relay,HIGH); // Pump ON
  lcd.setCursor(0,0);
  lcd.print("PUMP ON ");
  lcd.setCursor(3, 1); 
  lcd.write(byte(4));
  lcd.setCursor(4, 1); 
  lcd.write(byte(4));
  lcd.setCursor(5, 1); 
  lcd.write(byte(4));
  lcd.setCursor(6, 1); 
  lcd.write(byte(4));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(9, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(4));
  }
  
  
  
  }
