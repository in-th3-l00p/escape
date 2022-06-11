//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_GAME_H
#define ESCAPE_GAME_H

#include "Draw.h"
#include "Utilities.h"
#include "EntityComponentSystem.h"
#include "Input.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <exception>

//everything that relates to the game logics
namespace Game {
    class TestEntity: public Engine::Entity {
    private:
        Engine::Vector2<float> position{100, 100};

    public:
        TestEntity() = default;
        void update(double& deltaTime) override;
        void render(Engine::DrawHandler& draw, SDL_Renderer* renderer) override;
    };

    class TestScene: public Engine::Scene {
    public:
        TestScene(Engine::DrawHandler& draw, SDL_Renderer* renderer);
        void sceneUpdate(double &deltaTime) override;
    };

    static constexpr int windowWidth = 1280, windowHeight = 720;
    static const char* windowTitle = "Escape - horror game";

    //"main" class
    class Game {
    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_run = true;
        Engine::RandomGenerator m_randGen;
        Engine::DrawHandler m_draw;
        std::unique_ptr<Engine::Scene> m_scene; //main scene

        void clearScreen();
        void updateScreen();

    public:
        Game();
        ~Game();

        void gameLoop();
    };

} // Game

#endif //ESCAPE_GAME_H
