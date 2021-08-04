#ifdef _WIN64
   //define something for Windows (64-bit)
   #include <SDL2/SDL.h>
   char* FSRoot = (char*)"";
#elif _WIN32
   //define something for Windows (32-bit)
   #include <SDL2/SDL.h>
   char* FSRoot = (char*)"";
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE && TARGET_OS_SIMULATOR
        // define something for simulator
        // (although, checking for TARGET_OS_IPHONE should not be required).
        #include <SDL2/SDL.h>
        char* FSRoot = (char*)"";
    #elif TARGET_OS_IPHONE && TARGET_OS_MACCATALYST
        // define something for Mac's Catalyst
        #include <SDL2/SDL.h>
        char* FSRoot = (char*)"";
    #elif TARGET_OS_IPHONE
        // define something for iphone
        #include <SDL2/SDL.h>
        char* FSRoot = (char*)"";
    #else
        #define TARGET_OS_OSX 1
        #include <SDL2/SDL.h>
        char* FSRoot = (char*)"";
    #endif
#elif __linux
    // linux
    #include <SDL2/SDL.h>
    char* FSRoot = (char*)"";
#elif __unix // all unices not caught above
    // Unix
    #include <SDL2/SDL.h>
    char* FSRoot = (char*)"";
#elif __posix
    // POSIX
    #include <SDL2/SDL.h>
    char* FSRoot = (char*)"";
#elif __SWITCH__
    #include <switch.h>
    #include <SDL2/SDL.h>
    char* FSRoot = (char*)"romfs:/";
#elif __VITA__
    #include <SDL2/SDL.h>
    char* FSRoot = (char*)"app0:/";
#endif
