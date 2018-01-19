#include "Wire.h"
#define Output SerialUSB

void setup()
{
  Wire.begin();
 
  Output.begin(9600);
  while (!Output);             // Leonardo: wait for serial monitor
  Output.println("\nI2C Scanner");
}

void loop()
{
  byte error, address;
  int nDevices;
 
  Output.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Output.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Output.print(address,HEX);
      Output.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Output.print("Unknown error at address 0x");
      if (address<16)
        Output.print("0");
      Output.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Output.println("No I2C devices found\n");
  else
    Output.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan
}
