#pragma once

#include <memory>
#include "StateMachine.h"
#include "Assets.h"
#include <SFML/Graphics/RenderWindow.hpp>

enum AssetsId
{
  MAIN_FONT = 0,
  GRASS,
  FOOD,
  WALL,
  SNAKE
};

struct Context
{
  std::unique_ptr<Engine::Assets> m_assets;
  std::unique_ptr<Engine::StateMachine> m_states;
  std::unique_ptr<sf::RenderWindow> m_window;

  Context()
  {
    m_assets = std::make_unique<Engine::Assets>();
    m_states = std::make_unique<Engine::StateMachine>();
    m_window = std::make_unique<sf::RenderWindow>();
  }
};

namespace GameState
{
  class Game
  {
  public:
    Game();
    void run();

    void ProcessEvents();
    void Update(sf::Time deltaTime);
    void Render();

  private:
    std::shared_ptr<Context> m_context;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
  };
}