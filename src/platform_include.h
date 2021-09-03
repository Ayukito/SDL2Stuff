#include <string>
using namespace std;
#ifdef _WIN64
    //define something for Windows (64-bit)
    #include <SDL2/SDL.h>
#elif _WIN32
    //define something for Windows (32-bit)
    #include <SDL2/SDL.h>
#elif __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_IPHONE
        // iOS
        #include <SDL2/SDL.h>
    #else
        // MacOS
        #define TARGET_OS_OSX 1
        #include <SDL2/SDL.h>
    #endif
#elif __ANDROID__
    // Android
    #include <SDL.h>
    #include <physfs.h>
#elif __linux
    // linux
    #include <SDL2/SDL.h>
#elif __SWITCH__
    #include <switch.h>
    #include <SDL2/SDL.h>
#elif __VITA__
    #include <SDL2/SDL.h>
#endif

#ifndef __ANDROID__
    #include <PhysFS/physfs.h>
#endif

inline string GetBasePath(){
    #ifdef __SWITCH__
        return "romfs:/"; // The Switch SDL doesn't seem to want to work properly, the following function just crashes the system .-.
    #elif __ANDROID__
        return "";
    #endif
    return string(SDL_GetBasePath());
}
