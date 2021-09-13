# QRcode_ST7789

Subclass that you can use jointly with https://github.com/yoprogramo/QRcodeDisplay to generate QRcodes in TFT displays like ST7789

To use it:

## In platform.io: 

Add as dependencies:

 * yoprogramo/QRcodeDisplay
 * yoprogramo/QRcode_ST7789
 * adafruit/Adafruit GFX Library
 * adafruit/Adafruit ST7735 and ST7789 Library

 ## In arduino ide 
 
 Open Library Manager (menu Sketch > Include Library > Manage Libraries…) then install the following libraries:

 * QRcodeDisplay
 * QRcode_ST7789
 * Adafruit GFX Library
 * adafruit/Adafruit ST7735 and ST7789 Library

 Creating a QRcode is just as simple as (note we are using a Lilygo board that does not expose the SPI interface and we have to use other SPI):

 ```
#define TFT_RST       23    
#define TFT_CS        5     
#define TFT_DC        16  
#define TFT_BACKLIGHT 4
#define TFT_MOSI      19
#define TFT_SCLK      18  

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

 ```

 For other displays, please refer the main repository: https://github.com/yoprogramo/QRcodeDisplay
