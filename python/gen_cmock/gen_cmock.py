#!/usr/bin/env python
from __future__ import print_function
import sys
from optparse import OptionParser
import fileinput
import binascii

sys.path.extend(['.', '..'])

from pycparser import c_parser, c_ast, parse_file

# Portable cpp path for Windows and Linux/Unix
PYCPARSER_CO_PATH='/Users/shiva/dev/github/pycparser.git/pycparser'
CPPPATH = PYCPARSER_CO_PATH + '/utils/cpp.exe' if sys.platform == 'win32' else 'cpp'

# A simple visitor for FuncDef nodes that prints the names and
# locations of function definitions.
#
class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):
        print('test')
        print('%s at %s' % (node.decl.name, node.decl.coord))


def show_func_defs(filename):
    # Note that cpp is used. Provide a path to your own cpp or
    # make sure one exists in PATH.
    #
    INCLUDE_PATHS = r'-I /Users/shiva/dev/github/fun.git/fun/c/ooc/include'
                    #' -I' + PYCPARSER_CO_PATH + '/utils/fake_libc_include' 
    ast = parse_file(
            filename, 
            use_cpp=True, 
            cpp_path=CPPPATH, 
            cpp_args='-nostdinc')

    print("Hello")
    v = FuncDefVisitor()
    v.visit(ast)

def main(args):
    usage = "usage: %prog [options] <filenames>"
        
    parser = OptionParser(usage=usage)
    parser.add_option("-o", "--output-dir", dest="outputdir",
                      help="Directory to output mock headers")
    if (len(args) <= 1): 
        parser.print_help()
        sys.exit()

    args = args[1:]
    (options, args) = parser.parse_args()

    parse_files(options.outputdir, args)
  
def parse_files(outputdir, filelist):
    i = 1
    for f in filelist:
        #th_file = get_outfilename(f)
        show_func_defs(f)

def get_outfilename(filename):
    lhs,rhs = filename.split(".h")
    return lhs + "_mock.h"

if __name__ == "__main__":
	sys.exit(main(sys.argv))

