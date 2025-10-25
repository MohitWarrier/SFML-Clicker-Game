
#include "gameWorld.h"
#include "texts.h"

GameWorld::GameWorld() : enemy(100), texts()
{
    damage = 10;
}

bool GameWorld::loadBackground()
{
    if (!backgroundTexture.loadFromFile("Assets/background.png"))
    {
        std::cerr << "Failed to load background texture!" << std::endl;
        return false;
    }
    backgroundSprite.emplace(backgroundTexture);
    //scale background to fit window size 
    backgroundSprite->setScale(
        sf::Vector2f(1.6,2.25)
    );
    return true;
}

bool GameWorld::performSetup()
{
    isGameOver = false;
    enemy = Enemy(100);
    texts = Texts();
    return loadBackground() && enemy.performSetup() && texts.performSetup();
}

bool GameWorld::runGame()
{
    // setup the window
    sf::RenderWindow window(sf::VideoMode({1000u, 1000u}), "Game!");
    sf::Clock clock;

    while (window.isOpen())
    {
        if (!isGameOver)
        {
            time = clock.getElapsedTime();
        }
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (event->is<sf::Event::MouseButtonPressed>())
            {
                sf::Vector2i mousePos = event->getIf<sf::Event::MouseButtonPressed>()->position;
                if (enemy.checkIfHit(mousePos) && !isGameOver)
                {
                    if (enemy.takeDamage(damage))
                    {
                        isGameOver = true;
                        clock.restart(); // restart clock to show end game texts for some time
                    }
                }
            }
            else if (event->is<sf::Event::KeyPressed>())
            {
                if (isGameOver)
                {
                    //check if space bar is pressed
                    if(event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space)
                    {
                        return true; // restart the game
                    }
                }
            }
        }

        window.clear();
        // background sprite is not a sf::Sprite but an std::optional <sf::Sprite >
        // so we need to dereference it
        window.draw(*backgroundSprite);

        if (isGameOver)
        {
            texts.drawEndGameTexts(&window, time);
        }
        else
        {
            enemy.drawEnemy(&window);
            texts.drawInGameTexts(&window, time, enemy.energy);
        }

        window.display();
    }
    return false;
}