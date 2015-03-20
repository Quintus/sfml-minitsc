#include <stack>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "menu_scene.hpp"
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
