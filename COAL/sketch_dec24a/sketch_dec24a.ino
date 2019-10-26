#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include<SPI.h>
#include<SD.h>

const int rxPin = 0;
const int txPin = 1;

const int LED = 10;

SoftwareSerial mySerial(rxPin, txPin);

LiquidCrystal lcd(9, 8 , 6, 5, 3, 2);

PulseSensorPlayground pulseSensor;
File MyFile ;

int Threshold = 600;
int data = A0;
int myBPM = 0;
int avg = 0;
unsigned long temp = 0;
String string = "\0" ;
String fname = "" ;
String Date = "" ;
String Time = "" ;

char ch = '\0';

byte customChar1[8] = {0b00000, 0b00000, 0b00011, 0b00111, 0b01111, 0b01111, 0b01111, 0b01111};
byte customChar2[8] = {0b00000, 0b11000, 0b11100, 0b11110, 0b11111, 0b11111, 0b11111, 0b11111};
byte customChar3[8] = {0b00000, 0b00011, 0b00111, 0b01111, 0b11111, 0b11111, 0b11111, 0b11111};
byte customChar4[8] = {0b00000, 0b10000, 0b11000, 0b11100, 0b11110, 0b11110, 0b11110, 0b11110};
byte customChar5[8] = {0b00111, 0b00011, 0b00001, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};
byte customChar6[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b01111, 0b00111, 0b00011, 0b00001};
byte customChar7[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b11110, 0b11100, 0b11000, 0b10000};
byte customChar8[8] = {0b11100, 0b11000, 0b10000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ConnectBluetooth");
  lcd.setCursor(0, 1);
  lcd.print("And Login...");
  Serial.begin(9600);
  mySerial.begin(9600);
  while (1)
  {
    while (mySerial.available() <= 0);
    ch = mySerial.read();
    Serial.write(ch);
    if (ch == '#')
      break;
    if (ch == '!')
    {
      Serial.println(string);
      string = "";

    }
    else if (ch == '=')
    {
      Date = string;
      string = "";
    }
    else if (ch != '*' && ch != 1)
    {
      string += ch;
    }
  }

  Time = string;
  fname = fname + ".txt";
  string = "";
  Serial.println(fname);
  Serial.println(Date);
  Serial.println(Time);
  while (!SD.begin(4))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Insert SD Card...");

  }


  pulseSensor.analogInput(data);
  pulseSensor.blinkOnPulse(LED);
  pulseSensor.setThreshold(Threshold);

  while (!pulseSensor.begin())
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Insert heart");
    lcd.setCursor(0, 1);
    lcd.print("beat sensor ...");
  }

  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);
  lcd.createChar(8, customChar8);

}

void loop()
{
  myBPM = 0;
  avg = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Option");
  lcd.setCursor(0, 1);
  lcd.print("On Device...");

  while (1)
  {
    while (mySerial.available() <= 0);
    ch = (char)mySerial.read();
    Serial.println(ch);
    if (ch == '1' || ch == '2' || ch == '3')
      break;
  }

  if (ch == '1')
  {
    lcd.clear();

    temp = millis();

    while (millis() <= (temp + 10000))
    {
      if (pulseSensor.sawStartOfBeat())
      {
        myBPM = myBPM + pulseSensor.getBeatsPerMinute();
        avg++;
      }

      lcd.setCursor(0, 0);
      lcd.print("BPM : ");
      lcd.print(myBPM);

      lcd.setCursor(0, 1);
      lcd.print("Reading :");
      lcd.print(avg);

      lcd.setCursor(12, 0);
      lcd.write(byte(1));
      lcd.setCursor(13, 0);
      lcd.write(byte(2));
      lcd.setCursor(14, 0);
      lcd.write(byte(3));
      lcd.setCursor(15, 0);
      lcd.write(byte(4));

      lcd.setCursor(12, 1);
      lcd.write(byte(5));
      lcd.setCursor(13, 1);
      lcd.write(byte(6));
      lcd.setCursor(14, 1);
      lcd.write(byte(7));
      lcd.setCursor(15, 1);
      lcd.write(byte(8));

      delay(20);

      lcd.clear();
    }

    if (myBPM > 0)
    {
      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.setCursor(2, 0);
      lcd.write(byte(1));
      lcd.setCursor(3, 0);
      lcd.write(byte(2));
      lcd.setCursor(4, 0);
      lcd.write(byte(3));
      lcd.setCursor(5, 0);
      lcd.write(byte(4));

      lcd.setCursor(2, 1);
      lcd.write(byte(5));
      lcd.setCursor(3, 1);
      lcd.write(byte(6));
      lcd.setCursor(4, 1);
      lcd.write(byte(7));
      lcd.setCursor(5, 1);
      lcd.write(byte(8));

      myBPM = myBPM / avg;
      lcd.setCursor(7, 1);
      lcd.print("BPM : ");
      lcd.print(myBPM);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);

      MyFile = SD.open(fname, FILE_WRITE);

      if (MyFile)
      {
        MyFile.print("DATE : ");
        MyFile.println(Date);
        MyFile.print("TIME : ");
        MyFile.println(Time);
        MyFile.print("BPM : ");
        MyFile.println(myBPM);
        MyFile.println("-------------------------------");
        lcd.print("BPM Recorded");
        MyFile.close();
      }
      else
      {
        lcd.print("File Not Created");
        lcd.setCursor(0, 1);
        lcd.print("BPM Not Recorded");
      }
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Place Your");
      lcd.setCursor(0, 1);
      lcd.print("Finger On Sensor");
    }
    delay(2000);
  }
  else if (ch == '2')
  {
    ch = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sending Data..");
    delay(5);
    MyFile = SD.open(fname, FILE_READ);
    if (MyFile)
    {
      while (MyFile.available())
      {
        ch = MyFile.read();
        mySerial.write(ch);
        Serial.write(ch);
        delay(5);
      }
      MyFile.close();
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.println("File Not Exist!");
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Data Sent");
    delay(2000);
  }
  else if (ch == '3')
  {

    string = "";
    Date = "";
    fname = "";
    ch = '\0';
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Login First...");
    while (1)
    {
      while (mySerial.available() <= 0);
      ch = (char)mySerial.read();
      Serial.write(ch);
      if (ch == '#')
        break;
      if (ch == '!')
      {
        fname = string;
        string = "";
      }
      else if (ch == '=')
      {
        Date = string;
        string = "";
      }
      else if (ch != '*' && ch != 1)
      {
        string += ch;
      }
    }
    Time = string;
    fname = fname + ".txt";
    string = "";

    Serial.println(fname);
    Serial.println(Date);
    Serial.println(Time);
  }
  ch = '\0';
}
