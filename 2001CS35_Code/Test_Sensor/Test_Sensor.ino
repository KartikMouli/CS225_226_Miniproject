//Include libraries
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Initial Setup
void setup() {
  Serial.begin(9600);  
  mlx.begin();  
}

void loop() {
 
Serial.print("Temperature : ");
Serial.print(mlx.readObjectTempC()); //read temp from sensor and print it
Serial.println(" Celsius");

Serial.println();
delay(1000); //1 sec delay
}
