#pragma once
#include <SFML/Graphics.hpp>

class FPSCounter : virtual public sf::Drawable {
private:
	sf::Text m_text;
	sf::Font m_font;

	float m_fps;
	float m_timeSinceLastFPSUpdateSeconds;

public:
	FPSCounter(sf::Vector2f screenResolution);
	~FPSCounter();

	void update(float dtSeconds);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};