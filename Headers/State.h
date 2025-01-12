#pragma once

#include <SFML/System/Time.hpp>

namespace Engine
{
  class State
  {
  public:
    virtual void Init() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update(const sf::Time &deltaTime) = 0;
    virtual void Draw() = 0;
  };
}