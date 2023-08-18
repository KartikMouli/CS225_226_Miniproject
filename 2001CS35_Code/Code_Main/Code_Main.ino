//Including Requied Libraries
#include <Wire.h>
#include <Adafruit_MLX90614.h>  //Library for MLX90614 IR Temp Sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600); //Braud Rate
  Serial.println("Arduino Project");  //Print Arduino Project
  Serial.println("Non-Contact Thermometer"); //print Project Name
  Serial.println("Kartik Mouli"); //print Name
  mlx.begin(); //Initialise Sensor

}

void loop() {

  float a, b, c, d; //Variables Declaration to store temp

  //strore ambient temp and object temp in Celcius
  a = mlx.readAmbientTempC();
  b = mlx.readObjectTempC();

  //strore ambient temp and object temp in Fahrenheit
  c = mlx.readAmbientTempF();
  d = mlx.readObjectTempF();

  //for Object Temp
  //print temp in celcius
  Serial.print("Ambient Temp = ");
  Serial.print(a);  //print ambient temp
  Serial.print("*C\t Object Temp = ");
  Serial.print(b);  //print object temp
  Serial.println("*C");

  //print temp in fahrenheit
  Serial.print("Ambient Temp = ");
  Serial.print(c);  //print ambient temp
  Serial.print("*F\t Object Temp = ");
  Serial.print(d);  //print object temp
  Serial.println("*F");

  //difference between ambient and object temp
  Serial.print("Diffrence= ");
  Serial.print(b - a);  //print diff in Celcius
  Serial.println("*C");


  //for Human Body, Fever Detection

  if (b > 30 && b < 40) {   //30-40 C normal temp of human body in fever
    if (b >= 37.78) {
      Serial.print("Fever :(");   //print fever if temp is above 37.78 C
    }
    else if (b < 33) {
      Serial.print("Low Body Temp :(");   //print low body temp if temp is less than 33 C
    }
    else {
      Serial.print("Normal Body Temp :)");  //print normal body temp if temp is b/w 33-37.78
    }
  }

  Serial.println("\n---------------------------------------------------------------------"); //print line

  delay(3000); //delay of 3 sec
}
