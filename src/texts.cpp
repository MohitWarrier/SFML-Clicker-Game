#include "texts.h"
#include <iostream>

Texts::Texts()
{
}

void Texts::setupText(std::optional<sf::Text>& text, sf::Vector2f position)
{
    if (text.has_value())
    {
        text->setCharacterSize(50);
        text->setFillColor(sf::Color::White);
        text->setStyle(sf::Text::Bold);
        text->setPosition(position);
    }
}


bool Texts::performSetup()
{
    if (!font.openFromFile("Assets/Arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        return false;
    }

    // Create the text objects with the loaded font
    energyText.emplace(font);
    timeText.emplace(font);
    endGameSpaceText.emplace(font);
    endGameWonText.emplace(font);
    endGameTimeText.emplace(font);

    // Now configure each text object
    setupText(energyText, sf::Vector2f(650.f, 800.f));
    setupText(timeText, sf::Vector2f(650.f, 900.f));
    setupText(endGameWonText, sf::Vector2f(400.f, 600.f));
    setupText(endGameTimeText, sf::Vector2f(250.f, 700.f));
    setupText(endGameSpaceText, sf::Vector2f(200.f, 800.f));

    // Set the strings AFTER text objects exist
    endGameSpaceText->setString("Press Space to Play Again");
    endGameWonText->setString("You Won!");

    return true;
}

void Texts::drawInGameTexts(sf::RenderWindow *window, sf::Time time, int energy)
{
    if (energyText.has_value())
    {
        energyText->setString("Energy: " + std::to_string(energy));
        window->draw(*energyText);
    }
    if (timeText.has_value())
    {
        timeText->setString("Time: " + std::to_string(static_cast<int>(time.asSeconds())));
        window->draw(*timeText);
    }
}

void Texts::drawEndGameTexts(sf::RenderWindow *window, sf::Time time)
{
     // texts are not sf::Text but std::optional <sf::Text > 's
    // so we need to dereference it

    if (endGameWonText.has_value())
    {
        window->draw(*endGameWonText);
    }
    if (endGameTimeText.has_value())
    {
        endGameTimeText->setString("Your Time: " + std::to_string(static_cast<int>(time.asSeconds())) + " seconds");
        window->draw(*endGameTimeText);
    }
    if (endGameSpaceText.has_value())
    {
        window->draw(*endGameSpaceText);
    }
}