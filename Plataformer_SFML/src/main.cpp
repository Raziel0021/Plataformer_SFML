#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1568, 768), "STP Example");
	tmx::TileMap map("res/intento2.tmx");

	map.ShowObjects(); // Display all the layer objects.

										   // Start the game loop
	while (window.isOpen()) {
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the map
		window.draw(map);
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}