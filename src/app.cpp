#include <stack>
#include <SFML/Graphics.hpp>
#include <pathie.hpp>
#include "actors/actor.hpp"
#include "scenes/scene.hpp"
#include "scenes/menu_scene.hpp"
#include "texture_manager.hpp"
#include "scene_manager.hpp"
#include "app.hpp"

App* gp_app = NULL;

App::App()
{
  mp_renderwindow = new sf::RenderWindow(sf::VideoMode(640, 480), "Mini TSC");
  m_gamefont.loadFromFile("../data/fonts/DejaVuSans.ttf");

  mp_texture_manager = new TextureManager;
  mp_scene_manager = new SceneManager;
}

App::~App()
{
  delete mp_scene_manager;
  delete mp_texture_manager;
  delete mp_renderwindow;
}

int App::run()
{
  // Always start with the menu scene.
  MenuScene* p_menuscene = new MenuScene;
  mp_scene_manager->push_scene(p_menuscene);

  mp_scene_manager->play(*mp_renderwindow);
  return 0;
}
