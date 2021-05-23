#pragma once
#include <SFML/Graphics.hpp>

class FPSCounter {
private:
	sf::Text m_text;
	sf::Font m_font;

public:
	FPSCounter();
	~FPSCounter();
};