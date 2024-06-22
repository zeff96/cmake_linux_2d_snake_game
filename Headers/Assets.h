#pragma once

#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <unordered_map>

namespace Engine
{
  class Assets
  {
  public:
    Assets();
    virtual ~Assets();

    void AddTexture(int id, const std::string &filePath, bool wantRepeated = false);
    void AddFont(int id, const std::string &filePath);

    const sf::Texture &GetTexture(int id) const;
    const sf::Font &GetFont(int id) const;

  private:
    std::unordered_map<int, std::unique_ptr<sf::Texture>> m_texture;
    std::unordered_map<int, std::unique_ptr<sf::Font>> m_font;
  };
}