#include "Game.h"
#include "Debug/MousePositionsText.h"

// Constructor / Destructor
Game::Game() : window_(nullptr), sfEvent_(sf::Event()) {
    this->initFont();
    this->initWindow();
}

Game::~Game() {
    delete this->window_;
}

// Public functions
void Game::run() {
    this->particles_.init(this->window_->getSize());

    while (this->window_->isOpen()) {
        // Update delta time
        this->dt_ = this->dtClock_.restart().asSeconds();

        // Update key time
        this->updateKeyTime();
        // Update SFML events
        this->updateSFMLEvents();
        // Update mouse positions
        this->updateMousePositions();

        // Update and render
        this->update();
        this->render();
    }
}

void Game::update() {
    this->particles_.update();
}

void Game::render() const {
    this->window_->clear();

    // Render all game objects before display (player, enemies, etc...)
    this->window_->draw(this->particles_);

    // ----------------------------------------------------------------
    // DEBUG: display delta time
    std::stringstream ss;
    ss << "DeltaTime: " << this->dt_;

    DebugText debugText(this->font_, 22);
    debugText.setPosition(100, 100);
    debugText.setString(ss.str());

    this->window_->draw(debugText);

    // ----------------------------------------------------------------
    // DEBUG: display key time
    ss.str("");
    ss << "KeyTime: " << this->keyTime_;

    DebugText keyTimeText(this->font_, 22);
    keyTimeText.setPosition(100, 120);
    keyTimeText.setString(ss.str());

    this->window_->draw(keyTimeText);

    // ----------------------------------------------------------------
    // DEBUG: display mouse positions
    this->window_->draw(
            MousePositionsText(this->mousePositions_,
                    this->font_, 20));

    // END DEBUG
    // ----------------------------------------------------------------

    this->window_->display();
}

void Game::updateSFMLEvents() {
    while (this->window_->pollEvent(this->sfEvent_)) {
        if (this->sfEvent_.type == sf::Event::MouseButtonPressed) {
            this->particles_.setEmitter(sf::Mouse::getPosition(*this->window_));
        }
        if (this->sfEvent_.type == sf::Event::Closed ||
            (this->isKeyTime() && this->sfEvent_.type == sf::Event::KeyPressed && this->sfEvent_.key.code == sf::Keyboard::Escape))
            this->window_->close();
    }
}

void Game::updateMousePositions() {
    this->mousePositions_.screen = sf::Mouse::getPosition();
    this->mousePositions_.window = sf::Mouse::getPosition(*this->window_);
    this->mousePositions_.view = this->window_->mapPixelToCoords(this->mousePositions_.window);
}

void Game::updateKeyTime()
{
    if (this->keyTime_ < this->keyTimeMax_)
        this->keyTime_ += 100 * this->dt_;
}

bool Game::isKeyTime()
{
    if (this->keyTime_ >= this->keyTimeMax_)
    {
        this->keyTime_ = 0.f;
        return true;
    }

    return false;
}

// Private functions
void Game::initWindow() {
    const std::string title = "SFML Skeleton";

    this->mode_ = sf::VideoMode(1920u, 1080u);

    this->window_ = new sf::RenderWindow(this->mode_, title);
    this->window_->setFramerateLimit(144);
}

void Game::initFont() {
    if (!this->font_.loadFromFile(FONTS_PATH + "courbd.ttf"))
        throw std::runtime_error("ERROR::Game::initFont(): Failed to load font");
}