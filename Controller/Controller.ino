#include <TimerOne.h>
#include "TM1637.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ezButton.h>
#include <EEPROM.h>
#include <ezBuzzer.h>

#include <DHT.h>
#define DHTPIN 7     
#define DHTTYPE DHT11   // DHT11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz 

#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//FOR TEMP DISPLAY
#define CLK 2
#define DIO 3

//FOR HUMIDITY DISPAY
#define CLK1 A5
#define DIO1 A4

TM1637 tm1637(CLK,DIO);
TM1637 tm1(CLK1,DIO1);

/*==============Turning variables ==================*/
int turnUp  = 6;
int turnDown =  12; 

int turning_friency = EEPROM.read(26);
int turning_Period = EEPROM.read(28);
int turning_interval_InSec = turning_Period * 1000;

unsigned long timeInterval = turning_friency * 60000;
unsigned long timeInterval2 = timeInterval - 2000;
unsigned long time_from_start_Up = 0;
unsigned long time_from_start_Down = 0;
unsigned long millis_Count;

unsigned long turning_Interval = timeInterval + turning_interval_InSec;
unsigned long interval_count = 0;

int upState = 0;
int DownState = 0;

int turn_state = EEPROM.read(33);

/*-----------------------------------------------------------------------*/

int setRed = A0;
int menu = 0;
const int exhause = 9;

        
 float uhumidity = EEPROM.read(1);
 float lHumidity = EEPROM.read(5);

/*-----------Manual turning variables*------------*/
 unsigned long millis_time;
 unsigned long millis_interval = 300;
 unsigned long millis_from_start = 0;


bool state = true;
const long newState = millis();
const long interval = 300;
const long interval2 = 500;
int buttonPushCounter0 = EEPROM.read(1); // counter for the number of button presses for base Humidity
int buttonPushCounter1 =  EEPROM.read(5);//counter for the number of button presses for under Humidity


 int buzzState = EEPROM.read(32);
/*--------------------buttons variables-------------------*/
ezButton buttonSet(A1);  
ezButton buttonUp(A2);  
ezButton buttonDown(A3);
ezButton buttonOk(4);

void setup() {
  noInterrupts();
      CLKPR = 0x80;                           /*Enabling the clock prescaler function*/
      CLKPR = 0x00;                           /*Setting the prescaler to div by 1*/
      interrupts();

  EEPROM.update(32, 0);
  EEPROM.update(35, 0);
      
  pinMode(13,OUTPUT);
  pinMode(setRed,OUTPUT);
  pinMode(10,OUTPUT); //Heater
  pinMode(5,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(exhause,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(4,INPUT_PULLUP);
  millis();

  digitalWrite(exhause,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);

  tm1637.set();
  tm1637.init();

  tm1.set();
  tm1.init();

  dht.begin();
  sensors.begin();
  //Serial.begin(9600);
 
  buttonSet.setDebounceTime(2000); // set debounce time to 50 milliseconds
  buttonUp.setDebounceTime(60); // set debounce time to 50 milliseconds
  buttonDown.setDebounceTime(60); // set debounce time to 50 milliseconds
  buttonOk.setDebounceTime(100); // set debounce time to 50 milliseconds

  pinMode(turnUp,OUTPUT);
  pinMode(turnDown, OUTPUT);

  int m = EEPROM.read(33);

  if(m == 0){
    EEPROM.update(33,1);
    }

    if(m == 1){
    EEPROM.update(33,0);
    }



}

void loop() {       
        settings();          // Settings function
        change_Turn_State(); // Changing state of turner
        relayTemp();         // Temperature relay
        relayExhause();      // Exhause relay
        humidfier();         // Humidifier relay
        readH();             // reading Humidity
         

}

 float readH(){
     float readHH = dht.readHumidity();
     return readHH;
  }

  void humidfier(){

            float hData = readH();
           
             if(hData >=  uhumidity){ //UPPER humidity 
             digitalWrite(11,LOW);
           }
           
          if( hData <= lHumidity + 1){ //LOWER humidity 
            digitalWrite(11, HIGH);

            }
  }

  





  
