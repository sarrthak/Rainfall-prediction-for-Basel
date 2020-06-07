#include <Servo.h>
Servo servo1, servo2,servo3;
int angle = 10;
#include <SoftwareSerial.h>                           //we have to include the SoftwareSerial library, or else we can't use it
#define rx 2                                          //define what pin rx is going to be
#define tx 3  
void setup() {
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo1.write(angle);
  servo2.write(angle);servo3.write(angle);
   Serial.begin(9600);                                
  myserial.begin(9600);                              
  inputstring.reserve(10);                            
  sensorstring.reserve(30);  
}

void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC
}

void loop()
{ if (input_string_complete == true) {                //if a string from the PC has been received in its entirety
    myserial.print(inputstring);                      //send that string to the Atlas Scientific product
    myserial.print('\r');                             //add a <CR> to the end of the string
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }

  if (myserial.available() > 0) {                     //if we see that the Atlas Scientific product has sent a character
    char inchar = (char)myserial.read();              //get the char we just received
    sensorstring += inchar;                           //add the char to the var called sensorstring
    if (inchar == '\r') {                             //if the incoming character is a <CR>
      sensor_string_complete = true;                  //set the flag
    }
  }
double pH=sensor_string;
if(pH>3&&pH<7)
 {// scan from 0 to 180 degrees
  for(angle = 10; angle < 45; angle++)  
  {                                  
    servo.write(angle);              
    delay(15);                  
  }
  // now scan back from 180 to 0 degrees
  for(angle = 45; angle > 10; angle--)    
  {                                
    servo.write(angle);          
    delay(15);      
  }
  }
  else if (pH==7)
   {// scan from 0 to 180 degrees
  for(angle = 10; angle < 90; angle++)  
  {                                  
    servo2.write(angle);              
    delay(15);                  
  }
  // now scan back from 180 to 0 degrees
  for(angle = 90; angle > 10; angle--)    
  {                                
    servo2.write(angle);          
    delay(15);      
  }
  }
  else if(pH>7)
  {
    {// scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo4.write(angle);              
    delay(15);                  
  }
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--)    
  {                                
    servo3.write(angle);          
    delay(15);      
  }
  }
  }
   
}