#include "TempSystem.h"

TempSystem::TempSystem() {
  Serial.println("DHT 11 activation");
  dht.begin();
  thermometers.begin();
  numberOfThermometers = thermometers.getDeviceCount();

  Serial.print("Locating devices...");

  Serial.print("Found ");
  Serial.print(numberOfThermometers, DEC);
  Serial.println(" devices.");

  showIfParasite();

  // Loop through each device, print out address
  for(uint8_t i=0;i<numberOfThermometers; i++)
  {
    // Search the wire for address
    if(thermometers.getAddress(tempDeviceAddress, i))	{
	   Serial.print("Found device ");
	   Serial.print(i, DEC);
     Serial.print(" with address: ");
     //printAddress(tempDeviceAddress);
     Serial.println();

     Serial.print("Setting resolution to ");
     Serial.println(TEMPERATUREPRECISION, DEC);

		// set the resolution to TEMPERATURE_PRECISION bit (Each Dallas/Maxim device is capable of several different resolutions)
    thermometers.setResolution(tempDeviceAddress, TEMPERATUREPRECISION);

		 Serial.print("Resolution actually set to: ");
	   Serial.print(thermometers.getResolution(tempDeviceAddress), DEC);
	   Serial.println();
  }else{
	   Serial.print("Found ghost device at ");
	   Serial.print(i, DEC);
	   Serial.print(" but could not detect address. Check power and cabling");
  }
 }
}

void TempSystem::showIfParasite(){
  Serial.print("Parasite power is: ");
  if (thermometers.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
}

TempSystem & TempSystem::getInstance() {
  static TempSystem singleton;
  return singleton;
}

float TempSystem::getDTH11Temp() {
  return dht.readTemperature();
}

float TempSystem::getDTH11Humi() {
  return dht.readHumidity();
}

void TempSystem::getThermomethersTemp(){
  for(uint8_t i=0;i<numberOfThermometers; i++) {
    if(thermometers.getAddress(tempDeviceAddress, i))	{
      Serial.print("Temperature for device: ");
      Serial.print(i,DEC);
      Serial.print(" ");
      Serial.print("0");
      Serial.print(tempDeviceAddress[1], HEX);
      Serial.println(
        getThermometherTemp(tempDeviceAddress)
      );
    }
  }
}

String TempSystem::getThermometherTemp(DeviceAddress thermometerAddress){
  return(String("Temp C:") +
        String(thermometers.getTempC(thermometerAddress)));
}
