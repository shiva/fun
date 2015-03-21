#!/usr/bin/env python
import sys
from optparse import OptionParser
import fileinput
import binascii

def main(args):
    usage = "usage: %prog [options] <filenames>"
        
    parser = OptionParser(usage=usage)
    parser.add_option("-f", "--file", dest="filename",
                      help="output filename (html)")
    if (len(args) <= 1): 
        parser.print_help()
        sys.exit()

    args = args[1:]
    (options, args) = parser.parse_args()

    create_html(options.filename, args)
  
def create_html(output, filelist):
    i = 1
    for file in filelist:
        th_file = get_thumbname(file)
        id = "img_%d" % i
        title = "Title %d" % i
        desc = 'description'
        image = dict(id=id, link=file, title=title, image=th_file, alt=title, desc=desc)
        print_html(image)
        i+=1

def get_thumbname(file):
    lhs,rhs = file.split(".jpg")
    return lhs + "_th.jpg"

def print_html(image):
    #print image
    #a = '<li>\n<a class="thumb" name="%(id)" href="%(link)" title="%(title)">'
    #print repr(a).format(**image)
    a = '\n<li>\n    <a class="thumb" name="{id}" href="{link}" title="{title}">' \
        '\n        <img src="{image}" alt="{alt}" />\n    </a>' \
        '\n    <div class="caption"> <div class="image-title">{title}</div>' \
        '\n    <div class="image-desc">{desc}</div> </div>\n</li> '
    print a.format(**image)

if __name__ == "__main__":
	sys.exit(main(sys.argv))

