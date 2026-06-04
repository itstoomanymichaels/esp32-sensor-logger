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
  // build_flags = -Wl,-u,_printf_float in platformio.ini enables %f in snprintf
  char buff[64] = {0};
  snprintf(buff, sizeof(buff), "Temp: %.1f, Humidity: %.1f%%", data->temperature, data->humidity);
  Serial.println(buff);
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

