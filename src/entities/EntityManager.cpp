#include "EntityManager.h"

void EntityManager::update() {
}

void EntityManager::render(sf::RenderTarget &target) {
    for (auto &[frs, snd]: this->entityMap_)
        for (auto &e: snd)
            target.draw(*e);
}

EntityMap &EntityManager::getEntities() { return this->entityMap_; }

EntityVec &EntityManager::getEntities(std::string &tag) { return this->entityMap_[tag]; }

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
    auto entity = Entity::create(tag);
    this->entityMap_[tag].push_back(entity);

    return entity;
}

size_t EntityManager::getTotalEntities() {
    size_t total = 0;

    for (auto &[fst, snd]: this->entityMap_)
        total += snd.size();

    return total;
}
