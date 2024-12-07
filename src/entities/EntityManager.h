#ifndef SFML_SKELETON_ENTITYMANAGER_H
#define SFML_SKELETON_ENTITYMANAGER_H

#include <vector>
#include <memory>
#include <map>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Entity.h"

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
public:
    EntityManager() = default;

    ~EntityManager() = default;

    void update();

    void render(sf::RenderWindow &window);

    EntityMap &getEntities();

    EntityVec &getEntities(std::string &tag);

    std::shared_ptr<Entity> addEntity(const std::string &tag);

private:
    EntityMap entityMap_;
};


#endif //SFML_SKELETON_ENTITYMANAGER_H
