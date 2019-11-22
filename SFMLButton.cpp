#include "SFMLButton.h"
#include <iostream>
#include <string>

SFMLButton::SFMLButton(	sf::Vector2f _position, 
						sf::Vector2f _size, 
						std::string _string,
						const char* _picture, 
						const char* _font)
{
	position = _position;
	size = _size;

	sprite.setPosition(position);
	texture.loadFromFile(_picture);
	sprite.setTexture(texture);
	
	font.loadFromFile(_font);
	text.setFont(font);
	text.setString(_string);

	int characterSize = 25;
	text.setCharacterSize(characterSize);
	
	text.setPosition(position.x + (size.x - text.getLocalBounds().width) * 0.5,
		position.y + 0.5 * size.y - 0.5 * characterSize);

	

	sf::Vector2u texture_size = texture.getSize();
	sprite.setScale(size.x / texture_size.x, size.y / texture_size.y);

	
	texture.setSmooth(true);
}
void SFMLButton::resize(sf::Vector2f _new_size)
{
	size = _new_size;

	sf::Vector2u texture_size = texture.getSize();
	sprite.setScale(size.x / float(texture_size.x), size.y / float(texture_size.y));
	
	int characterSize = size.y / 3;
	text.setCharacterSize(characterSize);
	std::string _string = text.getString();
	text.setPosition(position.x + (size.x - text.getLocalBounds().width) * 0.5,
		position.y + 0.5 * size.y - 0.5 * characterSize);
}
void SFMLButton::move(sf::Vector2f _new_position)
{
	position = _new_position;
	sprite.setPosition(position);

	int characterSize = text.getCharacterSize();
	std::string _string = text.getString();
	text.setPosition(position.x + (size.x - text.getLocalBounds().width) * 0.5,
		position.y + 0.5 * size.y - 0.5 * characterSize);
}
void SFMLButton::mousePosition(sf::Vector2i mouse)
{
	mouse_over_button = true;
	
	if (mouse.x < position.x)	mouse_over_button = false;
	if (mouse.y < position.y)	mouse_over_button = false;
	if (mouse.x > position.x + size.x)	mouse_over_button = false;
	if (mouse.y > position.y + size.y)	mouse_over_button = false;	
}
void SFMLButton::mousePressed(void) 
{
	if (mouse_over_button == true)
		button_pressed = true;
	else
		button_pressed = false;
}
void SFMLButton::mouseReleased(void)
{
	if (mouse_over_button == true)
		button_released = true;
	else
		button_released = false;
}
void SFMLButton::windowResized(void)
{
	position = sprite.getPosition();
	size = { float(texture.getSize().x), float(texture.getSize().y) };
}
void SFMLButton::draw(sf::RenderWindow& _window)
{
	_window.draw(sprite);
	_window.draw(text);
}
void SFMLButton::setPicture(const char* _directory)
{
	texture.loadFromFile(_directory);
}
void SFMLButton::setText(std::string _string)
{
	text.setString(_string);
	text.setPosition(position.x + (size.x - text.getLocalBounds().width) * 0.5,
		position.y + 0.5 * size.y - 0.5 * text.getCharacterSize());
}
void SFMLButton::setColor(int _r, int _g, int _b, int _a)
{
	sprite.setColor(sf::Color(_r, _g, _b, _a));
}
void SFMLButton::clear(void)
{
	button_pressed = false;
	button_released = false;
}
void SFMLButton::turnOff(bool _off)
{
	if (_off)
		button_on = false;
	else
		button_on = true;
}
bool SFMLButton::pressed(void)
{
	if (mouse_over_button && button_pressed && button_released && button_on)
		return true;
	return false;
}
SFMLButton::~SFMLButton(void)
{

}