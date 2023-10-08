#include "Batiment.hpp"




Batiment::Batiment(Entite::Faction faction, Entite::Type type,
                   const sf::Vector2f &positionInitiale,
                   const sf::Vector2f &scale,
                   uint reserveInterne, uint maxSize,
                   float spawnRate, float flowRate)
    : Entite(faction, type, positionInitiale, scale),
      _reserveInterne(reserveInterne), _maxSize(maxSize),
      _spawnRate(spawnRate), _flowRate(flowRate) {}

Batiment::~Batiment() {}