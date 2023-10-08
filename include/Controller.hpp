#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>
#include <vector>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include "Soldat.hpp"
#include "Magasin.hpp"
#include "Igloo.hpp"
#include "Glacier.hpp"
#include "Map.hpp"

// #define PATH_FONT "ressources/fonts/almonte snow.otf"
#define PATH_FONT "ressources/fonts/FROSW___.TTF"
// #define PATH_FONT "ressources/fonts/Penguin-Regular.ttf"
// #define PATH_FONT "ressources/fonts/SnowtopCaps.otf"
constexpr int64_t TIME_FRAME = 0.017; // seconde

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

    sf::Clock _clock;
    sf::Time _timeFrame;

    sf::Font _font;
    Map _map;

    std::vector<Batiment> _allBatiments;
    std::list<Soldat *> _allSoldats;
    std::list<Batiment *> _playerBatiments;
    std::list<Batiment *> _EnemyBatiments;

    Batiment *_batimentSelect;
    Batiment *_batimentHover;

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
    void sourisMoved();

    // Gestion...
    void LanceAttaque(Batiment *source, Batiment *destination);
    void UpdateEntites();
    void UpdateBatiments();
    void UpdateSoldats();

    void GestionCollisionEntites();

private:
    Controller();
};

#endif