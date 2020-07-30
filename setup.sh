#!/bin/bash
CXX = g++-7
g++ --version
git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh

./vcpkg/vcpkg install sdl2
./vcpkg/vcpkg install sdl2-image
./vcpkg/vcpkg install sdl2-mixer
./vcpkg/vcpkg install sdl2-ttf
./vcpkg/vcpkg install sdl2-net
./vcpkg/vcpkg install box2d

