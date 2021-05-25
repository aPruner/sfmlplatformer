#include "GameObject.h"

void GameObject::initDebugRect(sf::Vector2f size) {
	m_debugRect.setSize(size);
	m_debugRect.setOutlineColor(sf::Color::Red);
	m_debugRect.setOrigin(getPosition());
	m_debugRect.setFillColor(sf::Color::Transparent);
	m_debugRect.setOutlineThickness(1.0);
}

sf::Vector2f GameObject::applyGravity(float timeElapsed, sf::Vector2f newPosition, double gravityAccel) {
	newPosition.y -= timeElapsed * (float) gravityAccel;
	return newPosition;
}

// Getters and Setters
sf::Sprite GameObject::getSprite() {
	return m_sprite;
}

sf::Vector2f GameObject::getPosition() {
	// TODO: For now, we only care about debugRects since there are no gfx in the game yet
	// return m_sprite.getPosition();
	return m_debugRect.getPosition();
}

sf::Vector2f GameObject::getOrigin() {
	// TODO: For now, we only care about debugRects since there are no gfx in the game yet
	// return m_sprite.getOrigin();
	return m_debugRect.getOrigin();
}

sf::RectangleShape GameObject::getDebugRect() {
	return m_debugRect;
}

void GameObject::setSprite(sf::Sprite sprite) {
	m_sprite = sprite;
}

void GameObject::setPosition(sf::Vector2f position) {
	m_sprite.setPosition(position);
	m_debugRect.setPosition(position);
}