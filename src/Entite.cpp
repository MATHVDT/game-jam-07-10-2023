#include "Entite.hpp"

Entite::Entite(std::string pathTexture) : _sprite{new sf::Sprite()}
{
    chargerTexture(pathTexture);
}

Entite::~Entite()
{
    delete _sprite->getTexture();
    delete _sprite;
}

bool Entite::chargerTexture(std::string pathTexture)
{
    if (fs::exists(pathTexture))
    {
        sf::Texture *texture = new sf::Texture();
        if (texture->loadFromFile(pathTexture))
            _sprite->setTexture(*texture);
        else
            std::cerr << "Erreur dans le chargement de la texture " << pathTexture << " dans le sprite" << std::endl;
    }
    else
    {
        std::cerr << "Le fichier" << pathTexture << "n'existe pas." << std::endl;
    }
}