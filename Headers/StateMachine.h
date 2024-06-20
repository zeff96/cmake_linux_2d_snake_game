#pragma once

#include "State.h"
#include <memory>
#include <stack>

namespace Engine
{
  class StateMachine
  {
  public:
    StateMachine() = default;

    void SetState(std::unique_ptr<State> newState);
    void Update(const sf::Time &deltaTime);
    void Draw();
    void ProcessInput();

  private:
    std::unique_ptr<State> currentState;
  };
}