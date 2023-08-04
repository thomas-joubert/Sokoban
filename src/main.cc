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
#include <memory>
#include <thread>

#include "board.hh"

int main(void)
{
    // Main window of the prg
    sf::RenderWindow window(sf::VideoMode(1920, 1080, sf::Style::Default), "Sokoban");
    window.setVerticalSyncEnabled(true);

    Board board(10, 10);

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
