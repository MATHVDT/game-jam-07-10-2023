#ifndef __MAGASIN_HPP__
#define __MAGASIN_HPP__

#include "Batiment.hpp"

class Magasin : public Batiment
{
private:
    /* data */
public:
    Magasin(Entite::Faction faction,
            const sf::Vector2f &positionInitaile,
            const sf::Vector2f &scale,
            uint reserveInitiale);
    ~Magasin();

    virtual std::list<Soldat *> *libereLigneSoldat() override;
};

#endif