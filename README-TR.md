# Modern-HIDKeyboard

Bu kütüphane, Arduino Uno kartlarını klavye olarak kullanan projelerdeki aynı anda tuşa basamama sorununu çözmek için geliştirilmiştir.

## Neden Bu Kütüphane?
Standart kütüphaneler genellikle her yeni tuş basımında eskisini siler. **Modern-HIDKeyboard** ise:
- **6-Key Rollover:** Aynı anda 6 tuşu basılı tutabilir.
- **Kodda Hata Düzeltmeleri:** Koddaki hatalar düzeltildi.
- **Klavye Input Method Değiştirme:** Bu özellik üzerinde çalışıyorum, ileride eklenebilir.

## Nasıl Kullanılır?

> [!WARNING]
> Bu işlem tüm orijinal Arduino Uno’larda çalışır ancak birçok klon Uno’da çalışmaz.
> Eğer USB portuna yakın 6 pin yoksa bu işlemi yapamazsınız.

.ino dosyanızı karta yükledikten sonra:

### Windows
1. Atmel Flip uygulamasını indirin.
2. Bu iki pini kısa devre yapın. (DFU modu)
3. Sol üstteki çip ikonuna basıp **ATMEGA16U2** seçin.
4. CTRL+U → Open
5. File → Load hex file → `Arduino-keyboard-0.3.hex`
6. Ayarlara dokunmadan **Run**'a tıklayın.
7. USB’yi çıkar tak, artık klavye.

Geri almak için `Arduino-usbserial-uno.hex` yükleyin.

### Linux
1. dfu-programmer kurun  
   `sudo pacman -S dfu-programmer` veya `sudo apt install dfu-programmer`
2. Kartı DFU moduna alın
3. `sudo dfu-programmer atmega16u2 get`
4. `sudo dfu-programmer atmega16u2 erase`
5. `sudo dfu-programmer atmega16u2 flash Arduino-keyboard-0.3.hex`
6. `sudo dfu-programmer atmega16u2 reset`
7. USB'yi çıkar tak, artık klavye.

Geri almak için `Arduino-usbserial-uno.hex` yükleyin.

## Kod Örneği

```cpp
#include <ModernHIDKeyboard.h>

ModernHIDKeyboard keyboard;

void setup() {
  keyboard.begin();
}

void loop() {
  keyboard.pressKey('a');
  keyboard.pressKey('s');
  delay(1000);
  keyboard.releaseKey('a');
}
```
