#!/bin/bash
if [ -d "vcpkg" ]; then
   if [ -z "$(ls -A vcpkg/)" ]; then
	   rm -rf vcpkg
	   git clone https://github.com/microsoft/vcpkg.git
   fi
fi

./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install sdl2 sdl2-image sdl2-mixer sdl2-ttf sdl2-net box2d

