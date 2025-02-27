#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Service UUID, helps us identify the beacon even more
const char *service_uuid = "6b671ad7-5fb8-437b-bf41-8c57bbbc3374";

void setup() {
  Serial.begin(115200);

  // Initialize BLE device with name MyBeacon
  BLEDevice::init("MyBeacon");
  // Create a server, which then we use to create the service with the service UUID from above
  BLEServer *bleServer = BLEDevice::createServer();
  BLEService *bleService = bleServer->createService(service_uuid);

  // Start the BLE service, add service UUID and start advertising
  bleService->start();
  BLEAdvertising *bleAdvertising = BLEDevice::getAdvertising();
  bleAdvertising->addServiceUUID(service_uuid);
  bleAdvertising->setScanResponse(true);
  bleAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}

void loop() {
  delay(2000);
}