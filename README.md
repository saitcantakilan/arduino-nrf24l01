```c++
// Verici Örneği

#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;
uint8_t _data;

void setup()
{
    _radio.init(0, 9, 10);  // Telsiz ID = 0, CE = 9 ve CSN = 10 pinlerini tanımla.
}

void loop()
{
    _data++;
    _radio.send(1, &_data, sizeof(_data)); // Telsiz ID = 1 olan telsize gönder mesajı.
    delay(1000);
}
```
```c++
// Alıcı Örneği

#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;
uint8_t _data;

void setup()
{
    Serial.begin(115200);
    _radio.init(1, 9, 10);  // Telsiz ID = 1, CE = 9 ve CSN = 10 pinlerini tanımla.
}

void loop()
{
    while (_radio.hasData())
    {
        _radio.readData(&_data);
        Serial.println(_data);
    }
}
```


### Kurulum
* Arduino IDE'yi başlatın.
* Taslak > Kütüphane ekle> Kitaplıkları Yönet menü öğesini seçerek Kütüphane Yöneticisini açın.
* 'nrflite' kelimesini aratın.
* En son sürümü seçin ve Yükle düğmesine tıklayın.
* Dosya> Örnekler> NRFLite menüsündeki örnekleri görüntüleyin.

### nRF24L01 + Pin Referansı

![nRF24L01 Pinout](https://github.com/dparson55/NRFLite/raw/master/extras/nRF24L01_pinout_small.jpg)



### Arduino UNO SPI Bağlama Kılavuzu

```
Radio MISO -> Arduino 12 MISO
Radio MOSI -> Arduino 11 MOSI
Radio SCK  -> Arduino 13 SCK
Radio CE   -> Herhangi bir GPIO Pin (CSN ile aynı olabilir)
Radio CSN  -> Herhangi bir GPIO Pin (pin 10 önerilir)
Radio IRQ  -> Herhangi bir GPIO Pin (isteğe bağlı)
```
![ArduinoUno Pinout](https://cdn.pixabay.com/photo/2017/03/23/12/32/arduino-2168193_960_720.png)

Kaynak : https://github.com/dparson55/NRFLite
