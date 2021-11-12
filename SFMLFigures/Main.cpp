#include <SFML/Graphics.hpp>

#include "Circle.h"
#include "Line.h"

int main()
{
    // Setting up render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Figure");
    window.setFramerateLimit(60);
    // Circle draw
    Circle circ(5, 150);
    circ.SetPosition(sf::Vector2f(400, 300));
    Line line1(300, 5), line2(250,5);
    line1.SetPosition(sf::Vector2f(700, 300));
    line2.SetPosition(sf::Vector2f(300, 300));
    // Delta time
    sf::Clock deltaClock;
    sf::Time deltaTime = deltaClock.restart();
    // Movement movementSpeed
    float movementSpeed = 85;
    float rotateSpeed = 0.5;
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
                line1.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
                line2.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                circ.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                line1.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                line2.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                circ.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                line1.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                line2.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                circ.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                line1.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                line2.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
            }
            // Rotating
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                circ.Rotate(rotateSpeed * deltaTime.asSeconds(), line1.GetCenterPosition());
                line1.Rotate(rotateSpeed * deltaTime.asSeconds(), circ.GetCenterPosition());
                line2.Rotate(rotateSpeed * deltaTime.asSeconds(), circ.GetCenterPosition());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                circ.Rotate(-rotateSpeed * deltaTime.asSeconds(), line1.GetCenterPosition());
                line1.Rotate(-rotateSpeed * deltaTime.asSeconds(), circ.GetCenterPosition());
                line2.Rotate(-rotateSpeed * deltaTime.asSeconds(), circ.GetCenterPosition());
            }
            // Scaling
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                circ.Scale(sf::Vector2f(1.1, 1.1));
                line1.Scale(sf::Vector2f(1.1, 1.1));
                line2.Scale(sf::Vector2f(1.1, 1.1));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                circ.Scale(sf::Vector2f(0.9, 0.9));
                line1.Scale(sf::Vector2f(0.9, 0.9));
                line2.Scale(sf::Vector2f(0.9, 0.9));
            }
        }
        // Window clear
        window.clear();
        
        // Draws figure
        circ.Draw(&window);
        line1.Draw(&window);
        line2.Draw(&window);

        // Window display
        window.display();
    }

    return 0;
}