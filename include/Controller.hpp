#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>
#include <vector>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Soldat.hpp"
#include "Batiment.hpp"

#define TIMEFRAME 0.017

class Controller
{
    /****************************************************/
    /*                      Static                      */
    /****************************************************/
private: // Static
    static Controller *_instance;

public: // Static
    static Controller *getInstance();
    /****************************************************/

private:
    sf::RenderWindow _fenetre;
    float _largeurFenetre;
    float _hauteurFenetre;

    std::vector<Batiment> _allBatiments;
    std::vector<Soldat> _allSoldats;
    std::list<Batiment *> _playerBatiments;
    std::list<Batiment *> _EnemyBatiments;

    Batiment *_batimentSelect;

public:
    ~Controller();

    void InitController();
    void InitGame();

    void Run();

    // Fenetre
    void InitFenetre(uint largeurFenetre, uint hauteurFenetre);
    void dessiner(const sf::Drawable &dessinable);
    void dessiner(const sf::Drawable *dessinable);
    void dessinerFenetre();
    void afficherFenetre();

    void boutonSourisPresse();

private:
    Controller();
};

#endif