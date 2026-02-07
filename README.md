# Modern-HIDKeyboard

Bu kütüphane, Arduino Uno kartlarını klavye olarak kullanan projelerdeki aynı anda tuşa basamama sorununu çözmek için geliştirilmiştir.

## Neden Bu Kütüphane?
Standart kütüphaneler genellikle her yeni tuş basımında eskisini siler. **Modern-HIDKeyboard** ise:
- **6-Key Rollover:** Aynı anda 6 tuşu basılı tutabilir.
- **Kodda Hata Düzeltmeleri:** Koddaki hatalar düzeltildi.
- **Klavye Input Method Değiştirme:** Bu özellik üzerinde çalışıyorum, ileride eklenebilir.

## Nasıl Kullanılır?

> [!WARNING]
> Bu işlem tüm Orijinal uno'larda çalışır ancak birçok Klon Uno'da çalışmaz. eğer USB portuna yakında 6 tane pin görmüyorsanız yapamazsınız.

.ino dosyanızı karta yükledikten sonra:

### Windows
1. Atmel Flip uygulamasını indirin.
2. Bu iki pini kısa devre yapın. Bu işlem cihazı DFU moduna sokacak. <img width="912" height="490" alt="image" src="https://github.com/user-attachments/assets/4bef37d9-2aec-4194-81ce-6cac10da9b95" />
3. Sol üstteki çip resmine tıklayın ve ATMEGA16u2 Çipini seçip OK'e basın. Eğer DFU işlemini doğru yaptıysanız en üstte çıkar.
4. CTRL+U yapıp Open tuşuna tıklayın.
5. Sol üstteki "File" tuşuna basıp "Load hex file" tuşuna basın. buradan `Arduino-keyboard-0.3.hex` dosyasını seçin.
6. hiçbir ayara dokunmadan "Run" Tuşuna basın. 2-3 saniye sürecek ve en altta "Verify PASS" diyecek.
7. USB kablosunu çıkarıp takın. artık bilgisayarınız Uno kartınızı Klavye olarak görecek ve .ino dosyanızdaki tuşlara basacak. geri almak için Atmel Flip uygulamasını kullanarak Arduino-usbserial-uno.hex dosyasını yükleyin.
### Linux
Linux'ta işlem çok daha kolay. 
1. dfu-programmer yazılımını indirin. paket yöneticinize göre: `sudo apt install dfu-programmer` veya `sudo pacman -S dfu-programmer` vs. yazmanız gerekir.
2. Bu iki pini kısa devre yapın. Bu işlem cihazı DFU moduna sokacak. <img width="912" height="490" alt="image" src="https://github.com/user-attachments/assets/4bef37d9-2aec-4194-81ce-6cac10da9b95" />
3. terminal penceresine `sudo dfu-programmer atmega16u2 get` yazın. eğer "no device present" görürseniz DFU moduna doğru almadınız veya kartınız bilgisayara düzgün bağlı değil.
4. Firmware yazmadan önce sıfırlamak gerekli. `sudo dfu-programmer atmega16u2 erase` komuduyla çipi sıfırlayın.
5. Klavye yazılımını çipe yazmak için `sudo dfu-programmer atmega16u2 flash Arduino-keyboard-0.3.hex` yazın. Bu komudun çalışması için HEX dosyalarının olduğu klasörde olmanız gerekir.
6. Son olarak `sudo dfu-programmer atmega16u2 reset` yazın. 
7. İşlem tamamlanınca Uno'nuzu çıkarıp takın, Klavye gibi davranacak. Eski haline dönmek için 5.adımda "Arduino-keyboard-0.3.hex" yerine "Arduino-usbserial-uno.hex" yazın.

## Kod Örneği

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

```
