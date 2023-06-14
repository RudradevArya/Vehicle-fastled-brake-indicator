
#include <FastLED.h>



const unsigned long interval = 1000; // time interval in milliseconds

unsigned long firstButtonPressTime = 0; // time when the first button was pressed
unsigned long secButtonPressTime = 0;

int flag1 = 0;
int flag2 = 0;


//---------------------------------------------------------------------
#define CHANNEL_LEDS 2 //Number of LEDs in a channel. Eg. 1,2,3,4,5,6,7,8,9,10,....18 
#define NUM_LEDS (CHANNEL_LEDS*8) //Total no of LEDs in the LED strip. Eg. 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144
int LED_POWER_7 = 100;
int LED_POWER_6 = 100;
int LED_POWER_5 = 120;
int LED_POWER_4 = 90;
int LED_POWER_3 = 50;
int LED_POWER_2 = 20;
int LED_POWER_1 = 5;
int LED_POWER_0 = 0;

int SPEED1 = 50;
int SPEED2 = 75;
int SPEED3 = 100;
int SPEED4 = 20;
int SPEED5 = 120;

const int buttonPin = 13;
const int mainButtonPin = 12;

int numb=0;
int pres=0;

//---------------------------------------------------------------------

#define numLEDS 16
#define blinkerLEDS 6

#define LEDpin 3
#define rytPin 5 
#define leftPin 7
#define brakePin 2 //9

#define RATE 500

CRGB leds[numLEDS];

//unsigned long turnColor = 0xff6a00; //kinda amber
unsigned long turnColor = 0xffbf00; //real amber 
//unsigned long turnColor = 0x00ffff; //blueish

int blinkerSpeed = 50;
int blinkerOffDelay = 200;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(600);

  FastLED.addLeds<WS2812B, LEDpin, GRB>(leds, numLEDS);
  pinMode(brakePin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rytPin, INPUT);

//---------------------------------------------------------------------
  pinMode(buttonPin, INPUT);
   pinMode(mainButtonPin, INPUT);
  
// CH1(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH8(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);
// CH1(LED_POWER_0, LED_POWER_0, LED_POWER_0);
// CH8(LED_POWER_0, LED_POWER_0, LED_POWER_0);
// CH2(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH7(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);
// CH2(LED_POWER_0, LED_POWER_0, LED_POWER_0);
// CH7(LED_POWER_0, LED_POWER_0, LED_POWER_0);
// CH3(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH6(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);
// CH3(LED_POWER_0, LED_POWER_0, LED_POWER_0);
// CH6(LED_POWER_0, LED_POWER_0, LED_POWER_0);
// CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);
// CH3(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH6(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);
// CH2(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH3(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH6(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH7(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);
// CH1(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH2(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH3(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH6(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH7(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// CH8(LED_POWER_7, LED_POWER_7, LED_POWER_7);
// delay (SPEED5);

  //---------------------------------------------------------------------

  //attachInterrupt(digitalPinToInterrupt(leftPin),btnPressR,RISING);

  // fill_solid(leds, numLEDS, CRGB::Black);
  // FastLED.show();

}

