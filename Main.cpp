#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleManager.h"

void update(float dt);
void render_frame();

sf::RenderWindow window;
ParticleManager manager;

sf::RectangleShape rect;

int main()
{
	window.create(sf::VideoMode(800, 600), "Particle");;
	srand(time(NULL));
	sf::Clock clock;
	manager.Init();
	for (int i = 0; i < manager._manager.size(); ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			manager._manager[i].CreateParticle();
		}
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
					window.close();
		
		}
		
		float dt = clock.restart().asSeconds();
		update(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update(float dt)
{
	for (int i = 0; i < manager._manager.size(); ++i)
	{
		manager.Update(dt);
		manager.Render();
	}

}

void render_frame()
{
	window.clear();
	bool big = false;
	for (int i = 0; i < manager._manager.size(); ++i)
	{
		for (int j = 0; j < manager._manager[i]._aliveCount; ++j)
		{
			window.draw(manager._manager[i]._particleList[j].m_Particle);
		}
	}
	//window.draw(ps._particleList[0].m_Particle);
}