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
    int offset;
    sf::Vector2f position;
    std::vector<sf::Vector2f> speed;
    float speed_coeff;
    std::vector<sf::Vector2f> destination;

    std::tuple<float, std::vector<sf::Vector2f>> Pathfinder(std::vector<sf::Vector2f> chemin, float len, int pos, int dest, Map map, std::vector<int> id_visited);
    sf::Vector2f GetTangent(sf::Vector2f u);
    sf::Vector2f RotatePoint(sf::Vector2f center, float angle, sf::Vector2f point, float det);
    
public:
    Soldat(int offs, int pos, float s, int dest, Map map, Entite::Type type, const sf::Vector2f &scale):offset(offs),alive(true),position(map.map[pos]->position),speed(std::vector<sf::Vector2f>()),speed_coeff(s),destination(std::vector<sf::Vector2f>()),Entite(type, scale) {
        destination = std::get<std::vector<sf::Vector2f>>(Pathfinder(std::vector<sf::Vector2f>(), 0, pos, dest, map, std::vector<int>()));
        destination.erase(destination.begin());
        SetSpeed();
        SetOffset();
        }
    void Avancer(float time);
    void SetSpeed();
    void Update();
    void SetOffset();
};

#endif