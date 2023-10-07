#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Controller
{
private:
    sf::RenderWindow _fenetre;
    float _largeurFenetre;
    float _hauteurFenetre;

    /****************************************************/
    /*                      Static                      */
    /****************************************************/
private: // Static
    static Controller *_instance;

public: // Static
    static Controller *getInstance();
    /****************************************************/

private:
    Controller(/* args */);

public:
    ~Controller();

    // Fenetre
    void InitFenetre(uint largeurFenetre, uint hauteurFenetre);
    void dessiner(const sf::Drawable &dessinable);
    void dessiner(const sf::Drawable *dessinable);
    void afficherFenetre();
};

#endif