#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "STP Example");
	tmx::TileMap map("res/intento2.tmx");
	sf::Texture texture;

	texture.loadFromFile("res/platformerPack_character.png");

	sf::Sprite sprite;
	
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	sprite.setColor(sf::Color(255, 255, 255, 255));
	sprite.setPosition(100, 2700);
	map.ShowObjects(); // Display all the layer objects.

	// let's define a view
	sf::View view(sf::FloatRect(0.0f,2500,800.f,720.f));
	float offSetX = 0;
	float offSetY = 0;
	float speed = 170;
	sf::Vector2f pos;
	// activate it
	
	sf::Clock clock;
	// Start the game loop
	while (window.isOpen()) {
		// Process events
		sf::Event event;
		sf::Time elapsed = clock.restart();

		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pos = sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			sprite.setPosition(pos.x -  speed * elapsed.asSeconds(),pos.y);	
			//sprite.setPosition(pos.x + offSetX, pos.y + offSetY);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			sprite.setPosition(pos.x + speed * elapsed.asSeconds(), pos.y);
			//offSetX = offSetX + speed * elapsed.asSeconds();
			//sprite.setPosition(pos.x + offSetX, pos.y + offSetY);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			sprite.setPosition(pos.x , pos.y - speed * elapsed.asSeconds());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// left key is pressed: move our character
			sprite.setPosition(pos.x, pos.y + speed * elapsed.asSeconds());
		}
		
		view.setCenter(400, pos.y - 210);
		window.setView(view);
		// Clear screen
		window.clear();
		// Draw the map
		window.draw(map);
		window.draw(sprite);
		
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}