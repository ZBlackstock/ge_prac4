#include "player.hpp"
#include <iostream>

using namespace sf;
using namespace std;

void Player::update(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move(sf::Vector2f(get_position().x - _speed * dt, get_position().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move(sf::Vector2f(get_position().x + _speed * dt, get_position().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		move(sf::Vector2f(get_position().x, get_position().y + _speed * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		move(sf::Vector2f(get_position().x, get_position().y - _speed * dt));
	}

	Entity::update(dt);
}

Player::Player() : Entity(make_unique<CircleShape>(_radius)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(sf::Vector2f(_radius, _radius));
	
}

void Player::render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}