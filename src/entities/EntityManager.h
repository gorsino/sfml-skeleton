#ifndef SFML_SKELETON_ENTITYMANAGER_H
#define SFML_SKELETON_ENTITYMANAGER_H

#include <vector>
#include <memory>
#include <map>

#include "Entity.h"

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
public:
    EntityManager() = default;

    ~EntityManager() = default;

    void updateInputs() {}

    void update() {}

    void render(sf::RenderTarget &target) {}

    EntityMap &getEntities() { return this->entityMap_; }

    EntityVec &getEntities(std::string &tag) { return this->entityMap_[tag]; }

    std::shared_ptr<Entity> createEntity(std::string &tag) {
        auto entity = std::make_shared<Entity>();
        this->entityMap_[tag].push_back(entity);

        return entity;
    }

private:
    EntityMap entityMap_;
};


#endif //SFML_SKELETON_ENTITYMANAGER_H
