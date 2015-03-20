#ifndef MINITSC_APP_HPP
#define MINITSC_APP_HPP

class App
{
public:

  App();
  ~App();

  int run();
  inline sf::Font& get_gamefont(){return m_gamefont;}
  inline sf::RenderWindow& get_renderwindow(){return *mp_renderwindow;}
  inline SceneManager& get_scene_manager(){return *mp_scene_manager;}
private:
  sf::RenderWindow* mp_renderwindow;
  sf::Font m_gamefont;

  TextureManager* mp_texture_manager;
  SceneManager* mp_scene_manager;
};

extern App* gp_app;

#endif
