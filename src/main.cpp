#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);


    //draw a circle on screen
    sf::CircleShape circle(50.0f);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(375,275);

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


        window.draw(circle);

        window.display();
    }
}
