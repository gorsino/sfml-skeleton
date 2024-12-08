#include "Entity.h"

std::shared_ptr<Entity> Entity::create(const std::string &tag) {
    auto entity = std::make_shared<Entity>();
    entity->tag = tag;

    return entity;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->rect);
}

template<typename T, typename... TArgs>
T &Entity::add(TArgs &&... args) {
    auto &component = this->get<T>();

    component = T(std::forward<TArgs>(args)...);
    component.exists = true;

    return component;
}

template<typename T>
void Entity::remove() {
    this->get<T>() = T();
}

template<typename T>
T &Entity::get() {
    return std::get<T>(this->components);
}

template<typename T>
bool Entity::has() const {
    return this->get<T>().exists;
}
