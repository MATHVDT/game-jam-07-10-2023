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

std::list<Soldat *> *Glacier::libereLigneSoldat(uint nbSoldats)
{
    if (_faction == Entite::Faction::Bleu)
        return Batiment::libereSoldat(nbSoldats, Entite::Type::PingouinBleu);
    else if (_faction == Entite::Faction::Rouge)
        return Batiment::libereSoldat(nbSoldats, Entite::Type::PingouinRouge);
    else
        return nullptr;
}
