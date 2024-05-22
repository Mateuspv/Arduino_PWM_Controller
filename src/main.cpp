#include <Arduino.h>

int button = 2;
int motor = 9;

int buttonState = 0;
int lastButtonState = 0;
int speedIndex = 0; 

void setup() {
  pinMode(button,INPUT_PULLUP);
}
void loop() {
  buttonState = digitalRead(button);

  if (lastButtonState == LOW && buttonState == HIGH) {
    speedIndex++;
    if(speedIndex == 0){
      analogWrite(9, 255);
    } else if(speedIndex == 1){
      analogWrite(9, 191);
    } else if(speedIndex == 2){
      analogWrite(9, 127);
    } else if(speedIndex == 3){
      analogWrite(9, 64);
    } else if(speedIndex == 4){
      analogWrite(9, 0);
    } else if(speedIndex == 5){
      analogWrite(9, 255);
      speedIndex = 0;
    }

  } 

  lastButtonState = buttonState;
}



