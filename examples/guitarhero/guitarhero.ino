/*
 * Modern-HIDKeyboard - Guitar Hero Controller Example
 * Created by BatuBey5G
 * * Bu örnek, 5 butonlu bir Guitar Hero kontrolcüsü için optimize edilmiştir.
 * Aynı anda birden fazla notaya (Chord) basmayı destekler.
 */

#include <ModernHIDKeyboard.h>

ModernHIDKeyboard keyboard;

// Buton Pinleri (GND ile buton arasına bağlayın)
const int buttonPins[5] = {2, 3, 4, 5, 6};

// Klavye Karşılıkları (Oyun ayarlarına göre değiştirilebilir)
const char keyMap[5] = {'a', 's', 'j', 'k', 'l'}; 

int lastState[5];

void setup() {
  // Kütüphaneyi başlat (9600 baud hızında çalışır)
  keyboard.begin();

  for (int i = 0; i < 5; i++) {
    // Dahili Pull-up dirençlerini aktif ediyoruz
    pinMode(buttonPins[i], INPUT_PULLUP);
    lastState[i] = HIGH; // Başlangıçta butonlar basılı değil
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int currentState = digitalRead(buttonPins[i]);

    // Buton durumunda değişiklik var mı?
    if (currentState != lastState[i]) {
      if (currentState == LOW) {
        // Butona basıldı
        keyboard.pressKey(keyMap[i]);
      } else {
        // Buton bırakıldı
        keyboard.releaseKey(keyMap[i]);
      }
      lastState[i] = currentState;
    }
  }
  
  // 5ms gecikme: Hem hızlı tepki hem de buton arkı (bounce) önleme
  delay(5);
}
