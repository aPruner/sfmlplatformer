#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive GameObject classes
// GameObject classes are anything that will be drawn to
// the screen and have collision, I.E: the player character,
// items, enemies, bosses, ranged attack projectiles, etc
class GameObject : public sf::Drawable {
private:
	sf::Sprite m_sprite;

public:

	// Getters and Setters
	sf::Vector2f getPosition();
	sf::Vector2f getOrigin();

	void setSprite(sf::Sprite sprite);
	void setPosition(sf::Vector2f position);
};