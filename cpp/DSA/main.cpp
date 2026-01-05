 //powershell -ExecutionPolicy Bypass -File .\setup_sfml.ps1 -Verbose 
 #include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
struct Person 
{
    int id;
    sf::CircleShape shape;
    sf::Text text;
};

int main() 
{
    int N, K;
    cout << "Enter number of people (N): ";
    cin >> N;
    cout << "Enter step count (K): ";
    cin >> K;

    // SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Josephus Problem");

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
     {
        cout << "Failed to load font!" << endl;
        return -1;
    }

    // Create circle positions
    vector<Person> people;
    float centerX = 400, centerY = 300, radius = 200;
    for (int i = 0; i < N; ++i)
     {
        float angle = i * 2 * 3.14159265 / N;
        float x = centerX + radius * std::cos(angle);
        float y = centerY + radius * std::sin(angle);

        Person p;
        p.id = i + 1;
        p.shape = sf::CircleShape(25.f);
        p.shape.setFillColor(sf::Color::Green);
        p.shape.setOrigin(25.f, 25.f);
        p.shape.setPosition(x, y);

        p.text.setFont(font);
        p.text.setString(std::to_string(p.id));
        p.text.setCharacterSize(40);
        p.text.setFillColor(sf::Color::White);
        p.text.setOrigin(p.text.getLocalBounds().width / 2, p.text.getLocalBounds().height / 2);
        p.text.setPosition(x, y - 10);

        people.push_back(p);
    }

    // Queue for Josephus simulation
    std::queue<int> q;
    for (int i = 0; i < N; ++i) q.push(i);

    sf::Clock clock;
    float delay = 1.0f; // seconds between eliminations

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() >= delay && q.size() > 1) 
        {
            // Rotate queue K-1 times
            for (int i = 0; i < K - 1; ++i) 
            {
                int front = q.front(); 
                q.pop();
                q.push(front);
            }

            // Remove Kth person
            int eliminated = q.front(); q.pop();
            people[eliminated].shape.setFillColor(sf::Color::Red); // mark eliminated
            people[eliminated].text.setString("X"); // optional X mark
            clock.restart();
        }

        window.clear(sf::Color::Black);

        // Draw all people
        for (auto &p : people)
         {
            window.draw(p.shape);
            window.draw(p.text);
        }

        window.display();

        // End simulation if one person left
        if (q.size() == 1)
         {
            int survivor = q.front();
            people[survivor].shape.setFillColor(sf::Color::Yellow);
            people[survivor].text.setString(std::to_string(people[survivor].id));
        }
    }

    return 0;
}
