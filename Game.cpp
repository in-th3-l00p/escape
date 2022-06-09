//
// Created by intheloop on 6/9/22.
//

#include "Game.h"
#define RESIZALBE SDL_WINDOW_RESIZABLE

namespace Game {
    Game::Game() {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            std::runtime_error(SDL_GetError());

        SDL_CreateWindowAndRenderer(
                windowWidth, windowHeight, RESIZALBE,
                &m_window, &m_renderer
        );

        if (m_window == nullptr || m_renderer == nullptr)
            std::runtime_error(SDL_GetError());

        m_draw = std::make_shared<Engine::DrawHandler>(m_renderer);

        SDL_SetWindowTitle(m_window, windowTitle);
    }

    Game::~Game() {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    void Game::clearScreen() {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
    }

    void Game::updateScreen() {
        SDL_RenderPresent(m_renderer);
    }

    void Game::gameLoop() {
        SDL_Event event;
        while (m_run) {
            //event driven programming
            while (SDL_PollEvent(&event))
                switch (event.type) {
                    case SDL_QUIT:
                        m_run = false;
                        break;
                }

            clearScreen();

            //rendering
            m_draw->rectangle({100, 100}, {200, 200}, {255, 255, 255, 255});

            updateScreen();
        }
    }
} // Game