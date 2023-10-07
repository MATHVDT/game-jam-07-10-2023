#ifndef __ENTITE_HPP__
#define __ENTITE_HPP__

#include <string>
#include <filesystem>
#include <iostream>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace fs = std::filesystem;

class Entite
{
protected:
    sf::Sprite *_sprite;

public:
    Entite(std::string pathTexture);
    ~Entite();

    // Position
    const sf::Vector2f &getPosition() const;
    void setPosition(const sf::Vector2f &newPosition);
    void move(const sf::Vector2f &offset);

    sf::FloatRect getGlobalBounds() const;

    virtual void Update() = 0;

private:
    bool chargerTexture(std::string pathTexture);
};

/****************************************************/
/*                  Méthodes inline                 */
/****************************************************/
inline const sf::Vector2f &Entite::getPosition() const { return _sprite->getPosition(); }
inline void Entite::setPosition(const sf::Vector2f &newPosition) { _sprite->setPosition(newPosition); }
inline void Entite::move(const sf::Vector2f &offset) { _sprite->move(offset); }

inline sf::FloatRect Entite::getGlobalBounds() const { return _sprite->getGlobalBounds(); }

#endif