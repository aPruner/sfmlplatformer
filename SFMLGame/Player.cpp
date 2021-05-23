#include "Player.h"

Player::Player() :
	m_health(10),
	m_movementSpeed(BASE_MOVEMENT_SPEED),
	m_moveLeftPressed(false),
	m_moveRightPressed(false),
	m_jumpPressed(false) {
	initDebugRect(sf::Vector2f(32, 32));
	setPosition(sf::Vector2f(500, 500));
}

Player::~Player() {
}

// Player update helpers
void Player::moveUpdateHelper(float timeElapsed) {
	// Copy the current position for mutation if the player will move
	sf::Vector2f newPosition = getPosition();
	// Move the player
	if (m_moveLeftPressed) {
		newPosition.x -= timeElapsed * m_movementSpeed;
	}
	if (m_moveRightPressed) {
		newPosition.x += timeElapsed * m_movementSpeed;
	}

	// TODO: Handle jump here

	// Apply gravity using the GameObject gravity helper
	// applyGravity(timeElapsed, BASE_GRAVITY_ACCEL_VALUE);

	// Finalize the new position
	setPosition(newPosition);
}

// Override for GameObject::update
void Player::update(float timeElapsed) {
	moveUpdateHelper(timeElapsed);
}

// Override for GameObject::draw
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_debugRect, states);
	target.draw(m_sprite, states);
}

// Getters and Setters
int Player::getHealth() {
	return m_health;
}

void Player::setHealth(int health) {
	m_health = health;
}

void Player::setMoveLeftPressed(bool moveLeftPressed) {
	m_moveLeftPressed = moveLeftPressed;
}

void Player::setMoveRightPressed(bool moveRightPressed) {
	m_moveRightPressed = moveRightPressed;
}

void Player::setJumpPressed(bool jumpPressed) {
	m_jumpPressed = jumpPressed;
}