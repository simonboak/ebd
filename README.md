# ebd
**ebd:** Eight Bit Dump - A hexdump utility for 8 bit software development.

An alternative to modern hexdump utilities, *ebd* is designed for anyone using modern systems to develop software for older 8 bit processors such as the 6502, Z80, etc.

Its style is inspired by the Apple II system monitor program and outputs 8 bit bytes with the option to show ASCII characters too. It is fixed to 8 bytes per row, with a 16 bit address which rolls over after each 64k. If you need more address space this probably isn't the tool for you.

I basically failed in using format strings in *hexdump* which comes with macOS and decided it would be faster to write this little utility.

Written in Python 2.7 because that was just easier for now.

## Usage
Just pass a file to *ebd* and you'll get a hexdump of it's contents:

<img width="682" alt="example-basic" src="https://user-images.githubusercontent.com/1146324/81479384-c5967b80-921a-11ea-9a31-c69430bee5fd.png">

### Custom starting address
Use the `-a` parameter to pass a different starting address for the output (in decimal):

<img width="682" alt="example-address" src="https://user-images.githubusercontent.com/1146324/81479389-cb8c5c80-921a-11ea-8139-d29368961658.png">

### Display ASCII text
Add the `-d` flag to display the ASCII text column in the output:

<img width="682" alt="example-ascii" src="https://user-images.githubusercontent.com/1146324/81479393-cdeeb680-921a-11ea-9be5-77a2ce433550.png">


## Installation

You can either just call the Python script directly or you could follow something like this for installing on *nix systems:

```chmod a+x ebd.py
sudo cp ebd.py /usr/local/bin/ebd```

Now you can call `ebd [options]` from any directory on your system.

## C Version
Long term, I'd like to write a version of *ebd* in C, along with a few extra features at the same time. Maybe one day I'll get around to that.
