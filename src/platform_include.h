#include <string>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#ifdef _WIN64
    //define something for Windows (64-bit)
#elif _WIN32
    //define something for Windows (32-bit
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE == 1
        // iOS
    #else
        // MacOS
        #define TARGET_OS_OSX 1
    #endif
#elif __ANDROID__
    // Android
    #include <SDL.h>
    #include <physfs.h>
#elif __linux
    // linux
#elif __SWITCH__
    #include <switch.h>
#elif __VITA__
#endif

#ifndef __ANDROID__
    #include <PhysFS/physfs.h>
    #include <SDL2/SDL.h>
#endif

inline string GetBasePath(){
    #ifdef __SWITCH__
        return "romfs:/"; // The Switch SDL doesn't seem to want to work properly, the following function just crashes the system .-.
    #elif __ANDROID__
        return "";
    #endif
    return string(SDL_GetBasePath());
}
