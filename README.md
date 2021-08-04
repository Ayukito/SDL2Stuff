# SDL2Stuff
## Builds on Windows, Mac, Linux, iOS, Vita, and Switch
My first usage of SDL2, will be absolute trash for a while.  
Plans are to make some sort of game, but I'm still just learning C++, makefiles, and SDL2.  
  
### To-do:  
- [x] Desktop Support 
- [x] Vita and Switch Support 
- [x] iOS Support
- [ ] Android Support  
- [ ] Actually make something cool  
  
  
### Windows:  
Builds using MinGW64  
Builds with includes and .DLLs sourced from SDL2-2.0.14 MinGW Devel.  
Builds dynamically, but has a switch to change that in the makefile. Static libs are not in repo.  
  
### Mac:  
Builds using clang with SDL2 installed through brew.  
Bundles SDL2.framework into the .app for easy distribution.  
Technically built statically as SDL2 is currently the only dependancy not included with the OS.  

### iOS:  
Open the included xcodeproj and add  XCode/SDL from the [SDL source](https://github.com/libsdl-org/SDL) to your Frameworks(?) to have the required libraries  
Included in the repo is the iOS includes for SDL2 and the needed assets to create an iOS app  
  
### Linux:  
Builds using gnu g++ with libsdl2-dev installed through the package manager.  
Builds with -no-pie because otherwise it's seen as a Shared Library for some reason.  
No idea if this can be statically built on Linux or not.  
  
### Vita and Switch:  
Both build using their respective homebrew SDKs and their ports of SDL2 and PhysFS  
Switch's ifdef is \_\_SWITCH\_\_ and Vita's ifdef is \_\_VITA\_\_  
The switch makefile is dumb and dumps all the .o files into /build
