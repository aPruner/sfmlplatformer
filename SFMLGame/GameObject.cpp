#include "GameObject.h"

sf::Vector2f GameObject::getPosition() {
	return m_sprite.getPosition();
}

sf::Vector2f GameObject::getOrigin() {
	return m_sprite.getOrigin();
}

void GameObject::setSprite(sf::Sprite sprite) {
	m_sprite = sprite;
}

void GameObject::setPosition(sf::Vector2f position) {
	m_sprite.setPosition(position);
}