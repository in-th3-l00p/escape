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
        Uint64 now{SDL_GetPerformanceCounter()}, last{0};
        double deltaTime = 0;
        while (m_run) {
            last = now;
            now = SDL_GetPerformanceCounter();
            deltaTime = static_cast<double>(
                    static_cast<double>((now - last) * 1000) /
                    static_cast<double>(SDL_GetPerformanceFrequency())
            );

            //event driven programming
            while (SDL_PollEvent(&event))
                switch (event.type) {
                    case SDL_QUIT:
                        m_run = false;
                        break;
                }

            clearScreen();

            //rendering
            std::cout << deltaTime << '\n';

            updateScreen();
        }
    }
} // Game