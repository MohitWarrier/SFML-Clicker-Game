
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "enemy.h"
#include "texts.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
    private:
        bool isGameOver;
        int damage;
        sf::Texture backgroundTexture;
        std::optional<sf::Sprite> backgroundSprite;
        sf::Time time;
        Enemy enemy;
        Texts texts;

        bool loadBackground();

    public:
        GameWorld();
        bool performSetup();
        bool runGame();
};

#endif // GAMEWORLD_H