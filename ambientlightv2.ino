
int photosensor = A0; // define input pin
int analogValue = 0;

void setup() 
{
    int analogValue = analogRead(photosensor);
}

void loop() 
{

// check to see what the value of the photoresistor or phototransistor is and store it in the int variable analogvalue
    analogValue = analogRead(photosensor);

    // This prints the value to the USB debugging serial port (for optional debugging purposes)
    Serial.printlnf("%d", analogValue);

    delay(100);

  analogValue = analogRead(photosensor);// read the light
  
  //publish the data to thingspeak
  
  String light = String(analogValue);
  Particle.publish("light",light, PRIVATE);
  delay(3000);  // wait for 3000 milliseconds
} 