//#include "Controller.hpp"
//#include <SFML/System.hpp>
#include "Soldat.hpp"

int main()
{
    /*
    Controller *controller = Controller::getInstance();

    // controller->InitFenetre(1920 / 2, 1080 / 2);

    // sf::CircleShape shape(50.f);
    // shape.setFillColor(sf::Color(150, 50, 250));
    // controller->dessiner(shape);
    // controller->afficherFenetre();

    controller->Run();

    sf::sleep(sf::seconds(5));
    */
    std::vector<sf::Vector2f> positions = std::vector<sf::Vector2f>();
    positions.push_back(sf::Vector2f(1.5,3.5));
    positions.push_back(sf::Vector2f(2.3,3.4));
    positions.push_back(sf::Vector2f(5.4,1.3));
    positions.push_back(sf::Vector2f(1.6,3.5));
   
    std::vector<sf::Vector2i> links = std::vector<sf::Vector2i>();
    links.push_back(sf::Vector2i(0,1));
    links.push_back(sf::Vector2i(0,2));
    links.push_back(sf::Vector2i(0,3));
    links.push_back(sf::Vector2i(2,3));
    links.push_back(sf::Vector2i(1,3));
    
    Map map = Map(positions, links);
    
    Soldat soldat = Soldat(0, sf::Vector2f(5,0), 1, map);

    //sf::sleep(sf::seconds(1));

    //delete controller;

    return 0;
}