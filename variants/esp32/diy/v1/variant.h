#pragma once

//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//               MESHTASTIC DIY V1 - ESP32 + EBYTE E22 + ST7735                //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////


// ============================================================================
// LORA - EBYTE E22 SX1262 / SX1268
// ============================================================================

#define USE_SX1262
#define USE_SX1268
#define USE_LLCC68

#define SX126X_CS 18
#define SX126X_DIO1 33
#define SX126X_BUSY 32
#define SX126X_RESET 23

#define SX126X_RXEN RADIOLIB_NC
#define SX126X_TXEN 13

#define SX126X_MAX_POWER 22

// SPI compartido LoRa + Display
#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS SX126X_CS

// Compatibilidad con partes antiguas del firmware
#define LORA_DIO0 26
#define LORA_DIO1 SX126X_DIO1
#define LORA_DIO2 SX126X_BUSY
#define LORA_RESET SX126X_RESET
#define LORA_DIO3


// ============================================================================
// EBYTE E22
// ============================================================================

#ifdef EBYTE_E22

#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL

#endif


// ============================================================================
// DISPLAY ST7735S 1.77" 128x160
// ============================================================================

#define HAS_SCREEN 1
#define HAS_SPI_TFT 1
#define USE_TFTDISPLAY 1

#define ST7735S 1

// Pines exclusivos del display
#define ST7735_CS 16
#define ST7735_RS 17
#define ST7735_RESET 4

// Bus SPI compartido con LoRa
#define ST7735_SCK 5
#define ST7735_SDA 27
#define ST7735_MISO 19

#define ST7735_BUSY -1

// ESP32-WROOM clásico
#define ST7735_SPI_HOST VSPI_HOST

// LoRa y ST7735 comparten el mismo host SPI.
// DMA de LovyanGFX debe permanecer desactivado para que RadioLib pueda
// realizar correctamente sus transferencias CPU/FIFO sobre el mismo bus.
#define TFT_DMA_CHANNEL 0

// Frecuencias SPI
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 16000000

// Resolución física
#define TFT_WIDTH 128
#define TFT_HEIGHT 160

#define TFT_OFFSET_X 0
#define TFT_OFFSET_Y 0

#define TFT_INVERT false

// Reduce el layout para pantallas pequeñas
#define FORCE_LOW_RES 1
#define DISPLAY_FORCE_SMALL_FONTS

#define SCREEN_TRANSITION_FRAMERATE 5

// Si la imagen aparece girada, habilitar:
// #define SCREEN_ROTATE


// ============================================================================
// GPS
// ============================================================================

#define HAS_GPS 1

#undef GPS_RX_PIN
#undef GPS_TX_PIN

#define GPS_RX_PIN 12
#define GPS_TX_PIN 15

#define GPS_UBLOX


// ============================================================================
// BOTÓN
// ============================================================================

#define BUTTON_PIN 39


// ============================================================================
// BATERÍA
// ============================================================================

#define BATTERY_PIN 35
#define ADC_CHANNEL ADC1_GPIO35_CHANNEL
#define ADC_MULTIPLIER 1.85


// ============================================================================
// LED DE ESTADO
// ============================================================================

#define LED_POWER 2


// ============================================================================
// CONFLICTOS DE GPIO
// ============================================================================

// GPIO4 ahora pertenece al RESET del ST7735.
// No puede utilizarse simultáneamente como EXT_PWR_DETECT.
#undef EXT_PWR_DETECT

// GPIO12 pertenece al GPS RX.
// Evitamos reutilizarlo como salida de notificaciones externas.
#undef EXT_NOTIFY_OUT


//////////////////////////////////////////////////////////////////////////////////
//                              FIN DE VARIANTE                                 //
//////////////////////////////////////////////////////////////////////////////////
