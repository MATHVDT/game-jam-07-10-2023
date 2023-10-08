#include "Entite.hpp"
/****************************************************/
/*                    Static                        */
/****************************************************/
uint Entite::compteurEntiteId = 0;

sf::Texture Entite::_textures[NB_TYPE_ENTITE];
std::map<Entite::Type, std::string> Entite::pathTextures = {
    {Type::PingouinBleu, "ressources/Bleu_normal.png"},
    {Type::LugeurBleu, "ressources/Bleu_luge.png"},
    {Type::PingouinRouge, "ressources/Rouge_normal.png"},
    {Type::LugeurRouge, "ressources/Rouge_luge.png"},
    {Type::Igloo, "ressources/Igloo.png"},
    {Type::Magasin, "ressources/test.png"},
    {Type::Glacier, "ressources/Glacier.png"},
};

void Entite::chargerTextures()
{
    for (auto pair : Entite::pathTextures)
    {
        if (fs::exists(pair.second))
        {
            if (!_textures[static_cast<uint>(pair.first)].loadFromFile(pair.second))
                std::cout << "Erreur dans le chargement de la texture " << pair.second << " dans le sprite" << std::endl;
        }
        else
        {
            std::cout << "Le fichier " << pair.second << " n'existe pas." << std::endl;
        }
    }
}

/****************************************************/
/*                 Constructeur                     */
/****************************************************/
Entite::Entite(Entite::Faction faction, Entite::Type type,
               const sf::Vector2f &initialPosition,
               const sf::Vector2f &scale)
    : _entiteId(++compteurEntiteId),
      _faction(faction),
      _type(type),
      _sprite(), _scale(scale)
{
    _sprite.setTexture(_textures[static_cast<uint>(type)]);
    _sprite.setPosition(initialPosition);
    _sprite.setScale(_scale);
    switch (_faction)
    {
    case Faction::Bleu:
        _sprite.setColor(sf::Color(0, 0, 255));
        break;
    case Faction::Rouge:
        _sprite.setColor(sf::Color(255, 0, 0));
        break;
    case Faction::Neutre:
        _sprite.setColor(sf::Color(128, 128, 128));
        break;
    default:

        break;
    }
}

Entite::~Entite() {}
