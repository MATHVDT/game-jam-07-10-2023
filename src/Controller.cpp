#include "Controller.hpp"

Controller *Controller::_instance = nullptr;

/****************************************************/
/*                 Instanciation                    */
/****************************************************/
Controller::Controller()
    : _fenetre{}, _largeurFenetre(), _hauteurFenetre(),
      _clock(), _timeFrame(sf::seconds(TIME_FRAME)),
      _font(), _map()
{
    _batimentHover = nullptr;
    _batimentSelect = nullptr;
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
    _fenetre.clear(sf::Color(255, 255, 255));
}

void Controller::dessinerFenetre()
{
    sf::Text text;
    for (Batiment &bat : _allBatiments)
    {
        dessiner(bat.getSprite());
        // Affiche texte Reserve interne du batiment
        text.setFont(_font);
        text.setString(std::to_string(bat.getReserveInterne()));
        text.setCharacterSize(26); // exprimée en pixels, pas en points !
        text.setFillColor(bat.getColorFaction());
        text.setPosition(bat.getPosition());

        dessiner(text);
    }
    for (Soldat &soldat : _allSoldats)
    {
        dessiner(soldat.getSprite());
    }
    dessinerOverlayBatiment();
}

void Controller::dessinerOverlayBatiment()
{
    Batiment *bat = _batimentHover;
    if (bat != nullptr)
    {
        sf::RectangleShape borderHover(sf::Vector2f(bat->getSprite().getGlobalBounds().width - 10, bat->getSprite().getGlobalBounds().height - 10));
        borderHover.setFillColor(sf::Color::Transparent);
        borderHover.setOutlineThickness(8);
        borderHover.setOutlineColor(sf::Color::Yellow);
        borderHover.setPosition(bat->getSprite().getPosition().x + 5, bat->getSprite().getPosition().y + 5);
        dessiner(borderHover);
    }
    bat = _batimentSelect;
    if (bat != nullptr)
    {
        sf::RectangleShape borderSelect(sf::Vector2f(bat->getSprite().getGlobalBounds().width - 10, bat->getSprite().getGlobalBounds().height - 10));
        borderSelect.setFillColor(sf::Color::Transparent);
        borderSelect.setOutlineThickness(5);
        borderSelect.setOutlineColor(sf::Color::Black);
        borderSelect.setPosition(bat->getSprite().getPosition().x + 5, bat->getSprite().getPosition().y + 5);
        dessiner(borderSelect);
    }
}
/****************************************************/
/****************************************************/

void Controller::InitController()
{
    InitFenetre(1920, 1080);

    Entite::chargerTextures();

    if (!_font.loadFromFile(PATH_FONT))
    {
        std::cerr << "Erreur dans chargement de la font : " << PATH_FONT << std::endl;
    }
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
    _allBatiments.push_back(std::move(Igloo(Entite::Faction::Bleu,
                                            sf::Vector2f(0.f, 0.f),
                                            sf::Vector2f(0.01f, 0.01f),
                                            10)));
    _allBatiments.push_back(std::move(Igloo(Entite::Faction::Neutre,
                                            sf::Vector2f(100.f, 0.f),
                                            sf::Vector2f(0.01f, 0.01f),
                                            10)));
    _allBatiments.push_back(std::move(Igloo(Entite::Faction::Rouge,
                                            sf::Vector2f(200.f, 0.f),
                                            sf::Vector2f(0.01f, 0.01f),
                                            10)));
}

void Controller::Run()
{
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
                sourisMoved();
                break;
            case sf::Event::MouseButtonPressed:
                boutonSourisPresse();
                break;
            case sf::Event::MouseButtonReleased:
                boutonSourisRelache();
                break;

            default:
                break;
            }
        }

        if (_clock.getElapsedTime() > _timeFrame)
        {
            UpdateEntites();
            _clock.restart();
        }

        dessinerFenetre();
        afficherFenetre();

        // sf::sleep(sf::seconds(0.017));
    }
}

/****************************************************/
/*              Gestion event souris                */
/****************************************************/
Batiment *Controller::getBatimentSousSouris()
{
    sf::Vector2i mousePositionFenetre = sf::Mouse::getPosition(_fenetre);
    sf::Vector2f mousePositionMonde = _fenetre.mapPixelToCoords(mousePositionFenetre); // convertit en coordonnées mondiales
    // std::cout << "Souris (" << mousePositionMonde.x << ", " << mousePositionMonde.y << ")" << std::endl;

    for (Batiment &bat : _allBatiments)
    {
        // Vérifie si la souris est sur la zone du batiment
        if (bat.getGlobalBounds().contains(mousePositionMonde.x, mousePositionMonde.y))
        {
            // std::cout << "Souris sur batiment" << std::endl;
            return &bat;
        }
    }
    return nullptr;
}

void Controller::boutonSourisPresse()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        // Check si le clique est sur un batiment
        Batiment *batimentSousSouris = getBatimentSousSouris();

        // Clique sur un bat, select ce batiment
        if (batimentSousSouris != nullptr)
        {
            _batimentSelect = batimentSousSouris;
            // std::cout << "Batiment selectionné" << std::endl;
        }
        else // clique à coté d'un bat, déselect batiment
        {
            _batimentSelect = nullptr;
            // std::cout << "Batiment déselectionné" << std::endl;
        }
    }
}

void Controller::boutonSourisRelache()
{
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        Batiment *batimentSousSouris = getBatimentSousSouris();
        if (batimentSousSouris == nullptr)
            return;

        uint idSrc = _batimentSelect->getId();
        uint idDest = batimentSousSouris->getId();
        uint nbSoldatsDispo = _batimentSelect->getReserveInterne();
        _batimentSelect->setNbSoldatsALiberer(nbSoldatsDispo / 3,
                                              idSrc, idDest, _map);
    }
}

void Controller::sourisMoved()
{
    Batiment *batimentSousSouris = getBatimentSousSouris();
    _batimentHover = batimentSousSouris;
}

/****************************************************/
/*                     Gestion ...                  */
/****************************************************/
void Controller::LanceAttaque(Batiment *source, Batiment *destination)
{
}

void Controller::UpdateEntites()
{
    // GestionCollisionEntites();

    UpdateBatiments();
    UpdateSoldats();
}

void Controller::UpdateSoldats()
{
    for (auto it = _allSoldats.begin(); it < _allSoldats.end(); it++)
    {
        it->Update();
    }
}

void Controller::UpdateBatiments()
{
    for (Batiment &bat : _allBatiments)
    {
        bat.Update();
        if (bat.doitLibererSoldats())
        {
            bat.libereLigneSoldat();
            //     switch (bat.getType())
            //     {
            //     case Entite::Type::Magasin:
            //         dynamic_cast<Magasin &>(bat).libereLigneSoldat();
            //         break;
            //     case Entite::Type::Igloo:
            //         dynamic_cast<Magasin &>(bat).libereLigneSoldat();
            //         break;
            //     case Entite::Type::Glacier:
            //         dynamic_cast<Magasin &>(bat).libereLigneSoldat();
            //         break;
            //     default:
            //         break;
            //     }
        }
    }
}
