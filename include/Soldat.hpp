#ifndef __SOLDAT_HPP__
#define __SOLDAT_HPP__

#include "Vector2.hpp"
#include <vector>

class Soldat {

private:
    bool alive;
    Vector2 position;
    float speed;
    std::vector<Vector2*> destination;

    std::vector<Vector2*> Pathfinder(Vector2 pos, Vector2 dest, std::vector<Vector2*> map);
    
public:
    Soldat(Vector2 pos, float speed, Vector2 dest, std::vector<Vector2*> map);
};

#endif