#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object
Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

void setup()
{
    Serial.begin(115200);

    // Initialize I2C
    Wire.begin();

    // Initialize OLED
    if(!display.begin(
        SSD1306_SWITCHCAPVCC,
        0x3C))
    {
        Serial.println("OLED failed");
        while(true);
    }

    // Clear display
    display.clearDisplay();

    // Text settings
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    // Print text
    display.setCursor(0, 10);
    display.println("TRUCK");

    display.setCursor(0, 35);
    display.println("GAUGE");

    // Push to screen
    display.display();
}

void loop()
{

}