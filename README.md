# Modern-HIDKeyboard

Bu kütüphane, Arduino Uno kartlarını klavye olarak kullanan projelerdeki "aynı anda tuşa basamama" sorununu çözmek için geliştirilmiştir.

## Neden Bu Kütüphane?
Standart kütüphaneler genellikle her yeni tuş basımında eskisini siler. **Modern-HIDKeyboard** ise:
- **6-Key Rollover:** Aynı anda 6 tuşu basılı tutabilir.

Bu kadar. diğerlerinden başka özelliği yok.

## Nasıl Kullanılır?
```cpp
#include <ModernHIDKeyboard.h>

ModernHIDKeyboard keyboard;

void setup() {
  keyboard.begin();
}

void loop() {
  // A ve S tuşlarına aynı anda bas!
  keyboard.pressKey('a');
  keyboard.pressKey('s');
  
  delay(1000);
  
  // Sadece A'yı bırak, S basılı kalsın
  keyboard.releaseKey('a');
}
