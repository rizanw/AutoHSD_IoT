const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int relay_pin = 3;
int led_pin = 13;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(relay_pin,OUTPUT);
   pinMode(led_pin,OUTPUT);
   digitalWrite(led_pin,HIGH);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   if( cm < 10){
      digitalWrite(relay_pin,HIGH);
   }else{
      digitalWrite(relay_pin,LOW);
   }
   delay(100);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
