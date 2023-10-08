#include "Batiment.hpp"

Batiment::Batiment(Entite::Faction faction, Entite::Type type,
                   const sf::Vector2f &positionInitiale,
                   const sf::Vector2f &scale,
                   uint reserveInterne, uint maxSize,
                   float spawnRate, float flowRate)
    : Entite(faction, type, positionInitiale, scale),
      _reserveInterne(reserveInterne), _maxSize(maxSize),
      _spawnRate(spawnRate), _flowRate(flowRate),
      _spawnDeltaFrame(0), _flowDeltaFrame(0), _nbSoldatsALiberer(0) {}

Batiment::~Batiment() {}

void Batiment::Update()
{
  // Ajoute un soldat à la réserve
  if (_spawnDeltaFrame > 3.f) // Pk 3 je sais pas comme ca
  {
    _reserveInterne += (_reserveInterne < _maxSize ? 1 : _maxSize);
    _spawnDeltaFrame = 0;
  }
  else
  {
    _spawnDeltaFrame += _spawnRate;
  }

  // if (_nbSoldatsALiberer > 0)
  // {
  //   if (_nbSoldatsALiberer > 1)
  //     if (_nbSoldatsALiberer > 2)
  //       libereLigneSoldat(3);
  //     else
  //       libereLigneSoldat(2);
  //   else
  //     libereLigneSoldat(1);
  // }
}

/// @brief Ajoute le nb de soldats à liberer et calcul le pathFinding
/// @param nbSoldats
/// @return
bool Batiment::setNbSoldatsALiberer(uint nbSoldats,
                                    uint idSource, uint idDest,
                                    Map &map)
{
  if (nbSoldats < _reserveInterne)
  {
    // Ajoute pathfinding
    _nbSoldatsALiberer = nbSoldats;
    return true;
  }
  else
  {
    // _pathFinding = nullptr; // delete
    return false;
  }
}

std::list<Soldat *> *Batiment::libereLigneSoldat(Entite::Type typeSoldat)
{
  // Libère 3 soldats
  if (_flowDeltaFrame > 3.f)
  {
    // _reserveInterne += (_reserveInterne < _maxSize ? 1 : _maxSize);
    _flowDeltaFrame = 0;

    if (_reserveInterne > 3)
    {
      std::list<Soldat *> *list = new std::list<Soldat *>();

      int offset = 20;
      // if (nbSoldats == 0)
      //   return;
      // else if (nbSoldats == 1)
      //   offset = 0;
      // else if (nbSoldats == 2)
      //   offset = 15;
      // else if (offset == 3)
      //   offset = 20;

      for (int i = -1; i < 3 - 1; i++)
      {
        // i*offset
        // list->push_back(new Soldat())
      }

      _reserveInterne -= 3;
      if (_reserveInterne <= 0)
      {
        // Reset pathfinding
      }
      // Offset, id bat source, vitesse, id bat arrivé, map
      // Soldat soldat = Soldat(0, 1, 100, 2, map, typeSoldat, sf::Vector2f(0.008f, 0.008f));
      // Soldat soldat1 = Soldat(-20, 1, 100, 2, map, typeSoldat, sf::Vector2f(0.008f, 0.008f));
      // Soldat soldat2 = Soldat(20, 1, 100, 2, map, typeSoldat, sf::Vector2f(0.008f, 0.008f));
    }
    else
    { // Peut plus liberer de soldat
      _flowDeltaFrame = 0;
    }
  }
  else
  {
    _flowDeltaFrame += _flowRate;
  }
}
