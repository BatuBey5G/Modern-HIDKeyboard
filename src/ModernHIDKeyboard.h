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

// HID Values - Bu değerler direkt USB tarama kodlarıdır (Scan Codes)
#define ENTER 0x28
#define ESCAPE 0x29
#define BACKSPACE 0x2a
#define TAB 0x2b
#define SPACEBAR 0x2c
#define RIGHTARROW 0x4f
#define LEFTARROW 0x50 
#define DOWNARROW 0x51
#define UPARROW 0x52
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
