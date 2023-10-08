#ifndef __SOLDAT_HPP__
#define __SOLDAT_HPP__

#include "Map.hpp"
#include <algorithm>
#include <tuple>

class Soldat {

private:
    bool alive;
    sf::Vector2f position;
    sf::Vector2f speed;
    float speed_coeff;
    std::vector<sf::Vector2f> destination;

    std::tuple<float, std::vector<sf::Vector2f>> Pathfinder(std::vector<sf::Vector2f> chemin, float len, int pos, int dest, Map map, std::vector<int> id_visited);
    
public:
    Soldat(int pos, float s, int dest, Map map):alive(true),position(map.map[pos]->position),speed(sf::Vector2f()),speed_coeff(s),destination(std::vector<sf::Vector2f>()) {
        destination = std::get<std::vector<sf::Vector2f>>(Pathfinder(std::vector<sf::Vector2f>(), 0, pos, dest, map, std::vector<int>()));
        SetNewSpeed();
        }
    void Avancer(float time);
    void SetNewSpeed();
};

#endif