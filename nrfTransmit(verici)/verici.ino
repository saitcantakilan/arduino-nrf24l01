#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;
uint8_t _data;

void setup()
{
    _radio.init(0, 9, 10); // Telsiz ID = 0, CE = 9 ve CSN = 10 pinlerini tanımla.
}

void loop()
{
    _data=++;
    _radio.send(1, &_data, sizeof(_data)); // Telsiz ID = 1 olan telsize gönder mesajı.
    delay(1000);
}
