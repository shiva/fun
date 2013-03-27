#!/usr/bin/env python
import sys
from optparse import OptionParser
import re

def main(args):
    usage = "usage: %prog [options] <strings to sort>"
        
    parser = OptionParser(usage=usage)
    if (len(args) <= 1): 
        parser.print_help()
        sys.exit()

    args = args[1:]
    (options, args) = parser.parse_args()

    sort_nicely(args)
    for item in args:
        print item

def tryint(s):
    try:
        return int(s)
    except:
        return s
     
def alphanum_key(s):
    """ Turn a string into a list of string and number chunks.
        "z23a" -> ["z", 23, "a"]
    """
    return [ tryint(c) for c in re.split('([0-9]+)', s) ]

def sort_nicely(l):
    """ Sort the given list in the way that humans expect.
    """
    l.sort(key=alphanum_key) 
if __name__ == "__main__":
	sys.exit(main(sys.argv))



