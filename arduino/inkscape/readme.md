### Functions for Inkscape

You can use this sketch for controlling [Inkscape](https://inkscape.org/).  
I've put my favourite commands, you can change the sketch for implementing what you want.  
All Inkscape commands, shortcuts and functions are [listed here](https://inkscape.org/sk/doc/keys.html).

#### Configuration

ENCODER
- <kbd>Clockwise Rotation</kbd>: Zoom IN (+)
- <kbd>Counter-Clockwise Rotation</kbd>: Zoom OUT (-)
- <kbd>Button</kbd>: Alternate between Zoom Fit (5) / Zoom 100% (1)

> Some people complains about they cannot write <kbd>+</kbd> and <kbd>-</kbd> in the Text areas because those keys are associated with the zoom function and so by pressing them the zoom changes and no signs are written.  
The key associated with the zoom functions are <kbd>+</kbd> and <kbd>-</kbd> located on the Numeric Keypad! The <kbd>+</kbd> and <kbd>-</kbd> on the keyboard (<kbd>+</kbd> on the same key where are located also <kbd>*]}</kbd> and <kbd>+</kbd> on the same key where is located the <kbd>underscore</kbd>) don't affect the zoom function.

THUMBSTICK 
- <kbd>X axis</kbd>: PAN Left/Right (SHIFT Mouse SCRLDN / SHIFT Mouse SCRLUP)
- <kbd>Y axis</kbd>: PAN up/down (Mouse SCRLUP/Mouse SCRLDN)
- <kbd>Button</kbd>: Go to page center without changing zoom (CTRL 4)

ROW 1
- <kbd>Button 1</kbd>: Save As (CTRL SHIFT s)
- <kbd>Button 2</kbd>: Undo (CTRL z)
- <kbd>Button 3</kbd>: Create Rectangle (r)
- <kbd>Button 4</kbd>: Create Ellipses (e)
- <kbd>Button 5</kbd>: Create Poligon and Stars (KEYPAD *)

ROW 2
- <kbd>Button 6</kbd>: Arrow (selector) (F1)
- <kbd>Button 7</kbd>: Node Selector (F2)
- <kbd>Button 8</kbd>: Draw Lines (b)
- <kbd>Button 9</kbd>: Draw Hand-free lines (p)
- <kbd>Button 10</kbd>: Insert Text (t)

ROW 3
- <kbd>Button 11</kbd>: Dropper (d)
- <kbd>Button 12</kbd>: Paint Bucket (u)
- <kbd>Button 13</kbd>: Eraser (SHIFT e)
- <kbd>Button 14</kbd>: Ruler (m)
- <kbd>Button 15</kbd>: 

ROW 4
- <kbd>Button 16</kbd>: Resize page to current selection, or to the drawing if nothing is selected (SHIFT CTRL r)
- <kbd>Button 17</kbd>: Open the window Align and Distribute (SHIFT CTRL a)
- <kbd>Button 18</kbd>: Open the window Fill and Stroke (SHIFT CTRL f)
- <kbd>Button 19</kbd>: Export to PNG (SHIFT CTRL e)
- <kbd>Button 20</kbd>: Toggle Windows (F12)

### Notes
- Every click on the encoder button alternate between Zoom Fit (adapt image to the monitor) and Zoom 100% (real dimensions). After a zoom command the first press of encoder will be resetted to Zoom fit (flag `zoomfit`).
