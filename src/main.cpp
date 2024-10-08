#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "ball.cpp"

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    sf::Font font;
    if (!font.loadFromFile("SUSE-VariableFont_wght.ttf")) {
        std::cerr << "Error loading font from path: Roboto-Black.ttf\n";
        //return -1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    sf::Text ballCountText;
    ballCountText.setFont(font);
    ballCountText.setCharacterSize(16);
    ballCountText.setFillColor(sf::Color::Green);
    ballCountText.setPosition(10,10);

    CirclePhysics physics;
    sf::Clock clock;

    //create balls and add to physics

    Ball ball1(100,100,20);
    Ball ball2(100,150,30);

    ball1.setAcceleration(0,9.8);
    ball2.setAcceleration(0,9.8);

    physics.addBall(ball1);
    physics.addBall(ball2);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            float radius = rand() % 10;
            Ball newBall(mousePos.x,mousePos.y,radius);
            newBall.setAcceleration(0,9.8);
            physics.addBall(newBall);
        }


        if(physics.getBallCount() < 100) {
            Ball randomBalls(std::rand() % 2560, std::rand() % 1440, 15);
            randomBalls.setAcceleration(0,90.8);
            physics.addBall(randomBalls);
        }

        physics.updateAll(deltaTime);


        ballCountText.setString("Ball count:" + std::to_string(physics.getBallCount()));

        window.clear(sf::Color::Black);
        physics.renderAll(window);
        window.draw(ballCountText);
        window.display();
    }
}
