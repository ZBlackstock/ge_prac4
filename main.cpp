#include "game_parameters.hpp"
#include "game_system.hpp"

using param = Parameters;

int main() {
	GameSystem::start(param::game_width, param::game_height, "Tile Maze", param::time_step);
	return 0;
}