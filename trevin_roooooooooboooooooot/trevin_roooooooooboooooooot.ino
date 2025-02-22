//trevin lalala, play music

#include "pitches.h"
#include <Servo.h>

Servo lefty;
Servo righty;


//notes in melody
int melody[] = {
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4
};

int harmony[] = {
  NOTE_C4, NOTE_G4, NOTE_D4, NOTE_G4, NOTE_G3, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_C4
};
int noteDurations2[] = {
  4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4
};

//ultrayayaya

int trigPin = 9;
int echoPin = 8;
int mr = 2;
int ml = 4;
int button = 3;
int tell = 1;
int played = 0;
int nextsong = 1;
int posit = 0;

float duration = 0;
float distance = 0;

void setup() {
  // iterate over the notes of the melody:




  //ultrayayayaya

  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);

  // motorrrrrrr
  //  pinMode (mr, OUTPUT);
  //  pinMode (ml, OUTPUT);
  //
  //  digitalWrite(mr, HIGH);
  //  delay(1000);
  //  digitalWrite(mr, HIGH);
  //  delay(500);

  // buttttttonnnnnnnnnnnjjnjnjnj
  pinMode (button, INPUT_PULLUP);

  //servo motor
  lefty.attach(5);
  righty.attach(6);



}

void loop() {

  tell = digitalRead(button);





  Serial.print("buttonstate");
  Serial.println(digitalRead(button));




  // no need to repeat the melody.

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = 0.017 * duration;
  if (distance < 70) {
    Serial.println("hello whoever");
    wheelstop ();
   
    tell = digitalRead(button);
    if (tell == 0  && played == 0) {
      if (nextsong == 1) {
        music1();
      } else {
        music2();
      }
    }
    else {
      played = 0;
    }
  }
  else {
    Serial.print("distance: ");
    Serial.print(distance);
    Serial.println("cm");
    wheelmove ();
     moveearms();



  }
  delay(500);
}

void music1() {

  for (int thisNote = 0; thisNote < 11; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    int noteDuration2 = 1000 / noteDurations2[thisNote];


    tone(10, melody[thisNote], noteDuration);


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(10);


  }
  nextsong = 2;
  played = 1;

}

void music2() {

  for (int thisNote = 0; thisNote < 11; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    int noteDuration2 = 1000 / noteDurations2[thisNote];

    tone(11, harmony[thisNote], noteDuration2);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes2 = noteDuration2 * 1.3;
    delay(pauseBetweenNotes2);

    noTone(11);
  }
  nextsong = 1;
  played = 1;
}

void wheelstop() {

  digitalWrite(mr, LOW);
  digitalWrite(ml, LOW);

}

void wheelmove() {

  digitalWrite(mr, HIGH);
  digitalWrite(ml, HIGH);
  delay(100);

}

void moveearms() {
  // pos += 1 == pos = pos + 1
  for (posit = 0; posit <= 180; posit += 2) {
    lefty.write(posit);
    righty.write(posit);
    delay(12);
  }
  for (posit = 180; posit >= 0; posit -= 2) {
    lefty.write(posit);
    righty.write(posit);
    delay(12);
  }

}
//
//void moveeleft(){
//   // pos += 1 == pos = pos + 1
//  for (posit = 0; posit <= 180; posit += 1) {
//    lefty.write(posit);
//    delay(12);
//  }
//  for (posit = 180; posit >= 0; posit -= 1) {
//    lefty.write(posit);
//    delay(12);
//  }
//}
//void moveeright() {
//  // pos += 1 == pos = pos + 1
//  for (posit = 0; posit <= 180; posit += 1) {
//    righty.write(posit);
//    delay(12);
//  }
//  for (posit = 180; posit >= 0; posit -= 1) {
//    righty.write(posit);
//    delay(12);
//  }
//}
