
// this is a ultrasonic test by Trevin

int trigPin = 9;
int echoPin = 8;

float duration = 0;
float distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = 0.017 * duration;
  if ((40 > distance) && (distance > 20)){
    Serial.println("hello, i am YESSSSS robot, i like ice cream, i do not care if i am talking to a wall ");
  }
  else {
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");

  
}
delay(500);
}
