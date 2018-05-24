/*
========================================================================================
Ultrassound Theremino - Andre Bahiense - May 2018

For this application you will need the Tone.h library, besides the comon Ultrassonic.h.
You can find Tone.h in: https://github.com/andrebahiense/PolyphonicPiano
And Ultrassonic.h you can add through the Arduino IDE.

Use it as you wish
=========================================================================================*/
#include <Ultrasonic.h>
#include <Tone.h>

#define trigger 4
#define echo 5

Ultrasonic ultrasonic(trigger, echo);

Tone tone1;

int flagb=0;
 

void setup() {
  Serial.begin(9600);
  tone1.begin(12);
  float som = 0;
  float ex=0;
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
}
 
void loop() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  digitalWrite(9, HIGH); 
  
  if(digitalRead(10) == HIGH && flagb == 0){
    theremin();
    if(digitalRead(10) == HIGH){
      flagb=1;
    }
  }
  else if(digitalRead(10) == HIGH && flagb==1){
    pentatonic();
    if(digitalRead(10) == HIGH){
      flagb=2;
    }
  }
  else if(digitalRead(10) == HIGH && flagb==2){
    harmonic();
    if(digitalRead(10) == HIGH){
      flagb=0;
    }
  }

  //Serial.println(cmMsec);
  Serial.print(digitalRead(10));

}

void theremin(){
  float ex;
  float cmMsec;
  float som;
  ex = pow(0.6104*cmMsec,2);
  som = ex + 9.3886*cmMsec+ 215.11;
  
  if(som >= 130 && som <= 2000){  
    tone1.play(som);
  }

  else{
    tone1.stop();
  }
}

void pentatonic(){
  float cmMsec;
  if(cmMsec>=4 && cmMsec<9){
    tone1.play(262);
  }
  else if(cmMsec>9 && cmMsec<14){
    tone1.play(311);
  }
  else if(cmMsec>14 && cmMsec<19){
    tone1.play(349);
  }
  else if(cmMsec>19 && cmMsec<24){
    tone1.play(392);
  }
  else if(cmMsec>24 && cmMsec<29){
    tone1.play(466);
  }
  else if(cmMsec>29 && cmMsec<34){
    tone1.play(523);
  }
  else{
    tone1.stop();
  }
}

void harmonic(){
  float cmMsec;
  if(cmMsec>=4 && cmMsec<9){
    tone1.play(220);
  }
  else if(cmMsec>9 && cmMsec<14){
    tone1.play(330);
  }
  else if(cmMsec>14 && cmMsec<19){
    tone1.play(440);
  }
  else if(cmMsec>19 && cmMsec<24){
    tone1.play(550);
  }
  else if(cmMsec>24 && cmMsec<29){
    tone1.play(660);
  }
  else if(cmMsec>29 && cmMsec<34){
    tone1.play(770);
  }
  else{
    tone1.stop();
  }
}
