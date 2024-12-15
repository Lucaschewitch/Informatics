#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 
#include<windows.h>
#include <cmath>
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x);

        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    /*setlocale(LC_CTYPE, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);*/
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphics");

    sf::CircleShape userPoint(5);
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    sf::Text zoneText;
    zoneText.setFont(font);
    zoneText.setCharacterSize(20);
    zoneText.setFillColor(sf::Color::White);
    zoneText.setPosition(10, 60);

    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);
    xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(750, 300);
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);
    yAxis[0].color = sf::Color::White;
    yAxis[1].position = sf::Vector2f(400, 550);
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    float mathX = (mousePos.x - 400) / 20.0f;
                    float mathY = -(mousePos.y - 300) / 20.0f;
                    mathX = round(mathX);
                    mathY = round(mathY);

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true;

                    if ((mathY > (mathX)*(mathX) - 8) && (mathY < -(mathX)*(mathX) + 8)) {
                        zoneText.setString("Zone: 1");
                    }
                    else if ((mathY > (mathX) * (mathX) - 8) && (mathY > -(mathX) * (mathX) + 8)) {
                        zoneText.setString("Zone: 2");
                    }
                    else if ((mathY < (mathX) * (mathX)-8) && (mathY < -(mathX) * (mathX)+8)) {
                        zoneText.setString("Zone: 5");
                    }
                    else if ((mathX < -2*pow(2,0.5) && mathY < (mathX) * (mathX)-8 && (mathY > -(mathX) * (mathX)+8))) {
                        zoneText.setString("Zone: 4");
                    }
                    else if ((mathX > 2*pow(2,0.5) && mathY < (mathX) * (mathX)-8 && (mathY > -(mathX) * (mathX)+8))) {
                        zoneText.setString("Zone: 3");
                    }
                    else if ((mathY == (mathX) * (mathX)-8) || (mathY == -(mathX) * (mathX)+8)) {
                        zoneText.setString("Zone border");
                    }


                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")");
                }
            }
        }
        window.clear();

        window.draw(xAxis);
        window.draw(yAxis);


        drawGraph(window, [](float x) { return x * x - 8; }, -20, 20, 30, 30, sf::Color::Red);

        drawGraph(window, [](float x) { return -x * x + 8; }, -20, 20, 30, 30, sf::Color::Blue);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
            window.draw(zoneText);
        }

        window.display();
    }

    return 0;
}