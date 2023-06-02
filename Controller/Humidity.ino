
        
        
        void humidityControl(){
              
         float readH = dht.readHumidity();
         float uhumidity = EEPROM.read(1);
         float lHumidity = EEPROM.read(5);


           if(dht.readHumidity() >=  uhumidity/1){ //UPPER humidity 
            digitalWrite(11,HIGH);
             //Serial.print("HIGHER Humidity ON ");
           }
           
          if( dht.readHumidity() <= (lHumidity/1)+ 1){ //LOWER humidity 
            digitalWrite(11, LOW);
            //erial.print("Lower Humidity ON ");

            }

         }
