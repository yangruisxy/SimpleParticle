#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
struct Particle
{
	sf::Vector2f m_Position;
	sf::Vector2f m_OldPosition;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_Size;
	sf::Color m_Color;
	sf::RectangleShape m_Particle;
	float  m_LifeTime = 0;
	float m_CurLifeTime = 0;
	float rotationAngle;
	float m_Acceleration;
	float m_ParticleSpeed = 40.0f;
};