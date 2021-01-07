### Photoshop

You can use this sketch for Photoshop. I've put my favourite commands, you can change the sketch for implementing what you want

#### Configuration

ENCODER
- <kbd>Clockwise Rotation</kbd>: Zoom IN (CTRL +)
- <kbd>Counter-Clockwise Rotation</kbd>: Zoom OUT (CTRL -)
- <kbd>Button</kbd>: Alternate between Zoom Fit (CTRL 0) / Zoom 100% (CTRL 1)
>  These same commands are used also in a lot of other programs such as web browsers

THUMBSTICK 
- <kbd>X axis</kbd>: PAN Left/Right (SHIFT CTRL PGUP / SHIFT CTRL PGDN)
- <kbd>Y axis</kbd>: PAN up/down (SHIFT PGUP/SHIFT PGDN)
- <kbd>Button: Change screen Mode (toggle fullscreen) (F)

ROW 1
- <kbd>Button 1</kbd>: Save As (CTRL SHIFT S)
- <kbd>Button 2</kbd>: Undo (CTRL ALT Z)
- <kbd>Button 3</kbd>: Show the INFO window (F8) (useful because give the pointer coordinates)
- <kbd>Button 4</kbd>: Resize (CTRL ALT I)
- <kbd>Button 5</kbd>: Change Canvas size (CTRL ALT C)

ROW 2
- <kbd>Button 6</kbd>: Alternate between Normal and Precision CrossHair (CAPS/LOCK)
- <kbd>Button 7</kbd>: Pointer/move (V)
- <kbd>Button 8</kbd>: Switch Between Rapid Selection/Magic Wand (SHIFT W)
- <kbd>Button 9</kbd>: Rectangular Select (M)
- <kbd>Button 10</kbd>: Switch Between Lasso types (SHIFT L)

ROW 3
- <kbd>Button 11</kbd>: Crop (C)
- <kbd>Button 12</kbd>: Eraser (E)
- <kbd>Button 13</kbd>: Switch Between Brush/Pencil/Color change/Mix Color (SHIFT B)
- <kbd>Button 14</kbd>: Horizontal Text (T)
- <kbd>Button 15</kbd>: Switch Background and Foreground colors (X)

ROW 4
- <kbd>Button 16</kbd>: Invert (CTRL I)
- <kbd>Button 17</kbd>: Black and White (CTRL ALT SHIFT B)
- <kbd>Button 18</kbd>: Color balance (CTRL B)
- <kbd>Button 19</kbd>: Brush window (F5)
- <kbd>Button 20</kbd>: Show/Hide Grid (CTRL ,)

### Notes
- Removing the comment at row `#define MAC` will make the program use the Mac key <kbd>⌘</kbd> instead of the Windows/Linux <kbd>LEFT CTRL</kbd> where CTRL or ⌘ are required. I don't have a MAC so those functions are untested for the MAC.
- Instead of the ALT on MAC is used the <kbd>OPTION</kbd> button. I didn't found this button in the library, maybe the is the same of ALT?
- Every click on the encoder button alternate between Zoom Fit (adapt image to the monitor) and Zoom 100% (real dimensions). After a zoom command the first press of encoder will be resetted to Zoom fit (flag `zoomfit`).
