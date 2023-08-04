#include "board.hh"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>

Board::Board(std::pair<int, int> format)
{
    this->length = format.first;
    this->width = format.second;
    this->board = std::vector<std::vector<char>>(this->length, std::vector<char>(this->width, 'w'));
}

Board::Board(int length, int width)
{
    this->length = length;
    this->width = width;
    this->board = std::vector<std::vector<char>>(this->length, std::vector<char>(this->width, 'w'));
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape rect(sf::Vector2f(50, 50));

    rect.setFillColor(sf::Color::Red);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(800, 800);

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            rect.setPosition(j * 50, i * 50);
            target.draw(rect);
        }
    }
}
