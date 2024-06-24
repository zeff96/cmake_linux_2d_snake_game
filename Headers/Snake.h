#pragma once

#include <list>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Snake : public sf::Drawable
{
public:
  Snake();
  virtual ~Snake();

  void Init(const sf::Texture &texture);
  void Move(const sf::Vector2f &direction);
  bool IsOn(const sf::Sprite &prite) const;
  void Grow(const sf::Vector2f &direction);
  bool IsSelfIntersecting() const;

  void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

private:
  std::list<sf::Sprite> m_body;
  std::list<sf::Sprite> m_head;
  std::list<sf::Sprite> m_tail;
};