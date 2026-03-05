# Makropad

A minimalistic makropad featuring a 4x4 grid of keys, two rotary encoders and a 128x32 OLED display. 
![render of the makropad](/images/render1.png)

# Features

- Arduino Pro Micro MCU (ATmega32u4)
- Two customizable rotary encoders
- A 128x32 OLED that displays helpful information
- Custom shortcuts for any program (with QMK)
- Power via USB-C
- Sleek minimalist case optimised for CNC milling and 3D printing
- Hot swap switches

# First start

- By default the makropad will work like a standard keypad in the following format:
'''
 ________
|7|8|9|+ |
 ________
|4|5|6|- |
 ________
|1|2|3|+ |
 ________
|0|.|/|↵ |
 ‾‾‾‾‾‾‾‾
'''