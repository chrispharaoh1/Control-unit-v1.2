

void settings(){
  
  buttonSet.loop(); 
  buttonUp.loop(); 
  buttonDown.loop(); 
  buttonOk.loop(); 
 
  float overTemp = EEPROMRead(17);
  float underTemp = EEPROMRead(20);
  int lowerHumidity = EEPROMRead(23);

  int buttonPushCounter2 =  EEPROMReadHumidity(8);//counter for the number of button presses for base Temperature
  int buttonPushCounter3 =  EEPROMReadHumidity(11);//counter for the number of button presses for lower Temperature
  int buttonPushCounter4 =  EEPROMReadHumidity(14);//counter for the number of button presses for lower exhause fan
  int buttonPushCounter5 =  EEPROMReadHumidity(17);//counter for the number of button presses for over Temperature alarm
  int buttonPushCounter6 =  EEPROMReadHumidity(20);//counter for the number of button presses for over Temperature alarm
  int buttonPushCounter7 =  EEPROMReadHumidity(23);//counter for the number of button presses for lowe humidity alarm
  int buttonPushCounter8 =  EEPROMReadHumidity(26);//counter for the number of button presses for Turning friquency
  int buttonPushCounter9 =  EEPROMReadHumidity(28);//counter for the number of button presses for Turning duration

  int old = 100;
  int current = millis();
  int state = 0;

  if(buttonSet.isPressed() ){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    
      menu = 1;

    }

    /*------- SWITCH CASES---------*/
    
    switch (menu){
      /*===========CASE NUMBER 1============*/
          case 1:  //F1-----Base temperature
           displayTemp(EEPROMReadHumidity(8)*10);
           tm1.display(0,15);
           tm1.display(1,1);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);
           noTone(5);

            if(EEPROMReadHumidity(8)== 255 || EEPROMReadHumidity(8)== 0){
              EEPROMWriteHumidity(8, 378);
            }

             if(buttonUp.isPressed()&& buttonPushCounter2 < 400){
              buttonPushCounter2++;
              EEPROMWriteHumidity(8, buttonPushCounter2);
              //Serial.print(EEPROMReadHumidity(8));

            }
             if(buttonDown.isPressed()&& buttonPushCounter2 > 300){
              buttonPushCounter2--;
              EEPROMWriteHumidity(8, buttonPushCounter2);
              //Serial.print(EEPROMReadHumidity(8));
            }

          
          if(buttonOk.isPressed() ){
             menu = 2;         
          }
          break;
          
       

         /*===========CASE NUMBER 3============*/
          case 2:  //F2-----temerature lower limit
           displayTemp(EEPROMReadHumidity(11)*10);
           tm1.display(0,15);
           tm1.display(1,2);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

            if(EEPROMReadHumidity(11)== 255 || EEPROMReadHumidity(11)== 0){
              EEPROMWriteHumidity(11, 375);
            }

             if(buttonUp.isPressed()&& buttonPushCounter3 < EEPROMReadHumidity(8)-1){
              buttonPushCounter3++;
              EEPROMWriteHumidity(11, buttonPushCounter3);
              //Serial.print(EEPROMReadHumidity(11));

            }
             if(buttonDown.isPressed()&& buttonPushCounter3 > 300){
              buttonPushCounter3--;
              EEPROMWriteHumidity(11, buttonPushCounter3);
              //Serial.print(EEPROMReadHumidity(11));
            }


          if(buttonOk.isPressed() ){
           menu = 3;         
          }
          break;

         /*===========CASE NUMBER 3============*/
          case 3:  //F3-----Over heat alarm
           displayTemp(EEPROMReadHumidity(14)*10);
           tm1.display(0,15);
           tm1.display(1,3);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

           if(EEPROMReadHumidity(14)== 255 || EEPROMReadHumidity(14)== 0){
              EEPROMWriteHumidity(14, 380);
            }

             if(buttonUp.isPressed()&& buttonPushCounter4 < 400){
              buttonPushCounter4++;
              EEPROMWriteHumidity(14, buttonPushCounter4);
              //Serial.print(EEPROMReadHumidity(14));

            }
             if(buttonDown.isPressed()&& buttonPushCounter4 > EEPROMReadHumidity(8)+1){
              buttonPushCounter4--;
              EEPROMWriteHumidity(14, buttonPushCounter4);
              //Serial.print(EEPROMReadHumidity(14));
            }

          if(buttonOk.isPressed() ){
             menu = 4;         
       }
          break;

        /*===========CASE NUMBER 4============*/
          case 4:  //F4-----)over temerature alarm
          displayTemp(EEPROMReadHumidity(17)*10);
           tm1.display(0,15);
           tm1.display(1,4);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

             if(EEPROMReadHumidity(17)== 255 || EEPROMReadHumidity(17)== 0){
              EEPROMWriteHumidity(17, 382);
            }

             if(buttonUp.isPressed()&& buttonPushCounter5 < 390){
              buttonPushCounter5++;
              EEPROMWriteHumidity(17, buttonPushCounter5);
              //Serial.print(EEPROMReadHumidity(17));

            }
             if(buttonDown.isPressed()&& buttonPushCounter5 > EEPROMReadHumidity(14)+1){
              buttonPushCounter5--;
              EEPROMWriteHumidity(17, buttonPushCounter5);
              //Serial.print(EEPROMReadHumidity(17));
            }

          if(buttonOk.isPressed() ){
             menu = 5;         
          }
          break;

         /*===========CASE NUMBER 5============*/
          case 5: //F5-----Under temperature alarm
           displayTemp(EEPROMReadHumidity(20)*10);
           tm1.display(0,15);
           tm1.display(1,5);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

            if(EEPROMReadHumidity(20)== 255 || EEPROMReadHumidity(20)== 0){
              EEPROMWriteHumidity(20, 370);
            }

             if(buttonUp.isPressed()&& buttonPushCounter6 < EEPROMReadHumidity(11)-1){
              buttonPushCounter6++;
              EEPROMWriteHumidity(20, buttonPushCounter6);
              //Serial.print(EEPROMReadHumidity(20));

            }
             if(buttonDown.isPressed()){
              buttonPushCounter6--;
              EEPROMWriteHumidity(20, buttonPushCounter6);
              //Serial.print(EEPROMReadHumidity(20));
            }

          if(buttonOk.isPressed() ){
          menu = 6;         
          }
          break;

     /*===========CASE NUMBER 6===37152824605=========*/
          case 6:  //E1-----Base humidity
           displayTemp(EEPROMReadHumidity(1)*100);
           tm1.display(0,14);
           tm1.display(1,1);
           
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

           if(EEPROMReadHumidity(1)== 255 || EEPROMReadHumidity(1)== 0){
              EEPROMWriteHumidity(1, 60);
            }
           if(buttonUp.isPressed() && EEPROMReadHumidity(1) <90){
             buttonPushCounter0++;
             EEPROMWriteHumidity(1, buttonPushCounter0);
            // Serial.print(buttonPushCounter0);
            }
            if(buttonDown.isPressed() && EEPROMReadHumidity(1) > 40){
              buttonPushCounter0--;
              EEPROMWriteHumidity(1, buttonPushCounter0);
            }
 
          if(buttonOk.isPressed() ){
             menu = 7;         
          }
          break;

         /*===========CASE NUMBER 7============*/
           case 7: //E2-----Under humidity alarm
           displayTemp(EEPROMReadHumidity(5)*100);
           tm1.display(0,14);
           tm1.display(1,2);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

            if(EEPROMReadHumidity(5)== 255 || EEPROMReadHumidity(5)== 0 ){
              EEPROMWriteHumidity(5, 50);
            }
           if(buttonUp.isPressed() && buttonPushCounter1 < EEPROMReadHumidity(1) - 2){
             buttonPushCounter1++;
             EEPROMWriteHumidity(5, buttonPushCounter1);
             //Serial.print(buttonPushCounter1);

            }
            if(buttonDown.isPressed() && buttonPushCounter1 > 39){
              buttonPushCounter1--;
              EEPROMWriteHumidity(5, buttonPushCounter1);
            }
           
          if(buttonOk.isPressed() ){
          menu = 8;         
       }
          break;


      /*===========CASE NUMBER 9============*/
          case 8:  //E3-----Under Humidity alarm
           displayTemp(EEPROM.read(23)*100); 
           tm1.display(0,14);
           tm1.display(1,3);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

           
            if(EEPROMReadHumidity(23)>= 255 || EEPROMReadHumidity(23)== 0 ){
              EEPROMWriteHumidity(23, 50);
            }
           if(buttonUp.isPressed() && buttonPushCounter7 < EEPROM.read(5) - 1){
             buttonPushCounter7++;
             EEPROM.update(23, buttonPushCounter7);
             //Serial.print(buttonPushCounter7);

            }
            if(buttonDown.isPressed() && buttonPushCounter7 > 20){
              buttonPushCounter7--;
              EEPROMWriteHumidity(23, buttonPushCounter7);
              //Serial.print(buttonPushCounter7);
            } else {buttonPushCounter7 = 20;}

          if(buttonOk.isPressed() ){
             menu = 9;         
       }
          break;

     /*===========CASE NUMBER 9============*/
          case 9:  //C1-----Turning friequency
           displayTemp(EEPROMReadHumidity(26)*100);
           tm1.display(0,12);
           tm1.display(1,1);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

          if(EEPROMReadHumidity(26)== 255 || EEPROMReadHumidity(26)== 0 ){
              EEPROMWriteHumidity(26, 1);
            }
           if(buttonUp.isPressed() && buttonPushCounter8 < 100){
             buttonPushCounter8++;
             EEPROMWriteHumidity(26, buttonPushCounter8);
             //Serial.print(buttonPushCounter8);

            }
            if(buttonDown.isPressed() && buttonPushCounter8 > 1){
              buttonPushCounter8--;
              EEPROMWriteHumidity(26, buttonPushCounter8);
            }

          if(buttonOk.isPressed() ){
             menu = 10;         
       }
          break; 

        /*===========CASE NUMBER 4============*/
          case 10:  //10-----Over heat alarm
           displayTemp(EEPROMReadHumidity(28)*10);
           tm1.display(0,12);
           tm1.display(1,2);
           digitalWrite(setRed,HIGH);
           digitalWrite(13,LOW);
           digitalWrite(5, LOW);

           if(EEPROMReadHumidity(28)== 255 || EEPROMReadHumidity(28)== 0 ){
              EEPROMWriteHumidity(28, 15);
            }
           if(buttonUp.isPressed() && buttonPushCounter9 < 300){
             buttonPushCounter9++;
             EEPROMWriteHumidity(28, buttonPushCounter9);
             //Serial.print(buttonPushCounter9);

            }
            if(buttonDown.isPressed() && buttonPushCounter9 > 5){
              buttonPushCounter9--;
              EEPROMWriteHumidity(28, buttonPushCounter9);
            }

          if(buttonOk.isPressed() ){
             menu = 0;         
       }
          break;        


       /*=========== DEFAULT CASE=============*/
          default :
        int m = EEPROM.read(33);
        unsigned long currentTime = millis();
        const unsigned long interval = 1000;
        unsigned long previousTime = 0;

           if(m == 0 and digitalRead(A2)== HIGH and digitalRead(4)== HIGH){   
                turningDown();
                digitalWrite(turnUp,LOW);
            }
    
           if(m == 1 and digitalRead(4)== HIGH and digitalRead(A2)== HIGH){
               turningUp();
               digitalWrite(turnDown,LOW);
           }
    
          menu = 0;
          if(menu == 0){
          digitalWrite(13,HIGH);
          digitalWrite(A0,LOW); 
          } 

          if(currentTime - previousTime >= interval){
             sensors.requestTemperatures();

              
            previousTime = currentTime;
            
            }  
          
            if(sensors.getTempCByIndex(0) == DEVICE_DISCONNECTED_C){
              displayTemp(0000);
              analogWrite(10,0);
            }else{
              displayTemp(sensors.getTempCByIndex(0)*100);
              }

          displayHum(dht.readHumidity()*100);
          redBlink();

     
           float getTempp = sensors.getTempCByIndex(0);
           int readHumid = dht.readHumidity();
          
          if( getTempp >= overTemp/10 || getTempp <= underTemp/10 || readHumid <= lowerHumidity && buzzState == 0){
     
              
                buzzerON();    


            
           } else{buzzerOFF();}


          buzzerControl();
         // turn_down();
         // turn_up();
  

      // Up and Down Button for default settings
       if( digitalRead(A2) == 0 && digitalRead(A3) == 0){
           digitalWrite(A0,HIGH);
           EEPROMWriteHumidity(8, 378);  //Upper limit temperature
           EEPROMWriteHumidity(11, 376); //Lower limit temperature
           EEPROMWriteHumidity(14, 380); //Exhause fan
           EEPROMWriteHumidity(17, 382); //Over temperature alarm
           EEPROMWriteHumidity(20, 374); //Low temperature alarm
           EEPROMWriteHumidity(1, 60);   //Upper limit humidity
           EEPROMWriteHumidity(5, 56);   //Lower limit humidity
           EEPROMWriteHumidity(23, 45);  //Low humidity alarm
           EEPROMWriteHumidity(26, 90);  //Turning friquency in minutes
           EEPROMWriteHumidity(28,90);   //Turning duration in seconds
           EEPROMWriteHumidity(33,0);    //Turning state
           EEPROMWriteHumidity(32,0);    //Alarm state


         }  else{
             digitalWrite(A0,LOW);
            }



           if(digitalRead(A3) == 0 && EEPROM.read(32) == 0){
              EEPROMWriteHumidity(32, 1);
                    
             }


          /*-------------------Turning up-------------------------*/
          if(digitalRead(4) == LOW){
                if(upState == 0) upState = 1;  
                digitalWrite(turnUp, upState);
                digitalWrite(turnDown,0);
             } 

//        /*----------------------------------------------------------*/
       if( digitalRead(A2) == LOW){
  
             if(DownState == 0) DownState = 1; 
               digitalWrite(turnDown, DownState);
               digitalWrite(turnUp, 0);
                    
        } 
         
          break;
        
      }
  
  }

