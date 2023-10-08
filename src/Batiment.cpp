#include "Batiment.hpp"

Batiment::Batiment(Entite::Faction faction, Entite::Type type,
                   const sf::Vector2f &initialPosition,
                   const sf::Vector2f &scale)
    : Entite(faction, type, initialPosition, scale) {}

Batiment::~Batiment() {}