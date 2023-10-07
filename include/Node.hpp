#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <vector>
#include <SFML/System/Vector2.hpp>

class Node {

public:
    sf::Vector2f position;
    std::vector<int> voisin;

public:
    Node(sf::Vector2f pos):position(pos),voisin(std::vector<int>()) {}
    ~Node() {}
    Node(double x, double y):position(sf::Vector2f(x,y)),voisin(std::vector<int>()) {}
    void AddVoisin(int i);

};

#endif