#include "Assets.h"

Engine::Assets::Assets() {}

Engine::Assets::~Assets(){};

void Engine::Assets::AddTexture(int id, const std::string &filePath, bool wantRepeated)
{
  auto texture = std::make_unique<sf::Texture>();

  if (texture->loadFromFile(filePath))
  {
    texture->setRepeated(wantRepeated);
    m_texture[id] = std::move(texture);
  }
}

void Engine::Assets::AddFont(int id, const std::string &filePath)
{
  auto font = std::make_unique<sf::Font>();

  if (font->loadFromFile(filePath))
  {
    m_font[id] = std::move(font);
  }
}

const sf::Texture &Engine::Assets::GetTexture(int id) const
{
  return *(m_texture.at(id).get());
}

const sf::Font &Engine::Assets::GetFont(int id) const
{
  return *(m_font.at(id).get());
}
