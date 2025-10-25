
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    private:
        sf::Texture enemyTexture;
        std::optional<sf::Sprite> enemySprite;
        sf::SoundBuffer enemySoundBuffer;
        std::optional<sf::Sound> attackSound;

    public:
        int energy;
        Enemy(int);
        bool performSetup();
        bool checkIfHit(sf::Vector2i);
        bool takeDamage(int);
        void drawEnemy(sf::RenderWindow *);
};

#endif // ENEMY_H