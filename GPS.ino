#include <TinyGPS++.h> //Libary TinyGPS
#include <SoftwareSerial.h> //Libarary softwareserial
#include <Ultrasonic.h>
// Choose two Arduino pins to use for software serial
int RXPin = 2; //Connect  TX GPS
int TXPin = 3; //Connect  RX GPS
Ultrasonic ultrasonic(7, 8);
int distance;
int GPSBaud = 9600; //default baud
long duration;
const int buzzerPin=10;

// Creating TinyGPS++ objects
TinyGPSPlus gps;

// Create a serial connection with the  "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  //Starting a serial connection on baudrate 9600
  Serial.begin(9600);
  //Starting a serial connection with a sensor 
  pinMode(buzzerPin,OUTPUT);
  gpsSerial.begin(GPSBaud);

}

void loop()
{
  //Creating a data display when there is a connection 
  while (gpsSerial.available() > 0){
    if (gps.encode(gpsSerial.read())){
      obs();
      displayInfo();
      }
    else{

    }
  }

  // if within 5 seconds there is no connection, an error "No GPS detected" will appear.
}
void obs(){
  distance = ultrasonic.read();
  Serial.println(distance);
  if(distance<20){
    digitalWrite(buzzerPin,HIGH);
  }
  else{
    digitalWrite(buzzerPin,LOW);
  }
}
void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(" ");
    Serial.print(gps.location.lng(), 6);
    Serial.print(" ");
    // Serial.print("Altitude: ");
    // Serial.println(gps.altitude.meters())
  }
  else
  {

}
}
