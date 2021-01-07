### Photoshop

You can use this sketch for Photoshop. I've put my favourite commands, you can change the sketch for implementing what you want

#### Configuration

ENCODER
- Clockwise Rotation: Zoom IN (CTRL +)
- Counter-Clockwise Rotation: Zoom OUT (CTRL -)
- Button: Alternate between Zoom Fit (CTRL 0) / Zoom 100% (CTRL 1)

THUMBSTICK
- X axis: PAN Left/Right (SHIFT CTRL PGUP/SHIFT CTRL PGDN)
- Y axis: PAN up/down (SHIFT PGUP/SHIFT PGDN)
- Button: Change screen Mode (toggle fullscreen) (F)

ROW 1
- Button 1: Save As (CTRL SHIFT S)
- Button 2: Undo (CTRL ALT Z)
- Button 3: Show the INFO window (F8) (useful because give the pointer coordinates)
- Button 4: Resize (CTRL ALT I)
- Button 5: Change Canvas size (CTRL ALT C)

ROW 2
- Button 6: Alternate between Normal and Precision CrossHair (CAPS/LOCK)
- Button 7: Pointer/move (V)
- Button 8: Switch Between Rapid Selection/Magic Wand (SHIFT W)
- Button 9: Rectangular Select (M)
- Button 10: Switch Between Lasso types (SHIFT L)

ROW 3
- Button 11: Crop (C)
- Button 12: Eraser (e)
- Button 13: Switch Between Brush/Pencil/Color change/Mix Color (SHIFT B)
- Button 14: Horizontal Text (t)
- Button 15: Switch Background and Foreground colors (x)

ROW 4
- Button 16: Invert (CTRL I)
- Button 17: Black and White (CTRL ALT SHIFT B)
- Button 18: Color balance (CTRL B)
- Button 19: Brush window (F5)
- Button 20: Show/Hide Grid (CTRL ,)

### Notes
- Removing the comment at row `#define MAC` will make the program use the Mac key <kbd>⌘</kbd> instead of the Windows/Linux <kbd>LEFT CTRL</kbd> where CTRL or ⌘ are required. I don't have a MAC so those functions are untested for the MAC.
- Instead of the ALT on MAC is used the <kbd>OPTION</kbd> button. I didn't found this button in the library, maybe the is the same of ALT?
- Every click on the encoder button alternate between Zoom Fit (adapt image to the monitor) and Zoom 100% (real dimensions). After a zoom command the first press of encoder will be resetted to Zoom fit (flag `zoomfit`).
