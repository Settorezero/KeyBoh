### Photoshop

[Work in progress] You can use this sketch for Photoshop.

#### Configuration

ENCODER
- Clockwise Rotation: Zoom IN (CTRL +)
- Counter-Clockwise Rotation: Zoom OUT (CTRL -)
- Button: Alternate between Zoom Fit (CTRL 0) / Zoom 100% (CTRL 1)

THUMBSTICK
- X axis: PAN Left/Right (SHIFT CTRL PGUP/SHIFT CTRL PGDN)
- Y axis: PAN up/down (SHIFT PGUP/SHIFT PGDN)
- Button: 

ROW 1
- Button 1: Show the INFO window (F8) (useful because give the pointer coordinates)
- Button 2: Alternate between Normal and Precision CrossHair (CAPS/LOCK)
- Button 3: Resize (CTRL ALT I)
- Button 4: Change Canvas size (CTRL ALT C)
- Button 5:

ROW 2
- Button 6:
- Button 7:
- Button 8:
- Button 9:
- Button 10:

ROW 3
- Button 11:
- Button 12:
- Button 13:
- Button 14:
- Button 15:

ROW 4
- Button 16: Invert (CTRL I)
- Button 17: Black and White (CTRL ALT SHIFT B)
- Button 18: Color balance (CTRL B)
- Button 19:
- Button 20:

### Notes
- Removing the comment `#define MAC` will make the program use the Mac key <kbd>⌘</kbd> instead of the Windows/Linux <kbd>LEFT CTRL</kbd>. I don't have a MAC so those functions are untested for the MAC.
- Instead of the ALT on MAC is used the <kbd>OPTION</kbd> button. I didn't found this button in the library, maybe the is the same of ALT, can anyone let me know?
- Every click on the encoder button alternate between Zoom Fit (adapt image to the monitor) and Zoom 100% (real dimensions). After a zoom command the first press of encoder will be resetted to Zoom fit (flag `zoomfit`).
