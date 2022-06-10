//
// Created by intheloop on 6/10/22.
//

#ifndef ESCAPE_ENTITYCOMPONENTSYSTEM_H
#define ESCAPE_ENTITYCOMPONENTSYSTEM_H

#include "Draw.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

//defining the ECS for the engine
namespace Engine {
    class Entity {
    protected:
        std::string m_uuid;
    public:
        Entity();
        virtual void render(DrawHandler& draw, SDL_Renderer* renderer) {};
        virtual void update(double& deltaTime) {};

        //getters and setters
        const std::string& getUUID() const;
    };

    class EntityComponentSystem {
    private:
        std::vector<std::shared_ptr<Entity>> m_entities;
        SDL_Renderer* m_renderer; //pointer to the main renderer
        DrawHandler& m_draw;
    public:
        EntityComponentSystem(DrawHandler& draw, SDL_Renderer* renderer);
        void update(double& deltaTime); //shall run in the game loop

        //for adding, getting and removing
        void addEntity(std::shared_ptr<Entity> entity);
        const std::vector<std::shared_ptr<Entity>>& getEntities();
        Entity& getEntity(const std::string& uuid);
        void removeEntity(const std::string& uuid);
    };

    //provides a way to add more functionality to the entity component system
    class Scene {
    protected:
        EntityComponentSystem m_ecs;
    public:
        Scene(DrawHandler& draw, SDL_Renderer* renderer);
        virtual ~Scene() = default;

        //lets the user change what happens every frame
        virtual void sceneUpdate(double& deltaTime) {};
        void update(double& deltaTime);
    };
} // Engine


#endif //ESCAPE_ENTITYCOMPONENTSYSTEM_H