/*============FUNCTIONS FOR UPDATING AND READING HUMIDITY REFERENCES=========*/
void EEPROMWriteHumidity(int address, int value)
  {
     byte two = (value & 0xFF);
     byte one = ((value >> 8) & 0xFF);

     EEPROM.update(address, two);
     EEPROM.update(address + 1, one);
  }
  
int EEPROMReadHumidity(int address)
  {
    long two = EEPROM.read(address);
    long one = EEPROM.read(address + 1);
    return ((two << 0) & 0xFFFFFF) + ((one << 8) & 0xFFFFFFFF);
  }


 //================HEATER RELAY================
    void relayTemp(){
        unsigned long currentTime = millis();
        const unsigned long interval = 1000;
        unsigned long previousTime = 0;
      
        float lowerTemp = EEPROMReadHumidity(11);
        float upperTemp = EEPROMReadHumidity(8);

        if (currentTime - previousTime >= interval){
          
           float temprature = sensors.getTempCByIndex(0);

           if(temprature >= upperTemp/10 ){ //uper temperature limit
            analogWrite(10,0);
            //Serial.print(upperTemp/10);
            }
            
         if(temprature <= lowerTemp /10){ // lower temerature limit
            analogWrite(10,255);
            
          } 
 
          previousTime = currentTime;
          }
          
      }

      void relayExhause(){

        unsigned long currentTime = millis();
        const unsigned long interval = 1000;
        unsigned long previousTime = 0;
        
        float exh = EEPROMReadHumidity(14);
            

         if (currentTime - previousTime >= interval){
          
           float temprature = sensors.getTempCByIndex(0);
            
 

          if( temprature >= exh/10){ // EXHAUSE ..........
            analogWrite(exhause,255);
           }
           else{
             analogWrite(exhause,0);
            }

          previousTime = currentTime;
          }

            
        }


   int EEPROMRead(int address)
  {
    long two = EEPROM.read(address);
    long one = EEPROM.read(address + 1);
    return ((two << 0) & 0xFFFFFF) + ((one << 8) & 0xFFFFFFFF);
  }



