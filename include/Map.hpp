#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "Node.hpp"
#include <cmath>

class Map
{

public:
    std::vector<Node *> map;

public:
    Map() {}
    Map(std::vector<sf::Vector2f> positions, std::vector<sf::Vector2i> links);
    ~Map();
    float Distance(int a, int b);
    void Init(std::vector<sf::Vector2f> positions, std::vector<sf::Vector2i> links);
};

#endif