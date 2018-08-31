// First we include the libraries for the temperature and display
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <TM1637Display.h>

#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int CLK = 9; //Set the CLK pin connection to the display
const int DIO = 8; //Set the DIO pin connection to the display

int TempC = 0;

TM1637Display display(CLK, DIO);  //set up the 4-Digit Display.

void setup()
{
  display.setBrightness(0x0a);  //set the diplay to maximum brightness
 // start serial port 
 Serial.begin(9600); 
 Serial.println("Dallas Temperature IC Control Library Demo"); 
 // Start up the library 
 sensors.begin(); 
}

void loop(void) 
{ 
 // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
/********************************************************************/
 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.println("DONE"); 
/********************************************************************/
 Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(1000);

   TempC = sensors.getTempCByIndex(0);
   display.showNumberDec(TempC); //Display the Variable value;
    //delay(2);  //A half second delay between steps. 
}




/* TM1637_4_Digit_Display_Basics.ino
The purpose of this sketch is to provide the basic
structure for using the TM1637 based 4-Digit Displays
like the Grove 4 digit display or other equivalents
available through the likes of www.dx.com. 

This makes use of the TM1637Display library developed by avishorp.
https://github.com/avishorp/TM1637

This has been developed to run on any Arduino.

Pin assignments are:
CLK - D9
DIO - D8
5V or 3.3V supply to Display
GND to Display

The operation is very simple.  The sketch initialises the display
and then steps through the loop incrementing the value of a
variable which is then displayed on the 4-Digit display.
Essentially it is the most basic function you would want from
such a display.  If you want more sophisticated functionality
then use the example that ships with the library.
*/
