#pragma once

// --- CONFIGURACIÓN DE PANTALLA ST7735 (SPI) ---
#define ST7735_CS 16      // Pin CS del Display
#define ST7735_RS 17      // Pin DC/RS del Display
#define ST7735_RESET 4    // Pin RESET del Display
#define SPI_SCK 5         // SCK compartido con LoRa
#define SPI_MOSI 27       // MOSI compartido con LoRa
#define SPI_MISO 19       // MISO compartido con LoRa

// --- GPS ---
#undef GPS_RX_PIN
#undef GPS_TX_PIN
#define GPS_RX_PIN 12
#define GPS_TX_PIN 15
#define GPS_UBLOX

// --- BOTONES Y ENERGÍA ---
#define BUTTON_PIN 39
#define BATTERY_PIN 35
#define ADC_CHANNEL ADC1_GPIO35_CHANNEL
#define ADC_MULTIPLIER 1.85
#define EXT_PWR_DETECT 4
#define EXT_NOTIFY_OUT 12
#define LED_POWER 2

// --- PINES MÓDULO LORA (SX1262 / EBYTE E22) ---
#define LORA_DIO0 26
#define LORA_RESET 23
#define LORA_DIO1 33
#define LORA_DIO2 32

#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS 18

// Módulos soportados
#define USE_RF95
#define USE_SX1262
#define USE_SX1268
#define USE_LLCC68

// Mapeo SX126X
#define SX126X_CS 18
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN RADIOLIB_NC
#define SX126X_TXEN 13

#define RF95_RXEN 14
#define RF95_TXEN 13
#define SX126X_MAX_POWER 22

#ifdef EBYTE_E22
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL
#endif
