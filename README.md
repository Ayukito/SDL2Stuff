# SDL2Stuff
## Builds on Windows, Mac, Linux, iOS, Vita, and Switch
My first usage of SDL2, will be absolute trash for a while.  
Plans are to make some sort of game, but I'm still just learning C++, makefiles, and SDL2.  
  
### To-do:  
- [x] Desktop Support 
- [x] Vita and Switch Support 
- [x] iOS Support
- [ ] Android Support (WIP!)  
- [ ] Actually make something cool  
  
  
### Windows:  
Builds using MinGW64 through MSys2 but you can probably use Visual Studio or normal MinGW with some changes.  
SDL2 includes and .DLL sourced from SDL2-2.0.14 MinGW Devel.  
PhysFS .DLL is built using MinGW64 and the includes are sourced from the 3.0.2 release.  
Builds dynamically with .DLL files from MinGW64 (libgcc_s_seh-1, libstd++-6, and libwinpthread-1), but has a boolean to build statically in the makefile. Static libs are not in repo.  
  
### Mac:  
Builds using clang with SDL2 and PhysFS installed through brew, static libs included built targeting MacOS 10.9.  
Built statically targetting MacOS 10.9 in the makefile.  

### iOS:  
Built using Xcode targeting iOS 9.0 as the minimum. iOS 13.0+ needed for controller support.  
Included in the repo are the iOS includes and static libs for SDL2 and PhysFS, and the needed assets to create an iOS app.  
  
### Linux:  
Builds using gnu g++ with libsdl2-dev and libphysfs-dev installed through the package manager.  
Builds with -no-pie because otherwise it's seen as a Shared Library for some reason.  
No idea if this can be statically built on Linux or not.  
  
### Vita and Switch:  
Both build using their respective homebrew SDKs and their ports of SDL2 and PhysFS.  
The Switch ifdef is \_\_SWITCH\_\_ and the Vita ifdef is \_\_VITA\_\_  
The Switch makefile is dumb and dumps all the .o files into /build.  
