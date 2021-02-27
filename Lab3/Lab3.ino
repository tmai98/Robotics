const int trigPin = 32;  //This is Port Pin 3.5 on the MSP432 Launchpad
const int echoPin = 33; //This is Port Pin 5.1 on the MSP432 Launchpad 

//constexpr size_t NUM_SAMPLES = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);      
   
  Serial.begin(9600);
  Serial.println("Starting HC-SR04 Test...");  
}

void loop() {
  long samples[5];
  long centimeters;
  long tmp;
  long reading[5];
  
  for (int i = 0; i < 5; ++i) {
    digitalWrite(trigPin, LOW);            // send low to get a clean pulse
    delayMicroseconds(5);                  // let it settle
    digitalWrite(trigPin, HIGH);           // send high to trigger device
    delayMicroseconds(10);                 // let it settle

    samples[i] = pulseIn(echoPin, HIGH);
    centimeters = samples[i] / 58;  
  
    Serial.print("Distance = ");
    Serial.print(centimeters);
    Serial.println(" centimeters");

    reading[i] = centimeters;
    
    delay(1000);
  }
  for(int t=0; t<5; t++){
    for(int j=0; j<5;j++){
      if(reading[j]>reading[t]){
         tmp = reading[t];
        reading[t] = reading[j];
        reading[j] = tmp;
    }
  }
}

  Serial.print("Median distance = ");
  Serial.print(reading[2]);
  Serial.println(" centimeters");
  

  delay(5000);

}
