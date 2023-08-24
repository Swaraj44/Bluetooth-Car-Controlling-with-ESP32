// --------------------------------------------------
//
// Code for control of ESP32 through App 
// device used for tests: ESP32-WROOM-32
// 
// App on phone has five buttons:
// Button 1: 11 for ON and 10 for OFF
// Button 2: 21 for ON and 20 for OFF
// Button 3: 31 for ON and 30 for OFF
// Button 4: 41 for ON and 40 for OFF
// Button 5: 50 for ON and OFF
//
// Written by Swaraj(update: 24.08.2023)
//
// --------------------------------------------------

// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h" 

// init Class:
BluetoothSerial ESP_BT; 

// init PINs: assign any pin on ESP32
//int led_pin_1 = 4;
//int led_pin_2 = 0;
//int led_pin_3 = 2;    
//int led_pin_4 = 15;





const int ENA = 12;  // Enable pin for Motor 1
const int IN1 = 13;  // Input 1 for Motor 1
const int IN2 = 14;  // Input 2 for Motor 1

const int ENB = 15;  // Enable pin for Motor 2
const int IN3 = 16;  // Input 1 for Motor 2
const int IN4 = 17;  // Input 2 for Motor 2

// Parameters for Bluetooth interface
int incoming;

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control"); //Name of your Bluetooth interface -> will show up on your phone

 // pinMode (led_pin_1, OUTPUT);
 // pinMode (led_pin_2, OUTPUT);
  //pinMode (led_pin_3, OUTPUT);
 // pinMode (led_pin_4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);




  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // motor speeds (0-255)
  analogWrite(ENA, 250); //  value to control motor 1 speed
  analogWrite(ENB, 250); //  value to control motor 2 speed

}

void loop() {
  
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); //Read what we receive 

    // separate button ID from button value -> button ID is 10, 20, 30,40,50 etc, value is 1 or 0
    int button = floor(incoming / 10);
    int value = incoming % 10;
    
    switch (button) {
      case 1:  
        Serial.print("Button 1:"); Serial.println(incoming);
        //digitalWrite(led_pin_1, value);
        if(IN1==LOW && IN2==HIGH){

          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          delay(20);

          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);

        }
        else{

                  digitalWrite(IN1, HIGH);
                  digitalWrite(IN2, LOW);

        }

        if(incoming==10){
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            delay(20);
        }
                
  

        break;




      case 2:  
        Serial.print("Button 2:"); Serial.println(incoming);
        //digitalWrite(led_pin_2, value);



        if(IN3==LOW && IN4==HIGH){

          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          delay(20);

          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);

        }
        else{

                  digitalWrite(IN3, HIGH);
                  digitalWrite(IN4, LOW);

        }

        if(incoming==20){
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            delay(20);
        }

        break;




      case 3:  
        Serial.print("Button 3:"); Serial.println(incoming);

            if(IN1==HIGH && IN2==LOW){

          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          delay(20);

          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);

        }
        else{

                  digitalWrite(IN1, LOW);
                  digitalWrite(IN2, HIGH);


        }

        if(incoming==30){
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            delay(20);
        }



        break;
      case 4:  
        Serial.print("Button 4:"); Serial.println(incoming);
        //digitalWrite(led_pin_4, value);


        if(IN3==HIGH && IN4==LOW){

          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          delay(20);

          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);

        }
        else{
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);

        }

        if(incoming==40){
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            delay(20);
        }

        

        break;



      case 5:  
        Serial.print("Button 5:"); Serial.println(incoming);
        //digitalWrite(led_pin_4, value);

            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            delay(20);

       break;

    }
  }
}