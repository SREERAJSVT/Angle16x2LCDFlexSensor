#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int flexPin = A0;  // Analog pin connected to the flex sensor
const int resistorValue = 10000;  // Resistor value in ohms

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 column and 2 rows

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  lcd.begin(16, 2);    // Initialize the LCD
}

void loop() {
  int flexValue = analogRead(flexPin);  // Read the analog value from the flex sensor

  // Calculate the voltage
  float voltage = flexValue * (5.0 / 1023.0);

  // Calculate the resistance of the flex sensor using the voltage divider formula
  float flexResistance = (5.0 * resistorValue) / voltage - resistorValue;

  // Map the resistance to an angle (adjust the values based on your sensor and requirements)
  float angle = map(flexResistance, 300, 1000, 0, 90);

  // Print the results to the serial monitor
  Serial.print("Flex Value: ");
  Serial.print(flexValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Resistance: ");
  Serial.print(flexResistance);
  Serial.print(", Angle: ");
  Serial.println(angle);

  // Display angle on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Flex Angle:");
  lcd.setCursor(0, 1);
  lcd.print(angle);

  delay(500);  // Add a delay for stability
}
