#include "StateManager.h"

Engine::StateManager::StateManager() : m_add{false}, m_replace{false}, m_remove{false}, m_removeAll{false} {};

Engine::StateManager::~StateManager(){};

void Engine::StateManager::Add(std::unique_ptr<State> toAdd, bool replace)
{
  m_add = true;
  m_newState = std::move(toAdd);
  m_replace = false;
}

void Engine::StateManager::PopCurrent()
{
  m_remove = true;
}

void Engine::StateManager::PopAll()
{
  m_removeAll = true;
  m_remove = false;
}

void Engine::StateManager::ProcessStateChange() {};

std::unique_ptr<Engine::State> &Engine::StateManager::GetCurrent()
{
  return m_stackSTate.top();
}

bool Engine::StateManager::isEmpty() const
{
  return m_stackSTate.empty();
}