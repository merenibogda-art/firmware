#include "core/powerSave.h"
#include <interface.h>

static void outputHigh(int pin) {
    if (pin < 0) return;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}

void _setup_gpio() {
    // Все SPI-устройства сначала отключены через CS.
    outputHigh(TFT_CS);
    outputHigh(SDCARD_CS);
    outputHigh(CC1101_SS_PIN);
    outputHigh(NRF24_SS_PIN);
    outputHigh(W5500_SS_PIN);

    outputHigh(TFT_RST);
    outputHigh(TFT_DC);
    outputHigh(W5500_RST_PIN);

    pinMode(NRF24_CE_PIN, OUTPUT);
    digitalWrite(NRF24_CE_PIN, LOW);

    pinMode(CC1101_GDO0_PIN, INPUT);
    pinMode(W5500_INT_PIN, INPUT_PULLUP);

    pinMode(UP_BTN, INPUT_PULLUP);
    pinMode(DW_BTN, INPUT_PULLUP);
    pinMode(SEL_BTN, INPUT_PULLUP);

    pinMode(TXLED, OUTPUT);
    digitalWrite(TXLED, LOW);
    pinMode(RXLED, INPUT);

    // Начальные настройки для чистого хранилища.
    bruceConfigPins.rfModule = CC1101_SPI_MODULE;
    bruceConfigPins.rfTx = -1;
    bruceConfigPins.rfRx = -1;
    bruceConfigPins.rfidModule = PN532_I2C_MODULE;

    Serial.println("[S3] ST7789 240x240; buttons 39/40/41");
}

// Измерение аккумулятора не подключено.
int getBattery() { return 0; }
bool isCharging() { return false; }

// GPIO подсветки не используется.
void _setBrightness(uint8_t brightval) {
    (void)brightval;
}

void InputHandler() {
    static uint32_t changedAt = 0;
    static uint32_t emittedAt = 0;
    static uint8_t previousRaw = 0;

    const uint32_t now = millis();

    const uint8_t raw =
        (digitalRead(UP_BTN) == LOW ? 1 : 0) |
        (digitalRead(DW_BTN) == LOW ? 2 : 0) |
        (digitalRead(SEL_BTN) == LOW ? 4 : 0);

    if (raw != previousRaw) {
        previousRaw = raw;
        changedAt = now;
    }

    if (!raw || now - changedAt < 25) return;
    if (!LongPress && now - emittedAt < 180) return;

    emittedAt = now;

    if (wakeUpScreen()) return;
    AnyKeyPress = true;

    // UP + DOWN = назад.
    if ((raw & 3) == 3) {
        EscPress = true;
        PrevPress = false;
        NextPress = false;
        SelPress = false;
        return;
    }

    PrevPress = (raw & 1) != 0;
    NextPress = (raw & 2) != 0;
    SelPress = (raw & 4) != 0;
}

// Управляемого выключателя питания нет.
void powerOff() {}
void checkReboot() {}
