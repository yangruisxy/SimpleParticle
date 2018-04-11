#include "ParticleSystem.h"
#include "Randomness.h"
#include <time.h>
#include <cstdlib>



ParticleSystem::ParticleSystem(sf::Texture tex, sf::Vector2f pos, int sizeType, int accelerationType, int rotationType, float startSize, float finalSize,
	float startAcceleration, float finalAcceleration, float eAngle, float startRotation, float finalRotation)
{
	_texture = tex;
	_position = pos;
	_sizeType = sizeType;
	_accelerationType = accelerationType;
	_rotationType = rotationType;
	_aliveCount = 0;
	_startSize = startSize;
	_finalSize = finalSize;
	_startAcceleration = startAcceleration;
	_finalAcceleration = finalAcceleration;
	_emissionAngle = eAngle;
	_rotationStart = startRotation;
	_rotationFinal = finalRotation;
}

void ParticleSystem::CreateParticle()
{
	Particle p;
	float dirAngle, dirAnglein, rotateAngle;
	dirAngle = dirAnglein = rotateAngle = 0.0f;
	p.m_OldPosition = p.m_Position = _position;
	dirAngle = rand() % 360 - 180;
	rotateAngle = _rotationStart;
	dirAnglein = dirAngle * 3.14f / 180.0f;
	p.m_LifeTime = rand() % 400  + 100;
	p.m_Particle.setSize(sf::Vector2f(100, 100));
	if (dirAngle> -_emissionAngle && dirAngle < _emissionAngle)
	{
		p.m_Velocity.x = cos(dirAnglein);
		p.m_Velocity.y = sin(dirAnglein);
		p.m_Size = _startSize * sf::Vector2f(1.0f, 1.0f);
		p.m_Acceleration = _startAcceleration;
		p.m_Color.r = rand() % 255;
		p.m_Color.g = rand() % 255;
		p.m_Color.b = rand() % 255;
		_particleList.push_back(p);
		++_aliveCount;
	}
}

bool ParticleSystem::Update(float t)
{
	float time = m_clock.restart().asSeconds();
	for (int i = 0; i < _particleList.size(); ++i)
	{
		_particleList[i].m_CurLifeTime++;
		if(_particleList[i].m_CurLifeTime <= _particleList[i].m_LifeTime)
		{
			float p = _particleList[i].m_CurLifeTime / _particleList[i].m_LifeTime;
			float progress;
			if (_accelerationType == Linear)
			{
				accelerationBehavior = new LinearBehavior();
				progress = accelerationBehavior->behaviorTime(p);
			}
			else if (_accelerationType == Quadratic)
			{
				accelerationBehavior = new QuadraticBehavior();
				progress = accelerationBehavior->behaviorTime(p);
			}
			else if (_accelerationType == Cubic)
			{
				accelerationBehavior = new CubicBehavior();
				progress = accelerationBehavior->behaviorTime(p);
			}
			else if (_accelerationType == Sine)
			{
				accelerationBehavior = new SineBehavior();
				progress = accelerationBehavior->behaviorTime(p);
			}
			else if (_accelerationType == Circular)
			{
				accelerationBehavior = new CircularBehavior();
				progress = accelerationBehavior->behaviorTime(p);
			}
			_particleList[i].m_Acceleration = _startAcceleration + progress * _finalAcceleration;
			if (_rotationType == Linear)
			{
				rotationBehavior = new LinearBehavior();
				progress = accelerationBehavior->behaviorTime(p);
			}
			else if (_rotationType == Quadratic)
			{
				rotationBehavior = new QuadraticBehavior();
				progress = rotationBehavior->behaviorTime(p);
			}
			else if (_rotationType == Cubic)
			{
				rotationBehavior = new CubicBehavior();
				progress = rotationBehavior->behaviorTime(p);
			}
			else if (_rotationType == Sine)
			{
				rotationBehavior = new SineBehavior();
				progress = rotationBehavior->behaviorTime(p);
			}
			else if (_rotationType == Circular)
			{
				rotationBehavior = new CircularBehavior();
				progress = rotationBehavior->behaviorTime(p);
			}
			_particleList[i].rotationAngle = _rotationStart + progress * _rotationFinal;
			_particleList[i].m_ParticleSpeed += _particleList[i].m_Acceleration * t;
			_particleList[i].m_Position += _particleList[i].m_Velocity * t * _particleList[i].m_ParticleSpeed;
			_particleList[i].m_OldPosition = _particleList[i].m_Position;
			if (_sizeType == Linear)
			{
				sizeBehavior = new LinearBehavior();
				progress = sizeBehavior->behaviorTime(p);
			}
			else if (_sizeType == Quadratic)
			{
				sizeBehavior = new QuadraticBehavior();
				progress = sizeBehavior->behaviorTime(p);
			}
			else if (_sizeType == Cubic)
			{
				sizeBehavior = new CubicBehavior();
				progress = sizeBehavior->behaviorTime(p);
			}
			else if (_sizeType == Sine)
			{
				sizeBehavior = new SineBehavior();
				progress = sizeBehavior->behaviorTime(p);
			}
			else if (_sizeType == Circular)
			{
				sizeBehavior = new CircularBehavior();
				progress = sizeBehavior->behaviorTime(p);
			}
			if(_startSize <= _finalSize)
				_particleList[i].m_Size = (_startSize + p * _finalSize) * _startSize * sf::Vector2f(1.0f, 1.0f);
			else
				_particleList[i].m_Size = (_startSize - p * _finalSize) * _startSize * sf::Vector2f(1.0f, 1.0f);
		}
		else
		{
			--_aliveCount;
		}
	}
	if (_aliveCount <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ParticleSystem::Render()
{
	for (int i = 0; i < _particleList.size(); ++i)
	{
		if (_particleList[i].m_CurLifeTime <= _particleList[i].m_LifeTime)
		{
			_particleList[i].m_Particle.setPosition(_particleList[i].m_Position);
			//_particleList[i].m_Particle.setSize(sf::Vector2f(10, 10));
			_particleList[i].m_Particle.setSize(_particleList[i].m_Size);
			//_particleList[i].m_Particle.setOrigin(0, 0);
			_particleList[i].m_Particle.setFillColor(_particleList[i].m_Color);
			_particleList[i].m_Particle.setTexture(&_texture);
			_particleList[i].m_Particle.setRotation(_particleList[i].rotationAngle);
		}
	}
}