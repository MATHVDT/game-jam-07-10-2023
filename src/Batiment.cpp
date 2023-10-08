#include "Batiment.hpp"

Batiment::Batiment(Entite::Faction faction, Entite::Type type,
                   const sf::Vector2f &positionInitiale,
                   const sf::Vector2f &scale,
                   uint reserveInterne, uint maxSize,
                   float spawnRate, float flowRate)
    : Entite(faction, type, positionInitiale, scale),
      _reserveInterne(reserveInterne), _maxSize(maxSize),
      _spawnRate(spawnRate), _flowRate(flowRate),
      _spawnDeltaFrame(0) {}

Batiment::~Batiment() {}

void Batiment::Update()
{
  if (_spawnDeltaFrame > 3.f)
  {
    _reserveInterne += (_reserveInterne < _maxSize ? 1 : _maxSize);
    _spawnDeltaFrame = 0;
  }
  else
  {
    _spawnDeltaFrame += _spawnRate;
  }
}
