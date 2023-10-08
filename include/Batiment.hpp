#ifndef __BATIMENT_HPP__
#define __BATIMENT_HPP__

#include "Entite.hpp"

class Batiment : public Entite
{
private:
    /* data */
public:
    Batiment(Entite::Type type, const sf::Vector2f &scale);
    ~Batiment();

    virtual void Update() {}
};

#endif