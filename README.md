# SDL2Stuff
My first usage of SDL2, will be absolute trash for a while.\
\
\
Plans are to make some sort of game, but I'm still just learning C++, makefiles, and SDL2. RIP my to-do list\
\
\
Windows:\
Builds using MinGW64\
Builds with includes and .DLLs sourced from SDL2-2.0.14 MinGW Devel.\
Builds dynamically, but has a switch to change that in the makefile. Static libs are not in repo.\
\
Mac:\
Builds using clang with SDL2 installed through brew.\
Bundles SDL2.framework into the .app for easy distribution.\
Technically built statically as SDL2 is currently the only dependancy not included with the OS.\
\
Linux:\
Builds using gnu g++ with libsdl2-dev installed through the package manager.\
Builds with -no-pie because otherwise it's seen as a Shared Library for some reason.\
No idea if this can be statically built on Linux or not.\
\
\
Vita and Switch:\
Not added to repo yet, will likely require their own makefiles just for sanity\
Will build using LibNX/Devkitpro for Switch and VitaSDK for Vita\