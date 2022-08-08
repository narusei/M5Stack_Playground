#include <Adafruit_LPS35HW.h>
#include <M5Stack.h>

Adafruit_LPS35HW lps35hw = Adafruit_LPS35HW();

// For SPI mode, we need a CS pin
#define LPS_CS  10
// For software-SPI mode we need SCK/MOSI/MISO pins
#define LPS_SCK  13
#define LPS_MISO 12
#define LPS_MOSI 11

TFT_eSprite sprite = TFT_eSprite(&M5.Lcd);

void setup() {
  M5.begin();
  M5.Power.begin();

  Serial.println("Adafruit LPS35HW Test");

  if (!lps35hw.begin_I2C()) {
  //if (!lps35hw.begin_SPI(LPS_CS)) {
  //if (!lps35hw.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {
    Serial.println("Couldn't find LPS35HW chip");
    while (1);
  }
  Serial.println("Found LPS35HW chip");

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(2);
}

void loop() {
  float t = lps35hw.readTemperature();
  float p = lps35hw.readPressure();
  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

  Serial.print("Pressure: ");
  Serial.print(p);
  Serial.println(" hPa");
  
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("%2.2f C", t);
  M5.Lcd.setCursor(0, 42);
  M5.Lcd.printf("%4.2f hPa", p);  

  delay(1000);
}