void loop() 
{
  // put your main code here, to run repeatedly:





  if((digitalRead(leftPin)==0)&&(digitalRead(rytPin)==0)&&(digitalRead(brakePin)==1))
  {
    //alternate reds dim
    //alterRed();
    //Pattern9();
    Pattern5();
    
    //Serial.println("hello?");
  } 

  if((digitalRead(leftPin)==0)&&(digitalRead(rytPin)==0)&&(digitalRead(brakePin)==0))
  {
    //all red
    allBrakes();
  }


  if((digitalRead(leftPin)==1)&&(digitalRead(rytPin)==0)&&(digitalRead(brakePin)==1))
  {
    //left turnColor
    // leftBlinker();
    //delay(blinkerOffDelay);
    middleAlterRed();

    EVERY_N_MILLISECONDS(RATE)
    {
      leftBlinker();
    }
  }

  if((digitalRead(leftPin)==0)&&(digitalRead(rytPin)==1)&&(digitalRead(brakePin)==1))
  {
    //right turnColor
    //rytBlinker();
    //delay(blinkerOffDelay);
    middleAlterRed();

    EVERY_N_MILLISECONDS(RATE)
    {
      rytBlinker();
    }
  }

  if((digitalRead(leftPin)==1)&&(digitalRead(rytPin)==0)&&(digitalRead(brakePin)==0))
  {
    //bright red for numLEDS - blinkerLEDS, left blinkerLEDS = turnColor 
    middleBrakes();
    //leftBlinker();
    //delay(blinkerOffDelay);
    EVERY_N_MILLISECONDS(RATE)
    {
      leftBlinker();
    }
  }

  if((digitalRead(leftPin)==0)&&(digitalRead(rytPin)==1)&&(digitalRead(brakePin)==0))
  {
    //bright red for numLEDS - blinkerLEDS, ryt blinkerLEDS = turnColor

    middleBrakes();
    //rytBlinker();
    //delay(blinkerOffDelay);

    EVERY_N_MILLISECONDS(RATE)
    {
      rytBlinker();
    }
  }


//OG HAZARD 

  // if((digitalRead(leftPin)==1)&&(digitalRead(rytPin)==1)&&(digitalRead(brakePin)==1))
  // {
  //   //only hazards

  //   // hazardBlinker();
  //   //delay(blinkerOffDelay);
  //   middleAlterRed();

  //   EVERY_N_MILLISECONDS(RATE)
  //   {
  //     hazardBlinker();
  //   }
  // }


//MIllis HAZARD

//   if (digitalRead(leftPin) == 1  &&(digitalRead(brakePin)==1)  ) {
//     firstButtonPressTime = millis();
//     Serial.println("button1 *** ");
//     flag1 = 1;
//   }

//   if (digitalRead(rytPin) == 1 &&(digitalRead(brakePin)==1)  ) { //&&(digitalRead(brakePin)==1)  
//     secButtonPressTime = millis();
//     Serial.println("---------------------button2  ");
//     flag2 = 1;
//   }

//   if (flag1 == 1 && flag2 == 1 && (secButtonPressTime - firstButtonPressTime <= interval || firstButtonPressTime - secButtonPressTime  <= interval)) {
//     // executeAnotherFunction();

//     middleAlterRed();
// //    hazardBlinker();
//     EVERY_N_MILLISECONDS(RATE)
//     {
//       hazardBlinker();
//     }
//     Serial.println("****here");

//     flag1 = 0;
//     flag2 = 0;
//   }




// //8th COmbination
//   if((digitalRead(leftPin)==1)&&(digitalRead(rytPin)==1)&&(digitalRead(brakePin)==0))
//   {
//     //hazards + brake light
//     middleBrakes();
//     //hazardBlinker();
//     //delay(blinkerOffDelay);
//     EVERY_N_MILLISECONDS(RATE)
//     {
//       hazardBlinker();
//     }
//   }



  //---------------------------------------------------------------------

  if(digitalRead(mainButtonPin)==1)
  {
    ButtonScan();

switch (numb) {
  case 1:
    Pattern1();
    break;
  case 2:
    Pattern2();
    break;
  case 3:
    Pattern3();
    break;
  case 4:
    Pattern4();
    break;
  case 5:
    Pattern5();
    break;
  case 6:
    Pattern6();
    break; 
   case 7:
    Pattern7();
    break;
  case 8:
    Pattern8();
    break;
  case 9:
    Pattern9();
    break;
  default:
    break;
}

  }
  
  //---------------------------------------------------------------------



}



  void alterRed()
  {
    //alternate red blinking with low brightness
    fill_solid(leds, numLEDS, CRGB(60,0,0));
    FastLED.show();

   
    // EVERY_N_MILLISECONDS(500)
    // {
    //   // fill_solid(leds, numLEDS, CRGB(0,0,0));
    //   // FastLED.show();

      
    //   for (int i = 0; i < numLEDS; i++)
    //   {
    //     leds[i] = CRGB(60, 0, 0);
    //   }
    //   FastLED.show();
    //   delay (200);

    //   for (int i = 0; i < numLEDS; i++)
    //   {
    //     leds[i] = CRGB(0, 0, 0);
    //   }
    //   FastLED.show();
    //   delay (150);

    //   for (int i = 0; i < numLEDS; i++)
    //   {
    //     leds[i] = CRGB(60, 0, 0);
    //   }
    //   FastLED.show();
    //   delay (200);

    //   for (int i = 0; i < numLEDS; i++)
    //   {
    //     leds[i] = CRGB(0, 0, 0);
    //   }
    //   FastLED.show();
    //   delay (500);
      
    // }

  }

  void middleAlterRed()
  {
    //alternate red blinking with low brightness
    //fill_solid(leds, 7, CRGB(60,0,0));
    for(int i = blinkerLEDS; i < numLEDS - blinkerLEDS ; i++)
    {
      leds[i] = CRGB(60,0,0);
    }
    FastLED.show();

    //Serial.println("middle ALter red");

  }


  void allBrakes()
  {
    // for(int i = 0; i < numLEDS ; i++)
    // {
    //   leds[i] = CRGB(255,0,0);
    //   //FastLED.show();
    // }
    fill_solid(leds, numLEDS, CRGB(200,0,0));
    FastLED.show();
  }

  void middleBrakes()
  {
    for(int i = blinkerLEDS ; i < numLEDS - blinkerLEDS ; i++)
    {
      leds[i] = CRGB(180,0,0);
    }
    FastLED.show();
  }

  void leftBlinker()
  {
    for(int i = blinkerLEDS-1; i >= 0  ; i--)
    {
      leds[i] = turnColor;
      //leds[i] = CRGB(255,191,0);
      FastLED.show();
      delay(blinkerSpeed);
      //delay(blinkerOffDelay);
    }
    fill_solid( leds, numLEDS, CRGB(0,0,0));
    FastLED.show();
  }


  void rytBlinker()
  {
    for(int i = (numLEDS - blinkerLEDS) ; i < numLEDS  ; i++)
    {
      leds[i] = turnColor;
      //leds[i] = CRGB(255,191,0);
      FastLED.show();
      delay(blinkerSpeed);
      //delay(blinkerOffDelay);
    }
    fill_solid( leds, numLEDS, CRGB(0,0,0));
    FastLED.show();
  }


  // void hazardBlinker()
  // {
  //   int x, y;
  //   for(x = blinkerLEDS-1 , y = (numLEDS - blinkerLEDS)  ; x >= 0 , y < numLEDS ; x-- , y++)
  //   {
  //     leds[x] = turnColor;
  //     //leds[i] = CRGB(255,191,0);

  //     // FastLED.show();
  //     // delay(blinkerSpeed);

  //     leds[y] = turnColor;
  //     //leds[i] = CRGB(255,191,0);

  //     FastLED.show();
  //     delay(blinkerSpeed);
  //     //delay(blinkerOffDelay);
  //   }
  //   fill_solid( leds, numLEDS, CRGB(0,0,0));
  //   FastLED.show();

  //   Serial.println("hazards");
  // }



  //---------------------------------------------------------------------

  
