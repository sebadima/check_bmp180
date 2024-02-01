#include <Adafruit_BMP085.h>
#include <SPI.h>

// Collega VCC del BMP085 sensore a 3.3 V (NON 5.0 V!)
// Collega GND a Ground
// Collega SCL al clock i2c
// Collega SDA ai  dati i2c

Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(115200);
  if (!bmp.begin()) {
	Serial.println("Non riesco a trovare il sensore BMP085. Controlla i collegamenti.");
	while (1) {}
  }
}
  
void loop() {
    Serial.print("Temperatura = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" C°");
    
    Serial.print("Pressione = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    Serial.print("Altitudine = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" metri");

    Serial.print("Pressione a livello del mare (calcolata) = ");

    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

    // Si può ottenere una misurazione più precisa dell'altitudine,
    // se si conosce l'attuale pressione del livello del mare.
    // Se assumiamo che sia 1015 millibar otteniamo il valore,
    // equivalente di 101500 Pascali da fornire come parametro alla funzione: 
    // bmp.readAltitude()

    Serial.print("Altitudine reale = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" metri");
    
    Serial.println();
    delay(1000);
}
