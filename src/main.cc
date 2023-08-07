#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shape.hpp>

#include <iostream>
#include <vector>
#include <fstream>

#include "board.hh"
#include "board_validator.hh"

Board createBoardFromJson(std::string rawBoard, std::string rawSchema)
{
    std::ifstream jsonBoard(rawBoard);
    nlohmann::json board = nlohmann::json::parse(jsonBoard);

    std::ifstream jsonSchema(rawSchema);
    nlohmann::json schema = nlohmann::json::parse(jsonSchema);

    if (!BoardValidator::isValid(board, schema))
    {
        std::cerr << "Invalid board" << std::endl;
        exit(84);
    }

    return Board::loadFromFile(board);
}

int main(void)
{
    // Main window of the prg
    sf::RenderWindow window(sf::VideoMode(1920, 1080, sf::Style::Default), "Sokoban");
    window.setVerticalSyncEnabled(true);

    Board board = createBoardFromJson("assets/boards/board1.json", "resources/board.schema.json");

    while (window.isOpen())
    {
        // Stores the event (keyboards...)
        sf::Event event;

        window.clear();

        board.draw(window, sf::RenderStates::Default);

        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }
    }
}
