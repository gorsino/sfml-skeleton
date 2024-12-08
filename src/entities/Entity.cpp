#include "Entity.h"

std::shared_ptr<Entity> Entity::create(const std::string &tag) {
    auto entity= std::make_shared<Entity>();
    entity->tag = tag;

    return entity;
}
