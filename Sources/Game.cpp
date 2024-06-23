#include "Game.h"
#include "MainMenu.h"
#include <memory>

using namespace GameState;
using namespace MenuState;

Game::Game() : m_context(std::make_shared<Context>())
{
  m_context->m_window->create(sf::VideoMode(800, 600), "Snake Game", sf::Style::Close);
  m_context->m_states->SetState(std::make_unique<MainMenu>(m_context));
}

void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (m_context->m_window->isOpen())
  {
    sf::Time deltaTime = clock.restart();
    timeSinceLastUpdate += deltaTime;

    while (timeSinceLastUpdate > TimePerFrame)
    {
      timeSinceLastUpdate -= TimePerFrame;
      ProcessEvents();
    }

    Render();
  }
}

void Game::ProcessEvents()
{
  m_context->m_states->ProcessInput();
}

void Game::Update(sf::Time deltaTime)
{
  m_context->m_states->Update(deltaTime);
}

void Game::Render()
{
  m_context->m_states->Draw();
}