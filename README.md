# Makropad

A minimalistic makropad featuring a 4x4 grid of keys, two rotary encoders and a 128x32 OLED display. 


![render of the makropad](/images/render1.png)

You can put most makropad like keyboards in two categories:


Way too expensive and overbloated with useless features

or

An ok price but a ugly design (in my opinion)

That's what motivated me to make my own makropad. It's designed to be easily build, having just the right amount of features all while having a sleek minimalistic design.

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

  The ledmatrix
  ![image of the led matrix](/images/ledmatrix.png)
</details>

# First start

- By default the makropad will work like a standard keypad in the following format:

<kbd> 7 </kbd> <kbd> 8 </kbd> <kbd> 9 </kbd> <kbd> + </kbd>

<kbd> 4 </kbd> <kbd> 5 </kbd> <kbd> 6 </kbd> <kbd> - </kbd>

<kbd> 1 </kbd> <kbd> 2 </kbd> <kbd> 3 </kbd> <kbd> * </kbd>

<kbd> 0 </kbd> <kbd> . </kbd> <kbd> / </kbd> <kbd> ↵ </kbd>

- You can either just compile and flash the firmware with QMK toolbox or choose to customize the code further to your needs
- By customizing the QMK files you can make it your own