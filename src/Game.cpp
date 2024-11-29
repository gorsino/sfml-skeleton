#include "Game.h"

/// Constructor / Destructor
Game::Game() : window_(nullptr), sfEvent_(sf::Event()), stateData_(StateData()) {
    this->initFont();
    this->initWindow();
    this->initState();
}

Game::~Game() {
    while (!this->states_.empty()) {
        delete this->states_.top();
        this->states_.pop();
    }

    delete this->window_;
}

/// Public functions
void Game::run() {
    while (this->window_->isOpen()) {
        // Update delta time
        this->dt_ = this->dtClock_.restart().asSeconds();

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
    // End Game
    if (this->states_.empty())
        this->window_->close();
    else {
        // Update current active state
        this->states_.top()->updateInput(this->dt_);
        this->states_.top()->update(this->dt_);

        if (this->states_.top()->isExit()) {
            delete this->states_.top();
            this->states_.pop();
        }
    }
}

void Game::render() const {
    /// Clear before drawing
    this->window_->clear();

    /// Draw active state
    if (!this->states_.empty())
        this->states_.top()->render();

    /// DEBUG START
    this->debugDeltaTime();
    this->debugMousePositions();

    this->window_->draw(*this->stateData_.debug);
    /// DEBUG END

    this->window_->display();
}

void Game::updateSFMLEvents() {
    while (this->window_->pollEvent(this->sfEvent_)) {
        // Toggle active DebugSystem
        if (this->sfEvent_.key.code == sf::Keyboard::T && this->states_.top()->isKeyTime())
            this->stateData_.debug->toggleActive();

        // End Game/Application
        if (this->sfEvent_.type == sf::Event::Closed || (
                this->sfEvent_.type == sf::Event::KeyPressed && this->sfEvent_.key.code == sf::Keyboard::Escape && this
                ->states_.top()->isKeyTime()))
            this->window_->close();
    }
}

void Game::updateMousePositions() {
    this->mousePositions_.screen = sf::Mouse::getPosition();
    this->mousePositions_.window = sf::Mouse::getPosition(*this->window_);
    this->mousePositions_.view = this->window_->mapPixelToCoords(this->mousePositions_.window);
}

void Game::debugDeltaTime() const {
    std::stringstream ss;
    ss << "DeltaTime: " << this->dt_;

    DebugText deltaTimeText(this->font_, 22);
    deltaTimeText.setPosition(100, 100);
    deltaTimeText.setString(ss.str());

    this->stateData_.debug->add(deltaTimeText, DELTA_TIME, sf::Vector2f(20, 80));
}

void Game::debugMousePositions() const {
    MousePositionsText mousePositionsText(this->mousePositions_, this->font_, 20);

    this->stateData_.debug->add(mousePositionsText, MOUSE_POSITIONS, sf::Vector2f(20, 140));
}

// Private functions
void Game::initWindow() {
    const std::string title = "SFML Skeleton";

    this->mode_ = sf::VideoMode(1920u, 1080u);

    this->window_ = new sf::RenderWindow(this->mode_, title, sf::Style::Titlebar | sf::Style::Close);
    this->window_->setFramerateLimit(144);
}

void Game::initFont() {
    if (!this->font_.loadFromFile(FONTS_PATH + "courbd.ttf"))
        throw std::runtime_error("ERROR::Game::initFont(): Failed to load font");
}

void Game::initState() {
    this->stateData_.window = this->window_;
    this->stateData_.videoMode = &this->mode_;
    this->stateData_.font = &this->font_;
    this->stateData_.states = &this->states_;
    this->stateData_.debug = new DebugSystem(sf::Vector2f(10, 100), sf::Vector2f(300, 500), this->font_);

    this->states_.push(new GameState(this->stateData_));
}