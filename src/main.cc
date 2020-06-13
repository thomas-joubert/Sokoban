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

int main(void)
{
    // Main window of the prg
    sf::RenderWindow window(sf::VideoMode(1920, 1080, sf::Style::Default),
            "Sokoban");
    window.setVerticalSyncEnabled(true);

    // Creating the background for the menu
    sf::Texture background_t;
    background_t.create(1920, 1080);
    sf::Sprite background(background_t); 
    background.setColor(sf::Color(255, 0, 0));

    while (window.isOpen())
    {
        // Stores the event (keyboards...)
        sf::Event event;

        window.clear();
        window.draw(background);
        window.display();

        //pollEvent renvoie true si un event est en attente, false sinon
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed 
                    || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab))
                window.close();
        }
    }
}
