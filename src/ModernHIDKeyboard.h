/*
* Modern-HIDKeyboard (6-Key Rollover Version)
* Created and Modified by BatuBey5G - 2026
* Based on the original HIDKeyboard library by Chris Taylor (SparkFun Electronics).
* Updated to support simultaneous key presses (Multi-key) and individual key releases.
* Original License: Beerware.
*/

#ifndef ModernHIDKeyboard_h
#define ModernHIDKeyboard_h

#include "Arduino.h"

// HID Values - Arduino Keyboard Library değerleri
#define ENTER 0xB0
#define ESCAPE 0xB1
#define BACKSPACE 0xB2
#define TAB 0xB3
#define SPACEBAR 0x20
#define RIGHTARROW 0xD7
#define LEFTARROW 0xD8
#define DOWNARROW 0xD9
#define UPARROW 0xDA
#define SHIFT 0x02

class ModernHIDKeyboard {
  public:
    ModernHIDKeyboard();
    void begin();
    
    // Normal karakterler için (a, s, d, 1, 2, 3...)
    void pressKey(uint8_t key);
    void pressKey(uint8_t modifier, uint8_t key);
    void releaseKey(uint8_t key);
    
    // Özel tuşlar için (Oklar, Enter, Tab vb.)
    void pressSpecialKey(uint8_t specialKey);
    void pressSpecialKey(uint8_t modifier, uint8_t specialKey);
    void releaseSpecialKey(uint8_t specialKey);
    
    void releaseAll();
    void print(char* sequence);
    void println(char* sequence);

  private:
    uint8_t buf[8]; 
    static const uint8_t HIDTable[];
    static const uint8_t modifierTable[];
};

#endif
