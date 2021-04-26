 //Doua Yang Lab07
 //Partner: Tien Mai
 //Wall Follower

 #include "SimpleRSLK.h"

 #define WHEELSPEED 19        // Defalt raw pwm speed for motor.
 #define DELAY_MILLI_SECONDS_90DEGR 525  // Milliseconds to approximate 90 degree right turn
 #define DELAY_MILLI_SECONDS_90DEGL 530  // Milliseconds to approximate 90 degree left turn

 const int f_trigPin =32;  //This is Port Pin 3.5 on the MSP432 Launchpad
 const int f_echoPin =33 ; //This is Port Pin 5.1 on the MSP432 Launchpad
 const int r_trigPin =37;  //This is Port Pin 5.6 on the MSP432 Launchpad
 const int r_echoPin =17 ; //This is Port Pin 5.7 on the MSP432 Launchpad
 const int l_trigPin =18;
 const int l_echoPin =38;
 long rduration;
 int rdistance;
 long fduration;
 int fdistance;
 long lduration;
 int ldistance;


void setup() {

  pinMode(f_trigPin, OUTPUT);
  pinMode(f_echoPin, INPUT);
  pinMode(r_trigPin, OUTPUT);
  pinMode(r_echoPin, INPUT);
  pinMode(l_trigPin, OUTPUT);
  pinMode(l_echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Starting HC-SR04 Test...");

  //Serial.begin(9600);
  setupRSLK();                // Set up all of the pins & functions needed to

}

void loop()
{
  delayMicroseconds(10);
  digitalWrite(r_trigPin, LOW);  // send low to get a clean pulse
  //delayMicroseconds(5);          // let it settle
  digitalWrite(r_trigPin,HIGH);  // send high to left trigger device
  //delayMicroseconds(5);         // let it settle
  digitalWrite(r_trigPin,LOW);
  rduration = pulseIn(r_echoPin, HIGH);
  rdistance = (rduration/2)/29.1;
  Serial.print("distance r: ");
  Serial.println(rdistance);
  

  digitalWrite(f_trigPin, LOW);  // send low to get a clean pulse
  //delayMicroseconds(10);          // let it settle
  digitalWrite(f_trigPin,HIGH); // send high to front trigger device
  //delayMicroseconds(10);         // let it settle
  digitalWrite(f_trigPin,LOW);
  fduration = pulseIn(f_echoPin, HIGH);
  fdistance = (fduration/2)/29.1;
  Serial.print("distance f: ");
  Serial.println(fdistance);
  
  digitalWrite(l_trigPin, LOW);  // send low to get a clean pulse
  //delayMicroseconds(10);          // let it settle
  digitalWrite(l_trigPin,HIGH); // send high to front trigger device
  //delayMicroseconds(10);         // let it settle
  digitalWrite(l_trigPin,LOW);
  lduration = pulseIn(l_echoPin, HIGH);
  ldistance = (lduration/2)/29.1;
  Serial.print("distance l: ");
  Serial.println(ldistance);

   //setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD); // Cause the robot to drive forward
   enableMotor(BOTH_MOTORS); 

  uint16_t normalSpeed = 15; //set normal speed
  uint16_t fastSpeed = 16; //set faster speed

  if(rdistance > 15){
     
    setMotorSpeed(LEFT_MOTOR,normalSpeed);
    setMotorSpeed(RIGHT_MOTOR,fastSpeed);
  }
   else if(rdistance < 15){ 
  
    setMotorSpeed(LEFT_MOTOR,fastSpeed);
    setMotorSpeed(RIGHT_MOTOR,normalSpeed);
  }
}
  
/*
   if (rdistance <150 && fdistance > 150) //drive straight when left wall is detect
 {
  drivestraight();
  //delayMicroseconds(100000);
  
 }
 else if (rdistance > 150 && fdistance > 150 && ldistance < 150) //turn right when front and left wall is detect
 {
  drivestraight1();
  turnright();
  delayMicroseconds(100000);
  drivestraight2();
  while(1){}
 }

 else if (rdistance > 150 && fdistance > 150 && ldistance > 150) //turn left when front and left wall is not detect
 {
  drivestraight();
  //turnleft();
  //drivestraight();
  
 }

  else if (rdistance < 150 && fdistance < 150 && ldistance < 150){

  drivestraight();  

 }

 else
 {
  if(rdistance < 5){
  drivestraight3();
  }
  else if(rdistance > 5){
  drivestraight4();
  }
  else{
    drivestraight();
  }
 drivestraight1(); //loop repeat again when left wall is detected

 }
}

*/

void drivestraight4()
{
 uint16_t normalSpeed = 16; //set normal speed
 uint16_t fastSpeed = 15; //set faster speed


 // === DRIVE Straight ==========================

   setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD); // Cause the robot to drive forward
   enableMotor(BOTH_MOTORS);                         // "Turn on" the motor
   setMotorSpeed(LEFT_MOTOR,normalSpeed);            // Set left motor speed normal
   setMotorSpeed(RIGHT_MOTOR,fastSpeed);             // set right motor speed faster
   delay(5500);           //This should take it to X amount of distance until ultrasonic detect wall
   //disableMotor(BOTH_MOTORS);  //halt motor
}
void drivestraight3()
{
 uint16_t normalSpeed = 15; //set normal speed
 uint16_t fastSpeed = 16; //set faster speed


 // === DRIVE Straight ==========================

   setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD); // Cause the robot to drive forward
   enableMotor(BOTH_MOTORS);                         // "Turn on" the motor
   setMotorSpeed(LEFT_MOTOR,normalSpeed);            // Set left motor speed normal
   setMotorSpeed(RIGHT_MOTOR,fastSpeed);             // set right motor speed faster
   delay(5500);           //This should take it to X amount of distance until ultrasonic detect wall
   //disableMotor(BOTH_MOTORS);  //halt motor
}

