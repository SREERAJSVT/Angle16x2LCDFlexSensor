# Angle16x2LCDFlexSensor
To measure the angle using a flex sensor with Arduino, you can follow these general steps. Keep in mind that the specific implementation might vary based on the sensor model and your project requirements.
To measure the angle using a flex sensor with Arduino, you can follow these general steps. Keep in mind that the specific implementation might vary based on the sensor model and your project requirements.

Components Needed:

    Arduino board (e.g., Arduino Uno)
    Flex sensor
    Resistor (10k ohms is commonly used)
    Breadboard and jumper wires

Connections:

    Connect one end of the flex sensor to the 5V output on the Arduino.
    Connect the other end of the flex sensor to the analog pin (e.g., A0) on the Arduino.
    Connect one leg of the resistor to the same analog pin (e.g., A0) on the Arduino.
    Connect the other leg of the resistor to the ground (GND) on the Arduino.

Here's a basic example of Arduino code to get you started:



    const int flexPin = A0;  // Analog pin connected to the flex sensor
    const int resistorValue = 10000;  // Resistor value in ohms
    
    void setup() {
      Serial.begin(9600);  // Initialize serial communication
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
    
      delay(500);  // Add a delay for stability
    }

This example reads the analog value from the flex sensor, calculates the corresponding voltage and resistance, and then maps the resistance to an angle. Adjust the mapping values based on the specifications of your flex sensor.If you want to display the flex sensor angle data on a 16x2 LCD using Arduino, you can modify the previous code to include the LCD library. Here's an example:

Components Needed (in addition to the previous components):

    16x2 LCD Display
    Potentiometer (for contrast adjustment)

Connections:

    Connect the VCC and GND of the LCD to 5V and GND on the Arduino.
    Connect the SDA and SCL of the LCD to the respective SDA and SCL pins on the Arduino.
    Connect the contrast pin (V0) of the LCD to the middle pin of the potentiometer, and connect the other two pins to 5V and GND on the Arduino.

Now, modify the previous code to include the LCD library and display the angle on the LCD:

      

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
          
This code initializes the LiquidCrystal_I2C library for the 16x2 LCD and displays the flex sensor angle on the LCD. Adjust the I2C address of the LCD (0x27) and the LCD dimensions if you are using a different setup.If you are using a 16x2 LCD without an I2C converter, you would typically connect it using parallel GPIO pins. Below is an example code that uses the standard LiquidCrystal library for a non-I2C 16x2 LCD:
                           
          
      #include <LiquidCrystal.h>
      
      const int flexPin = A0;  // Analog pin connected to the flex sensor
      const int resistorValue = 10000;  // Resistor value in ohms
      
      LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Pins for RS, E, D4, D5, D6, D7
      
      void setup() {
        Serial.begin(9600);  // Initialize serial communication
        lcd.begin(16, 2);    // Initialize the LCD with 16 columns and 2 rows
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
  
In this code, the LiquidCrystal library is used with the specific GPIO pin connections for RS, E, D4, D5, D6, and D7. Make sure to connect these pins correctly between the Arduino and the LCD. Adjust the pin numbers in the LiquidCrystal lcd(...) line according to your wiring.

This example assumes that you are using the default pin configuration for the LCD library. If you have a different pinout, adjust the pin numbers accordingly.
