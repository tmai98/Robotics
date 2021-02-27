
#define LED RED_LED
#define LED GREEN_LED
#define LED BLUE_LED


void setup() {
  pinMode(LED, OUTPUT);

}

void loop() {
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  ///////////////////////////////////////////////////////
  digitalWrite(BLUE_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(BLUE_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  //////////////////////////////////////////////////////////
  digitalWrite(GREEN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(GREEN_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  //////////////////////////////////////////////////////////
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BLUE_LED, HIGH);
  delay(500);               // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(BLUE_LED, LOW);
  delay(500); 
    //////////////////////////////////////////////////////////
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(GREEN_LED, HIGH);
  delay(500);               // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(GREEN_LED, LOW);
  delay(500); 
    //////////////////////////////////////////////////////////
  digitalWrite(BLUE_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(GREEN_LED, HIGH);
  delay(500);               // wait for a second
  digitalWrite(BLUE_LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(GREEN_LED, LOW);
  delay(500); 
      //////////////////////////////////////////////////////////
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(GREEN_LED, HIGH);
  delay(500);               // wait for a second
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(GREEN_LED, LOW);
  delay(500);
}
