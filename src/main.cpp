#include <iostream>
#include "platform_include.h"
#include "PhysFS/physfs.h"

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

int main( int argc, char *argv[] ){
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "There was an error initilizing SDL"  << endl
        << SDL_GetError() << endl;
        return 0;
    };

    SDL_Window *window;

    window = SDL_CreateWindow(  "Testing!",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1280,
                                720,
                                SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI );
    if (window == NULL){
        cout << "There was an error initilizing the SDL Window"  << endl
        << SDL_GetError() << endl;
        return 0;
    };

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    PHYSFS_init(NULL);

    int res = PHYSFS_mount("Resources", "/", 1);
    cout << "mounted " << res << endl;

    bool exists = false;

    exists = PHYSFS_exists("/test.txt");
    cout << exists << endl;

    string txt = PHYSFS_readFile("/test.txt");
    cout << txt << endl;

    SDL_Event event;
    bool running = true;

    while ( running ) {
    while (SDL_PollEvent(&event)) {
            if ( event.type == SDL_QUIT){
                running = false;
                break;
            }
        }
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