void ButtonScan()
{
  if(digitalRead(buttonPin)==1 )
  {
    if(pres==0)
    {
      numb++;
      pres=1;
     //Serial.println("here");
    }
  }
  else
  {
    pres=0;
    //Serial.println("NOT here");
  }  

  if(numb == 10)
  {
    numb = 1;
  } 
}

void Pattern1()
{
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
delay (SPEED1); ButtonScan();

CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);   
}


void Pattern2()
{
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();

CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();  
}


void Pattern3()
{
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH5(0, 0, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH5(0, 0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();

CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);
delay (SPEED1); ButtonScan();
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);
delay (SPEED1); ButtonScan(); 
}


void Pattern4()
{
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED2); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED2); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED2); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);  
delay (SPEED2); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED2); ButtonScan();
}

void Pattern5()
{
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
  
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
}

void Pattern6()
{
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
}


void Pattern7()
{
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
}

void Pattern8()
{
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH4(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH5(LED_POWER_0, LED_POWER_0, LED_POWER_0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_7);

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED4); ButtonScan();

CH2(LED_POWER_7, 0, 0);
CH7(0, 0, LED_POWER_7);

CH1(LED_POWER_7, 0, 0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH8(0, 0, LED_POWER_0); 
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH8(0, 0, LED_POWER_0); 
delay (SPEED4); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH8(0, 0, LED_POWER_7);  
delay (SPEED4); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH8(0, 0, LED_POWER_0); 
delay (SPEED4); ButtonScan();

CH1(LED_POWER_7, 0, 0);
CH8(0, 0, LED_POWER_7);  
}


void Pattern9()
{
CH4(LED_POWER_7, LED_POWER_7, LED_POWER_7);
CH5(LED_POWER_7, LED_POWER_7, LED_POWER_7);

CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_7, 0, 0);
CH2(LED_POWER_7, 0, 0);
CH3(LED_POWER_7, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();

CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_7);
CH7(0, 0, LED_POWER_7);
CH8(0, 0, LED_POWER_7);  
delay (SPEED1); ButtonScan();
CH1(LED_POWER_0, 0, 0);
CH2(LED_POWER_0, 0, 0);
CH3(LED_POWER_0, 0, 0);
CH6(0, 0, LED_POWER_0);
CH7(0, 0, LED_POWER_0);
CH8(0, 0, LED_POWER_0);  
delay (SPEED1); ButtonScan();
}




int CH1(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*0); i <= ((CHANNEL_LEDS*0)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH2(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*1); i <= ((CHANNEL_LEDS*1)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH3(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*2); i <= ((CHANNEL_LEDS*2)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH4(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*3); i <= ((CHANNEL_LEDS*3)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH5(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*4); i <= ((CHANNEL_LEDS*4)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH6(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*5); i <= ((CHANNEL_LEDS*5)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH7(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*6); i <= ((CHANNEL_LEDS*6)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}

int CH8(int r, int g, int b)
{
  for (int i = (CHANNEL_LEDS*7); i <= ((CHANNEL_LEDS*7)+(CHANNEL_LEDS-1)); i++)
  {
    leds[i] = CRGB(r, g, b);
  }
    FastLED.show();
}
  //---------------------------------------------------------------------


