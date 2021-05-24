#include "FPSCounter.h"

FPSCounter::FPSCounter(sf::Vector2f screenResolution) :
	m_fps(0.0),
	m_timeSinceLastFPSUpdateSeconds(0.0) {
	m_font.loadFromFile("Assets/Fonts/VT323-Regular.ttf");
	m_text.setString("FPS: calculating...");
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(screenResolution.x - 300, screenResolution.y - 100);
}

FPSCounter::~FPSCounter() {
}

void FPSCounter::update(float dtSeconds) {
	m_timeSinceLastFPSUpdateSeconds += dtSeconds;
	if (m_timeSinceLastFPSUpdateSeconds > 1) {
		m_fps = 1.f / dtSeconds;
		m_text.setString("FPS: " + std::to_string((int)m_fps));
		m_timeSinceLastFPSUpdateSeconds = 0.0;
	}
}

void FPSCounter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_text, states);
}