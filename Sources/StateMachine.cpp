#include "StateMachine.h"

void Engine::StateMachine::SetState(std::unique_ptr<State> newState)
{
  currentState = std::move(newState);
  currentState->Init();
}

void Engine::StateMachine::Update(const sf::Time &deltaTime)
{
  if (currentState)
  {
    currentState->Update(deltaTime);
  }
}

void Engine::StateMachine::Draw()
{
  if (currentState)
  {
    currentState->Draw();
  }
}

void ::Engine::StateMachine::ProcessInput()
{
  if (currentState)
  {
    currentState->ProcessInput();
  }
}
