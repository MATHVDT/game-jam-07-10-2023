#ifndef __BATIMENT_HPP__
#define __BATIMENT_HPP__

#include <list>

#include "Entite.hpp"
#include "Soldat.hpp"
#include "Map.hpp"

// Magasin
#define RESERVE_INTERNE_ MAGASIN 0
#define MAX_SIZE_MAGASIN 50
#define SPAWN_RATE_MAGASIN 0.016
#define FLOW_RATE_MAGASIN 0.02

// Igloo
#define RESERVE_INTERNE_IGLOO 0
#define MAX_SIZE_IGLOO 50
#define SPAWN_RATE_IGLOO 0.016
#define FLOW_RATE_IGLOO 0.015

// Glacier
#define RESERVE_INTERNE_GLACIER 0
#define MAX_SIZE_GLACIER 20
#define SPAWN_RATE_GLACIER 0
#define FLOW_RATE_GLACIER 0.015

class Batiment : public Entite
{

private:
    uint _reserveInterne;
    uint _maxSize;
    float _spawnRate;
    float _flowRate;

    float _spawnDeltaFrame;
    float _flowDeltaFrame;
    int _nbSoldatsALiberer;

public:
    Batiment(Entite::Faction faction, Entite::Type type,
             const sf::Vector2f &positionInitiale,
             const sf::Vector2f &scale,
             uint reserveInterne, uint maxSize,
             float spawnRate, float flowRate);
    ~Batiment();

    virtual void Update() override;

    uint getReserveInterne() const;
    bool setNbSoldatsALiberer(uint nbSoldats,
                              uint idSource, uint idDest,
                              Map &map);
    bool doitLibererSoldats() const;
    virtual std::list<Soldat *> *libereLigneSoldat() { return nullptr; }

    bool prendreDegat(Entite::Faction factionAttaquant);

protected:
    std::list<Soldat *> *libereLigneSoldat(Entite::Type typeSoldat);
};

/****************************************************/
/*                  Méthodes inline                 */
/****************************************************/
inline uint Batiment::getReserveInterne() const { return _reserveInterne; }
inline bool Batiment::doitLibererSoldats() const { return _nbSoldatsALiberer > 0; }

#endif