void drivestraight1()
{
 uint16_t normalSpeed = 16.5; //set normal speed
 uint16_t fastSpeed = 15; //set faster speed


 // === DRIVE Straight ==========================

   setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD); // Cause the robot to drive forward
   enableMotor(BOTH_MOTORS);                         // "Turn on" the motor
   setMotorSpeed(LEFT_MOTOR,normalSpeed);            // Set left motor speed normal
   setMotorSpeed(RIGHT_MOTOR,fastSpeed);             // set right motor speed faster
   delay(5500);           //This should take it to X amount of distance until ultrasonic detect wall
   //disableMotor(BOTH_MOTORS);  //halt motor

  
  

}
void drivestraight2()
{
 uint16_t normalSpeed = 16.5; //set normal speed
 uint16_t fastSpeed = 15; //set faster speed


 // === DRIVE Straight ==========================

   setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD); // Cause the robot to drive forward
   enableMotor(BOTH_MOTORS);                         // "Turn on" the motor
   setMotorSpeed(LEFT_MOTOR,normalSpeed);            // Set left motor speed normal
   setMotorSpeed(RIGHT_MOTOR,fastSpeed);             // set right motor speed faster
   delay(19500);           //This should take it to X amount of distance until ultrasonic detect wall
   //disableMotor(BOTH_MOTORS);  //halt motor


  return;

}



void drivestraight()
{
 uint16_t normalSpeed = 15; //set normal speed
 uint16_t fastSpeed = 16; //set faster speed


 // === DRIVE Straight ==========================

   setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD); // Cause the robot to drive forward
   enableMotor(BOTH_MOTORS);                      // "Turn on" the motor
   setMotorSpeed(LEFT_MOTOR,normalSpeed);            // Set left motor speed normal
   setMotorSpeed(RIGHT_MOTOR,fastSpeed);             // set right motor speed faster
   delay(1100);           //This should take it to X amount of distance until ultrasonic detect wall
   //disableMotor(BOTH_MOTORS);  //halt motor


  return;

}

void turnright()
{
  // === DRIVE 90 degree turn CW ================
  setMotorDirection(RIGHT_MOTOR,MOTOR_DIR_BACKWARD);  // Cause the robot to drive 90 degrees CW
  setMotorDirection(LEFT_MOTOR,MOTOR_DIR_FORWARD);  //   by setting the L motor and R motor CCW
  enableMotor(BOTH_MOTORS);                          // "Turn on" the motor
  setMotorSpeed(BOTH_MOTORS,WHEELSPEED);             // Set motor speed
  delay(DELAY_MILLI_SECONDS_90DEGR);
  disableMotor(BOTH_MOTORS);                         // Halt motors
 return;
}

void turnleft()
{
 // === DRIVE 90 degree turn CCW ================
  setMotorDirection(RIGHT_MOTOR ,MOTOR_DIR_FORWARD);  // Cause the robot to drive 90 degrees CCW
  setMotorDirection(LEFT_MOTOR,MOTOR_DIR_BACKWARD);  //   by setting the L motor and R motor CW
  enableMotor(BOTH_MOTORS);                          // "Turn on" the motor
  setMotorSpeed(BOTH_MOTORS,WHEELSPEED);             // Set motor speed
  delay(DELAY_MILLI_SECONDS_90DEGL);
  disableMotor(BOTH_MOTORS);                         // Halt motors
 return;
}
