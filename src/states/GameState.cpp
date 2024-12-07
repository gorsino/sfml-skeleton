#include "GameState.h"

GameState::GameState(StateData &stateData) : BaseState(stateData) {
}

GameState::~GameState() = default;

void GameState::updateInputs(const float &dt) {
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

void GameState::update(const float &dt) {
}

void GameState::render() {
    this->entityManager_.render(*this->stateData.window);
}