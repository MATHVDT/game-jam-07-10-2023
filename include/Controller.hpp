#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>
#include <vector>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Magasin.hpp"
#include "Igloo.hpp"
#include "Glacier.hpp"

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
    void dessinerOverlayBatiment();
    void dessinerFenetre();
    void afficherFenetre();

    // Event souris
    Batiment *getBatimentSousSouris();
    void boutonSourisPresse();
    void boutonSourisRelache();

    // Gestion...
    void LanceAttaque(Batiment *source, Batiment *destination);

private:
    Controller();
};

#endif