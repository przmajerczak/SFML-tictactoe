#ifndef _SFMLBUTTON_H
#define _SFMLBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class SFMLButton
{
public:
	SFMLButton(	sf::Vector2f _position = { 0, 0 }, 
				sf::Vector2f _size = { 10, 10 }, 
				std::string _string = "", 
				const char* _picture = "Pictures/default_button.png", 
				const char* _font = "Fonts/EncodeSans-Black.ttf");

	void resize(sf::Vector2f _new_size);
	void move(sf::Vector2f _new_position);
	void mousePosition(sf::Vector2i _mouse);
	void mousePressed(void);
	void mouseReleased(void);
	void windowResized(void);
	void draw(sf::RenderWindow& _window);
	void setPicture(const char* _directory);
	void setText(std::string _string);
	void setColor(int _r, int _g, int _b, int _a = 255);
	void clear(void); 
	void turnOff(bool _off);
	bool pressed(void);

	
	~SFMLButton(void);
	
private:
	sf::Vector2f position;
	sf::Vector2f size;	

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text text;

	bool mouse_over_button = false;
	bool button_pressed = false;
	bool button_released = false;
	bool button_on = true;

	
	
};
#endif