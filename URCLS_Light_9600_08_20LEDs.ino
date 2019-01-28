// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS     32

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte LightMode;

int delayval = 50,SCounter,tTurn; // delay for half a second
void _test(void);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
Serial.begin(9600);
Serial.print("Hello it is UniLightKit01 Light control  URCLS_Light_07 Short 9600  ver 08");
  _test();
}

void loop() {
if(( LightMode&0x04) == 0x00)
{
 for(int i=0;i<NUMPIXELS;i++)
 {
     pixels.setPixelColor(i, pixels.Color(5,5 ,5)); // Moderately bright white color.
 
  }
}
else
{
  for (int i=1;i<3;i++) // 
{
  pixels.setPixelColor(i, pixels.Color(31,31,31));
   pixels.setPixelColor(i+6, pixels.Color(31,31,31));
}

  for (int i=9;i<12;i++)
{
  pixels.setPixelColor(i, pixels.Color(31,15,0));
   pixels.setPixelColor(i+8, pixels.Color(31,15,0));
}

pixels.setPixelColor(12, pixels.Color(31,15,0));
pixels.setPixelColor(0, pixels.Color(31,15,0));

 pixels.setPixelColor(16, pixels.Color(31,0,0));
 pixels.setPixelColor(13, pixels.Color(31,0,0));
 pixels.setPixelColor(15, pixels.Color(5,5,5));
 pixels.setPixelColor(14, pixels.Color(5,5,5));
 
  for (int i=3;i<7;i++)
{
  pixels.setPixelColor(i, pixels.Color(5,5,5));
   //pixels.setPixelColor(i+13, pixels.Color(5,5,5));
}
 

if((LightMode&0x01) == 0x01)
{

for (int i=1;i<3;i++)
{
  pixels.setPixelColor(i, pixels.Color(127,127 ,127));
   pixels.setPixelColor(i+6, pixels.Color(127,127 ,127));
}
 
}

if((LightMode&0x02) == 0x02)
{

for (int i=12;i<15;i++)
{
  pixels.setPixelColor(i, pixels.Color(127,127 ,127));
   pixels.setPixelColor(i+3, pixels.Color(127,127 ,127));
}
 
}

if((LightMode&0x08) == 0x08)
{




  
for (int i=9;i<13;i++)
if(tTurn++<1200)
 pixels.setPixelColor(i, pixels.Color(255,127 ,0));
 else
 {
 pixels.setPixelColor(i, pixels.Color(0,0 ,0));
  if(tTurn>2400)
  tTurn=0;
 }






 
}
if((LightMode&0x10) == 0x10)
{

if(tTurn++<1200)
pixels.setPixelColor(0, pixels.Color(255,127 ,0));
else
pixels.setPixelColor(0, pixels.Color(0,0 ,0));
  
for (int i=17;i<20;i++)
if(tTurn++<1200)
 pixels.setPixelColor(i, pixels.Color(255,127 ,0));
 else
 {
 pixels.setPixelColor(i, pixels.Color(0,0 ,0));
  if(tTurn>2400)
  tTurn=0;
 }
}

if((LightMode&0x20) == 0x20)
{

for (int i=1;i<3;i++)
{
  pixels.setPixelColor(i, pixels.Color(31,31 ,31));
   pixels.setPixelColor(i+6, pixels.Color(31,31 ,31));
}
for (int i=12;i<18;i++)
{
 
   pixels.setPixelColor(i, pixels.Color(255,255 ,255));
   
}




}


 if((LightMode&0x40) == 0x40)
{

pixels.setPixelColor(14, pixels.Color(63,0,0));
pixels.setPixelColor(13, pixels.Color(63,0,0));
for (int i=14;i<16;i++)
{
  pixels.setPixelColor(i, pixels.Color(31,31 ,31));
 //  pixels.setPixelColor(i+7, pixels.Color(255,255 ,255));
}
for (int i=1;i<9;i++)
{
 // pixels.setPixelColor(i+10, pixels.Color(255,255 ,255));
   pixels.setPixelColor(i, pixels.Color(255,255 ,255));
}
}
  
}

  if((LightMode&0x80) == 0x80)
{
  
for (int i=13;i<17;i++)
 
 pixels.setPixelColor(i, pixels.Color(255,0 ,0));

 
  
}


if ( ( LightMode&0x18) == 0x18)
{

// if(tTurn++<2400)
  
  byte i16=byte(tTurn/400);
 pixels.setPixelColor(  20+ (0+i16)%6 , pixels.Color(127,0 ,0));
 pixels.setPixelColor(  26+ (0+i16)%6 , pixels.Color(127,0 ,0));

  pixels.setPixelColor(  20+ (1+i16)%6 , pixels.Color(255,0 ,0));
 pixels.setPixelColor(  26+ (1+i16)%6 , pixels.Color(255,0 ,0));


  pixels.setPixelColor(  20+ (2+i16)%6 , pixels.Color(127,0 ,0));
 pixels.setPixelColor(  26+ (2+i16)%6 , pixels.Color(127,0 ,0));

  pixels.setPixelColor(  20+ (3+i16)%6 , pixels.Color(0,0 ,127));
 pixels.setPixelColor(  26+ (3+i16)%6 , pixels.Color(0,0 ,127));

  pixels.setPixelColor(  20+ (4+i16)%6 , pixels.Color(0,0 ,255));
 pixels.setPixelColor(  26+ (4+i16)%6 , pixels.Color(0,0 ,255));

  pixels.setPixelColor(  20+ (5+i16)%6 , pixels.Color(0,0 ,127));
 pixels.setPixelColor(  26+ (5+i16)%6 , pixels.Color(0,0 ,127));


 
}
else
{


  for(byte i16=0;i16<12;i16++)
  {

      pixels.setPixelColor(  20+ i16 , pixels.Color(50,50 ,50));
  }
}


   pixels.show(); 




if(Serial.available())  
{
    LightMode =  Serial.read();

Serial.write(LightMode);
SCounter=0;
}

if(SCounter++>31000)
{
LightMode=0;
Serial.println("Wait too long");
SCounter=0;
}







   
}


void _test(void)
{
// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,0 ,0)); // Moderately bright green color.
    if(i>0)
     pixels.setPixelColor(i-1, pixels.Color(5,0 ,0)); // Moderately bright green color.
     

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }

    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0 ,255)); // Moderately bright green color.
    if(i>0)
     pixels.setPixelColor(i-1, pixels.Color(0,0 ,5)); // Moderately bright green color.
     

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,255 ,0)); // Moderately bright green color.
    if(i>0)
     pixels.setPixelColor(i-1, pixels.Color(0,5 ,0)); // Moderately bright green color.
     

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    
     pixels.setPixelColor(i, pixels.Color(5,5 ,5)); // Moderately bright green color.
     

   

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
 pixels.show(); // This sends the updated pixel color to the hardware.
  
  }
