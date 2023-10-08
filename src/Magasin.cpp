#include "Magasin.hpp"

Magasin::Magasin(Entite::Faction faction,
                 const sf::Vector2f &positionInitiale,
                 const sf::Vector2f &scale,
                 uint reserveInitiale)
    : Batiment(faction, Entite::Type::Magasin,
               positionInitiale, scale,
               reserveInitiale, MAX_SIZE_MAGASIN,
               SPAWN_RATE_MAGASIN, FLOW_RATE_MAGASIN)
{
}

Magasin::~Magasin()
{
}

std::list<Soldat *> *Magasin::libereLigneSoldat(uint nbSoldats)
{
    if (_faction == Entite::Faction::Bleu)
        return Batiment::libereSoldat(nbSoldats, Entite::Type::LugeurBleu);
    else if (_faction == Entite::Faction::Rouge)
        return Batiment::libereSoldat(nbSoldats, Entite::Type::LugeurRouge);
    else
        return nullptr;
}
