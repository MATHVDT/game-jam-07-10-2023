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
    if (destination.empty())
    {
        return;
    }
    sf::Vector2f before = position - destination[0];
    sf::Vector2f new_pos = position + speed[0] * time;
    sf::Vector2f after = new_pos - destination[0];
    if (before.x * after.x < 0 or before.y * after.y < 0)
    // on est allé trop loin dans le déplacement
    {
        if (abs(speed[0].x) < 0.000000001)
        {
            time = time - ((destination[0].y - position.y) / speed[0].y);  
        }
        else
        {
            time = time - ((destination[0].x - position.x) / speed[0].x);    
        }
        position = destination[0];
        destination.erase(destination.begin());
        speed.erase(speed.begin());
        position = position + speed[0] * time;
    }
    else {position = new_pos;}
    _sprite.setPosition(position.x, position.y);
}

void Soldat::SetSpeed() {
    sf::Vector2f currentpos = position;
    sf::Vector2f speedtemp;
    float temp;
    for (auto &dest : destination)
    {
        speedtemp = dest - currentpos;
        temp = std::sqrt(pow(speedtemp.x,2)+pow(speedtemp.y,2));
        speedtemp.x = speedtemp.x / temp * speed_coeff;
        speedtemp.y = speedtemp.y / temp * speed_coeff;
        speed.push_back(speedtemp);
        currentpos = dest;
    }
    speed.push_back(sf::Vector2f(0,0));
}

void Soldat::Update() 
{
    Avancer(0.017);
}

void Soldat::SetOffset()
{
    //when soldiers spawn
    sf::Vector2f tangent = GetTangent(speed[0]);
    position.x = position.x + tangent.x * offset;
    position.y = position.y - tangent.y * offset;
    
    float theta;
    sf::Vector2f middledest;
    int id = 0;
    float turnoffset, det;
    for (auto it = destination.begin(); it < destination.end()-1; it++)
    {
        theta = std::acos((speed[id].x * speed[id+1].x + speed[id+1].y * speed[id].y)/pow(speed_coeff,2));
        tangent = GetTangent(speed[id]);
        middledest = *it;
        turnoffset = offset / std::sin(theta/2);
        det = speed[id].x * speed[id+1].y - speed[id+1].x * speed[id].y;
        it->x = it->x + tangent.x * turnoffset;
        it->y = it->y + tangent.y * turnoffset;
        *it = RotatePoint(middledest, theta/2, *it, det);
        id++;
    }
    
    //when soldiers get to their destination
    tangent = GetTangent(speed[speed.size()-2]); //last element of speed is always (0,0)
    destination[destination.size()-1].x = destination[destination.size()-1].x + tangent.x * offset;
    destination[destination.size()-1].y = destination[destination.size()-1].y - tangent.y * offset;
}

sf::Vector2f Soldat::GetTangent(sf::Vector2f u)
{
    sf::Vector2f result = sf::Vector2f();
    if (u.y != 0)
    {
        result.y = -(u.x/u.y);
        float temp = std::sqrt(1+pow(result.y,2));
        result.x = 1 / temp;
        result.y = result.y / temp;
    }
    else 
    {
        if (u.x <0) result.y = -1;
        else result.y = 1;
    }
    return result;
}

sf::Vector2f Soldat::RotatePoint(sf::Vector2f center, float angle, sf::Vector2f point, float det)
{
    float s,c;
    if (det<0)
    {
        s = std::sin(angle);
        c = -std::cos(angle);
    }
    else    
    {
        s = std::sin(angle);
        c = std::cos(angle);
    }

    // translate point back to origin:
    point = point - center;
    
    // rotate point
    float xnew = point.x * c - point.y * s;
    float ynew = point.x * s + point.y * c;

    // translate point back:
    point.x = xnew + center.x;
    point.y = ynew + center.y;
    return point;
}