#pragma once

//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//        MESHTASTIC DIY V1 - ESP32 + SX127x + ST7735S (SPI COMPARTIDO)       //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

// ============================================================================
// LORA - SX1276 / SX1278 (comprobado por RegVersion 0x42 = 0x12)
// ============================================================================

#define USE_RF95

#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS 18

#define LORA_DIO0 26
// Meshtastic RF95Configuration.h requires LORA_DIO1 to exist for SX127x.
// It is not used by the RF95 path on this board, so leave it unconnected.
#define LORA_DIO1 RADIOLIB_NC
#define LORA_RESET 14

// Este modulo SX127x no usa BUSY/DIO1/DIO2 ni TXEN/RXEN externos.
// No definir RF95_RXEN/RF95_TXEN: GPIO13 pertenece al CS del TFT.


// ============================================================================
// DISPLAY ST7735S 1.77" 128x160
// ============================================================================

#define HAS_SCREEN 1
#define HAS_SPI_TFT 1
#define USE_TFTDISPLAY 1
#define ST7735S 1

// Pinout comprobado en hardware
#define ST7735_CS 13
#define ST7735_RS 12
#define ST7735_RESET 2

// Bus SPI compartido con SX127x
#define ST7735_SCK 5
#define ST7735_SDA 27
#define ST7735_MISO 19
#define ST7735_BUSY -1

#define ST7735_SPI_HOST VSPI_HOST

// Mantener DMA desactivado al compartir el host SPI con RadioLib.
#define TFT_DMA_CHANNEL 0

#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 16000000

#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define TFT_OFFSET_X 0
#define TFT_OFFSET_Y 0
#define TFT_INVERT false

#define FORCE_LOW_RES 1
#define DISPLAY_FORCE_SMALL_FONTS
// TFTDisplay::connect() rotates this panel to landscape (rotation 3).
// Match the OLED framebuffer geometry to the physical 160x128 landscape area.
#define SCREEN_ROTATE
#define SCREEN_TRANSITION_FRAMERATE 5

// LEDA/BL sigue conectado directamente a VCC.
// Cuando se mueva fisicamente a GPIO21 se agregara el control de backlight.


// ============================================================================
// GPS
// ============================================================================

// NEO-6M UART a 9600 baudios.
// GPS TX -> ESP32 GPIO16 (RX); GPS RX -> ESP32 GPIO17 (TX).
// No usar GPIO12: pertenece al TFT ST7735.
#define HAS_GPS 1
#define GPS_UBLOX
#undef GPS_RX_PIN
#undef GPS_TX_PIN
#define GPS_RX_PIN 16
#define GPS_TX_PIN 17
#define GPS_BAUDRATE 9600


// ============================================================================
// BOTON
// ============================================================================

#define BUTTON_PIN 39


// ============================================================================
// BATERIA
// ============================================================================

#define BATTERY_PIN 35
#define ADC_CHANNEL ADC1_GPIO35_CHANNEL
#define ADC_MULTIPLIER 1.85


// ============================================================================
// CONFLICTOS DE GPIO
// ============================================================================

// GPIO2 pertenece al RESET del ST7735: no usarlo como LED_POWER.
// GPIO12 pertenece al DC/RS del ST7735: no usarlo para GPS ni Ext Notify.
#undef LED_POWER
#undef EXT_PWR_DETECT
#undef EXT_NOTIFY_OUT


//////////////////////////////////////////////////////////////////////////////////
//                              FIN DE VARIANTE                                 //
//////////////////////////////////////////////////////////////////////////////////
