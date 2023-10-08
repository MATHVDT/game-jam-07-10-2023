#ifndef __SOLDAT_HPP__
#define __SOLDAT_HPP__

#include "Map.hpp"
#include <algorithm>
#include <tuple>
#include "Entite.hpp"
//#include "Controller.hpp"

class Soldat : public Entite {

private:
    bool alive;
    sf::Vector2f position;
    sf::Vector2f speed;
    float speed_coeff;
    std::vector<sf::Vector2f> destination;

    std::tuple<float, std::vector<sf::Vector2f>> Pathfinder(std::vector<sf::Vector2f> chemin, float len, int pos, int dest, Map map, std::vector<int> id_visited);
    
public:
    Soldat(int pos, float s, int dest, Map map, Entite::Type type, const sf::Vector2f &scale):alive(true),position(map.map[pos]->position),speed(sf::Vector2f()),speed_coeff(s),destination(std::vector<sf::Vector2f>()),Entite(type, scale) {
        destination = std::get<std::vector<sf::Vector2f>>(Pathfinder(std::vector<sf::Vector2f>(), 0, pos, dest, map, std::vector<int>()));
        destination.erase(destination.begin());
        SetNewSpeed();
        }
    void Avancer(float time);
    void SetNewSpeed();
    void Update();
};

#endif