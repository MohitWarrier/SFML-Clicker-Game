
#include <SFML/Graphics.hpp>

#ifndef TEXTS_H
#define TEXTS_H

class Texts
{
    private:
        sf::Font font;

        void setupText(std::optional<sf::Text>&, sf::Vector2f);

    public:
        std::optional<sf::Text> energyText;
        std::optional<sf::Text> timeText;
        std::optional<sf::Text> endGameSpaceText;
        std::optional<sf::Text> endGameWonText;
        std::optional<sf::Text> endGameTimeText;

        Texts();
        bool performSetup();
        void drawInGameTexts(sf::RenderWindow *, sf::Time, int);
        void drawEndGameTexts(sf::RenderWindow *, sf::Time);
};

#endif // TEXTS_H