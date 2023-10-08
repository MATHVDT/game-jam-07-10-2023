#ifndef __ENTITE_HPP__
#define __ENTITE_HPP__

#include <string>
#include <filesystem>
#include <iostream>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace fs = std::filesystem;

#define NB_TYPE_ENTITE 7

class Entite
{
public:
    enum class Type 
    {
        PingouinBleu,
        LugeurBleu,
        PingouinRouge,
        LugeurRouge,

        Igloo,   // Batiment de base
        Magasin, // Batiment donnant des skieurs
        Glacier, // Batiment défensive
    };

    enum class Faction : uint
    {
        Bleu,
        Rouge,
        Neutre,
    };

private: // static
    static uint compteurEntiteId;
    static sf::Texture _textures[NB_TYPE_ENTITE];
    static std::map<Type, std::string> pathTextures;

public: // static
    static void chargerTextures();

protected:
    uint _entiteId;
    Entite::Faction _faction;
    Entite::Type _type;
    sf::Sprite _sprite;
    sf::Vector2f _scale;

public:
    Entite(Entite::Faction faction, Entite::Type type,
           const sf::Vector2f &positionInitiale,
           const sf::Vector2f &scale);
    ~Entite();

    // Position
    const sf::Vector2f &getPosition() const;
    void setPosition(const sf::Vector2f &newPosition);
    void move(const sf::Vector2f &offset);

    sf::FloatRect getGlobalBounds() const;
    const sf::Sprite &getSprite() const;
    const sf::Vector2f &getScale() const;
    const Entite::Type getType() const;
    const Entite::Faction getFaction() const;

    virtual void Update() = 0;
};

/****************************************************/
/*                  Méthodes inline                 */
/****************************************************/
inline const sf::Vector2f &Entite::getPosition() const { return _sprite.getPosition(); }
inline void Entite::setPosition(const sf::Vector2f &newPosition) { _sprite.setPosition(newPosition); }
inline void Entite::move(const sf::Vector2f &offset) { _sprite.move(offset); }

inline sf::FloatRect Entite::getGlobalBounds() const { return _sprite.getGlobalBounds(); }
inline const sf::Sprite &Entite::getSprite() const { return _sprite; }
inline const sf::Vector2f &Entite::getScale() const { return _scale; }
inline const Entite::Type Entite ::getType() const { return _type; }
inline const Entite::Faction Entite ::getFaction() const { return _faction; }

#endif