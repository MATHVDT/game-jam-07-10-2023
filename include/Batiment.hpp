#ifndef __BATIMENT_HPP__
#define __BATIMENT_HPP__

#include "Entite.hpp"

// Magasin
#define RESERVE_INTERNE_ MAGASIN 0
#define MAX_SIZE_MAGASIN 50
#define SPAWN_RATE_MAGASIN 1
#define FLOW_RATE_MAGASIN 5

// Igloo
#define RESERVE_INTERNE_IGLOO 0
#define MAX_SIZE_IGLOO 50
#define SPAWN_RATE_IGLOO 1
#define FLOW_RATE_IGLOO 1

// Glacier
#define RESERVE_INTERNE_GLACIER 0
#define MAX_SIZE_GLACIER 20
#define SPAWN_RATE_GLACIER 0
#define FLOW_RATE_GLACIER 1

class Batiment : public Entite
{

private:
    uint _reserveInterne;
    uint _maxSize;
    float _spawnRate;
    float _flowRate;

public:
    Batiment(Entite::Faction faction, Entite::Type type,
             const sf::Vector2f &positionInitiale,
             const sf::Vector2f &scale,
             uint reserveInterne, uint maxSize,
             float spawnRate, float flowRate);
    ~Batiment();

    virtual void Update() {}

    uint getReserveInterne() const;
};

/****************************************************/
/*                  Méthodes inline                 */
/****************************************************/
inline uint Batiment::getReserveInterne() const { return _reserveInterne; }

#endif