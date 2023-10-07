#include "Controller.hpp"

Controller *Controller::_instance = nullptr;

/****************************************************/
/*                 Instanciation                    */
/****************************************************/
Controller::Controller(/* args */) {}

Controller::~Controller()
{
    _fenetre.close();
}

Controller *Controller::getInstance()
{
    
    if (Controller::_instance == nullptr)
    {
        Controller::_instance = new Controller();
        if (Controller::_instance == nullptr)
        {
            std::cerr << "Erreur de new\n";
            return nullptr;
        }
    }
    return Controller::_instance;
}

/****************************************************/
/*                     Fenetre                      */
/****************************************************/
void Controller::InitFenetre(uint largeurFenetre, uint hauteurFenetre)
{
    _largeurFenetre = largeurFenetre;
    _hauteurFenetre = hauteurFenetre;

    _fenetre.create(sf::VideoMode(_largeurFenetre,
                                  _hauteurFenetre),
                    "",
                    sf::Style::Default);

    _fenetre.setPosition(sf::Vector2i(0, 0));
    _fenetre.setActive();
}

void Controller::dessiner(const sf::Drawable &dessinable)
{
    _fenetre.draw(dessinable);
}

void Controller::dessiner(const sf::Drawable *dessinable)
{
    _fenetre.draw(*dessinable);
}

/// @brief Affiche la fenetre.
void Controller::afficherFenetre()
{
    _fenetre.display();
    _fenetre.clear();
}

void Controller::dessinerFenetre()
{
    for (Batiment &bat : _allBatiments)
    {
        dessiner(bat.getSprite());
    }
}

/****************************************************/
/****************************************************/

void Controller::InitController() {}

void Controller::InitGame() {}

void Controller::Run()
{
    InitFenetre(1920 / 2, 1080 / 2);
    InitController();
    InitGame();

    while (_fenetre.isOpen())
    {
        sf::Event event;
        while (_fenetre.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                _fenetre.close();
                break;

            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseButtonReleased:
                break;

            default:
                break;
            }
        }

        afficherFenetre();
    }
}
