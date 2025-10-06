#include "player.hpp"
#include <iostream>

using namespace sf;
using namespace std;

void Player::update(const float& dt) {
	sf::Vector2f moveSpeed{0,0};

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveSpeed.x -= _speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveSpeed.x += _speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveSpeed.y -= _speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveSpeed.y += _speed;
	}
	move(moveSpeed);
	Entity::update(dt);
}

Player::Player() : Entity(make_unique<CircleShape>(_radius)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(sf::Vector2f(_radius, _radius));
}

void Player::render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}