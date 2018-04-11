#pragma once
#include "Particle.h"
#include "BehaviorTime.h"
#include <vector>
class ParticleSystem
{
public:
	enum SystemShape {
		Linear,
		Quadratic,
		Cubic,
		Sine,
		Circular
	};
	void CreateParticle();
	bool Update(float t);
	void Render();
	ParticleSystem(sf::Texture, sf::Vector2f, int, int, int, float , float, float, float, float, float, float);
	std::vector<Particle> _particleList;
	int _aliveCount;
private:
	BehaviorTime *sizeBehavior;
	BehaviorTime *accelerationBehavior;
	BehaviorTime *rotationBehavior;
	sf::Texture _texture;
	sf::Vector2f _position;
	int _sizeType;
	int _accelerationType;
	int _rotationType;
	float _startSize;
	float _finalSize;
	float _startAcceleration;
	float _finalAcceleration;
	float _rotationStart;
	float _rotationFinal;
	float _emissionAngle;
	sf::Clock m_clock;
};