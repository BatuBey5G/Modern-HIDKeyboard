#ifndef ModernHIDKeyboard_h
#define ModernHIDKeyboard_h

#include "Arduino.h"

// Gerçek USB HID Klavye Kodları (Linux, Windows, Mac uyumlu)
#define ENTER 0x28
#define ESCAPE 0x29
#define BACKSPACE 0x2A
#define TAB 0x2B
#define SPACEBAR 0x2C
#define RIGHTARROW 0x4F
#define LEFTARROW 0x50
#define DOWNARROW 0x51
#define UPARROW 0x52
#define SHIFT 0x02

class ModernHIDKeyboard {
  public:
    ModernHIDKeyboard();
    void begin();
    
    void pressKey(uint8_t key);
    void pressKey(uint8_t modifier, uint8_t key);
    void releaseKey(uint8_t key);
    
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
