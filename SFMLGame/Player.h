#pragma once
#include "GameObject.h"

class Player : virtual public GameObject {
private:
	Level* m_level;

	int m_health;
	float m_movementSpeed;

	// Player movement input flags
	bool m_moveLeftPressed;
	bool m_moveRightPressed;
	bool m_jumpPressed;

	// TODO: add more player-related data fields here

	// Player update helpers
	void moveUpdateHelper(float timeElapsed);

	// This method checks for collisions after a single position change represented by the 
	// difference in both x and y of newPosition - currentPosition, and will undo the position
	// change if a collision was found
	// NOTE: This method ASSUMES that only one change in position has happened, so it needs
	// to be called after every change of position
	// params:
	//	currentPosition: position before the change
	//	newPosition: position after the change
	sf::Vector2f checkCollisionHelper(float timeElapsed, sf::Vector2f currentPosition, sf::Vector2f newPosition);

public:
	Player(Level* level);
	~Player();

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters and Setters
	int getHealth();

	void setHealth(int health);
	void setMoveLeftPressed(bool moveLeftPressed);
	void setMoveRightPressed(bool moveRightPressed);
	void setJumpPressed(bool jumpPressed);

};