// RX example

#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;
uint8_t _data;

void setup()
{
    Serial.begin(115200);
    _radio.init(1, 9, 10); // Telsiz ID = 1, CE = 9 ve CSN = 10 pinlerini tanımla.
}

void loop()
{
    while (_radio.hasData())
    {
        _radio.readData(&_data); // Gelen mesajı oku.
        Serial.println(_data);
    }
}
