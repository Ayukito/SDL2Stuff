#include "platform_include.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string PHYSFS_readFile( string path){
    string output;
    PHYSFS_File* fp;
    fp = PHYSFS_openRead(path.c_str());
    if (fp){
        //char buffer[PHYSFS_fileLength(fp)];
        char buffer[128];
        PHYSFS_sint64 rc;
        do {
            rc = PHYSFS_readBytes(fp, buffer, sizeof(buffer));
            string s(buffer);
            output += s.substr(0, rc);
        } while (!(rc < sizeof(buffer)));
    }
    PHYSFS_close(fp);

    return output;
}

char* file_read(const char* filename) {
    SDL_RWops *rw = SDL_RWFromFile(filename, "rb");
    if (rw == NULL) return NULL;

    Sint64 res_size = SDL_RWsize(rw);
    char* res = (char*)malloc(res_size + 1);

    Sint64 nb_read_total = 0, nb_read = 1;
    char* buf = res;
    while (nb_read_total < res_size && nb_read != 0) {
        nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }
    SDL_RWclose(rw);
    if (nb_read_total != res_size) {
        free(res);
        return NULL;
    }

    res[nb_read_total] = '\0';
    return res;
}

int main( int argc, char *argv[] ){
    // Need to initialize these two on switch specifically, otherwise nothing happens
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0){
        SDL_Log("There was an error initilizing SDL! SDL_Error: %s\n", SDL_GetError());
        return 0;
    };

    SDL_Window *window;

    window = SDL_CreateWindow(  "Testing!",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1280,
                                720,
                                SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN );
    if (window == NULL){
        SDL_Log("There was an error initilizing the SDL Window! SDL_Error: %s\n", SDL_GetError());
        return 0;
    };
    SDL_Log("Test2222");
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    PHYSFS_init(NULL);

#ifdef __SWITCH__
    romfsInit();
        socketInitializeDefault();
        nxlinkStdio();
#endif

    int res;

    SDL_Log("Base Path: %s", GetBasePath().c_str());
    char* file = file_read("Assets/test.txt");
    SDL_Log("file: %s", file);
    //ToDo: Use SDL RWops on Android instead of physfs, make filesystem wrapper. Use PHYSFS_mountMemory if using .zip to mount
    string tmp = GetBasePath() + "Assets";
    char *array = &tmp[0];
    res = PHYSFS_mount(array, "/", 1);
    SDL_Log("Mounted: %d", res);
    if (res == 0){
        SDL_Log("PhysFS Error: %s", PHYSFS_getLastError());
    }

    bool exists = false;

    exists = PHYSFS_exists("/test.txt");
    SDL_Log("Exists: %d", exists?1:0);

    string txt = PHYSFS_readFile("/test.txt");
    SDL_Log("Text: %s", txt.c_str());

    SDL_Event event;
    bool running = true;

    while ( running ) {
        while (SDL_PollEvent(&event)) {
            if ( event.type == SDL_QUIT){
                running = false;
                break;
            }
        }
        if (exists){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }else{
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
        //cout << PHYSFS_isInit() << endl;
        /* do some other stuff here -- draw your app, etc. */
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    PHYSFS_deinit();
    return 0;
}