#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive GameObject classes
// GameObject classes are anything that will be drawn to
// the screen and have collision, I.E: the player character,
// items, enemies, bosses, ranged attack projectiles, etc
class GameObject : public sf::Drawable {
protected:
	sf::Sprite m_sprite;

	sf::RectangleShape m_debugRect;

	const float BASE_MOVEMENT_SPEED = 500.0;
	const double BASE_GRAVITY_ACCEL_VALUE = -9.8;

public:

	void initDebugRect(sf::Vector2f size);

	// Helper method for applying base gravity
	void applyGravity(float timeElapsed, double gravityAccel);

	// Pure virtual method for updating the game object
	// Must be defined in the derived class
	virtual void update(float timeElapsed) = 0;

	// Pure virtual method for drawing the game object
	// Must be defined in the derived class
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Getters and Setters
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::Vector2f getOrigin();
	sf::RectangleShape getDebugRect();

	void setSprite(sf::Sprite sprite);
	void setPosition(sf::Vector2f position);
};