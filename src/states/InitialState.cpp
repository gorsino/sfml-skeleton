#include "InitialState.h"

InitialState::InitialState(StateData *stateData) : BaseState(stateData) {
    this->name = "Initial";

    /// Init background
    {
        auto size = sf::Vector2f(
                static_cast<float >(stateData->window->getSize().x),
                static_cast<float >(stateData->window->getSize().y)
        );

        this->background_ = sf::RectangleShape(size);
        this->background_.setFillColor(ALIZARIN);
    }

    /// Init panel
    {
        auto size = sf::Vector2f(500.f, 800.f);
        auto pos = sf::Vector2f(
                (static_cast<float >(stateData->window->getSize().x) - size.x) / 2.f,
                (static_cast<float >(stateData->window->getSize().y) - size.y) / 2.f
        );

        this->panel_ = sf::RectangleShape(size);
        this->panel_.setPosition(pos);
        this->panel_.setFillColor(POMEGRANATE);
    }

    /// Init buttons
    {
        auto characterSize = 30;
        auto size = sf::Vector2f(300.f, 100.f);
        auto posX = (static_cast<float >(stateData->window->getSize().x) - size.x) / 2.f;

        this->buttons_["EDITOR"] = new ui::Button(
                sf::Vector2f(posX, 300.f), size,
                *this->stateData->font, "Editor", characterSize);

        this->buttons_["EXIT"] = new ui::Button(
                sf::Vector2f(posX, 410.f), size,
                *this->stateData->font, "Exit", characterSize);
    }
}

void InitialState::updateInputs() {
    if ((this->buttons_["EXIT"]->isPressed() || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
        this->isKeyTime()) {
        this->exit = true;
    }

    if (this->buttons_["EDITOR"]->isPressed() && this->isKeyTime())
        this->stackState(new EditorState(this->stateData));
}

void InitialState::update() {
    for (auto &[fst, snd]: this->buttons_)
        snd->update(static_cast<sf::Vector2f>(this->stateData->mousePositions->window));
}

void InitialState::render() {
    this->stateData->window->draw(this->background_);
    this->stateData->window->draw(this->panel_);

    for (auto &[fst, snd]: this->buttons_)
        this->stateData->window->draw(*snd);
}