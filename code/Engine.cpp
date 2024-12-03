#include "Engine.h"
using namespace sf;
using namespace std;

void Engine::input()
{
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                for (int i = 0; i < 5; i++)
                {
                    Vector2i position(event.mouseButton.x, event.mouseButton.y);
                    int randNum = (rand % 25) + 25;
                    Particle p(m_Window, randNum, position);
                    m_Particles.push_back(p);
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
    }


}

void Engine::update(float dtAsSeconds)
{

}

void Engine::draw()
{
    m_Window.clear();
    for(int i = 0; i < m_Particles.size(); i++)
    {
        m_Window.draw(m_Particles.at(i));
    }
    m_Window.display();

}

Engine::Engine()
{
    // Create a video mode object Vanessa
    int pixelWidth = VideoMode::getDesktopMode().width / 2;
    int pixelHeight = VideoMode::getDesktopMode().height / 2;
    VideoMode vm(pixelWidth, pixelHeight);

    // Create and open a window for the game Vanessa
    RenderWindow window(vm, "Mandelbrot", Style::Default);

    //assign window to member variable m_Window
    m_Window = window;
  
    
}

void Engine::run()
{
    Clock clock();
    Time time();
  
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;

    while (m_Window.isOpen())
    {
        time = clock.restart();
        time = time.asSeconds();
        input();
        update(time);
        draw();

    }
    

}
