# ebd: Eight Bit Dump
**A hexdump utility for 8 bit software development.**

An alternative to modern hexdump utilities, *ebd* is designed for anyone using modern systems to develop software for older 8 bit processors such as the 6502, Z80, etc.

Its style is inspired by the Apple II system monitor program and outputs 8 bit bytes with the option to show ASCII characters too. It is fixed to 8 bytes per row, with a 16 bit address which rolls over after each 64k. If you need more address space this probably isn't the tool for you.

## Usage
Pass a file to *ebd* and you'll get a hexdump of its contents:

`ebd [filename]`

```
0000: D8 58 A0 7F 8C 12 D0 A9 
0008: A7 8D 11 D0 8D 13 D0 C9 
0010: DF F0 13 C9 9B F0 03 C8 
0018: 10 0F A9 DC 20 EF FF A9 
0020: 8D 20 EF FF A0 01 88 30 
0028: F6 AD 11 D0 10 FB AD 10 
0030: D0 99 00 02 20 EF FF C9 
0038: 8D D0 D4 A0 FF A9 00 AA 
0040: 0A 85 2B C8 B9 00 02 C9 
0048: 8D F0 D4 C9 AE 90 F4 F0 
0050: F0 C9 BA F0 EB C9 D2 F0 
0058: 3B 86 28 86 29 84 2A B9 
0060: 00 02 49 B0 C9 0A 90 06 
0068: 69 88 C9 FA 90 11 0A 0A 
0070: 0A 0A A2 04 0A 26 28 26 
0078: 29 CA D0 F8 C8 D0 E0 C4 
0080: 2A F0 97 24 2B 50 10 A5 
0088: 28 81 26 E6 26 D0 B5 E6 
0090: 27 4C 44 FF 6C 24 00 30 
0098: 2B A2 02 B5 27 95 25 95 
00A0: 23 CA D0 F7 D0 14 A9 8D 
00A8: 20 EF FF A5 25 20 DC FF 
00B0: A5 24 20 DC FF A9 BA 20 
00B8: EF FF A9 A0 20 EF FF A1 
00C0: 24 20 DC FF 86 2B A5 24 
00C8: C5 28 A5 25 E5 29 B0 C1 
00D0: E6 24 D0 02 E6 25 A5 24 
00D8: 29 07 10 C8 48 4A 4A 4A 
00E0: 4A 20 E5 FF 68 29 0F 09 
00E8: B0 C9 BA 90 02 69 06 2C 
00F0: 12 D0 30 FB 8D 12 D0 60 
00F8: 00 00 00 0F 00 FF 00 00 
```

### Custom starting address
Use the `-a` parameter to pass a different starting address for the output (in decimal):

`ebd -a [starting address] [filename]`

```
FF00: D8 58 A0 7F 8C 12 D0 A9 
FF08: A7 8D 11 D0 8D 13 D0 C9 
FF10: DF F0 13 C9 9B F0 03 C8 
FF18: 10 0F A9 DC 20 EF FF A9 
FF20: 8D 20 EF FF A0 01 88 30 
FF28: F6 AD 11 D0 10 FB AD 10 
FF30: D0 99 00 02 20 EF FF C9 
FF38: 8D D0 D4 A0 FF A9 00 AA 
FF40: 0A 85 2B C8 B9 00 02 C9 
FF48: 8D F0 D4 C9 AE 90 F4 F0 
FF50: F0 C9 BA F0 EB C9 D2 F0 
FF58: 3B 86 28 86 29 84 2A B9 
FF60: 00 02 49 B0 C9 0A 90 06 
FF68: 69 88 C9 FA 90 11 0A 0A 
FF70: 0A 0A A2 04 0A 26 28 26 
FF78: 29 CA D0 F8 C8 D0 E0 C4 
FF80: 2A F0 97 24 2B 50 10 A5 
FF88: 28 81 26 E6 26 D0 B5 E6 
FF90: 27 4C 44 FF 6C 24 00 30 
FF98: 2B A2 02 B5 27 95 25 95 
FFA0: 23 CA D0 F7 D0 14 A9 8D 
FFA8: 20 EF FF A5 25 20 DC FF 
FFB0: A5 24 20 DC FF A9 BA 20 
FFB8: EF FF A9 A0 20 EF FF A1 
FFC0: 24 20 DC FF 86 2B A5 24 
FFC8: C5 28 A5 25 E5 29 B0 C1 
FFD0: E6 24 D0 02 E6 25 A5 24 
FFD8: 29 07 10 C8 48 4A 4A 4A 
FFE0: 4A 20 E5 FF 68 29 0F 09 
FFE8: B0 C9 BA 90 02 69 06 2C 
FFF0: 12 D0 30 FB 8D 12 D0 60 
FFF8: 00 00 00 0F 00 FF 00 00 
```

### Display ASCII text
Add the `-d` flag to display the ASCII text column in the output:

`ebd -d [filename]`

```
0000: D8 58 A0 7F 8C 12 D0 A9 .X......
0008: A7 8D 11 D0 8D 13 D0 C9 ........
0010: DF F0 13 C9 9B F0 03 C8 ........
0018: 10 0F A9 DC 20 EF FF A9 .... ...
0020: 8D 20 EF FF A0 01 88 30 . .....0
0028: F6 AD 11 D0 10 FB AD 10 ........
0030: D0 99 00 02 20 EF FF C9 .... ...
0038: 8D D0 D4 A0 FF A9 00 AA ........
0040: 0A 85 2B C8 B9 00 02 C9 ..+.....
0048: 8D F0 D4 C9 AE 90 F4 F0 ........
0050: F0 C9 BA F0 EB C9 D2 F0 ........
0058: 3B 86 28 86 29 84 2A B9 ;.(.).*.
0060: 00 02 49 B0 C9 0A 90 06 ..I.....
0068: 69 88 C9 FA 90 11 0A 0A i.......
0070: 0A 0A A2 04 0A 26 28 26 .....&(&
0078: 29 CA D0 F8 C8 D0 E0 C4 ).......
0080: 2A F0 97 24 2B 50 10 A5 *..$+P..
0088: 28 81 26 E6 26 D0 B5 E6 (.&.&...
0090: 27 4C 44 FF 6C 24 00 30 'LD.l$.0
0098: 2B A2 02 B5 27 95 25 95 +...'.%.
00A0: 23 CA D0 F7 D0 14 A9 8D #.......
00A8: 20 EF FF A5 25 20 DC FF  ...% ..
00B0: A5 24 20 DC FF A9 BA 20 .$ .... 
00B8: EF FF A9 A0 20 EF FF A1 .... ...
00C0: 24 20 DC FF 86 2B A5 24 $ ...+.$
00C8: C5 28 A5 25 E5 29 B0 C1 .(.%.)..
00D0: E6 24 D0 02 E6 25 A5 24 .$...%.$
00D8: 29 07 10 C8 48 4A 4A 4A )...HJJJ
00E0: 4A 20 E5 FF 68 29 0F 09 J ..h)..
00E8: B0 C9 BA 90 02 69 06 2C .....i.,
00F0: 12 D0 30 FB 8D 12 D0 60 ..0....`
00F8: 00 00 00 0F 00 FF 00 00 ........
```

### Reading from stdin
Omit the filename and *ebd* will read from stdin:

`cat [filename] | ebd -d`

## Installation

Build with make:

`make`

Then install to `/usr/local/bin`:

`sudo make install`

Now you can call `ebd [options]` from any directory on your system.
