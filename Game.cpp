//
// Created by intheloop on 6/9/22.
//

#include "Game.h"
#define RESIZALBE SDL_WINDOW_RESIZABLE

//for the TestScene
namespace Game {
    void TestEntity::update(double& deltaTime) {
        using namespace Engine::Input;
        if (isKeyPressed(Key::KEY_W))
            position.y -= 1 * deltaTime;
        else if (isKeyPressed(Key::KEY_S))
            position.y += 1 * deltaTime;
        else if (isKeyPressed(Key::KEY_A))
            position.x -= 1 * deltaTime;
        else if (isKeyPressed(Key::KEY_D))
            position.x += 1 * deltaTime;
    }

    void TestEntity::render(Engine::DrawHandler &draw, SDL_Renderer *renderer) {
        draw.rectanglef(position, {100, 100}, {255, 0, 0, 255});
    }

    TestScene::TestScene(
            Engine::DrawHandler &draw, SDL_Renderer *renderer
    ) : Scene(draw, renderer) {
        m_ecs.addEntity(std::make_shared<TestEntity>());
    }

    void TestScene::sceneUpdate(double &deltaTime) {
        std::cout << "Debug info:\n";
        std::cout << "Delta time: " << deltaTime << '\n';
        std::cout << "Entity component system:\n";
        if (m_ecs.getEntities().size())
            for (auto& entity: m_ecs.getEntities())
                std::cout << entity->getUUID() << '\n';
        else
            std::cout << "no entity\n";
        std::cout << '\n';
    }

} // Game

namespace Game {
    Game::Game() {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            throw std::runtime_error(SDL_GetError());

        SDL_CreateWindowAndRenderer(
                windowWidth, windowHeight, RESIZALBE,
                &m_window, &m_renderer
        );

        if (m_window == nullptr || m_renderer == nullptr)
            throw std::runtime_error(SDL_GetError());

        m_draw = Engine::DrawHandler(m_renderer);
        m_scene = std::make_unique<TestScene>(m_draw, m_renderer);

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
            m_scene->update(deltaTime);
            updateScreen();
        }
    }

} // Game