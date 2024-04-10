int redled = 10; 
int greenled = 8;
int blueled = 9;
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(redled, OUTPUT);// set the pin with red LED as “output”
  pinMode(greenled, OUTPUT); // set the pin with yellow LED as “output”
  pinMode(blueled, OUTPUT); // set the pin with green LED as “output”
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
 
   Serial.println(volts);
   delay(10); 

  /*   Calibration was made with white noise and a Digital Sound Level Meter (fast trigger). 
        0.3v = 50 dBa 
        0.7v = 65 dBa
        3.0v = 85 dBa
        3.3v = 90 dBa
        Those are starting values, you may need to calibrate your electret microphone.
  */
       {
      if (volts < 1.0) {
       digitalWrite(blueled, HIGH);     // When noise level is low.
      }
      else {
        digitalWrite(blueled, LOW);
      }
      if (volts > 1.0 && volts < 3) {
        digitalWrite(greenled, HIGH);   // When noise level is acceptable.
      }
      else {
        digitalWrite(greenled, LOW);
        
      }
      if (volts >= 3.0) {
        digitalWrite(redled, HIGH);     // When ear protection is needed. 
        
      }
      else {
        digitalWrite(redled, LOW);
      }
   
    }
}
