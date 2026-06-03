#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22
#define LED_PIN 2
#define TEMP_THRESHOLD_C 25.0f

DHT dht(DHT_PIN, DHT_TYPE);

typedef struct{
  float temperature;
  float humidity;
  bool is_valid;
} SensorData;


void printReading(SensorData *data) {
  if (!data->is_valid) {
    Serial.println("Invalid reading");
    return;
  }
  // snprintf with %f doesn't work on ESP32 without
  // compiler flags I believe. Using Serial.print() for floats for now.
  // Fix in platformio.ini: build_flags = -u _printf_float
  Serial.print("Temp: ");
  Serial.print(data->temperature);
  Serial.print("C, Humidity: ");
  Serial.print(data->humidity);
  Serial.println("%");
}


void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  delay(3000);
  Serial.println("Sensor logger started");
}

void loop() {
  SensorData reading = {0};
  reading.temperature = dht.readTemperature();
  reading.humidity = dht.readHumidity();
  reading.is_valid = !isnan(reading.temperature) && !isnan(reading.humidity);

  printReading(&reading);
  if (reading.is_valid && reading.temperature > TEMP_THRESHOLD_C) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(5000);
}

