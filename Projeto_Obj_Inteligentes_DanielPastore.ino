#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "AdafruitIO_WiFi.h" // Biblioteca Adafruit IO

// Configurações do Wi-Fi
#define WIFI_SSID "rede"
#define WIFI_PASS "senha"

// Configurações do Adafruit IO
#define IO_USERNAME "daniel_pastore"
#define IO_KEY "senha"

// Instancia AdafruitIO
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Configuração do LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Configuração do módulo RFID
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Feed do Adafruit IO
AdafruitIO_Feed *rfidFeed = io.feed("rfid");

void setup() {
  Serial.begin(9600);

  // Inicialização do LCD
  lcd.begin(16, 2);
  lcd.print("Conectando...");

  // Inicializa a interface SPI e o módulo RFID
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println(F("Aproxime uma etiqueta RFID..."));

  // Conexão ao Adafruit IO
  io.connect();

  // Espera até estar conectado
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    lcd.print(".");
    delay(500);
  }

  Serial.println("\nConectado ao Adafruit IO");
  lcd.clear();
  lcd.print("Adafruit IO OK");
  delay(1000);
}

void loop() {
  io.run(); // Mantém a conexão com o Adafruit IO ativa

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Constrói o ID da tag
  String tagID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      tagID += "0";
    }
    tagID += String(mfrc522.uid.uidByte[i], HEX);
  }
  tagID.toUpperCase();

  // Exibe o ID no Serial Monitor e no LCD
  Serial.println("ID da Tag: " + tagID);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ID da Tag:");
  lcd.setCursor(0, 1);
  lcd.print(tagID);

  // Envia o ID da tag para o Adafruit IO
  rfidFeed->save(tagID.c_str());

  mfrc522.PICC_HaltA();
}

