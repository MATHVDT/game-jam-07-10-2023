#include "Controller.hpp"

Controller *Controller::_instance = nullptr;

/****************************************************/
/*                 Instanciation                    */
/****************************************************/
Controller::Controller(/* args */)
{
}

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
/****************************************************/
/****************************************************/