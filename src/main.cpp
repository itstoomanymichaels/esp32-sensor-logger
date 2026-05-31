#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

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
  char buf[64];
  sniprintf(buf, sizeof(buf), "Temp: %.1fC, Humidity: %.1f%%", data->temperature, data->humidity);
  Serial.println(buf);
}


void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Sensor logger started");
}

void loop() {
  SensorData reading = {0};
  reading.temperature = dht.readTemperature();
  reading.humidity = dht.readHumidity();
  reading.is_valid = !isnan(reading.temperature) && !isnan(reading.humidity);

  printReading(&reading);
  delay(5000);
}

