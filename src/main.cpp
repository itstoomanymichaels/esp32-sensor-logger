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
  Serial.print("Temp: ");
  Serial.print(data->temperature);
  Serial.print("C, Humidity: ");
  Serial.print(data->humidity);
  Serial.println("%");
}


void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);
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

