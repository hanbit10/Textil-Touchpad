#include <LedControl.h>
#include <CapacitiveSensor.h>
#include <pt.h>
#include <math.h>

// millis
unsigned long time1;
unsigned long time2 = 5000;

/****Set the Sensor sensitivity*/
CapacitiveSensor cs_1 = CapacitiveSensor(38, 39);
CapacitiveSensor cs_2 = CapacitiveSensor(36, 37);
CapacitiveSensor cs_3 = CapacitiveSensor(34, 35);
CapacitiveSensor cs_4 = CapacitiveSensor(32, 33);
CapacitiveSensor cs_30_31 = CapacitiveSensor(30, 31);

/****Set the pins for the Arduino*/
int DIN = 12;
int CS = 11;
int CLK = 10;

int DIN2 = 7;
int CS2 = 6;
int CLK2 = 5;

LedControl lc = LedControl(DIN, CLK, CS, 8);
LedControl lc2 = LedControl(DIN2, CLK2, CS2, 8);

/*****Setup the Panel*/
void setup()
{
  cs_1.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example
  cs_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_30_31.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  lc.shutdown(0, false);  // The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0, 15); // Set the brightness to maximum value
  lc.clearDisplay(0);     // and clear the display
  lc2.shutdown(0, false);
  lc2.setIntensity(0, 15);
  lc2.clearDisplay(0);
}

void set_unit(byte number_of_unit)
{
  lc.shutdown(number_of_unit - 1, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(number_of_unit - 1, 1);
  /* and clear the display */
  lc.clearDisplay(number_of_unit - 1);
}

void set_unit2(byte number_of_unit2)
{
  lc2.shutdown(number_of_unit2 - 1, false);
  /* Set the brightness to a medium values */
  lc2.setIntensity(number_of_unit2 - 1, 1);
  /* and clear the display */
  lc2.clearDisplay(number_of_unit2 - 1);
}

// Swipe left
void left(byte number_of_unit)
{
  delay(50);
  lc2.setColumn(number_of_unit - 4, 1, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 4, 2, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 4, 3, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 4, 4, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 4, 5, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 4, 6, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 4, 7, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 0, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 1, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 2, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 3, B11111110);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 4, B01111100);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 5, B00111000);
  delay(20);
  lc2.setColumn(number_of_unit - 5, 6, B00010000);
  delay(20);

} // Swipe left ends//

// mid point
void mid_point(byte number_of_unit)
{
  delay(50);
  lc.setRow(number_of_unit, 3, B00000001);
  lc.setRow(number_of_unit, 4, B00000001);
  lc.setRow(number_of_unit - 1, 3, B10000000);
  lc.setRow(number_of_unit - 1, 4, B10000000);
  delay(150);

  lc.setRow(number_of_unit, 2, B00000011);
  lc.setRow(number_of_unit, 3, B00000011);
  lc.setRow(number_of_unit, 4, B00000011);
  lc.setRow(number_of_unit, 5, B00000011);
  lc.setRow(number_of_unit - 1, 2, B11000000);
  lc.setRow(number_of_unit - 1, 3, B11000000);
  lc.setRow(number_of_unit - 1, 4, B11000000);
  lc.setRow(number_of_unit - 1, 5, B11000000);
  delay(150);
  lc.setRow(number_of_unit, 1, B00000011);
  lc.setRow(number_of_unit, 2, B00000111);
  lc.setRow(number_of_unit, 3, B00000111);
  lc.setRow(number_of_unit, 4, B00000111);
  lc.setRow(number_of_unit, 5, B00000111);
  lc.setRow(number_of_unit, 6, B00000011);
  lc.setRow(number_of_unit - 1, 1, B11000000);
  lc.setRow(number_of_unit - 1, 2, B11100000);
  lc.setRow(number_of_unit - 1, 3, B11100000);
  lc.setRow(number_of_unit - 1, 4, B11100000);
  lc.setRow(number_of_unit - 1, 5, B11100000);
  lc.setRow(number_of_unit - 1, 6, B11000000);
  delay(150);

  lc.setRow(number_of_unit, 0, B00000011);
  lc.setRow(number_of_unit, 1, B00000111);
  lc.setRow(number_of_unit, 2, B00001111);
  lc.setRow(number_of_unit, 3, B00001111);
  lc.setRow(number_of_unit, 4, B00001111);
  lc.setRow(number_of_unit, 5, B00001111);
  lc.setRow(number_of_unit, 6, B00000111);
  lc.setRow(number_of_unit, 7, B00000011);
  lc.setRow(number_of_unit - 1, 0, B11000000);
  lc.setRow(number_of_unit - 1, 1, B11100000);
  lc.setRow(number_of_unit - 1, 2, B11110000);
  lc.setRow(number_of_unit - 1, 3, B11110000);
  lc.setRow(number_of_unit - 1, 4, B11110000);
  lc.setRow(number_of_unit - 1, 5, B11110000);
  lc.setRow(number_of_unit - 1, 6, B11100000);
  lc.setRow(number_of_unit - 1, 7, B11000000);
}
// mid point ends

