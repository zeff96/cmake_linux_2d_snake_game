#include "Snake.h"

Snake::Snake(const sf::Texture &texture, const sf::Vector2f &startingPosition, int initialLength) : headPosition{startingPosition}, direction(0.f, 0.f), length{initialLength}
{
  for (size_t i = 0; i < initialLength; ++i)
  {
    sf::Sprite segment;
    segment.setPosition(startingPosition.x - i * texture.getSize().x, startingPosition.y);
    body.emplace_back(segment);
  }
};
Snake::~Snake(){};

void Snake::Move(const sf::Vector2f &direction)
{
  this->direction = direction;
  for (int i = body.size() - 1; i > 0; i--)
  {
    body[i].setPosition(body[i - 1].getPosition());
  }
  body[0].move(direction);
  headPosition = body[0].getPosition();
};

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