#include "Igloo.hpp"

Igloo::Igloo(Entite::Faction faction,
             const sf::Vector2f &positionInitiale,
             const sf::Vector2f &scale,
             uint reserveInitiale)
    : Batiment(faction, Entite::Type::Igloo,
               positionInitiale, scale,
               reserveInitiale, MAX_SIZE_IGLOO,
               SPAWN_RATE_IGLOO, FLOW_RATE_IGLOO) {}

Igloo::~Igloo() {}

std::list<Soldat *> *Igloo::libereLigneSoldat(uint nbSoldats)
{
    if (_faction == Entite::Faction::Bleu)
        return Batiment::libereSoldat(nbSoldats, Entite::Type::PingouinBleu);
    else if (_faction == Entite::Faction::Rouge)
        return Batiment::libereSoldat(nbSoldats, Entite::Type::PingouinRouge);
    else
        return nullptr;
}
