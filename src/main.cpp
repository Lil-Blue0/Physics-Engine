#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "kinematics.h"
#include "customPhysics.h"

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);


    //draw a circle on screen
    sf::CircleShape circle(50.0f);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(375,275);

    float x_pos;
    double time = 1;

    customPhysicsObject obj(10,0);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        window.clear(sf::Color::Black);


        x_pos = circle.getPosition().y;


        circle.setPosition(circle.getPosition().x,update_x_pos(x_pos,obj,time));

        window.draw(circle);

        time += 0.01;

        //std::cout << x_pos << std::endl;
        std::cout << time << std::endl;

        if(circle.getPosition().y > 1080) {
            circle.setPosition(circle.getPosition().x,1);
            time = 0;
        }

        window.display();
    }
}
