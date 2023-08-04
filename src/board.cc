#include "board.hh"

Board::Board(std::pair<int, int> format)
{
    this->length = format.first;
    this->width = format.second;
    this->board = std::vector<std::vector<short>>(this->length, std::vector<short>(this->width, WALL));
}

Board::Board(int length, int width)
{
    this->length = length;
    this->width = width;
    this->board = std::vector<std::vector<short>>(this->length, std::vector<short>(this->width, WALL));
}

Board::Board(int length, int width, board_t board)
{
    this->length = length;
    this->width = width;
    this->board = board;
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape tile(sf::Vector2f(50, 50));
    tile.setOutlineThickness(1);
    tile.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            switch (this->board[i][j])
            {
                case WALL:
                    tile.setFillColor(sf::Color::Yellow);
                    break;
                case EMPTY:
                    tile.setFillColor(sf::Color::Red);
                    break;
                case BOX:
                    tile.setFillColor(sf::Color::Blue);
                    break;
                case PLAYER:
                    tile.setFillColor(sf::Color::Magenta);
                    break;
                case GOAL:
                    tile.setFillColor(sf::Color::Green);
                    break;
                case BOX_ON_GOAL:
                    tile.setFillColor(sf::Color::Cyan);
                    break;
                default:
                    break;
            }

            tile.setPosition(sf::Vector2f(i * 50, j * 50));
            target.draw(tile, states);
        }
    }
}

// Loads a Board object from a json file
Board Board::loadFromFile(std::string path)
{
    std::ifstream file(path);
    nlohmann::json rawBoard = nlohmann::json::parse(file);

    return Board(rawBoard["height"], rawBoard["width"], rawBoard["rows"]);
}