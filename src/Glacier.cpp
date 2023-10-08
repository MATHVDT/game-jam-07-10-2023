#include "Glacier.hpp"

Glacier::Glacier(Entite::Faction faction,
                 const sf::Vector2f &positionInitiale,
                 const sf::Vector2f &scale,
                 uint reserveInitiale)
    : Batiment(faction, Entite::Type::Glacier,
               positionInitiale, scale,
               reserveInitiale, MAX_SIZE_GLACIER,
               SPAWN_RATE_GLACIER, FLOW_RATE_GLACIER)
{
}

Glacier::~Glacier()
{
}