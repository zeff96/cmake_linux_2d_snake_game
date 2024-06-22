#pragma once

#include <memory>
#include "State.h"
#include <SFML/Graphics/Text.hpp>
#include "Game.h"

namespace MenuState
{
  class MainMenu : public Engine::State
  {
  public:
    MainMenu(std::shared_ptr<Context> &context);
    virtual ~MainMenu();

    void Init() override;
    void ProcessInput() override;
    void Update(const sf::Time &deltaTime) override;
    void Draw() override;

  private:
    std::shared_ptr<Context> m_context;
    sf::Text mTitle;

    sf::Text mPlayButton;
    sf::Text mExitButton;

    bool ismPlayButtonSelected;
    bool ismPlayButtonPressed;

    bool ismExitButtonSelected;
    bool ismExitButtonPressed;
  };
}