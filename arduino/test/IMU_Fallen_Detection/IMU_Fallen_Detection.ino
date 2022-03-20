#include "./IMU.h"

#define PULLUP

#ifdef PULLUP
  #define Pressed  0
  #define Rereased 1
#else
  #define Pressed  1
  #define Rereased 0
#endif

#define SW_Pin        3
#define BaudRate 115200
#define dataSize    128

uint8_t SW_old, SW_new = 0;
uint8_t IMU_Datas[dataSize];

void setup() {
  Serial.begin(BaudRate);
  pinMode(SW_Pin, INPUT_PULLUP);
  
}

void loop() {
  IMU_Datas[0] = random(256);
  IMU_Data_Switch();
  show_All_IMU_Datas();
  delay(1000);
/*
  SW_old = SW_new;
  SW_new = digitalRead(SW_Pin);
  if(SW_old == Rereased && SW_new == Pressed){
    //とりあえずパス:
  }
 */
}

void show_All_IMU_Datas(){
  for(uint16_t i = 0; i < dataSize; i++){
    Serial.print("IMU_Datas[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(IMU_Datas[i]);
  }
  Serial.println();
}

void IMU_Data_Switch(){
  for(uint16_t i = dataSize - 1; i > 0; i--){
    IMU_Datas[i] = IMU_Datas[i - 1];
  }
}
