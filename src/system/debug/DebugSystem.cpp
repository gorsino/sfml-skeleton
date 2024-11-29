#include "DebugSystem.h"

DebugSystem::DebugSystem(sf::Vector2f position, sf::Vector2f size, const sf::Font& font)
    : active_(true)
{
    auto color = WET_ASPHALT;
    color.a = 100;

    this->container_ = sf::RectangleShape(size);
    this->container_.setFillColor(color);

    this->setPosition(position);

    this->title_ = sf::Text("DEBUG", font, 24);
    this->title_.setFillColor(CLOUDS);
    this->title_.setPosition(
        sf::Vector2f(
            (static_cast<float>(this->container_.getSize().x) - this->title_.getGlobalBounds().getSize().x) / 2,
            this->container_.getPosition().y + 20)
    );
}

DebugSystem::~DebugSystem() = default;

void DebugSystem::toggleActive()
{
    this->active_ = !this->active_;
}

bool DebugSystem::getActive() const
{
    return this->active_;
}

void DebugSystem::add(DebugText& debugText, int index, const sf::Vector2f offsetPos)
{
    debugText.setPosition(
        sf::Vector2f(
            this->container_.getPosition().x + offsetPos.x,
            this->container_.getPosition().y + offsetPos.y)
    );

    this->debugTexts_.erase(index);
    this->debugTexts_.emplace(index, debugText);
}

void DebugSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (this->active_)
    {
        states.transform *= getTransform();

        states.texture = nullptr;

        target.draw(this->container_, states);
        target.draw(this->title_, states);

        for (const auto& [fst, snd] : this->debugTexts_)
            target.draw(snd, states);
    }
}