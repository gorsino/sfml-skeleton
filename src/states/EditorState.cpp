#include "EditorState.h"

EditorState::EditorState(StateData *stateData) : BaseState(stateData) {
    this->name = "Editor";
}

EditorState::~EditorState() = default;

void EditorState::updateInputs(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->isKeyTime()) {
        this->exit = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->isKeyTime()) {
        std::shared_ptr<Entity> e = this->entityManager_.addEntity("number");
        e->rect.setFillColor(POMEGRANATE);
        e->rect.setSize(sf::Vector2f(100.f, 100.f));
        e->rect.setPosition(rand() % 1920, rand() % 1080);

    }
}

void EditorState::update(const float &dt) {
    this->debugTotalEntities();
}

void EditorState::render() {
    this->entityManager_.render(*this->stateData->window);
}

void EditorState::debugTotalEntities() {
    if (!this->stateData->debug->isActive())
        return;

    std::stringstream ss;
    ss << "Entities: " << this->entityManager_.getTotalEntities();

    DebugText totalEntities(*this->stateData->font, 22);
    totalEntities.setString(ss.str());

    this->stateData->debug->add(totalEntities, TOTAL_ENTITIES, sf::Vector2f(20, 400));

}
