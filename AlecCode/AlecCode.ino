// Alec's 2 motor, 2 button program!--- 


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
boolean setdir = LOW; // Set Direction




int switchState = 0; // Variable for reading the switch's status
int switchState2 = 0; // Variable for reading the switch's status 
 
 




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
  //11111read the state of the switch value:
  switchState = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);


  //Check if CC switch is pressed.
  if (switchState == LOW) {
    // Turn Motor on
    pd = map((analogRead(spd)),0,1023,2000,50);
    digitalWrite(driverDIR1,setdir);
    digitalWrite(driverPUL1,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL1,LOW);
    delayMicroseconds(pd);
  }
  else {
     //read the state of the switch value:
  switchState = digitalRead(reversePin1);
    //Check if CW switch is pressed.
  if (switchState == LOW) {
    // Turn Motor on
    pd = map((analogRead(spd)),0,1023,2000,50);
    digitalWrite(driverDIR1,!setdir);
    digitalWrite(driverPUL1,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL1,LOW);
    delayMicroseconds(pd);
  }


    


  //Check if CC switch is pressed.
  if (switchState2 == LOW) {
    // Turn Motor on
    pd = map((analogRead(spd)),0,1023,2000,50);
    digitalWrite(driverDIR2,setdir);
    digitalWrite(driverPUL2,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL2,LOW);
    delayMicroseconds(pd);
  }
  else {
     //read the state of the switch value:
  switchState = digitalRead(reversePin2);
    //Check if CW switch is pressed.
  if (switchState == LOW) {
    // Turn Motor on
    pd = map((analogRead(spd)),0,1023,2000,50);
    digitalWrite(driverDIR2,!setdir);
    digitalWrite(driverPUL2,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL2,LOW);
    delayMicroseconds(pd);
    // Turn motor off.
    digitalWrite(driverDIR2,setdir);
    digitalWrite(driverPUL2,LOW);
    delayMicroseconds(pd);
    digitalWrite(driverPUL2,LOW);
    delayMicroseconds(pd);
    }
}


}
}
