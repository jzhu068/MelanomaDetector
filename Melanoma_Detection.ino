
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

#define TFT_CS     10 //chip select pin for the TFT screen
#define TFT_RST    9  // you can also connect this to the Arduino reset
                      // in which case, set this #define pin to 0!
#define TFT_DC     8

//low range of the sensor (this will be blue on the screen)
#define MINTEMP 15

//high range of the sensor (this will be red on the screen)
#define MAXTEMP 45

//the colors we will be using
const uint16_t camColors[] = {0x480F,
0x400F,0x400F,0x400F,0x4010,0x3810,0x3810,0x3810,0x3810,0x3010,0x3010,
0x3010,0x2810,0x2810,0x2810,0x2810,0x2010,0x2010,0x2010,0x1810,0x1810,
0x1811,0x1811,0x1011,0x1011,0x1011,0x0811,0x0811,0x0811,0x0011,0x0011,
0x0011,0x0011,0x0011,0x0031,0x0031,0x0051,0x0072,0x0072,0x0092,0x00B2,
0x00B2,0x00D2,0x00F2,0x00F2,0x0112,0x0132,0x0152,0x0152,0x0172,0x0192,
0x0192,0x01B2,0x01D2,0x01F3,0x01F3,0x0213,0x0233,0x0253,0x0253,0x0273,
0x0293,0x02B3,0x02D3,0x02D3,0x02F3,0x0313,0x0333,0x0333,0x0353,0x0373,
0x0394,0x03B4,0x03D4,0x03D4,0x03F4,0x0414,0x0434,0x0454,0x0474,0x0474,
0x0494,0x04B4,0x04D4,0x04F4,0x0514,0x0534,0x0534,0x0554,0x0554,0x0574,
0x0574,0x0573,0x0573,0x0573,0x0572,0x0572,0x0572,0x0571,0x0591,0x0591,
0x0590,0x0590,0x058F,0x058F,0x058F,0x058E,0x05AE,0x05AE,0x05AD,0x05AD,
0x05AD,0x05AC,0x05AC,0x05AB,0x05CB,0x05CB,0x05CA,0x05CA,0x05CA,0x05C9,
0x05C9,0x05C8,0x05E8,0x05E8,0x05E7,0x05E7,0x05E6,0x05E6,0x05E6,0x05E5,
0x05E5,0x0604,0x0604,0x0604,0x0603,0x0603,0x0602,0x0602,0x0601,0x0621,
0x0621,0x0620,0x0620,0x0620,0x0620,0x0E20,0x0E20,0x0E40,0x1640,0x1640,
0x1E40,0x1E40,0x2640,0x2640,0x2E40,0x2E60,0x3660,0x3660,0x3E60,0x3E60,
0x3E60,0x4660,0x4660,0x4E60,0x4E80,0x5680,0x5680,0x5E80,0x5E80,0x6680,
0x6680,0x6E80,0x6EA0,0x76A0,0x76A0,0x7EA0,0x7EA0,0x86A0,0x86A0,0x8EA0,
0x8EC0,0x96C0,0x96C0,0x9EC0,0x9EC0,0xA6C0,0xAEC0,0xAEC0,0xB6E0,0xB6E0,
0xBEE0,0xBEE0,0xC6E0,0xC6E0,0xCEE0,0xCEE0,0xD6E0,0xD700,0xDF00,0xDEE0,
0xDEC0,0xDEA0,0xDE80,0xDE80,0xE660,0xE640,0xE620,0xE600,0xE5E0,0xE5C0,
0xE5A0,0xE580,0xE560,0xE540,0xE520,0xE500,0xE4E0,0xE4C0,0xE4A0,0xE480,
0xE460,0xEC40,0xEC20,0xEC00,0xEBE0,0xEBC0,0xEBA0,0xEB80,0xEB60,0xEB40,
0xEB20,0xEB00,0xEAE0,0xEAC0,0xEAA0,0xEA80,0xEA60,0xEA40,0xF220,0xF200,
0xF1E0,0xF1C0,0xF1A0,0xF180,0xF160,0xF140,0xF100,0xF0E0,0xF0C0,0xF0A0,
0xF080,0xF060,0xF040,0xF020,0xF800,};

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

Adafruit_AMG88xx amg;
unsigned long delayTime;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
uint16_t displayPixelWidth, displayPixelHeight;


int serInLen = 25;
char serInString[25];

float logValue1=0;
float logValue2=0;
float logValue3=0;
float logValue4=0;
float logValue5=0;
float logValue6=0;
float logValue7=0;
float logValue8=0;

