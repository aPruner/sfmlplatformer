#pragma once
#include "GameObject.h"

class Player : virtual public GameObject {
private:
	int m_health;
	float m_movementSpeed;

	// Player movement input flags
	bool m_moveLeftPressed;
	bool m_moveRightPressed;
	bool m_jumpPressed;

	// TODO: add more player-related data fields here

	// Player update helpers
	void moveUpdateHelper(float timeElapsed);

public:
	Player();
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