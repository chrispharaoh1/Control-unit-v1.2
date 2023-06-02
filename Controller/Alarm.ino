  
  void buzzerON(){
  if(EEPROM.read(32) == 0){
    const int onDuration = 400;
    int timeDuraion = 100;
    unsigned long lastPeriodStart;

    if(millis()- lastPeriodStart >= timeDuraion){
        timeDuraion += timeDuraion;
        tone(5,2500,onDuration);
      }

     if(buttonDown.isPressed()){
          EEPROM.update(32,0);
       }
 
  }

    }

  void buzzerOFF(){
        if(EEPROM.read(32) == 1){
        if(buzzState == 1){
        digitalWrite(5,LOW);
        noTone(5);
      }
        }
    }

 void buzzerControl(){
 

  }
