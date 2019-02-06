#include <time.h>
#include "import_struct.h"

void end_of_game() {
    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_q) {
                    SDL_DestroyRenderer(rend);
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                    return;
                }
            }
        }
        SDL_SetRenderDrawColor(rend, 5, 5, 5, 255);
        SDL_RenderClear(rend);
        stringRGBA(rend, 260, 280, "GAME OVER", 255, rand() % 255, rand() % 255, 255);
        stringRGBA(rend, 240, 330, "press 'q' to exit", 255, 255, 255, 100);
        for (int i = 0; i < 10; i++)
            stringRGBA(rend, rand() % 400 + 50, rand() % 800 + 100, "GAME OVER", 255, rand() % 255, rand() % 255, 255);
        char buff[100];
        sprintf(buff, "your score: %d", score);
        stringRGBA(rend, 250, 300, buff, 255, 255, 255, 255);
        SDL_RenderPresent(rend);
        SDL_Delay(100);
    }
}

int main() {
    init();
    srand(time(NULL));
    while (play) {
        int time = SDL_GetTicks();
        if (keyboard() == 1234) break;
        move_gun();
        draw();
        while (SDL_GetTicks() - time < 1000 / FPS);
    }
    if (score > 1)
        end_of_game();
    return 0;
}


