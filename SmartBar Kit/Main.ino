#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>

// 🧠 STEP 1: Fill in your Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 chars, 2 rows

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
      // ✅ TODO 1: Make an API request to WeatherAPI.com
      // 1. Go to https://www.weatherapi.com/
      // 2. Sign up and get your free API key
      // 3. Construct a URL like:
      // http://api.weatherapi.com/v1/current.json?key=YOUR_KEY&q=YOUR_CITY&aqi=no
      //
      // Example:
      // HTTPClient http;
      // http.begin("http://api.weatherapi.com/v1/current.json?key=...&q=...&aqi=no");
      // int code = http.GET();
      // parse response...

      // ✅ TODO 2: Use ArduinoJson to parse the JSON response
      // Extract "temp_f" and "condition.text"
      // Show them on the LCD

      // 📟 Placeholder display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Weather:");
      lcd.setCursor(0, 1);
      lcd.print("Sunny 75F");  // Replace this with real data
      delay(3000);

      // 🕒 BONUS: Show current time and date using NTP
      // ✅ TODO 3: Set up time using configTime(), localtime_r(), etc.
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
