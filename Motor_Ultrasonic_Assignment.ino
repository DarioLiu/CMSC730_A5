// #include <ESP32Servo.h>

// Servo myservo;

int pos = 0;
int servoPin = 13;
const int trigPin = 14;
const int echoPin = 12;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoPin, OUTPUT);


}

void mysweep(int p)  
{
  int peakTime = map(p, 0, 180, 500, 2600);
  int entirePauseWidth = 20000;
  digitalWrite(servoPin , HIGH);
  delayMicroseconds(peakTime);

  int lowTime = entirePauseWidth - peakTime;
  digitalWrite(servoPin, LOW);
  delayMicroseconds(lowTime);


}
int dist(){
  long duration, distance = -1;
  digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  if(duration == 0){
    Serial.println("Timeout or error in reading sensor");
    return -1;
  }
  distance = (duration/2)*0.0343;
   if(distance >= 20) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  return distance;
  

}

void loop() {
  // unsigned long currentMillis = millis();

  // if (currentMillis - previousMillisServo >= intervalServo){
  //   previousMillisServo = currentMillis;
  //   rotateServo();
  // }
  // if (currentMillis - previousMillisUltra >= intervalUltra){
  //   previousMillisUltra = currentMillis;
  //   measureAndDisplayDistance();
  int distance = dist(); // Get the distance
  

  for(pos = 0; pos <= 180; pos++) {
    mysweep(pos);
    delay(5);  // Adjust this delay for servo speed
    dist();
  delay(10);
    
  }
  for(pos = 180; pos >= 0; pos--) {
    mysweep(pos);
    delay(5);  // Adjust this delay for servo speed
    dist();
  
  delay(10);
  } 

}

// void measureAndDisplayDistance() {
//   int distance = dist(); // Get the distance
//   if(distance >= 20) {
//     Serial.println("Out of range");
//   } else {
//     Serial.print(distance);
//     Serial.println(" cm");
//   }
//   delay(600); // Wait a bit before the next measurement (you can adjust this delay as needed)
// }

// void rotateServo() {
//   for(pos = 0; pos <= 180; pos++) {
//     mysweep(pos);
//     delay(5);  // Adjust this delay for servo speed
//   }
//   for(pos = 180; pos >= 0; pos--) {
//     mysweep(pos);
//     delay(5);  // Adjust this delay for servo speed
//   }
// }


  // professor's demonstrations:
  
  
 
   
    






