#include <iostream>
#include "platform_include.h"
#include "PhysFS/physfs.h"

using namespace std;

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
                                640,
                                480,
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
        cout << PHYSFS_isInit() << endl;
        /* do some other stuff here -- draw your app, etc. */
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
