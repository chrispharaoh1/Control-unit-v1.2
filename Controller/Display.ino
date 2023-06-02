void displayTemp(int num){ 
   tm1637.display(3, num % 10);   
   tm1637.display(2, num / 10 % 10);   
   tm1637.display(1, num / 100 % 10);   
   tm1637.display(0, num / 1000 % 10);
}

void displayHum(int num){ 
   tm1.display(3, num % 10);   
   tm1.display(2, num / 10 % 10);   
   tm1.display(1, num / 100 % 10);   
   tm1.display(0, num / 1000 % 10);
}
