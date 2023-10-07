#include "Controller.hpp"
#include <SFML/System.hpp>

int main()
{

    Controller *controller = Controller::getInstance();

    controller->InitFenetre(1920 / 2, 1080 / 2);

    while (1)
    {
        // Pause for 2 seconds
        sf::sleep(sf::seconds(2));
        controller->afficherFenetre();
    }

    return 0;
}