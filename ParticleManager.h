#pragma once
#include "ParticleSystem.h"

class ParticleManager
{
public:
	std::vector<ParticleSystem> _manager;
	void Init();
	void AddSystem(const ParticleSystem&);
	void Update(float t);
	void Render();
private:
	sf::Texture particleTexture1;
	sf::Texture particleTexture2;
	sf::Texture particleTexture3;
};