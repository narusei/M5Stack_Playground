#include "arduino_secrets.h"

String serviceUUIDTop = SERVICE_UUID_TOP;
String serviceUUIDUnd = SERVICE_UUID_UND;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);

  char buf[50];
  serviceUUIDTop.toCharArray(buf, 50);
  int top = strtol(buf,NULL,16);
  serviceUUIDUnd.toCharArray(buf, 50);
  int und = strtol(buf,NULL,16);
  Serial.println(top);
  Serial.println(und);
}

void loop() {
  // put your main code here, to run repeatedly:

}
