#!/bin/sh

if [ -z "$TRAVIS_OS_NAME" ]; then
    # Multi-OS feature not yet enabled. Build for linux with GCC 4.6.
    TRAVIS_OS_NAME=linux
fi

if [ "$TRAVIS_OS_NAME" = "linux" ]; then
    sudo apt-get install -qq cdbs cmake libboost-dev libboost-thread-dev libboost-filesystem-dev libmsgpack-dev lcov
    gem install coveralls-lcov
elif [ "$TRAVIS_OS_NAME" = "osx" ]; then
    brew install msgpack
else
    echo "Unknown OS ($TRAVIS_OS_NAME). Stopping build ..."
    exit 1
fi
