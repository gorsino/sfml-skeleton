#include "EntityManager.h"

void EntityManager::update() {
}

void EntityManager::render(sf::RenderWindow &window) {
    for (auto &[frs, snd]: this->entityMap_)
        for (auto &e: snd)
            window.draw(e->rect);
}

EntityMap &EntityManager::getEntities() { return this->entityMap_; }

EntityVec &EntityManager::getEntities(std::string &tag) { return this->entityMap_[tag]; }

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
    auto entity = std::make_shared<Entity>();
    entity->tag = tag;

    this->entityMap_[tag].push_back(entity);

    return entity;
}