#!/bin/sh

if [ -z "$TRAVIS_OS_NAME" ]; then
    # Multi-OS feature not yet enabled. Build for linux with GCC 4.6.
    export TRAVIS_OS_NAME=linux
fi

if [ "$TRAVIS_OS_NAME" = "linux" ]; then
    sudo apt-get update -qq
elif [ "$TRAVIS_OS_NAME" = "osx" ]; then
    brew update && brew --config
else
    echo "Unknown OS - '$TRAVIS_OS_NAME'. Stopping the build ..."
    exit 1
fi    
