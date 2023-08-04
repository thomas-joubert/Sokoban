#pragma once

#include <utility>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>

using board_t = std::vector<std::vector<char>>;

// This class represents a sokoban board. It extends the Drawable sfml interface.
class Board : public sf::Drawable
{
    public:
        Board(std::pair<int, int> format);
        Board(int length, int width);

        // Getters
        int getLength(void) const { return (this->length); }
        int getWidth(void) const { return (this->width); }
        board_t getBoard(void) const { return (this->board); }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        int length;
        int width;
        board_t board;
};