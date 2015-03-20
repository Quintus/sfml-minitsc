#ifndef MINITSC_TEXTURE_MANAGER_HPP
#define MINITSC_TEXTURE_MANAGER_HPP

class TextureManager
{
public:
  ~TextureManager();
  sf::Texture& get_texture(const Pathie::Path& path);
private:
  std::map<Pathie::Path, sf::Texture*> m_textures;
};

#endif
