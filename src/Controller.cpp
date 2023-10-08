#include "Controller.hpp"

Controller *Controller::_instance = nullptr;

/****************************************************/
/*                 Instanciation                    */
/****************************************************/
Controller::Controller()
    : _fenetre{}, _largeurFenetre()
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

void Controller::dessinerFenetre()
{
    for (Batiment &bat : _allBatiments)
    {
        dessiner(bat.getSprite());
    }
    
    for (Soldat &soldat : _allSoldats)
    {
        dessiner(soldat.getSprite());
    }
}

/****************************************************/
/****************************************************/

void Controller::InitController()
{
    Entite::chargerTextures();
}

void Controller::InitGame()
{
    std::vector<sf::Vector2f> positions = std::vector<sf::Vector2f>();
    positions.push_back(sf::Vector2f(100,100));
    positions.push_back(sf::Vector2f(400,100));
    positions.push_back(sf::Vector2f(100,400));
    positions.push_back(sf::Vector2f(400,400));
   
    std::vector<sf::Vector2i> links = std::vector<sf::Vector2i>();
    //links.push_back(sf::Vector2i(0,1));
    links.push_back(sf::Vector2i(0,2));
    links.push_back(sf::Vector2i(0,3));
    //links.push_back(sf::Vector2i(2,3));
    links.push_back(sf::Vector2i(1,3));
    
    Map map = Map(positions, links);
    
    Soldat soldat = Soldat(0, 1, 100, 2, map, Entite::Type::PingouinBleu, sf::Vector2f(0.008f, 0.008f));
    Soldat soldat1 = Soldat(-20, 1, 100, 2, map, Entite::Type::PingouinBleu, sf::Vector2f(0.008f, 0.008f));
    Soldat soldat2 = Soldat(20, 1, 100, 2, map, Entite::Type::PingouinBleu, sf::Vector2f(0.008f, 0.008f));
    _allSoldats.push_back(soldat);
    _allSoldats.push_back(soldat1);
    _allSoldats.push_back(soldat2);
    // std::string path = "ressources/Bleu_luge.png";
    // std::string path = "/home/mathvdt/game-jam-07-10-2023/ressources/test.png";
    _allBatiments.push_back(std::move(Batiment(Entite::Type::Igloo, sf::Vector2f(0.01f, 0.01f))));
}

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
            case sf::Event::MouseButtonPressed:
                boutonSourisPresse();
                break;
            case sf::Event::MouseButtonReleased:
                break;

            default:
                break;
            }
        }

        dessinerFenetre();
        afficherFenetre();
        for (auto it=_allSoldats.begin();it<_allSoldats.end();it++)
        {
           it->Update();
        }
        sf::sleep(sf::seconds(0.017));
    }
}

void Controller::boutonSourisPresse()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition();
        for (int i = 0; i < _allBatiments.size(); i++)
        {
            sf::FloatRect zoneBat = _allBatiments[i].getGlobalBounds();
            if (zoneBat.contains(mousePosition.x, mousePosition.y))
                std::cout << "dedans" << std::endl;
        }
    }
}
