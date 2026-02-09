/*
 * Guitar Hero + HW504 Joystick HID Controller
 * Created by BatuBey5G
 */
#include <ModernHIDKeyboard.h>
ModernHIDKeyboard keyboard;

/// ===== GH BUTTONS =====
const int buttonPins[5] = {2, 3, 4, 5, 6};
const uint8_t keyMap[5] = {
  'a', // green
  's', // red
  'j', // yellow
  'k', // blue
  'l'  // orange
};
int lastButtonState[5];

/// ===== JOYSTICK =====
const int joyXPin = A0;
const int joyYPin = A1;
const int joyClickPin = 7;
int lastJoyDir = 0; // 0 none, 1 up, 2 down, 3 left, 4 right
int lastJoyClickState = HIGH;
const int centerMin = 400;
const int centerMax = 600;
unsigned long startTime;

void setup() {
  keyboard.begin();
  
  for (int i = 0; i < 5; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    lastButtonState[i] = HIGH;
  }
  
  pinMode(joyClickPin, INPUT_PULLUP);
  startTime = millis();
}

void loop() {
  handleButtons();
  handleJoystick();
  delay(5);
}

void handleButtons() {
  for (int i = 0; i < 5; i++) {
    int s = digitalRead(buttonPins[i]);
    if (s != lastButtonState[i]) {
      if (s == LOW) {
        keyboard.pressKey(keyMap[i]);
      } else {
        keyboard.releaseKey(keyMap[i]);
      }
      lastButtonState[i] = s;
    }
  }
}

void handleJoystick() {
  // startup floating ADC ignore
  if (millis() - startTime < 1000) return;
  
  // ORIENTATION FIX (axes swapped)
  int y = analogRead(joyXPin); // UP / DOWN
  int x = analogRead(joyYPin); // LEFT / RIGHT
  
  int dir = 0;
  if (y < centerMin) dir = 1;       // UP
  else if (y > centerMax) dir = 2;  // DOWN
  else if (x < centerMin) dir = 3;  // LEFT
  else if (x > centerMax) dir = 4;  // RIGHT
  
  if (dir != lastJoyDir) {
    // release old direction - FIXED: use releaseSpecialKey!
    if (lastJoyDir == 1) keyboard.releaseSpecialKey(UPARROW);
    if (lastJoyDir == 2) keyboard.releaseSpecialKey(DOWNARROW);
    if (lastJoyDir == 3) keyboard.releaseSpecialKey(LEFTARROW);
    if (lastJoyDir == 4) keyboard.releaseSpecialKey(RIGHTARROW);
    
    // press direction
    if (dir == 1) keyboard.pressSpecialKey(UPARROW);
    if (dir == 2) keyboard.pressSpecialKey(DOWNARROW);
    if (dir == 3) keyboard.pressSpecialKey(LEFTARROW);
    if (dir == 4) keyboard.pressSpecialKey(RIGHTARROW);
    
    lastJoyDir = dir;
  }
  
  // Joystick click = ENTER
  int clickState = digitalRead(joyClickPin);
  if (clickState != lastJoyClickState) {
    if (clickState == LOW) {
      keyboard.pressSpecialKey(ENTER);
    } else {
      keyboard.releaseSpecialKey(ENTER);
    }
    lastJoyClickState = clickState;
  }
}
