#include "Player.h"

Player::Player(Level* level) :
	m_level(level),
	m_health(10),
	m_movementSpeed(BASE_MOVEMENT_SPEED),
	m_jumpSpeed(BASE_JUMP_SPEED),
	m_moveLeftPressed(false),
	m_moveRightPressed(false),
	m_isJumping(false),
	m_isAirborne(false) {
	initDebugRect(sf::Vector2f(62, 62));
	setPosition(sf::Vector2f(192, 512));
}

Player::~Player() {
}

void Player::triggerJump() {
	if (!m_isJumping && !m_isAirborne) {
		m_jumpClock.restart();
		setIsAirborne(true);
		setIsJumping(true);
	}
}

// Player update helpers
void Player::moveUpdateHelper(float timeElapsed) {
	// Copy the current position for mutation if the player will move
	sf::Vector2f newPosition = getPosition();
	sf::Vector2f currentPosition = getPosition();

	// Move the player and check for collisions after each potential move
	// We need to check for collisions after each move so we can reverse that move 
	// before the next frame if it were to cause a collision. This is difficult
	// if I simply check collisions once, as it would be difficult to figure out
	// which move caused the collision. However, if this method needs optimization later,
	// I'll revisit this
	if (m_moveLeftPressed) {
		newPosition.x -= timeElapsed * m_movementSpeed;
		newPosition = checkCollisionHelper(timeElapsed, currentPosition, newPosition, m_level->getDebugEnvArray());
		currentPosition = newPosition;
	}
	if (m_moveRightPressed) {
		newPosition.x += timeElapsed * m_movementSpeed;
		newPosition = checkCollisionHelper(timeElapsed, currentPosition, newPosition, m_level->getDebugEnvArray());
		currentPosition = newPosition;
	}

	if (m_isJumping) {
		newPosition.y -= timeElapsed * m_jumpSpeed;
		newPosition = checkCollisionHelper(timeElapsed, currentPosition, newPosition, m_level->getDebugEnvArray());

		currentPosition = newPosition;
		if (m_jumpClock.getElapsedTime().asSeconds() > JUMP_CLOCK_INTERVAL) {
			setIsJumping(false);
		}
	}

	// Apply gravity using the GameObject gravity helper
	newPosition = applyGravity(timeElapsed, newPosition, BASE_GRAVITY_ACCEL_VALUE);
	newPosition = checkCollisionHelper(timeElapsed, currentPosition, newPosition, m_level->getDebugEnvArray());

	// In this case, we've just landed on a platform/the ground
	if (currentPosition == newPosition && m_isAirborne) {
		setIsAirborne(false);
	}

	// Finalize the new position
	setPosition(newPosition);
}

// This method checks for collisions after a single position change represented by the 
// difference in both x and y of newPosition - currentPosition, and will undo the position
// change if a collision was found
// NOTE: This method ASSUMES that only one change in position has happened, so it needs
// to be called after every change of position
// params:
//  timeElapsed: time interval for the change
//	currentPosition: position before the change
//	newPosition: position after the change
//  objectsToCheck: array of drawables to check collisions against
sf::Vector2f Player::checkCollisionHelper(float timeElapsed,
											sf::Vector2f currentPosition,
											sf::Vector2f newPosition,
											std::vector<sf::RectangleShape>* objectsToCheck) {
	for (auto it = objectsToCheck->begin(); it != objectsToCheck->end(); it++) {
		sf::FloatRect newPositionBoundingBox(newPosition, m_debugRect.getSize());
		if (newPositionBoundingBox.intersects((*it).getGlobalBounds())) {
			return currentPosition;
		}
	}
	return newPosition;
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

bool Player::getIsAirborne() {
	return m_isAirborne;
}

bool Player::getIsJumping() {
	return m_isJumping;
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

void Player::setIsAirborne(bool isAirborne) {
	m_isAirborne = isAirborne;
}

void Player::setIsJumping(bool isJumping) {
	m_isJumping = isJumping;
}