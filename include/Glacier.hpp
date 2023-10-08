#ifndef __GLACIER_HPP__
#define __GLACIER_HPP__

#include "Batiment.hpp"

class Glacier : public Batiment
{
private:
    /* data */
public:
    Glacier(Entite::Faction faction,
            const sf::Vector2f &positionInitaile,
            const sf::Vector2f &scale,
            uint reserveInitiale);
    ~Glacier();
};

#endif