float logValue9=0;
float logValue10=0;
float logValue11=0;
float logValue12=0;
float logValue13=0;
float logValue14=0;
float logValue15=0;
float logValue16=0;

float logValue17=0;
float logValue18=0;
float logValue19=0;
float logValue20=0;
float logValue21=0;
float logValue22=0;
float logValue23=0;
float logValue24=0;

float logValue25=0;
float logValue26=0;
float logValue27=0;
float logValue28=0;
float logValue29=0;
float logValue30=0;
float logValue31=0;
float logValue32=0;

float logValue33=0;
float logValue34=0;
float logValue35=0;
float logValue36=0;
float logValue37=0;
float logValue38=0;
float logValue39=0;
float logValue40=0;

float logValue41=0;
float logValue42=0;
float logValue43=0;
float logValue44=0;
float logValue45=0;
float logValue46=0;
float logValue47=0;
float logValue48=0;

float logValue49=0;
float logValue50=0;
float logValue51=0;
float logValue52=0;
float logValue53=0;
float logValue54=0;
float logValue55=0;
float logValue56=0;

float logValue57=0;
float logValue58=0;
float logValue59=0;
float logValue60=0;
float logValue61=0;
float logValue62=0;
float logValue63=0;
float logValue64=0;

//int next = 0;
float result;

void setup() 
{ 
  // Setup serial comm. Initialize random function.
  Serial.begin(9600); 
  randomSeed(analogRead(0));
  delay(5000); 

  tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab
    tft.fillScreen(ST7735_BLACK);

    displayPixelWidth = tft.width() / 8;
    displayPixelHeight = tft.height() / 8;

    //tft.setRotation(3);
    
    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid Infrared sensor, check wiring!");
        while (1);
    }

   Serial.println("Ensure proper positioning of IR Sensor.");
    Serial.println();
    delay(2000); 
    Serial.println("Melanoma Detection Test will begin in 5 seconds.");
    Serial.println();
    delay(5000); // let sensor boot up

     
  // Use the COPYLOG copy file command to make a copy of a new empty logfile
  Serial.println("#S|COPYLOG|[]#");
  readSerialString(serInString,1000);
  // There ought to be a check here for a non 0 return value indicating an error and some error handeling
} 
 
void loop() 
{ 
   //read all the pixels
  amg.readPixels(pixels);

//Serial.print("#S|LOGTEST|[");
  Serial.print("[");
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i-1]);
      Serial.print("; ");
      if( i%8 == 0 ) Serial.println();
    }
    Serial.println("]");
    Serial.println();
