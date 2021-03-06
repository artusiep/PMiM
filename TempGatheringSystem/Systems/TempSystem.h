#ifndef TEMPSYSTEM
#define TEMPSYSTEM
#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONEWIREBUS 2
#define TEMPERATUREPRECISION 10

#define DHTPIN 3
#define DHTTYPE DHT11

class TempSystem {
  private:
    OneWire oneWire{ONEWIREBUS};
    DallasTemperature thermometers{&oneWire};
    uint8_t numberOfThermometers;
    DeviceAddress tempDeviceAddress;
    void showIfParasite();
    void printDdress(DeviceAddress thermometerAddress);
    String getThermometherTemp(DeviceAddress);


    DHT dht{DHTPIN, DHTTYPE};

    TempSystem();
  public:
    void getThermomethersTemp();
    static TempSystem & getInstance();
    float getDTH11Temp();
    float getDTH11Humi();
};

#endif
