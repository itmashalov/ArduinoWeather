import processing.serial.*;
import cc.arduino.*;
Arduino arduino;
int ledPin = 13;//it will be for red led
int ledPin2 = 12;//it will be for green led
int ledRgb1 = 7;
int ledRgb2 = 6;
void setup()
{
size(800, 600);
PImage bg = loadImage("clouds.jpg");
background(bg);
//println(Arduino.list());
arduino = new Arduino(this, Arduino.list()[0], 57600);
arduino.pinMode(ledPin, Arduino.OUTPUT);
}
float y = 40;
float new_t=1;
float old_t=2;
void draw()
{
new_t = temp();
delay(0);
if(new_t>old_t){
arduino.digitalWrite(ledRgb1, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb1, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.HIGH);

arduino.digitalWrite(ledPin2, Arduino.HIGH);
delay(5000);
arduino.digitalWrite(ledPin2, Arduino.LOW);
delay(50);
// turn off rgb
arduino.digitalWrite(ledRgb1, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb1, Arduino.LOW);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.LOW);
}
if(new_t<old_t){
arduino.digitalWrite(ledRgb1, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb1, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.HIGH);

arduino.digitalWrite(ledPin, Arduino.HIGH);
delay(5000);
arduino.digitalWrite(ledPin, Arduino.LOW);
delay(50);

// turn off rgb
arduino.digitalWrite(ledRgb1, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb1, Arduino.LOW);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.HIGH);
delay(0);
arduino.digitalWrite(ledRgb2, Arduino.LOW);
}
while(old_t!=new_t){

y += 30;
text("Temperature Dundee : "+new_t,26, y);
old_t=new_t;
}
}
float temp(){
float bit;
int y;
float x = 0;
String[] hr1;
String[] hr2;
String[] hr3;
String[] hr4;
String[] hr5;
String[] hr6;
String[] hr7;
String[] hr8;
String[] hr9;
String[] page = loadStrings("http://www.sat.dundee.ac.uk/weather/");
// initilise a new string variable to put the page into
String p = "";
String p1 = "";
//for every line
for (int i=0;i<page.length;i++) {
p += page[i];
}
String startMarker = "<table";
String endMarker = "</table>";
int start = p.indexOf(startMarker);
p = p.substring(start+startMarker.length(), p.length());
int end = p.indexOf(endMarker);
String ss = p.substring(0, end);
String[] list1 = split(ss, "th align");
hr1 = list1[1].split(">");
hr1 = hr1[2].split("<");
String content = "";
String[] hight;
for (int i=0; i<page.length; i++) {
content += page[i];
}
String[] h_list = split(content,"<td>");
hight = split(h_list[1],"<script");
String temp=hight[0].substring(0, 3);
float temp_temp =float(temp);
//int temp=int(temp_temp*10);
fill(255,255,255);
textSize(22);
return temp_temp;
}