#include "Entite.hpp"

/****************************************************/
/*                    Static                        */
/****************************************************/
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
            // _textures[static_cast<uint>(pair.first)] = new sf::Texture();
            if (!_textures[static_cast<uint>(pair.first)].loadFromFile(pair.second))
                std::cout << "Erreur dans le chargement de la texture " << pair.second << " dans le sprite" << std::endl;
        }
        else
        {
            std::cout << "Le fichier " << pair.second << " n'existe pas." << std::endl;
        }
    }
}

// void Entite ::dechargerTextures()
// {
//     // for (auto text : _textures)
//     //     delete text;
// }

/****************************************************/
Entite::Entite(Entite::Type type, const sf::Vector2f &scale)
    : _type(type),
      _sprite(),
      _scale(scale)
{
    _sprite.setTexture(_textures[static_cast<uint>(type)]);
    _sprite.setPosition(0, 0);
    _sprite.setScale(_scale);
}

Entite::~Entite()
{
    // delete _texture;
}

bool Entite::chargerTexture(std::string pathTexture)
{
}
