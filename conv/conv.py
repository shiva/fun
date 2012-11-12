#!/usr/bin/env python
import sys
from optparse import OptionParser
import fileinput
import binascii

def main(args):
    usage = "usage: %prog [options] arg1"
        
    parser = OptionParser(usage=usage)
    parser.add_option("-f", "--file", dest="filename",
                      help="read data from FILENAME (1 binary value per line)")
    parser.add_option("-a", "--ascii_to_binary", action="store_true", dest="a2b",
                      help="Ascii to binary")
    if (len(args) <= 1): 
        parser.print_help()
        sys.exit()

    args = args[1:]
    (options, args) = parser.parse_args()

    if (options.a2b):
        ascii_to_bin(args[0])
    else:
        bin_to_ascii(options.filename)
  
def ascii_to_bin(text):
    for c in text:
        s = "" + bin(ord(c))
        print s

def bin_to_ascii(file):
    str = ""
    print "Input:"
    i = 0;
    for line in fileinput.input([file]):
        line = line.strip()
        sys.stdout.write(line + " ")
        i += 1
        if (i%5 == 0) : 
            print ""
        str = str + chr(int(line, 2))

    print ("\nOutput: %s" % str)

if __name__ == "__main__":
	sys.exit(main(sys.argv))

