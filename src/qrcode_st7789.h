#ifndef ESPQRST7789_H
#define ESPQRST7789_H
/* ESP_QRcode. tft version for ST7789
 * include this .h if you have a TFT display
 */

#define TFTDISPLAY

#include "qrcodedisplay.h"
#include <Adafruit_GFX.h>   
#include <Adafruit_ST7789.h>


class QRcode_ST7789 : public QRcodeDisplay
{
	private:
		Adafruit_ST7789 *display;
        void drawPixel(int x, int y, int color);
	public:
		
		QRcode_ST7789(Adafruit_ST7789 *display);

		void init();
		void screenwhite();
		void screenupdate();
};
#endif