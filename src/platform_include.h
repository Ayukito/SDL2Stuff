#include <string>
using namespace std;
#ifdef _WIN64
    //define something for Windows (64-bit)
    #include <SDL2/SDL.h>
    // string FSRoot = "";
    // char* abspath = NULL;
#elif _WIN32
    //define something for Windows (32-bit)
    #include <SDL2/SDL.h>
    // string FSRoot = "";
    // char* abspath = NULL;
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE && TARGET_OS_SIMULATOR
        // define something for simulator
        // (although, checking for TARGET_OS_IPHONE should not be required).
        #include <SDL2/SDL.h>
        // string FSRoot = "";
        // char* abspath = NULL;
    #elif TARGET_OS_IPHONE && TARGET_OS_MACCATALYST
        // define something for Mac's Catalyst
        #include <SDL2/SDL.h>
        // string FSRoot = "";
        // char* abspath = NULL;
    #elif TARGET_OS_IPHONE
        // define something for iphone
        #include <SDL2/SDL.h>
        string FSRoot = "";
        // char* abspath = NULL;
        // inline void setupPath(){}
    #else
        #define TARGET_OS_OSX 1
        #include <mach-o/dyld.h>
        #include <SDL2/SDL.h>
        // string FSRoot = "../Resources/";
        // char abspath[1024];

        // inline void setupPath(){
        //     uint32_t size = sizeof(abspath);
        //     if (_NSGetExecutablePath(abspath, &size) == 0){
        //         *(strrchr(abspath, '/')+1) = '\0';
        //         //printf("executable path is %s\n", abspath);
        //     } else{
        //         //printf("buffer too small; need size %u\n", size);
        //     }
        // }
    #endif
#elif __ANDROID__
    // Android
    #include <SDL.h>
    #include <physfs.h>
    // string FSRoot = "";
    // char* abspath = NULL;
#elif __linux
    // linux
    #include <SDL2/SDL.h>
    // string FSRoot = "";
    // char* abspath = NULL;
#elif __unix // all unices not caught above
    // Unix
    #include <SDL2/SDL.h>
    // string FSRoot = "";
    // char* abspath = NULL;
#elif __posix
    // POSIX
    #include <SDL2/SDL.h>
    // string FSRoot = "";
    // char* abspath = NULL;
#elif __SWITCH__
    #include <switch.h>
    #include <SDL2/SDL.h>
    // char* abspath = NULL;
    // string FSRoot = "romfs:/";
#elif __VITA__
    #include <SDL2/SDL.h>
    // string FSRoot = "app0:/";
    // char* abspath = NULL;
#endif

#ifndef __ANDROID__
    #include <PhysFS/physfs.h>
#endif

inline string GetBasePath(){
    #ifdef __SWITCH__
        return "romfs:/"; // The Switch SDL doesn't seem to want to work properly, the following function just crashes the system .-.
    #endif
    #ifdef __linux
        return "";
    #endif
    return string(SDL_GetBasePath());
}
