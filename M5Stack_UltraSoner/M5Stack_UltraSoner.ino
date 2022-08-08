#include <M5Stack.h>

unsigned char data[4]={};
float distance;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  Serial.begin(115200);
  Serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  do {
    for (int i=0; i<4; i++) {
      data[i]=Serial2.read();
    }
  } while (Serial2.read() == 0xff);

  Serial2.flush();

  if (data[0] == 0xff) {
    int sum;
    sum = (data[0]+data[1]+data[2])&0x00FF;
    if (sum == data[3]) {
      distance = (data[1]<<8) + data[2];
    
        Serial.print("distance in air = ");
        Serial.print(distance/10);
        Serial.println("cm");
        Serial.print("distance in water = ");
        Serial.print(distance/2);
        Serial.println("cm");
     
    } else {
      Serial.println("ERROR");
    }
  }
  delay(100);
}
