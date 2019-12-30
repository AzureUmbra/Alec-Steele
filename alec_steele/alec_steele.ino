#include <AccelStepper.h>

// Defining buttons for input and pot
// Don't forget pull-down resistors on your buttons!
#define UP_L A0
#define DN_L A1
#define UP_R A2
#define DN_R A3
#define POT  A4

// Define a value for max stepper speed
#define MAXSPEED 1000

// Defines 2 stepper motors
AccelStepper stepperL(AccelStepper::FULL4WIRE, 2, 3, 4, 5);
AccelStepper stepperR(AccelStepper::FULL4WIRE, 6, 7, 8, 9);

// Define variable to control motor direction
int motorState = 0;

// Define variable to set movement speed
int motorSpeed = MAXSPEED/2;

void setup() {
  // Setup 4 pins to be the input for buttons for control and 1 for the pot
  pinMode(UP_L, INPUT);
  pinMode(UP_R, INPUT);
  pinMode(DN_L, INPUT);
  pinMode(DN_R, INPUT);
  pinMode(POT, INPUT);

  // Setup the steppers
  stepperL.setMaxSpeed(1000);
  stepperR.setMaxSpeed(1000);
  stepperL.setSpeed(0);
  stepperR.setSpeed(0);
}

void loop() {
  // Check the buttons and assign a bitwise values
  motorState = digitalRead(UP_L) + (digitalRead(UP_R) * 2) + (digitalRead(DN_L) * 4) + (digitalRead(DN_R) * 8);

  // Check the pot, and map it so it's full range of motion is useful
  motorSpeed = map(analogRead(POT), 0, 1023, 0, MAXSPEED);

  switch (motorState) {
    case 0:
      //both doors do not move
      stepperL.stop();
      stepperR.stop();
      break;
    case 1:
      //left door moves up
      stepperL.setSpeed(motorSpeed);
      stepperL.runSpeed();
      stepperR.stop();
      break;
    case 2:
      //right door moves up
      stepperL.stop();
      stepperR.setSpeed(motorSpeed);
      stepperR.runSpeed();
      break;
    case 3:
      //both doors move up
      stepperL.setSpeed(motorSpeed);
      stepperL.runSpeed();
      stepperR.setSpeed(motorSpeed);
      stepperR.runSpeed();
      break;
    case 4:
      //left door moves down
      stepperL.setSpeed(-motorSpeed);
      stepperL.runSpeed();
      stepperR.stop();
      break;
    case 5:
      //invalid state, decide what you want to do for safety
      //this is pushing up and down at the same time on the left door
      stepperL.stop();
      stepperR.stop();
      break;
    case 6:
      //left door moves down, right door moves up
      stepperL.setSpeed(-motorSpeed);
      stepperL.runSpeed();
      stepperR.setSpeed(motorSpeed);
      stepperR.runSpeed();
      break;
    case 7:
      //invalid state, decide what you want to do for safety
      //this is pushing up and down at the same time on the left door, and pushing up on the right
      stepperL.stop();
      stepperR.stop();
      break;
    case 8:
      //right door moves down
      stepperL.stop();
      stepperR.setSpeed(-motorSpeed);
      stepperR.runSpeed();
      break;
    case 9:
      //left door moves up, right door moves down
      stepperL.setSpeed(motorSpeed);
      stepperL.runSpeed();
      stepperR.setSpeed(-motorSpeed);
      stepperR.runSpeed();
      break;
    case 10:
      //invalid state, decide what you want to do for safety
      //this is pushing up and down at the same time on the right door
      stepperL.stop();
      stepperR.stop();
      break;
    case 11:
      //invalid state, decide what you want to do for safety
      //this is pushing up and down at the same time on the right door, and pushing up on the left
      stepperL.stop();
      stepperR.stop();
      break;
    case 12:
      //both doors move down
      stepperL.setSpeed(-motorSpeed);
      stepperL.runSpeed();
      stepperR.setSpeed(-motorSpeed);
      stepperR.runSpeed();
      break;
    case 13:
      //invalid state, decide what you want to do for safety
      //this is pushing up and down at the same time on the left door, and pushing down on the right
      stepperL.stop();
      stepperR.stop();
      break;
    case 14:
      //invalid state, decide what you want to do for safety
      //this is pushing up and down at the same time on the right door, and pushing down on the left
      stepperL.stop();
      stepperR.stop();
      break;
    case 15:
      //VERY invalid state, decide what you want to do for safety
      // this is literally just mashing all 4 buttons at the same time
      stepperL.stop();
      stepperR.stop();
      break;
  }

}
