#include "Snake.h"

Snake::Snake(const sf::Texture &texture, const sf::Vector2f &startingPosition, int initialLength)
{
}
Snake::~Snake(){};

void Snake::Move(const sf::Vector2f &direction)
{
}

bool Snake::CheckWallCollision(const sf::RenderWindow &window) const
{
  return false;
}

void Snake::Grow(const sf::Vector2f &direction)
{
}
bool Snake::CheckSelfCollision() const
{
  return false;
}
void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const {
};