#include "../include/Soldat.hpp"

Soldat::Soldat(Vector2 pos, float speed, Vector2 dest, std::vector<Vector2 *> map)
{
    alive = true;
    position = pos;
    
}

std::vector<Vector2 *> Soldat::Pathfinder(Vector2 pos, Vector2 dest, std::vector<Vector2 *> map)
{
    return std::vector<Vector2 *>();
}