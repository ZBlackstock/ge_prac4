#include "SFML/Graphics.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"
#include "player.hpp"
std::unique_ptr<Player> GameSystem::player;


void GameSystem::start(unsigned int width, unsigned int height, const std::string& name, const float& time_step) {
	sf::RenderWindow window(sf::VideoMode({ width, height }), name);
	_init();
	sf::Event event;
	GameSystem::player = std::make_unique<Player>();
	GameSystem::player->set_position(sf::Vector2f(Parameters::game_width / 2, Parameters::game_height / 2));

	while (window.isOpen()) {
		static sf::Clock clock;
		float dt = clock.restart().asSeconds();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				clean();
				return;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		window.clear();
		_update(dt);

		_render(window);
		sf::sleep(sf::seconds(time_step));
		window.display();
	}
	window.close();
	clean();
}


void Scene::update(const float& dt) {
	for (std::shared_ptr<Entity>& ent : _entities) {
		ent->update(dt);
	}
	

}

void Scene::render(sf::RenderWindow& window) {
	for (std::shared_ptr<Entity>& ent : _entities) {
		ent->render(window);
	}
	
}

void Scene::unload() {

}

void GameSystem::_init() {

}
void GameSystem::clean() {

}

void GameSystem::_update(const float& dt) {
	GameSystem::player->update(dt);
}

void GameSystem::_render(sf::RenderWindow& window) {
	GameSystem::player->render(window);
}