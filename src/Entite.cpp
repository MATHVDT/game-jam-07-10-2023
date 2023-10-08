#include "Entite.hpp"

/****************************************************/
/*                    Static                        */
/****************************************************/
uint Entite::compteurEntiteId = 0;

sf::Texture Entite::_textures[NB_TYPE_ENTITE];
std::map<Entite::Type, std::string> Entite::pathTextures = {
    {Type::PingouinBleu, "ressources/imgs/Bleu_normal.png"},
    {Type::LugeurBleu, "ressources/imgs/Bleu_luge.png"},
    {Type::PingouinRouge, "ressources/imgs/Rouge_normal.png"},
    {Type::LugeurRouge, "ressources/imgs/Rouge_luge.png"},
    {Type::Igloo, "ressources/imgs/Igloo.png"},
    {Type::Magasin, "ressources/imgs/test.png"},
    {Type::Glacier, "ressources/imgs/Glacier.png"},
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
               const sf::Vector2f &positionInitiale,
               const sf::Vector2f &scale)
    : _entiteId(++compteurEntiteId),
      _faction(faction),
      _type(type),
      _sprite(), _scale(scale)
{
    _sprite.setTexture(_textures[static_cast<uint>(type)]);
    _sprite.setPosition(positionInitiale);
    _sprite.setScale(_scale);
    // _sprite.setColor(getColorFaction());
}

Entite::~Entite() {}

const sf::Color Entite::getColorFaction()
{
    switch (_faction)
    {
    case Faction::Bleu:
        return sf::Color(0, 0, 255);
    case Faction::Rouge:
        return sf::Color(255, 0, 0);
    case Faction::Neutre:
        return sf::Color(128, 128, 128);
    default:
        return sf::Color::Black;
    }
}