/*===========================================================*/
/*====================TURNING PROGRAM=======================================*/
  
/*----------Function for turning up--------------*/

void turningUp(){
  int m = EEPROM.read(33);
  millis_Count = millis();


  if(millis_Count - time_from_start_Up > timeInterval){
    time_from_start_Up = millis_Count;
    int onTime = time_from_start_Up + turning_interval_InSec;

      if(millis_Count <= onTime){
        digitalWrite(turnUp,1);
        digitalWrite(turnDown,0);
       }   else {
        digitalWrite(turnUp,0);
        }         

      } else { 
        digitalWrite(turnUp,0);
        }

    if(millis_Count - time_from_start_Up < timeInterval && millis_Count > time_from_start_Up + turning_interval_InSec ){

               digitalWrite(turnUp,0);

    } else {
      digitalWrite(turnUp,1);
      }

  }

/*----------Function for turning Down--------------*/

  void turningDown(){
    int m = EEPROM.read(33);
    millis_Count = millis();
    

  if(millis_Count - time_from_start_Up > timeInterval  ){
    time_from_start_Up = millis_Count;
    int onTime = time_from_start_Up + turning_interval_InSec;
    

      if(millis_Count < onTime){
          digitalWrite(turnDown,1);
          digitalWrite(turnUp,0);
 
       }     else {
          digitalWrite(turnDown,0);
       }  

    } 

   if(millis_Count - time_from_start_Up < timeInterval && millis_Count > time_from_start_Up + turning_interval_InSec){

               digitalWrite(turnDown,0);

    } else {
      digitalWrite(turnDown,1);
      
      }
   
  
  }
  
/*----------Function for turning state--------------*/

  void change_Turn_State(){
    int m = EEPROM.read(33);
    
      if(millis_Count - time_from_start_Down > timeInterval2){
             
         time_from_start_Down = millis_Count;
         
         if(m == 0) {
            
            EEPROM.update(33,1);
          } else{
            EEPROM.update(33,0);
            }

         if(m == 1) {
            
            EEPROM.update(33,0);
          } else{
            EEPROM.update(33,1);
            }
          
      }
 
    }




  
