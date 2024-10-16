#include "Game.h"

// Constructor / Destructor
Game::Game() : dt_(0.f), window_(nullptr), sfEvent_(sf::Event()) {
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

        // Update SFML events
        this->updateSFMLEvents();

        // Update and render
        this->update();
        this->render();
    }
}

void Game::updateSFMLEvents() {
    while (this->window_->pollEvent(this->sfEvent_)) {
        if (this->sfEvent_.type == sf::Event::MouseButtonPressed) {
            this->particles_.setEmitter(sf::Mouse::getPosition(*this->window_));
        }
        if (this->sfEvent_.type == sf::Event::Closed ||
            (this->sfEvent_.type == sf::Event::KeyPressed && this->sfEvent_.key.code == sf::Keyboard::Escape))
            this->window_->close();
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

    DebugText debugText(this->font_, 20);
    debugText.setPosition(200, 200);
    debugText.setString(ss.str());

    this->window_->draw(debugText);
    // END DEBUG
    // ----------------------------------------------------------------

    this->window_->display();
}

// Private functions
void Game::initWindow() {
    const std::string title = "SFML Skeleton";

    this->mode_ = sf::VideoMode(1920u, 1080u);

    this->window_ = new sf::RenderWindow(this->mode_, title);
    this->window_->setFramerateLimit(144);
}

void Game::initFont() {
    if (!this->font_.loadFromFile(FONTS_PATH + "arialbd.ttf"))
        throw std::runtime_error("ERROR::Game::initFont(): Failed to load font");
}
