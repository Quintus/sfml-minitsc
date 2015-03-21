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
  inline TextureManager& get_texture_manager(){return *mp_texture_manager;}

  inline float get_gravity_factor(){return m_gravity_factor;}
private:
  sf::RenderWindow* mp_renderwindow;
  sf::Font m_gamefont;

  TextureManager* mp_texture_manager;
  SceneManager* mp_scene_manager;

  float m_gravity_factor = 9.81f;
};

extern App* gp_app;

#endif
