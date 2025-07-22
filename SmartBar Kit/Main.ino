// 📦 Required Libraries
#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <time.h>  

// 🔌 Step 1: Add your Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// 🌤️ Step 2: Add your WeatherAPI key and location
const char* apiKey = "YOUR_API_KEY_HERE";   // Get this from https://weatherapi.com
const char* city = "YOUR_CITY";             // Example: "austin"
String apiUrl = String("http://api.weatherapi.com/v1/current.json?key=")+apiKey +"&q=" +city + "&aqi=no";

// 📟 LCD Setup (I2C address, 16 chars, 2 lines)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 🕒 Set weather refresh interval (e.g., every 10 seconds)
const long updateInterval = 10000;
unsigned long lastUpdate = 0;

// 🌐 NTP Time config (for Part 2)
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -5 * 3600;        // Adjust for your timezone (example: GMT-5)
const int daylightOffset_sec = 0;            // Optional: daylight savings

void setup() {
  Serial.begin(115200);

  // ✅ Step 3: Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Connecting WiFi");

  // ✅ Step 4: Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  lcd.clear();
  lcd.print("WiFi connected!");
  delay(1000);
  lcd.clear();

  // 🕒 Step 5 (Part 2): Configure NTP time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  if (millis() - lastUpdate >= updateInterval) {
    lastUpdate = millis();

    if (WiFi.status() == WL_CONNECTED) {
      // TODO: Use HTTPClient to send a GET request

      if (httpCode == 200){

        // TODO: Use ArduinoJson to parse the response
        // Extract: "temp_f" and "condition.text"
        if(!err) {
          // TODO: Display the temperature and weather condition on the LCD
          // Use lcd.setCursor(x, y) and lcd.print()

          // Optional: Add delay(2500) between displays

          // ⏰ Show Time & Date
          // TODO: Use time(nullptr), localtime_r() to get current time
          // TODO: Format time as HH:MM:SS and date as MM/DD/YYYY
          // TODO: Display time and date on LCD


        }
        

      } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("api error");
      }
      
      http.end();
      
    } else {
      // 🚫 Wi-Fi Disconnected
      lcd.clear();
      lcd.print("WiFi lost...");
    }
  }
}

/*
📘 GOING FURTHER (BONUS):

Try displaying:
- 📈 Live stock prices
- 🔧 3D printer print status
- 📦 Home automation sensor data
- or any other ideas you have!

🔧 You can switch displays every few seconds and build your own dashboard!

📣 Need help or want to share your build?
Join our Discord and post in #showcase!
*/