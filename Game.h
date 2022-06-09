//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_GAME_H
#define ESCAPE_GAME_H

#include "Draw.h"
#include "Utilities.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <exception>

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
        Engine::RandomGenerator m_randGen;
        std::shared_ptr<Engine::DrawHandler> m_draw;

        void clearScreen();
        void updateScreen();

    public:
        Game();
        ~Game();

        void gameLoop();
    };

} // Game

#endif //ESCAPE_GAME_H