// Right swipe
void right(byte number_of_unit)
{
  delay(50);
  lc.setColumn(number_of_unit - 5, 6, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 5, 5, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 5, 4, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 5, 3, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 5, 2, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 5, 1, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 5, 0, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 4, 7, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 4, 6, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 4, 5, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 4, 4, B11111110);
  delay(20);
  lc.setColumn(number_of_unit - 4, 3, B01111100);
  delay(20);
  lc.setColumn(number_of_unit - 4, 2, B00111000);
  delay(20);
  lc.setColumn(number_of_unit - 4, 1, B00010000);
  delay(20);
} // Right swipe ends//

// Push Button: "Push On"
void push_on(byte number_of_unit2)
{
  time1 = millis();
  lc2.setRow(number_of_unit2, 0, B11101001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 1, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 2, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 3, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 4, B11101001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 5, B10001001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 6, B10000110);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 0, B01101001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 1, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 2, B01001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 3, B00101111);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 4, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 5, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 6, B01101001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 0, B00000110);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 1, B00001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 2, B00001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 3, B00001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 4, B00001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 5, B00000110);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 0, B10001000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 1, B11001000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 2, B11101000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 3, B10111000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 4, B10011000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 5, B10001000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 6, B00000000);
} // push on ends//

void push(byte number_of_unit2)
{
  time1 = millis();
  lc2.setRow(number_of_unit2, 0, B11101001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 1, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 2, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 3, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 4, B11101001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 5, B10001001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 6, B10000110);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 0, B01101001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 1, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 2, B01001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 3, B00101111);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 4, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 5, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 6, B01101001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 7, B00000000);
}

/*//push   off
void push_off (byte number_of_unit){

    time1 = millis();
    lc.setRow(number_of_unit, 0,B11101001);
    time1 = millis();
    lc.setRow(number_of_unit,1,B10011001);
    time1 = millis();
    lc.setRow(number_of_unit,2,B10011001);
    time1 = millis();
    lc.setRow(number_of_unit,3,B10011001);
    time1 = millis();
    lc.setRow(number_of_unit,4,B11101001);
    time1 = millis();
    lc.setRow(number_of_unit,5,B10001001);
    time1 = millis();
    lc.setRow(number_of_unit,6,B10000110);

    time1 = millis();
    lc.setRow(number_of_unit-1,0,B01101001);
    time1 = millis();
    lc.setRow(number_of_unit-1,1,B10011001);
    time1 = millis();
    lc.setRow(number_of_unit-1,2,B01101001);
    time1 = millis();
    lc.setRow(number_of_unit-1,3,B00011111);
    time1 = millis();
    lc.setRow(number_of_unit-1,4,B10011001);
     time1 = millis();
    lc.setRow(number_of_unit-1,5,B10011001);
    time1 = millis();
    lc.setRow(number_of_unit-1,6,B01101001);

    time1 = millis();
    lc.setRow(number_of_unit-4,0,B00110111);
    time1 = millis();
    lc.setRow(number_of_unit-4,1,B01001100);
    time1 = millis();
    lc.setRow(number_of_unit-4,2,B01001100);
    time1 = millis();
    lc.setRow(number_of_unit-4,3,B01001111);
    time1 = millis();
    lc.setRow(number_of_unit-4,4,B01001100);
     time1 = millis();
    lc.setRow(number_of_unit-4,5,B00110100);

    time1 = millis();
    lc.setRow(number_of_unit-5,0,B10111100);
    time1 = millis();
    lc.setRow(number_of_unit-5,1,B00100000);
    time1 = millis();
    lc.setRow(number_of_unit-5,2,B00100000);
    time1 = millis();
    lc.setRow(number_of_unit-5,3,B10111100);
    time1 = millis();
    lc.setRow(number_of_unit-5,4,B00100000);
     time1 = millis();
    lc.setRow(number_of_unit-5,5,B00100000);
     time1 = millis();
    lc.setRow(number_of_unit-5,6,B00000000);
 } //push off ends//*/

// Push Button: "Push OFF"
void push_off2(byte number_of_unit2)
{

  time1 = millis();
  lc2.setRow(number_of_unit2, 0, B11101001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 1, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 2, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 3, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 4, B11101001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 5, B10001001);
  time1 = millis();
  lc2.setRow(number_of_unit2, 6, B10000110);

  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 0, B01101001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 1, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 2, B01001001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 3, B00101111);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 4, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 5, B10011001);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 1, 6, B01101001);

  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 0, B00110111);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 1, B01001100);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 2, B01001100);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 3, B01001111);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 4, B01001100);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 4, 5, B00110100);

  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 0, B10111100);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 1, B00100000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 2, B00100000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 3, B10111100);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 4, B00100000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 5, B00100000);
  time1 = millis();
  lc2.setRow(number_of_unit2 - 5, 6, B00000000);
} // push off ends//

