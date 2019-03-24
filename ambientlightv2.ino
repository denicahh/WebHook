
int photosensor = A0; // define input pin
int analogValue = 0;

void setup() 
{
    int analogValue = analogRead(photosensor);
}

void loop() 
{

    analogValue = analogRead(photosensor);// read the light
    
    // This prints the value to the USB debugging serial port (for optional debugging purposes)
    Serial.printlnf("%d", analogValue);

    delay(100);

  //publish the data to thingspeak
  
  String light = String(analogValue);
  Particle.publish("light",light, PRIVATE);
  delay(3000);  // wait for 3000 milliseconds
} 