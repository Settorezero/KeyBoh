/* 
 * KeyBoh
 * https://www.github.com/settorezero/keyboh
 * (C)2020 Giovanni Bernardo (Cyb3rn0id), Roberto D'Amico (Bobboteck)
 * https://www.settorezero.com
 *
 * Inkscape shortcuts
 * See readme for keyboh configuration
 */

#include "HID-Project.h" // HID-Project library by Nico-Hood
//#define MAC // uncomment this if you're using a MAC

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

#ifdef MAC
#define CONTROL KEY_LEFT_GUI
#else
#define CONTROL KEY_LEFT_CTRL
#endif

bool zoomfit=true;

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
  Keyboard.begin();
  Mouse.begin();
  //Consumer.begin(); // used for multimedia buttons
  //Gamepad.begin();
  }

void loop()
  {
  // check pressed button on the 5x4 matrix
  // buttons are numbered from 1 to 20 as on the PCB
  // the number of the button pressed is (column+1)+(row*5)
  
  static uint8_t pressed_button=0; // pressed button on matrix keypad from 1 to 20, 0=no button pressed
  static long last_T; // used for giving some delay to mouse movement
  
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
        // zoom in
        zoomfit=true; // reset encoder click behaviour
        Keyboard.press(KEYPAD_ADD); // + on numeric keypad
        delay(100);
        Keyboard.releaseAll();      
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
        // zoom out
        zoomfit=true; // reset encoder click behaviour
        Keyboard.press(KEYPAD_SUBTRACT);
        delay(100);
        Keyboard.releaseAll();      
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
  switch (pb)
    {
    case 1:
      // Save As
      Keyboard.press(CONTROL); 
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('s'); 
      break;

    case 2:
      // Undo
      Keyboard.press(CONTROL); 
      Keyboard.press('z'); 
      break;

    case 3:
      // rectangle
      Keyboard.press('r'); 
      break;

    case 4:
      // ellipse
      Keyboard.press('e'); 
      break;

    case 5:
      // Polygon and stars
      Keyboard.press(KEYPAD_MULTIPLY); 
      break;

    case 6:
      // selector
      Keyboard.press(KEY_F1); 
      break;

    case 7:
      // Node selector
      Keyboard.press(KEY_F2); 
      break;

    case 8:
      // Lines
      Keyboard.press('b');
      break;

    case 9:
      // Handree Lines
      Keyboard.press('p');
      break;

    case 10:
      // Text
      Keyboard.press('t');
      break;

    case 11:
      // Dropper
      Keyboard.press('d');
      break;

    case 12:
      // Bucket
      Keyboard.press('u');
      break;

    case 13:
      // Eraser
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('e');
      break;

    case 14:
      // Ruler
      Keyboard.press('m');
      break;

    case 15:
      // empty
      //Keyboard.press('');
      break;

    case 16:
      // Resize page
      Keyboard.press(CONTROL); 
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press('r'); 
      break;

    case 17:
      // Align and distribute
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(CONTROL); 
      Keyboard.press('a'); 
      break;

    case 18:
      // Fill and stroke
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(CONTROL); 
      Keyboard.press('f'); 
      break;

    case 19:
      // PNG export
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(CONTROL); 
      Keyboard.press('e'); 
      break;

    case 20:
      // Toggle windows
      Keyboard.press(KEY_F12);
      break;

    default:
       return;
      break;
    }

  delay(50);
  Keyboard.releaseAll();
  return;
  }

// click on encoder button
void do_encoder_button_stuff(void)
  {
  if (zoomfit)
    {
    Keyboard.press('5'); // fit
    }
  else
    {
    Keyboard.press('1'); // 100%  
    }
  zoomfit^=1; // invert
  delay(50);
  Keyboard.releaseAll();
  }

// click on thumbstick button
void do_thumbstick_button_stuff(void)
  {
  // toggle fullscreen
  Keyboard.press(CONTROL);
  Keyboard.press('4');
  delay(50);
  Keyboard.releaseAll(); 
  }

// movement of thumbstick axis
void do_thumbstick_analog_stuff(uint16_t x, uint16_t y)
  {
  int8_t dx=0;
  int8_t dy=0;

  // we'll use the analog joystick as a digital joystick
  // so I set a deadband and I'll check only the movement direction, not the movement amount
  if (x>620) dx=-1; // move left 
  else if (x<380) dx=1; // move right
  if (y>620) dy=-1; // move up
  else if (y<380) dy=1; // move down

  if (dx==-1) // left
    {
    Keyboard.press(KEY_LEFT_SHIFT);
    Mouse.move(0,0,1); // x,y, scroll up
    delay(80);
    Keyboard.releaseAll();   
    }
  else if (dx==1) // right
    {
    Keyboard.press(KEY_LEFT_SHIFT);
    Mouse.move(0,0,-1); // x,y, scroll down
    delay(80);
    Keyboard.releaseAll();   
    }      
 if (dy==-1) // up
    {    
    Mouse.move(0,0,1); // x,y, scroll up    
    delay(80);
    }
  else if (dy==1) // down
    {    
    Mouse.move(0,0,-1); // x,y, scroll down
    delay(80);
    }       
   }
