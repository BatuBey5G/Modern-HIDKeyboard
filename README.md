# Modern-HIDKeyboard

Bu kütüphane, Arduino Uno kartlarını klavye olarak kullanan projelerdeki "aynı anda tuşa basamama" sorununu çözmek için geliştirilmiştir.

## Neden Bu Kütüphane?
Standart kütüphaneler genellikle her yeni tuş basımında eskisini siler. **Modern-HIDKeyboard** ise:
- **6-Key Rollover:** Aynı anda 6 tuşu basılı tutabilir.

Bu kadar. diğerlerinden başka özelliği yok.

## Nasıl Kullanılır?
1. Atmel Flip uygulamasını indirin.
2. Bu iki pini kısa devre yapın. <img width="912" height="490" alt="image" src="https://github.com/user-attachments/assets/4bef37d9-2aec-4194-81ce-6cac10da9b95" />
3. Sol üstteki çip resmine tıklayın ve ATMEGA16u2 Çipini seçip OK'e basın. Eğer DFU işlemini doğru yaptıysanız en üstte çıkar.
4. CTRL+U yapıp Open tuşuna tıklayın.
5. Sol üstteki "File" tuşuna basıp "Load hex file" tuşuna basın. buradan yüklemek istediğiniz hex dosyasını seçin. Arduino-usbserial-uno.hex: normale çevirmek için. usb-keyboard-03.hex: Klavye moduna çevirmek için.
6. hiçbir ayara dokunmadan "Run" Tuşuna basın. 2-3 saniye sürecek ve en altta "Verify PASS" diyecek.
7. USB kablosunu çıkarıp takın. artık bilgisayarınız bir daha bu işlemi yapıp arduino-usbserial-uno.hex dosyasını yükleyene kadar arduino uno kartınızı klavye olarak görecek. 

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
