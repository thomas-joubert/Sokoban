#pragma once

#include <utility>
#include <vector>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>
#include <nlohmann/json.hpp>
#include <fstream>

#define WALL 0
#define EMPTY 1
#define BOX 2
#define PLAYER 3
#define GOAL 4
#define BOX_ON_GOAL 5


using board_t = std::vector<std::vector<short>>;

// This class represents a sokoban board. It extends the Drawable sfml interface.
class Board : public sf::Drawable
{
    public:
        Board(std::pair<int, int> format);
        Board(int length, int width);
        Board(int length, int width, board_t board);

        // Getters
        int getLength(void) const { return (this->length); }
        int getWidth(void) const { return (this->width); }
        board_t getBoard(void) const { return (this->board); }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // Loads a board from a json file
        static Board loadFromFile(std::string path);

    private:

        int length;
        int width;
        board_t board;
};