//Serial.println("]#");

    //delay a second
    delay(2000);

  for(int i=0; i<AMG88xx_PIXEL_ARRAY_SIZE; i++){
    uint8_t colorIndex = map(pixels[i], MINTEMP, MAXTEMP, 0, 255);
    colorIndex = constrain(colorIndex, 0, 255);

    //draw the pixels!
    tft.fillRect(displayPixelHeight * floor(i / 8), displayPixelWidth * (i % 8),
        displayPixelHeight, displayPixelWidth, camColors[colorIndex]);
  }
   
   //Create some random values to log to a file on the PC.  This could be sensor readings or whatever
   //but for this example it's just 3 random values
   logValue1=(pixels[0]);
   logValue2=(pixels[1]);
   logValue3=(pixels[2]);
   logValue4=(pixels[3]);
   logValue5=(pixels[4]);
   logValue6=(pixels[5]);
   logValue7=(pixels[6]);
   logValue8=(pixels[7]);

   logValue9=(pixels[8]);
   logValue10=(pixels[9]);
   logValue11=(pixels[10]);
   logValue12=(pixels[11]);
   logValue13=(pixels[12]);
   logValue14=(pixels[13]);
   logValue15=(pixels[14]);
   logValue16=(pixels[15]);

   logValue17=(pixels[16]);
   logValue18=(pixels[17]);
   logValue19=(pixels[18]);
   logValue20=(pixels[19]);
   logValue21=(pixels[20]);
   logValue22=(pixels[21]);
   logValue23=(pixels[22]);
   logValue24=(pixels[23]);
   
   logValue25=(pixels[24]);
   logValue26=(pixels[25]);
   logValue27=(pixels[26]);
   logValue28=(pixels[27]);
   logValue29=(pixels[28]);
   logValue30=(pixels[29]);
   logValue31=(pixels[30]);
   logValue32=(pixels[31]);

   logValue33=(pixels[32]);
   logValue34=(pixels[33]);
   logValue35=(pixels[34]);
   logValue36=(pixels[35]);
   logValue37=(pixels[36]);
   logValue38=(pixels[37]);
   logValue39=(pixels[38]);
   logValue40=(pixels[39]);

   logValue41=(pixels[40]);
   logValue42=(pixels[41]);
   logValue43=(pixels[42]);
   logValue44=(pixels[43]);
   logValue45=(pixels[44]);
   logValue46=(pixels[45]);
   logValue47=(pixels[46]);
   logValue48=(pixels[47]);

   logValue49=(pixels[48]);
   logValue50=(pixels[49]);
   logValue51=(pixels[50]);
   logValue52=(pixels[51]);
   logValue53=(pixels[52]);
   logValue54=(pixels[53]);
   logValue55=(pixels[54]);
   logValue56=(pixels[55]);

   logValue57=(pixels[56]);
   logValue58=(pixels[57]);
   logValue59=(pixels[58]);
   logValue60=(pixels[59]);
   logValue61=(pixels[60]);
   logValue62=(pixels[61]);
   logValue63=(pixels[62]);
   logValue64=(pixels[63]);


   logData1(logValue1,logValue2,logValue3,logValue4,logValue5,logValue6,logValue7,logValue8);
   logData2(logValue9,logValue10,logValue11,logValue12,logValue13,logValue14,logValue15,logValue16);
   logData3(logValue17,logValue18,logValue19,logValue20,logValue21,logValue22,logValue23,logValue24);
   logData4(logValue25,logValue26,logValue27,logValue28,logValue29,logValue30,logValue31,logValue32);
   logData5(logValue33,logValue34,logValue35,logValue36,logValue37,logValue38,logValue39,logValue40);
   logData6(logValue41,logValue42,logValue43,logValue44,logValue45,logValue46,logValue47,logValue48);
   logData7(logValue49,logValue50,logValue51,logValue52,logValue53,logValue54,logValue55,logValue56);
   logData8(logValue57,logValue58,logValue59,logValue60,logValue61,logValue62,logValue63,logValue64);
   
   delay(5000); 
}


 
void logData1( float value1, float value2, float value3, float value4, float value5, float value6, float value7, float value8) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value1, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value2, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value3, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value4, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value5, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value6, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value7, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value8, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");
   
   readSerialString(serInString,1000);
   
} 

void logData2( float value9, float value10, float value11, float value12, float value13, float value14, float value15, float value16) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value9, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value10, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value11, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value12, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value13, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value14, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value15, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value16, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   readSerialString(serInString,1000);
   
} 

void logData3( float value17, float value18, float value19, float value20, float value21, float value22, float value23, float value24) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value17, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value18, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value19, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value20, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value21, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value22, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value23, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value24, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   readSerialString(serInString,1000);
  
} 

void logData4( float value25, float value26, float value27, float value28, float value29, float value30, float value31, float value32) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value25, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value26, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value27, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value28, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value29, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value30, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value31, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value32, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   readSerialString(serInString,1000);
  
} 

void logData5( float value33, float value34, float value35, float value36, float value37, float value38, float value39, float value40) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value33, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value34, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value35, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value36, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value37, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value38, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value39, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value40, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   readSerialString(serInString,1000);
  
} 

void logData6( float value41, float value42, float value43, float value44, float value45, float value46, float value47, float value48) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value41, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value42, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value43, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value44, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value45, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value46, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value47, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value48, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   readSerialString(serInString,1000);
  
} 

void logData7( float value49, float value50, float value51, float value52, float value53, float value54, float value55, float value56) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value49, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value50, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value51, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value52, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value53, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value54, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value55, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value56, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   readSerialString(serInString,1000);
  
} 

void logData8( float value57, float value58, float value59, float value60, float value61, float value62, float value63, float value64) 
{
   char buffer[5];
  
   Serial.print("#S|LOGTEST|[");
   Serial.print(dtostrf(value57, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value58, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value59, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value60, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value61, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value62, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value63, 4, 2, buffer));
   Serial.print(";");
   Serial.print(dtostrf(value64, 4, 2, buffer));
   Serial.print(";");
   Serial.println("]#");

   //Serial.print("#S|LOGTEST|[");
   //Serial.print(itoa((next),buffer,10));
   //Serial.println("]#");

   readSerialString(serInString,1000);
  
} 



//read a string from the serial and store it in an array
//you must supply the array variable - return if timeOut ms passes before the sting is read
void readSerialString (char *strArray,long timeOut) 
{
   long startTime=millis();
   int i;

   while (!Serial.available()) {
      if (millis()-startTime >= timeOut) {
         return;
      }
   }
   while (Serial.available() && i < serInLen) {
      strArray[i] = Serial.read();
      i++;
   }
}
