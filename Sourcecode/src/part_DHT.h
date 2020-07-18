SimpleDHT11 dht11(DHT_DATA);

void readDHT() {
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&dht11Temp, &dht11Hum, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  #if DEBUG
  Serial.print("Sample OK: ");
  Serial.print((int)dht11Temp); Serial.print(" *C, "); 
  Serial.print((int)dht11Hum); Serial.println(" H");
  #endif
}