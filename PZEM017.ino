#include <SimpleModbusMaster.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define baud 9600
#define timeout 1000
#define polling 400 // the scan rate
#define retry_count 50

#define TxEnablePin 2

#define TOTAL_NO_OF_REGISTERS 8

enum
{
  PACKET1,
  TOTAL_NO_OF_PACKETS // leave this last entry
};

Packet packets[TOTAL_NO_OF_PACKETS];
unsigned int regs[TOTAL_NO_OF_REGISTERS];

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set LCD address to 0x27 for a 16 chars and 2-line display

void setup()
{
  Serial.begin(9600);        // Start Serial Monitor
  Serial1.begin(9600);       // Start Serial1 for communication with PZEM-017

  // Configure Modbus packet
  modbus_construct(&packets[PACKET1], 1, READ_INPUT_REGISTERS, 0, TOTAL_NO_OF_REGISTERS, 0);
  modbus_configure(&Serial1, baud, SERIAL_8N2, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS, regs);  

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PZEM-017");
  delay(1000);
}

void loop()
{
  modbus_update();

  // Display data on LCD
  lcd.setCursor(0, 1);
  lcd.print("V: ");
  lcd.print(regs[0] / 100.0); // Assuming voltage is stored in regs[0] and needs conversion
  lcd.print("V");

  // Print data to Serial Monitor
  Serial.print("Voltage: ");
  Serial.println(regs[0] / 100.0);

  Serial.print("Current: ");
  Serial.println(regs[1] / 1000.0); // Assuming current is stored in regs[1] and needs conversion

  // Power is a 32-bit value, combine regs[2] and regs[3]
  unsigned long power = (regs[2] | (regs[3] << 16));
  Serial.print("Power: ");
  Serial.println(power / 10.0); // Assuming power needs conversion

  // Energy is a 32-bit value, combine regs[4] and regs[5]
  unsigned long energy = (regs[4] | (regs[5] << 16));
  Serial.print("Energy: ");
  Serial.println(energy); // Assuming energy is in Wh

  // High voltage alarm status
  Serial.print("High Voltage Alarm Status: ");
  Serial.println(regs[6]);

  // Low voltage alarm status
  Serial.print("Low Voltage Alarm Status: ");
  Serial.println(regs[7]);

  delay(2000); // Delay for readability
}
