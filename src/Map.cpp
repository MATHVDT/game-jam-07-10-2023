#include "../include/Map.hpp"

Map::Map(std::vector<sf::Vector2f> positions, std::vector<sf::Vector2i> links)
{
    map = std::vector<Node*>();
    for (auto it=positions.begin();it<positions.end();it++)
    {
        map.push_back(new Node(it->x,it->y));
    }
    
    for (auto it=links.begin();it<links.end();it++)
    {
        map[it->x]->AddVoisin(it->y);
        map[it->y]->AddVoisin(it->x);
    }
}

Map::~Map()
{
    for (auto it=map.begin();it<map.end();it++)
    {
        //delete *it;
    } 
}

float Map::Distance(int a, int b)
{
    return std::sqrt(pow(map[a]->position.x - map[b]->position.x, 2) + pow(map[a]->position.y - map[b]->position.y, 2));
}