#include "SFML/Graphics.hpp"
#include "entity.hpp"
#include "player.hpp"

class Scene {
public:
	Scene() = default;

	virtual ~Scene() = default;

	virtual void update(const float& dt);
	virtual void render(sf::RenderWindow& window);
	virtual void load() = 0;
	virtual void unload();
	std::vector<std::shared_ptr<Entity>>& get_entities() { return _entities; }

protected:
	std::vector<std::shared_ptr<Entity>> _entities;
};

class GameSystem {
public:
	static std::unique_ptr<Player> player;

	static void start(unsigned int width, unsigned int height, const std::string& name, const float& time_step);
	static void clean();
	static void reset();

private:
	GameSystem() = delete;
	static void _init();
	static void _update(const float& dt);
	static void _render(sf::RenderWindow& window);
	static Scene* _active_scene;
};
