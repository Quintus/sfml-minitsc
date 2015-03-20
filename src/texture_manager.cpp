#include <map>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"

TextureManager::~TextureManager()
{
  std::map<Pathie::Path, sf::Texture*>::iterator iter;
  for (iter=m_textures.begin(); iter != m_textures.end(); iter++) {
    delete iter->second;
  }
}

/**
 * Load the given texture from the given file if it hasn’t
 * been loaded yet. If it has been loaded already, return
 * it from the cache.
 */
sf::Texture& TextureManager::get_texture(const Pathie::Path& path)
{
  if (m_textures.count(path)) {
    return *m_textures[path];
  }
  else {
    sf::Texture* p_texture = new sf::Texture;
    p_texture->loadFromFile(path.native());
    m_textures[path] = p_texture;
    return *p_texture;
  }
}
