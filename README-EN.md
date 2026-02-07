# Modern-HIDKeyboard

This library was developed to fix the limitation of Arduino Uno projects where multiple keys cannot be pressed at the same time.

## Why This Library?
Standard keyboard libraries overwrite previous key presses. **Modern-HIDKeyboard** provides:
- **6-Key Rollover:** Hold up to 6 keys simultaneously
- **Bug Fixes:** Cleaned and fixed internal logic
- **Input Method Switching:** Planned feature

## How to Use
> [!WARNING]
> Works on original Arduino Uno boards.
> Most clone boards do NOT support this (missing 16u2 pins).

After uploading your `.ino` file:

### Windows
1. Install Atmel Flip
2. Short the two pins to enter DFU mode
3. Select **ATMEGA16U2**
4. CTRL+U → Open
5. File → Load hex → `Arduino-keyboard-0.3.hex`
6. Press **Run**
7. Replug USB, Uno now acts as a keyboard

To revert, flash `Arduino-usbserial-uno.hex`.

### Linux
1. Install dfu-programmer  
   `sudo pacman -S dfu-programmer` or `sudo apt install dfu-programmer`
2. Enter DFU mode
3. `sudo dfu-programmer atmega16u2 get`
4. `sudo dfu-programmer atmega16u2 erase`
5. `sudo dfu-programmer atmega16u2 flash Arduino-keyboard-0.3.hex`
6. `sudo dfu-programmer atmega16u2 reset`

## Code Example

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
