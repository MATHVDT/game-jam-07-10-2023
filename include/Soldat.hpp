#ifndef __SOLDAT_HPP__
#define __SOLDAT_HPP__

#include "Map.hpp"
#include <algorithm>
#include <tuple>

class Soldat {

private:
    bool alive;
    sf::Vector2f position;
    float speed;
    std::vector<sf::Vector2f*> destination;

    std::tuple<float, std::vector<sf::Vector2f *>> Pathfinder(std::vector<sf::Vector2f *> chemin, float len, int pos, int dest, Map map, std::vector<int> id_visited);
    
public:
    Soldat(int pos, float s, int dest, Map map):alive(true),position(map.map[pos]->position),speed(s),destination(std::vector<sf::Vector2f*>()) {
        destination = std::get<std::vector<sf::Vector2f*>>(Pathfinder(std::vector<sf::Vector2f *>(), 0, pos, dest, map, std::vector<int>()));
        }
};

#endif