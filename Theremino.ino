#include <Ultrasonic.h>
#include <Tone.h>

#define trigger 4
#define echo 5

Ultrasonic ultrasonic(trigger, echo);

Tone tone1; 
 
void setup() {
  Serial.begin(9600);
  tone1.begin(12);
  float som = 0;
  float ex=0;
}
 
void loop() {
  float cmMsec;
  float som;
  float ex;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  ex = pow(0.6104*cmMsec,2);
  som = ex + 9.3886*cmMsec+ 215.11;
  
  if(som >= 130 && som <= 2000){  
    tone1.play(som);
  }

  else{
    tone1.stop();
  }
   
  Serial.println(cmMsec);

}
