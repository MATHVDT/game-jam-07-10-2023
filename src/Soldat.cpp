#include "../include/Soldat.hpp"

std::tuple<float, std::vector<sf::Vector2f *>> Soldat::Pathfinder(std::vector<sf::Vector2f *> chemin, float len, int pos, int dest, Map map, std::vector<int> id_visited)
{
    if (pos==dest)
    {
        chemin.push_back(&map.map[pos]->position);
        return std::tuple<float, std::vector<sf::Vector2f *>>(len, chemin);
    }
    std::tuple<float, std::vector<sf::Vector2f *>> res = std::tuple<float, std::vector<sf::Vector2f *>>(__FLT_MAX__, chemin);
    chemin.push_back(&map.map[pos]->position);
    id_visited.push_back(pos);
    for (auto it=map.map[pos]->voisin.begin();it<map.map[pos]->voisin.end();it++)
    {
        if (std::find(id_visited.begin(), id_visited.end(), *it) == id_visited.end())
        {
            std::tuple<float, std::vector<sf::Vector2f *>> temp = this->Pathfinder(chemin, len + map.Distance(pos, *it), *it, dest, map, id_visited);
            if (std::get<float>(temp) < std::get<float>(res))
            {
                res = temp;
            }
        }
    }
    return res;
}