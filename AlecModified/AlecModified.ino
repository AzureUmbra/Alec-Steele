// named constants for the switch and motor pins;
int switchPin1 = 2; // The number of the Counter Clockwise pin
int reversePin1 = 3; // The number of the clockwise pin
int driverPUL1 = 7;    // PUL- pin
int driverDIR1 = 6;    // DIR- pin
int switchPin2 = 8; // The number of the Counter Clockwise pin
int reversePin2 = 9; // The number of the clockwise pin
int driverPUL2 = 12;    // PUL- pin
int driverDIR2 = 11;    // DIR- pin
int spd = A0;     // Potentiometer


// Variables
 
int pd = 500;       // Pulse Delay period
boolean setdir = HIGH; // Set Direction
int buttonState = 0; //Binary expression of pressed buttons

// Array info for each stepper
// Active1?,Direction1?,Active2?,Direction2?
int stepperActive[] = {0,0};
bool stepperDir[] = {LOW,LOW};


void setup() {
  // Initialise the MotorPin as an output:
  pinMode(driverPUL1, OUTPUT);
  pinMode(driverDIR1, OUTPUT);
  // Initialise the switchPin as an input:
  pinMode(switchPin1, INPUT); 
  pinMode(reversePin1, INPUT);
   // Initialise the MotorPin as an output:
  pinMode(driverPUL2, OUTPUT);
  pinMode(driverDIR2, OUTPUT);
  // Initialise the switchPin as an input:
  pinMode(switchPin2, INPUT); 
  pinMode(reversePin2, INPUT);

}

void loop() {
  // Check the buttons and assign a bitwise values
  buttonState = digitalRead(reversePin1) + (digitalRead(reversePin2) * 2) + (digitalRead(switchPin1) * 4) + (digitalRead(switchPin2) * 8);

  // Check the pot, and map it so it's full range of motion is useful
  pd = map(analogRead(spd), 0, 1023, 2000, 50);

  switch (buttonState) {
    case 0:
      //both doors do not move
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 1:
      //motor 1 moves CW
      stepperActive[0] = 1;
      stepperActive[1] = 0;
      stepperDir[0] = {setdir};
      break;
    case 2:
      //motor 2 moves CW
      stepperActive[0] = 0;
      stepperActive[1] = 1;
      stepperDir[1] = {setdir};
      break;
    case 3:
      //both move CW
      stepperActive[0] = 1;
      stepperActive[1] = 1;
      stepperDir[0] = {setdir};
      stepperDir[1] = {setdir};
      break;
    case 4:
      //motor 1 moves CCW
      stepperActive[0] = 1;
      stepperActive[1] = 0;
      stepperDir[0] = {!setdir};
      break;
    case 5:
      //invalid state, decide what you want to do for safety
      //this is pushing CW and CCW at the same time on motor 1
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 6:
      //motor 1 moves CCW, motor 2 moves CW
      stepperActive[0] = 1;
      stepperActive[1] = 1;
      stepperDir[0] = {!setdir};
      stepperDir[1] = {setdir};
      break;
    case 7:
      //invalid state, decide what you want to do for safety
      //this is pushing CW and CCW at the same time on motor 1, and pushing CW on motor 2
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 8:
      //motor 2 moves CCW
      stepperActive[0] = 0;
      stepperActive[1] = 1;
      stepperDir[1] = {!setdir};
      break;
    case 9:
      //motor 1 moves CW, motor 2 moves CCW
      stepperActive[0] = 1;
      stepperActive[1] = 1;
      stepperDir[0] = {setdir};
      stepperDir[1] = {!setdir};
      break;
    case 10:
      //invalid state, decide what you want to do for safety
      //this is pushing CW and CCW at the same time on motor 2
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 11:
      //invalid state, decide what you want to do for safety
      //this is pushing CW and CCW at the same time on motor 2, and pushing CW on motor 1
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 12:
      //both move CCW
      stepperActive[0] = 1;
      stepperActive[1] = 1;
      stepperDir[0] = {!setdir};
      stepperDir[1] = {!setdir};
      break;
    case 13:
      //invalid state, decide what you want to do for safety
      //this is pushing CW and CCW at the same time on motor 1, and pushing CCW on motor 2
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 14:
      //invalid state, decide what you want to do for safety
      //this is pushing CW and CCW at the same time on motor 2, and pushing CCW on motor 1
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
    case 15:
      //VERY invalid state, decide what you want to do for safety
      // this is literally just mashing all 4 buttons at the same time
      stepperActive[0] = 0;
      stepperActive[1] = 0;
      break;
  }

  pulseStepper();

}

void pulseStepper(){
  digitalWrite(driverDIR1,stepperDir[0]);
  digitalWrite(driverDIR2,stepperDir[1]);
  
  if (stepperActive[0]==1){
    digitalWrite(driverPUL1,HIGH);
  }
  if (stepperActive[1]==1){
    digitalWrite(driverPUL2,HIGH);
  }
  
  delayMicroseconds(pd);
  
  if (stepperActive[0]==1){
    digitalWrite(driverPUL1,HIGH);
  }
  if (stepperActive[0]==1){
    digitalWrite(driverPUL1,HIGH);
  }

  delayMicroseconds(pd);
}

