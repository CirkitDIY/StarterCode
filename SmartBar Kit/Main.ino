#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>

// 🧠 STEP 1: Fill in your Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// 🖥️ LCD setup (Most common I2C address is 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 chars, 2 rows

// 🔁 Interval for updating the display (in milliseconds)
const long updateInterval = 10000;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(115200);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Connecting WiFi");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  lcd.clear();
  lcd.print("WiFi connected!");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (millis() - lastUpdate >= updateInterval) {
    lastUpdate = millis();

    if (WiFi.status() == WL_CONNECTED) {
      // ✅ TODO 1: Make an API request to get live weather
      // Use HTTPClient + API URL (e.g., from weatherapi.com or openweathermap)
      // Example:
      // HTTPClient http;
      // http.begin("http://api.example.com/weather...");
      // int code = http.GET();
      // parse response...

      // ✅ TODO 2: Parse JSON response to extract temperature and condition
      // Use ArduinoJson library
      // Display data on LCD with lcd.setCursor() and lcd.print()

      // 📟 Placeholder display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Weather:");
      lcd.setCursor(0, 1);
      lcd.print("Sunny 75F");  // Replace this with real data
      delay(3000);

      // 🕒 BONUS: Show current time and date using NTP
      // ✅ TODO 3: Set up NTP and display live time
      // configTime(...), struct tm, localtime_r(), etc.
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time:");
      lcd.setCursor(0, 1);
      lcd.print("00:00:00");  // Replace with real time
      delay(3000);
    } else {
      lcd.clear();
      lcd.print("WiFi lost...");
    }
  }
}


/*
🎯 Going further:

This is just the beginning. Once you're done with the basics, we recommend going beyond this!

🔌 You can connect and display:
- Live stock prices
- Your 3D printer's live print status
- Smart home data
- And so much more...

📣 Show off what you've made in our Discord's #showcase channel, and don’t hesitate to ask questions in the respective channels!

*/
