#ifndef __IGLOO_HPP__
#define __IGLOO_HPP__

#include "Batiment.hpp"

class Igloo : public Batiment
{
private:
    /* data */
public:
    Igloo(Entite::Faction faction,
          const sf::Vector2f &positionInitaile,
          const sf::Vector2f &scale,
          uint reserveInitiale);
    ~Igloo();

    std::list<Soldat *> *libereLigneSoldat(uint nbSoldats);
};

#endif