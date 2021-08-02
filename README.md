# SDL2Stuff\
My first usage of SDL2, will be absolute trash for a while.\
\
\
Plans are to make some sort of game, but I'm still just learning C++, makefiles, and SDL2. RIP my to-do list\
\
\
Windows:\
Builds using MinGW64, may look into providing a VS 2019 project\
Builds with includes and lib files sourced from SDL2-2.0.14 MinGW Devel\
For now builds statically so the file size is large (~13mb). I don't know what to really do about that\
Uses rm -rf in the makefile so will probably not build with default terminal. Will be fixed later, maybe\
\
Mac:\
Builds using xcode clang with SDL2 and SDL2-Image installed through brew\
\
Linux:\
Builds using gnu g++ on a modified Ubuntu 20.04.2 LTS build for T2 MacBooks, seems to work fine.\
Builds with -no-pie because otherwise it's seen as a Shared Library for some reason.\
Currently uses libsdl2-dev and lib-sdl2-image-dev packages\