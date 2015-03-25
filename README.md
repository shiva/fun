[![Build Status](https://travis-ci.org/shiva/fun.svg?branch=master)](https://travis-ci.org/shiva/fun)
[![Join the chat at https://gitter.im/shiva/fun](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/shiva/fun?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Summary of Contents
===================


 - th-stor     - Thread local storage 
 - fwc_stdlib  - A standard library (based on Linux Programming Interface stdlib) that provides basic types, error functions, etc 
 - nim         - A set of simple programs using [nim language](http://nim-lang.org/) 
 - ooc         - Basic framework and library for object-oriented programming in C

Comming Soon
------------
 - locks       - Examples for thread locking (coming soon)
 - cplug       - A C framework for loading multiple c-libraries as plugins - using a config file (coming soon)


Compiling the examples 
======================
This project uses cmake to generate makefiles. The generated makefiles are used to build the targets for your platform. 

Out-of-source builds are supported and the instructions below will build everything within the build directory.
On linux machines, you will need the following

 - cmake - version 2.6 or greater (you can install this using apt-get)
 - make/gmake - the default should suffice
 - gcc/something other c compiler - the default should suffice
 - nim-lang - version 0.9.6 or greater
 - cunit - version 2.1+

To install cunit on Ubuntu:
    # sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

Steps to compile all targets:

    # cd $CHECKOUT/build
    # cmake ../
    # make

The above commands generate binaries and libraries in $CHECKOUT/build/bin and $CHECKOUT/build/lib respectively.


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/shiva/fun/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

