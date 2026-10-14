#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// USB-UART
static const uint8_t TX = 43;
static const uint8_t RX = 44;

// I2C
static const uint8_t SDA = 17;
static const uint8_t SCL = 16;

// Общая SPI-шина
static const uint8_t SS = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 13;
static const uint8_t SCK = 12;

#define SPI_SCK_PIN 12
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 13
#define SPI_SS_PIN 10

// Экран ST7789, 240x240
#define HAS_SCREEN 1
#define USER_SETUP_LOADED 1
#define ST7789_DRIVER 1
#define ROTATION 1
#define TFT_WIDTH 240
#define TFT_HEIGHT 240
#define TFT_RGB_ORDER TFT_BGR

#define TFT_SCLK 12
#define TFT_MOSI 11
#define TFT_MISO 13
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

// Подсветка пока НЕ управляется GPIO.
// BL физически отсоединить от GPIO18.
#define TFT_BL -1
#define BACKLIGHT -1
#define TFT_BACKLIGHT_ON 1
#define MINBRIGHT 1

#define TOUCH_CS -1
#define SPI_FREQUENCY 10000000
#define SPI_READ_FREQUENCY 10000000

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT 1

// Кнопки замыкаются на GND
#define HAS_3_BUTTONS
#define UP_BTN 39
#define DW_BTN 40
#define SEL_BTN 41
#define BTN_ACT LOW
#define BTN_ALIAS "OK"

// SD-карта
#define SDCARD_SCK 12
#define SDCARD_MOSI 11
#define SDCARD_MISO 13
#define SDCARD_CS 1

// CC1101
#define USE_CC1101_VIA_SPI
#define CC1101_SCK_PIN 12
#define CC1101_MOSI_PIN 11
#define CC1101_MISO_PIN 13
#define CC1101_SS_PIN 7
#define CC1101_GDO0_PIN 6
#define CC1101_GDO2_PIN -1

// NRF24L01
#define USE_NRF24_VIA_SPI
#define NRF24_SCK_PIN 12
#define NRF24_MOSI_PIN 11
#define NRF24_MISO_PIN 13
#define NRF24_SS_PIN 4
#define NRF24_CE_PIN 5

// Ethernet W5500
#define USE_W5500_VIA_SPI
#define W5500_SCK_PIN 12
#define W5500_MOSI_PIN 11
#define W5500_MISO_PIN 13
#define W5500_SS_PIN 42
#define W5500_INT_PIN 2
#define W5500_RST_PIN 38

// PN532, режим I2C
#define GROVE_SDA 17
#define GROVE_SCL 16

// GPS: TX модуля -> GPIO14,
// RX модуля -> GPIO15
#define GPS_SERIAL_RX 14
#define GPS_SERIAL_TX 15

// Дополнительный UART не подключён
#define SERIAL_RX -1
#define SERIAL_TX -1

// ИК
#define TXLED 21
#define RXLED 47
#define LED_ON HIGH
#define LED_OFF LOW

#define IR_TX_PINS {{"IR driver", 21}}
#define IR_RX_PINS {{"IR receiver", 47}}

// Отдельных однопроводных RF-модулей нет.
// Для радио выбран CC1101.
#define RF_TX_PINS {{"Not connected", -1}}
#define RF_RX_PINS {{"Not connected", -1}}

#endif
