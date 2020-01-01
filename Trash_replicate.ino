#include <WiFiNINA.h> 
#include <BlynkSimpleWiFiNINA.h>

const char* ssid = "MH";    
const char* password = "2222222222";  
char auth[] = "wfxedfv6sTByWHXQyKIMWF3O23igxs7u"; 

BlynkTimer timer;

WidgetLED green(V1);
WidgetLED orange(V2);
WidgetLED red(V3);

const int trigPin = 12;
const int echoPin = 13;

int thresh[3] = {7, 17, 27}; //this sets the height for the indicators and can be adjusted depending on the trash bin
long duration;
int distance;

void sensor(){
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance 
  distance= duration*0.034/2;
// Printing the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}

void amountOfTrash() {
  if(distance<thresh[0]){
    green.on();
    orange.on();
    red.on();
    }
  else if(distance<thresh[1]){
    green.on();
    orange.on();
  }
  else if(distance<thresh[2]){
    green.on();
 
  }
  else{
    green.off();
    orange.off();
    red.off();
  delay(1000);
}
}

void setup()
{
  // Debug console
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  Blynk.begin(auth, ssid, password);

}


void loop()
{
  Blynk.run();
  sensor();
  amountOfTrash();
}
