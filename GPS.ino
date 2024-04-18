#include <TinyGPS++.h> //Libary TinyGPS
#include <SoftwareSerial.h> //Libarary bawaan
#include <Ultrasonic.h>
// Choose two Arduino pins to use for software serial
int RXPin = 2; //Connect ke TX GPS
int TXPin = 3; //Connect ke RX GPS
Ultrasonic ultrasonic(7, 8);
int distance;
int GPSBaud = 9600; //Biarin default
long duration;
const int buzzerPin=10;

// Membuat objek TinyGPS++
TinyGPSPlus gps;

// Mmebuat koneksi serial dengan nama "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  //Memulai koneksi serial pada baudrate 9600
  Serial.begin(9600);
  //Memulai koneksi serial dengan sensor
  pinMode(buzzerPin,OUTPUT);
  gpsSerial.begin(GPSBaud);

}

void loop()
{
  //Membuat tampilan data ketika terdapat koneksi
  while (gpsSerial.available() > 0){
    if (gps.encode(gpsSerial.read())){
      obs();
      displayInfo();
      }
    else{

    }
  }

  // Jika dalam 5 detik tidak ada koneksi, maka akan muncul error "No GPS detected"
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
