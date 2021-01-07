# KeyBoh

![image](./media/keyboh_16_9.jpg)

KeyBoh is an Arduino Leonardo shield for making customizable, cheap, USB keyboards. We love to use the [NicoHood HID Project library](https://github.com/NicoHood/HID) for interfacing the whole thing to a Computer. It's very cheap because uses commonly available 12x12 tactile switches.

## PCB  
Making the PCB on PCBWay will support our work. You need to subscribe to PCBWay first using [this invite link](https://www.pcbway.com/setinvite.aspx?inviteid=355653&from=settorezero2020). 
Once subscribed to PCBWay you can let them make you the PCB [from the shared project page](https://www.pcbway.com/project/shareproject/KeyBoh_Shield.html)

## Enclosure
In the [STL folder](./stl) are located the two panels you can 3Dprint by yourself. Then you can assemble the Keyboh as showed in the pictures using 4x 24mm F/F  and 4x M/F 6mm hex spacers + 12x M3 6mm screws and 4 3M bolts.

## Code examples
See in the [Arduino folder](./arduino) for code examples. We're currently working to a multi-predefined configurable keyset for various applications, so stay tuned.  

## Informations
See the [NicoHood HID Project library](https://github.com/NicoHood/HID) for knowing how library works and example.
In the [keys.txt](./docs/keys.txt) document are reported the names for the keys of the keyboard as used by NicoHood library.

## Connection table
(To do)
In the meanwhile look at schematic in the [docs folder](./docs)

## Can I use keyboh with other boards?
Keyboh is designed for the Arduino __Leonardo__ using his own USB features for making USB devices you can use on the computer or any device recognizes HID devices (even if on cellphone).

### Keyboh on Arduino UNO ?
You can use Keyboh on the Arduino UNO if you want to control remote devices through the UART: you can connect an external device simply connecting the UART using wires or you can attach a Bluetooth or an XBee module, or an ESP8266 but be always aware of the voltage levels! There is the possibility to have a voltage divider only on the Arduino RX but connecting an ESP8266 requires a voltage divider on the TX.  

You can use Keyboh on the Arduino UNO also for USB communication using the [HoodLoader by NicoHood](https://github.com/NicoHood/HoodLoader2). This project is made for reprogramming the 16U2, used on the UNO as serial/USB bridge, and use it for USB custom purposes. We've still not used that feature so please read the documentation of this library.

Since the Leonardo has separate `SDA` and `SCL` lines while the UNO has `SDA` and `SCL` shared with `A4` and `A5`, using the shield on the UNO will make not available I2C lines, or you may not use the joystick (connected to A4 and A5) freeing those two pins for using them for I2C.  

### Keyboh on other boards
You can use the shield on other development boards connecting wires on pads: the silkscreen will help a lot.  
You can also saw off the PCB part with encoder and joystick: a part of soldering pads will be anyway available for reconnecting the two separate pcbs or for connecting them through wires.

## Warnings!!
Since keymatrix is implemented __without protection diodes on pushbuttons__, is no safe press more than 1 button on the same row at a time: this bring to a momentary short-circuit since 2 or more columns are connected together. Usually this is not a big problem since the duration of the short is very small due to column scan, but is better not doing this. In the next revision we'll add the protection diodes.

## Improvements
The encoder software debounce has still some issues, it will be better implement an hardware debounce too. [This webpage](https://www.best-microcontroller-projects.com/rotary-encoder.html) has interesting disquisition about encoder debouncing.
In the meanwhile you can solder 2 small 10pF ceramic capacitors at place of `R3` and `R4` for improving the encoder response. Those resistor were tought for implementing pull-up in devices that has no the GPIO PullUp feature, on Arduino are not needed since Arduino boards have pullups.

## Bad Coding leads to problems!
First of all: Always remember to put a `Keyboard.releaseALL()` or `Keyboard.relese([KEY])` after `Keyboard.press` instructions or the keys will remain pressed forever causing a lot of problems!

A very big problem is this: you write some wrong instructions so the keyboard cycles some keys indefinitely (ore some keys are always pressed) and then, since those keys affects the Arduino IDE functions, you may be not able to reprogram the board. In this case a thing you can do is detach the Arduino Leonardo, then see in the Control Panel which devices are connected, then you attach the Leonardo and you will see new devices (example: _HID Keyboard_), in the panel you can try to disinstall the new device (<kbd>Mouse right click</kbd> - <kbd>Uninstall</kbd>) but you need to do this very fast.

In worst cases you can reprogram the Leonardo with a clean sketch on the ISP connector using another Arduino as ISP programmer.

Another problem can be _board not recognized_ from Arduino IDE even if the board is working and the selected serial port is right. In this case try to disconnect and reconnect the USB cable or pressing the Leonardo <kbd>reset</kbd> button after you've pressed the IDE button for the sketch upload.

## Notes for an ipothetical next PCB revision
- Add protection diodes on keymatrix switches
- Add circuitry for hardware debounce, on the encoder mainly
- Add voltage divider also on UART TX
- Use the Arduino micro instead of Leonardo (more compact) ?

## Links
- [more pictures of KeyBoh](https://photos.app.goo.gl/CL2jDvoLArWxuAqx8)

## Sharings
Since we love when others share our projects, here are linked pages who shared the project.  
Those links can be useful since people make also questions commenting on social posts and we try to give answers directly.

- [Arduino on IG](https://www.instagram.com/p/CIPJXs_j-tg/)
- [Arduino on TW](https://twitter.com/arduino/status/1333078330598363136)
- [Arduino on FB](https://www.facebook.com/official.arduino/posts/5567229216636685)
- [PCBWay on IG](https://www.instagram.com/p/CINa9Nnra6t/)
- [PCBWay on TW](https://twitter.com/PCBWayOfficial/status/1333344888537026561)
- [Microchip on IG](https://www.instagram.com/p/CIRuX1qnB_U/)
- [Microchip on TW](https://twitter.com/MicrochipMakes/status/1333442492117737475)
- [Microchip on FB](https://www.facebook.com/MicrochipMakes/posts/3820599841292022)
- [Hackster](https://www.hackster.io/news/keyboh-is-an-open-source-arduino-leonardo-shield-for-making-custom-usb-keyboards-208a930cc3f5)
