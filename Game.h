//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_GAME_H
#define ESCAPE_GAME_H

#include <SDL2/SDL.h>

//everything that relates to the game logics
namespace Game {
    static constexpr int windowWidth = 1280, windowHeight = 720;
    static const char* windowTitle = "Escape - horror game";

    //"main" class
    class Game {
    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_run = true;

        void clearScreen();
        void updateScreen();

    public:
        Game();
        ~Game();

        void gameLoop();
    };

} // Game

#endif //ESCAPE_GAME_H
