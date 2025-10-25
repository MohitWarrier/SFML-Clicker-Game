#include "enemy.h"
#include <iostream>

Enemy::Enemy(int initEnergy)
{
    energy = initEnergy;
}

bool Enemy::performSetup()
{
    if (!enemyTexture.loadFromFile("Assets/enemy.png"))
    {
        std::cerr << "Failed to load enemy texture!" << std::endl;
        return false;
    }
    enemySprite.emplace(enemyTexture);
    enemySprite->setScale(sf::Vector2f(2.f, 2.f));
    enemySprite->setPosition(sf::Vector2f(225.f, 400.f));

    if (!enemySoundBuffer.loadFromFile("Assets/damage.ogg"))
    {
        std::cerr << "Failed to load enemy sound!" << std::endl;
        return false;
    }
    attackSound.emplace(enemySoundBuffer);

    return true;
}

void Enemy::drawEnemy(sf::RenderWindow *window)
{
     // enemy  sprite is not a sf::Sprite but an std::optional <sf::Sprite >
    // so we need to dereference it
    window->draw(*enemySprite);
}   

bool Enemy::checkIfHit(sf::Vector2i mousePos)
{
     // check if mousePos is within enemySprite bounds
    if (enemySprite->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
    {
        return true;
    }
    return false;
}

bool Enemy::takeDamage(int damage)
{
    energy -= damage;
    if (attackSound)
    {
        attackSound->play();
    }
    if (energy <= 0)
    {
        energy = 0;
        return true; // Enemy defeated
    }
    return false; // Enemy still alive
}