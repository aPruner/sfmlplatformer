#include "Animation.h"

Animation::Animation(TextureMapper* textureMap, std::string const& animName, int scalingFactor, std::string const& spriteSheetFilename, float animationSpeed, bool* isInvertedX)
{
	m_textureMap = textureMap;
	m_animName = animName;
	m_clock = new sf::Clock();
	m_animationSpeed = animationSpeed;
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = new sf::Sprite(m_textureMap->getTexture(spriteSheetFilename), m_animSpriteSheetBounds);
	m_scalingFactor = scalingFactor;
	m_sprite->scale((float)scalingFactor, (float)scalingFactor);
	m_isAnimating = false;
	m_isInvertedX = isInvertedX;
}

void Animation::initAnimFrames()
{
	std::tuple<int, int, int, int, int> animTuple = m_textureMap->getAnimTuple(m_animName);
	m_firstFrameTopLeft = sf::Vector2f((float)std::get<0>(animTuple), (float)std::get<1>(animTuple));
	m_width = std::get<2>(animTuple);
	m_height = std::get<3>(animTuple);
	m_frames = std::get<4>(animTuple) - 1;
	m_animSpriteSheetBounds = sf::IntRect((int)m_firstFrameTopLeft.x, (int)m_firstFrameTopLeft.y, m_width, m_height);
	m_animIndex = 0;
}

void Animation::resetAnimation()
{
	m_animSpriteSheetBounds.left = (int)m_firstFrameTopLeft.x;
	m_sprite->setTextureRect(m_animSpriteSheetBounds);
	m_animIndex = 0;
}

void Animation::updateAnimationFrame()
{
	// If necessary, invert the sprite on this frame
	if (*m_isInvertedX)
	{
		m_sprite->setScale(-1 * m_scalingFactor, m_scalingFactor);
	}
	else
	{
		m_sprite->setScale(m_scalingFactor, m_scalingFactor);
	}

	if (m_animIndex < m_frames)
	{
		m_animSpriteSheetBounds.left += m_width;
		m_sprite->setTextureRect(m_animSpriteSheetBounds);
		m_animIndex++;
	}
	else
	{
		resetAnimation();
	}
}

// Assumes that the isAnimating() currently returns true
void Animation::animate()
{
	float dtSeconds = m_clock->getElapsedTime().asSeconds();
	if (dtSeconds > m_animationSpeed)
	{
		updateAnimationFrame();
		m_clock->restart();
	}
}

// Essentially acts as a setter for m_isAnimating
void Animation::startAnimation()
{
	m_isAnimating = true;
}

void Animation::stopAnimation()
{
	m_isAnimating = false;
	resetAnimation();
}

// Getters and Setters
// Getters
bool Animation::getIsAnimating()
{
	return m_isAnimating;
}

sf::Sprite* Animation::getFrameSprite()
{
	return m_sprite;
}

bool Animation::getIsInvertedX()
{
	return *m_isInvertedX;
}