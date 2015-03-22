#include <stack>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "../actors/actor.hpp"
#include "../actors/player_actor.hpp"
#include "../scenery.hpp"
#include "scene.hpp"
#include "menu_scene.hpp"
#include "level_scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

MenuScene::MenuScene()
{
  m_start_text.setFont(gp_app->get_gamefont());
  m_start_text.setString("Press [ENTER] to start");
  m_start_text.setCharacterSize(24);
  m_start_text.setColor(sf::Color::Red);

  sf::FloatRect bounding_box = m_start_text.getGlobalBounds();
  sf::Vector2u windowsize = gp_app->get_renderwindow().getSize();
  int textpos_x = (windowsize.x - bounding_box.width) / 2;
  int textpos_y = (windowsize.y - bounding_box.height) / 2;

  m_start_text.setPosition(textpos_x, textpos_y);
}

MenuScene::~MenuScene()
{
  //
}

void MenuScene::handle_event(sf::Event& evt)
{
  Scene::handle_event(evt);

  switch(evt.type) {
  case sf::Event::KeyPressed:
    if (evt.key.code == sf::Keyboard::Return) {
      // Place the target scene (level scene) on top of
      // the stack, so that it will automatically get
      // rendered on next mainloop iteration.
      gp_app->get_scene_manager().push_scene(new LevelScene);
    }
  default:
    // Ignore
    break;
  }
}

void MenuScene::update()
{
  Scene::update();
}

void MenuScene::draw(sf::RenderWindow& stage)
{
  Scene::draw(stage);

  stage.draw(m_start_text);
}
