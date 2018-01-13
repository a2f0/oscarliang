#include <Wire.h>

#define SLAVE_ADDRESS 0x04
#define DEBUG false 
#define Output SerialUSB

int number = 0;
int state = 0;

void debugln(String s) {
  if (DEBUG == true) {
    Output.println(s);
  }
}

void debug(String s) {
  if (DEBUG == true) {
    Output.print(s);
  }
}

void setup() {
  //if DEBUG is set to true a serial monitor MUST be connected or the execution
  //will be blocked 
  if (DEBUG == true) { 
    Output.begin(9600); // start serial for output
    while (!Output);    // Wait for Serial monitor to open
    debugln("Finished initializing serial");
  }
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}

void loop() {
  delay(100);
}

// callback for received data
void receiveData(int byteCount) {

}

// callback for sending data
void sendData(){
  Wire.write("Multibyte");
}