///////////////////////////////////loop////////////////////////////
void loop()
{

  /*for(byte i=1;i<=16;i++){
         set_unit(i);
  }
  int i =6;
  push(i);*/

  boolean on;
  on = false;

  while (on == false)
  {
    long sensor5 = cs_30_31.capacitiveSensor(1);
    Serial.println(sensor5); // print sensor output

    // which led matrix
    for (byte i = 1; i <= 16; i++)
    {
      set_unit(i);
    } // which led matrix ends//

    // which led matrix
    for (byte i = 1; i <= 16; i++)
    {
      set_unit2(i);
    } // which led matrix ends//
    for (int j = 0; j <= 20; j++)
    {
      int number_of_unit2 = 6;
      long sensor5 = cs_30_31.capacitiveSensor(200);
      Serial.println(sensor5);
      if (j == 0)
      {
        lc2.setRow(number_of_unit2, 0, B11101001);
        delay(100);
      }
      if (j == 1)
      {
        lc2.setRow(number_of_unit2, 1, B10011001);
        delay(100);
      }
      if (j == 2)
      {
        lc2.setRow(number_of_unit2, 2, B10011001);
        delay(100);
      }
      if (j == 3)
      {
        lc2.setRow(number_of_unit2, 3, B10011001);
        delay(100);
      }
      if (j == 4)
      {
        lc2.setRow(number_of_unit2, 4, B11101001);
        delay(100);
      }
      if (j == 5)
      {
        lc2.setRow(number_of_unit2, 5, B10001001);
        delay(100);
      }
      if (j == 6)
      {
        lc2.setRow(number_of_unit2, 6, B10000110);
        delay(100);
      }
      if (j == 7)
      {
        lc2.setRow(number_of_unit2 - 1, 0, B01101001);
        delay(100);
      }
      if (j == 8)
      {
        lc2.setRow(number_of_unit2 - 1, 1, B10011001);
        delay(100);
      }
      if (j == 9)
      {
        lc2.setRow(number_of_unit2 - 1, 2, B01001001);
        delay(100);
      }
      if (j == 10)
      {
        lc2.setRow(number_of_unit2 - 1, 3, B00101111);
        delay(100);
      }
      if (j == 11)
      {
        delay(100);
        lc2.setRow(number_of_unit2 - 1, 4, B10011001);
      }
      if (j == 12)
      {
        lc2.setRow(number_of_unit2 - 1, 5, B10011001);
        delay(100);
      }
      if (j == 13)
      {
        lc2.setRow(number_of_unit2 - 1, 6, B01101001);
        delay(100);
      }
      if (j == 14)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(100);
      }
      if (j == 15)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(150);
      }
      if (j == 16)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(150);
      }
      if (j == 17)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(150);
      }
      if (j == 18)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(200);
      }
      if (j == 19)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(200);
      }
      if (j == 20)
      {
        lc2.setRow(number_of_unit2 - 1, 7, B00000000);
        delay(200);
      }
      if (j >= 0 && sensor5 >= 6700)
      {
        int i = 6;
        push_on(i);
        delay(2000);
        on = true;
      }
    }
  }

  while (on == true)
  {

    for (byte i = 1; i <= 8; i++)
    {
      set_unit2(i);
    }

    // sensor push off
    long sensor5 = cs_30_31.capacitiveSensor(200);
    if (sensor5 >= 6700 && on == true)
    {
      on = false;
      int i = 6;
      push_off2(i);
      delay(2000);
      for (int i = 0; i < 8; i++)
      {
        lc2.clearDisplay(i);
      }
    } // sensor push off end

    long sensor1 = cs_1.capacitiveSensor(100);
    long sensor2 = cs_2.capacitiveSensor(100);
    long sensor3 = cs_3.capacitiveSensor(100);

    Serial.print(sensor5); // print sensor output
    Serial.print("\t");
    Serial.print(sensor1);
    Serial.print("\t");
    Serial.print(sensor2);
    Serial.print("\t");
    Serial.println(sensor3);

    boolean a;
    a = false;

    int ab1 = 160;
    int ab2 = 160;
    int ab3 = 160;

    // sensorLeft => start

    if (sensor1 >= ab1 && a == false)
    {
      int i = 6;
      left(i);
      delay(300);
      for (int j = 0; j <= 7; j++)
      {
        lc.clearDisplay(j);
      }
      a = true;
    }
    if (sensor2 >= ab2 && a == false)
    {
      int i = 6;
      mid_point(i);
      delay(300);
      for (int j = 0; j <= 7; j++)
      {
        lc.clearDisplay(j);
      }
      a = true;
    }
    // sensorLeft ends//

    // sensorRight <= start

    if (sensor3 >= ab3 && a == false)
    {
      int i = 6;
      right(i);
      delay(300);
      for (int j = 0; j <= 7; j++)
      {
        lc.clearDisplay(j);
      }
      a = true;
    }
    // sensorright ends*/
  }
}

void printByte(byte character[])
{
  int i = 0;
  for (i = 0; i < 16; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}
