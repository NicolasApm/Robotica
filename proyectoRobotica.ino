#include <SoftwareSerial.h>

SoftwareSerial ModBluetooth(2, 3); // RX | TX
int value = 0;
const int inputPin = A0;
String Init = "?";
String ShObj = "?";
String InitBit = "Ok";
String StopBit = "#";
int Send = 0;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  pinMode(inputPin, INPUT);
  pinMode(11, INPUT);
  digitalWrite(12, LOW);

  ModBluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  String conc = InitBit + "," + Init + "," + ShObj + StopBit;
  ModBluetooth.print(conc);
  button();
  if (ModBluetooth.available())
  {
    Shape(value);
  }
  // ModBluetooth.print(conc);
  delay(100);
}

void Shape(int value1) {

  char VarChar = ModBluetooth.read();
  if (value == LOW) {

    if (VarChar == '0')
    {
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      ShObj = "Rec";
      VarChar = '\n';
    }

    else if (VarChar == '1')
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      ShObj = "Tri";
      Send = 1;
      VarChar = '\n';
    }

    else if (VarChar == '2')
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      
      ShObj = "Cir";
      VarChar = '\n';
    }
    else {
      VarChar = '\n';
    }
  }
}

void button() {
  value = digitalRead(inputPin);  //lectura digital de pin
  if (value == HIGH) {
    delay(100);
    value = HIGH;
    digitalWrite(13, HIGH);
    Init = "Run";
    Shape(value);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
  else {
    delay(100);
    value = LOW;
    Init = "Stop";
    digitalWrite(13, LOW);
    Shape(value);
  }
}

