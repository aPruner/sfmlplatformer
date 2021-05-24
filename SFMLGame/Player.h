#pragma once
#include "GameObject.h"

class Player : virtual public GameObject {
private:
	Level* m_level;

	int m_health;
	float m_movementSpeed;
	float m_jumpSpeed;

	// Player movement input flags
	bool m_moveLeftPressed;
	bool m_moveRightPressed;

	bool m_isAirborne;
	bool m_isJumping;

	sf::Clock m_jumpClock;
	const double JUMP_CLOCK_INTERVAL = 0.3;

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

	void triggerJump();

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters and Setters
	int getHealth();
	bool getIsAirborne();
	bool getIsJumping();

	void setHealth(int health);
	void setMoveLeftPressed(bool moveLeftPressed);
	void setMoveRightPressed(bool moveRightPressed);
	void setIsAirborne(bool isAirborne);
	void setIsJumping(bool isJumping);

};