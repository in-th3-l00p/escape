//
// Created by intheloop on 6/10/22.
//

#include "EntityComponentSystem.h"
#include "Utilities.h"

namespace Engine {
    Entity::Entity(): m_uuid(uuid::generateUUID4()) { }

    const std::string &Entity::getUUID() const {
        return m_uuid;
    }

    EntityComponentSystem::EntityComponentSystem(
            Engine::DrawHandler &draw, SDL_Renderer *renderer
    ): m_draw(draw), m_renderer(renderer) {
        std::cout << "Entity component system initialized\n";
    }

    void EntityComponentSystem::update(double &deltaTime) {
        //updating
        for (auto &entity: m_entities) {
            entity->render(m_draw, m_renderer);
            entity->update(deltaTime);
        }
    }

    void EntityComponentSystem::addEntity(std::shared_ptr<Entity> entity) {
        m_entities.push_back(entity);
    }

    const std::vector<std::shared_ptr<Entity>>& EntityComponentSystem::getEntities() {
        return m_entities;
    }

    Entity &EntityComponentSystem::getEntity(const std::string &uuid) {
        for (auto &entity: m_entities)
            if (entity->getUUID() == uuid)
                return *entity;
        throw std::runtime_error(
                std::string("cannot find the entity with the uuid: ") + uuid
        );
    }

    void EntityComponentSystem::removeEntity(const std::string &uuid) {
        for (auto entity = m_entities.begin(); entity != m_entities.end(); entity++)
            if (entity->get()->getUUID() == uuid) {
                m_entities.erase(entity);
                return;
            }
    }

    Scene::Scene(DrawHandler &draw, SDL_Renderer *renderer)
        : m_ecs(draw, renderer) {
        if (renderer == nullptr)
            throw std::runtime_error("renderer doesn't exist");
    }

    void Scene::update(double &deltaTime) {
        m_ecs.update(deltaTime);
        sceneUpdate(deltaTime);
    }
} // Engine
