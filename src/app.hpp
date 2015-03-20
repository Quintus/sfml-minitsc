#ifndef MINITSC_APP_HPP
#define MINITSC_APP_HPP

class App
{
public:

  App();
  ~App();

  int run();
private:
  sf::RenderWindow* mp_renderwindow;
  TextureManager* mp_texture_manager;
  SceneManager* mp_scene_manager;
};

extern App* gp_app;

#endif
