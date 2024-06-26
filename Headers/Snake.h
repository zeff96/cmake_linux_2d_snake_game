#pragma once

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Snake : public sf::Drawable
{
public:
  Snake(const sf::Texture &texture, const sf::Vector2f &startingPosition, int initialLength = 3);
  virtual ~Snake();

  void Move(const sf::Vector2f &direction);
  bool CheckWallCollision(const sf::RenderWindow &window) const;
  void Grow(const sf::Vector2f &direction);
  bool CheckSelfCollision() const;

  void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

private:
  std::vector<sf::Sprite> body;
  sf::Vector2f headPosition;
  sf::Vector2f direction;
  int length;
};