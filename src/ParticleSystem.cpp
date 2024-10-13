#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() : size_(5.f) {
}

ParticleSystem::~ParticleSystem() = default;

void ParticleSystem::init(const sf::Vector2u size) {
    this->windowSize_ = size;
    this->reset();
}

void ParticleSystem::update() {
    for (std::size_t i = 0; i < this->particles_.size(); i++) {
        if (this->particles_[i].lifetime == 0)
            resetParticle(i);

        this->vertices_[4 * i + 0].position += this->particles_[i].velocity;
        this->vertices_[4 * i + 1].position += this->particles_[i].velocity;
        this->vertices_[4 * i + 2].position += this->particles_[i].velocity;
        this->vertices_[4 * i + 3].position += this->particles_[i].velocity;

        this->particles_[i].lifetime--;
    }
}

void ParticleSystem::reset(const size_t count, const float size) {
    this->particles_ = std::vector<Particle>(count);
    this->vertices_ = sf::VertexArray(sf::Quads, count * 4);
    this->size_ = size;

    for (size_t p = 0; p < this->particles_.size(); p++) {
        this->resetParticle(p, true);
    }
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->vertices_);
}

void ParticleSystem::resetParticle(const size_t index, const bool first) {
    // Give the particle an initial position
    const float mx = static_cast<float>(this->windowSize_.x) / 2;
    const float my = static_cast<float>(this->windowSize_.y) / 2;

    this->vertices_[4 * index + 0].position = sf::Vector2f(mx, my);
    this->vertices_[4 * index + 1].position = sf::Vector2f(mx + this->size_, my);
    this->vertices_[4 * index + 2].position = sf::Vector2f(mx + this->size_, my + this->size_);
    this->vertices_[4 * index + 3].position = sf::Vector2f(mx, my + this->size_);

    // Give the particle a color
    sf::Color color(rand() % 255, 0, 0, rand() % 255);

    if (first)
        color.a = 0;

    this->vertices_[4 * index + 0].color = color;
    this->vertices_[4 * index + 1].color = color;
    this->vertices_[4 * index + 2].color = color;
    this->vertices_[4 * index + 3].color = color;

    // Give the particle velocity
    float rx = ((float) rand() / RAND_MAX) * 10.f - 5.f;
    float ry = ((float) rand() / RAND_MAX) * 10.f - 5.f;

    this->particles_[index].velocity = sf::Vector2f(rx, ry);

    // Give the particle a lifespan
    this->particles_[index].lifetime = 72 + rand() % 144;
}
