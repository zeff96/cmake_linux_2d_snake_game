#include "MainMenu.h"
#include <SFML/Window/Event.hpp>

MenuState::MainMenu::MainMenu(std::shared_ptr<Context> &context) : m_context(context), ismPlayButtonSelected(true),
                                                                   ismPlayButtonPressed(false), ismExitButtonSelected(false),
                                                                   ismExitButtonPressed(false){};

MenuState::MainMenu::~MainMenu()
{
}

void MenuState::MainMenu::Init()
{
  m_context->m_assets->AddFont(AssetsId::MAIN_FONT, "./Resources/fonts/Pacifico-Regular.ttf");
  mTitle.setFont(m_context->m_assets->GetFont(AssetsId::MAIN_FONT));
  mTitle.setString("Main Menu");
  mTitle.setCharacterSize(50);
  mTitle.setOrigin(mTitle.getLocalBounds().width / 2, mTitle.getLocalBounds().height / 2);
  mTitle.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 150.f);

  // play button
  mPlayButton.setFont(m_context->m_assets->GetFont(AssetsId::MAIN_FONT));
  mPlayButton.setString("Play");
  mPlayButton.setCharacterSize(20);
  mPlayButton.setOrigin(mPlayButton.getLocalBounds().width / 2, mPlayButton.getLocalBounds().height / 2);
  mPlayButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 25.f);

  // exit button

  mExitButton.setFont(m_context->m_assets->GetFont(AssetsId::MAIN_FONT));
  mExitButton.setString("Exit");
  mExitButton.setCharacterSize(20);
  mExitButton.setOrigin(mExitButton.getLocalBounds().width / 2, mExitButton.getLocalBounds().height / 2);
  mExitButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 25.f);
}

void MenuState::MainMenu::ProcessInput()
{
  sf::Event event;

  while (m_context->m_window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      m_context->m_window->close();
    }
    else if (event.type == sf::Event::KeyPressed)
    {
      switch (event.key.code)
      {
      case sf::Keyboard::Up:
        if (!ismExitButtonSelected)
        {
          ismPlayButtonSelected = true;
          ismExitButtonSelected = false;
        }
        break;
      case sf::Keyboard::Down:
      {
        if (ismExitButtonSelected)
        {
          ismPlayButtonSelected = false;
          ismExitButtonSelected = true;
        }
        break;
      }
      case sf::Keyboard::Return:
      {
        ismPlayButtonPressed = false;
        ismExitButtonPressed = false;

        if (ismPlayButtonSelected)
        {
          ismPlayButtonPressed = true;
        }

        if (ismExitButtonSelected)
        {
          ismExitButtonPressed = true;
        }
      }
      default:
        break;
      }
    }
  }
}

void MenuState::MainMenu::Update(const sf::Time &deltaTime)
{
  if (ismPlayButtonSelected)
  {
    mPlayButton.setFillColor(sf::Color::Black);
    mExitButton.setFillColor(sf::Color::White);
  }
  else
  {
    mPlayButton.setFillColor(sf::Color::White);
    mExitButton.setFillColor(sf::Color::Black);
  }

  if (ismPlayButtonPressed)
  {
    // enter game state
  }
  else if (ismExitButtonPressed)
  {
    m_context->m_window->close();
  }
}

void MenuState::MainMenu::Draw()
{
  m_context->m_window->clear(sf::Color::Blue);
  m_context->m_window->draw(mTitle);
  m_context->m_window->draw(mPlayButton);
  m_context->m_window->draw(mExitButton);
  m_context->m_window->display();
}