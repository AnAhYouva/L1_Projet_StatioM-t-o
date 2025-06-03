
#include <Wire.h>
#include <SI7021.h>
#include <FastLED.h>
#include <LTR303.h>

// === Définition LED ===
#define LED_PIN     4
#define NUM_LEDS    21
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

// === Capteurs ===
SI7021 sensor;
LTR303 light;

unsigned char gain = 0;
unsigned char integrationTime = 1;

void setup() {
  Serial.begin(115200);
  delay(3000);

  // === Initialisation capteurs ===
  sensor.begin();

  light.begin();
  unsigned char ID;
  if (light.getPartID(ID)) {
    Serial.print("Capteur lumière ID: 0x");
    Serial.println(ID, HEX);
  } else {
    Serial.println("Erreur init LTR303");
  }

  light.setControl(gain, false, false);
  light.setMeasurementRate(integrationTime, 3);
  light.setPowerUp();

  // === LED ===
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // === Température et humidité ===
  int temp = sensor.getCelsiusHundredths() / 100;
  int hum = sensor.getHumidityPercent();

  Serial.println("===== Station Météo =====");
  Serial.print("Température : ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidité : ");
  Serial.print(hum);
  Serial.println(" %");

  // === Luminosité ===
  unsigned int data0, data1;
  double lux;
  boolean good;

  if (light.getData(data0, data1)) {
    good = light.getLux(gain, integrationTime, data0, data1, lux);
    Serial.print("Luminosité (lux) : ");
    Serial.println(lux);
  } else {
    Serial.println("Erreur lecture luminosité");
    lux = 0;
  }

  // === LEDs selon luminosité ===
  uint8_t lux_temp = map((int)lux, 0, 50, 170, 0);
  fill_solid(leds, NUM_LEDS, ColorFromPalette(RainbowColors_p, lux_temp, BRIGHTNESS, LINEARBLEND));
  FastLED.show();

  delay(3000);
}
