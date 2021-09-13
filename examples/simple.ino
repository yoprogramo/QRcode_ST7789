
#define TFT_RST   23    
#define TFT_CS    5     
#define TFT_DC    16  
#define TFT_BACKLIGHT 4
#define TFT_MOSI 19
#define TFT_SCLK 18  

#include <Adafruit_GFX.h>      
#include <Adafruit_ST7789.h>   
#include <SPI.h>
#include <qrcode_st7789.h>

Adafruit_ST7789 display = Adafruit_ST7789(&SPI, TFT_CS, TFT_DC, TFT_RST);
QRcode_ST7789 qrcode (&display);


void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    // enable debug qrcode
    // qrcode.debug();
    SPI.begin(TFT_SCLK,TFT_RST,TFT_MOSI,TFT_CS);
    display.init(135,240);
    pinMode(TFT_BACKLIGHT, OUTPUT);
    digitalWrite(TFT_BACKLIGHT, HIGH);

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Hello world.");

}

void loop() { }