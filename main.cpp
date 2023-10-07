#include "Controller.hpp"
#include <SFML/System.hpp>

int main()
{

    Controller *controller = Controller::getInstance();

    controller->InitFenetre(1920 / 2, 1080 / 2);
    
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(150, 50, 250));
    controller->dessiner(shape);
    controller->afficherFenetre();

    sf::sleep(sf::seconds(5));

    return 0;
}