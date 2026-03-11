# Makropad

A minimalistic makropad featuring a 4x4 grid of keys, two rotary encoders and a 128x32 OLED display. 


![render of the makropad](/images/render1.png)

You can put most makropad-like keyboards in two categories:


Way too expensive and overbloated with useless features

or

An ok price but an ugly design (in my opinion)

That's what motivated me to make my own makropad. It's designed to be easily built, having just the right amount of features all while having a sleek minimalistic design.

# Features

- Arduino Pro Micro MCU (ATmega32u4)
- Two customizable rotary encoders
- A 128x32 OLED that displays helpful information
- Custom shortcuts for any program (with QMK)
- Power via USB-C
- Sleek minimalistic case optimised for CNC milling and 3D printing
- Hot swap switches

# PCB

The pcb layout

![screenshot of the pcb layout](/images/pcb.png)

<details>
  <summary> The schematics </summary>
  
  The MCU with the encoders and OLED

  ![image of mcu + encoders](/images/mcu+encoders.png)

  The switch matrix

  ![image of the switch matrix](/images/switchmatrix.png)

  The LED matrix

  ![image of the led matrix](/images/ledmatrix.png)
</details>

# First start

- By default the makropad will work like a standard numpad in the following format:

<kbd> 7 </kbd> <kbd> 8 </kbd> <kbd> 9 </kbd> <kbd> + </kbd>

<kbd> 4 </kbd> <kbd> 5 </kbd> <kbd> 6 </kbd> <kbd> - </kbd>

<kbd> 1 </kbd> <kbd> 2 </kbd> <kbd> 3 </kbd> <kbd> * </kbd>

<kbd> 0 </kbd> <kbd> . </kbd> <kbd> / </kbd> <kbd> ↵ </kbd>

- You can either just compile and flash the firmware with QMK toolbox or choose to customize the code further to your needs
- By customizing the QMK files you can make it your own

# BOM

This is an estimated cost:
| Product Name            | Product Description            | Product Link                                                                                              | Product Unit Cost in EUR   | Product Amount   |    Total in EUR |
|:------------------------|:-------------------------------|:----------------------------------------------------------------------------------------------------------|:---------------------------|:-----------------|----------------:|
| 1N4148WS                | Diode SOD-323                         | https://jlcpcb.com/partdetail/2485-1N4148WS/C2128                                                         | 0.0079                     | 16.0             |            0.13 |
| -                       | 128x32 OLED                    | https://www.amazon.de/-/en/gp/product/B07BDFXFRK                                                          | 4.5                        | 1.0              |            4.5  |
| WS2812B-V5/W            | LED 5050                    | https://jlcpcb.com/partdetail/Worldsemi-WS2812B_V5W/C2874885                                              | 0.09                       | 16.0             |            1.34 |
| RCA02330RJLF            | 330 Ohm resistor 0402          | https://jlcpcb.com/partdetail/23789673-RCA02330RJLF/C22356229                                             | 0.0003                     | 1.0              |            0    |
| CHERRY MX2A-71NN        | Cherry style keyboardswitch    | https://www.reichelt.de/de/de/shop/produkt/cherry_mx_silent_red_-_tastenmodul_-_schnappbefestigung-361531 | 0.75                       | 16.0             |           12    |
| -                       | EC11 Rotary encoder            | https://www.amazon.de/-/en/gp/product/B08728PS6N                                                          | 2.0                        | 2.0              |            4    |
| ARD PRO-MICRO-C         | Arduino Pro Micro (ATmega32u4) | https://www.reichelt.de/de/de/shop/produkt/arduino_-_mikrocontroller_atmega32u4_usb-c-421607              | 7.99                       | 1.0              |            7.99 |
| YMDK Kailh CPG151101S11 | Kailh Hotswap Sockets          | https://www.amazon.de/-/en/YMDK-CPG151101S11-Swappable-Mechanical-Keyboards/dp/B07K8CCMQZ                 | 0.16                       | 16.0             |            2.56 |
|                         |                                |                                                                                                           |                            |                  |           32.52 |
