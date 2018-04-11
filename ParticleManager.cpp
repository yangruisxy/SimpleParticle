#include "ParticleManager.h"
void ParticleManager::Init()
{
	particleTexture1.loadFromFile("star.png");
	particleTexture2.loadFromFile("flower.png");
	particleTexture3.loadFromFile("snow.jpg");
	ParticleSystem ps(particleTexture1, sf::Vector2f(200, 200), 0, 0, 0, 3, 10, -10, 10, 120, 30, -120);
	ParticleSystem ps2(particleTexture2, sf::Vector2f(300, 200), 2, 2, 2, 3, 10, -10, 10, 270, 30, -120);
	ParticleSystem ps3(particleTexture3, sf::Vector2f(400, 200), 4, 4, 4, 3, 10, -10, 10, 320, 60, -120);
	_manager.push_back(ps);
	_manager.push_back(ps2);
	_manager.push_back(ps3);
}

void ParticleManager::Update(float t)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < _manager.size(); i++)
		{
			for (int j = 0; j < 100; ++j)
				_manager[i].CreateParticle();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < _manager.size(); i++)
		{
			_manager[i]._aliveCount -= 100;
		}
	}
	for (int i = 0; i < _manager.size(); i++)
	{
		if (!_manager[i].Update(t))
		{
			_manager.erase(_manager.begin() + i);
		}
	}
	
}

void ParticleManager::Render()
{
	for (int i = 0; i < _manager.size(); i++)
	{
		_manager[i].Render();
	}
}
