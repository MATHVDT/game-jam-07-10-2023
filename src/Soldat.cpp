#include "../include/Soldat.hpp"

std::tuple<float, std::vector<sf::Vector2f>> Soldat::Pathfinder(std::vector<sf::Vector2f> chemin, float len, int pos, int dest, Map map, std::vector<int> id_visited)
{
    if (pos==dest)
    {
        chemin.push_back(map.map[pos]->position);
        return std::tuple<float, std::vector<sf::Vector2f>>(len, chemin);
    }
    std::tuple<float, std::vector<sf::Vector2f>> res = std::tuple<float, std::vector<sf::Vector2f>>(__FLT_MAX__, chemin);
    chemin.push_back(map.map[pos]->position);
    id_visited.push_back(pos);
    for (auto it=map.map[pos]->voisin.begin();it<map.map[pos]->voisin.end();it++)
    {
        if (std::find(id_visited.begin(), id_visited.end(), *it) == id_visited.end())
        {
            std::tuple<float, std::vector<sf::Vector2f>> temp = this->Pathfinder(chemin, len + map.Distance(pos, *it), *it, dest, map, id_visited);
            if (std::get<float>(temp) < std::get<float>(res))
            {
                res = temp;
            }
        }
    }
    return res;
}

void Soldat::Avancer(float time)
{
    sf::Vector2f before = position - destination[0];
    sf::Vector2f new_pos = position + speed * time;
    sf::Vector2f after = new_pos - destination[0];
    if (before.x * after.x < 0 or before.y * after.y < 0)
    // on est allé trop loin dans le déplacement
    {
        time = time - ((destination[0].x - position.x) / speed.x);
        position = destination[0];
        destination.erase(destination.begin());
        if (!destination.empty())
        {
            SetNewSpeed();
            position = position + speed * time;
        }
        else 
        {
            speed.x=0;
            speed.y=0;
        }
    }
    else {position = new_pos;}
    _sprite.setPosition(position.x, position.y);
}

void Soldat::SetNewSpeed() {
    speed = destination[0] - position;
    float temp = std::sqrt(pow(speed.x,2)+pow(speed.y,2));
    speed.x = speed.x / temp * speed_coeff;
    speed.y = speed.y / temp * speed_coeff;
}

void Soldat::Update() 
{
    Avancer(0.017);
}