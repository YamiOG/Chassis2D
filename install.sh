#!/bin/bash
if [[ `which apt` ]]; then
    sudo apt-get install build-essential \
                            libsdl2-dev libsdl2-2.0-0 \
                            libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 \
                            libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 \
                            libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 \
                            libbox2d-dev libbox2d2.3.0 -y
elif [[ `which yum` ]]; then
    sudo yum groupinstall 'Development Tools' -y
    sudo yum install SDL2-devel SDL2_image-devel SDL2_mixer-devel SDL2_ttf-devel SDL2_net-devel libBox2D2_1_0-devel -y
elif [[ `which apk` ]]; then
    echo -e "\e[1;31mCannot install packages through this Package Manager\e[0m"
else
    echo -e "\e[1;31mPackage Manager is Unknown\e[0m"
fi