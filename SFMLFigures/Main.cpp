#include <SFML/Graphics.hpp>

#include "SnowflakeShape.h"

// TEST PREPROCESSORS (Comment all preprocessors except the one you want to test)

#define TEST_SIMPLE_FIGURES
//#define COMPLEX_FIGURE

int main()
{
// Simple figure test
#ifdef TEST_SIMPLE_FIGURES
#ifndef COMPLEX_FIGURE
    // Setting up render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Figure");
    window.setFramerateLimit(60);
    // Figures
    Circle circ(50, 2);
    circ.SetPosition(sf::Vector2f(300, 350));
    Line line1(300, 5), line2(250,5);
    line1.SetPosition(sf::Vector2f(700, 300));
    line2.SetPosition(sf::Vector2f(700, 100));
    Rectangle rect(150, 100, 5);
    rect.SetPosition(sf::Vector2f(300, 150));
    Paraboloid parab1(20,100,5), parab2(20,100,5);
    parab1.SetPosition(sf::Vector2f(300, 100));
    parab2.SetPosition(sf::Vector2f(300, 135));
    parab2.Rotate(180);
    Leaf leaf(15, 150, 5);
    leaf.SetPosition(sf::Vector2f(300, 350));
    // Delta time
    sf::Clock deltaClock;
    sf::Time deltaTime = deltaClock.restart();
    // Movement movementSpeed
    float movementSpeed = 85;
    float rotateSpeed = 45;
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
                line2.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
                rect.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
                parab1.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
                parab2.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
                leaf.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                circ.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                line1.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                line2.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                rect.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                parab1.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                parab2.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
                leaf.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                circ.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                line1.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                line2.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                rect.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                parab1.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
                parab2.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                circ.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                line1.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                line2.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                rect.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                parab1.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
                parab2.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
            }
            // Rotating
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                circ.Rotate(rotateSpeed * deltaTime.asSeconds());
                line1.Rotate(rotateSpeed * deltaTime.asSeconds(), line2.GetCenterPosition());
                line2.Rotate(rotateSpeed * deltaTime.asSeconds(), line1.GetCenterPosition());
                rect.Rotate(rotateSpeed * deltaTime.asSeconds(), circ.GetCenterPosition());
                parab1.Rotate(rotateSpeed * deltaTime.asSeconds(), parab2.GetCenterPosition());     
                parab2.Rotate(rotateSpeed * deltaTime.asSeconds(), parab1.GetCenterPosition());
                leaf.Rotate(rotateSpeed * deltaTime.asSeconds());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                circ.Rotate(-rotateSpeed * deltaTime.asSeconds());
                line1.Rotate(-rotateSpeed * deltaTime.asSeconds(), line2.GetCenterPosition());
                line2.Rotate(-rotateSpeed * deltaTime.asSeconds(), line1.GetCenterPosition());
                rect.Rotate(-rotateSpeed * deltaTime.asSeconds(), circ.GetCenterPosition());
                parab1.Rotate(rotateSpeed * deltaTime.asSeconds(), parab2.GetCenterPosition());
                parab2.Rotate(rotateSpeed * deltaTime.asSeconds(), parab1.GetCenterPosition());
                leaf.Rotate(-rotateSpeed * deltaTime.asSeconds());
            }
            // Scaling
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                circ.Scale(sf::Vector2f(1.1, 1.1));
                line1.Scale(sf::Vector2f(1.1, 1.1));
                line2.Scale(sf::Vector2f(1.1, 1.1));
                rect.Scale(sf::Vector2f(1.1, 1.1));                           
                parab1.Scale(sf::Vector2f(1.1, 1.1));
                parab2.Scale(sf::Vector2f(1.1, 1.1));
                leaf.Scale(sf::Vector2f(1.1, 1.1));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                circ.Scale(sf::Vector2f(0.9, 0.9));
                line1.Scale(sf::Vector2f(0.9, 0.9));
                line2.Scale(sf::Vector2f(0.9, 0.9));
                rect.Scale(sf::Vector2f(0.9, 0.9));
                parab1.Scale(sf::Vector2f(0.9, 0.9));
                parab2.Scale(sf::Vector2f(0.9, 0.9));
                leaf.Scale(sf::Vector2f(0.9, 0.9));
            }
        }
        // Window clear
        window.clear();
        
        // Draws figure
        circ.Draw(&window);
        line1.Draw(&window);
        line2.Draw(&window);
        rect.Draw(&window);
        parab1.Draw(&window);
        parab2.Draw(&window);
        leaf.Draw(&window);

        // Window display
        window.display();
    }
#endif // COMPLEX_FIGURE
#endif // TEST_SIMPLE_FIGURES

#ifdef COMPLEX_FIGURE
#ifndef TEST_SIMPLE_FIGURES
    // Setting up render window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML Figure");
    window.setFramerateLimit(60);
    // Figures
    SnowflakeShape snowflakeShape(250, 5);
    snowflakeShape.SetPosition(sf::Vector2f(500, 400));
    // Delta time
    sf::Clock deltaClock;
    sf::Time deltaTime = deltaClock.restart();
    // Movement movementSpeed
    float movementSpeed = 85;
    float rotateSpeed = 45;
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
                snowflakeShape.Move(sf::Vector2f(0, -movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                snowflakeShape.Move(sf::Vector2f(0, movementSpeed * deltaTime.asSeconds()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                snowflakeShape.Move(sf::Vector2f(-movementSpeed * deltaTime.asSeconds(), 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                snowflakeShape.Move(sf::Vector2f(movementSpeed * deltaTime.asSeconds(), 0));
            }
            // Rotating
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                snowflakeShape.Rotate(rotateSpeed * deltaTime.asSeconds());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                snowflakeShape.Rotate(-rotateSpeed * deltaTime.asSeconds());
            }
            // Scaling
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                snowflakeShape.Scale(sf::Vector2f(1.1, 1.1));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                snowflakeShape.Scale(sf::Vector2f(0.9, 0.9));
            }
        }
        // Window clear
        window.clear();

        // Draws figure
        snowflakeShape.Draw(&window);

        // Window display
        window.display();
    }
#endif // !TEST_SIMPLE_FIGURES
#endif // COMPLEX_FIGURE

    return 0;
}