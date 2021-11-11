#include <SFML/Graphics.hpp>

#include "Circle.h"

int main()
{
    // Setting up render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Figure");
    window.setFramerateLimit(60);
    // Circle draw
    Circle circ(5, 150);
    circ.SetPosition(sf::Vector2f(400, 300));
    // Delta time
    sf::Clock deltaClock;
    sf::Time deltaTime = deltaClock.restart();
    // Movement movementSpeed
    float movementSpeed = 85;
    float rotateSpeed = 1;
    // Window cycle
    while (window.isOpen())
    {
        // Updating delta time
        deltaTime = deltaClock.restart();
        // Working with events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            // Moving
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                circ.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                circ.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                circ.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                circ.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
            }
            // Rotating
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                circ.Rotate(rotateSpeed * deltaTime.asSeconds());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                circ.Rotate(-rotateSpeed * deltaTime.asSeconds());
            }
            // Scaling
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                circ.Scale(sf::Vector2f(1.1, 1.1));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                circ.Scale(sf::Vector2f(0.9, 0.9));
            }
        }
        // Window clear
        window.clear();
        
        // Draws figure
        circ.Draw(&window);

        // Window display
        window.display();
    }

    return 0;
}