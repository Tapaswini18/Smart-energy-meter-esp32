#define BLYNK_TEMPLATE_ID "TMPL3HGtAtL3t"
#define BLYNK_TEMPLATE_NAME "Smart Energy Meter"
#define BLYNK_AUTH_TOKEN "7dWxaxQH6A8LSYEIpZ4EJXa_Jdwm5TK3"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define VOLTAGE_PIN 34
#define CURRENT_PIN 35

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

float energy = 0;
unsigned long previousTime = 0;

void sendEnergyData()
{
  int voltageADC = analogRead(VOLTAGE_PIN);
  int currentADC = analogRead(CURRENT_PIN);

  float voltage = (voltageADC / 4095.0) * 250.0;
  float current = (currentADC / 4095.0) * 10.0;

  float power = voltage * current;

  unsigned long currentTime = millis();

  float elapsedHours =
    (currentTime - previousTime) / 3600000.0;

  energy += (power * elapsedHours) / 1000.0;

  previousTime = currentTime;

  // Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Current: ");
  Serial.print(current);
  Serial.print(" A | Power: ");
  Serial.print(power);
  Serial.print(" W | Energy: ");
  Serial.print(energy, 6);
  Serial.println(" kWh");

  // Send data to Blynk
  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, power);
  Blynk.virtualWrite(V3, energy);
}

void setup()
{
  Serial.begin(115200);

  delay(1000);

  previousTime = millis();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Blynk connection finished");

  timer.setInterval(1000L, sendEnergyData);
}

void loop()
{
  Blynk.run();
  timer.run();
}
