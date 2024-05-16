#!/usr/bin/env python

"""ebd: Eight Bit Dump - A hexdump utility for 8 bit software development - For Python3

http://github.com/simonboak/ebd

Copyright (c) 2020 Simon Boak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

"""

import argparse
import binascii


parser = argparse.ArgumentParser( description='ebd: Eight Bit Dump - A hexdump utility for 8 bit software development - http://github.com/simonboak/ebd - Version 1.0.0' )
parser.add_argument( '-f', '--file', help='Input file to dump', required=True )
parser.add_argument( '-a', '--address', type=int, help='Decimal starting address of output', required=False )
parser.add_argument( '-d', '--displayascii', action='store_true', help='Display ASCII characters and show to the right of output', required=False )
args = vars( parser.parse_args() )


file = open( args['file'], 'r' )

fileOpen = 1
rowCount = 0

# Get the starting byte address from arguments, otherwise 0
if args['address'] == None:
    byteCount = 0
else:
    byteCount = args['address']

while fileOpen:
    byteCountHex = hex( byteCount )
    byteCountHexList = byteCountHex.split( 'x' ) # only want the digits after x from the 0x42 formatting style
    print( byteCountHexList[1].zfill(4).upper(), end=': ' )
    
    asciiColumn = ''
    
    while rowCount < 8: # 8 bytes to a line
        char = file.read( 1 )
        if not char:
            fileOpen = 0 # end of file reached
            break
        
        print( binascii.b2a_hex( char.encode() ).decode().upper(), end=' ' ) # convert byte to hex and in uppercase
        
        if args['displayascii'] == True and len( char ) > 0:
            # If in printable ASCII range, then print the character, otherwise just a period
            if ord( char ) > 31 and ord( char ) < 127:
                asciiColumn = asciiColumn + char
            else:
                asciiColumn = asciiColumn + '.'
        
        byteCount += 1
        rowCount += 1
    
    
    
    
    # parse the bytes and display ascii
    if args['displayascii'] == True:
        # If the last line is less than 8 bytes long, add space to line up this column
        if rowCount < 8:
            spaces = 8 - rowCount
            while spaces > 0:
                print( '   ', end='' ) # print 3 empty spaces for each empty byte column
                spaces = spaces - 1
            
        print( asciiColumn, end='' )
    
    
    rowCount = 0
    print() # New line
    
file.close()
