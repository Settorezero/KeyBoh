/* 
 * KeyBoh
 * https://www.github.com/settorezero/keyboh
 * (C)2020 Giovanni Bernardo (Cyb3rn0id), Roberto D'Amico (Bobboteck)
 * https://www.settorezero.com
 *
 * keytest
 * - Open a serial terminal @115200
 * - Press buttons, move encoder and thumbstick
 */

#include "HID-Project.h" // HID-Project library by Nico-Hood

int row[]={A0,A1,A2,A3};    // matrix keypad - rows 
int col[]={9,10,11,12,13};  // matrix keypad - columns

// encoder
#define ENC_BTN   6
#define ENC_A     7
#define ENC_B     8

// thumbstick
#define STICK_BTN 4
#define STICK_X   A5
#define STICK_Y   A4

void setup()
  {
  uint8_t i=0;
  // rows setup
  for (i=0; i<4; i++)
    {
    pinMode(row[i], INPUT_PULLUP);
    }
  // columns setup
  for (i=0; i<5; i++)
    {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], HIGH);
    }
    
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_BTN, INPUT_PULLUP);
  pinMode(STICK_BTN, INPUT_PULLUP);
  
  // encoder interrupt
  attachInterrupt(digitalPinToInterrupt(ENC_A), encoderTick, CHANGE); // Pulse interrupt
  
  // HID peripherals initialization
  //Keyboard.begin();
  //Mouse.begin();
  //Consumer.begin(); // used for multimedia buttons
  //Gamepad.begin();
  Serial.begin(115200);
  }

void loop()
  {
  // check pressed button on the 5x4 matrix
  // buttons are numbered from 1 to 20 as on the PCB
  // the number of the button pressed is (column+1)+(row*5)
  
  static uint8_t pressed_button=0; // pressed button on matrix keypad from 1 to 20, 0=no button pressed
    
  // keyboad scan
  for(uint8_t c=0; c<5; c++) // column scan
      {
      digitalWrite(col[c], LOW);
      for(uint8_t r=0; r<4; r++) // row scan
         {
         if(digitalRead(row[r])==LOW)
            {
            delay(20); // antibounce
            if(digitalRead(row[r])==LOW)
              {
              pressed_button=(c+1)+(r*5);
              while(digitalRead(row[r])==LOW); // stay until button released
              }
            }
         } // \row scan
       digitalWrite(col[c], HIGH);
       } // \column scan

	// a button is pressed, recall the associated function
    if (pressed_button>0) 
      {
        do_keypad_stuff(pressed_button);
        pressed_button=0;
      }
    
    // check encoder button
    if (digitalRead(ENC_BTN)==LOW)
      {
      delay(20);
      if (digitalRead(ENC_BTN)==LOW)
        {
         do_encoder_button_stuff(); 
         while(digitalRead(ENC_BTN)==LOW);
        }
      }

    // check thumbstick button
    if (digitalRead(STICK_BTN)==LOW)
      {
      delay(20);
      if (digitalRead(STICK_BTN)==LOW)
        {
         do_thumbstick_button_stuff();
         while(digitalRead(STICK_BTN)==LOW);
        }
      }

   // check analog thumbstick axis
   int16_t x=analogRead(STICK_X);
   int16_t y=analogRead(STICK_Y);
   do_thumbstick_analog_stuff(x,y);
   } // \loop

// encoder interrupt
void encoderTick()
  {
  static long t=millis();
  static int8_t m=0; // movement: 0=no movement, 1=clockwise, -1=counter-clockwise
  static int8_t c=0; // the tick will be checked two consecutive times, this will count the consecutive times
  if (t>millis()) t=millis(); // millis() rollover
  if (millis()-t<30) return; // to few time passed, maybe is a bounce
  c++; // a tick has occurred
  if (digitalRead(ENC_A)==digitalRead(ENC_B)) 
    {
    if (c==1) m=1; // first tick with clockwise movement
    if (c==2) // second tick
      {
      if (m==1) // the movement is still clockwise?
        {
        Serial.println("Encoder rotated clockwise");     
        }
      c=0;
      m=0;
      }
    }
  else // movement is counter-clockwise
    {
    if (c==1) m=-1;
    if (c==2)
      {
      if (m==-1)
        {
        Serial.println("Encoder rotated counter-clockwise");
        }
      c=0;
      m=0;
      }
    }
  t=millis(); // last time we checked
  }

// do function associated to buttons on keypad
void do_keypad_stuff(uint8_t pb)
  {
  Serial.print("Button ");
  Serial.println(pb);
  }

// click on encoder button
void do_encoder_button_stuff(void)
  {
  Serial.println("Encoder Button");  
  }

// click on thumbstick button
void do_thumbstick_button_stuff(void)
  {
  Serial.println("Thumbstick button");
  }

// movement of thumbstick axis
void do_thumbstick_analog_stuff(uint16_t x, uint16_t y)
  {
  // previous movement
  static int8_t predx=0;
  static int8_t predy=0;
  
  // actual movement
  int8_t dx=0;
  int8_t dy=0;

  // we'll use the analog joystick as a digital joystick
  // so I set a deadband and I'll check only the movement direction, not the movement amount
  if (x>600) dx=-1;
  else if (x<400) dx=1;

  if (y>600) dy=-1;
  else if (y<400) dy=1;

  if (dx==-1 && predx!=-1)
    {
    Serial.println("Thumbstick left");
    }
  else if (dx==1 && predx!=1)
    {
    Serial.println("Thumbstick right");  
    }
  predx=dx;

  if (dy==-1 && predy!=-1)
    {
    Serial.println("Thumbstick up");
    }
  else if (dy==1 && predy!=1)
    {
    Serial.println("Thumbstick down");  
    }
  predy=dy;
  }
