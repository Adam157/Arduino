// First we include the libraries for the temperature and display
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <TM1637Display.h>
#include <dht.h>

#define DHT11_PIN 7
#define ONE_WIRE_BUS 2 

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int CLK = 9; //Set the CLK pin connection to the display
const int DIO = 8; //Set the DIO pin connection to the display

TM1637Display display(CLK, DIO);  //set up the 4-Digit Display.
int TempC = 0;
int Humid = 0;
dht DHT;

void setup()
{
 display.setBrightness(0x0a);  //set the diplay to maximum brightness
 Serial.begin(9600); 
 sensors.begin(); 
//  Serial.print("LIBRARY VERSION: ");
//  Serial.println(DHT_LIB_VERSION);
//  Serial.println();
//  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop(void) 
{ 
 // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
/********************************************************************/
// Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
// Serial.println("DONE"); 
int chk = DHT.read11(DHT11_PIN);
int k;
/********************************************************************/
 Serial.print("DB18SB Temp: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
 Serial.print("\tDHT11 Temp: ");
 Serial.print(DHT.temperature, 1);
 Serial.print("\tHumidity: ");
 Serial.print(DHT.humidity, 1);
 Serial.println();
 // Serial.print(",\t");
  //Serial.println(DHT.temperature, 1);

//   delay(1000);
/*  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
*/
   TempC = sensors.getTempCByIndex(0);
   Humid = DHT.humidity;
   
   
   for(k=0; k <= 4; k++) {
	 display.showNumberDecEx(0, (0x80 >> k), true);
   }
   display.showNumberDec(TempC); //Display the Variable value;
   delay(2000);
   display.showNumberDec(Humid);
   delay(2000);
   //delay(750); 
  //  Serial.print("DHT11, \t");
  
  // DISPLAY DATA

}

