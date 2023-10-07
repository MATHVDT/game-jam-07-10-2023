#ifndef __BATIMENT_HPP__
#define __BATIMENT_HPP__

#include "Entite.hpp"

class Batiment : public Entite
{
private:
    /* data */
public:
    Batiment(std::string pathTexture);
    ~Batiment();
};

#endif